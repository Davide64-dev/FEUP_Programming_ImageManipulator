#include "Color.hpp"

namespace prog {
    Color::Color() {
        //default color black
        this->red_ = 0;
        this->green_ = 0;
        this->blue_ = 0;
    }
    Color::Color(const Color& other) {
        //copy constructor
        this->red_ = other.red();
        this->green_ = other.green();
        this->blue_ = other.blue();

    }
    Color::Color(rgb_value red, rgb_value green, rgb_value blue) {
        //constructor using supplied (r,g,b) values
        this->red_ = red;
        this->green_ = green;
        this->blue_ = blue;
    }

    //get values for individual RGB color channels
    rgb_value Color::red() const {
        return this->red_;
    }
    rgb_value Color::green() const {
        return this->green_;
    }
    rgb_value Color::blue() const {
        return this->blue_;
    }

    //get references for individual RGB color channels
    rgb_value& Color::red()  {
        return this->red_;
    }
    rgb_value& Color::green()  {
      return this->green_;
    }
    rgb_value& Color::blue()  {
      return this->blue_;
    }
}
