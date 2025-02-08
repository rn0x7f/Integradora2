#include <gtest/gtest.h>
#include "../include/TravelingLib.h"

// Caso de prueba único para resolver el TSP con el grafo dado
TEST(TravelingTest, BasicTSP) {
    int N = 4;
    std::vector<std::vector<int>> distance_matrix = {
        {0, 16, 45, 32},
        {16, 0, 18, 21},
        {45, 18, 0, 7},
        {32, 21, 7, 0}
    };

    // El recorrido esperado ahora incluye el regreso al punto A
    std::vector<int> expected_path = {0, 0, 1, 2, 3, 0, 0};  // A -> B -> C -> D -> A
    
    std::vector<int> best_path = solve_tsp(N, distance_matrix);

    // Verificar que el recorrido más corto encontrado sea el esperado
    ASSERT_EQ(best_path.size(), expected_path.size());
    for (int i = 0; i < best_path.size(); ++i) {
        EXPECT_EQ(best_path[i], expected_path[i]);
    }
}
