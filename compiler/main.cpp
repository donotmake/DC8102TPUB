#include <string.h>
#include <vector>
#include <iostream>
#include "error.h"
#include "utils.h"
using namespace std;


//全局变量
vector<string> scr_code_lines;  //源代码列表
vector<string> dst_code_lines;  //目标代码列表
vector<error_item> error_list;  //错误列表

void process()//语法分析驱动的入口函数
{
	

}


int main(int argc, char* argv[])
{
	settings params = preprocess(argc, argv);  //参数处理，根据用户输入的参数确定输入和输出方式

	input(params);  //源代码读入

	process();//语法分析驱动的入口函数

	output(params);  //目标代码和日志输出
}



