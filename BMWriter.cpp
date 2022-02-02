// --------------------------------------------------------
//    File: BMWriter.cpp
//  Author: COP 3003 Programming II
// Purpose: class implementation for a writer that writes Byte
//  size data from a binary file
// --------------------------------------------------------

#include "BMWriter.h"


/**
 * Default constructor
 * @param writer - pointer to filestream
 */
BMWriter::BMWriter(std::ofstream* writer) {
    this->writer = writer;
}

/**
 * late-bind filestream pointer
 * @param writer - pointer to filestream
 */
void BMWriter::setWriter(std::ofstream* writer) {
    this->writer = writer;
}


// member methods
// ----------------------------------------------------

/**
 * writes a single byte to file
 * @param field - buffer with data to write
 * @return int  - number of bytes written
 */
int BMWriter::writeByte(BYTE &field) {
    return writeBytes(reinterpret_cast<char*>(&field), sizeof(BYTE));
}


/**
 * writes 2-bytes to file
 * @param field - buffer with data to write
 * @return int  - number of bytes written
 */
int BMWriter::writeWord(WORD &field) {
    return writeBytes(reinterpret_cast<char*>(&field), sizeof(WORD));
}


/**
 * writes 4-bytes to file
 * @param field - buffer with data to write
 * @return int  - number of bytes written
 */
int BMWriter::writeDWord(DWORD &field) {
    return writeBytes(reinterpret_cast<char*>(&field), sizeof(DWORD));
}


/**
 * determine if the writer has been set and the file open
 * @return bool - is the file open
 */
bool BMWriter::isOpen() {
    bool isOpen = false;
    if (writer)
        isOpen = writer->is_open();
    return isOpen;
}


/**
 * Save the file output by closing the file so it flushes the buffers
 */
void BMWriter::save() {
    if (writer && writer->is_open()) {
        // close the file to save the output
        writer->close();

        // make the writer null (needs to be re-opened to reuse this class
        writer = nullptr;
    }
}


// private methods
// ----------------------------------------------------

/**
 * write data to binary file in Byte size chunks
 * @param field - buffer to with data to write
 * @param size  - size of data in buffer
 * @return int  - number of bytes written
 */
int BMWriter::writeBytes(char* field, int size) {
    int bytes = 0;
    if (isOpen()) { // make sure we have an open writer first
        bytes = size;
        writer->write(field, bytes);
    }
    return bytes;
}
