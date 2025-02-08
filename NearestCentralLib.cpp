
#include "include/NearestCentralLib.h"

/**
 * @brief Parsea una cadena de la forma "(x,y)" y la convierte en un objeto Point.
 */
Point parse_point(const std::string& s) {
    std::string content = s.substr(1, s.size() - 2);
    size_t comma = content.find(',');
    int x = std::stoi(content.substr(0, comma));
    int y = std::stoi(content.substr(comma + 1));
    return Point(x, y);
}

/**
 * @brief Lee la lista de centrales y el punto de consulta desde la entrada estándar.
 */
void read_centrales(int N, std::vector<Point>& centrales, Point& query) {
    centrales.reserve(N);
    for (int i = 0; i < N; ++i) {
        std::string s;
        std::getline(std::cin >> std::ws, s);
        centrales.push_back(parse_point(s));
    }

    std::string query_s;
    std::getline(std::cin >> std::ws, query_s);
    query = parse_point(query_s);
}

/**
 * @brief Calcula la distancia euclidiana al cuadrado entre dos puntos.
 */
double squared_distance(const Point& p1, const Point& p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return dx * dx + dy * dy;
}

/**
 * @brief Encuentra la central más cercana a un punto de consulta.
 */
Point find_nearest_central(const std::vector<Point>& centrales, const Point& query) {
    Point closest_central = centrales[0];
    double min_dist = squared_distance(query, closest_central);

    for (const Point& central : centrales) {
        double dist = squared_distance(query, central);
        if (dist < min_dist) {
            min_dist = dist;
            closest_central = central;
        }
    }
    return closest_central;
}

/**
 * @brief Imprime la central más cercana en el formato correcto.
 */
void print_nearest_central(const Point& central) {
    std::cout << "4.\n(" << central.x << "," << central.y << ")\n";
}
