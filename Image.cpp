#include "Image.hpp"

namespace prog
{
  Image::Image(int w, int h, const Color &fill){
    //create image with width w, height h, and all pixels set to color fill

    /*
    Color temp = fill;
    this->width_ = w;
    this->height_ = h;

    for (int i = 0; i < h;i++){
      for (int j = 0; j < w;j++){
        this->_image[i].push_back(temp);
      }
    }*/

    this->width_ = w;
    this->height_ = h;

    //it creates a matrix vector with the h and w dimensions and fill it with "fill" color
    this->_image = vector<vector<Color>>(height_, vector<Color>(width_, fill));
  }

  Image::~Image(){
    //destructor. Only use it if you use dynamically allocated memory explicitly.
  }

  //get image width and height
  int Image::width() const{
    return width_;
  }
  int Image::height() const{
    return height_;
  }

  //get mutable reference to the value of pixel (x,y)
  //width x, height y
  Color& Image::at(int x, int y){
    return _image[y][x];
  }

  //get read-only reference to the value of pixel (x,y)
  const Color& Image::at(int x, int y) const{
    return _image[y][x];
  }
}