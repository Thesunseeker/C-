#include <iostream>
#include <stdio.h>

void PrintArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

void Swap(int array[], int i, int j) {
	int t = array[i];
	array[i] = array[j];
	array[j] = t;
}

/*
时间复杂度:
	最好		O(n）			有序
	平均		O(n^2)
	最坏		O(n^2)			逆序
空间复杂度:
	O(1)
稳定性: 稳定
*/
void InsertSort(int array[], int size) {
	// 一次处理一个数，所以需要循环 size 次
	// 严格意义上， size - 1 次就够了
	// 有序 [0, i - 1]
	// 要处理 [i]
	// 无序 [i + 1, size - 1]
	for (int i = 0; i < size; i++) {
		// 遍历整个有序区间 [0, i - 1]
		// 查找合适的位置
		int j;
		for (j = i - 1; j >= 0 && array[j] > array[i]; j--) {}

		// 把 array[i] 插进去
		if (j + 1 != i) {
			// 看作把 array[i] 插入到 [0, i - 1] 的顺序表里
			// 插入的下标是 j
			int key = array[i];
			for (int k = i; k > j + 1; k--) {
				array[k] = array[k - 1];
			}

			array[j + 1] = key;
		}
	}
}

void InsertSort2(int array[], int size) {
	for (int i = 0; i < size; i++) {
		int key = array[i];
		int j;
		for (j = i - 1; j >= 0 && array[j] > key; j--) {
			array[j + 1] = array[j];
		}

		array[j + 1] = key;
	}
}

/*
时间复杂度:
	最好	O(n)
	平均	O(n^1.2-1.3)
	最坏	O(n^2)		减少最坏情况出现的概率
空间复杂度:
	O(1)
稳定性: 不稳定
*/
void InsertSortWithGap(int array[], int size, int gap) {
	for (int i = 0; i < size; i++) {
		int key = array[i];
		int j;
		for (j = i - gap; j >= 0 && array[j] > key; j -= gap) {
			array[j + gap] = array[j];
		}

		array[j + gap] = key;
	}
}


void ShellSort(int array[], int size) {
	int gap = size;
	while (1) {
		gap = gap / 3 + 1;
		// gap = gap / 2;

		InsertSortWithGap(array, size, gap);

		if (gap == 1) {
			break;
		}
	}
}


// 选择排序
// 1. 直接选择
/*
时间复杂度:	数据不敏感		O(n^2)
空间复杂度: O(1)
稳定性: 不稳定
*/
void SelectSort(int array[], int size) {
	for (int i = 0; i < size; i++) {
		// 有序 [size - i, size - 1]
		// 无序 [0, size - 1 - i]
		int maxIdx = 0;
		// 要查找整个无序区间的最大值的下标
		for (int j = 0; j <= size - 1 - i; j++) {
			if (array[j] >= array[maxIdx]) {
				maxIdx = j;
			}
		}
		// maxIdx 记录着无序区间部分最大的数的下标
		// 和无序区间的最后一个位置的数进行交换
		Swap(array, maxIdx, size - 1 - i);
	}
}

// 2. 堆排序
// 时间复杂度 数据不敏感 O(n * log(n))
// 空间复杂度 O(1)
// 稳定性: 不稳定
void Heapify(int array[], int size, int index) {
	/*
	1. 判断是不是叶子
	2. 找到最大的孩子
		1) 没有右孩子
		2) 右孩子
			1) 左孩子大
			2) 右孩子大
	3. 最大的孩子和根比较，如果根比较大，退出
	4. 交换并且继续调整
	*/
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	if (left >= size) { return; }
	int max = left;
	if (right < size && array[right] > array[left]) {
		max = right;
	}
	if (array[index] >= array[max]) {
		return;
	}

	Swap(array, max, index);

	Heapify(array, size, max);
}

void CreateHeap(int array[], int size) {
	// 从最后一个非叶子结点，一直到 0，不断的向下调整
	for (int i = (size - 2) / 2; i >= 0; i--) {
		Heapify(array, size, i);
	}
}
void HeapSort(int array[], int size) {
	// 建大堆
	CreateHeap(array, size);

	// 一次处理一个数
	// 无序 [0, size - 1 - i]
	// 有序 [size - i, size - 1]
	for (int i = 0; i < size; i++) {
		// 交换最大的数和无序区间的最后一个数
		Swap(array, 0, size - 1 - i);
		// 堆的性质被破坏了
		// 只有根的地方
		// 要调整的是剩余无序部分的长度 size - 1 - i
		Heapify(array, size - 1 - i, 0);
	}
}

/*
时间复杂度:
最好: O(n)
平均: O(n^2)
最坏: O(n^2)
空间复杂度: O(1)
稳定性: 稳定
*/
void BubbleSort(int array[], int size) {
	for (int i = 0; i < size; i++) {
		int isSorted = 1;
		// 有序 [size - i, size - 1]
		// 无序 [0, size - 1 - i]
		for (int j = 0; j < size - 1 - i; j++) {
			if (array[j] > array[j + 1]) {
				Swap(array, j, j + 1);
				isSorted = 0;
			}
		}

		if (isSorted == 1) {
			break;
		}
	}
}


