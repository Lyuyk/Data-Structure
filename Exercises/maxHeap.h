#pragma once
#define DefaultSize 10;
using namespace std;

const int DEFAULT_SIZE = 130;

template <class T>
class Heap
{
    
public:
    
    Heap(int sz = DEFAULT_SIZE);//缺省构造函数
    
    Heap(T arr[], int n);//由数组生成最小堆
    
    ~Heap() { delete[]heap; }//析构函数
    
    bool Insert(T& x);//最小堆插入算法
    
    bool Remove(T& x);//最小堆删除算法
    
    bool IsEmpty()const//判断堆是否为空
    {
        return currentSize == 0;
    }
    
    bool IsFull()const//判断堆是否已满
    {
        return currentSize == maxHeapSize;
    }
    
    void MakeEmpty()//清空堆
    {
        currentSize = 0;
    }

    void print()
    {
        for (int i = 0; i < currentSize; i++)
        {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
    void heapSort();
public:
    T* heap;
    int currentSize;
    int maxHeapSize;
    void siftDown(int start, int m);//最小堆向下调整算法
    void siftUp(int start);//最小堆向上调整算法
    void Swap(const int i, const int j)
    {
        T tmp = heap[i];
        heap[i] = heap[j];
        heap[j] = tmp;
    }
};


template<class T>
Heap<T>::Heap(int sz)
{
    maxHeapSize = (DEFAULT_SIZE < sz) ? sz : DEFAULT_SIZE;
    heap = new T[maxHeapSize];
    currentSize = 0;
}

template <class T>
Heap<T>::Heap(T arr[], int n)
{
    maxHeapSize = (DEFAULT_SIZE < n) ? n : DEFAULT_SIZE;
    heap = new T[maxHeapSize];
    //对数组赋值
    currentSize=n;
    for (int i = 0; i < n; i++)
    {
        heap[i] = arr[i];
    }
    for (int i = (currentSize - 2) / 2; i >= 0; i--)
        siftDown(i, currentSize - 1);
}

template <class T>
bool Heap<T>::Insert(T& x)
{
    if (currentSize == maxHeapSize)
    {
        cout << "堆已满" << endl;
        return false;
    }
    //未满
    heap[currentSize] = x;
    siftUp(currentSize);
    currentSize++;
    return true;
}

//函数功能：最小堆删除算法，删除堆顶元素
//函数参数：将堆顶元素赋值给x
//返回值：逻辑值true或false
template <class T>
bool Heap<T>::Remove(T& x)
{
    //若堆为空
    if (!currentSize)
    {
        cout << "堆为空" << endl;
        return false;
    }
    //堆不空
    x = heap[0];					 // 返回最小元素
    heap[0] = heap[currentSize - 1]; //最后元素填补到根结点
    currentSize--;                   //当前元素数减1
    siftDown(0, currentSize - 1); //自上向下调整为堆
    return true;
}

//函数功能：最小堆向下调整算法
//函数参数：起点位置start，终点位置m
//返回值：无
template<class T>
void Heap<T>::siftDown(int start, int m)
{
    int i = start, j = 2 * i + 1;
    T temp = heap[i];
    while (j <= m)
    {
        //两子女选小的
        if (j<m && heap[j]>heap[j + 1])
            j++;
        if (temp <= heap[j])break;//大于等于
        else
        {
            heap[i] = heap[j];
            i = j;
            j = 2 * j + 1;//往下走
        }
    }
    heap[i] = temp;
}

//函数功能：最小堆向上调整算法
//函数参数：起点位置start
//返回值：无
template<class T>
void Heap<T>::siftUp(int start)
{
    //从start开始向上调整到0
    int j = start, i = (j - 1) / 2;//i是j的双亲
    T temp = heap[j];
    while (j > 0)
    {
        if (heap[i] <= temp)break;//大于等于
        else
        {
            heap[j] = heap[i];
            j = i;
            i = (i - 1) / 2;//往上走
        }
    }
    heap[j] = temp;
}

template<class T>
void Heap<T>::heapSort()
{
    
    for (int i = currentSize - 1; i >= 0; i--)
    {
        Swap(0, i);//将堆顶元素元素与末尾元素进行交换
        siftDown(0, i - 1);//重新对最小堆进行调整
    }
}
