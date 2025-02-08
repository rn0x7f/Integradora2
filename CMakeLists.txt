cmake_minimum_required(VERSION 3.30)
project(unit_test)

set(CMAKE_CXX_STANDARD 17)

# Ruta a los archivos de cabecera
include_directories(${PROJECT_SOURCE_DIR}/include)

# Archivos fuente principales
set(SOURCES
    main.cpp  
    KruskalLib.cpp
    TravelingLib.cpp
    FordFulkersonLib.cpp
    NearestCentralLib.cpp
)

# Crear ejecutable principal
add_executable(unit_test ${SOURCES})

# Opciones para pruebas y cobertura
option(ENABLE_TESTING "Enable a Unit Testing build." ON)
option(ENABLE_COVERAGE "Enable code coverage instrumentation." OFF)

# Configuración para la instrumentación de cobertura
if(ENABLE_COVERAGE)
    message(STATUS "Enabling code coverage flags")
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
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

# Configuración de pruebas unitarias
if(ENABLE_TESTING)
    enable_testing()

    # Archivos de pruebas
    set(TEST_SOURCES
        tests/kruskal.cpp
        tests/traveling.cpp
        tests/ford_fulkerson.cpp
        tests/nearest_central.cpp
    )

    foreach(TEST_FILE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
    set(EXEC_NAME "unit_test_${TEST_NAME}")
    add_executable(${EXEC_NAME} ${TEST_FILE} 
        KruskalLib.cpp TravelingLib.cpp FordFulkersonLib.cpp NearestCentralLib.cpp)
    target_link_libraries(${EXEC_NAME} PRIVATE gtest gtest_main)
    # Añadir flags de cobertura explícitamente
    if(ENABLE_COVERAGE)
        target_compile_options(${EXEC_NAME} PRIVATE --coverage)
        target_link_libraries(${EXEC_NAME} PRIVATE --coverage)
    endif()
    add_test(NAME ${EXEC_NAME} COMMAND ${EXEC_NAME})
endforeach()
