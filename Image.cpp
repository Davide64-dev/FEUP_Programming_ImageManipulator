#include "Image.hpp"
#include <iostream>
namespace prog
{
  //create image with width w, height h, and all pixels set to color fill
  Image::Image(int w, int h, const Color &fill){
    Color temp = fill;
    this->width_ = w;
    this->height_ = h;

    for (int i = 0; i < h;i++){
      for (int j = 0; j < w;j++){
        this->_image[i].push_back(temp);
      }
    }
  }

  //destructor. Only use it if you use dynamically allocated memory explicitly.
  Image::~Image(){
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
