// DemoPointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <random>

using namespace std;
typedef unsigned int uint;
int randInt(int min, int max)
{
    return (rand() % (max - min)) + min;
}

int main()
{
    std::cout << "This file is meant to help you understand File IO!\n";
    srand(time(NULL));

    cout << endl; //Just a Space

    //This is writing into the file
    ofstream outFile = ofstream("MyFile.txt");
    if (outFile.is_open())
    {
        outFile << "Hello, my name is Indigo Montoya." << endl;
        outFile << "You killed my father." << endl;
        outFile << "Prepare to die!" << endl;
        outFile.close();
    }

    //this is reading into the file
    ifstream inFile = ifstream("MyFile.txt");
    string fileAsString;
    if (inFile.is_open())
    {
        fileAsString = string(istreambuf_iterator<char>(inFile), istreambuf_iterator<char>());
        inFile.close();
    }

    //this is printing the file contents;
    cout << fileAsString << endl;


    
    cout << endl; //Just a Space

    //this is writing the encrypted file
    const int OBFUSCATION_KEY = 12345;
    ofstream outFileInc = ofstream("MySecretFile.txt");
    if (outFileInc.is_open())
    {
        for (uint i = 0; i < fileAsString.length(); i++)
        {
            fileAsString[i] ^= OBFUSCATION_KEY;
        }
        outFileInc << fileAsString;
        outFileInc.close();
    }

    //this is reading the encrypted file
    ifstream InFileInc = ifstream("MySecretFile.txt");
    string fileAsIncryptedString;
    if (InFileInc.is_open())
    {
        fileAsIncryptedString = string(istreambuf_iterator<char>(InFileInc), istreambuf_iterator<char>());
        for (uint i = 0; i < fileAsIncryptedString.length(); i++)
        {
            fileAsIncryptedString[i] ^= OBFUSCATION_KEY;
        }
        InFileInc.close();
    }
    cout << fileAsIncryptedString << endl;

    //This is writing a treasure map!
    ofstream mapFile = ofstream("MyMap.txt");
    if (mapFile.is_open())
    {
        int lines = randInt(5, 6);
        int spaces = randInt(5, 10);
        for (uint i = 0; i < lines; i++)
        {
            for (uint i = 0; i < spaces; i++)
            {
                mapFile << "*";
            }
            mapFile << endl;
        }
        mapFile << "*****x*****" << endl;
        for (uint i = 0; i < lines; i++)
        {
            for (uint i = 0; i < spaces; i++)
            {
                mapFile << "*";
            }
            mapFile << endl;
        }
        mapFile.close();
    }

    //this is reading a treasure map!
    inFile.open("MyMap.txt");
    uint space = 0;
    while (inFile.good())
    {
        string line;
        getline(inFile, line);
        
        
        for (uint i = 0; i < line.size(); i++)
        {
            if (line[i] != 'x')
                space++;
        }
    }
    cout << space << " entries before finding me treasure!" << endl;
    inFile.close();
}