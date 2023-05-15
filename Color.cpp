#include "Color.hpp"
#include <string>
#include <map>
#include <sstream>
#include <iomanip>
using namespace std;

namespace prog {
    /**
     * @brief Default constructor of the class Color. Default color is black.
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
     * @param Color Color that will be copied
     */
    Color::Color(const Color& other) {
        this->red_ = other.red();
        this->green_ = other.green();
        this->blue_ = other.blue();

    }

    /**
     * @brief Color constructor using the hexadecimal string representation of a color 
     * in the format #RRGGBB
     * 
     * @param hex The hexadecimal representation of the color
     */
    Color::Color(const std::string& hex){
        std::string red, green, blue;
        red = hex.substr(1, 2);
        green = hex.substr(3, 2);
        blue = hex.substr(5, 2);
        this->red_ = std::stoi(red, nullptr, 16);
        this->green_ = std::stoi(green, nullptr, 16);
        this->blue_ = std::stoi(blue, nullptr, 16);
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

    /**
     * @brief Color inverter. Every component of the Color is inverted
     * 
     */
    void Color::invert(){
        red_ = 255 - red_;
        green_ = 255 - green_;
        blue_ = 255 - blue_;
    }

    /**
     * @brief Converts the color to gray scale
     * 
     */
    void Color::to_gray_scale(){
        int k = (red_ + green_ + blue_)/3;
        red_ = k;
        green_ = k;
        blue_= k; 
    }

    /**
     * @brief Override of the '<' operator. Compares red components,
     *  then green (if reds are equal), then blue (if greens are also equal)
     * 
     * @param other Color that will be compared
     * @return true If red value is larger, or if reds are equal and green is larger,
     *  or if reds and greens are equal and blue is larger
     * @return false Otherwise
     */
    bool Color::operator<(const Color& other) const{
        if (red_ == other.red()){
            if (green_ == other.green()){
                return blue_ < other.blue();
            }
            return green_ < other.green();
        }
        return red_ < other.red();
    }

    /**
     * @brief Overide of the '==' operator
     * 
     * @param other Color that will be compared
     * @return true If the red, green and blue components are equal for both colors
     * @return false Otherwise
     */
    bool Color::operator==(const Color& other) const{
        return red_ == other.red() and green_ == other.green() and blue_ == other.blue();
    }

    /**
     * @brief Override of the '=' operator
     * 
     * @param other Color that will be assigned
     * @return Color& The assigned Color
     */
    Color& Color::operator=(const Color& other){
        red_ = other.red();
        green_ = other.green();
        blue_ = other.blue();
        return *this;
    }

    /**
     * @brief Override of the '-' operator.
     *  Subtracts the rgb values of 'other' to the color's corresponding values
     * 
     * @param other Color whose components will be used for subtraction
     * @return Color& The final color
     */
    Color& Color::operator-(const Color& other){
        red_ -= other.red();
        green_ -= other.green();
        blue_ -= other.blue();
        return *this;
    }

    /**
     * @brief Creates a string that corresponds to the hexadecimal
     *  representation of the Color in the format #RRGGBB
     * 
     * @return std::string The hexadecimal representation of the color
     */
    std::string Color::toHex() const{
        string HexCode = "#";
        HexCode += intToHex(red_);
        HexCode += intToHex(green_);
        HexCode += intToHex(blue_);
        return HexCode;
    }

    /**
     * @brief Transforms an integer value in the range [0, 255]
     *  into its hexadecimal representation in string format
     * 
     * @param num Number to be transformed
     * @return std::string The number's hexadecimal representation
     */
    std::string Color::intToHex(int num){
        string HexCode = "";
        int first = num / 16;
        int second = num % 16;
        map<int, char> converter = {{10, 'A'}, {11, 'B'},{12, 'C'}, {13, 'D'},{14, 'E'}, {15, 'F'}};
        
        if (first >= 10) HexCode.push_back(converter[first]);
        else HexCode.push_back(to_string(first)[0]);

        if (second >= 10) HexCode.push_back(converter[second]);
        else HexCode.push_back(to_string(second)[0]);

        return HexCode;
    }

}