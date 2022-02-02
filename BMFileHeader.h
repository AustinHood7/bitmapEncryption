// --------------------------------------------------------
//    File: BMFileHeader.h
//  Author: COP 3003 Programming II
// Purpose: class definition for a bitmap file header
//  wikipedia.org
//  "This block of bytes is at the start of the file and is used to identify the file.
//  A typical application reads this block first to ensure that the file is actually a
//  BMP file and that it is not damaged. The first 2 bytes of the BMP file format are
//  the character "B" then the character "M" in ASCII encoding. All of the integer values
//  are stored in little-endian format (i.e. least-significant byte first)."
// --------------------------------------------------------

#ifndef BMFILEHEADER_H
#define BMFILEHEADER_H

#include <string>       // for file type property
#include "BMReader.h"   // bitmap file reader
#include "BMWriter.h"   // bitmap file writer

class BMFileHeader {
public:
    // constructors
    // ----------------------------------------------------
    BMFileHeader();

    // accessors/mutators (getters/setters)
    // properties are readonly and can only be modified
    // through the load method
    // ----------------------------------------------------
    std::string getType();
    int getSize();
    int getReserved1();
    int getReserved2();
    int getOffset();


    // member methods
    // ----------------------------------------------------
    int load(BMReader* reader);
    int store(BMWriter* writer);

    std::string toString();


private:
    BYTE  type[3];      // file type (2 byte "BM" plus null "\0")
    DWORD size;     // size of file in bytes (from header)
    WORD  reserved1;    // not used
    WORD  reserved2;    // not used
    DWORD offset;       // number of bytes into the file where pixel-array data starts
};


#endif //BMFILEHEADER_H
