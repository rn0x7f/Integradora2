#include <gtest/gtest.h>
#include "../include/KruskalLib.h"

// Caso de prueba para el algoritmo de Kruskal
TEST(KruskalTest, BasicMST) {
    int N = 4;
    std::vector<std::vector<int>> distance_matrix = {
        {0, 1, 3, 0},
        {1, 0, 2, 4},
        {3, 2, 0, 5},
        {0, 4, 5, 0}
    };

    std::vector<std::pair<int, int>> expected_mst = {{0, 1}, {1, 2}, {1, 3}};
    
    std::vector<std::pair<int, int>> mst_edges = kruskalMST(N, distance_matrix);

    // Verificar que el MST tenga el mismo número de aristas esperado
    ASSERT_EQ(mst_edges.size(), expected_mst.size());

    // Verificar que todas las aristas esperadas estén en el resultado
    for (const auto& edge : expected_mst) {
        EXPECT_NE(std::find(mst_edges.begin(), mst_edges.end(), edge), mst_edges.end());
    }
}

// Caso de prueba cuando solo hay un nodo
TEST(KruskalTest, SingleNode) {
    int N = 1;
    std::vector<std::vector<int>> distance_matrix = {{0}};

    std::vector<std::pair<int, int>> mst_edges = kruskalMST(N, distance_matrix);

    // Un solo nodo no debe tener ninguna arista en el MST
    ASSERT_TRUE(mst_edges.empty());
}

// Caso de prueba cuando el grafo es completamente desconectado
TEST(KruskalTest, DisconnectedGraph) {
    int N = 3;
    std::vector<std::vector<int>> distance_matrix = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    std::vector<std::pair<int, int>> mst_edges = kruskalMST(N, distance_matrix);

    // Un grafo desconectado no debe tener ninguna arista en el MST
    ASSERT_TRUE(mst_edges.empty());
}
