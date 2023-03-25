#ifndef STUINFO_H
#define STUINFO_H

#include <QString>

class stuInfo
{
public:
    stuInfo(){};
    stuInfo(QString Nm,long long Id,int Ag,QString Gd,QString Ad,QString Br,long long tl,QString BC);//含参构造函数

    QString getName();//获取姓名
    long long getID();//获取学号
    int getAge();//获取年龄
    QString getGender();//获取性别
    QString getAddress();//获取地址
    QString getBirthday();//获取生日
    long long getTel();//获取电话
    QString getBodyCondition();//获取健康状况

    void setName(QString Name);//设置姓名
    void setID(long long ID);//设置学号
    void setAge(int Age);//设置年龄
    void setGender(QString Gender);//设置性别
    void setAddress(QString Address);//设置地址
    void setTel(long long Tel);//设置电话
    void setBirthday(QString Birthday);//设置生日
    void setBodyCondition(QString BodyCondition);//设置健康状况

private:
    QString name;//姓名
    long long ID;// 学号
    int age;// 年龄
    QString gender;// 性别
    QString address;// 地址
    QString birthday;// 生日
    long long tel;// 联系方式
    QString BodyCondition;// 健康状况
};




#endif // STUINFO_H
