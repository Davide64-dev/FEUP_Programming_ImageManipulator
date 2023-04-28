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


  void Image::rotateRight(){
    vector<vector<Color>> newImage(height_, vector<Color>(width_));
    for (int i = 0; i < width_;i++){
      vector<Color> atual;
      for (int j = 0; j < height_;j++){
        newImage[j][height_-1-i] = _image[i][j];
      }
    }

    this->_image = newImage;

  }

  void Image::h_mirror(){
    int h = this->height();
        int w = this->width();
        for (int y = 0; y < h; y++){
            for (int x = 0; x < w / 2; x++){
                Color temp = this->at(x,y);
                this->at(x,y) = this->at(w-1-x,y);
                this->at(w-1-x,y) = temp;
            }
        }
  }

  void Image::v_mirror(){
        int h = this->height();
        int w = this->width();
        for (int y = 0; y < h / 2; y++){
            for (int x = 0; x < w; x++){
                Color temp = this->at(x,y);
                this->at(x,y) = this->at(x,h-1-y);
                this->at(x,h-1-y) = temp;
            }
        }
  }
}