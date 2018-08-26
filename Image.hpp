#include <string>
#include <fstream>
#include "Bmp.hpp"
#include "Pixel.cpp"

using std::string;

class Image{
    public:
        Image();
        ~Image();
        void set_bmp_filename(string);
        void set_bmp_header(BMPHEADER);
        void set_pixel(int, int, Pixel);
        void init_pixels();
        BMPHEADER get_bmp_header();
        Pixel get_pixel(int, int);
        string get_bmp_filename();
    private:
        BMPHEADER header;
        Pixel **pixels;
        string filename;
};