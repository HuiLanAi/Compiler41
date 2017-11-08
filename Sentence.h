/* ************************************************* */
/* Sentence类用于保存每一行语句以及对应的token串和词法单元 */
/* ************************************************** */
#pragma once

#include "iostream"
#include "vector"
#include "string"
using namespace std;

#include "Defination.h"    
//partition的所用变量
    //判断是否是括号
    bool isBracket(char a);
    int  isLogic(char a);//   0是（）{}   1是-  2是算符  3不是算符
    int isNumber(char a);
    //判断字母  下划线
    bool isLetter(char a);
    
   //前缀符                                                                              11               15      
string prefix[] = { "-",  "+","*","/","=",">","<","&","|", "," ,"!" ,   "(" ,")" ,"{","}" ,"'","#","@","$","%","\\" , "?" , ":","_" };//11后是括号
//数字符
string numberPrefix[] = { "-","0","1","2","3","4","5","6","7","8","9" };
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

    void partition();

    int anaPart()
    {
        /* 如果产生词法错误则在此函数中报错 */
        /* 东哥写的 */
    }


};

void Sentence:: partition()
{       
       int i = 0, j = 0;//2个指针
        thisLine += '\0';
        while (thisLine[i] != '\n')
        {
            cout << "算符" << isLogic(thisLine[j]) << endl;
            string s = "";
            //处理空格
            
            while (thisLine[i] == ' ')
            {
                i++;
                j++;
            }
            cout<<"i"<<i<<endl;
            //数字类型: 开头就是数字  科学记数法：a=12e-12 开头是-  前面没有
            if (isNumber(thisLine[j]) == 2 )
            {
                //开头是数字  中间有  e-|e 数字                            数字                             小数点                     e                         e-
                while (thisLine[j] != '\n'&& thisLine[j] != ' ' && ((isNumber(thisLine[j]) == 2) || thisLine[j] == '.' || (thisLine[j]=='e') || (thisLine[j]=='e'&&thisLine[j+1]=='-')))//之后是数字  或者小数点
                {
                    //检测到e-就一起压入
                    if(thisLine[j]=='e'&&thisLine[j+1]=='-')
                         { s += thisLine[j++];
                          s += thisLine[j++];}
                          else
                          {
                            s += thisLine[j++];
                          }
                }
                sentencePart.push_back(s);
                i = j;
                s = "";
            }
            //变量  关键字
            else if (isLetter(thisLine[j]))
            {
                while (thisLine[j] != '\n'&&thisLine[j] != ' ' && isLetter(thisLine[j]))
                {
                    s += thisLine[j++];
                }
                sentencePart.push_back(s);
                i = j;
                s = "";
            }
    
            //       算符                                                    减号                                 括号
            else if (isLogic(thisLine[j]) == 2 || isLogic(thisLine[j]) == 1 || isLogic(thisLine[j]) == 0)
            {
                //减号  前面是数字
                if ( isLogic(thisLine[j]) == 1 && ( isNumber(thisLine[j-1])==2 )    )
                    {
                        s = +thisLine[j++];
                    }
                 //减号前面是算数符号
                 else if(   isLogic(thisLine[j]) == 1 &&  isLogic(thisLine[j-1]==2 ))
                 {
                        //处理负数    - [0-9] e- . e                                               
                        while (thisLine[j] != '\n'&& thisLine[j] != ' ' && ( isLogic(thisLine[j]) == 1   ||(isNumber(thisLine[j]) == 2) || thisLine[j] == '.' || (thisLine[j]=='e') || (thisLine[j]=='e'&&thisLine[j+1]=='-')))//之后是数字  或者小数点
                        {
                            //检测到e-就一起压入
                            if(thisLine[j]=='e'&&thisLine[j+1]=='-')
                                 { s += thisLine[j++];
                                  s += thisLine[j++];}
                                  else
                                  {
                                    s += thisLine[j++];
                                  }
                        }
                        cout<<"负数"<<s<<endl;
                 }
                //是括号
                else if (isLogic(thisLine[j]) == 0)
                {
                    s = +thisLine[j++];
                    cout<<"括号"<<s<<endl;
                    
                }
    
                //普通算符
                else {
                    cout<<"普通算符"<< isLogic(thisLine[j])<<endl;
                    while (thisLine[j] != '\n' && thisLine[j] != ' ' &&  isLogic(thisLine[j]) == 2  )
                    {
                        s += thisLine[j++];
                    }
                    cout<<"普通算符"<<s<<endl;
                }
    
                sentencePart.push_back(s);//核心
                i = j;
                s = "";
            }
        }
    
}


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


//判断是否是括号
bool isBracket(char a)
{
	string s = "";
	s = +a;
	for (int i = 11; i<15; i++)
	{
		if (s.compare(prefix[i]))
			return(true);
	}
	return(false);
}

int  isLogic(char a)//   0是（）{}   1是-  2是算符  3不是算符
{
	//属于标识符和逗号是false
	string s = "";
	s = +a;
	if (s.compare(prefix[0]) == 0)  return(1);//负号
	for (int i = 11; i<24; i++)
	{
		if (s.compare(prefix[i])==0)
		{
			return(2);
		}
	}
	for (int i = 1; i<11; i++)//正常算符
	{
		if (s.compare(prefix[i]) == 0)
		{
			return(2);
		}
	}

	for (int i = 11; i < 15; i++)//判断括号
	{
		if (s.compare(prefix[i]) == 0)
			return(0);
	}
	return(3);//不是算符
}

//判断开头是不是数字 -号返回1  其他返回2 不是返回三
int isNumber(char a)
{
	string s = "";
	s = +a;
	if (s.compare(numberPrefix[0]) == 0)return(1);
	for (int i = 1; i<11; i++)
	{
		if (s.compare(numberPrefix[i]) == 0)
		{
			return(2);
		}
	}
	return(3);
}

//判断字母  下划线
bool isLetter(char a)
{
	if ((a >= 'a'&&a <= 'z') || (a >= 'A'&&a <= 'Z') || a == '_')
		return(true);
	else
		return(false);
}