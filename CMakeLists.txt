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

# Opciones
option(ENABLE_TESTING "Enable a Unit Testing build." ON)

# Descarga GoogleTest usando FetchContent
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

# Si se habilitan las pruebas, agrega GoogleTest y las pruebas unitarias
if(ENABLE_TESTING)
    enable_testing()

    # Activar cobertura de código con GCC
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")

    # Archivos de pruebas
    set(TEST_SOURCES
        tests/kruskal.cpp
        tests/traveling.cpp  # Agregado traveling.cpp para pruebas de Traveling
        tests/ford_fulkerson.cpp
    )

    # Crear ejecutable de pruebas para cada archivo de prueba
    foreach(TEST_FILE ${TEST_SOURCES})
        get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
        
        # Cambiar "test" por algo más único si es necesario
        set(EXEC_NAME "unit_test_${TEST_NAME}")
        add_executable(${EXEC_NAME} ${TEST_FILE} KruskalLib.cpp TravelingLib.cpp FordFulkersonLib.cpp NearestCentralLib.cpp)

        # Enlazar GoogleTest
        target_link_libraries(${EXEC_NAME} PRIVATE gtest gtest_main)

        # Registrar pruebas con CTest
        add_test(NAME ${EXEC_NAME} COMMAND ${EXEC_NAME})
    endforeach()
endif()
