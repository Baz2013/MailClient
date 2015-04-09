#include"Config.h"
#include<fstream>
#include<iostream>

bool Config::IsSpace(char c){
  if ( ' ' == c || '\t' == c){
   return true;
  }
 return false;
}

bool Config::IsCommentChar(char c){
  switch(c){
   case COMMENT_CHAR :
      return true; 
   default :
     return false;
   }
}

//去掉字符串中的空格
void Config::trim(string &str){
  if(str.empty()){
   return;
  }
  int i,start_pos,end_pos;
  for(i=0;i<str.size();++i){
    if(!IsSpace(str[i])){
     break;
    }
 } 
  if(i==str.size()){
    str = "";
  }
  start_pos = i;
  for(i=str.size() - 1;i>=0;--i){
    if(!IsSpace(str[i])){
      break;
    } 
  }
  
  end_pos = i;

  str = str.substr(start_pos,end_pos - start_pos + 1);
}

bool Config::AnalyseLine(const string &line,string &key,string &value){
  if(line.empty()){
    return false;
  }
  int start_pos = 0;
  int end_pos = line.size() - 1;
  int  pos;
  if((pos = line.find(COMMENT_CHAR)) != -1){
     if(0==pos){
     return false;
   } 
  end_pos = pos - 1;
 } 

  //预处理,删除注释
  string new_line = line.substr(start_pos,start_pos + 1 - end_pos);
  if((pos = new_line.find('=')) == -1)
     return  false; //没有 = 号
  key = new_line.substr(0,pos);
  value = new_line.substr(pos + 1,end_pos + 1 -(pos + 1));
  
  trim(key);
  if(key.empty()){
    return false;
   }

   trim(value);
   return true;
}

/**
功能 : 读取文件中的一行,然后对该行解析,将=号前后的值分别
       赋值给key和value,然后组成map m 的一个元素
参数 : const string &filename,map<string,string> &m
返回值 : bool 类型
*/
bool Config::ReadConfig(map<string,string> &m){
  m.clear();
  ifstream infile(config_filename.c_str());
  if(!infile){
    cout<<"file open error!!"<<endl; //文件不存在
    return false;
   }

  string line,key,value;
  while(getline(infile,line)){
    // cout<<line<<endl;
    if(AnalyseLine(line,key,value)){
       m[key] = value;
    }
  }

  infile.close();
  return true;
}

void Config::PrintConfig(const map<string,string> &m){
  map<string,string>::const_iterator mite = m.begin();
  for (;mite != m.end();++mite){
   cout<<mite->first<<"="<<mite->second<<endl; 
  }
}

void Config::init(){
	map<string,string> map_config ;
	ReadConfig(map_config);
	
	map<string,string>::iterator it1 = map_config.find("username");
	if (it1 != map_config.end()){
	 	username = it1->second;
	}
	
	map<string,string>::iterator it2 = map_config.find("password");
	if (it2 != map_config.end()){
	 	password = it2->second;
	}

	map<string,string>::iterator it3 = map_config.find("servname");
	if (it3 != map_config.end()){
	 	password = it3->second;
	}

	map<string,string>::iterator it4 = map_config.find("input_filename");
	if (it4 != map_config.end()){
	 	password = it4->second;
	}

	map<string,string>::iterator it5 = map_config.find("output_filename");
	if (it5 != map_config.end()){
	 	password = it5->second;
	}

	map<string,string>::iterator it6 = map_config.find("input_token");
	if (it6 != map_config.end()){
	 	password = it6->second;
	}

	map<string,string>::iterator it7 = map_config.find("output_token");
	if (it7 != map_config.end()){
	 	password = it7->second;
	}
}
