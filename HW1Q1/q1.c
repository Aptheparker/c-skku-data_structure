//include
#include <stdio.h>
#include <stdlib.h>
//define the max size of queue
#define MAX_QUEUE 100

//define the types: bool, Data, and Queue
typedef enum { false, true } bool;
typedef int Data;
typedef struct {
    int front, rear;
Data items[MAX_QUEUE]; } Queue;

// Make a queue empty.
void InitQueue(Queue *pqueue);
// Check whether a queue is full. 
bool IsFull(Queue *pqueue);
// Check whether a queue is empty. 
bool IsEmpty(Queue *pqueue);
// Read the item at the front.
Data Peek(Queue *pqueue);
// Insert an item at the rear.
void EnQueue(Queue *pqueue, Data item);
// Delete an item at the front.
void DeQueue(Queue *pqueue);
//Median Calculator
void CalculateMedian(int list[], int len);

//main func
int main(){
  int N;
  int O;
  Queue queue;

  InitQueue(&queue);

  scanf("%d", &N);
  for(int i=0; i<N; i++){
      int cmd;
      scanf("%d", &cmd);
      EnQueue(&queue, cmd);
  }
}




// Make a queue empty.
void InitQueue(Queue *pqueue)
{
    pqueue->front = pqueue->rear = 0; 
}
// Check whether a queue is full.
bool IsFull(Queue *pqueue)
{
    return pqueue->front
        == (pqueue->rear + 1) % MAX_QUEUE;
}
// Check whether a queue is empty.
bool IsEmpty(Queue *pqueue)
{
    return pqueue->front == pqueue->rear;
}
// Read the item at the front.
Data Peek(Queue *pqueue)
{
    if (IsEmpty(pqueue))
        exit(1); //error: empty stack
    return pqueue->items[pqueue->front];
}
// Insert an item at the rear.
void EnQueue(Queue *pqueue, Data item)
{
    if (IsFull(pqueue))
        exit(1); //error: stack full
    pqueue->items[pqueue->rear] = item;
    pqueue->rear = (pqueue->rear + 1) % MAX_QUEUE;
}
// Delete an item at the front.
void DeQueue(Queue *pqueue) {
    if (IsEmpty(pqueue))
        exit(1); //error: empty stack
    pqueue->front = (pqueue->front + 1) % MAX_QUEUE;
}
//Median Calculator
void CalculateMedian(int list[], int len){
  int median;

  // if (n % 2 == 0)
  //   median = (list[n/2] + list[n/2+1])/2.0 ;
  // else
  //   median = list[n/2 + 1];
}