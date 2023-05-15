#include "XPM2.hpp"
#include <fstream>
#include <iostream>
#include <unordered_map>

namespace prog {
    Image* loadFromXPM2(const std::string& file) {
        std::ifstream input(file);
        std::unordered_map<string, Color> char_colors;
        string line;
        int width, height, n, char_per_color;
        input >> line;
        input >> line;
        input >> width >> height >> n >> char_per_color;
        for (int i = 0; i < n; i++){
            string character;
            input >> character;
            input >> line;
            input >> line;
            char_colors[character] = Color(line);
        }
        Image* image = new Image(width, height);
        for (int i = 0; i < height; i++){
            input >> line;
            for (int j = 0; j < width; j++){
                image->at(j, i) = char_colors[line.substr(j, 1)];
            }
        }

        return image;
    }

    void saveToXPM2(const std::string& file, const Image* image) {
        ofstream out(file);
        out << "! XPM2\n";
        map<Color, string> colors = image->colorsToASCII();
        out << image->width() << " " << image->height() << " " << colors.size() << " 1\n";
        
        for (auto pair : colors){
            cout << pair.first.blue();
            out << pair.second << " " << "c "; 
            out << pair.first.toHex() << '\n';
        }

        for (int i = 0; i < image->height();i++){
            for (int j = 0; j < image->width();j++){
                out << colors[image->at(j, i)];
            }
            out << '\n';
        }
        
    }
}
