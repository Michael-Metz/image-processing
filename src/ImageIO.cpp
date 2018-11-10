
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
        std::cout << "Invalid pgm file";
        std::cout << "magic: " << magicNum <<  std::endl;
        std::cout << "width: " << width <<  std::endl;
        std::cout << "height: " << height <<  std::endl;
        std::cout << "max: " << maxPixelIntensity << std::endl;
        exit(0);
    }
    ImageGrayscale8Bit image(width,height);
    int size = width * height;

    char c;
    getline(file,magicNum); //consume new line character

    bool error;

    for(int i = 0; i < size; i++){

        //read byte by byte and set pixel
        file.read(&c,1);
        unsigned char intensityValue = (unsigned char) c;
        image.setIntensity(i,intensityValue);
        error = file.eof();
        if(error){
            std::cout << "reached end of file while reading binary PGM" << std::endl;
            exit(1);
        }
    }

    file.close();

    return image;
}

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

/**
 * Reads an ASCII PGM file. magic number of P2
 * See https://en.wikipedia.org/wiki/Netpbm_format
 *
 * @param filePath
 * @return
 */
void ImageIO::writeASCIIPGMFile(std::string filePath, const ImageGrayscale8Bit &img) {
    std::ofstream file(filePath);
    file << "P2" << std::endl;
    file << img.getWidth() << " " << img.getHeight()<< std::endl;
    file << "255" << std::endl;

    int printNewLineCounter = 1;
    for(int i = 0; i < img.size(); i++)
    {
        unsigned int c = img.getIntensity(i);
        file << c;
        if(printNewLineCounter == img.getWidth()) {
            file << std::endl;
            printNewLineCounter = 1;
        }
        else {
            file << " ";
            printNewLineCounter++;
        }
    }
    file.close();
}

/**
 * Reads an ASCII PGM file. magic number of P2
 * See https://en.wikipedia.org/wiki/Netpbm_format
 *
 * @param filePath
 * @return
 */
ImageGrayscale8Bit ImageIO::readASCIIPGMFile(std::string filePath) {
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

    if(magicNum != "P2")
    {
        std::cout << "Invalid pgm file";
        std::cout << "magic: " << magicNum <<  std::endl;
        std::cout << "width: " << width <<  std::endl;
        std::cout << "height: " << height <<  std::endl;
        std::cout << "max: " << maxPixelIntensity << std::endl;
        exit(0);
    }

    ImageGrayscale8Bit image(width,height);
    int size = width * height;

    for(int i = 0; i < size; i++)
    {
        unsigned int c;
        file >> c;
        unsigned char intensity = c;
        image.setIntensity(i,intensity);
    }
    file.close();
    return image;
}