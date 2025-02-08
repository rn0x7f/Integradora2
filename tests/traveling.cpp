
#include <gtest/gtest.h>
#include "../include/TravelingLib.h"

// Caso de prueba para resolver el TSP con un grafo pequeño
TEST(TravelingTest, BasicTSP) {
    int N = 4;
    std::vector<std::vector<int>> distance_matrix = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    std::vector<int> expected_path = {1, 2, 3};
    
    std::vector<int> best_path = solve_tsp(N, distance_matrix);

    // Verificar que el recorrido más corto encontrado sea el esperado
    ASSERT_EQ(best_path.size(), expected_path.size());
    for (int i = 0; i < best_path.size(); ++i) {
        EXPECT_EQ(best_path[i], expected_path[i]);
    }
}

// Caso de prueba cuando hay solo un nodo
TEST(TravelingTest, SingleNodeTSP) {
    int N = 1;
    std::vector<std::vector<int>> distance_matrix = {{0}};
    
    std::vector<int> best_path = solve_tsp(N, distance_matrix);

    // Un solo nodo no tiene recorrido que hacer, por lo que debería devolver un camino vacío
    ASSERT_TRUE(best_path.empty());
}

// Caso de prueba con un grafo de distancias no simétricas
TEST(TravelingTest, NonSymmetricGraph) {
    int N = 3;
    std::vector<std::vector<int>> distance_matrix = {
        {0, 2, 9},
        {1, 0, 6},
        {15, 7, 0}
    };

    std::vector<int> expected_path = {1, 2};  // El camino más corto de 'A' -> 'B' -> 'C'
    
    std::vector<int> best_path = solve_tsp(N, distance_matrix);

    // Verificar que el recorrido más corto encontrado sea el esperado
    ASSERT_EQ(best_path.size(), expected_path.size());
    for (int i = 0; i < best_path.size(); ++i) {
        EXPECT_EQ(best_path[i], expected_path[i]);
    }
}
