#followed this make file tutorial
#http://mrbook.org/blog/tutorials/make/

#variable for the compiler
CC = g++

CFLAGS = -std=c++11 -c

all: otsu

#otsu
otsu:  ImageGrayscale8Bit.o ImageIO.o OtsuDriver.o
	$(CC)  ImageGrayscale8Bit.o ImageIO.o OtsuDriver.o -o otsu

OtsuDriver.o:
	$(CC) $(CFLAGS) OtsuDriver.cpp

ImageIO.o:
	$(CC) $(CFLAGS) ImageIO.cpp

ImageGrayscale8Bit.o:
	$(CC) $(CFLAGS) ImageGrayscale8Bit.cpp

DebugUtilities.o:
	$(CC) $(CFLAGS) DebugUtilities.cpp
clean:
	rm *.o otsu

#clean and then compile