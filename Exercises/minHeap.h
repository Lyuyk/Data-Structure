#pragma once
#define DefaultSize 10;
using namespace std;

const int DEFAULT_SIZE = 130;

template <class T>
class Heap
{

public:

    Heap(int sz = DEFAULT_SIZE);//ȱʡ���캯��

    Heap(T arr[], int n);//������������С��

    ~Heap() { delete[]heap; }//��������

    bool Insert(T& x);//��С�Ѳ����㷨

    bool Remove(T& x);//��С��ɾ���㷨

    bool IsEmpty()const//�ж϶��Ƿ�Ϊ��
    {
        return currentSize == 0;
    }

    bool IsFull()const//�ж϶��Ƿ�����
    {
        return currentSize == maxHeapSize;
    }

    void MakeEmpty()//��ն�
    {
        currentSize = 0;
    }
private:
    T* heap;
    int currentSize;
    int maxHeapSize;
    void siftDown(int start, int m);//��С�����µ����㷨
    void siftUp(int start);//��С�����ϵ����㷨
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
    //�����鸳ֵ
    for (int i = 0; i < n; i++)
    {
        heap[i] = arr[i];
    }
    //��������е�����ʹ֮��Ϊ��С��
    currentSize = n;
    int currentPos = (currentSize - 2) / 2;//����Ҷ�ӽ��
    while (currentPos >= 0)
    {
        //��currentPos������currentSize
        siftDown(currentPos, currentSize - 1);
        currentPos--;
    }
}

template <class T>
bool Heap<T>::Insert(T& x)
{
    if (currentSize == maxHeapSize)
    {
        cout << "������" << endl;
        return false;
    }
    //δ��
    heap[currentSize] = x;
    siftUp(currentSize);
    currentSize++;
    return true;
}

//�������ܣ���С��ɾ���㷨��ɾ���Ѷ�Ԫ��
//�������������Ѷ�Ԫ�ظ�ֵ��x
//����ֵ���߼�ֵtrue��false
template <class T>
bool Heap<T>::Remove(T& x)
{
    //����Ϊ��
    if (!currentSize)
    {
        cout << "��Ϊ��" << endl;
        return false;
    }
    //�Ѳ���
    x = heap[0];					 // ������СԪ��
    heap[0] = heap[currentSize - 1]; //���Ԫ����������
    currentSize--;                   //��ǰԪ������1
    siftDown(0, currentSize - 1); //�������µ���Ϊ��
    return true;
}

//�������ܣ���С�����µ����㷨
//�������������λ��start���յ�λ��m
//����ֵ����
template<class T>
void Heap<T>::siftDown(int start, int m)
{
    int i = start, j = 2 * i + 1;
    T temp = heap[i];
    while (j <= m)
    {
        //����ŮѡС��
        if (j<m && heap[j]>heap[j + 1])
            j++;
        if (temp <= heap[j])break;
        else
        {
            heap[i] = heap[j];
            i = j;
            j = 2 * j + 1;//������
        }
    }
    heap[i] = temp;
}

//�������ܣ���С�����ϵ����㷨
//�������������λ��start
//����ֵ����
template<class T>
void Heap<T>::siftUp(int start)
{
    //��start��ʼ���ϵ�����0
    int j = start, i = (j - 1) / 2;//i��j��˫��
    T temp = heap[j];
    while (j > 0)
    {
        if (heap[i] <= temp)break;
        else
        {
            heap[j] = heap[i];
            j = i;
            i = (i - 1) / 2;//������
        }
    }
    heap[j] = temp;
}


