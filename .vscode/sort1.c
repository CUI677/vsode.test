#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PrintArray(int *a, int n);

// 有实践意义
void InsertSort(int *a, int n);

void ShellSort(int *a, int n);

void ShellSort(int *a, int n);

void HeapSort(int *a, int n);

// 适合教学，实践中没啥价值
void BubbleSort(int *a, int n);

void SelectSort(int *a, int n);

void PrintArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void Swap(int *p1, int *p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

// 时间复杂度：O(N^2)  什么情况最坏：逆序
// 最好：顺序有序，O(N)
// 插入排序
void InsertSort(int *a, int n)
{
    //  [0, n-1]
    for (int i = 0; i < n - 1; i++)
    {
        // [0, n-2]是最后一组
        // [0,end]有序 end+1位置的值插入[0,end]，保持有序
        int end = i;
        int tmp = a[end + 1];
        while (end >= 0)
        {
            if (tmp < a[end])
            {
                a[end + 1] = a[end];
                --end;
            }
            else
            {
                break;
            }
        }
        a[end + 1] = tmp;
    }
}

// O(N^1.3)
// void ShellSort(int* a, int n)
//{
//	/*int gap = 3;
//	for (int j = 0; j < gap; j++)
//	{
//		for (size_t i = j; i < n - gap; i += gap)
//		{
//			int end = i;
//			int tmp = a[end + gap];
//			while (end >= 0)
//			{
//				if (tmp < a[end])
//				{
//					a[end + gap] = a[end];
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//			a[end + gap] = tmp;
//		}
//	}*/
//
//	int gap = n;
//	while (gap > 1)
//	{
//		// +1保证最后一个gap一定是1
//		// gap > 1时是预排序
//		// gap == 1时是插入排序
//		gap = gap / 3 + 1;
//
//		for (size_t i = 0; i < n - gap; ++i)
//		{
//			int end = i;
//			int tmp = a[end + gap];
//			while (end >= 0)
//			{
//				if (tmp < a[end])
//				{
//					a[end + gap] = a[end];
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//			a[end + gap] = tmp;
//		}
//		//printf("gap:%2d->", gap);
//		//PrintArray(a, n);
//	}
//}

// O(N ^ 1.3)
void ShellSort(int *a, int n)
{
    int gap = n;
    while (gap > 1)
    {
        // +1保证最后一个gap一定是1
        // gap > 1时是预排序
        // gap == 1时是插入排序
        gap = gap / 3 + 1;

        for (size_t i = 0; i < n - gap; ++i)
        {
            int end = i;
            int tmp = a[end + gap];
            while (end >= 0)
            {
                if (tmp < a[end])
                {
                    a[end + gap] = a[end];
                    end -= gap;
                }
                else
                {
                    break;
                }
            }
            a[end + gap] = tmp;
        }
    }
}

void AdjustDown(int *a, int n, int parent)
{
    // 先假设左孩子小
    int child = parent * 2 + 1;

    while (child < n) // child >= n说明孩子不存在，调整到叶子了
    {
        // 找出小的那个孩子
        if (child + 1 < n && a[child + 1] > a[child])
        {
            ++child;
        }

        if (a[child] > a[parent])
        {
            Swap(&a[child], &a[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }
}

void HeapSort(int *a, int n)
{
    // 向下调整建堆 O(N)
    for (int i = (n - 1 - 1) / 2; i >= 0; i--)
    {
        AdjustDown(a, n, i);
    }

    // O(N*logN)
    int end = n - 1;
    while (end > 0)
    {
        Swap(&a[0], &a[end]);
        AdjustDown(a, end, 0);
        --end;
    }
}

// O(N^2) 最坏
// O(N)   最好
void BubbleSort(int *a, int n)
{
    for (int j = 0; j < n; j++)
    {
        // 单趟
        int flag = 0;
        for (int i = 1; i < n - j; i++)
        {
            if (a[i - 1] > a[i])
            {
                Swap(&a[i - 1], &a[i]);
                flag = 1;
            }
        }

        if (flag == 0)
        {
            break;
        }
    }
}

void SelectSort(int *a, int n)
{
    int begin = 0, end = n - 1;

    while (begin < end)
    {
        int mini = begin, maxi = begin;
        for (int i = begin + 1; i <= end; ++i)
        {
            if (a[i] > a[maxi])
            {
                maxi = i;
            }

            if (a[i] < a[mini])
            {
                mini = i;
            }
        }

        Swap(&a[begin], &a[mini]);
        Swap(&a[end], &a[maxi]);
        ++begin;
        --end;
    }
}
void TestInsertSort()
{
    int a[] = {2, 4, 1, 7, 8, 3, 9, 2};
    InsertSort(a, sizeof(a) / sizeof(int));
    PrintArray(a, sizeof(a) / sizeof(int));
}

void TestShellSort()
{
    int a[] = {9, 1, 2, 5, 7, 4, 6, 3, 5, 9, 1, 2, 5, 7, 4, 6, 3, 5, 9, 1, 2, 5, 7, 4, 6, 3, 5, 9, 1, 2, 5, 7, 4, 6, 3, 5, 9, 1, 2, 5, 7, 4, 6, 3, 5};
    // InsertSort(a, sizeof(a) / sizeof(int));

    PrintArray(a, sizeof(a) / sizeof(int));

    ShellSort(a, sizeof(a) / sizeof(int));
    PrintArray(a, sizeof(a) / sizeof(int));
}

void TestSelectSort()
{
    // int a[] = { 9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5,9,1,2,5,7,4,6,3,5 };
    // InsertSort(a, sizeof(a) / sizeof(int));
    // int a[] = { 2,4,1,7,8,3,9,2 };
    int a[] = {9, 1, 2, 5, 7, 4, 6, 3};

    PrintArray(a, sizeof(a) / sizeof(int));
    SelectSort(a, sizeof(a) / sizeof(int));
    PrintArray(a, sizeof(a) / sizeof(int));
}

void TestOP()
{
    srand(time(0));
    const int N = 1000000;
    int *a1 = (int *)malloc(sizeof(int) * N);
    int *a2 = (int *)malloc(sizeof(int) * N);
    int *a3 = (int *)malloc(sizeof(int) * N);
    int *a4 = (int *)malloc(sizeof(int) * N);
    int *a5 = (int *)malloc(sizeof(int) * N);
    int *a6 = (int *)malloc(sizeof(int) * N);
    int *a7 = (int *)malloc(sizeof(int) * N);

    for (int i = 0; i < N; ++i)
    {
        a1[i] = rand() + i;
        a2[i] = a1[i];
        a3[i] = a1[i];
        a4[i] = a1[i];
        a5[i] = a1[i];
        a6[i] = a1[i];
        a7[i] = a1[i];
    }

    int begin1 = clock();
    // InsertSort(a1, N);
    int end1 = clock();

    int begin2 = clock();
    ShellSort(a2, N);
    int end2 = clock();

    int begin3 = clock();
    // SelectSort(a3, N);
    int end3 = clock();

    int begin4 = clock();
    HeapSort(a4, N);
    int end4 = clock();

    int begin5 = clock();
    // QuickSort(a5, 0, N - 1);
    int end5 = clock();

    int begin6 = clock();
    // MergeSort(a6, N);
    int end6 = clock();

    int begin7 = clock();
    // BubbleSort(a7, N);
    int end7 = clock();

    printf("InsertSort:%d\n", end1 - begin1);
    printf("ShellSort:%d\n", end2 - begin2);
    printf("SelectSort:%d\n", end3 - begin3);
    printf("HeapSort:%d\n", end4 - begin4);
    printf("QuickSort:%d\n", end5 - begin5);
    printf("MergeSort:%d\n", end6 - begin6);
    printf("BubbleSort:%d\n", end7 - begin7);

    free(a1);
    free(a2);
    free(a3);
    free(a4);
    free(a5);
    free(a6);
    free(a7);
}

int main()
{
    // TestInsertSort();
    // TestShellSort();
    TestSelectSort();

    // TestOP();

    return 0;
}