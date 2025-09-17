#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int QDataType;
typedef struct QueueNode
{
    struct QueueNode *next;
    QDataType data;
} QNode;
typedef struct Queue
{
    QNode *head;
    QNode *tail;
    int size;
} Queue;
void QueuePush(Queue *pq, QDataType x);
void QueueInit(Queue *pq);
void QueuePop(Queue *pq);