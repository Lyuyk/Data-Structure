#ifndef _HUFFMANNODE_H_
#define _HUFFMANNODE_H_

//定义哈夫曼树结点
#include<iostream>
#include"Heap.h"
#include<fstream>
#include<cstdio>
#include<math.h>

using namespace std;

struct HuffmanNode
{
    char key;//字母
    int times;//出现的次数
    string code;//该字符对应的编码
    HuffmanNode* leftChild, * rightChild;
    HuffmanNode* parent;
    //缺省构造函数
    HuffmanNode() :leftChild(NULL), rightChild(NULL), parent(NULL)
    {
        key = '\0';
        times = 0;
        code = "";
    }
    //参数构造函数
    HuffmanNode(char c,int t=0, HuffmanNode* left = NULL, HuffmanNode* right = NULL,HuffmanNode* par=NULL)
    {
        key = c;
        times = t;
        leftChild = left;
        rightChild = right;
        parent = par;
        code = "";
    }
    //重载<=运算符，排序依据是该符号出现的次数times
    bool operator<=(HuffmanNode& R) { return times <= R.times; }
    //重载>运算符，排序依据是该符号出现的次数times
    bool operator>(HuffmanNode& R) { return times > R.times; }
};


#endif
