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
void QueueInit(Queue *pq)
{
    assert(pq);
    pq->head = NULL;
    pq->tail = NULL;
    pq->size = 0;
}
void QueuePush(Queue *pq, QDataType x)
{
    assert(pq);
    QNode *newnode = (QNode *)malloc(sizeof(QNode));
    if (newnode == NULL)
    {
        perror("malloc fail");
        exit(-1);
    }
    newnode->data = x;
    newnode->next = NULL;
    if (pq->head == NULL)
    {
        pq->head = pq->tail = newnode;
        newnode->next = NULL;
        pq->size++;
    }
    else
    {
        pq->tail->next = newnode;
        pq->tail = newnode;
        pq->size++;
    }
}
void QueuePop(Queue *pq)
{
    assert(pq);
    if (pq->size == 0)
    {
        exit(-1);
    }
    else
    {
        QNode *next = pq->head->next;
        free(pq->head);
        pq->head = next;
        pq->size--;
    }
    if (pq->size == 0)
    {
        pq->head = pq->tail = NULL;
    }
}
int main()
{
    Queue q;
    QueueInit(&q);
    QueuePush(&q, 1);
    QueuePush(&q, 2);
    QueuePush(&q, 3);
    QueuePush(&q, 4);
    return 0;
}