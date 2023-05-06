#ifndef __prog_Image_hpp__
#define __prog_Image_hpp__
#include "Color.hpp"
#include <vector>
#include <map>
using namespace std;

namespace prog
{ 
  /**
   * @brief This class is used to represent an image
   * 
   */
  class Image
  {
  private:
  /**
   * @brief Width of the image
   * 
   */
    int width_;
    /**
     * @brief Height of the image
     * 
     */
    int height_;
    /**
     * @brief Matrix of pixels (class Color) that represents the image itself
     * 
     */
    vector<vector<Color>> _image;
    
  public:
    Image(int w, int h, const Color &fill = {255, 255, 255});
    ~Image();
    int width() const;
    int height() const;
    Color &at(int x, int y);
    const Color &at(int x, int y) const;
    void invert();
    void fill(int x, int y, int w, int h, const Color &_fill);
    void to_gray_scale();
    void replace(Color _original, Color _replace);
    void h_mirror();
    void v_mirror();
    void crop(int x, int y, int w, int h);
    void rotate_left();
    void rotate_right();
    void add(Image *image_add, Color neutral_color, int x, int y);
    void median_filter(int ws);
    static int median(vector<int> vetor);
    map<Color, string> colorsToASCII() const;
  };
}
#endif