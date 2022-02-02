// --------------------------------------------------------
//    File: BMCoreHeader.h
//  Author: COP 3003 Programming II
// Purpose: class definition for a bitmap core header
//  wikipedia.org
//  "This block of bytes tells the application detailed information about the image,
//  which will be used to display the image on the screen. The block also matches the header
//  used internally by Windows and OS/2 and has several different variants."
//  Note:
//  "The Windows 2.x BITMAPCOREHEADER differs from the OS/2 1.x BITMAPCOREHEADER in
//  one detail that the image width and height fields are signed integers, not unsigned."
// --------------------------------------------------------

#ifndef BMCOREHEADER_H
#define BMCOREHEADER_H

#include "BMReader.h"   // bitmap file reader
#include "BMWriter.h"   // bitmap file writer

class BMCoreHeader {
public:
    // constructors
    // ----------------------------------------------------
    BMCoreHeader();

    // accessors/mutators (getters/setters)
    // properties are readonly and can only be modified
    // through the load method
    // ----------------------------------------------------
    int getSize();
    int getWidth();
    int getHeight();
    int getPlanes();
    int getDepth();


    // member methods
    // ----------------------------------------------------
    int load(BMReader* reader);
    int store(BMWriter* writer);

    std::string toString();

protected:
    DWORD size;     // size of this header
    DWORD width;    // bitmap width in pixels
    DWORD height;   // bitmap height in pixels
    WORD  planes;   // number of color planes
    WORD  depth;    // bits-per-pixel
};


#endif //BMCOREHEADER_H
