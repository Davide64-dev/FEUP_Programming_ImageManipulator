#include "Image.hpp"
#include <iostream>
namespace prog
{
  Image::Image(int w, int h, const Color &fill)
  {
    Color temp = fill;
    this->width_ = w;
    this->height_ = h;
    cout << width_;
    for (int i = 0; i < h;i++){
      for (int j = 0; j < w;j++){
        this->_image[i].push_back(temp);
      }
    }
    for (int i = 0; i < height_;i++){
      for (int j = 0; j < width_;j++){
        cout << i << " " << j;
      }
      cout << '\n';
    }



  }
  Image::~Image()
  {
  }
  int Image::width() const
  {
    return this->width_;
  }
  int Image::height() const
  {
    return this->height_;
  }

  // TODO: remove this DUMMY_color variable once you have appropriate fields for representing image pixels.
  Color DUMMY_color;

  Color& Image::at(int x, int y)
  {
    return DUMMY_color;
  }

  const Color& Image::at(int x, int y) const
  {
    return DUMMY_color;
  }
}
