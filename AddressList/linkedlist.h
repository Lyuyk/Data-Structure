#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<iostream>
using namespace std;


template<class T>
struct linkNode
{
    T data;
    linkNode<T> *next;
    linkNode(linkNode<T> *ptr=NULL){next=ptr;}
    linkNode(const T &item, linkNode<T> *ptr=NULL){data=item;next=ptr;}
};

template <class T>//带表头结点地非循环单链表
class linkedList
{
public:
    linkedList(linkedList<T> *other=new linkNode<T>){first=other;length=0;}
    linkedList(linkedList<T> &L);
    ~linkedList(){makeEmpty();}
    void makeEmpty();
    int Length() const {return length;}
    linkNode<T> *getHead() const {return first;}
    linkNode<T> *search(T x) const;
    linkNode<T> *locate(int i) const;
    bool getData(int i,T &x) const;
    void setData(int i,T &x);
    bool insert(int i,T &x);
    void append(T &x);
    bool remove(int i,T &x);
    bool isEmpty() const {return length==0?true:false;}
    bool isFull() const {return false;}
    void inputFront(T endTag);//头插法建立单链表
    void inputRear(T endTag);
    linkedList<T> &operator=(linkedList<T> &L);
protected:
    linkNode<T> *first;
    int length;
};

#endif // LINKEDLIST_H
