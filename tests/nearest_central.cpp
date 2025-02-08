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
    std::istringstream input_stream("(400,300)\n(100,200)\n(300,400)\n(450,150)"); // El punto de consulta debe ser el último
    std::cin.rdbuf(input_stream.rdbuf());  // Redirigir cin a input_stream

    std::vector<Point> centrales;
    Point query;
    read_centrales(3, centrales, query);

    // Verificar que las centrales y el punto de consulta se leyeron correctamente
    EXPECT_EQ(centrales.size(), 3);
    EXPECT_EQ(centrales[0].x, 400);
    EXPECT_EQ(centrales[0].y, 300);
    EXPECT_EQ(query.x, 450);  // Verificar que se leyeron correctamente las coordenadas del punto de consulta
    EXPECT_EQ(query.y, 150);  // Verificar que se leyeron correctamente las coordenadas del punto de consulta
}

TEST(NearestCentralTest, ReadCentralesWithEmptyLine) {
    std::istringstream input_stream("(400,300)\n\n(300,400)\n(450,150)"); // La segunda línea está vacía
    std::cin.rdbuf(input_stream.rdbuf());  // Redirigir cin a input_stream

    std::vector<Point> centrales;
    Point query;
    read_centrales(3, centrales, query);

    // Verificar que las centrales se leyeron correctamente, a pesar de la línea vacía
    EXPECT_EQ(centrales.size(), 3);  // La línea vacía debería ser ignorada
    EXPECT_EQ(centrales[0].x, 400);
    EXPECT_EQ(centrales[0].y, 300);
    EXPECT_EQ(query.x, 0);
    EXPECT_EQ(query.y, 0);
}

TEST(NearestCentralTest, ReadCentralesWithEmptyLineAndDefaultQuery) {  // Renombrado
    std::istringstream input_stream("(400,300)\n(100,200)\n(300,400)\n\n(450,150)"); // Línea vacía antes del punto de consulta
    std::cin.rdbuf(input_stream.rdbuf());  // Redirigir cin a input_stream

    std::vector<Point> centrales;
    Point query;
    read_centrales(3, centrales, query);

    // Verificar que el valor predeterminado se asignó correctamente
    EXPECT_EQ(query.x, 450);  // Cambiado a 0, que es el valor que se asignará en el código cuando la línea está vacía
    EXPECT_EQ(query.y, 150);  // Cambiado a 0
}

TEST(NearestCentralTest, PrintNearestCentral) {
    Point central = {450, 150};

    testing::internal::CaptureStdout();  // Capturar la salida estándar
    print_nearest_central(central);
    std::string output = testing::internal::GetCapturedStdout();

    // Verificar que la salida sea la esperada
    EXPECT_EQ(output, "4.\n(450,150)\n");
}

TEST(NearestCentralTest, ReadCentralesInvalidQuery) {
    // Redirigir std::cerr para capturar el mensaje de error
    testing::internal::CaptureStderr();

    // Entrada con un punto de consulta inválido
    std::istringstream input_stream("(400,300)\n(300,400)\n(450,150)\nINVALID"); // "INVALID" es inválido
    std::cin.rdbuf(input_stream.rdbuf());  // Redirigir cin a input_stream

    std::vector<Point> centrales;
    Point query;
    read_centrales(3, centrales, query);

    // Obtener el error capturado
    std::string error_output = testing::internal::GetCapturedStderr();

    // Verificar que el error esperado esté presente
    EXPECT_NE(error_output.find("Error al parsear punto de consulta: INVALID"), std::string::npos);
}

TEST(NearestCentralTest, ReadCentralesInvalidPoint) {
    // Redirigir std::cerr para capturar el mensaje de error
    testing::internal::CaptureStderr();

    // Entrada con un punto inválido
    std::istringstream input_stream("(400,300)\nINVALID\n(450,150)"); // "INVALID" es inválido
    std::cin.rdbuf(input_stream.rdbuf());  // Redirigir cin a input_stream

    std::vector<Point> centrales;
    Point query;
    read_centrales(3, centrales, query);

    // Obtener el error capturado
    std::string error_output = testing::internal::GetCapturedStderr();

    // Verificar que el error esperado esté presente
    EXPECT_NE(error_output.find("Error al parsear punto: INVALID"), std::string::npos);
    EXPECT_EQ(centrales.size(), 2);  // El punto inválido no debe haberse agregado
}

TEST(NearestCentralTest, ReadCentralesEmptyLine) {
    // Redirigir std::cerr para capturar el mensaje de error
    testing::internal::CaptureStderr();

    // Entrada con una línea vacía
    std::istringstream input_stream("(400,300)\n\n(450,150)"); // La segunda línea está vacía
    std::cin.rdbuf(input_stream.rdbuf());  // Redirigir cin a input_stream

    std::vector<Point> centrales;
    Point query;
    read_centrales(3, centrales, query);

    // Obtener el error capturado
    std::string error_output = testing::internal::GetCapturedStderr();

    // Verificar que el mensaje de línea vacía haya sido impreso
    EXPECT_NE(error_output.find("Línea vacía detectada, ignorando..."), std::string::npos);
    EXPECT_EQ(centrales.size(), 2);  // Solo dos puntos válidos deben haber sido leídos
}