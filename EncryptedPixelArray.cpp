// --------------------------------------------------------
//    file: EncryptedPixelArray.cpp
//  Author: COP 3003 Programming II
// Purpose: implementation file for steganography encryptor
// --------------------------------------------------------
#include "EncryptedPixelArray.h"

EncryptedPixelArray::EncryptedPixelArray(int width, int height)
    : BMFile{ width, height } {}

int EncryptedPixelArray::encrypt(std::string message) {
    int bytes;

    int row = 0, column = 0;
    for (int next = 0; next < message.length(); next++) {
        char nextChar = message[next];

        for (int bit = 0; bit < 8; bit++) {

            Pixel* nextPixel = &pixels[row][column];

            uint8_t blue = nextPixel->getBlue();

            if (nextChar & 1) {
                blue |= 1;
            }
            else {
                blue &= 0xFE;
            }

            nextPixel->setBlue(blue);

            nextChar >>= 1;
        }

        column++;
        if (column == width) {
            row++;
            column = 0;
        }
        bytes++;
    }

    for (int term = 0; term < 8; term++) {
        Pixel* nextPixel = &pixels[row][column];
        uint8_t blue = nextPixel->getBlue();
        blue &= 0xFE;
        nextPixel->setBlue(blue);
        column++;
        if (column == width) {
            row++;
            column = 0;
        }
        bytes++;
    }

    return bytes;
}

std::string EncryptedPixelArray::decrypt(BMFile) {
    int row = 0, column = 0;
    char nextChar;
    std::string secretMessage = "";

    // until we hit the null terminator
    do {

        for (int i = 0; i < 8; i++) {

            Pixel pixel = pixels[row][column];

            //or the result of {Blue & 1 (isolate bit-0) shifted i times to the left}
            nextChar |= (pixel.getBlue() & 1) << i;

            // get next pixel
            column++;
            if (column == width) {
                column = 0;
                row++;
            }

        }

        secretMessage += nextChar;
    } while (nextChar);

    return secretMessage;
}

