// --------------------------------------------------------
//    file: main.cpp
//  Author: COP 3003 Programming II
// Purpose: class def file for steganography encryptor
// --------------------------------------------------------

#ifndef ENCRYPTEDPIXELARRAY_H
#define ENCRYPTEDPIXELARRAY_H

#include <string>
#include "PixelArray.h"
#include "BMFile.h"

class EncryptedPixelArray : public BMFile {
public:
    EncryptedPixelArray(int width = 0, int height = 0);

    EncryptedPixelArray(int width = 0, int height = 0);

    int encrypt(std::string message);

    std::string decrypt(BMFile);

private:
};


#endif //ENCRYPTEDPIXELARRAY_H
