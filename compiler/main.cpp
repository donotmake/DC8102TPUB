#include <string.h>
#include <vector>
#include <iostream>
#include "error.h"
#include "utils.h"
using namespace std;


//ȫ�ֱ���
vector<string> scr_code_lines;  //Դ�����б�
vector<string> dst_code_lines;  //Ŀ������б�
vector<error_item> error_list;  //�����б�

void process()//�﷨������������ں���
{
	

}


int main(int argc, char* argv[])
{
	settings params = preprocess(argc, argv);  //�������������û�����Ĳ���ȷ������������ʽ

	input(params);  //Դ�������

	process();//�﷨������������ں���

	output(params);  //Ŀ��������־���
}



