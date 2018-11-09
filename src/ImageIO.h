//
// Created by michael on 4/3/18.
//

#ifndef IMAGE_IMAGEIO_H
#define IMAGE_IMAGEIO_H

#include "ImageGrayscale8Bit.h"
#include <string>


class ImageIO{
public:
    static ImageGrayscale8Bit readBinaryPGMFile(std::string filePath);
    static void writeBinaryPGMFile(std::string filePath, const ImageGrayscale8Bit &img);
};



#endif //IMAGE_IMAGEIO_H