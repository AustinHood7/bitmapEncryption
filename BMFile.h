// --------------------------------------------------------
//    File: BMFile.h
//  Author: COP 3003 Programming II
// Purpose: class definition for a bitmap file object that
//  represents the whole file with headers and pixels
// --------------------------------------------------------

#ifndef BMFILE_H
#define BMFILE_H

#include "BMReader.h"       // file reader
#include "BMWriter.h"       // file writer
#include "BMFileHeader.h"   // Bitmap File Header
#include "BMInfoHeader.h"   // Bitmap Info Header (DIB)
#include "PixelArray.h"     // Array of Pixel data

class BMFile {
public:
    // constructors
    // ----------------------------------------------------
    BMFile(std::ifstream* reader = nullptr, std::ofstream* writer = nullptr);
    ~BMFile();

    // accessors/mutators (getters/setters)
    // ----------------------------------------------------
    void setReader(std::ifstream* reader);
    void setWriter(std::ofstream* writer);

    // read only accessors for headers
    BMFileHeader* getFileHeader();
    BMInfoHeader* getInfoHeader();

    // member methods
    // ----------------------------------------------------
    int load();
    int store();

    std::string toString();

private:
    BMReader reader;
    BMWriter writer;

    BMFileHeader fileHeader;
    BMInfoHeader infoHeader;

    PixelArray pixels;

};


#endif //BMFILE_H
