#ifndef QUEUE_H
#define QUEUE_H
#include "linkedlist.h"
#include <QMessageBox>

template<class T>
class queue
{
public:
    queue():rear(NULL){};
    ~queue(){makeEmpty();}
    bool enQueue(const T &x);
    bool deQueue(T &x);
    bool getFront(T &x) const;
    int getSize() const;
    void makeEmpty();
    bool isEmpty() const {return rear==NULL? true:false;}

protected:
    linkNode<T> *rear;
};

template <class T>
void queue<T>::makeEmpty()
{
    if(rear==NULL)return;
    linkNode<T> *del=NULL;
    while(rear->next!=rear)
    {
        del=rear->next;
        rear->next=del->next;
        delete del;
    }
    delete rear;
}

template<class T>
bool queue<T>::enQueue(const T &x)
{
    if (rear == NULL)
    {
        rear = new linkNode<T>(x);          //空队列时，新结点成为队列的第一个结点，既是队头也是队尾
        if (rear == NULL) { QMessageBox::critical(NULL, "错误", "存储分配错误！"); return false;}
        rear->next = rear;                  //将链表头尾相连
    }
    else
    {
        linkNode<T> *newNode = new linkNode<T>(x);      //非空队列时，在链尾追加新的结点，并更新队尾指针
        if (newNode == NULL) {QMessageBox::critical(NULL, "错误", "存储分配错误！"); return false;}
        newNode->next = rear->next;                     //新结点的link为队头
        rear->next = newNode;                           //将新结点链上队尾
        rear = newNode;                                 //将rear指向新结点
    } return true;
}

//若队列不为空，将队头结点从链表中删去，函数返回true，否则返回fasle
template <class T>
bool queue<T>::deQueue(T &x)
{
    if (isEmpty()) return false;                        //队空
    linkNode<T> *top = rear->next; x = top->data;
    rear->next = top->next;
    if (top == rear) rear = NULL;                       //队列只剩下一个元素，删除该结点后，rear指针置空
    delete top; return true;                            //队头修改，释放原队头结点
}

//若队列不为空，则函数返回队头元素的值及true；若为空，返回false
template <class T>
bool queue<T>::getFront(T &x) const
{
    if (isEmpty()) return false;                        //队空
    x = rear->next->data; return true;                  //取出队头元素中的数据值
}

//求队列中元素个数
template <class T>
int queue<T>::getSize() const
{
    linkNode<T> *p = rear->next; int k = 0;
    while (p->next != rear->next) {p = p->next; k++;} return k;
}


#endif // QUEUE_H
