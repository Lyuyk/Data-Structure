/*====================================================

  Copyright(C) 2021-2022 Lyuyk
  All rights reserved

  文件名称:linkedlist.cpp
  摘要:链表类源文件
  当前版本号:v1.0
  版本历史信息：无

  created by Lyuyk at 12/29/2021

=====================================================*/
#include "linkedlist.h"
#include <QMessageBox>

template<class T>
linkedList<T>::linkedList(linkedList<T> &L)
{
    linkNode<T> *srcptr=L.getHead()->next;
    linkNode<T> *destptr=first=new linkNode<T>;
    while(srcptr!=NULL)
    {
        linkNode<T> *newNode=new linkNode<T>(srcptr->data);
        if(newNode==NULL){QMessageBox::warning(NULL,"错误","内存分配错误");return;}
        destptr->next=newNode;
        destptr=destptr->next;
        srcptr=srcptr->next;
        length++;
    }
}

template <class T>
void linkedList<T>::makeEmpty()
{
    //将链表置换为空表
    linkNode<T> *del;
    while (first->next != NULL)             //当链不空时，删去链中所有结点
    {
        del = first->next;
        first->next = del->next;            //保存被删结点，从前往后摘下结点
        delete del;                         //删除(仅保留一个表头结点)
    }
    length = 0;
};

template <class T>
linkNode<T> *linkedList<T>::search(T x) const
{
    //在表中搜索含数据x的结点，搜索成功时函数返回该结点的地址；否则返回NULL值
    linkNode<T> *current = first->next;
    while (current != NULL)                         //循链找含x结点
        if (current -> data == x) break;            //找到，跳出循环
        else current = current -> next;             //未找到，继续寻找下一个结点
    return current;
};

template <class T>
linkNode<T> *linkedList<T>::locate(int i) const
{
    //定位函数。返回表中第i个元素的地址。若i<0或i超出表中结点个数，则返回NULL(0为表头结点)
    if (i < 0 || i > this->Length) return NULL;                     //i不合理
    linkNode<T> *current = first; int k = 0;
    while (current != NULL && k++ < i) current = current -> next;   //循链找第i个结点
    return current;                                                 //返回第i个结点地址，若返回NULL，表示i值太大
};

template <class T>
bool linkedList<T>::getData(int i,T &x) const
{
    linkNode<T> *current = locate(i);
    if(current == NULL) return false;
    x = current->data;
}

template <class T>
void linkedList<T>::setData(int i,T &x)
{
    linkNode<T> *nowNode=locate(i);
    if(nowNode==NULL)return;
    nowNode->data=x;
}

template <class T>
bool linkedList<T>::insert(int i,T &x)
{
    linkNode<T> *current=locate(i);
    if(current==NULL)return false;
    linkNode<T> *newNode =new linkNode<T>(x);
    if(newNode==NULL){QMessageBox::warning(NULL,"错误","存储分配失败");return false;}
    newNode->next=current->next;
    current->next=newNode;
    return true;
}

template <class T>
bool linkedList<T>::remove(int i, T &x)
{
    //将链表中第i个元素删去，通过引用型参数x返回该元素的值
    linkNode<T> *current = locate(i - 1);           //寻找删除结点的前一个结点
    if (current == NULL) return false;              //删除不成功
    linkNode<T> *del = current->next;               //重新拉链，将被删结点从链中摘下
    current->next = del->next;
    x = del->data; delete del;                      //取出被删结点中的数据值
    length--; return true;                          //计数减一
}

template <class T>
ostream &operator << (ostream &out, linkedList<T> L)
{
    //单链表的输出函数：将单链表中所有数据按逻辑顺序输出到屏幕上
    linkNode<T> *current = L.first->next;           //跳过空表头
    while (current != NULL)
    {
        cout << current->data << endl;
        current = current->next;
    } return out;
};

template <class T>
linkedList<T> &linkedList<T>::operator = (linkedList<T> &L)
{
    //重载函数：赋值操作，形式如A = B，其中A是调用此操作的List对象，B是与参数表中的引用型参数L结合的实参
    linkNode<T> *srcptr = L.getHead()->next;              //被复制表的附加头结点的下一个结点
    linkNode<T> *destptr = first = new linkNode<T>;
    while (srcptr != NULL)                                //逐个结点复制
    {
        linkNode<T> *newNode = new linkNode<T>(srcptr->data);
        if (newNode == NULL) {QMessageBox::critical(NULL,"错误","内存分配错误(operator= ->linkedList)");}
        destptr->next = newNode;
        destptr = destptr -> link;                       //对赋值对象下一个结点操作
        srcptr = srcptr -> link;                         //跳到源链表的下一个结点
        length++;
    } return *this;                                      //返回操作对象地址
}

template <class T>
void linkedList<T>::inputFront(T endTag)
{
    //endTag 是约定的输入序列结束的标志。如果输入序列是正整数，endTag可以是0或负数
    linkNode<T> *newNode; T val;
    makeEmpty();
    cin >> val;
    while (val != endTag)
    {
        newNode = new linkNode<T>(val);              //创建新结点
        if (newNode == NULL) {QMessageBox::critical(NULL,"错误","内存分配错误(inputFront->linkedList)");return;}
        newNode->next = first->next;
        first -> link = newNode;                    //插入到表前端
        length++;
        cin >> val;
    }
};

template <class T>
void linkedList<T>::inputRear(T endTag)
{
    linkNode<T> *newNode, *last; T val;
    makeEmpty();
    cin >> val; last = first;
    while (val != endTag)               //last指向表尾
    {
        newNode = new linkNode<T>(val);
        if (newNode == NULL) {QMessageBox::critical(NULL,"错误","内存分配错误(inputRear->linkedList)");return;}
        last->next = newNode; last = newNode;             //插入到表末端
        length++;
        cin >> val;
    }
};

