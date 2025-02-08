
#include <gtest/gtest.h>
#include "../include/TravelingLib.h"
#include <sstream>

// Caso de prueba con 4 nodos
TEST(TravelingTest, BasicTSP) {
    int N = 4;
    std::vector<std::vector<int>> distance_matrix = {
        {0, 16, 45, 32},
        {16, 0, 18, 21},
        {45, 18, 0, 7},
        {32, 21, 7, 0}
    };

    std::string expected_output = "2.\nA B C D A";

    std::vector<int> best_path = solve_tsp(N, distance_matrix);

    std::ostringstream oss;
    std::streambuf* old_buf = std::cout.rdbuf(oss.rdbuf());

    print_tsp(best_path);

    std::cout.rdbuf(old_buf);

    std::string actual_output = oss.str();
    actual_output.erase(actual_output.find_last_not_of(" \n") + 1);

    ASSERT_EQ(actual_output, expected_output);
}

// Caso de prueba con 3 nodos
TEST(TravelingTest, SmallTSP) {
    int N = 3;
    std::vector<std::vector<int>> distance_matrix = {
        {0, 10, 15},
        {10, 0, 20},
        {15, 20, 0}
    };

    std::string expected_output = "2.\nA B C A";

    std::vector<int> best_path = solve_tsp(N, distance_matrix);

    std::ostringstream oss;
    std::streambuf* old_buf = std::cout.rdbuf(oss.rdbuf());

    print_tsp(best_path);

    std::cout.rdbuf(old_buf);

    std::string actual_output = oss.str();
    actual_output.erase(actual_output.find_last_not_of(" \n") + 1);

    ASSERT_EQ(actual_output, expected_output);
}

// Caso de prueba con 5 nodos
TEST(TravelingTest, LargerTSP) {
    int N = 5;
    std::vector<std::vector<int>> distance_matrix = {
        {0, 3, 12, 8, 7},
        {3, 0, 6, 2, 4},
        {12, 6, 0, 5, 10},
        {8, 2, 5, 0, 6},
        {7, 4, 10, 6, 0}
    };

    std::string expected_output = "2.\nA B C D E A";

    std::vector<int> best_path = solve_tsp(N, distance_matrix);

    std::ostringstream oss;
    std::streambuf* old_buf = std::cout.rdbuf(oss.rdbuf());

    print_tsp(best_path);

    std::cout.rdbuf(old_buf);

    std::string actual_output = oss.str();
    actual_output.erase(actual_output.find_last_not_of(" \n") + 1);

    ASSERT_EQ(actual_output, expected_output);
}
