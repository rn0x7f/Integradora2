#include "../include/FordFulkersonLib.h"
#include <gtest/gtest.h>

TEST(FordFulkersonTest, BasicFlow) {
    std::vector<std::vector<int>> capacity = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };
    
    FordFulkerson ff(6, capacity);
    int maxFlow = ff.ComputeMaxFlow();  // Usar el valor devuelto
    EXPECT_EQ(maxFlow, 23);
}
