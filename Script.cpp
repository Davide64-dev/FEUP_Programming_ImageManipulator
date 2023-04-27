#include <iostream>
#include <fstream>
#include "Script.hpp"
#include "PNG.hpp"
#include "XPM2.hpp"

using namespace std;

namespace prog {
    // Use to read color values from a script file.
    istream& operator>>(istream& input, Color& c) {
        int r, g, b;
        input >> r >> g >> b;
        c.red() = r;
        c.green() = g;
        c.blue() = b;
        return input;
    }

    Script::Script(const string& filename) :
            image(nullptr), input(filename) {

    }
    void Script::clear_image_if_any() {
        if (image != nullptr) {
            delete image;
            image = nullptr;
        }
    }
    Script::~Script() {
        clear_image_if_any();
    }

    void Script::run() {
        string command;
        while (input >> command) {
            cout << "Executing command '" << command << "' ..." << endl;
            
            //Script commands for initialization and I/O
            if (command == "open") {
                open();
                continue;
            }
            if (command == "blank") {
                blank();
                continue;
            }
            if (command == "save") {
                save();
                continue;
            } 
            
            //Script commands for simple image manipulations (image dimensions are not altered)
            if (command == "invert") {
                invert();
                continue;
            }

            if (command == "fill") {
                fill();
                continue;
            }

            if (command == "to_gray_scale") {
                to_gray_scale();
                continue;
            }

            if (command == "replace") {
                replace();
                continue;
            }
        }
    }
    
    void Script::open() {
        // Replace current image (if any) with image read from PNG file.
        clear_image_if_any();
        string filename;
        input >> filename;
        image = loadFromPNG(filename);
    }
    void Script::blank() {
        // Replace current image (if any) with blank image.
        clear_image_if_any();
        int w, h;
        Color fill;
        input >> w >> h >> fill;
        image = new Image(w, h, fill);
    }
    void Script::save() {
        // Save current image to PNG file.
        string filename;
        input >> filename;
        saveToPNG(filename, image);
    }
    void Script::invert() {
        //invert Color of image
        for (int y = 0; y < image->height(); y++){
            for (int x = 0; x < image->width(); x++){
                Color& pixel = image->at(x,y);
                    pixel.red() = 255 - pixel.red();
                    pixel.green() = 255 - pixel.green();
                    pixel.blue() = 255 - pixel.blue();
            }
        }
    }
    void Script::fill() {
        //fill with a color partial of the image
        int x, y, w, h, r, g, b;
        input >> x >> y >> w >> h >> r >> g >> b;
        Color _fill(r,g,b);

        for (int i = y; i < y + h; i++){
            for (int j = x; j < x + w; j++){
                image->at(j,i) = _fill;
            }
        }
    }
    void Script::to_gray_scale() {
        //gray tone of the image
        for (int y = 0; y < image->height(); y++){
            for (int x = 0; x < image->width(); x++){
                Color& pixel = image->at(x,y);
                int v = (pixel.red()+pixel.green()+pixel.blue())/3;
                Color gray_tone(v,v,v);
                image->at(x,y) = gray_tone;
            }
        }
    }

    void Script::replace() {
        //replace all pixels of color1 to color2
        int r1, g1, b1, r2, g2, b2;
        input >> r1 >> g1 >> b1 >> r2 >> g2 >> b2;
        Color _original(r1,g1,b1), _replace(r2,g2,b2);
        
        for (int y = 0; y < image->height(); y++){
            for (int x = 0; x < image->width(); x++){
                Color& pixel = image->at(x,y);
                if (pixel.red() == r1 and pixel.green() == g1 and pixel.blue() == b1){
                    image->at(x,y) = _replace;
                }
            }
        }
    }

}
