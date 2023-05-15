#include "Image.hpp"
#include <iostream>
#include <algorithm>

namespace prog
{
  /**
   * @brief Constructor of a new Image with all pixels set to the same color
   * 
   * @param w Width of the image
   * @param h Height of the image
   * @param fill Color that will fill the image
   */
  Image::Image(int w, int h, const Color &fill){
    this->width_ = w;
    this->height_ = h;
    this->_image = vector<vector<Color>>(h, vector<Color>(w, fill));
  }

  /**
   * @brief Destructor. Only use it if we use dynamically allocated memory explicty (we don't)
   * 
   */
  Image::~Image(){
  }

 /**
  * @brief Getter of the width of the image
  * 
  * @return int Width of the image
  */
  int Image::width() const{
    return this->width_;
  }

  /**
   * @brief Getter of the height of the image
   * 
   * @return int Height of the image
   */
  int Image::height() const{
    return this->height_;
  }

  /**
   * @brief Getter of mutable reference to the value of pixel (x,y)
   * 
   * @param x x coordinate
   * @param y y coordinate
   * @return Color& Reference to the pixel that is accessed
   */
  Color& Image::at(int x, int y){
    return this->_image[y][x];
  }

  /**
   * @brief Getter of read-only reference to the value of pixel
   * 
   * @param x x coordinate
   * @param y y coordinate
   * @return const Color& read-only reference to a pixel
   */
  const Color& Image::at(int x, int y) const{
    return this->_image[y][x];
  }

  /**
   * @brief Inverter of every color in the image
   * 
   */
  void Image::invert() {
    for (int y = 0; y < height_; y++){
      for (int x = 0; x < width_; x++){
        at(x,y).invert();
      }
    }
  }

  /**
   * @brief Method that fills part of an image with a given Color
   * 
   * @param x Upper left corner x component of the fill
   * @param y Upper left corner y component of the fill
   * @param w Width of the fill
   * @param h Height of the fill
   * @param _fill Color to be used to fill in
   */
  void Image::fill(int x, int y, int w, int h, const Color& _fill) {
    for (int i = y; i < y + h; i++){
      for (int j = x; j < x + w; j++){
        at(j,i) = _fill;
      }
    }
  }

  /**
   * @brief Converts image to gray scale
   * 
   */
  void Image::to_gray_scale() {
    for (int y = 0; y < height_; y++){
      for (int x = 0; x < width_; x++){
        at(x,y).to_gray_scale();
      }
    }
  }

  /**
   * @brief Replace all pixels in the image of a given color with a new color.
   * 
   * @param _original The original color that will be replaced
   * @param _replace The new color
   */
  void Image::replace(Color _original, Color _replace) {
    for (int y = 0; y < height_; y++){
      for (int x = 0; x < width_; x++){
        if (at(x,y) == _original){
          at(x,y) = _replace;
        }
      }
    }
  }

  /**
   * @brief Horizontally mirrors the image
   * 
   */
  void Image::h_mirror() {
    for (int y = 0; y < height_; y++){
      for (int x = 0; x < width_ / 2; x++){
        Color temp = at(x,y);
        at(x,y) = at(width_-1-x,y);
        at(width_-1-x,y) = temp;
      }
    }
  }

  /**
   * @brief Vertically mirrors the image
   * 
   */
  void Image::v_mirror() {
    for (int y = 0; y < height_ / 2; y++){
      for (int x = 0; x < width_; x++){
        Color temp = at(x,y);
        at(x,y) = at(x,height_-1-y);
        at(x,height_-1-y) = temp;
      }
    }
  }

  /**
   * @brief Crop the image, reducing it to all pixels 
   * contained in the rectangle defined by top-left corner (x, y), 
   * width w, and height h
   * 
   * @param x x component of the upper left corner of the rectangle
   * @param y y component of the upper left corner of the rectangle
   * @param w Width of the rectangle
   * @param h Height of the rectangle
   */
  void Image::crop(int x, int y, int w, int h) {
    Image _crop(w,h);
    for (int i = y; i < y + h; i++){
      for (int j = x; j < x + w; j++){
        _crop.at(j-x,i-y) = at(j,i);
      }
    }
    //replace the original image with the new image object
    _image = _crop._image;

    //set the dimensions of the new image;
    width_ = w;
    height_ = h;
  }

