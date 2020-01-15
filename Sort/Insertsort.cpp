#include <iostream>
#include <string>

using namespace std;

void Swap(int *a, int *b)
{
  int p = *a;
  *a = *b;
  *b = p;
}
//时间复杂度:
//最好: O(n)已经有序  平均 O(n^2) 最差:O(n^2)已经有序,倒序
//空间复杂度:O(1)
void InserSort(int array[] ,int size)
{
  for(int i = 0 ; i < size; i++)
  {
    int key = array[i];
    int j;
    for(j = i - 1 ; j >= 0 && array[j] > key; j--)
    {
      array[j + 1] = array[j];
    }
    
    array[j+1] = key;
  }
}

//希尔(在进行插排之前进行与排序, 让数列尽可能的有序, 也就是分组插排)
//时间复杂度
//最好: O(n) 平均:O(n^1.3) 最差:(O^n)
//稳定性:不稳定, 由于相同的数没办法保证分在一个分组,所以无法保证相同数的次序
void InsertSortWithGap(int array[],int size, int gap)
{
  for(int i = gap; i < size ; i++)
  {
    int key = array[i];
    int j;
    for(j = i - gap; j >= 0 && array[j] > key ; j-=gap)
    {
      array[j + gap] = array[j];
    }
    array[j + gap] = key;
  }
}
void ShellSort(int array[], int size)
{
  int gap = size;
  while(1)
  {
    gap = gap / 3 + 1;
    InsertSortWithGap(array,size,gap);
    if(gap == 1)
      break;
  }
}

void BriSort(int array[] , int size)
{
  //用一个标志变量,让冒泡排序的排序时间减小
  bool flag = false;
  for(int i = 0 ; i < size - 1 ; i++)
  {
    flag = false;
    for (int j = 0 ; j < size - i - 1; j++)
    {
      if(array[j] < array[j+1])
      {
        swap(array[j],array[j+1]);
        flag = true;
      }
    }
    if(flag == false)
    {
      break;
    }
  }
}

//直接选择排序
//时间复杂度: O(n^2)---对数据不明感
//空间复杂度:O(1)
//稳定性: 不稳定:
void SelectSort(int array[], int size)
{
  for(int i = 0; i < size ; i++)
  {
    int m = 0;
    for(int j = 0; j < size - i; j++ )
    {
      if(array[j] > array[m])
      {
        m = j;
      }
    }
    swap(array[m], array[size - i - 1]);
    //Swap(array + m , array + size - i - 1);
  }
}

int main()
{
  int array[] = { 3 , 1, 2, 4, 6, 7, 4, 5};
  int size = sizeof(array)/sizeof(int);
  SelectSort(array,size);
  for(int i = 0; i < size ; i++)
  {
    printf("%d",array[i]);
  }
  printf("\n");
}

