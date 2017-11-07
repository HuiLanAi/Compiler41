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
    cout << fileContent << endl;
	
	system("pause");
}