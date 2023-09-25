#include "steganography.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void Steg::readImage(string fileName)
{
    ifstream jFile;
    jFile.open(fileName);
    
    if(jFile.is_open())
    {
        jFile >> magicNumber;
	    jFile >> width;
        jFile >> height;
        jFile >> maxColor;
    }
}

void Steg::printImage(string fileName)
{
    ifstream jFile;
    jFile.open(fileName);
    
    if(jFile.is_open())
    {
        for(int i = 0; i < width; i++)
        {
            for(int q = 0; q < height; q++)
            {
                
            }
        }
    }
}

int Steg::getNthBit(char cipherChar, int n)
{
    
    return 
}
