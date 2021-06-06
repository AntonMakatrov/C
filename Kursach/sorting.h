#ifndef SORTING_H
#define SORTING_H

#include <QObject>

class Sorting
{
public:

    Sorting(int *array, uint64_t len);
    Sorting(int *array, uint64_t left, uint64_t right);
    virtual ~Sorting();
    void init(int *array, uint64_t len);
  //  void init2(int *c,uint64_t len);
    bool sorted();
    virtual void step() = 0;

    virtual void sort() = 0;
protected:
    int *array;
    uint64_t length;
    bool finished;
    uint64_t I, J, K,j,i,f,k,g;
    uint64_t n = 1, l, ost;
    int * mas1;
//    uint64_t mid ; // находим середину сортируемой последовательности
//    uint64_t h ;
//    uint64_t stepp;
};

class BubbleSort : public Sorting
{
public:
    BubbleSort(int *array, uint64_t len);
    ~BubbleSort();
    void step();

    void sort();
};

class ShakerSort : public Sorting
{
public:
    ShakerSort(int *array, uint64_t len);
    ~ShakerSort();
    void step();
    void sort();
};

class MergeSort : public Sorting
{
public:
    MergeSort(int *array, uint64_t len);
    ~MergeSort();
    void step();
    int* merge(int *m1, int*m2, int l1, int l2);
    void sort();
};

class InsertionSort : public Sorting
{
public:
    InsertionSort(int *array, uint64_t len);
    ~InsertionSort();
    void step();

    void sort();
};

class SelectionSort : public Sorting
{
public:
    SelectionSort(int *array, uint64_t len);
    ~SelectionSort();
    void step();

    void sort();
private:
    uint64_t min;
};

#endif // SORTING_H
