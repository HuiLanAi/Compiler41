/* ************************************************* */
/* Sentence类用于保存每一行语句以及对应的token串和词法单元 */
/* ************************************************** */
#pragma once

#include "iostream"
#include "vector"
#include "string"
using namespace std;

#include "Defination.h"

class Sentence
{
public:
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
        int i;
        for(i=0;i<sentencePart.size();i++)
        {
    
        //判断关键字,运算符
            if(sentencePart[i]=="int")
                 sentencePart.push_back(INT);
            else if(sentencePart[i]=="long")
                 sentencePart.push_back(LONG_INT);
            else if(sentencePart[i]=="float")
                 sentencePart.push_back(FLOAT);
            else if(sentencePart[i]=="double")
                 sentencePart.push_back(DOUBLE);
            else if(sentencePart[i]=="void")
                 sentencePart.push_back(VOID);
            else if(sentencePart[i]=="+")
                 sentencePart.push_back(ADD);
            else if(sentencePart[i]=="-")
                 sentencePart.push_back(MINUS);
            else if(sentencePart[i]=="*")
                 sentencePart.push_back(MULT);
            else if(sentencePart[i]=="/")
                sentencePart.push_back(DIV);
            else if(sentencePart[i]=="&")
                 sentencePart.push_back(ADD);
            else if(sentencePart[i]=="|")
                 sentencePart.push_back(OR);
            else if(sentencePart[i]=="!")
                 sentencePart.push_back(NOT);
            else if(sentencePart[i]=="<")
                 sentencePart.push_back(LESS);
            else if(sentencePart[i]==">")
                 sentencePart.push_back(MORE);
            else if(sentencePart[i]=="<=")
                 sentencePart.push_back(LESS_EQU);
            else if(sentencePart[i]==">=")
                 sentencePart.push_back(MORE_EQU);
            else if(sentencePart[i]=="==")
                 sentencePart.push_back(DOUBLE_EQU);
            else if(sentencePart[i]=="=")
                 sentencePart.push_back(EQUAL);
            else if(sentencePart[i]==",")
                 sentencePart.push_back(LINGER);
            else if(sentencePart[i]=="(")
                 sentencePart.push_back(LEFT);
            else if(sentencePart[i]==")")
                 sentencePart.push_back(RIGHT);
            else if(sentencePart[i]=="{")
                 sentencePart.push_back(LEFT_BRACE);
            else if(sentencePart[i]=="}")
                 sentencePart.push_back(RIGHT_BRACE);
            else if(sentencePart[i]=="if")
                 sentencePart.push_back(IF);
            else if(sentencePart[i]=="else")
                 sentencePart.push_back(ELSE);
            else if(sentencePart[i]=="while")
                 sentencePart.push_back(WHILE);
            else if(sentencePart[i]=="return")
                 sentencePart.push_back(RETURN);
            else if(sentencePart[i]=="'")
                 sentencePart.push_back(SINGLE_QOUTE);
            else if(sentencePart[i]=="\"")
                 sentencePart.push_back(DOUBLE_QOUTE);
        /* 如果产生词法错误则在此函数中报错 */
        /* 东哥写的 */
    }


};

void mergeString(vector<string>* str1, vector<int>* type, vector<Sentence> array)
/*  将文本中所有行的词法单元和种类都合并到一起 */
{
    for(int i = 0; i < array.size(); i++)
    {
        //外层循环遍历所有的Sentence元素
        for(int j = 0; j < array.at(i).sentencePart.size(); j++)
        {
            //内层循环遍历一个Sentence元素中的所有成员
            (*str1).push_back(array.at(i).sentencePart.at(j));
            (*type).push_back(array.at(i).partType.at(j));
        }
    }
}