
// tests/nearest_central.cpp
#include "../include/NearestCentralLib.h"
#include <gtest/gtest.h>

TEST(NearestCentralTest, ClosestPoint) {
    std::vector<Point> centrales = {
        {200, 500},
        {300, 100},
        {450, 150},
        {520, 480}
    };
    Point query = {400, 300};
    
    Point closest = find_nearest_central(centrales, query);
    EXPECT_EQ(closest.x, 450);
    EXPECT_EQ(closest.y, 150);
}
