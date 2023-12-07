#include "ReadImage.h"
//#include "stb_image.h"
#include <iostream> // Experimental ~ coded to learn, with guesswork by Kieran J

using namespace std;

vector<vector<unsigned int>> ReadImage::ReadPNG(const char* filename, int &width, int &height) {
    vector<vector<unsigned int>> pixelValues;
    /*
    // Read the image using stb_image
    unsigned char* data = stbi_load(filename, &width, &height, nullptr, 4); // 4 channels for RGBA

    if (data == nullptr) {
        cerr << "Error loading image: " << filename << endl;
        return pixelValues;
    }

    // Iterate through each pixel and gather hex values
    for (int x = 0; x < width; ++x) {
        vector<unsigned int> columnValues;
        for (int y = 0; y < height; ++y) {
            // Calculate index for RGBA values
            int index = (y * width + x) * 4;

            // Convert RGBA to a hex value with transparency
            unsigned int hexValue = (data[index] << 24) | (data[index + 1] << 16) | (data[index + 2] << 8) | data[index + 3];
            columnValues.push_back(hexValue);
        }
        pixelValues.push_back(columnValues);
    }

    // Free the image data
    stbi_image_free(data);
    */
    return pixelValues;
}  