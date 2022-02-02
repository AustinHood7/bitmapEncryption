// --------------------------------------------------------
//    File: BMCoreHeader.cpp
//  Author: COP 3003 Programming II
// Purpose: class implementation for a bitmap core header
// --------------------------------------------------------

#include "BMCoreHeader.h"


// constructors
// ----------------------------------------------------

/**
 * default constructor
 */
BMCoreHeader::BMCoreHeader() {
    size = 0;
    width = 0;
    height = 0;
    planes = 0;
    depth = 0;
}

// accessors/mutators (getters/setters)
// properties are readonly and can only be modified
// through the load method
// ----------------------------------------------------
/**
 * @return int - header size as integer
 */
int BMCoreHeader::getSize() {
    return size;
}

/**
 * @return int - bitmap width in pixles as integer
 */
int BMCoreHeader::getWidth() {
    return width;
}

/**
 * @return int - bitmap height in pixels as integer
 */
int BMCoreHeader::getHeight() {
    return height;
}


/**
 * @return int - number of color planes as integer
 */
int BMCoreHeader::getPlanes() {
    return planes;
}


/**
 * @return int - bits-per-pixel as integer
 */
int BMCoreHeader::getDepth() {
    return depth;
}


// member methods
// ----------------------------------------------------

/**
 * read core-header data from file
 * @param reader - pointer to bitmap file reader
 * @return int   - number of bytes read
 */
int BMCoreHeader::load(BMReader* reader) {
    int bytes = 0;

    bytes += reader->readDWord(size);
    bytes += reader->readDWord(width);
    bytes += reader->readDWord(height);
    bytes += reader->readWord(planes);
    bytes += reader->readWord(depth);

    return bytes;
}


/**
 * write file-header data to file
 * @param writer - pointer to bitmap file writer
 * @return int   - number of bytes written
 */
int BMCoreHeader::store(BMWriter* writer) {
    int bytes = 0;

    bytes += writer->writeDWord(size);
    bytes += writer->writeDWord(width);
    bytes += writer->writeDWord(height);
    bytes += writer->writeWord(planes);
    bytes += writer->writeWord(depth);

    return bytes;
}


/**
 * @return string - representation of core-header with current data
 */
std::string BMCoreHeader::toString() {
    std::string header = "\nBitmap Core Header: \n";
    header += "\t        Size: " + std::to_string(size) + '\n';
    header += "\t       Width: " + std::to_string(width) + '\n';
    header += "\t      Height: " + std::to_string(height) + '\n';
    header += "\tColor Planes: " + std::to_string(planes) + '\n';
    header += "\t   Bit-Depth: " +  std::to_string(depth);
    return header;
}
