#pragma once
#include "Dictionary.hpp"

extern int treeHeight;
extern Dictionary<char, string> dict;

const static QString nil = QString();
 
///对content编码，同时写入全局变量，返回01字符串
QString encode(const QString & content);

///参数：二进制串，霍夫曼编码（格式为单冒号，以HFMLINE分隔).返回解码状态，1继续，-1取消
int decode(const QString & binary, const QString & hfmTree);

///reset static members
void resetProj();

///alert. most simple
void showErrorMessage(QString & msg);

///question with result titles. select result returned as title name 
int showQuestionMsg(QString & msg, QString & title1, QString & title2, QString & title3);

///info. most simple
void showInfoMessage(QString & msg);

///reference to the str. postLength doesnt contain '.' //If file exsits, rename it by inserting (1),(2)...
void fileExists(string & str, int postLength);

///str append a char. I think it's more efficient
void append(string & str, char c);

///str1 append str2
void append(string & str1, const string & str2);

///适用于树的button,x, y为正常xy
QPushButton * getRegularButton(QWidget * parent, int xx, int yy, string & key);

///点一个按钮 弹出来选择文件 并返回内容。
QString readFile();

 
///just get writable location str
QString saveToWhere(const QString &);

///把content写到path里。需要
QString writeTo(const QString & path, const QString & content, const long & length);