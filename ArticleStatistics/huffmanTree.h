#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include<iostream>
#include"Heap.h"
#include<fstream>
#include<cstdio>
#include<math.h>
#include"huffmannode.h"

using namespace std;

class HuffmanTree
{
public:
    HuffmanTree();
    //析构函数，释放HuffmanTree的空间
    ~HuffmanTree()
    {
        deleteTree(root);
        delete[]times;
        delete[]codes;
        delete[]keys;
    }
    unsigned short *times;//数组，存储各字符出现的次数
    int wpl;//总编码长度
    short typeNum;//出现的字符种类数
    string* codes;//字符串数组，用于存储每个字符的编码
    char* keys;//字符数组，存储出现的字符
    HuffmanNode* root;//根结点
    void createTree(char keys[], unsigned short w[], int n);//由已知数组生成HuffmanTree
    void mergeTree(HuffmanNode* bt1, HuffmanNode* bt2, HuffmanNode*& parent);//将两棵树合并成一棵
    void encoding(string fileName);//将文件编码并将所得编码写入文件
    void decode(string fileName);//将fileName文件译码并将保存译码文件
    void save();//将生成的HuffmanTree写入到hfmTree.txt文件
    bool isEmpty() { return root == 0; }  //检测哈夫曼树是否为空
    void setWpl(HuffmanNode* root);   //统计wpl，wpl是所有非叶子结点的权值之和
    void encode(HuffmanNode* root, string s);//功能是对HuffmanTree的每个叶子结点进行编码
    void setCodeArray(HuffmanNode* root);//编写codes[]字符串数组的内容
    void displayHuffman();//存储树
private:
    void displayHuffman(HuffmanNode* root, int ident, ofstream& out);//子函数，辅助打印生成的HuffmanTree
    void deleteTree(HuffmanNode* root);//子函数，后序遍历删除树结点
};



#endif // HUFFMANTREE_H
