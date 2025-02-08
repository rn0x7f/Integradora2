
#include "../include/KruskalLib.h"

std::vector<std::pair<int, int>> kruskal_mst(int N, const std::vector<std::vector<int>>& distance_matrix) {
    std::vector<Edge> edges;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int weight = distance_matrix[i][j];
            if (weight > 0) {
                edges.emplace_back(i, j, weight);
            }
        }
    }
    
    std::sort(edges.begin(), edges.end());
    UnionFind uf(N);
    std::vector<std::pair<int, int>> mst_edges;

    for (const Edge& e : edges) {
        if (uf.Find(e.u) != uf.Find(e.v)) {
            uf.Unite(e.u, e.v);
            mst_edges.emplace_back(e.u, e.v);
        }
    }

    return mst_edges;
}

void print_mst(const std::vector<std::pair<int, int>>& mst_edges) {
    std::cout << "1." << std::endl;
    for (const auto& edge : mst_edges) {
        char u = 'A' + edge.first;
        char v = 'A' + edge.second;
        std::cout << "(" << u << ", " << v << ")" << std::endl;
    }
}
