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
    partLine(&originFile, filename, fileContent);//对文本进行分行
    for(int i = 0; i < originFile.size(); i++)
    {
        originFile.at(i).partition();
		system("clear");
    }

	for (int i = 0; i < originFile.size(); i++)
	{
		originFile.at(i).showSentencePart();
	}
    

    system("pause");
    return 0;
}