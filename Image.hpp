#ifndef __prog_Image_hpp__
#define __prog_Image_hpp__
#include "Color.hpp"
#include <vector>
#include <unordered_map>
using namespace std;

namespace prog
{
  class Image
  {
  private:
    int width_;
    int height_;
    vector<vector<Color>> _image;
    
  public:
    Image(int w, int h, const Color &fill = {255, 255, 255});
    ~Image();
    int width() const;
    int height() const;
    Color &at(int x, int y);
    const Color &at(int x, int y) const;
    void median_filter(int ws);
    static int median(vector<int> vetor);
    unordered_map<Color, string> colorsToASCII() const;
    //void rotateRight();
    //void h_mirror();
    //void v_mirror();
  };
}
#endif