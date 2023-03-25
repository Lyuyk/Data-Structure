/*====================================================

  Copyright(C) 2021-2022 Lyuyk
  All rights reserved

  文件名称:node.cpp
  摘要:节点结构（储存学生信息的）源文件
  当前版本号:v1.0
  版本历史信息：无

  created by Lyuyk at 10/16/2021

=====================================================*/

#include "node.h"
#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include <QDebug>

Node::Node()
{

}

bool Node::addStuInfoAtIndex(int index, QString Nm, long long Id, int Ag, QString Gd, QString Ad, QString Br, long long tl, QString BC)
{
    int valuableMaxIndex=stuInfoIndex();//查询最大有效下标
    if(valuableMaxIndex<index&&index<0)//检查下标是否有效
    {
        QMessageBox::warning(0,"错误","给定下标为无效值");
        return false;
    }
    int idx=0;

    Node *nowNode=head;//创建新的虚拟节点指针

    for(;idx<index;idx++)
    {
        nowNode=nowNode->next;
    }

    Node *addNode=new Node;//创建被插入节点
    addNode->stu.setName(Nm);
    addNode->stu.setID(Id);
    addNode->stu.setAge(Ag);
    addNode->stu.setGender(Gd);
    addNode->stu.setAddress(Ad);
    addNode->stu.setBirthday(Br);
    addNode->stu.setTel(tl);
    addNode->stu.setBodyCondition(BC);

    addNode->next=nowNode->next;
    nowNode->next=addNode;//将节点挂入链表中

    QMessageBox::about(0,"提示","节点插入成功");

    //outputStuInfo();

    return true;
}

void Node::inputStuInfo()
{
    QFile file("stuInfo.txt");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    if(!file.isOpen())
    {
        QMessageBox::about(0,"错误","数据文件打开失败");
        return;
    }
    QTextStream infile(&file);

    head=new Node;//创建新头节点
    if(head==0)
    {
        QMessageBox::about(0,"错误","动态内存分配失败！");
        return;
    }
    Node* tail=head;//创建一个指针复制头部
    tail->next=0;//头部指针域初始化为空

    QString name;//姓名
    long long ID;// 学号
    int age;// 年龄
    QString gender;// 性别
    QString address;// 地址
    QString birthday;// 生日
    long long tel;// 联系方式
    QString BodyCondition;// 健康状况

    while(!infile.atEnd())
    {
      Node* newNode=new Node;//创建一个新的被插入节点
      if(newNode==0)
      {
          QMessageBox::about(0,"错误","动态内存分配失败");
          return;
      }
      infile>>name>>ID>>age>>gender>>tel>>birthday>>address>>BodyCondition;
      newNode->stu.setName(name);//设置学生姓名
      newNode->stu.setID(ID);//设置学生学号
      newNode->stu.setAge(age);//设置学生年龄
      newNode->stu.setGender(gender);//设置学生性别
      newNode->stu.setTel(tel);//设置学生电话
      newNode->stu.setBirthday(birthday);//设置学生生日
      newNode->stu.setAddress(address);//设置学生地址
      newNode->stu.setBodyCondition(BodyCondition);//设置学生健康状况

      tail->next=newNode;//将待插入节点挂入被插入位置处
      tail=newNode;//将被挂入处位置向后移一位
      tail->next=0;//将被挂入处next指针域初始化为空
    }
    file.close();//关闭文件
}

void Node::deleteStuInfo(long long ID)
{
    Node *point,*before,*bp;
    point=head->next;
    if(ID==point->stu.getID())
    {
        head->next=head->next->next;
        delete [] head->next->next;//删除节点
        QMessageBox::about(0,"提示","已成功删除学生信息");
    }
    else
    {
        before = bp = point;
        while(ID!=bp->stu.getID()&&bp->next!=0)
        {
            before=bp;
            bp=bp->next;
        }
        if(ID==bp->stu.getID())
        {
            before->next=bp->next;
            delete [] bp;
            QMessageBox::about(0,"提示","已成功删除该学生信息");//学生成功删除后的提示
        }
        else
        {
            QMessageBox::about(0,"错误","该学生信息不存在");//学生不存在时的提示
        }
    }
}

void Node::outputStuInfo()
{
    QFile file("stuInfo.txt");
    file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate);
    if(!file.isOpen())//文件是否打开成功
    {
        QMessageBox::about(0,"错误","数据文件打开失败");
        return;
    }

    QTextStream out(&file);
    Node* nowNode=head->next;
    for(;nowNode->next;nowNode=nowNode->next)
    {
        if(nowNode->stu.getName()=="")break;
        out<<nowNode->stu.getName()<<" "<<
             nowNode->stu.getID()<<" "<<
             nowNode->stu.getAge()<<" "<<
             nowNode->stu.getGender()<<" "<<
             nowNode->stu.getTel()<<" "<<
             nowNode->stu.getBirthday()<<" "<<
             nowNode->stu.getAddress()<<" "<<
             nowNode->stu.getBodyCondition()<<"\n";
    }
    file.close();
}

