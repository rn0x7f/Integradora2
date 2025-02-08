
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include "include/KruskalLib.h"
#include "include/TravelingLib.h"

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
    // Ejecutar Kruskal para encontrar el MST
    std::vector<std::pair<int, int>> mst_edges = kruskal_mst(N, distance_matrix);
    // Imprimir el MST
    print_mst(mst_edges);

    // Parte 2: Resolver el Problema del Viajante de Comercio (TSP)
    std::vector<int> tsp_path = solve_tsp(N, distance_matrix);
    // Imprimir el mejor camino encontrado para el TSP
    print_tsp(tsp_path);

    return 0;
}
