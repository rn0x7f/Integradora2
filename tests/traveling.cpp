#include <gtest/gtest.h>
#include "../include/TravelingLib.h"
#include <sstream>

// Caso de prueba único para resolver el TSP con el grafo dado
TEST(TravelingTest, BasicTSP) {
    int N = 4;
    std::vector<std::vector<int>> distance_matrix = {
        {0, 16, 45, 32},
        {16, 0, 18, 21},
        {45, 18, 0, 7},
        {32, 21, 7, 0}
    };

    // El recorrido esperado ahora incluye el regreso al punto A
    std::string expected_output = "A B C D A ";

    std::vector<int> best_path = solve_tsp(N, distance_matrix);

    // Capturar la salida de print_tsp en una stringstream
    std::ostringstream oss;
    std::streambuf* old_buf = std::cout.rdbuf(oss.rdbuf()); // Redirigir std::cout a oss

    print_tsp(best_path);  // Llamar a la función de impresión

    std::cout.rdbuf(old_buf); // Restaurar std::cout

    // Comparar la salida generada con la salida esperada
    ASSERT_EQ(oss.str(), expected_output);
}
