#include "iostream"
#include "string"
using namespace std;

#include "Sentence.h"
#include "Defination.h"
#include "LoadFile.h"

int main()
{
    string filename, fileContent;
    readFile(&filename, &fileContent);
    vector<Sentence> originFile;//主Sentence数组 
    partLine(&originFile, filename, fileContent);

    system("pause");
    return 0;
}