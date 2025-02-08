
#include "../include/NearestCentralLib.h"

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
        
        // Verificar si la línea no está vacía y tiene un formato correcto
        if (!s.empty()) {
            try {
                centrales.push_back(parse_point(s));
            } catch (const std::exception& e) {
                std::cerr << "Error al parsear punto: " << s << std::endl;
                continue;  // Si ocurre un error, continuamos con la siguiente línea
            }
        } else {
            std::cerr << "Línea vacía detectada, ignorando..." << std::endl;
        }
    }

    std::string query_s;
    std::getline(std::cin >> std::ws, query_s);

    // Verificar que la línea del punto de consulta no esté vacía
    if (!query_s.empty()) {
        try {
            query = parse_point(query_s);
        } catch (const std::exception& e) {
            std::cerr << "Error al parsear punto de consulta: " << query_s << std::endl;
        }
    } else {
        std::cerr << "Línea vacía detectada para el punto de consulta, ignorando..." << std::endl;
    }
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
