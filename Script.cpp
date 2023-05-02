#include <iostream>
#include <fstream>
#include "Script.hpp"
#include "PNG.hpp"
#include "XPM2.hpp"

using namespace std;

namespace prog {
    
    istream& operator>>(istream& input, Color& c) {
    // Use to read color values from a script file.
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

            if (command == "h_mirror") {
                h_mirror();
                continue;
            }

            if (command == "v_mirror") {
                v_mirror();
                continue;
            }

            if (command == "crop") {
                crop();
                continue;
            }

            if (command == "rotate_left") {
                rotate_left();
                continue;
            }

            if (command == "rotate_right") {
                rotate_right();
                continue;
            }

            if (command == "add") {
                add();
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
        //invert the colors of a image
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
        //fill a part of image with a solid color
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
        //grayed out a image
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
        //replace all pixel with color1 by color2
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

    void Script::h_mirror() {
        //horizontal mirror
        int h = image->height();
        int w = image->width();
        for (int y = 0; y < h; y++){
            for (int x = 0; x < w / 2; x++){
                Color temp = image->at(x,y);
                image->at(x,y) = image->at(w-1-x,y);
                image->at(w-1-x,y) = temp;
            }
        }
    }

    void Script::v_mirror() {
        //vertical mirror
        int h = image->height();
        int w = image->width();
        for (int y = 0; y < h / 2; y++){
            for (int x = 0; x < w; x++){
                Color temp = image->at(x,y);
                image->at(x,y) = image->at(x,h-1-y);
                image->at(x,h-1-y) = temp;
            }
        }
    }

    void Script::crop() {
        //crop the image starting in (x,y) this the (w,h) dimensions
        int x, y, w, h;
        input >> x >> y >> w >> h;
        Image* _crop = new Image(w,h);
        
        for (int i = y; i < y + h; i++){
            for (int j = x; j < x + w; j++){
                _crop->at(j-x,i-y) = image->at(j,i);
            }
        }

        //del the original image and set _crop as the image
        delete image;
        image = _crop;
    }

    void Script::rotate_left(){
        //rotate the image 90 degrees to the left
        int w = image->width();
        int h = image->height();

        Image* _rotated = new Image(h,w);

        for (int y = 0; y < h; y++){
            for (int x = 0; x < w; x++){
                _rotated->at(y,w-1-x) = image->at(x,y);
            }
        }
        //del the original image and set _rotated as the image
        delete image;
        image = _rotated;
    }

    void Script::rotate_right(){
        //rotate the image 90 degrees to the right
        int w = image->width();
        int h = image->height();

        Image* _rotated = new Image(h,w);

        for (int y = 0; y < h; y++){
            for (int x = 0; x < w; x++){
                _rotated->at(h-1-y,x) = image->at(x,y);
            }
        }
        //del the original image and set _rotated as the image
        delete image;
        image = _rotated;
    }

    void Script::add(){
        //overlay one image on top of another assuming that it always fits on the original image.
        //the top-left corner of the new image is placed at the position (x,y) of the original image.
    
        string filename;
        input >> filename;
        Image* image_add = loadFromPNG(filename);

        int r, g, b, x, y;
        input >> r >> g >> b >> x >> y;
        Color neutral_color(r,g,b);

        int i_ = 0;
        for (int i = y; i < y + image_add->height(); i++){
            int j_ = 0;
            for (int j = x; j < x + image_add->width(); j++){
                Color& pixel_add = image_add->at(j_,i_);
                if (neutral_color.red() != pixel_add.red() or neutral_color.green() != pixel_add.green() or neutral_color.blue() != pixel_add.blue()){
                    image->at(j,i) = image_add->at(j_,i_);
                }
                j_++;
            }
            i_++;
        }
        delete image_add;
    }



}
