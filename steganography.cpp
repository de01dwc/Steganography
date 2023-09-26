#include "Steganography.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void Steganography::readImage(string fileName)
{
    //Opening the file for reading
    ifstream jFile;
    jFile.open(fileName);

    //Placing the data into member variables
    if(jFile.is_open())
    {
        jFile >> magicNumber;
        jFile >> width;
        jFile >> height;
        jFile >> maxColor;

        //loop over width and height of the sample data
        for(int i = 0; i < width; i++)
        {
            for(int q = 0; q < height; q++)
            {
                int r, g, b;
                jFile >> r >> g >> b;
                cout << " " << r << " " << g << " " << b << " ";
                colorData.push_back(r);
                colorData.push_back(g);
                colorData.push_back(b);
            }
            cout << endl;
        }
    }
}

void Steganography::printImage(string fileName)
{
    ofstream tFile;
    tFile.open(fileName);

    tFile << magicNumber;
    tFile << width;
    tFile << height;
    tFile << maxColor;


    if(tFile.is_open())
    {
        for(int i = 0; i < width; i++)
        {
            for(int q = 0; q < height; q++)
            {
                int r, g, b;
                tFile << r << g << b;
                cout << r << g << b << " ";
            }
        }
    }
}

void Steganography::readCipherText(string fileName){
    ifstream jFile;
    jFile.open(fileName);

    int index;
    cipherText = "Run through the wall";

    for(int u = 0; u < index; u++){
        cipherText;
        index++;
    }
}

void Steganography::printCipherText(string fileName){
    ofstream tFile;
    tFile.open(fileName);
}

void Steganography::cleanImage() {

    // replace each least significant bit in colorData with zero
    for (int i = 0; i < colorData.size(); i++) {
        colorData[i] &= ~(1);
    }
}

int Steganography::getNthBit(char cipherChar, int n) {
    return (cipherChar >> n) & 1;
}

void Steganography::encipher() {

    // check there are enough pixels to encipher entire text
    if (colorData.size() < cipherText.length() * 8) throw runtime_error("PPM image too small to encipher text");

    // index for colorData
    int index = 0;

    // loop over each character in text
    for (int pos = 0; pos < cipherText.length(); pos++) {

        // encipher character into least significant character bit across next eight values in colorData
        for (int bit = 7; bit >=0; bit--) {
            colorData[index] |= getNthBit(cipherText[pos], bit); // using the required helper function
            index++;
        }
    }
}

void Steganography::decipher() {

    // initialize output text
    cipherText = "";

    // loop over each value in colorData 
    // for() increase intentionally excluded, index incremented inside inner for loop
    for (int index = 0; index < colorData.size(); ) {

        // create new character value
        char val = 0;

        // extract least significant bit of next eight colorData values to reconstruct character
        for (int bit = 7; bit >= 0; bit--) {
            val |= (colorData[index] & 1) << bit;
            index++;
        }

        // if no character value, assume end of text
        if (val == 0) return;

        // push character value onto end of text string
        cipherText.push_back(val);
    }
}
