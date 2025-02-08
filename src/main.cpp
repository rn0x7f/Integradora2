
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
#include "../include/KruskalLib.h"
#include "../include/TravelingLib.h"
#include "../include/FordFulkersonLib.h"
#include "../include/NearestCentralLib.h"

std::vector<std::pair<int, int>> run_kruskal(int N, const std::vector<std::vector<int>>& distance_matrix) {
    return kruskal_mst(N, distance_matrix);
}

std::vector<int> run_tsp(int N, const std::vector<std::vector<int>>& distance_matrix) {
    return solve_tsp(N, distance_matrix);
}

FordFulkerson run_ford_fulkerson(int N, const std::vector<std::vector<int>>& capacity_matrix) {
    FordFulkerson ff(N, capacity_matrix);
    ff.ComputeMaxFlow();
    return ff;
}

Point run_nearest_central(int N, std::vector<Point>& centrales) {
    Point query;
    read_centrales(N, centrales, query);
    return find_nearest_central(centrales, query);
}

void print_results(const std::vector<std::pair<int, int>>& mst_edges, const std::vector<int>& tsp_path, const FordFulkerson& ff, const Point& closest_central) {
    print_mst(mst_edges);
    print_tsp(tsp_path);
    ff.PrintMaxFlow();
    print_nearest_central(closest_central);
}

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
    
    // Parte 2: Resolver el Problema del Viajante de Comercio (TSP)
    std::vector<int> tsp_path = run_tsp(N, distance_matrix);
    
    // Parte 3: Algoritmo de Ford-Fulkerson
    std::vector<std::vector<int>> capacity_matrix(N, std::vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> capacity_matrix[i][j];
        }
    }
    
    FordFulkerson ff = run_ford_fulkerson(N, capacity_matrix);
    
    // Parte 4: Encontrar la central más cercana
    std::vector<Point> centrales;
    Point closest_central = run_nearest_central(N, centrales);
    
    // Imprimir resultados
    print_results(run_kruskal(N, distance_matrix), tsp_path, ff, closest_central);
    
    return 0;
}
