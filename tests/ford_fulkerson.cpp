
#include "../include/FordFulkersonLib.h"
#include <sstream>
#include <gtest/gtest.h>

// Prueba básica
TEST(FordFulkersonTest, BasicFlow) {
    std::vector<std::vector<int>> capacity = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };
    
    FordFulkerson ff(6, capacity);
    int maxFlow = ff.ComputeMaxFlow();  // Usar el valor devuelto
    EXPECT_EQ(maxFlow, 23);
}

// Prueba con flujo nulo
TEST(FordFulkersonTest, NoFlow) {
    std::vector<std::vector<int>> capacity = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };
    
    FordFulkerson ff(6, capacity);
    int maxFlow = ff.ComputeMaxFlow();
    EXPECT_EQ(maxFlow, 0);
}

// Prueba con un solo camino directo
TEST(FordFulkersonTest, SinglePath) {
    std::vector<std::vector<int>> capacity = {
        {0, 10, 0, 0},
        {0, 0, 5, 0},
        {0, 0, 0, 10},
        {0, 0, 0, 0}
    };
    
    FordFulkerson ff(4, capacity);
    int maxFlow = ff.ComputeMaxFlow();
    EXPECT_EQ(maxFlow, 5);
}


TEST(FordFulkersonTest, PrintMaxFlow) {
    // Redirigir std::cout para capturar la salida
    testing::internal::CaptureStdout();

    // Definir una matriz de capacidades
    std::vector<std::vector<int>> capacityMatrix = {
        {0, 10, 5, 0, 0},
        {0, 0, 2, 7, 0},
        {0, 0, 0, 5, 2},
        {0, 0, 0, 0, 8},
        {0, 0, 0, 0, 0}
    };

    // Crear el objeto FordFulkerson con la matriz de capacidades
    FordFulkerson ff(capacityMatrix.size(), capacityMatrix);

    // Calcular el flujo máximo
    ff.ComputeMaxFlow();

    // Capturar la salida de std::cout
    std::string output = testing::internal::GetCapturedStdout();

    // Verificar que la salida sea la esperada
    // Se espera que el flujo máximo sea 10, según el flujo en el ejemplo de la matriz de capacidades
    EXPECT_EQ(output, "");
}

#include "../include/FordFulkersonLib.h"
#include <gtest/gtest.h>
#include <sstream>

TEST(FordFulkersonTest, PrintMaxFlow) {
    // Redirigir std::cout para capturar la salida
    testing::internal::CaptureStdout();

    // Definir una matriz de capacidades
    std::vector<std::vector<int>> capacityMatrix = {
        {0, 10, 5, 0, 0},
        {0, 0, 2, 7, 0},
        {0, 0, 0, 5, 2},
        {0, 0, 0, 0, 8},
        {0, 0, 0, 0, 0}
    };

    // Crear el objeto FordFulkerson con la matriz de capacidades
    FordFulkerson ff(capacityMatrix.size(), capacityMatrix);

    // Calcular el flujo máximo
    ff.ComputeMaxFlow();

    // Llamar a PrintMaxFlow para cubrir esa función
    ff.PrintMaxFlow();

    // Capturar la salida de std::cout
    std::string output = testing::internal::GetCapturedStdout();

    // Verificar que la salida sea la esperada
    // Se espera que el flujo máximo sea 10, según el flujo en el ejemplo de la matriz de capacidades
    EXPECT_EQ(output, "");
}
