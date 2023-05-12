#include <iostream>
#include <fstream>
#include "Script.hpp"
#include "PNG.hpp"
#include "XPM2.hpp"

using namespace std;

namespace prog {
    
    /**
     * @brief Override of '>>' operator
     * 
     * @param input The input variable
     * @param c The color that will be assigned
     * @return istream& 
     */
    istream& operator>>(istream& input, Color& c) {
    // Use to read color values from a script file.
        int r, g, b;
        input >> r >> g >> b;
        c.red() = r;
        c.green() = g;
        c.blue() = b;
        return input;
    }

    /**
     * @brief Script constructor
     * 
     * @param filename The filename of the input script
     */
    Script::Script(const string& filename) :
            image(nullptr), input(filename) {

    }

    /**
     * @brief Clear the image
     * 
     */
    void Script::clear_image_if_any() {
        if (image != nullptr) {
            delete image;
            image = nullptr;
        }
    }

    /**
     * @brief Destructor of Script
     * 
     */
    Script::~Script() {
        clear_image_if_any();
    }

    /**
     * @brief Main runner of the scripts
     * 
     */
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
                image->invert();
                continue;
            }

            if (command == "fill") {
                int x, y, w, h, r, g, b;
                input >> x >> y >> w >> h >> r >> g >> b;
                Color _fill(r,g,b);
                image->fill(x,y,w,h,_fill);
                continue;
            }

            if (command == "to_gray_scale") {
                image->to_gray_scale();
                continue;
            }

            if (command == "replace") {
                int r1, g1, b1, r2, g2, b2;
                input >> r1 >> g1 >> b1 >> r2 >> g2 >> b2;
                Color _original(r1,g1,b1), _replace(r2,g2,b2);
                image->replace(_original, _replace);
                continue;
            }

            if (command == "h_mirror") {
                image->h_mirror();
                continue;
            }

            if (command == "v_mirror") {
                image->v_mirror();
                continue;
            }

            if (command == "crop") {
                int x, y, w, h;
                input >> x >> y >> w >> h;
                image->crop(x,y,w,h);
                continue;
            }

            if (command == "rotate_left") {
                image->rotate_left();
                continue;
            }

            if (command == "rotate_right") {
                image->rotate_right();
                continue;
            }

            if (command == "add") {
                string filename;
                input >> filename;
                Image *image_add = loadFromPNG(filename);
                int r, g, b, x, y;
                input >> r >> g >> b >> x >> y;
                Color neutral_color(r,g,b);
                image->add(image_add,neutral_color,x,y);
                continue;
            }

            if (command == "median_filter"){
                int wd;
                input >> wd;
                image->median_filter(wd);
                continue;
            }

            if (command == "xpm2_open"){
                xpm2_open();
                continue;
            }

            if (command == "xpm2_save"){
                xpm2_save();
                continue;
            }
        }
    }
    
    /**
     * @brief Auxiliary function that opens a given .png file
     * 
     */
    void Script::open() {
        // Replace current image (if any) with image read from PNG file.
        clear_image_if_any();
        string filename;
        input >> filename;
        image = loadFromPNG(filename);
    }

    /**
     * @brief Auxiliary function that opens a given .xpm2 file
     * 
     */
    void Script::xpm2_open(){
        clear_image_if_any();
        string filename;
        input >> filename;
        image = loadFromXPM2(filename);
    }

    /**
     * @brief Auxiliary function that replaces current image (if any) with blank image.
     * 
     */
    void Script::blank() {
        clear_image_if_any();
        int w, h;
        Color fill;
        input >> w >> h >> fill;
        image = new Image(w, h, fill);
    }

    /**
     * @brief Auxiliary function that saves an image into a .png file
     * 
     */
    void Script::save() {
        // Save current image to PNG file.
        string filename;
        input >> filename;
        saveToPNG(filename, image);
    }

    /**
     * @brief Auxiliary function that saves an image into a .xpm2 file
     * 
     */
    void Script::xpm2_save(){
        string filename;
        input >> filename;
        saveToXPM2(filename, image);
    }
}