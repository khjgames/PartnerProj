#pragma once

#include <vector> // Experimental ~ coded to learn, with guesswork by Kieran J

class ReadImage {
public:
    static std::vector<std::vector<unsigned int>> ReadPNG(const char* filename, int& width, int& height);
};