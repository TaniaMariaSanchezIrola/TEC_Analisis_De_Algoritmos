#include <iostream>
#include "matrix.h"
#include <fstream>
#include <cstdlib>

using namespace std;

void exportCsvMatrix(int pHeight, int pWidth, std::string pName){
    Matrix* testMatrix = new Matrix(pHeight, pWidth);
    std::cout << "Matrix done, writing csv..." << std::endl;
    std::ofstream outdata;          // outdata is like cin
    int i;                          // loop index
    outdata.open(pName);   // opens the file
    if( !outdata ) {                // file couldn't be opened
        std::cerr << "Error: file could not be opened" << std::endl;
        exit(1);
    }

    for (int square = 0; square < testMatrix->amountSquares; square++)
    {
        for (int line = 0; line < testMatrix->squares->at(square)->lines->size(); line++)
        {
            outdata << testMatrix->squares->at(square)->lines->at(line)->initialPoint->toString();
            for(int point = 0;point < testMatrix->squares->at(square)->lines->at(line)->referenceListPoints->size(); point++){
                outdata << testMatrix->squares->at(square)->lines->at(line)->referenceListPoints->at(point)->toString();
            }
            outdata << testMatrix->squares->at(square)->lines->at(line)->finalPoint->toString();
            outdata << "|"; //Line Separator
        }
        outdata << ",";     //Square separator
    }
    std::cout << "Csv done!" << std::endl;
    outdata.close();
}

int main(){
    //f(n) = 96nr + 532n + 10

    //This will create your matrix with the name given in csv format.
    exportCsvMatrix(100, 100, "testing 1.csv");
    exportCsvMatrix(200, 300, "testing 2.csv");      
    
}