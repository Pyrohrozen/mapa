#include "TerrainMap.h"
#include <fstream>
#include <exception>
#include <iostream>
#include <numeric>

TerrainMap::TerrainMap(int n, int m) : altitude(n,m), access_count(n,m), nx(n), ny(m) {
    altitude.zero(); access_count.zero();
}

TerrainMap::TerrainMap(int n, int m, std::string filename) : TerrainMap(n,m) {
    std::ifstream input_file(filename);

    if (!input_file) throw std::runtime_error("Cannot open file " + filename);

    int a; int i=0;
    while (input_file >> a) {
        altitude.flattened(i) = a; i++;
    }

    if (i != nx*ny) throw std::runtime_error("Inappropriate format of input data");
}

int TerrainMap::alt(int x, int y) {
    if (x < 0 || x >= nx || y < 0 || y >= ny) throw std::runtime_error("Coordinates out of bounds [" + std::to_string(x) + ", " + std::to_string(y) + "]");
    access_count(x,y)++;
    return altitude(x,y);
}

int TerrainMap::alt(Point const& v) {
    return alt(v.x,v.y);
}

void TerrainMap::outputStats() {
    long long sum = 0;

    std::vector<Point> multiple_hits;
    for (int i = 0; i < nx; ++i)
        for (int j = 0; j < ny; ++j)
            if (access_count(i,j) > 1) {
                multiple_hits.push_back({i,j});
                sum += access_count(i,j);
            }

    std::cout << "Total " << sum << "map queries." << std::endl;

    if (multiple_hits.size() > 0) {
        std::cout << "Detected " << multiple_hits.size() << " multiple queries:" << std::endl;
        for (Point p : multiple_hits)
            std::cout << "[" << p.x << "," << p.y << "] = " << access_count(p.x,p.y) << " hits" << std::endl;
    }
}

bool TerrainMap::validCoords(Point p) const {
    if (p.x >= 0 && p.x < nx && p.y >= 0 && p.y < ny) return true;
    else return false;
}