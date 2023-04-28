#include "Color.hpp"

namespace prog {
    /**
     * @brief Default constructor of the class Color. The color will be assigned with black color
     * 
     */
    Color::Color() {
        this->red_ = 0;
        this->green_ = 0;
        this->blue_ = 0;
    }
    /**
     * @brief Copy constructor
     * 
     * @param Color that will be copied
     */
    Color::Color(const Color& other) {
        this->red_ = other.red();
        this->green_ = other.green();
        this->blue_ = other.blue();

    }

    /**
     * @brief Color Constructor using supplied (r,g,b) values
     * 
     * @param red Red component of the color
     * @param green Green component of the color
     * @param blue Blue component of the color
     */
    Color::Color(rgb_value red, rgb_value green, rgb_value blue) {
        this->red_ = red;
        this->green_ = green;
        this->blue_ = blue;
    }

    /**
     * @brief Getter of the red component of the color
     * 
     * @return rgb_value red component
     */
    rgb_value Color::red() const {
        return this->red_;
    }

    /**
     * @brief Getter of the green component of the color
     * 
     * @return rgb_value green component
     */
    rgb_value Color::green() const {
        return this->green_;
    }

    /**
     * @brief Getter of the blue component of the color
     * 
     * @return rgb_value blue component
     */
    rgb_value Color::blue() const {
        return this->blue_;
    }

    /**
     * @brief Getter of reference to red component of the color
     * 
     * @return rgb_value& red component
     */
    rgb_value& Color::red()  {
        return this->red_;
    }

    /**
     * @brief Getter of reference to green component of the color
     * 
     * @return rgb_value& green component
     */
    rgb_value& Color::green()  {
      return this->green_;
    }

    /**
     * @brief Getter of reference to blue component of the color
     * 
     * @return rgb_value& blue component
     */
    rgb_value& Color::blue()  {
      return this->blue_;
    }
}
