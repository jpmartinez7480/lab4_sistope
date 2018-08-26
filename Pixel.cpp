#include "Pixel.hpp"


Pixel::Pixel(){}

Pixel::Pixel(unsigned char b, unsigned char g, unsigned char r, unsigned char a){
    set_blue(b);
    set_green(g);
    set_red(r);
    set_alpha(a);
}

void Pixel::set_blue(unsigned char b){
    blue = b;
}

void Pixel::set_green(unsigned char g){
    green = g;
}

void Pixel::set_red(unsigned char r){
    red = r;
}

void Pixel::set_alpha(unsigned char a){
    alpha = a;
}

unsigned char Pixel::get_blue(){
    return blue;
}

unsigned char Pixel::get_green(){
    return green;
}

unsigned char Pixel::get_red(){
    return red;
}

unsigned  char Pixel::get_alpha(){
    return alpha;
}