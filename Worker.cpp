#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "Worker.hpp"

using std::cout;
using std::endl;
using std::ios;
using std::ifstream;
using std::ofstream;
using std::string;
using std::stringstream;

Worker::Worker(){
}

Worker::~Worker(){}

void Worker::set_image(Image i){
    bmp_image = i;
}

Image Worker::get_image(){
    return bmp_image;
}

bool Worker::read_bmp_image(string filename){
    Image image;
    image.set_bmp_filename(filename);
    const char *filename_char = filename.c_str();
    ifstream file_bmp_image(filename_char,ios::binary);
    if(!file_bmp_image){
        cout << "Error openning the file " << filename << endl;
        return false;
    }
    else{
        BMPHEADER header;
        file_bmp_image.read((char*)&header,sizeof(BMPHEADER));
        image.set_bmp_header(header);
        image.init_pixels();
        file_bmp_image.seekg(image.get_bmp_header().offset,ios::beg);
        for(int i = 0; i < image.get_bmp_header().height; i++){
            for(int j = 0; j < image.get_bmp_header().width; j++){
                unsigned char color_blue;
                unsigned char color_green;
                unsigned char color_red;
                unsigned char color_alpha;
                file_bmp_image >> std::hex >> color_blue;
                file_bmp_image >> std::hex >> color_green;
                file_bmp_image >> std::hex >> color_red;
                file_bmp_image >> std::hex >> color_alpha;
                Pixel p = Pixel(color_blue, color_green, color_red, color_alpha);
                image.set_pixel(i,j,p);
            }
        }
        set_image(image);
        file_bmp_image.close();
        return true;
    }
}

bool Worker::write_bmp_image(){
    string file2 = "res_" + get_image().get_bmp_filename();
    const char *file = file2.c_str();
    ofstream bmp_image_binarized(file,ios::binary);
    BMPHEADER header = get_image().get_bmp_header();
    if(bmp_image_binarized){
        bmp_image_binarized.write((char*)&header,sizeof(BMPHEADER));
        bmp_image_binarized.seekp(get_image().get_bmp_header().offset,ios::beg);
        for(int i = 0; i < get_image().get_bmp_header().height; i++){
            for(int j = 0; j < get_image().get_bmp_header().width; j++){
                bmp_image_binarized << (unsigned char)get_image().get_pixel(i,j).get_blue();
                bmp_image_binarized << (unsigned char)get_image().get_pixel(i,j).get_green();
                bmp_image_binarized << (unsigned char)get_image().get_pixel(i,j).get_red();
                bmp_image_binarized << (unsigned char)get_image().get_pixel(i,j).get_alpha();
            }
        }
        bmp_image_binarized.close();
        return true;
    }
    else return false;
}

//recuerda que no he hecho nada del buffer, hice esta parte para probar el flujo
void Worker::pipeline(int amount_images, int threshold, int cat, int flag){
    int cnt = 1;
    Worker worker;
    while(cnt <= amount_images){
        //recuerda lo del buffer y monitores
        stringstream aux;
        aux << cnt;
        string filename_aux = "imagen_" + aux.str() + ".bmp";
        worker.read_bmp_image(filename_aux);
        worker.write_bmp_image();
        cnt++;
    }
}