void Node::sortStuInfoByID()
{
    qDebug()<<"startSorting(sortStuInfoByID)\n";

    if(head==0||head->next==0)//如果头节点next为空或者头节点为空则返回
    {
        qDebug()<<"pNowNode==0||pNowNode->next==0\n";
        return;
    }

    Node *pNowNode=new Node;
    pNowNode->next=head;//复制头结点的next域（通过前面判断的都是非空表）
    Node *sortedTail=pNowNode;//指向排好序的链表的末尾

    while(sortedTail->next!=0)
    {
        Node *minNode=sortedTail->next;
        Node *p=sortedTail->next->next;

        qDebug()<<"sortedTail->next!=NULL\n";

        while(p!=0)
        {
            //qDebug()<<"p!=NULL";
            //qDebug()<<p->stu.getID()<<"\n";
            if(p->stu.getID() < minNode->stu.getID())
            {
                minNode=p;
                qDebug()<<p->stu.getID()<<" "<<minNode->stu.getID();
            }
            p=p->next;

        }
        //swap(minNode->val,sortedTail->next->val);
        {QString temp;
        temp=minNode->stu.getAddress();//交换地址
        minNode->stu.setAddress(sortedTail->next->stu.getAddress());
        sortedTail->stu.setAddress(temp);//qDebug()<<temp<<"\n";

        temp=minNode->stu.getBirthday();//交换生日
        minNode->stu.setBirthday(sortedTail->next->stu.getBirthday());
        sortedTail->stu.setBirthday(temp);//qDebug()<<temp<<"\n";

        temp=minNode->stu.getBodyCondition();//交换健康状况
        minNode->stu.setBodyCondition(sortedTail->next->stu.getBodyCondition());
        sortedTail->stu.setBodyCondition(temp);//qDebug()<<temp<<"\n";

        temp=minNode->stu.getGender();//交换性别
        minNode->stu.setGender(sortedTail->next->stu.getGender());
        sortedTail->stu.setGender(temp);//qDebug()<<temp<<"\n";

        temp=minNode->stu.getName();//交换名字
        minNode->stu.setName(sortedTail->next->stu.getName());
        sortedTail->stu.setName(temp);//qDebug()<<temp<<"\n";

        int tempAge;
        tempAge=minNode->stu.getAge();//交换年龄
        minNode->stu.setAge(sortedTail->next->stu.getAge());
        sortedTail->stu.setAge(tempAge);//qDebug()<<tempAge<<"\n";

        long long tempNumber;
        tempNumber=minNode->stu.getID();//交换学号
        minNode->stu.setID(sortedTail->next->stu.getID());
        sortedTail->stu.setID(tempNumber);//qDebug()<<tempNumber<<"\n";

        tempNumber=minNode->stu.getTel();//交换电话
        minNode->stu.setTel(sortedTail->next->stu.getTel());
        sortedTail->stu.setTel(tempNumber);//qDebug()<<tempNumber<<"\n";

        sortedTail=sortedTail->next;}
    }

    head=pNowNode->next;
    delete pNowNode;

    Node *pNew=new Node;
    pNew=head;
    for(;pNew->next!=0;pNew=pNew->next)
    {
        qDebug()<<"ID:"<<pNew->stu.getID()<<"\n";
    }

}

void Node::modifyStuInfo(QString Nm, long long Id, int Ag, QString Gd, QString Ad, QString Br, long long tl, QString BC)
{
    Node *nowNode=head->next;
    bool flag=false;
    for(;nowNode;nowNode=nowNode->next)
    {
        if(Id==nowNode->stu.getID())
        {
            flag=true;
            break;
        }
    }
    if(flag==false)
    {
        QMessageBox::about(0,"提示","该学生不存在");
        return;
    }
    nowNode->stu.setName(Nm);//设置学生姓名
    nowNode->stu.setID(Id);//设置学生学号
    nowNode->stu.setAge(Ag);//设置学生年龄
    nowNode->stu.setGender(Gd);//设置学生性别
    nowNode->stu.setTel(tl);//设置学生电话
    nowNode->stu.setBirthday(Br);//设置学生生日
    nowNode->stu.setAddress(Ad);//设置学生地址
    nowNode->stu.setBodyCondition(BC);//设置学生健康状况
    QMessageBox::about(0,"提示","已经成功修改学生信息");
}

bool Node::searchStuInfo(QString &Nm, long long Id, int &Ag, QString &Gd, QString &Ad, QString &Br, long long &tl, QString &BC)
{
    Node *p=head->next;
    bool flag=false;

    for(;p;p=p->next)
    {
        if(Id==p->stu.getID())
        {
            flag=true;
            Nm=p->stu.getName();
            Id=p->stu.getID();
            Ag=p->stu.getAge();
            Gd=p->stu.getGender();
            Ad=p->stu.getAddress();
            tl=p->stu.getTel();
            Br=p->stu.getBirthday();
            BC=p->stu.getBodyCondition();
            break;
        }
    }
    if(flag==false)
    {
        return false;
    }
    else
        return true;
}

int Node::stuInfoIndex()
{
    if(head->next==0)//若为空表，则返回0
        return 0;

    Node *p=head->next;
    int index=0;

    for(;p->next;p=p->next)
    {
        index++;
    }
    qDebug()<<"stuInfoIndex:"<<index<<Qt::endl;
    return index;
}




