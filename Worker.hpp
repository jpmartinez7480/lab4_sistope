#include <string>
#include "Image.cpp"

using std::string;

class Worker
{
    public:
        Worker();
        ~Worker();
        void set_image(Image);
        Image get_image();
        bool read_bmp_image(string);
        bool write_bmp_image();
        void to_gray_scale();
        void to_binary_iamge();
        void analyze_image();
        void pipeline(int,int,int,int);
    private:
        Image bmp_image;
};