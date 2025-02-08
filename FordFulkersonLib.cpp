
#include "include/FordFulkersonLib.h"

/**
 * @brief Constructor de la estructura FFEdge.
 */
FordFulkerson::FFEdge::FFEdge(int to, int capacity)
    : to(to), capacity(capacity), flow(0), reverse(nullptr) {}

/**
 * @brief Retorna la capacidad restante en la arista.
 */
int FordFulkerson::FFEdge::Remaining() const {
    return capacity - flow;
}

/**
 * @brief Agrega flujo a la arista y actualiza la arista inversa.
 */
void FordFulkerson::FFEdge::AddFlow(int amount) {
    flow += amount;
    reverse->flow -= amount;
}

/**
 * @brief Constructor para inicializar la instancia de FordFulkerson.
 *
 * Construye la lista de adyacencia a partir de la matriz de capacidades.
 */
FordFulkerson::FordFulkerson(int n, const std::vector<std::vector<int>>& capacityMatrix)
    : n_(n), maxFlow_(0) {
    ffAdj_.resize(n_);
    for (int i = 0; i < n_; ++i) {
        for (int j = 0; j < n_; ++j) {
            int cap = capacityMatrix[i][j];
            if (cap > 0) {
                FFEdge* edge = new FFEdge(j, cap);
                FFEdge* revEdge = new FFEdge(i, 0);
                edge->reverse = revEdge;
                revEdge->reverse = edge;
                ffAdj_[i].push_back(edge);
                ffAdj_[j].push_back(revEdge);
            }
        }
    }
}

/**
 * @brief Encuentra un camino aumentante usando BFS.
 */
std::vector<FordFulkerson::FFEdge*> FordFulkerson::FindAugmentingPath(int source, int sink) {
    std::vector<FFEdge*> pred(n_, nullptr);
    std::queue<int> q;
    q.push(source);

    while (!q.empty() && pred[sink] == nullptr) {
        int u = q.front();
        q.pop();
        for (FFEdge* edge : ffAdj_[u]) {
            if (pred[edge->to] == nullptr && edge->Remaining() > 0 && edge->to != source) {
                pred[edge->to] = edge;
                q.push(edge->to);
            }
        }
    }

    return pred;
}

/**
 * @brief Actualiza el flujo a lo largo del camino aumentante.
 */
void FordFulkerson::UpdateFlow(int sink, int source, const std::vector<FFEdge*>& pred, int pathFlow) {
    for (int v = sink; v != source; v = pred[v]->reverse->to) {
        pred[v]->AddFlow(pathFlow);
    }
}

/**
 * @brief Calcula el flujo máximo utilizando el algoritmo de Ford-Fulkerson.
 *
 * Utiliza una búsqueda en anchura (BFS) para encontrar caminos aumentantes y actualiza el flujo.
 *
 * @return int Flujo máximo encontrado.
 */
int FordFulkerson::ComputeMaxFlow() {
    int source = 0;
    int sink = n_ - 1;
    maxFlow_ = 0;

    while (true) {
        // Encuentra un camino aumentante utilizando BFS
        std::vector<FFEdge*> pred = FindAugmentingPath(source, sink);

        // Si no se encontró un camino aumentante, termina el algoritmo
        if (pred[sink] == nullptr) {
            break;
        }

        // Determina el flujo mínimo en el camino aumentante
        int pathFlow = INT_MAX;
        for (int v = sink; v != source; v = pred[v]->reverse->to) {
            pathFlow = std::min(pathFlow, pred[v]->Remaining());
        }

        // Actualiza el flujo a lo largo del camino aumentante
        UpdateFlow(sink, source, pred, pathFlow);

        // Agrega el flujo del camino aumentante al flujo máximo
        maxFlow_ += pathFlow;
    }

    return maxFlow_;
}

/**
 * @brief Imprime el flujo máximo calculado.
 */
void FordFulkerson::PrintMaxFlow() {
    std::cout << "3." << std::endl;
    std::cout << maxFlow_ << std::endl;
}
