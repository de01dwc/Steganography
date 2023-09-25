#ifndef STEGANOGRAPHY_H
#define STEGANOGRAPHY_H

#include <string>
#include <vector>

class Steganography {

    private:
        std::string magicNumber;
        int width;
        int height;
        int maxColor;
        std::vector<int> colorData;
        std::string cipherText;
        int getNthBit(char cipherChar, int n);

    public:
        Steganography();
        void readImage(std::string fileName);
        void printImage(std::string fileName);
        void readCipherText(std::string fileName);
        void printCipherText(std::string fileName);
        void cleanImage();
        void encipher();
        void decipher();

};

#endif // STEGANOGRAPHY_H