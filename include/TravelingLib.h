
#ifndef TRAVELINGLIB_H
#define TRAVELINGLIB_H

#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>


/**
 * @brief Resuelve el problema del Viajante de Comercio (TSP) usando el algoritmo de fuerza bruta.
 * 
 * @param N Número de nodos en el grafo.
 * @param distance_matrix Matriz de distancias entre las ciudades.
 * @return std::vector<int> El mejor recorrido encontrado para el TSP.
 */
std::vector<int> solve_tsp(int N, const std::vector<std::vector<int>>& distance_matrix);

/**
 * @brief Imprime el recorrido óptimo para el TSP.
 * 
 * @param tsp_path El recorrido óptimo encontrado por el TSP.
 */
void print_tsp(const std::vector<int>& tsp_path);

#endif // TRAVELINGLIB_H
