#include "iostream"
#include "string"
using namespace std;

#include "Sentence.h"
#include "Defination.h"
#include "LoadFile.h"

int main()
{
    string filename, fileContent;
    readFile(&filename, &fileContent);//读取文件
    vector<Sentence> originFile;//主Sentence数组 
    partLine(&originFile, filename, fileContent);//文本分行写入Sentence
    for(int i = 0; i < originFile.size(); i++)
    {
        originFile.at(i).partition();
    }//完成分词

    for(int i = 0; i < originFile.size(); i++)
    {
        originFile.at(i).showSentencePart();
    }

    system("pause");
    return 0;
}