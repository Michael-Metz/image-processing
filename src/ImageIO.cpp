
#include "ImageIO.h"
#include <iostream>
#include <fstream>

/**
 * Reads a binary pgm file into an 8 bit image
 *Magic number is p5 which indicates binary 8 bit grayscale image @see https://en.wikipedia.org/wiki/Netpbm_format
 *
 * @return image that was read
 */
ImageGrayscale8Bit ImageIO::readBinaryPGMFile(std::string filePath) {
    std::ifstream file(filePath.c_str(), std::ios::binary);
    if(! file.is_open())
    {
        std::cout << filePath << " could not be open." <<  std::endl;
        exit(0);
    }

    std::string magicNum;
    long width = 0;
    long height = 0;
    long maxPixelIntensity = 0;

    file >> magicNum;
    file >> width;
    file >> height;
    file >> maxPixelIntensity;

    if(magicNum != "P5")
    {
        std::cout << "Invalid ppm file";
        std::cout << "magic: " << magicNum <<  std::endl;
        std::cout << "width: " << width <<  std::endl;
        std::cout << "height: " << height <<  std::endl;
        std::cout << "max: " << maxPixelIntensity << std::endl;
        exit(0);
    }

    ImageGrayscale8Bit image(width,height);
    int size = width * height;

    char* buff = new  char[size];
    file.read(buff, size);

    for(int i = 0; i < size; i++) {
        char c = buff[i];
        unsigned char intensity = (c>127) ? (unsigned char)(-(256 + c)) : (unsigned char)c;
        image.setIntensity(i, intensity);
    }
    file.close();

    delete [] buff;
    return image;
}

//void ImageIO::writePGMFile(std::string filePath, const ImageGrayscale8Bit& img){
//    std::ofstream file(filePath,std::ios::binary);
//    file << "P5" << std::endl;
//    file << img.getWidth() << " " << img.getHeight()<< std::endl;
//    file << "255" << std::endl;
//
//    int size = img.size();
//    for(int i = 0; i < size; i++)
//        file << img.getIntensity(i);
//    file.close();
//}


/**
 * Writes an 8 bit grayscale image to a binary 8bit pgm file.
 * Magic number is p5 which indicates binary 8 bit grayscale image @see https://en.wikipedia.org/wiki/Netpbm_format
 *
 * @param filePath - that your want to save file to. Include the extension
 * @param img - the image file
 */
void ImageIO::writeBinaryPGMFile(std::string filePath, const ImageGrayscale8Bit& img){
    std::ofstream file(filePath,std::ios::binary);
    file << "P5" << std::endl;
    file << img.getWidth() << " " << img.getHeight()<< std::endl;
    file << "255" << std::endl;

    int size = img.size();
    char* buff = new char[size];
    std::cout << std::endl;
    for(int i = 0; i < size; i++)
    {
        unsigned char uc = img.getIntensity(i);
        char c = (char)uc;
        buff[i] = c;
    }

    file.write(buff, size);
    file.close();

    delete[] buff;
}
