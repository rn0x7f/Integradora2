
#include "include/TravelingLib.h"

/**
 * @brief Resuelve el problema del Viajante de Comercio (TSP) mediante un enfoque de fuerza bruta.
 * 
 * Calcula el recorrido más corto visitando todos los nodos exactamente una vez, regresando al nodo de inicio.
 * 
 * @param N Número de nodos en el grafo.
 * @param distance_matrix Matriz de distancias entre los nodos.
 * @return std::vector<int> El recorrido más corto de los nodos.
 */
std::vector<int> solve_tsp(int N, const std::vector<std::vector<int>>& distance_matrix) {
    // Inicializa los nodos a visitar (excepto el nodo 0)
    std::vector<int> tsp_nodes;
    for (int i = 1; i < N; ++i) tsp_nodes.push_back(i);

    int min_tsp_dist = INT_MAX;  // Distancia mínima encontrada
    std::vector<int> best_path;  // Mejor camino encontrado

    // Fuerza bruta: probar todas las permutaciones de nodos
    do {
        int current_dist = distance_matrix[0][tsp_nodes[0]];  // Distancia desde el nodo 0 al primero
        // Sumar las distancias entre los nodos de la permutación
        for (int i = 0; i < tsp_nodes.size() - 1; ++i) {
            current_dist += distance_matrix[tsp_nodes[i]][tsp_nodes[i + 1]];
        }
        current_dist += distance_matrix[tsp_nodes.back()][0];  // Regresar al nodo 0

        // Actualizar el mejor camino si se encuentra uno más corto
        if (current_dist < min_tsp_dist || (current_dist == min_tsp_dist && tsp_nodes < best_path)) {
            min_tsp_dist = current_dist;
            best_path = tsp_nodes;
        }
    } while (std::next_permutation(tsp_nodes.begin(), tsp_nodes.end()));  // Generar siguiente permutación

    return best_path;
}

/**
 * @brief Imprime el recorrido óptimo para el TSP.
 * 
 * @param tsp_path El recorrido óptimo encontrado por el TSP.
 */
void print_tsp(const std::vector<int>& tsp_path) {
    std::cout << "2." << std::endl;
    std::cout << "A ";
    for (int node : tsp_path) {
        std::cout << char('A' + node) << " ";
    }
    std::cout << "A" << std::endl;
}
