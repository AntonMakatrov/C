#include <stdio.h>
#include <stdint.h>
#include "drawwidget.h"
#include "mainwidget.h"
#include <QWidget>
#define UPDATE_INTERVAL_MS 5
template <class T>
void copy(T target[], T source[], uint64_t source_len)
{
    for (uint64_t i = 0; i < source_len; i++)
        target[i] = source[i];
}

template <class T>
void swaP(T &a, T &b)
{
    T c;
    c = a;
    a = b;
    b = c;
}

template <class T>
void shuffle_array(T array[], uint64_t len)
{
    srand(time(0));
    for (uint64_t i = 0; i < len; i++)
    {
        uint64_t rand_index_1 = static_cast<uint64_t>(rand()) % len;
        uint64_t rand_index_2 = static_cast<uint64_t>(rand()) % len;
        swaP(array[rand_index_1], array[rand_index_2]);
    }
}

template <class T>
void bubble_sort(T array[], uint64_t len)
{
    for (uint64_t i = 0; i < len; i++)
        for (uint64_t j = 0; j < len - 1 - i; j++)
            if (array[j] > array[j+1])
                swaP(array[j], array[j+1]);
}

template <class T>
void insertion_sort(T array[], uint64_t len)
{
    for (uint64_t i = 1; i < len; i++)
        for (uint64_t j = i; j > 0 && array[j-1] > array[j]; j--)
            swaP(array[j-1], array[j]);
}

template <class T>
void selection_sort(T array[], uint64_t len)
{
    for (uint64_t i = 0; i < len - 1; i++)
    {
        uint64_t min = i;
        for (uint64_t j = i+1; j < len; j++)
        {
            if (array[j] < array[min])
                min = j;
        }
        swaP(array[i], array[min]);
    }
}
template <class T>
void shaker_sort(T array[], uint64_t len)
{
    uint64_t left = 0, right = len - 1;
      while ((left < right) )
      {

        for (uint64_t i = left; i<right; i++)  //двигаемся слева направо
        {
          if (array[i]>array[i + 1]) // если следующий элемент меньше текущего,
          {             // меняем их местами
            swaP(array[i],array[i+1]);      // перемещения в этом цикле были
          }
        }
        right--; // сдвигаем правую границу на предыдущий элемент
        for (uint64_t i = right; i>left; i--)  //двигаемся справа налево
        {
          if (array[i - 1]>array[i]) // если предыдущий элемент больше текущего,
          {            // меняем их местами
            swaP(array[i-1],array[i]);
                // перемещения в этом цикле были
          }
        }
        left++;
        // сдвигаем левую границу на следующий элемент
      }
}

template <class T>
void quick_sort(T array[], uint64_t left,uint64_t right)
{
     uint64_t pivot; // разрешающий элемент
       uint64_t l_hold = left; //левая граница
       uint64_t r_hold = right; // правая граница
      pivot = array[left];
      while (left < right) // пока границы не сомкнутся
      {
        while ((array[right] >= pivot) && (left < right))
          right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
        if (left != right) // если границы не сомкнулись
        {
          array[left] = array[right]; // перемещаем элемент [right] на место разрешающего
          left++; // сдвигаем левую границу вправо
        }
        while ((array[left] <= pivot) && (left < right))
          left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
        if (left != right) // если границы не сомкнулись
        {
          array[right] = array[left]; // перемещаем элемент [left] на место [right]
          right--; // сдвигаем правую границу вправо
        }
      }
      array[left] = pivot; // ставим разрешающий элемент на место
      pivot = left;
      left = l_hold;
      right = r_hold;
      if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
        quickSort(array, left, pivot - 1);
      if (right > pivot)
        quickSort(array, pivot + 1, right);
}
// TODO: quicksort и merge sort

