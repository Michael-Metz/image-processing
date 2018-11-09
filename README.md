
# Table of Contents

1. [What is This](#what)
2. [Otsu's Method Program](#otsu)
3. [PGM Files](#pgm)
4. [Known Bugs](#bugs)
5. [Test Images](#test-images)

<a name="otsu"></a>
# What is This

This repository is a place for me to experiment with image processing algorithms.  I am taking a course on image processing through coursera  [https://www.coursera.org/learn/image-processing](https://www.coursera.org/learn/image-processing).  They suggest using matlab, but since I am learning c++ in my college data structures course I thought it'd be fun to use c++.

<a name="otsu"></a>
# Otsu's Method Program
Otsu's method is an algorithm that automatically selects the optimal threshold level for a grayscale image.  This threshold level can then be used to threshold an image into a binary image.  For more information on how the algorithm works you can read `otsus-method-paper.pdf`.  The code for this algorithm is in Image8BitGrayscale.cpp and is the the method ImageGrayscale8Bit::otsuMethod.

I recently migrated this from makefile to cmake.  To my understanding cmake generates a makefile. Then you use makefile just as before
To use the program first you need to run a `cmake .` 

```
#run cmake first, which will generate a makefile
cmake .

#now we can use make to create the binary
make
```

then all you do is

```
./otsu infile outfile
```

for example you can use one of the test images.

```
./otsu test-images/keys-raw.pgm output.pgm
```
In the case below a. is keys-raw.pgm b. is output.pgm and the histgram represents keys-raw.pgm while the red line represents the threshold value of 163, which was selected using Otsu's method 
![Example image processed using otsus](https://i.imgur.com/dVr8oyA.jpg)

<a name="pgm"></a>
# PGM Files

A pgm file is a simple file type that can store an 8 bit grayscale image.  There is no compression making it straightforward to read and write, but at the cost of disk space.  To convert a file to this type you can use [https://www.online-utility.org/image/convert/to/PGM](https://www.online-utility.org/image/convert/to/PGM) or [ImageMagick](https://www.imagemagick.org/script/index.php).  You can view pgm files nativly on mac, and for windows you can view them using [irfanview](https://www.irfanview.com/). Currently the c++ code is written to read 8 bit grayscale binary pgm files.  It will not read ASCII pgm files. There are test images in the `test-images/` directory that work.

<a name="bugs"></a>
# Known Bugs

Either ImageIO::readBinaryPGMFile or ImageIO::writeBinaryPGMFile is not working as expected.  This issue is slight but noticable.  This issue shifts all the pixels to the right by 1 pixel.  The left most column is then replaced with white pixels.  I have no idea what is causing this.

<a name="test-images"></a>
# Test Images

Each test image was taken by myself, therefore no attribution is required.
