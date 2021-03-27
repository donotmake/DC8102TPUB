//错误处理模块
#ifndef _ERROR_
#define _ERROR_

//阶段定义
#define LEXEME 1  //词法分析
#define SYNTAX 2  //语法分析
#define SEMANTEME 3  //语义分析

//错误代码定义
//(未填）

typedef struct {
	int raw; //错误出现的行数
	int stage; //错误出现的阶段
	int error_code; //错误代码
}error_item;  //错误条目

void append_error(int raw, int stage, int error_code);//向错误列表添加错误条目

#endif



