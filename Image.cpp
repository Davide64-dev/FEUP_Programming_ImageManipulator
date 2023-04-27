#include "Image.hpp"
#include <iostream>
namespace prog
{
  Image::Image(int w, int h, const Color &fill){
    //create image with width w, height h, and all pixels set to color fill
    Color temp = fill;
    this->width_ = w;
    this->height_ = h;

    for (int i = 0; i < h;i++){
      for (int j = 0; j < w;j++){
        this->_image[i].push_back(temp);
      }
    }
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

  Color& Image::at(int x, int y){
    //get mutable reference to the value of pixel (x,y)
    //width x, height y
    return this->_image[y][x];
  }

  const Color& Image::at(int x, int y) const{
    //get read-only reference to the value of pixel (x,y)
    return this->_image[y][x];
  }
}
