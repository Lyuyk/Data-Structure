#include "completebinarytree.h"
#include <math.h>
#include "queue.h"
#include <iostream>
#include <string>
#include <QString>
#include "stack.h"
#include <fstream>


template<class T>
unsigned completeBinaryTree<T>::Height(binTreeNode<T> *current) const
{
    if(current == NULL)return 0;
    unsigned i=Height(current->child[0]);
    unsigned j=Height(current->child[1]);
    return (i<j)?j+1:i+1;
}

template<class T>
void completeBinaryTree<T>::levelOrder(void (*visit)(binTreeNode<T> *))
{
    queue<binTreeNode<T> *> Q;
    binTreeNode<T> *current=root;
    Q.enQueue(current);
    while(!Q.isEmpty())
    {
        Q.deQueue(current);
        visit(current);
        if(current->child[0]!=NULL)Q.enQueue(current->child[0]);
        if(current->child[1]!=NULL)Q.enQueue(current->child[1]);
    }
}

template<class T>
void completeBinaryTree<T>::CreateBinTree(T *stu, unsigned n)
{
    CreateBinTree(stu, root, n);
}

template<class T>
void completeBinaryTree<T>::insert(const T &item)
{
    binTreeNode<T> *parent = Parent(++size);
    binTreeNode<T> *temp = binTreeNode<T>(item);
    if(temp==NULL){QMessageBox::warning(NULL,"错误","内存分配错误");return;}
    if(root==NULL){root=temp;return;}
    parent->child[(size&1)]=temp;
}

template<class T>
bool completeBinaryTree<T>::remove(binTreeNode<T> *current)
{
    if(current==NULL)return false;
    if(size==1){delete root;root=NULL;size=0;return true;}
    binTreeNode<T> *parent=Parent(size);size--;
    binTreeNode<T> *&temp=(parent->child[1]!=NULL)?parent->child[1]:parent->child[0];

    current->data=temp->data;
    delete temp;
    temp=NULL;

    return true;
}

template<class T>
bool completeBinaryTree<T>::save(const char *path) const
{
    ofstream outfile(path,ios::out|ios::binary);
    char version[]="0xA0B0C0";
    if(root==NULL||!outfile)
    {
        outfile.close();
        return false;
    }

    queue<binTreeNode<T> *> Q;
    binTreeNode<T> *current=root;
    outfile.write(version,8);

    Q.enQueue(current);
    while(!Q.isEmpty())
    {
        Q.deQueue(current);outfile.write((char*)&current->data,sizeof(current->data));
        if(current->child[0]!=NULL)Q.enQueue(current->child[0]);
        if(current->child[1]!=NULL)Q.enQueue(current->child[1]);
    }
    outfile.close();
    return true;
}

template<class T>
bool completeBinaryTree<T>::load(const char *path)
{
    ifstream infile(path,ios::in|ios::binary);char version[9];
    if(!infile||(infile.read(version,8),strcmp(version,"0xA0B0C0")!=0))
    {
        infile.close();
        return false;
    }

    destroy(root);
    queue<binTreeNode<T> *>Q;
    T item;

    if(infile.read((char*)&item,sizeof(item)))
    {
        root=new binTreeNode<T>(item);
        size++;
        if(root==NULL)
        {
            QMessageBox::warning(NULL,"错误","存储分配错误");
        }
    }
    else
        return false;

    binTreeNode<T> *temp=root;
    binTreeNode<T> *newNode=NULL;
    Q.enQueue(temp);
    while(infile.read((char*)&item,sizeof(item)))
    {
        if(++size&1)
            Q.deQueue(temp);
        else
            Q.getFront(temp);
        newNode=new binTreeNode<T>(item);
        if(temp==NULL)
        {
            QMessageBox::warning(NULL,"错误","存储分配错误");
            return false;
        }
        Q.enQueue(newNode);
        temp->child[size%2]=newNode;
    }
    infile.close();
    return true;
}

