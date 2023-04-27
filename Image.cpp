#include "Image.hpp"

namespace prog
{
  Image::Image(int w, int h, const Color &fill){
    //create image with width w, height h, and all pixels set to color fill
    this->width_ = w;
    this->height_ = h;

    //it creates a matrix vector with the h and w dimensions and fill it with "fill" color
    this->_image = vector<vector<Color>>(h, vector<Color>(w, fill));
  }

  Image::~Image(){
    //destructor. Only use it if you use dynamically allocated memory explicitly.
  }

  //get image width and height
  int Image::width() const{
    return this->width_;
  }
  int Image::height() const{
    return this->height_;
  }

  //get mutable reference to the value of pixel (x,y)
  //width x, height y
  Color& Image::at(int x, int y){
    return this->_image[y][x];
  }

  //get read-only reference to the value of pixel (x,y)
  const Color& Image::at(int x, int y) const{
    return this->_image[y][x];
  }
}