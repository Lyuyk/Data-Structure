/*====================================================

  Copyright(C) 2021-2022 Lyuyk
  All rights reserved
  文件名称:stack.cpp
  摘要:栈类源文件
  当前版本号:v1.0
  版本历史信息：无

  created by Lyuyk at 12/29/2021

=====================================================*/
#include "stack.h"

template<class T>
stack<T>::stack()
{

}

template<class T>
seqStack<T>::seqStack(int size):top(-1),maxSize(size)
{
    elements=new T[maxSize];
    assert(elements!=NULL);
}

template<class T>
void seqStack<T>::push(const T &x)
{
    if(isFull()==true)overflowProcess();
    elements[++top]=x;
}

template <class T>
bool seqStack<T>::pop(T &x)
{
    if (isEmpty() == true) return false;
    x = elements[top--];
    return true;
}

template<class T>
void seqStack<T>::overflowProcess()
{
    T *newArray=new T[2*maxSize];
    if(newArray==NULL){QMessageBox::warning(NULL,"错误","存储分配失败");return;}
    for(int i=0;i<=top;i++)newArray[i]=elements[i];
    maxSize=2*maxSize;
    delete[] elements;
    elements=newArray;
}