template<class T>
binTreeNode<T> *completeBinaryTree<T>::Parent(binTreeNode<T> *subTree, binTreeNode<T> *current) const
{
    if(subTree == NULL)return NULL;
    if(subTree->child[0]==current||subTree->child[1]==current)return subTree;  //找到，返回父节点subTree
    binTreeNode<T> *p=Parent(subTree->child[0],current);
    return(p!=NULL)?p:Parent(subTree->child[1],current);
}

template<class T>
binTreeNode<T> *completeBinaryTree<T>::Parent(unsigned n) const
{
    if (n == 1) return NULL;
    unsigned level = ceil(log2(n+1))-1,
                 p = n>>1,
             first = 1<<(level-1),
               end = (1<<level)-1,
            middle = (first+end)>>1,
                 i = 1;
    binTreeNode<T> *current=root;
    while(i++ < level)
    {
        current=current->child[p>middle];
        if(p>middle)first=middle;
        else end=middle;
        middle=(first+end)>>1;
    }
    return current;
}

template<class T>
binTreeNode<T> *completeBinaryTree<T>::copy(binTreeNode<T> *originNode)
{
    if(originNode==NULL)return NULL;
    binTreeNode<T> *temp =new binTreeNode<T>(originNode->data);size++;
    if(temp==NULL){QMessageBox::warning(NULL,"错误","存储分配错误");}
    temp->child[0]=copy(originNode->child[0]);
    temp->child[1]=copy(originNode->child[1]);
    return temp;
}

template<class T>
void completeBinaryTree<T>::destroy(binTreeNode<T> *&subTree)
{
    if(subTree == NULL)
    {
        destroy(subTree->child[0]);
        destroy(subTree->child[1]);
        delete subTree;
        size--;
    }
}

template<class T>
void completeBinaryTree<T>::CreateBinTree(T *stu, binTreeNode<T> *&subTree, unsigned n)
{
    destroy(root);
    queue<binTreeNode<T>*> Q;
    size=n;

    subTree=new binTreeNode<T>(stu[0]);
    if(subTree==NULL){QMessageBox::warning(NULL,"错误","存储分配错误");return;}

    binTreeNode<T> *temp=subTree;
    binTreeNode<T> *newNode=NULL;
    unsigned count=1;

    Q.enQueue(temp);
    while(count<size)
    {
        if(++count &1)
            Q.deQueue(temp);
        else
            Q.getFront(temp);
        newNode=new binTreeNode<T>(stu[count-1]);
        if(newNode==NULL){QMessageBox::warning(NULL,"错误","内存分配错误");return;}
        Q.enQueue(newNode);
        temp->child[(count&1)]=newNode;
    }

}

template <class T>
template<typename Y>
binTreeNode<T> *completeBinaryTree<T>::find(binTreeNode<T> *&subTree, const Y &x) const
{
    if(subTree==NULL)return 0;
    if(subTree->data==x)return subTree;
    binTreeNode<T> *temp=find(subTree->child[0],x);
    return temp!=NULL ? temp:find(subTree->child[1],x);
}

template <class T>
template<typename E>
void completeBinaryTree<T>::preOrder(binTreeNode<T> *subTree, E &visit)
{
    if(subTree!=NULL)
    {
        visit(subTree);
        preOrder(subTree->child[0],visit);
        preOrder(subTree->child[1],visit);
    }
}

template <class T>
template<typename E>
void completeBinaryTree<T>::inOrder(binTreeNode<T> *subTree, E &visit)
{
    if(subTree!=NULL)
    {
        inOrder(subTree->child[0],visit);
        visit(subTree);
        inOrder(subTree->child[1],visit);
    }
}

template <class T>
template<typename E>
void completeBinaryTree<T>::postOrder(binTreeNode<T> *subTree, E &visit)
{
    if(subTree!=NULL)
    {
        postOrder(subTree->child[0],visit);
        postOrder(subTree->child[1],visit);
        visit(subTree);
    }
}

template <class T>
template<typename Y>
binTreeNode<T> *completeBinaryTree<T>::find(const Y &x)
{
    return find(root, x);
}
