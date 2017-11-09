/* ********************************************** */
/* *******************实现文件读写相关功能*********** */
/* *************************************************** */
#pragma once
#include "fstream"
#include "string"
#include "iostream"
using namespace std;

#include "Sentence.h"

void readFile(string *filename, string* fileContent)
//功能：读取一个文件
//filename是调用函数中保存该文件名的string
//fileContent是调用函数中保存文本内容的string
{
    cout << "请输入文件名：" << endl;
    cin >> *filename;
    
    ifstream in;
    in.open(*filename);
	char temp[524288] = { 0 };
    in.getline(temp, 524288, 0);
    (*fileContent).append(temp);
    (*fileContent).append("\n");
}

void partLine(vector<Sentence>* file, string filename, string fileContent)
//将一个文本按照换行符分行
//file是调用函数中的保存每一行文本的Sentence数组
//filename是用于初始化Setence类对象的文件名
//fileContent是文本原始内容
{
    int front = 0, back = 0, line = 1;
    while(fileContent.size() > back)
    {
        if(fileContent.at(back) == '\n')
        {
            char temp[100] = { 0 };
            for(int i = front; i < back; i ++)
            {
                temp[i - front] = fileContent.at(i);
                // cout << temp[i];
            }
            Sentence tempS(line, filename, temp);
            //cout << temp << endl;
            (*file).push_back(tempS);
            line ++;
            back ++;
			if(back == fileContent.size() - 1 || back == fileContent.size())
			{
				return;
            }
            /* 溢出边界检查 */
            while(fileContent.at(back) == '\n')
            {
                line ++;
                back ++;
            }
            /* 为了解决多个换行符相邻的情况 */
            front = back;
        }
        else
        {
            back ++;
        }
    }
}
