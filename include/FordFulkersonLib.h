
#ifndef FORDFULKERSONLIB_H
#define FORDFULKERSONLIB_H

#include <vector>
#include <queue>
#include <climits>
#include <iostream>

/**
 * @brief Clase que implementa el algoritmo de Ford-Fulkerson para calcular el flujo máximo en un grafo.
 */
class FordFulkerson {
public:
    /**
     * @brief Estructura que representa una arista en el grafo para el algoritmo de Ford-Fulkerson.
     *
     * Cada arista contiene el nodo destino, la capacidad, el flujo actual y un puntero a la arista inversa.
     */
    struct FFEdge {
        int to;         ///< Nodo destino de la arista.
        int capacity;   ///< Capacidad de la arista.
        int flow;       ///< Flujo actual a través de la arista.
        FFEdge* reverse;///< Puntero a la arista inversa.

        /**
         * @brief Constructor para crear una arista.
         * 
         * @param to Nodo destino de la arista.
         * @param capacity Capacidad de la arista.
         */
        FFEdge(int to, int capacity);

        /**
         * @brief Retorna la capacidad restante en la arista.
         * 
         * @return int Capacidad restante.
         */
        int remaining() const;

        /**
         * @brief Agrega flujo a la arista y actualiza la arista inversa.
         * 
         * @param amount Cantidad de flujo a agregar.
         */
        void addFlow(int amount);
    };

    /**
     * @brief Constructor para inicializar la instancia de FordFulkerson.
     * 
     * Construye la lista de adyacencia a partir de la matriz de capacidades.
     * 
     * @param n Número de nodos en el grafo.
     * @param capacityMatrix Matriz de capacidades del grafo.
     */
    FordFulkerson(int n, const std::vector<std::vector<int>>& capacityMatrix);

    /**
     * @brief Calcula el flujo máximo utilizando el algoritmo de Ford-Fulkerson.
     * 
     * Utiliza una búsqueda en anchura (BFS) para encontrar caminos aumentantes.
     * 
     * @return int Flujo máximo encontrado.
     */
    int computeMaxFlow();

    /**
     * @brief Imprime el flujo máximo calculado.
     */
    void printMaxFlow();

private:
    int n_;   ///< Número de nodos en el grafo.
    std::vector<std::vector<FFEdge*>> ffAdj_; ///< Lista de adyacencia para las aristas.
    int maxFlow_; ///< Flujo máximo calculado.
};

#endif // FORDFULKERSONLIB_H
