#include "Image.hpp"

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

  /*
  void Image::rotateRight(){
    vector<vector<Color>> newImage(width_, vector<Color>(height_));
    for (int i = 0; i < height_;i++){
    vector<vector<Color>> newImage;
    for (int i = 0; i < width_;i++){
      vector<Color> atual;
      for (int j = 0; j < width_;j++){
        atual.push_back(_image[j][i]);
      }
      newImage.push_back(atual);
    }

    this->_image = newImage;
    v_mirror();
    

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
        for (int y = 0; y < height_ / 2; y++){
            for (int x = 0; x < width_; x++){
                Color temp = this->at(x,y);
                this->_image[y][x] = this->_image[h-1-y][x];
                this->_image[h-1-y][x] = temp;
                this->at(x,y) = this->at(x,height_-1-y);
                this->at(x,height_-1-y) = temp;
            }
        }
  }
  */
}