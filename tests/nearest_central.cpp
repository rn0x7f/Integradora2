
// tests/nearest_central.cpp
#include "../include/NearestCentralLib.h"
#include <gtest/gtest.h>
#include <sstream>


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

TEST(NearestCentralTest, ParsePoint) {
    std::string input = "(400,300)";
    Point result = parse_point(input);
    EXPECT_EQ(result.x, 400);
    EXPECT_EQ(result.y, 300);
}

TEST(NearestCentralTest, ReadCentrales) {
    // Asegurarse de que las cadenas tengan el formato adecuado.
    std::istringstream input_stream("(400,300)\n(100,200)\n(300,400)\n");
    std::cin.rdbuf(input_stream.rdbuf());  // Redirigir cin a input_stream

    std::vector<Point> centrales;
    Point query;
    read_centrales(3, centrales, query);

    // Verificar que las centrales y el punto de consulta se leyeron correctamente
    EXPECT_EQ(centrales.size(), 3);
    EXPECT_EQ(centrales[0].x, 400);
    EXPECT_EQ(centrales[0].y, 300);
    EXPECT_EQ(query.x, 300);
    EXPECT_EQ(query.y, 400);
}

TEST(NearestCentralTest, PrintNearestCentral) {
    Point central = {450, 150};

    testing::internal::CaptureStdout();  // Capturar la salida estándar
    print_nearest_central(central);
    std::string output = testing::internal::GetCapturedStdout();

    // Verificar que la salida sea la esperada
    EXPECT_EQ(output, "4.\n(450,150)\n");
}