#include "Image.hpp"
#include <iostream>
namespace prog
{
  Image::Image(int w, int h, const Color &fill)
  {
    Color temp = fill;
    this->width_ = w;
    this->height_ = h;

    for (int i = 0; i < h;i++){
      for (int j = 0; j < w;j++){
        this->_image[i].push_back(temp);
      }
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

  Color& Image::at(int x, int y)
  {
    return this->_image[y][x];
  }

  const Color& Image::at(int x, int y) const
  {
    return this->_image[y][x];
  }
}
