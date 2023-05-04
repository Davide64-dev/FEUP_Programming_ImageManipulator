#include "Image.hpp"
#include <iostream>
#include <algorithm>

namespace prog
{
  /**
   * @brief Constructor of a new Image with all pixels at the same color
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
   * @brief Destructor. Only use it if we use dynamically allocated memory explicty. It is not the case
   * 
   */
  Image::~Image(){
  }

 /**
  * @brief Getter of the width of the image
  * 
  * @return int width of the image
  */
  int Image::width() const{
    return this->width_;
  }

  /**
   * @brief Getter of the height of the image
   * 
   * @return int height of the image
   */
  int Image::height() const{
    return this->height_;
  }

  /**
   * @brief Getter of mutable reference to the value of pixel (x,y)
   * 
   * @param x x coordinate
   * @param y y coordinate
   * @return Color& Reference of the pixel that is accessed
   */
  Color& Image::at(int x, int y){
    return this->_image[y][x];
  }

  /**
   * @brief Getter read-only reference to the value of pixel
   * 
   * @param x x coordinate
   * @param y y coordinate
   * @return const Color& read-only reference of the pixel
   */
  const Color& Image::at(int x, int y) const{
    return this->_image[y][x];
  }

  void Image::median_filter(int ws){
    Color color = Color(255, 255, 255);
    vector<vector<Color>> image = vector<vector<Color>>(height_, vector<Color>(width_, color));
    
    for (int x = 0; x < width_;x++){
      for (int y = 0; y< height_;y++){
        vector<int> reds;
        vector<int> greens;
        vector<int> blues;
        for (int nx = max(0, x - ws / 2); nx <= min(width() - 1, x + ws / 2);nx++){
          for (int ny = max(0, y - ws / 2); ny <= min(height() - 1, y + ws /2); ny++){
            reds.push_back(_image[ny][nx].red());
            greens.push_back(_image[ny][nx].green());
            blues.push_back(_image[ny][nx].blue());
          }
        }
        int red = Image::median(reds);
        int green = Image::median(greens);
        int blue = Image::median(blues);
        image[y][x].red() = red;
        image[y][x].blue() = blue;
        image[y][x].green() = green;
      }
    }
    this->_image = image;
  }

  int Image::median(vector<int> vetor){
    int size = vetor.size();
    std::cout << size;
    sort(vetor.begin(), vetor.end());
    if (size % 2 == 1)
      return vetor[size / 2];
    return (vetor[size/2 -1] + vetor[size/2]) / 2;
  }



    
    map<Color, string> Image::colorsToASCII() const{
      map<Color, string> ret;
      char begin = 35;
      for (int i = 0; i < width_; i++){
        for (int j = 0; j < height_; j++){
          if (!ret.count(_image[j][i])){
            Color color = _image[j][i];
            ret[color] = begin;
            begin++;
          }
        }
      }
      return ret;
    }
    
}

