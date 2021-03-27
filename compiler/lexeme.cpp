/*
	错误文件在主程序中进行打开和关闭
	category表示记号类别
	sub_category表示记号子类
	content表示记号内容
	row为行号
	col为列号 回车算到下一行0列
	空格,\t,\n统一为 pointless无意义符号
	end_sign为文件结束标记 1表示结束
*/
#include "LexicalAnalysis.h"

int main()
{
	ofstream out_error;
	out_error.open("error.txt", ios::in);
	out_error << "类别编码" << "\t" << "助记符" << "\t" << "单词" << "\t" << "行号" << "\t" << "列号" << endl;
	initial();
	while (end_sign != 1) {
		analysis();
		if (end_sign != 1 && sub_category != "pointless" && category != "ERROR")
			cout << token[n].id << "\t" << token[n].symbol << "\t" << token[n].name << "\t" << token[n].rnum << "\t" << token[n].cnum << endl;
	}


	if (end_sign == 1) {
		cout << "end of file!" << endl;
		for (int i = 1; i <= lexicalError; i++)
			out_error << error_message[i].id << "\t" << error_message[i].symbol << " " << error_message[i].name << " 第" << error_message[i].rnum << "行，第" << error_message[i].cnum << "列"
			<< " 错误阶段：词法分析" << endl;
		out_error << "共有" << lexicalError << "处错误。" << endl;
	}
	out_error.close();
	system("pause");
}
