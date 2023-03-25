#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <assert.h>
#include <QMessageBox>
using namespace std;


template <class T>
class stack
{
public:
    stack();
    virtual void push(const T &x)=0; //新元素x进栈
    virtual bool pop(T &x)=0; //栈顶元素出栈，由x返回
    virtual bool getTop(T &x)const = 0; //读取栈顶元素，由x返回
    virtual bool isEmpty()const = 0; //判断栈是否为空
    virtual bool isFull()const = 0; //判断栈是否为满
    virtual int getSize()const = 0; //计算栈中元素个数
};

template <class T>
class seqStack: public stack<T>
{
public:
    seqStack(int size=50); //建立一个空栈
    ~seqStack(){delete[] elements;}//析构函数
    virtual void push(const T&x);//如果isFull(),则溢出
    virtual bool pop(T &x);
    virtual bool getTop(T &x)const;
    virtual bool isEmpty() const {return (top==-1)?true:false;}
    virtual bool isFull() const {return (top==maxSize-1)?true:false;}
    virtual int getSize() const {return top+1;}
    void makeEmpty(){top=-1;}

private:
    T *elements;
    int top;
    int maxSize;
    void overflowProcess();
};

#endif // STACK_H
