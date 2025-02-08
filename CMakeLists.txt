cmake_minimum_required(VERSION 3.30)
project(unit_test)

set(CMAKE_CXX_STANDARD 17)

# Ruta a los archivos de cabecera
include_directories(${PROJECT_SOURCE_DIR}/include)

# Archivos fuente principales
set(SOURCES
    main.cpp  
    KruskalLib.cpp
    TravelingLib.cpp  # Agregado TravelingLib.cpp
    FordFulkersonLib.cpp
    NearestCentralLib.cpp
)

# Crear ejecutable principal
add_executable(unit_test ${SOURCES})

# Opciones para pruebas y cobertura
option(ENABLE_TESTING "Enable a Unit Testing build." ON)
option(ENABLE_COVERAGE "Enable code coverage instrumentation." OFF)

# Si se habilita la cobertura, se agregan las flags necesarias para GCC/Clang
if(ENABLE_COVERAGE)
    message(STATUS "Enabling code coverage flags")
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        # Las banderas --coverage generan los archivos .gcno y .gcda necesarios para gcov/gcovr.
        # Se recomienda usar -O0 para evitar que las optimizaciones interfieran con la cobertura.
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -O0")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
    endif()
endif()

# Descarga GoogleTest usando FetchContent
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

# Si se habilitan las pruebas, se configuran las pruebas unitarias
if(ENABLE_TESTING)
    enable_testing()

    # Archivos de pruebas
    set(TEST_SOURCES
        tests/kruskal.cpp
        tests/traveling.cpp
        tests/ford_fulkerson.cpp
        tests/nearest_central.cpp
    )

    # Para cada archivo de prueba se crea un ejecutable y se registra la prueba en CTest
    foreach(TEST_FILE ${TEST_SOURCES})
        get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
        
        # Se define un nombre único para el ejecutable de prueba
        set(EXEC_NAME "unit_test_${TEST_NAME}")
        add_executable(${EXEC_NAME} ${TEST_FILE} 
            KruskalLib.cpp TravelingLib.cpp FordFulkersonLib.cpp NearestCentralLib.cpp)

        # Se enlaza con GoogleTest
        target_link_libraries(${EXEC_NAME} PRIVATE gtest gtest_main)

        # Se registra la prueba
        add_test(NAME ${EXEC_NAME} COMMAND ${EXEC_NAME})
    endforeach()
endif()
