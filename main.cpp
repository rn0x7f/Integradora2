#include <iostream>
#include <vector>
#include "include/KruskalLib.h"

int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> distance_matrix(N, std::vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> distance_matrix[i][j];
        }
    }

    std::vector<std::pair<int, int>> mst_edges = kruskal_mst(N, distance_matrix);
    
    printMST(mst_edges);

    return 0;
}
