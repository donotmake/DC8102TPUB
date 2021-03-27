#include "head.h"


void initial();             // 初始化函数  
bool isKey(string word);    // 表示识别的单词是否是关键字  
int isId(string word);      // 判断改符号是否存于符号中  
void get_nbc();             // 读取下一个非空格字符  
void get_char();            // 读取字符  
void analysis();            // 分析程序  
void file_close();  		// 关闭文件 
char c;                     // 记录当前读入的字符 
int col = 0;                // 记录当前列数  
int row = 1;                // 记录当前行数  
int character = 0;          // 记录当前字符数  
int word = 0;               // 记录当前单词数  
int end_sign = 0;			// 程序结束标志，1表示结束（遇到EOF） 
int is_int = 1;				//判断数是否问整数 
ifstream in;                // 读入文件对象  
string fileName;            // 待进行词法分析的文件名  
vector<string> Id;          // 存放符号表的数据结构  
string category;            // 记录记号类别 
string sub_category;        // 记录记号子类 
string content;             // 记录记号内容 
void record_word(int record_id); 	// 将信息录入结构体 
void record_error();		//录入错误信息 


void record_word(int record_id)
{
	n++;
	token[n].id = record_id;
	token[n].symbol = sub_category;
	token[n].name = content;
	token[n].cnum = col;
	token[n].rnum = row;
}

void record_error()
{
	lexicalError++;
	error_message[lexicalError].id = 0;
	error_message[lexicalError].symbol = sub_category;
	error_message[lexicalError].name = content;
	error_message[lexicalError].cnum = col;
	error_message[lexicalError].rnum = row;
}

/*
	初始化函数：输入要进行词法分析的文件名
*/
void initial()
{
	cout << "词法分析开始，请输入要分析的文件名(例如：test.txt):";
	cin >> fileName;
	in.open(fileName.c_str(), ios::in);
	if (!in) {
		cout << "打开文件失败。" << endl;
	}
	c = in.get();
	cout << "类别编码" << "\t" << "助记符" << "\t" << "单词" << "\t" << "行号" << "\t" << "列号" << endl;
}

/*
	关键字函数：判断识别出来的单词是否是关键字
*/
bool isKey(string word)
{
	for (int i = 0; i < Key.size(); i++) {
		if (Key[i] == word)
			return true;
	}
	return false;
}

/*
	符号表函数：判断识别出来的非关键字单词是否是已经存在的符号，
			   如果存在，返回相对指针；否则加入到符号表中。
*/
int isId(string word)
{
	int i = 0;
	for (i; i < Id.size(); i++) {
		if (Id[i] == word)
			return i;
	}
	Id.push_back(word);
	return i;
}

/*
	读取字符函数：读取下一个字符
*/
void get_char()
{
	character++;
	c = in.get();
	col++;
}

/*
	关闭相关文件函数
*/

