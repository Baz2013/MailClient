#ifndef _GET_CONFIG_H_
#define _GET_CONFIG_H_
#include<string>
#include<map>
using namespace std;
//#define COMMENT_CHAR '#' //配置文件中的注释

class Config{
public:
Config(string config_file):config_filename(config_file){};
bool ReadConfig(const string &filename,map<string,string> &m);
void PrintConfig(const map<string,string> &m);
//void setParam(const map<string,string> &m);
void init();

private:
string COMMENT_CHAR = '#';
string username ;
string password;
string servname;
string input_filename;
string output_filename;
string input_token;
string output_token;
string config_filename;

bool AnalyseLine(const string &line,string &key,string &value);
bool IsCommentChar(char c);
void trim(string &str);
bool IsSpace(char c);

};
#endif
