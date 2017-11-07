#pragma once
#include "fstream"
#include "string"
#include "iostream"
using namespace std;

void readFile(string *filename, string* fileContent)
{
    cout << "请输入文件名：" << endl;
    cin >> *filename;
    
    ifstream in;
    in.open(*filename);
	char temp[524288] = { 0 };
    in.getline(temp, 524288, 0);
	(*fileContent).append(temp);
}
