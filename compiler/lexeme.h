///�ʷ�����ģ��
#ifndef _LEXEME_
#define _LEXEME_
#include <string.h>
#include <iostream>
using namespace std;

typedef struct{
	int type;  //�Ǻ����
	string attribute;  //�Ǻ�����
	int raw;  //�к�
}mark;


mark get_next_mark();//�����һ��mark���ú������﷨����ģ����ôʷ�����ģ��Ľӿ�

#endif







