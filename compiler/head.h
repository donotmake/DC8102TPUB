// 建议所有源文件都用这个当头文件，加入新库文件也加在这里

#include<iostream>  
#include<fstream>  
#include<vector>  
#include<iomanip>  
using namespace std;

#define ID	1
#define INT 2
#define REL 3
#define DIG 4	// 貌似没啥必要，优先考虑int
#define STR 5

#define KEY_program 101
#define KEY_const   102
#define KEY_var		103
#define KEY_procedure 104
#define KEY_funtion	105
#define KEY_begin	106
#define KEY_end		107
#define KEY_array	108
#define KEY_of		109
#define KEY_integer	110
#define KEY_real	111
#define KEY_boolean	112
#define KEY_char	113
#define KEY_if		114
#define KEY_then	115
#define KEY_else    116
#define KEY_for     117
#define KEY_to		118
#define KEY_do      119
#define KEY_read	120
#define KEY_write	121
#define KEY_or		122
#define KEY_div		123
#define KEY_mod		124
#define KEY_and		125
#define KEY_not		126
#define KEY_string	127

#define OPR_assign	201
#define OPR_equal	202
#define OPR_add		203
#define OPR_sub		204
#define OPR_great	205
#define OPR_less	206
#define OPR_gequal	207
#define OPR_lequal	208
#define OPR_nequal	209
#define OPR_mul		210
#define OPR_div		211

#define PUN_lbrkt	301
#define PUN_rbrkt	302
#define PUN_comma	303
#define PUN_semicolon	304
#define PUN_dot		305
#define PUN_colon	306
#define PUN_quotation	307
#define PUN_lsbrkt	308
#define PUN_rsbrkt	309
#define PUN_lcbrkt	310
#define PUN_rcbrkt	311
#define PUN_ddot	312


// 利用string数组存储关键字  
string KEY[] = {
	"program",   "const",   "var",   "procedure",   "function",
	"begin",   "end",   "array",   "of",   "integer",
	"real",   "boolean",   "char",   "if",   "then",
	"else",   "for",   "to",   "do",   "read",
	"write",   "or",   "div",   "mod",   "and",
	"not",   "string"
};
// 将关键字数组存贮到全局变量vector中便于查询  
vector<string> Key(KEY, KEY + sizeof(KEY) / sizeof(KEY[0]));

struct Word
{
	int id;			// 类别编码：宏定义中的序号，
	string symbol;	// 助记符：类似 KEY_begin 之类的
	string name;	// 标识符：这个变量本身的名字，类似 program，i，j 之类的
	int rnum;		// 行号
	int cnum;		// 列号
};

int n = 0;				// 词法分析结构体个数
int lexicalError = 0;	// 词法分析错误数
struct Word token[500];	// 存放词法分析结果的结构体
struct Word error_message[500];//存放错误信息 
