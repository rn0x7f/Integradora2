
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
#include "include/KruskalLib.h"
#include "include/TravelingLib.h"
#include "include/FordFulkersonLib.h"
#include "include/NearestCentralLib.h"

int main() {
    int N;
    std::cin >> N;

    // Parte 1: Algoritmo de Kruskal para encontrar el Árbol de Expansión Mínima (MST)
    std::vector<std::vector<int>> distance_matrix(N, std::vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> distance_matrix[i][j];
        }
    }
    std::vector<std::pair<int, int>> mst_edges = kruskal_mst(N, distance_matrix);

    // Parte 2: Resolver el Problema del Viajante de Comercio (TSP)
    std::vector<int> tsp_path = solve_tsp(N, distance_matrix);

    // Parte 3: Algoritmo de Ford-Fulkerson
    std::vector<std::vector<int>> capacity_matrix(N, std::vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> capacity_matrix[i][j];
        }
    }
    FordFulkerson ff(N, capacity_matrix);
    ff.ComputeMaxFlow();

    // Parte 4: Encontrar la central más cercana
    std::vector<Point> centrales;
    Point query;
    read_centrales(N, centrales, query);
    Point closest_central = find_nearest_central(centrales, query);

    // Imprimir resultados
    print_mst(mst_edges);
    print_tsp(tsp_path);
    ff.PrintMaxFlow();
    print_nearest_central(closest_central);

    return 0;
}
