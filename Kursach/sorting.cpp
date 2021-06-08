#include "sorting.h"
#include "sorts.cpp"
#include <tuple>
Sorting::Sorting(int *array, uint64_t len)
{
    init(array, len);
}

Sorting::~Sorting()
{}

bool Sorting::sorted()
{
    return finished;
}

void Sorting::init(int *array, uint64_t len)
{
    this->array = array;
    length = len;
    finished = false;
}

//void Sorting::init2(int *c,uint64_t len)
//{
//    this->c = c;
//    length = len;
//    finished = false;
//}
BubbleSort::BubbleSort(int *array, uint64_t len):
    Sorting(array, len)
{
    I = 0; J = 0;
}

BubbleSort::~BubbleSort()
{}

void BubbleSort::sort()
{
    bubble_sort(array, length);
}

void BubbleSort::step()
{
    if (finished)
        return;
    if (array[J] > array[J+1])
        swaP(array[J], array[J+1]);
    J++;
    if (J >= length - 1 - I)
    {
        J = 0;
        I++;
    }
    if (I >= length)
        finished = true;
}

ShakerSort::ShakerSort(int *array, uint64_t len):
    Sorting(array, len)
{
    I = 0; J = 0; K = len-1;j=0;f=len-1;g=0;
    finished = false;

}

ShakerSort::~ShakerSort()
{}

void ShakerSort::sort()
{
    shaker_sort(array, length);
}

void ShakerSort::step()
{

    if (finished)
        return;
    if(j<f)
    {
        if(array[j]>array[j+1])
            swaP(array[j],array[j+1]);
        j++;
    }

    if(j>=f)
    {
        f--;
        if(array[f-1]>array[f])
            swaP(array[f-1],array[f]);
        if(f<=J)
        {
            K--;
            J++;
            j = J;
            f = K;
        }
    }

    if(J>=K)
    {
        finished = true;
    }

}

InsertionSort::InsertionSort(int *array, uint64_t len):
    Sorting (array, len)
{
    I = 1; J = I;
    finished = false;
}

InsertionSort::~InsertionSort()
{}

void InsertionSort::sort()
{
    insertion_sort(array, length);
}

void InsertionSort::step()
{
    if (finished)
        return;
    if (I < length)
    {
        if (J > 0 && array[J-1] > array[J])
        {
            swaP(array[J], array[J-1]);
            J--;
        }
        else
        {
            I++;
            J = I;
        }
    }
    else
        finished = true;
}

SelectionSort::SelectionSort(int *array, uint64_t len):
    Sorting (array, len)
{
    I = 0;
    J = I + 1;
    min = I;
    finished = false;
}

SelectionSort::~SelectionSort()
{}

void SelectionSort::sort()
{
    selection_sort(array, length);
}

void SelectionSort::step()
{
    if (finished)
        return;
    if (array[J] < array[min])
        min = J;
    J++;
    if (J >= length)
    {
        swaP(array[I], array[min]);
        I++;
        min = I;
        J = I;
    }
    if (I >= length - 1)
        finished = true;
}

MergeSort::MergeSort(int *array, uint64_t len):
    Sorting(array, len)

{
    J =0; j = J; f = K ;K = len;I = (J+K)/2;finished = false;

    curr_size = 1; left_start = 0;
//     mid = 20; // находим середину сортируемой последовательности
//    h = 1;
//    i=0;
//    k=0;
//    j=mid;
//    stepp =h;

}

MergeSort::~MergeSort()
{}

void MergeSort::sort()
{
   //quick_sort(array, left, right);
}
void MergeSort::merge(int *arr,int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }

        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void MergeSort::step()
{
    if (finished)
        return;

    if(left_start<K-1)
    {
        int mid = min(left_start + curr_size - 1, K-1);
        int right_end = min(left_start + 2*curr_size - 1, K-1);
        merge(array, left_start, mid, right_end);
        left_start += 2*curr_size;
    }
    if(left_start>=K-1)
    {
        curr_size = 2*curr_size;
        left_start = 0;
    }
    if(curr_size>K-1)
        finished = true;
}

