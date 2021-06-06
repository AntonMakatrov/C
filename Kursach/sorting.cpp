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
    //else j = J, f = K;
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
int* MergeSort::merge(int *m1, int *m2, int l1, int l2)
{
    int* ret = new int[l1+l2];
    int n = 0;
    // Сливаем массивы, пока один не закончится
    while (l1 && l2) {
        if (*m1 < *m2) {
            ret[n] = *m1;
            m1++;
            --l1;
        } else {
            ret[n] = *m2;
            ++m2;
            --l2;
        }
        ++n;
    }
    // Если закончился первый массив
    if (l1 == 0) {
        for (int i = 0; i < l2; ++i) {
            ret[n++] = *m2++;
        }
    } else { // Если закончился второй массив
        for (int i = 0; i < l1; ++i) {
            ret[n++] = *m1++;
        }
    }
    return ret;
}
void MergeSort::step()
{
    if (finished)
        return;

    l = 0;
    if (l<K)
    {
        if(l+n<K)
        {
            ost = (l + n * 2 > K) ? (K - (l + n)) : n;
            mas1 = merge(array + l, array + l + n, n, ost);
            for (uint64_t i = 0; i < n + ost; ++i)
                array[l+i] = mas1[i];
            delete [] mas1;
            l += n * 2;
        }
    }
    n *= 2;

    if(n<K)
        finished = true;
//    if(stepp <= mid)
//    {
//        if ((i < stepp) && (j < K) && (j < (mid + stepp)))
//        { // пока не дошли до конца пути
//            // заполняем следующий элемент формируемой последовательности
//            // меньшим из двух просматриваемых
//            if (array[i] < array[j])
//            {
//                c[k] = array[i];
//                i++; k++;
//            }
//            else
//            {
//                c[k] = array[j];
//                j++; k++;
//            }
//        }
//        else
//        {
//            if (i < stepp)
//            {  // переписываем оставшиеся элементы первого пути (если второй кончился раньше)
//                c[k] = array[i];
//                i++; k++;
//            }
//            else
//            {
//                if ((j < (mid + stepp)) && (j<K))
//                {  // переписываем оставшиеся элементы второго пути (если первый кончился раньше)
//                    c[k] = array[j];
//                    j++; k++;
//                }
//                else
//                {
//                    stepp = stepp + h;
//                }
//            }

//        }// переходим к следующему этапу
//    }
//    if(stepp > mid)
//    {
//        stepp = h;
//        i = 0;   // индекс первого пути
//        j = mid; // индекс второго пути
//        k = 0;

//        h = h * 2;
//        // Переносим упорядоченную последовательность (промежуточный вариант) в исходный массив
//        for (i = 0; i<K; i++)
//            array[i] = c[i];
//    }

//    if(h>=K)
//        finished = true;
}

