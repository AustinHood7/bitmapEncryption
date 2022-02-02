// --------------------------------------------------------
//    file: Pixel.h
//  Author: COP 3003 Programming II
// Purpose: class definition file for a pixel
// --------------------------------------------------------

#ifndef PIXEL_H
#define PIXEL_H

#include "bitmap_defs.h"

class Pixel {
public:
    Pixel(BYTE red = 0, BYTE green = 0, BYTE blue = 0);

    BYTE getRed();
    BYTE getGreen();
    BYTE getBlue();

    void setRed(BYTE value);
    void setGreen(BYTE value);
    void setBlue(BYTE value);

private:
    BYTE red;
    BYTE green;
    BYTE blue;
};


#endif //PIXEL_H
