// --------------------------------------------------------
//    File: BMFileHeader.cpp
//  Author: COP 3003 Programming II
// Purpose: class implementation for a bitmap file header
// --------------------------------------------------------

#include "BMFileHeader.h"

// constructors
// ----------------------------------------------------
/**
 * default constructor
 */
BMFileHeader::BMFileHeader() {
    type[0] = '\0';
    size = 0;
    reserved1 = 0;
    reserved2 = 0;
    offset = 0;
}


// accessors/mutators (getters/setters)
// properties are readonly and can only be modified
// through the load method
// ----------------------------------------------------

/**
 * @return string - file type as a 2-byte string with null-terminator
 */
std::string BMFileHeader::getType() {
    return reinterpret_cast<char const*>(type);
}


/**
 * @return int - file size as an integer
 */
int BMFileHeader::getSize() {
    return size;
}


/**
 * @return int - reserved1 as an integer
 */
int BMFileHeader::getReserved1() {
    return reserved1;
}


/**
 * @return int - reserved2 as an integer
 */
int BMFileHeader::getReserved2() {
    return reserved2;
}


/**
 * @return int - reserved3
 */
int BMFileHeader::getOffset() {
    return offset;
}


// member methods
// ----------------------------------------------------

/**
 * read file-header data from file
 * @param reader - pointer to bitmap file reader
 * @return int   - number of bytes read
 */
int BMFileHeader::load(BMReader* reader) {
    int bytes = 0;

    bytes += reader->readByte(type[0]);
    bytes += reader->readByte(type[1]);
    type[2] = '\0'; // add null terminator
    bytes += reader->readDWord(size);
    bytes += reader->readWord(reserved1);
    bytes += reader->readWord(reserved2);
    bytes += reader->readDWord(offset);

    return bytes;
}


/**
 * write file-header data to file
 * @param writer - pointer to bitmap file writer
 * @return int   - number of bytes written
 */
int BMFileHeader::store(BMWriter* writer) {
    int bytes = 0;

    bytes += writer->writeByte(type[0]);
    bytes += writer->writeByte(type[1]);
    bytes += writer->writeDWord(size);
    bytes += writer->writeWord(reserved1);
    bytes += writer->writeWord(reserved2);
    bytes += writer->writeDWord(offset);

    return bytes;
}


/**
 * @return string - representation of file-header with current data
 */
std::string BMFileHeader::toString() {
    std::string header = "\nFile Header: \n";
    header += "\tType: " + getType() + '\n';
    header += "\tSize: " + std::to_string(size) + '\n';
    header += "\tOffset: " +  std::to_string(offset);
    return header;
}
