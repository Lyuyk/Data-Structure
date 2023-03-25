#ifndef STUDENT_H
#define STUDENT_H
#include <QMessageBox>
#include <iostream>
using namespace std;


struct student
{
    student() {};
    student(const student &s);                                          //拷贝构造函数
    char name[21];                                                      //姓名(20位字符)
    char sex[5];                                                        //性别：男/女
    char number[21];                                                    //学号(20位数字)
    unsigned birthday;                                                  //出生日期：1~23位存储年份，24~27存储月份，28~32存储日期
    char phonenum[12];                                                  //手机号
    char addr[50];                                                      //地址
    bool operator == (const char key[21]);//重载姓名与关键码判等于
    bool operator >= (const char key[21]);//重载学号与关键码判等于
    bool operator <= (const char key[21]);//重载电话号码与关键码判等于
    bool operator > (const unsigned &key);                              //重载生日与关键码判大于(左值为类成员)
    bool operator == (const unsigned &key);                             //重载生日与关键码判等于(左值为类成员)
    bool operator < (const unsigned &key);                              //重载生日与关键码判小于(左值为类成员)
    friend bool operator > (const unsigned &key, const student &s);     //重载生日与关键码判大于(右值为类成员)
    friend bool operator == (const unsigned &key, const student &s);    //重载生日与关键码判等于(右值为类成员)
    friend bool operator < (const unsigned &key, const student &s);     //重载生日与关键码判小于(右值为类成员)
    friend bool operator > (const student &s1, const student &s2);      //学生之间按年龄比较
    friend bool operator == (const student &s1, const student &s2);     //学生之间按年龄比较
    friend bool operator < (const student &s1, const student &s2);      //学生之间按年龄比较
    friend ostream &operator << (ostream &out, const student &s);       //重载输出流，输出一个学生的所有信息
    friend istream &operator >> (istream &in, student &s);              //重载输入流，输入一个学生的所有信息
};

#endif // STUDENT_H
