#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int HPDataType;

typedef struct Heap
{
    HPDataType *a;
    int size;
    int capacity;
} HP;

void Swap(HPDataType *p1, HPDataType *p2);
void AdjustUp(HPDataType *a, int child);
void AdjustDown(HPDataType *a, int n, int parent);

void HPInit(HP *php);
void HPDestroy(HP *php);
void HPPush(HP *php, HPDataType x);
void HPPop(HP *php);
HPDataType HPTop(HP *php);
bool HPEmpty(HP *php);

void HPInit(HP *php)
{
    assert(php);
    php->a = NULL;
    php->size = php->capacity = 0;
}

void HPDestroy(HP *php)
{
    assert(php);
    free(php->a);
    php->a = NULL;
    php->size = php->capacity = 0;
}

void Swap(HPDataType *p1, HPDataType *p2)
{
    HPDataType tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void AdjustUp(HPDataType *a, int child)
{
    // 初始条件
    // 中间过程
    // 结束条件
    int parent = (child - 1) / 2;
    // while (parent >= 0)
    while (child > 0)
    {
        if (a[child] < a[parent])
        {
            Swap(&a[child], &a[parent]);
            child = parent;
            parent = (child - 1) / 2;
        }
        else
        {
            break;
        }
    }
}

void HPPush(HP *php, HPDataType x)
{
    assert(php);

    if (php->size == php->capacity)
    {
        int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
        HPDataType *tmp = (HPDataType *)realloc(php->a, newcapacity * sizeof(HPDataType));
        if (tmp == NULL)
        {
            perror("realloc fail");
            return;
        }

        php->a = tmp;
        php->capacity = newcapacity;
    }

    php->a[php->size] = x;
    php->size++;

    AdjustUp(php->a, php->size - 1);
}

void AdjustDown(HPDataType *a, int n, int parent)
{
    // 先假设左孩子小
    int child = parent * 2 + 1;

    while (child < n) // child >= n说明孩子不存在，调整到叶子了
    {
        // 找出小的那个孩子
        if (child + 1 < n && a[child + 1] < a[child])
        {
            ++child;
        }

        if (a[child] < a[parent])
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

// logN
void HPPop(HP *php)
{
    assert(php);
    assert(php->size > 0);
    Swap(&php->a[0], &php->a[php->size - 1]);
    php->size--;

    AdjustDown(php->a, php->size, 0);
}

HPDataType HPTop(HP *php)
{
    assert(php);
    assert(php->size > 0);

    return php->a[0];
}

bool HPEmpty(HP *php)
{
    assert(php);

    return php->size == 0;
}
int main()
{
    HP hp;
    HPInit(&hp);
    HPPush(&hp, 3);
    HPPush(&hp, 5);
    HPPush(&hp, 2);
    HPPush(&hp, 7);
    HPPush(&hp, 1);
    HPPush(&hp, 4);

    while (!HPEmpty(&hp))
    {
        printf("%d ", HPTop(&hp));
        HPPop(&hp);
    }
    printf("\n");

    HPDestroy(&hp);
    return 0;
}