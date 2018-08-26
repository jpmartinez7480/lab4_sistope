class __attribute__ ((__packed__)) Pixel
{
    public:
        Pixel();
        Pixel(unsigned char,unsigned char, unsigned char,unsigned char);
        //~Pixel();
        void set_blue(unsigned char);
        void set_green(unsigned char);
        void set_red(unsigned char);
        void set_alpha(unsigned char);
        unsigned char get_blue();
        unsigned char get_green();
        unsigned char get_red();
        unsigned char get_alpha();

    private:
        unsigned char blue;
        unsigned char green;
        unsigned char red;
        unsigned char alpha;
};