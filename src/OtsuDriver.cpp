
#include <iostream>
#include "ImageGrayscale8Bit.h"
#include "ImageIO.h"

using namespace std;

void printUsage(){
    cout << endl << endl << "This program uses otsu's method to threshold an image to an binary image" << endl;
    cout << "For more information on how the algorthim works visit https://github.com/Michael-Metz/image-processing";
    cout << endl << endl;
    cout << "The infile must be a binary pgm file. Aswell as the outfile" << endl << endl;
    cout << "Usage: ./otsu infile outfile" << endl;
    cout << endl;
    cout << "Example: ./otsu keys.pgm mask.pgm" << endl << endl;
}
int main(int arc, char *argv[]){
    //make sure two arguments are  passed when running the program from command line
    //remember first argument is the name of the program
    if (arc != 3) {
        printUsage();
        return 0;
    }
    //at this point
    //argv[1] is the path to the input file
    //argv[2] is the path to save the output file
    string infile = argv[1];
    string outfile = argv[2];

    ImageGrayscale8Bit image = ImageIO::readBinaryPGMFile(infile);
    unsigned char intensity = image.otsuMethod();
    unsigned int i = (int) intensity;
    cout << "otsu's method found the intensity of " << i  << " to be the best threshold level"<< endl;
    image.thresholdOperation(intensity);
    ImageIO::writeBinaryPGMFile(outfile,image);
};