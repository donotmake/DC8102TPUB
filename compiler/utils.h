//ͨ��ģ��
#ifndef _UTILS_
#define _UTILS_
#include <string.h>
#include <vector>
#include <iostream>
using namespace std;

typedef struct {
	string scr_path;  //Դ����·��
	string dst_path;  //Ŀ�����·��
	string log_path;  //��־·��
	bool file_output;  //�Ƿ��ṩ�ļ����
}settings;

settings preprocess(int argc, char* argv[]);  //�������������û�����Ĳ���ȷ������������ʽ
void input(settings params);  //Դ�������
void output(settings params);  //Ŀ��������־���

#endif