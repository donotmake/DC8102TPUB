///词法分析模块
#ifndef _LEXEME_
#define _LEXEME_
#include <string.h>
#include <iostream>
using namespace std;

typedef struct{
	int type;  //记号类别
	string attribute;  //记号属性
	int raw;  //行号
}mark;


mark get_next_mark();//获得下一个mark，该函数是语法分析模块调用词法分析模块的接口

#endif







