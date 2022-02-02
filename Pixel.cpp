//    file: Pixel.h
//  Author: COP 3003 Programming II
// Purpose: class implementation file for a pixel
// --------------------------------------------------------

#include "Pixel.h"

Pixel::Pixel(BYTE red, BYTE green, BYTE blue)
{
    this->red = red;
    this->green = green;
    this->blue = blue;
}

BYTE Pixel::getRed() { return red; }
BYTE Pixel::getGreen() { return green; }
BYTE Pixel::getBlue() { return blue; }

void Pixel::setRed(BYTE value) { red = value; }
void Pixel::setGreen(BYTE value) { green = value; }
void Pixel::setBlue(BYTE value) {blue = value; }
