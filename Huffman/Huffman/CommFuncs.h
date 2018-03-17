#pragma once
#include "Dictionary.hpp"

extern int treeHeight;
extern Dictionary<char, string> dict;

const static QString nil = QString();
 
///��content���룬ͬʱд��ȫ�ֱ���������01�ַ���
QString encode(const QString & content);

///�����������ƴ������������루��ʽΪ��ð�ţ���HFMLINE�ָ�).���ؽ���״̬��1������-1ȡ��
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

///����������button,x, yΪ����xy
QPushButton * getRegularButton(QWidget * parent, int xx, int yy, string & key);

///��һ����ť ������ѡ���ļ� ���������ݡ�
QString readFile();

 
///just get writable location str
QString saveToWhere(const QString &);

///��contentд��path���Ҫ
QString writeTo(const QString & path, const QString & content, const long & length);