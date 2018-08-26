#include "Worker.cpp"
#include <string>
#include <unistd.h>
#include <cstdlib>

using std::string;
using std::cout;
using std::endl;
using std::cerr;

int main(int argc, char **argv){
    Worker worker;
    //worker.read_bmp_image(filename);
    //worker.write_bmp_image();
    int c = 0;
    int u = 0;
    int n = 0;
    int B = 0;
    int b = 0;
    int index = 0;
    int c1;
    int opterr = 0;

    while((c1 = getopt(argc, argv,"c:u:n:B:b")) != -1){
        switch(c1){
            case 'c':
                if(atof(optarg) <= 0){
                    cout << "invalid image quantity" << endl;
                    c=-1;
                    break;
                }
                else c = atof(optarg);
                break;
            case 'u':
                if(atof(optarg) < 0 && atof(optarg) >= 255){
                    cout << "invalid range for threshold" << endl;
                    c1 = -1;
                    break;
                }
                else u = atof(optarg);
                break;
            case 'n':
                if(atof(optarg) < 0 && atof(optarg) > 100){
                    cout << "invalid %% for classify" << endl;
                    c1 = -1;
                    break;
                }
                else n = atof(optarg);
                break;
            //falta agregar validacion para cantidad de imagenes en buffer
            case 'b':
                b = 1;
                break;
            case '?':
                if(optopt == 'c' || optopt == 'u' || optopt == 'n')
                    cerr <<  stderr << optopt << " requieres an argument" << endl;
                else if(isprint(optopt))
                    cerr << "Unknow option " << optopt << endl;
                else
                    cerr << stderr << "Unknow option character " << optopt << endl;
                return 1;
            default:
                abort();
        } 
    }

    if(b == 1){
            cout << endl << " ************************************* " << endl;
            cout << "|   image          |   nearly black   |" << endl;
            cout << "|------------------|------------------|" << endl;
        }
        else 
            cout << "you chose not to see the results" << endl;
        
        worker.pipeline(c,u,n,b);
        cout <<"  *************************************" << endl;
    return 0;
}