//������ģ��
#ifndef _ERROR_
#define _ERROR_

//�׶ζ���
#define LEXEME 1  //�ʷ�����
#define SYNTAX 2  //�﷨����
#define SEMANTEME 3  //�������

//������붨��
//(δ�

typedef struct {
	int raw; //������ֵ�����
	int stage; //������ֵĽ׶�
	int error_code; //�������
}error_item;  //������Ŀ

void append_error(int raw, int stage, int error_code);//������б���Ӵ�����Ŀ

#endif



