// --------------------------------------------------------
//    File: BMReader.cpp
//  Author: COP 3003 Programming II
// Purpose: class implementation for a reader that reads Byte
//  size data from a binary file
// --------------------------------------------------------

#include "BMReader.h"


/**
 * Default constructor
 * @param reader - pointer to an input filestream (default null)
 */
BMReader::BMReader(std::ifstream* reader) {
    this->reader = reader;
}


/**
 * set/reset the internal file reader
 * @param reader - pointer to an input filestream
 */
void BMReader::setReader(std::ifstream* reader) {
    this->reader = reader;
}


// member methods
// ----------------------------------------------------
/**
 * Read a single Byte from file and fill the field parameter
 * @param field - buffer to fill
 * @return int  - size of data read in Bytes
 */
int BMReader::readByte(BYTE &field) {
    return readBytes(reinterpret_cast<char*>(&field), sizeof(BYTE));
}


/**
 * Read a 2-Bytes from file and fill the field parameter
 * @param field - buffer to fill
 * @return int  - size of data read in Bytes
 */
int BMReader::readWord(WORD &field) {
    return readBytes(reinterpret_cast<char*>(&field), sizeof(WORD));
}


/**
 * Read a 4-Bytes from file and fill the field parameter
 * @param field - buffer to fill
 * @return int  - size of data read in Bytes
 */
int BMReader::readDWord(DWORD &field) {
    return readBytes(reinterpret_cast<char*>(&field), sizeof(DWORD));
}


/**
 * determine if the reader has been set and the file open
 * @return bool - is the file open
 */
bool BMReader::isOpen() {
    bool isOpen = false;
    if (reader)
        isOpen = reader->is_open();
    return isOpen;
}


// private methods
// ----------------------------------------------------

/**
 * reads data from the file in byte-size chunks
 * @param field - largest size buffer DWORD
 * @param size  - size to read for this field
 * @return int  - number of bytes read
 */
int BMReader::readBytes(char* field, int size) {
    int bytes = 0;
    if (isOpen()) { // make sure we have an open reader first
        bytes = size;
        reader->read(field, bytes);
    }
    return bytes;
}
