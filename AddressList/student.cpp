/*====================================================

  Copyright(C) 2021-2022 Lyuyk
  All rights reserved

  文件名称:student.cpp
  摘要:学生结构体文件
  当前版本号:v1.0
  版本历史信息：无

  created by Lyuyk at 12/29/2021

=====================================================*/
#include "student.h"
#include <QString>
#include <string.h>

student::student(const student &s)
{
    strcpy_s(name, s.name);
    strcpy_s(sex, s.sex);
    strcpy_s(number, s.number);
    birthday = s.birthday;
    strcpy_s(phonenum, s.phonenum);
    strcpy_s(addr, s.addr);
}

//重载姓名判等于
bool student::operator == (const char key[21])//name
{return strcmp(name, key) == 0  ? true : false;}

//重载学号判等于
bool student::operator >= (const char key[21])//number
{return strcmp(number, key) == 0  ? true : false;}

//重载电话号码判等于
bool student::operator <= (const char key[21])//phoneNum
{return strcmp(phonenum, key) == 0 ? true : false;}

//重载生日与关键码判大于
bool student::operator > (const unsigned &key) {return birthday > key ? true : false;}

//重载生日与关键码判等于
bool student::operator == (const unsigned &key) {return birthday == key ? true : false;}

//重载生日与关键码判小于
bool student::operator < (const unsigned &key) {return birthday > key ? true : false;}

//重载生日与关键码判大于(右值为类成员)
bool operator > (const unsigned &key, const student &s) {return key > s.birthday ? true : false;}

//重载生日与关键码判等于(右值为类成员)
bool operator == (const unsigned &key, const student &s) {return key == s.birthday ? true : false;}

//重载生日与关键码判小于(右值为类成员)
bool operator < (const unsigned &key, const student &s) {return key < s.birthday ? true :false;}

//学生之间按年龄比较：大于
bool operator > (const student &s1, const student &s2) {return s1.birthday > s2.birthday ? true : false;}

//学生之间按年龄比较：等于
bool operator == (const student &s1, const student &s2) {return s1.birthday == s2.birthday ? true : false;}

//学生之间按年龄比较：大于
bool operator < (const student &s1, const student &s2) {return s1.birthday < s2.birthday ? true : false;}

