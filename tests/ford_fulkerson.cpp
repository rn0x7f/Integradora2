
#include "../include/FordFulkersonLib.h"
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

// Prueba con un gráfico con caminos múltiples
TEST(FordFulkersonTest, MultiplePaths) {
    std::vector<std::vector<int>> capacity = {
        {0, 10, 10, 0, 0},
        {0, 0, 0, 10, 0},
        {0, 0, 0, 10, 0},
        {0, 0, 0, 0, 10},
        {0, 0, 0, 0, 0}
    };
    
    FordFulkerson ff(5, capacity);
    int maxFlow = ff.ComputeMaxFlow();
    EXPECT_EQ(maxFlow, 20);
}

// Prueba con un flujo mayor a la capacidad total
TEST(FordFulkersonTest, OverflowFlow) {
    std::vector<std::vector<int>> capacity = {
        {0, 20, 10, 0},
        {0, 0, 0, 10},
        {0, 0, 0, 10},
        {0, 0, 0, 0}
    };
    
    FordFulkerson ff(4, capacity);
    int maxFlow = ff.ComputeMaxFlow();
    EXPECT_EQ(maxFlow, 10);  // El flujo no puede superar la capacidad total
}
