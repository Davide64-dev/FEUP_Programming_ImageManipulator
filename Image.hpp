#ifndef __prog_Image_hpp__
#define __prog_Image_hpp__
#include "Color.hpp"
#include <vector>
using namespace std;

namespace prog
{
  class Image
  {
  private:
    int width_;
    int height_;
    vector<vector<Color>> _image;
  public:
    Image(int w, int h, const Color &fill = Color(255,255,255)); //default color is white
    ~Image();
    int width() const;
    int height() const;
    Color &at(int x, int y);
    const Color &at(int x, int y) const;
  };
}
#endif
