/*====================================================

  Copyright(C) 2021-2022 Lyuyk
  All rights reserved

  文件名称:stuinfo.cpp
  摘要:学生信息类源文件
  当前版本号:v1.0
  版本历史信息：无

  created by Lyuyk at 10/16/2021

=====================================================*/

#include "stuinfo.h"

stuInfo::stuInfo(QString Nm, long long Id, int Ag, QString Gd, QString Ad, QString Br, long long tl, QString BC)
{
    name=Nm;
    ID=Id;
    age=Ag;
    gender=Gd;
    address=Ad;
    tel=tl;
    birthday=Br;
    BodyCondition=BC;
}

QString stuInfo::getName()
{
    return name;
}

long long stuInfo::getID()
{
    return ID;
}

int stuInfo::getAge()
{
    return age;
}

QString stuInfo::getGender()
{
    return gender;
}

QString stuInfo::getAddress()
{
    return address;
}

QString stuInfo::getBirthday()
{
    return birthday;
}

long long stuInfo::getTel()
{
    return tel;
}

QString stuInfo::getBodyCondition()
{
    return BodyCondition;
}

void stuInfo::setName(QString Name)
{
    name=Name;
}

void stuInfo::setID(long long Id)
{
    ID=Id;
}

void stuInfo::setAge(int Age)
{
    age=Age;
}

void stuInfo::setGender(QString Gender)
{
    gender=Gender;
}

void stuInfo::setAddress(QString Address)
{
    address=Address;
}

void stuInfo::setTel(long long Tel)
{
    tel=Tel;
}

void stuInfo::setBirthday(QString Birthday)
{
    birthday=Birthday;
}

void stuInfo::setBodyCondition(QString bodyCondition)
{
    BodyCondition=bodyCondition;
}
