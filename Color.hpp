#ifndef __prog_Color_hpp__
#define __prog_Color_hpp__

namespace prog
{ 
  /**
   * @brief unsinged char that represents an rgb_value in the range [0, 255]
   * 
   */
  typedef unsigned char rgb_value;

  /**
   * @brief This class is used to represent a color in the RGB representation system
   * 
   */
  class Color
  {
    private:
      rgb_value red_;
      rgb_value green_;
      rgb_value blue_;
    public:
      Color();
      Color(const Color& c);
      Color(rgb_value r, rgb_value g, rgb_value b);
      rgb_value red() const;
      rgb_value& red();
      rgb_value green() const;
      rgb_value& green();
      rgb_value blue() const;
      rgb_value& blue();
  };
}
#endif
