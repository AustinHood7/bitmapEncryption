// --------------------------------------------------------
//    file: PixelArray.h
//  Author: COP 3003 Programming II
// Purpose: implementation file for array of pixels
// --------------------------------------------------------
#include <cmath>            // floor function
#include "PixelArray.h"

// constructors
// ----------------------------------------------------

/**
 * default constructor
 * @param width - of bitmap in pixels
 * @param height - of bitmap in rows
 */
PixelArray::PixelArray(int width, int height, int depth) {
    this->width = width;
    this->height = height;
    this->depth = depth;
    this->pixels = nullptr;
}


/**
 * destructor - deletes the pixel array
 */
PixelArray::~PixelArray() {
    if (pixels) {
        for (int row = 0; row < height; row++ ) {
            delete pixels[row];
        }
        delete pixels;
    }
}


// accessors/mutators (getters/setters)
// ----------------------------------------------------

/**
 * @return int - column width of pixel array
 */
int PixelArray::getWidth() {
    return width;
}


/**
 * @return int - number of rows in pixel array
 */
int PixelArray::getHeight() {
    return height;
}


/**
 * @return int - bytes per pixel
 */
int PixelArray::getDepth() {
    return depth;
}


/**
 * set column width of pixel array
 */
void PixelArray::setWidth(int value) {
    width = value;
}


/**
 * set number of rows in pixel array
 */
void PixelArray::setHeight(int value) {
    height = value;
}


/**
 * set bytes per pixel
 */
void PixelArray::setDepth(int value) {
    depth = value;
}


/**
 * @return Pixel** - 2d pixel array
 */
Pixel** PixelArray::getPixels() {
    return pixels;
}


// member methods
// ----------------------------------------------------

/**
 * read pixel array data from file
 * @param reader - pointer to bitmap file reader
 * @return int   - number of bytes read
 */
int PixelArray::load(BMReader* reader) {
    int bytes = 0;

    int padding = calcPadding();

    // dimension the rows for the pixel array
    pixels = new Pixel * [height];
    if (width * height > 0) {

        for (int row = 0; row < height; row++ ) {
            // create room for the pixels in this row
            pixels[row] = new Pixel[width];

            for (int column = 0; column < width; column++) {
                BYTE red, green, blue;
                // pixel stored in reverse in file
                bytes += reader->readByte(blue);
                bytes += reader->readByte(green);
                bytes += reader->readByte(red);
                pixels[row][column] = Pixel(red, green, blue);
            } // column

            // read padding bytes
            for (int i = 0; i < padding; i++) {
                BYTE pad;
                bytes += reader->readByte(pad);
            } // padding

        } // row

    } // width * height > 0

    return bytes;
}


/**
 * write pixel array data to file
 * @param writer - pointer to bitmap file writer
 * @return int   - number of bytes written
 */
int PixelArray::store(BMWriter* writer) {
    int bytes = 0;

    int padding = calcPadding();

    // write pixel array
    for (int row = 0; row < height; row++) {
        for (int column = 0; column < width; column++) {
            Pixel pixel = pixels[row][column];
            BYTE color = pixel.getBlue();
            bytes += writer->writeByte(color);
            color = pixel.getGreen();
            bytes += writer->writeByte(color);
            color = pixel.getRed();
            bytes += writer->writeByte(color);
        } // column

        // write column padding to file
        for (int i = 0; i < padding; i++) {
            BYTE pad = 0;
            bytes += writer->writeByte(pad);
        }

    } // row

    return bytes;
}


/**
 * @return string - representation of pixel array
 */
std::string PixelArray::toString() {
    std::string pixelArray = "Pixel Array:\n";
    if (pixels) {
        pixelArray += "\t    Rows: " + std::to_string(height) + '\n';
        pixelArray += "\t Columns: " + std::to_string(width) + '\n';
        pixelArray += "\t Padding: " + std::to_string(calcPadding()) + '\n';
    } else {
        pixelArray += "\tNot loaded!\n";
    }

    return pixelArray;
}


// private methods
// ----------------------------------------------------

/**
 * private method that caluclates the number of padding
 * bytes needed per row based on formula:
 * RowSize = floor[(depth * width + 31)/ 32] * 4
 * Padding = RowSize - ((depth /8) * width)  // 8 for size of byte
 * @return int - padding bytes
 */
int PixelArray::calcPadding() {
    int rowSize = std::floor((depth * width + 31) / 32) * 4;
    int padding = rowSize - ((depth / 8) * width);
    return padding;
}