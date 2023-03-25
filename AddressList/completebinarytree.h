#ifndef COMPLETEBINARYTREE_H
#define COMPLETEBINARYTREE_H
#include <math.h>
#include <iostream>
#include <fstream>
#include <QTextStream>
#include "queue.h"
#include "stack.h"
#include <string>
#include <QString>
using namespace std;

template <class T>
struct binTreeNode//二叉树的链表
{
    T data;//数据域
    binTreeNode<T> *child[2];//左子女，右子女
    binTreeNode() {child[0]=NULL;child[1]=NULL;}
    binTreeNode(const T &x, binTreeNode<T> *l=NULL, binTreeNode *r=NULL)
    {
        data=x;child[0]=l;child[1]=r;
    }
};

template <class T>
class completeBinaryTree
{
    protected:
        const unsigned DATA_SIZE = sizeof(T);                                                   //数据域的大小
        binTreeNode<T> *root;                                                                   //二叉树的根指针
        unsigned size;                                                                          //二叉树的结点数
        binTreeNode<T> *Parent(binTreeNode<T> *subTree, binTreeNode<T> *current) const;         //返回父节点
        binTreeNode<T> *Parent(unsigned n) const;                                               //寻找完全二叉树编号为n的结点的父结点
        binTreeNode<T> *copy(binTreeNode<T> *orignode);                                         //复制
        template <typename Y>
        binTreeNode<T> *find(binTreeNode<T> *&subTree, const Y &x) const;                       //查找关键码为x的结点，返回该结点
        template <typename Y>
        binTreeNode<T> *findName(binTreeNode<T> *&subTree, const Y &x) const;
        template <typename Y>
        binTreeNode<T> *findNumber(binTreeNode<T> *&subTree, const Y &x) const;
        template <typename Y>
        binTreeNode<T> *findTel(binTreeNode<T> *&subTree, const Y &x) const;
        void destroy(binTreeNode<T> *&subTree);                                                 //删除整棵树
        template<typename E>
        void preOrder(binTreeNode<T> *subTree, E &visit);         //前序遍历
        template<typename E>
        void inOrder(binTreeNode<T> *subTree, E &visit);          //中序遍历
        template<typename E>
        void postOrder(binTreeNode<T> *subTree, E &visit);        //后序遍历
        void CreateBinTree(T *stu, binTreeNode<T> *&subTree, unsigned n);                  //层次遍历非递归建树
    public:
        completeBinaryTree(): root(NULL), size(0){};                      //构造函数
        completeBinaryTree(completeBinaryTree<T> &s) {root = copy(s.root); size = s.Size();}    //拷贝构造函数
        ~completeBinaryTree() {destroy(root);}                                                  //析构函数
        binTreeNode<T> *Parent(binTreeNode<T> *current)                                         //返回父节点
            {return (root == NULL || root == current) ? NULL : Parent(root, current);}
        binTreeNode<T> *LeftChild(binTreeNode<T> *current)                                      //返回左子女
            {return (current != NULL) ? current->child[0] : NULL;}
        binTreeNode<T> *RightChild(binTreeNode<T> *current)                                     //返回右子女
            {return (current != NULL) ? current->child[1] : NULL;}
        binTreeNode<T> *getRoot() const{return root;}                                           //返回根结点
        template <typename Y>
        binTreeNode<T> *find(const Y &x);                                 //寻找关键码为x的结点，函数返回该结点的数据域
        template <typename Y>
        binTreeNode<T> *findName(const Y &x);
        template <typename Y>
        binTreeNode<T> *findNumber(const Y &x);
        template <typename Y>
        binTreeNode<T> *findTel(const Y &x);
        unsigned Height(binTreeNode<T> *current) const;                                         //返回current为根的子树高度
        unsigned Height() const{return ceil(log2(size + 1));};                                  //返回树的高度
        unsigned Size() const {return size;}                                                    //返回结点数
        bool isEmpty() const {return (root == NULL ? true : false);}                            //判断二叉树空否
        template<typename E>
        void preOrder(E &visit) {preOrder(root, visit);}          //前序遍历
        template<typename E>
        void inOrder(E &visit) {inOrder(root, visit);}            //中序遍历
        template<typename E>
        void postOrder(E &visit) {postOrder(root, visit);}        //后序遍历
        void levelOrder(void (*visit)(binTreeNode<T> *current));                                //层次遍历
        void CreateBinTree(T *stu, unsigned n);               //创建完全二叉树,n为创建结点数
        void insert(const T &item);                                                             //将item插入二叉树中
        template <typename Y>
        bool remove(const Y &x){return remove(find(root, x));}                                  //移除值为x的结点
        bool remove(binTreeNode<T> *current);                                                   //移除current结点
        bool save(const char *path) const;                                                      //将二叉树以层次遍历方式存入二进制文件
        bool load(const char *path);                                                            //从二进制文件导入二叉树
};




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
    binTreeNode<T> *temp =new binTreeNode<T>(item);
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


    clock_t startTime, endTime;
    startTime = clock();

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
    endTime = clock(); //计时
    double time=(double) (endTime - startTime) / CLOCKS_PER_SEC;
    QMessageBox::information(NULL,"提示","加载数据时间为"+QString::number(time)+"s");
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
    if(subTree != NULL)
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
template<typename Y>
binTreeNode<T> *completeBinaryTree<T>::findName(binTreeNode<T> *&subTree, const Y &x) const
{
    if(subTree==NULL)return 0;
    if(subTree->data==x)return subTree;
    binTreeNode<T> *temp=findName(subTree->child[0],x);
    return temp!=NULL ? temp:findName(subTree->child[1],x);
}

template <class T>
template<typename Y>
binTreeNode<T> *completeBinaryTree<T>::findNumber(binTreeNode<T> *&subTree, const Y &x) const
{
    if(subTree==NULL)return 0;
    if(subTree->data>=x)return subTree;//>=重载学号与关键码判等于
    binTreeNode<T> *temp=findNumber(subTree->child[0],x);
    return temp!=NULL ? temp:findNumber(subTree->child[1],x);
}

template <class T>
template<typename Y>
binTreeNode<T> *completeBinaryTree<T>::findTel(binTreeNode<T> *&subTree, const Y &x) const
{
    if(subTree==NULL)return 0;
    if(subTree->data<=x)return subTree;//<=重载电话号码与关键码判等于
    binTreeNode<T> *temp=findTel(subTree->child[0],x);
    return temp!=NULL ? temp:findTel(subTree->child[1],x);
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

template <class T>
template<typename Y>
binTreeNode<T> *completeBinaryTree<T>::findName(const Y &x)
{
    return findName(root, x);
}

template <class T>
template<typename Y>
binTreeNode<T> *completeBinaryTree<T>::findNumber(const Y &x)
{
    return findNumber(root, x);
}

template <class T>
template<typename Y>
binTreeNode<T> *completeBinaryTree<T>::findTel(const Y &x)
{
    return findTel(root, x);
}




#endif // COMPLETEBINARYTREE_H
