// --------------------------------------------------------
//    File: BMFile.cpp
//  Author: COP 3003 Programming II
// Purpose: class implementation for a bitmap file object that
//  represents the whole file with headers and pixels
// --------------------------------------------------------

#include "BMFile.h"


// constructors
// ----------------------------------------------------

/**
 * default constructor
 * @param reader - file input stream
 * @param writer - file output stream
 */
BMFile::BMFile(std::ifstream* reader, std::ofstream* writer) {
    this->reader = BMReader(reader);
    this->writer = BMWriter(writer);

    // create empty properties (call default constructors)
    BMFileHeader fileHeader = BMFileHeader();
    BMInfoHeader infoHeader = BMInfoHeader();
    PixelArray pixels = PixelArray();
}

/**
 * destructor
 */
BMFile::~BMFile() {

}


// accessors/mutators (getters/setters)
// ----------------------------------------------------

/**
 * set/reset the file reader object
 * @param reader - file input stream
 */
void BMFile::setReader(std::ifstream* reader) {
    this->reader.setReader(reader);
}


/**
 * set/reset the file writer object
 * @param writer - file output stream
 */
void BMFile::setWriter(std::ofstream* writer) {
    this->writer.setWriter(writer);
}


// read only accessors for headers

/**
 * @return BMFileHeader* - pointer to File Header
 */
BMFileHeader* BMFile::getFileHeader() {
    return &fileHeader;
}


/**
 * @return BMInfoHeader* - pointer to Core/Info Header
 */
BMInfoHeader* BMFile::getInfoHeader() {
    return &infoHeader;
}


// member methods
// ----------------------------------------------------
/**
 * read bitmap data from file
 * @return int   - number of bytes read
 */
int BMFile::load() {
    int bytes = fileHeader.load(&reader);
    bytes += infoHeader.load(&reader);

    // setup pixel array and load it
    pixels.setWidth(infoHeader.getWidth());
    pixels.setHeight(infoHeader.getHeight());
    pixels.setDepth(infoHeader.getDepth());
    bytes += pixels.load(&reader);

    return bytes;
}


/**
 * write bitmap data to file
 * @return int   - number of bytes written
 */

int BMFile::store() {
    int bytes = fileHeader.store(&writer);
    bytes += infoHeader.store(&writer);
    bytes += pixels.store(&writer);
    writer.save();
    return bytes;
}


/**
 * @return string - representation of the bitmap with current data
 */
std::string BMFile::toString() {
    std::string bitmap = "Bitmap: \n\n";
    bitmap += fileHeader.toString();
    bitmap += infoHeader.toString();
    bitmap += pixels.toString();
    return bitmap;
}