#include <stdlib.h>
/*
完全有序
完全逆序
完全随机
完全相等
*/
int * CreateSorted(int size) {
	int *array = (int *)malloc(sizeof(int)* size);
	for (int i = 0; i < size; i++) {
		array[i] = i;
	}

	return array;
}

int * CreateReverse(int size) {
	int *array = (int *)malloc(sizeof(int)* size);
	for (int i = 0; i < size; i++) {
		array[i] = size - i;
	}

	return array;
}

int * CreateRandom(int size) {
	int *array = (int *)malloc(sizeof(int)* size);
	for (int i = 0; i < size; i++) {
		array[i] = rand() % size;
	}

	return array;
}

int * CreateEqual(int size) {
	int *array = (int *)malloc(sizeof(int)* size);
	for (int i = 0; i < size; i++) {
		array[i] = size;
	}

	return array;
}

typedef int *(*CreateFunc)(int);
typedef void(*SortFunc)(int *, int);
#include "高精度计时.h"

void TestSpeed() {
	char * createNames[] = {
		"有序",
		"逆序",
		"随机",
		"相等"
	};
	CreateFunc funcs[] = {
		CreateSorted,
		CreateReverse,
		CreateRandom,
		CreateEqual
	};

	char * sortNames[] = {
		"插入排序",
		"选择排序",
		"冒泡排序",
		"希尔排序",
		"  堆排序"
	};

	SortFunc sortFuncs[] = {
		InsertSort2,
		SelectSort,
		BubbleSort,
		ShellSort,
		HeapSort
	};

	高精度计时	计时器;
	for (int i = 0; i < sizeof(funcs) / sizeof(CreateFunc); i++) {
		char * createName = createNames[i];
		CreateFunc	createFunc = funcs[i];
		for (int j = 0; j < sizeof(sortFuncs) / sizeof(SortFunc); j++) {
			SortFunc sortFunc = sortFuncs[j];
			char * name = sortNames[j];

			for (int k = 1; k < 20; k++) {
				int size = k * 5000;
				int *array = createFunc(size);
				计时器.开始();
				sortFunc(array, size);
				计时器.结束();
				free(array);

				printf("[%s] [%s] 数据量: %02d 千: 耗时: %.4f 毫秒\n", name, createName, size / 1000, 计时器.间隔毫秒());
			}
	
		}
	}
}


void InsertSortBS(int array[], int size) {
	for (int i = 0; i < size; i++) {
		// 有序 [0, i - 1] 有序
		// 无序 [i, size - 1] 无序

		int left = 0;
		int right = i - 1;
		// [left, right] 左闭右闭
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (array[mid] == array[i]) {
				left = mid + 1;
			}
			else if (array[mid] < array[i]) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		// left 是要插入的位置的下标
		int key = array[i];
		for (int k = i; k > left; k--) {
			array[k] = array[k - 1];
		}

		array[left] = key;
	}
}


void SelectSortOP(int array[], int size) {
	int begin = 0;
	int end = size - 1;
	// [0, begin - 1]	有序 最小的数
	// [begin, end]		无序 
	// [end + 1, size - 1] 有序 最大的数
	while (begin <= end) {
		int min = begin;
		int max = begin;
		for (int i = begin; i <= end; i++) {
			if (array[i] > array[max]) {
				max = i;
			}

			if (array[i] < array[min]) {
				min = i;
			}
		}

		// 最小的数放到无序区间的最开始
		// 最大的数放到无序区间的最末尾
		Swap(array, min, begin);
		if (max == begin) {
			max = min;
		}
		Swap(array, max, end);

		begin++;
		end--;
	}
}


/*
快速排序
每一层的 Partition
	时间复杂度是 O(n)
	空间复杂度是 O(1)
数多少个 O(n)，二叉树高度个 O(n)
空间消耗在于递归调用的栈帧消耗，最终消耗的情况是二叉树的高度
	二叉树的高度是 log(n) - n 在变化
					最好						平均					最坏
时间复杂度		O(n * log(n))				O(n * log(n))			O(n^2)
空间复杂度		O(log(n))					O(log(n))				O(n)

稳定性: 不稳定
*/

// Hover
int Partition_1(int array[], int left, int right) {
	int begin = left;	// [left, begin] 保证 <= pivot
	int end = right;	// [end, right] 保证 >= pivot
	int pivot = array[right];	// 基准值

	while (begin < end) {
		while (begin < end && array[begin] <= pivot) {
			begin++;
		}

		// array[begin] > pivot	一定

		while (begin < end && array[end] >= pivot) {
			end--;
		}

		// array[end] < pivot 一定
		Swap(array, begin, end);
	}

	// 把 基准值 和 begin 所在的下标交换，和第一个比 pivot 大的数交换
	Swap(array, begin, right);

	return begin;
}

