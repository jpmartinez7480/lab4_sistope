#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "Image.hpp"

using std::cout;
using std::endl;
using std::ios;
using std::ifstream;
using std::ofstream;
using std::string;

Image::Image(){}

Image::~Image(){}

void Image::set_bmp_filename(string name){
    filename = name;
}

void Image::set_bmp_header(BMPHEADER bmp_header){
    header = bmp_header;
}

void Image::init_pixels(){
    pixels = new Pixel*[get_bmp_header().height];
    for(int i = 0; i < get_bmp_header().width; i++)
        pixels[i] = new Pixel[get_bmp_header().width];
}

void Image::set_pixel(int i, int j, Pixel p){
    pixels[i][j] = Pixel(p.get_blue(), p.get_green(), p.get_red(), p.get_alpha());
}

BMPHEADER Image::get_bmp_header(){
    return header;
}

Pixel Image::get_pixel(int i, int j){
    return pixels[i][j];
}

string Image::get_bmp_filename(){
    return filename;
}
