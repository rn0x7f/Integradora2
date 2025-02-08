
#ifndef NEAREST_CENTRAL_LIB_H
#define NEAREST_CENTRAL_LIB_H

#include <vector>
#include <iostream>
#include <string>

/**
 * @brief Estructura que representa un punto en el plano cartesiano.
 */
struct Point {
    int x; ///< Coordenada X del punto.
    int y; ///< Coordenada Y del punto.

    /**
     * @brief Constructor para inicializar un punto.
     * @param x Coordenada X.
     * @param y Coordenada Y.
     */
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

/**
 * @brief Parsea una cadena de la forma "(x,y)" y la convierte en un objeto Point.
 * 
 * @param s Cadena con el formato "(x,y)".
 * @return Point Punto representado por la cadena.
 */
Point parse_point(const std::string& s);

/**
 * @brief Lee la lista de centrales y el punto de consulta desde la entrada estándar.
 * 
 * @param N Número de centrales.
 * @param centrales Vector donde se almacenarán las centrales.
 * @param query Punto de consulta.
 */
void read_centrales(int N, std::vector<Point>& centrales, Point& query);

/**
 * @brief Calcula la distancia euclidiana al cuadrado entre dos puntos.
 * 
 * @param p1 Primer punto.
 * @param p2 Segundo punto.
 * @return double Distancia euclidiana al cuadrado.
 */
double squared_distance(const Point& p1, const Point& p2);

/**
 * @brief Encuentra la central más cercana a un punto de consulta.
 * 
 * @param centrales Lista de centrales.
 * @param query Punto de consulta.
 * @return Point Central más cercana al punto de consulta.
 */
Point find_nearest_central(const std::vector<Point>& centrales, const Point& query);

/**
 * @brief Imprime la central más cercana en el formato correcto.
 * 
 * @param central Punto representando la central más cercana.
 */
void print_nearest_central(const Point& central);

#endif // NEAREST_CENTRAL_LIB_H