  /**
   * @brief Rotate the image 90 degrees to the left
   * 
   */
  void Image::rotate_left() {
    Image _rotated(height_,width_);
    for (int y = 0; y < height_; y++){
      for (int x = 0; x < width_; x++){
        _rotated.at(y,width_-1-x) = at(x,y);
      }
    }
    //replace the original image with the new image object
    _image = _rotated._image;

    //swap the width and height;
    swap(width_,height_);
  }

  /**
   * @brief Rotate the image 90 degrees to the right
   * 
   */
  void Image::rotate_right() {
    Image _rotated(height_,width_);
    for (int y = 0; y < height_; y++){
      for (int x = 0; x < width_; x++){
        _rotated.at(height_-1-y,x) = at(x,y);
      }
    }
    //replace the original image with the new image object
    _image = _rotated._image;

    //swap the width and height;
    swap(width_,height_);
  }

  /**
   * @brief "Pastes" an image on top of the current image, at a given point,
   * leaving pixels of a given color unchanged
   * 
   * @param image_add Image to be added
   * @param neutral_color Color to be ignored
   * @param x x component of the top-left corner of the space where the image should be added
   * @param y y component of the top-left corner of the space where the image should be added
   */
  void Image::add(Image *image_add, Color neutral_color, int x, int y) {
      int i_ = 0;
      for (int i = y; i < y + image_add->height(); i++){
          int j_ = 0;
          for (int j = x; j < x + image_add->width(); j++){
            Color& pixel_add = image_add->at(j_,i_);
            if (!(neutral_color == pixel_add)){
              at(j,i) = image_add->at(j_,i_);
            }
            j_++;
          }
          i_++;
      }
      delete image_add;
  }

  /**
   * @brief Median filter used to remove noise from an image
   * 
   * @param ws Window size of the median calculator
   */
  void Image::median_filter(int ws) {
    Color color = Color(255, 255, 255);
    vector<vector<Color>> image = vector<vector<Color>>(height_, vector<Color>(width_, color));
    
    for (int x = 0; x < width_;x++){
      for (int y = 0; y< height_;y++){

        vector<int> reds, greens, blues;

        for (int nx = max(0, x - ws / 2); nx <= min(width() - 1, x + ws / 2);nx++){
          for (int ny = max(0, y - ws / 2); ny <= min(height() - 1, y + ws /2); ny++){
            reds.push_back(at(nx,ny).red());
            greens.push_back(at(nx,ny).green());
            blues.push_back(at(nx,ny).blue());

          }
        }

        int red = Image::median(reds);
        int green = Image::median(greens);
        int blue = Image::median(blues);
        
        //operator = was implemented in class Color
        image[y][x] = Color(red, green, blue);
      }
    }
    _image = image;
  }

  /**
   * @brief Static method tthat calculates the median of a vector
   *  of integers. The vector doesn't need to be ordered
   * 
   * @param vetor Vector
   * @return int Median
   */
  int Image::median(vector<int> vetor) {
    sort(vetor.begin(), vetor.end());
    int size = vetor.size();
    if (size % 2 == 1)
      return vetor[size / 2];
    return (vetor[size/2 -1] + vetor[size/2]) / 2;
  }

  /**
   * @brief Creates a map that assigns an ascii character
   *  to every different color in the image
   * 
   * @return map<Color, string>
   */
  map<Color, string> Image::colorsToASCII() const {
    map<Color, string> ret;
    char begin = 35;
    for (int i = 0; i < width_; i++){
      for (int j = 0; j < height_; j++){
        if (!ret.count(at(i,j))){
          Color color = at(i,j);
          ret[color] = begin;
          begin++;
        }
      }
    }
    return ret;
  }
}
