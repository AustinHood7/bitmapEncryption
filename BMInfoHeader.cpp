// --------------------------------------------------------
//    File: BMInfoHeader.h
//  Author: COP 3003 Programming II
// Purpose: class implementation for a bitmap info header
// --------------------------------------------------------

#include "BMInfoHeader.h"


// constructors
// ----------------------------------------------------
BMInfoHeader::BMInfoHeader() {
    compression = 0;
    imageSize = 0;
    horizontal = 0;
    vertical = 0;
    colorPalette = 0;
    importantColors = 0;
};

// accessors/mutators (getters/setters)
// properties are readonly and can only be modified
// through the load method
// ----------------------------------------------------

/**
 * @return int - compression method as integer
 */
int BMInfoHeader::getCompression() {
    return compression;
}


/**
 * @return int - raw image size as integer
 */
int BMInfoHeader::getImageSize() {
    return imageSize;
}


/**
 * @return int - horizontal resolution (pixel per metre) as integer
 */
int BMInfoHeader::getHorizontal() {
    return horizontal;
}


/**
 * @return int - vertical resolution (pixel per metre) as integer
 */
int BMInfoHeader::getVertical() {
    return vertical;
}


/**
 * @return int - number of colors in palette as integer
 */
int BMInfoHeader::getColorPalette() {
    return colorPalette;
}


/**
 * @return int - number of important colors as integer
 */
int BMInfoHeader::getImportantColors() {
    return importantColors;
}

// member methods
// ----------------------------------------------------

/**
 * read core-header data from file
 * @param reader - pointer to bitmap file reader
 * @return int   - number of bytes read
 */
int BMInfoHeader::load(BMReader* reader) {
    int bytes = BMCoreHeader::load(reader);

    bytes += reader->readDWord(compression);
    bytes += reader->readDWord(imageSize);
    bytes += reader->readDWord(horizontal);
    bytes += reader->readDWord(vertical);
    bytes += reader->readDWord(colorPalette);
    bytes += reader->readDWord(importantColors);

    return bytes;
}


/**
 * write file-header data to file
 * @param writer - pointer to bitmap file writer
 * @return int   - number of bytes written
 */
int BMInfoHeader::store(BMWriter* writer) {
    int bytes = BMCoreHeader::store(writer);

    bytes += writer->writeDWord(compression);
    bytes += writer->writeDWord(imageSize);
    bytes += writer->writeDWord(horizontal);
    bytes += writer->writeDWord(vertical);
    bytes += writer->writeDWord(colorPalette);
    bytes += writer->writeDWord(importantColors);

    return bytes;
}

/**
 * @return string - representation of info-header and
 *                  base core-header with current data
 */
std::string BMInfoHeader::toString() {
    std::string header = BMCoreHeader::toString();
    header += "\nBitmap Info Header: \n";
    header += "\t    Compression Method: " + std::to_string(compression) + '\n';
    header += "\t            Image Size: " + std::to_string(imageSize) + '\n';
    header += "\t Horizontal Resolution: " + std::to_string(horizontal) + '\n';
    header += "\t   Vertical Resolution: " + std::to_string(vertical) + '\n';
    header += "\t         Color Palette: " + std::to_string(colorPalette) + '\n';
    header += "\t      Important Colors: " +  std::to_string(importantColors);
    return header;
}
