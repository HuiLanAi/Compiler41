#pragma once

#include "iostream"
#include "vector"
#include "string"
using namespace std;

#include "Defination.h"

class Sentence
{
    string fileName;//所在文件
    int line;//所在行数
    string thisLine;
    vector<string> sentencePart;
    vector<int> partType;

    Sentence()
    /* 默认构造函数 */
    {
        ;
    }

    Sentence(int l, string f, string s)
    /* 初始化行数和内容 */
    {
        line = l;
        thisLine = s;
        fileName = f;
    }

    void partition()
    {
        ;
        /* 填入朱强所写的代码 */
    }

    int anaPart()
    {
        /* 如果产生词法错误则在此函数中报错 */
        /* 东哥写的 */
    }


};