// 挖坑
int Partition_2(int array[], int left, int right) {
	int begin = left;	// [left, begin] 保证 <= pivot
	int end = right;	// [end, right] 保证 >= pivot
	int pivot = array[right];	// 基准值

	while (begin < end) {
		while (begin < end && array[begin] <= pivot) {
			begin++;
		}
		array[end] = array[begin];

		while (begin < end && array[end] >= pivot) {
			end--;
		}
		array[begin] = array[end];
	}

	array[begin] = pivot;

	return begin;
}

// 前后下标
int Partition_3(int array[], int left, int right) {
	int d = left;
	for (int i = left; i < right; i++) {
		if (array[i] < array[right]) {
			Swap(array, i, d);
			d++;
		}
	}

	Swap(array, d, right);

	return d;
}

// [left, right]
void QuickSortInner(int array[], int left, int right) {
	// 3. 直到 size == 0 || size == 1
	if (left == right) {
		// size == 1
		return;
	}

	if (left > right) {
		// size == 0
		return;
	}

	// 1. 确定基准值，目前选最后边, pivot = array[right] 使基准值
	// 2. 遍历区间，进行切割，直到小的左，大的右，并且返回最终基准值所在的下标
	int d = Partition_3(array, left, right);
	// [left, right] 的区间被分成三部分
	// [left, d - 1] <= pivot
	// [d]				pivot
	// [d + 1, right] >= pivot
	// 3. 分治处理所有两个小区间
	QuickSortInner(array, left, d - 1);
	QuickSortInner(array, d + 1, right);
}

void QuickSort(int array[], int size) {
	QuickSortInner(array, 0, size - 1);
}

#include <stack>

void QuickSortNoR(int array[], int size) {
	// 保存要排序区间的左右边界
	std::stack<int>	stack;
	stack.push(size - 1);		// right;
	stack.push(0);				// left

	while (!stack.empty()) {
		int left = stack.top(); stack.pop();
		int right = stack.top(); stack.pop();

		if (left >= right) {
			continue;
		}

		int d = Partition_1(array, left, right);
		// [d + 1, right]
		stack.push(right);
		stack.push(d + 1);

		// [left, d - 1]
		stack.push(d - 1);
		stack.push(left);
	}
}

/*
归并排序
时间复杂度	O(n * log(n))
空间复杂度	O(n)
稳定
外部排序(海量数据排序，内存放不下)
*/

void Merge(int array[], int low, int mid, int high, int extra[]) {
	// [low, high)

	int i = low;	// [low, mid)
	int j = mid;	// [mid, high)
	int k = low;	// extra[low, high)

	while (i < mid && j < high) {
		if (array[i] <= array[j]) {	// = 保证了稳定性
			extra[k++] = array[i++];
		}
		else {
			extra[k++] = array[j++];
		}
	}

	while (i < mid) {
		extra[k++] = array[i++];
	}

	while (j < high) {
		extra[k++] = array[j++];
	}

	for (int x = low; x < high; x++) {
		array[x] = extra[x];
	}
}

// [low, high)
void MergeSortInner(int array[], int low, int high, int extra[]) {
	// 2. 直到 size == 1 || size == 0
	if (low >= high) {
		// size == 0
		return;
	}

	if (low + 1 == high) {	// [3, 4)
		// size == 1
		return;
	}

	// 1. 平均切割
	int mid = low + (high - low) / 2;
	// 2. 分治处理左右两个小区间
	MergeSortInner(array, low, mid, extra);	// [low, mid)
	MergeSortInner(array, mid, high, extra);	// [mid, high)
	// 3. 合并两个有序数组
	Merge(array, low, mid, high, extra);
}

void MergeSort(int array[], int size) {
	int *extra = (int *)malloc(sizeof(int)* size);
	MergeSortInner(array, 0, size, extra);
	free(extra);
}

void MergeSortNoR(int array[], int size) {
	int *extra = (int *)malloc(sizeof(int)* size);
	// 这一层，左右两个小区间的长度都是 i
	for (int i = 1; i < size; i = i * 2) {
		for (int j = 0; j < size; j = j + 2 * i) {
			// 根据 i 和 j，确定 low, mid, high
			int low = j;
			int mid = low + i;
			if (mid >= size) {
				// 没有右边的小区间，不需要合并
				continue;
			}
			int high = mid + i;
			if (high > size) {
				high = size;
			}

			Merge(array, low, mid, high, extra);
		}
	}

	free(extra);
}

void Test() {
	int array[] = { 9, 4, 3, 7, 2, 5, 8, 8, 7, 1, 3 };
	int size = sizeof(array) / sizeof(int);

	PrintArray(array, size);
	MergeSortNoR(array, size);
	PrintArray(array, size);
}
