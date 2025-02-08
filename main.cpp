
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
#include "include/KruskalLib.h"
#include "include/TravelingLib.h"
#include "include/FordFulkersonLib.h"


// Structure for Ford-Fulkerson's Edge
struct FFEdge {
    int to, capacity, flow;
    FFEdge* reverse;
    FFEdge(int to, int capacity) : to(to), capacity(capacity), flow(0), reverse(nullptr) {}
    int remaining() { return capacity - flow; }
    void add_flow(int amount) {
        flow += amount;
        reverse->flow -= amount;
    }
};

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

    // Parte 3 Ford-Fulkerson
    // Read capacity matrix for Ford-Fulkerson
    std::vector<std::vector<int>> capacity_matrix(N, std::vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> capacity_matrix[i][j];
        }
    }

    // Crear una instancia de FordFulkerson y calcular el flujo máximo
    FordFulkerson ff(N, capacity_matrix);
    ff.compute_max_flow();
    ff.print_max_flow();

    

    return 0;
}
