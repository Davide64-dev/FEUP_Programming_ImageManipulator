#ifndef __prog_Color_hpp__
#define __prog_Color_hpp__
#include <string>

namespace prog
{ 
  /**
   * @brief unsinged char that represents an rgb value in the range [0, 255]
   * 
   */
  typedef unsigned char rgb_value;

  /**
   * @brief This class is used to represent a color using RGB values
   * 
   */
  class Color
  {
    private:
      /**
       * @brief Red component of the Color
       * 
       */
      rgb_value red_;
      /**
       * @brief Green component of the Color
       * 
       */
      rgb_value green_;
      /**
       * @brief Blue component of the Color
       * 
       */
      rgb_value blue_;
    public:
      Color();
      Color(const Color& c);
      Color(rgb_value r, rgb_value g, rgb_value b);
      Color(const std::string& hex);
      rgb_value red() const;
      rgb_value& red();
      rgb_value green() const;
      rgb_value& green();
      rgb_value blue() const;
      rgb_value& blue();
      void invert();
      void to_gray_scale();
      bool operator<(const Color& other) const;
      bool operator==(const Color& other) const;
      Color& operator=(const Color& other);
      Color& operator-(const Color& other);
      std::string toHex() const;
      static std::string intToHex(int num);

      
  };
}
#endif
