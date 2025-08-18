#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;

typedef struct SeqList
{

    SLDataType *arr;
    int size;
    int capacity;
} SL;

void SLCheckCapacity(SL *ps);
void SlInit(SL *ps);
void SLPushBack(SL *ps, SLDataType x);
void SLPrint(SL s);
void SLPushFront(SL *ps, SLDataType x);
void SLCheckCapacity(SL *ps)
{
    if (ps->size == ps->capacity)
    {
        int new_capacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
        SLDataType *temp = (SLDataType *)realloc(ps->arr, new_capacity * sizeof(SLDataType));
        if (temp == NULL)
        {
            perror("wrong realloc\n");
            exit(1);
        }
        else
        {
            ps->arr = temp;
            ps->capacity = new_capacity;
        }
    }
}
void SlInit(SL *ps)
{
    ps->arr = NULL;
    ps->size = 0;
    ps->capacity = 0;
}

void SLPushBack(SL *ps, SLDataType x)
{
    SLCheckCapacity(ps);
    ps->arr[ps->size] = x;
    ps->size++;
}
void SLPrint(SL s)
{
    for (int i = 0; i < s.size; i++)
    {
        printf("%d ", s.arr[i]);
    }
    printf("\n");
}
void SLPushFront(SL *ps, SLDataType x)
{
    int i = 0;
    SLCheckCapacity(ps);
    assert(ps);
    for (i = ps->size; i > 0; i--)
    {
        ps->arr[i] = ps->arr[i - 1];
    }
    ps->arr[0] = x;
    ps->size++;
}
SL sl;
void test_1()
{
    SL sl;
    SlInit(&sl);
    SLPushBack(&sl, 1);
    SLPushBack(&sl, 2);
    SLPrint(sl);
}
void test_2()
{

    SLPushFront(&sl, 0);
    SLPushFront(&sl, 20);
    SLPushFront(&sl, 30);
    SLPrint(sl);
}
int main()
{
    test_1();
    test_2();
    return 0;
}