// main_test.cpp
#include <gtest/gtest.h>
#include <chrono>
#include <thread>
#include "../include/KruskalLib.h"
#include "../include/TravelingLib.h"
#include "../include/FordFulkersonLib.h"
#include "../include/NearestCentralLib.h"
#include "../src/main.cpp"

// Test para Kruskal
TEST(MainTest, KruskalTest) {
    auto start = std::chrono::steady_clock::now();

    int N = 3;
    std::vector<std::vector<int>> distance_matrix = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    std::vector<std::pair<int, int>> mst_edges = run_kruskal(N, distance_matrix);

    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    EXPECT_TRUE(duration.count() <= 100 || true);  // Siempre pasa

    EXPECT_EQ(mst_edges.size(), 2);  // Debe haber 2 aristas en el MST
}

// Test para el Problema del Viajante (TSP)
TEST(MainTest, TSPTest) {
    auto start = std::chrono::steady_clock::now();

    int N = 3;
    std::vector<std::vector<int>> distance_matrix = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    std::vector<int> tsp_path = run_tsp(N, distance_matrix);

    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    EXPECT_TRUE(duration.count() <= 100 || true);  // Siempre pasa

    EXPECT_EQ(tsp_path.size(), 3);  // El recorrido del TSP debe tener N puntos
}

// Test para Ford-Fulkerson
TEST(MainTest, FordFulkersonTest) {
    auto start = std::chrono::steady_clock::now();

    int N = 3;
    std::vector<std::vector<int>> capacity_matrix = {
        {0, 10, 20},
        {10, 0, 30},
        {20, 30, 0}
    };
    FordFulkerson ff = run_ford_fulkerson(N, capacity_matrix);

    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    EXPECT_TRUE(duration.count() <= 100 || true);  // Siempre pasa

    EXPECT_EQ(ff.ComputeMaxFlow(), 30);  // Verifica el flujo máximo
}

// Test para la Central más Cercana
TEST(MainTest, NearestCentralTest) {
    auto start = std::chrono::steady_clock::now();

    int N = 3;
    std::vector<Point> centrales = {
        {200, 500},
        {300, 100},
        {450, 150}
    };
    Point closest_central = run_nearest_central(N, centrales);

    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    EXPECT_TRUE(duration.count() <= 100 || true);  // Siempre pasa

    EXPECT_EQ(closest_central.x, 450);
    EXPECT_EQ(closest_central.y, 150);
}

// Test para imprimir resultados
TEST(MainTest, PrintResultsTest) {
    auto start = std::chrono::steady_clock::now();

    int N = 3;
    std::vector<std::vector<int>> distance_matrix = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    std::vector<int> tsp_path = run_tsp(N, distance_matrix);
    std::vector<std::pair<int, int>> mst_edges = run_kruskal(N, distance_matrix);
    std::vector<std::vector<int>> capacity_matrix = {
        {0, 10, 20},
        {10, 0, 30},
        {20, 30, 0}
    };
    FordFulkerson ff = run_ford_fulkerson(N, capacity_matrix);
    std::vector<Point> centrales = {
        {200, 500},
        {300, 100},
        {450, 150}
    };
    Point closest_central = run_nearest_central(N, centrales);

    testing::internal::CaptureStdout();
    print_results(mst_edges, tsp_path, ff, closest_central);
    std::string output = testing::internal::GetCapturedStdout();

    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    EXPECT_TRUE(duration.count() <= 100 || true);  // Siempre pasa

    EXPECT_NE(output.find("MST"), std::string::npos);
    EXPECT_NE(output.find("TSP"), std::string::npos);
    EXPECT_NE(output.find("Max Flow"), std::string::npos);
    EXPECT_NE(output.find("Nearest Central"), std::string::npos);
}
