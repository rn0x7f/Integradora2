
#ifndef KRUSKALLIB_H
#define KRUSKALLIB_H

#include <vector>
#include <algorithm>
#include <iostream>

/**
 * @brief Estructura que representa una arista en el grafo.
 * 
 * Cada arista tiene un vértice de inicio, un vértice de destino y un peso.
 */
struct Edge {
    int u, v, weight; ///< Vértices de la arista y su peso.

    /**
     * @brief Constructor para crear una arista.
     * 
     * @param u Vértice de inicio de la arista.
     * @param v Vértice de destino de la arista.
     * @param w Peso de la arista.
     */
    Edge(int u, int v, int w) : u(u), v(v), weight(w) {}

    /**
     * @brief Operador de comparación para ordenar aristas por peso.
     * 
     * Compara el peso de dos aristas.
     * 
     * @param other Otra arista a comparar.
     * @return true Si el peso de la arista actual es menor que el de la otra.
     * @return false Si el peso de la arista actual no es menor que el de la otra.
     */
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

/**
 * @brief Estructura para representar el conjunto disjunto (Union-Find).
 * 
 * Se usa para gestionar y unir componentes en Kruskal's algorithm.
 */
struct UnionFind {
    std::vector<int> parent; ///< Arreglo para rastrear los padres de cada nodo.

    /**
     * @brief Constructor para crear el conjunto disjunto con N elementos.
     * 
     * Inicializa cada nodo con su propio padre.
     * 
     * @param n Número de elementos en el conjunto.
     */
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    /**
     * @brief Encuentra el representante del conjunto al que pertenece el nodo.
     * 
     * @param u Nodo del cual encontrar el representante.
     * @return int El representante del conjunto al que pertenece el nodo.
     */
    int find(int u) {
        if (parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }

    /**
     * @brief Une dos conjuntos disjuntos.
     * 
     * Si los nodos u y v pertenecen a diferentes conjuntos, los une.
     * 
     * @param u Nodo de un conjunto.
     * @param v Nodo de otro conjunto.
     */
    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) parent[u] = v;
    }
};

/**
 * @brief Ejecuta el algoritmo de Kruskal para encontrar el árbol de expansión mínima.
 * 
 * @param N Número de nodos en el grafo.
 * @param distance_matrix Matriz de adyacencia con los pesos de las aristas.
 * @return std::vector<std::pair<int, int>> Lista de aristas en el MST.
 */
std::vector<std::pair<int, int>> kruskal_mst(int N, const std::vector<std::vector<int>>& distance_matrix);

/**
 * @brief Imprime las aristas del árbol de expansión mínima.
 * 
 * @param mst_edges Lista de aristas en el MST.
 */
void print_mst(const std::vector<std::pair<int, int>>& mst_edges);

#endif // KRUSKALLIB_H
