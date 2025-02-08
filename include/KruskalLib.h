
#ifndef KRUSKALLIB_H
#define KRUSKALLIB_H

#include <vector>
#include <algorithm>
#include <iostream>

struct Edge {
    int u, v, weight;
    Edge(int u, int v, int w) : u(u), v(v), weight(w) {}
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

struct UnionFind {
    std::vector<int> parent;
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int u) {
        if (parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }
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