void file_close()
{
	in.close();
}
/*
	词法分析函数：进行文件分析
*/
void analysis()
{
	string str;       // 创建储存当前单词的对象  
	str.clear();
	if (!in.is_open()) {    // 如果文件未正常打开，及时报错  
		cout << "打开文件失败！" << endl;
	}
	else {
		if (c != EOF) {
			switch (c)
			{
			case 'A':   case 'B':   case 'C':   case 'D':
			case 'E':   case 'F':   case 'G':   case 'H':   case 'I':   case 'J':
			case 'K':   case 'L':   case 'M':   case 'N':   case 'O':   case 'P':
			case 'Q':   case 'R':   case 'S':   case 'T':   case 'U':   case 'V':
			case 'W':   case 'X':   case 'Y':   case 'Z':
				c = c + 32;
			case 'a':   case 'b':   case 'c':   case 'd':   case 'e':   case 'f':
			case 'g':   case 'h':   case 'i':   case 'j':   case 'k':   case 'l':
			case 'm':   case 'n':   case 'o':   case 'p':   case 'q':   case 'r':
			case 's':   case 't':   case 'u':   case 'v':   case 'w':   case 'x':
			case 'y':   case 'z':
			case '_':
				word++;
				while (isalpha(c) || isdigit(c) || c == '_') {
					str += c;
					get_char();
				}
				if (c == '~' || c == '@' || c == '$' || c == '?') {//处理变量命名错误  含非法字符 
					int tag = col;
					while (isalpha(c) || isdigit(c) || c == '_' || c == '~' || c == '@' || c == '$' || c == '?') {
						str += c;
						get_char();
					}
					category = "ERROR";
					sub_category = "WRONG_SIGNAL";
					content = str;
					record_error();
					str.clear();
					break;
				}
				if (isKey(str)) {
					category = "RESERVED";
					sub_category = "KEY_" + str;
					content = str;
					if (str == "program") record_word(101);
					else if (str == "const") record_word(102);
					else if (str == "var") record_word(103);
					else if (str == "procedure") record_word(104);
					else if (str == "function") record_word(105);
					else if (str == "begin") record_word(106);
					else if (str == "end") record_word(107);
					else if (str == "array") record_word(108);
					else if (str == "of") record_word(109);
					else if (str == "integer") record_word(110);
					else if (str == "real") record_word(111);
					else if (str == "boolean") record_word(112);
					else if (str == "char") record_word(113);
					else if (str == "if") record_word(114);
					else if (str == "then") record_word(115);
					else if (str == "else") record_word(116);
					else if (str == "for") record_word(117);
					else if (str == "to") record_word(118);
					else if (str == "do") record_word(119);
					else if (str == "read") record_word(120);
					else if (str == "write") record_word(121);
					else if (str == "or") record_word(122);
					else if (str == "div") record_word(123);
					else if (str == "mod") record_word(124);
					else if (str == "and") record_word(125);
					else if (str == "not") record_word(126);
					else if (str == "string") record_word(127);
				}
				else {
					int i = isId(str);
					category = "ID";
					sub_category = "id";
					content = str;
					record_word(1);
				}
				str.clear();
				break;
			case '0':   case '1':   case '2':
			case '3':   case '4':   case '5':
			case '6':   case '7':   case '8':
			case '9':
				is_int = 1;
				word++;
				while (isdigit(c) || c == '.' || c == 'e' || c == 'E') {
					str += c;
					if (!isdigit(c))
						is_int = 0;
					if (c == 'e' || c == 'E') {
						get_char();
						str += c;
					}
					get_char();
				}
				if (isalpha(c)) {//1A1 处理数字中出现字母字符的错误，或是以数字开头的变量名错误 
					int tag = col;
					while (isalpha(c) || isdigit(c) || c == '_' || c == '@' || c == '#' || c == '$' || c == '?') {
						str += c;
						get_char();
					}
					category = "ERROR";
					sub_category = "WRONG_NUM";
					content = str;
					record_error();
					str.clear();
					break;
				}
				if (is_int == 0) {
					category = "REL";
					sub_category = "REL";
					content = str;
					record_word(3);
				}
				else {
					category = "INT";
					sub_category = "INT";
					content = str;
					record_word(2);
				}
				str.clear();
				break;
			case '>':
				get_char();
				if (c == '=') {
					category = "OPERATOR";
					sub_category = "OPR_gequal";
					content = ">=";
					record_word(207);
				}
				else {
					category = "OPERATOR";
					sub_category = "OPR_great";
					content = ">";
					record_word(205);
					break;
				}
				get_char();
				break;
			case '<':
				get_char();
				if (c == '=') {
					category = "OPERATOR";
					sub_category = "OPR_lequal";
					content = "<=";
					record_word(208);
				}

				else if (c == '>') {
					category = "OPERATOR";
					sub_category = "OPR_nequal";
					content = "<>";
					record_word(209);
				}

				else {
					category = "OPERATOR";
					sub_category = "OPR_less";
					content = "<";
					record_word(206);
					break;
				}
				get_char();
				break;
			case '=':
				get_char();
				category = "OPERATOR";
				sub_category = "OPR_equal";
				content = "=";
				record_word(202);
				break;
			case '+':
				get_char();
				category = "OPERATOR";
				sub_category = "OPR_add";
				content = "+";
				record_word(203);
				break;
			case '-':
				get_char();
				category = "OPERATOR";
				sub_category = "OPR_sub";
				content = "-";
				record_word(204);
				break;
			case '*':
				get_char();
				category = "OPERATOR";
				sub_category = "OPR_mul";
				content = "*";
				record_word(210);
				break;
			case '\'':
				str += c;
				get_char();
				while (c != '\'' && c != '\n') {
					str += c;
					get_char();
				}
				if (c == '\n') {
					category = "ERROR";
					sub_category = "STRING_END_SIGNAL_LOST";
					content = str;
					record_error();
					str.clear();
					break;
				}
				str += c;
				category = "STRING";
				sub_category = "string";
				content = str;
				record_word(5);
				str.clear();
				get_char();
				break;
			case '/':
				get_char();
				category = "OPERATOR";
				sub_category = "OPR_div";
				content = "/";
				record_word(211);
				break;
			case ':':
				get_char();
				if (c == '=') {
					category = "OPERATOR";
					sub_category = "OPR_assign";
					content = ":=";
					record_word(201);
				}
				else {
					category = "PUNCTUATION";
					sub_category = "PUN_colon";
					content = ":";
					record_word(306);
					break;
				}
				get_char();
				break;
			case '(':
				get_char();
				category = "PUNCTUATION";
				sub_category = "PUN_lbrkt";
				content = "(";
				record_word(301);
				break;
			case ')':
				get_char();
				category = "PUNCTUATION";
				sub_category = "PUN_rbrkt";
				content = ")";
				record_word(302);
				break;
			case ',':
				get_char();
				category = "PUNCTUATION";
				sub_category = "PUN_comma";
				content = ",";
				record_word(303);
				break;
			case ';':
				get_char();
				category = "PUNCTUATION";
				sub_category = "PUN_semicolon";
				content = ";";
				record_word(304);
				break;
			case '.':
				get_char();
				if (c == '.') {
					category = "PUNCTUATION";
					sub_category = "PUN_ddot";
					content = "..";
					record_word(312);
				}
				else {
					category = "PUNCTUATION";
					sub_category = "PUN_dot";
					content = ".";
					record_word(305);
					break;
				}
				get_char();
				break;
			case '[':
				get_char();
				category = "PUNCTUATION";
				sub_category = "PUN_lsbrkt";
				content = "[";
				record_word(308);
				break;
			case ']':
				get_char();
				category = "PUNCTUATION";
				sub_category = "PUN_rsbrkt";
				content = "]";
				record_word(309);
				break;
			case '{':
				get_char();
				str += c;
				get_char();
				while (c != '}' && c != EOF) {
					str += c;
					get_char();
				}
				if (c == EOF) {
					category = "ERROR";
					sub_category = "COMMENT_END_SIGNAL_LOST";
					content = "notes";
					end_sign = 1;
					record_error();
					break;
				}
				str += c;
				category = "NOTES";
				sub_category = "notes";
				content = "notes";
				str.clear();
				get_char();
				break;
			case ' ':
			case '\t':
				get_char();
				category = "POINTLESS";
				sub_category = "pointless";
				content = "pointless";
				break;
			case '\n':
				get_char();
				category = "POINTLESS";
				sub_category = "pointless";
				content = "pointless";
				row++;
				col = 0;
				break;
			}
		}
		else {
			end_sign = 1;
			file_close();
		}

	}
}
