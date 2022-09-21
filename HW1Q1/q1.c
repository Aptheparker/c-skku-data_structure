//include
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
//define the max size of queue

void SortQueue(Queue *pqueue, int N){
    for(int i=0; i<N; i++){
      for(int j=i+1; j<N; j++){
         if(pqueue->items[i]>pqueue->items[j]){
            int temp=pqueue->items[i];
            pqueue->items[i]=pqueue->items[j];
            pqueue->items[j]=temp;
         }
      }
   }
}

//Median Calculator
void CalculateMedian(int items[], int N){
    int median;
    median = items[N/2];
    printf("%d", median);
}

//main func
int main(){
    int N;
    int cmd;
    Queue queue;
    InitQueue(&queue);

    printf("How many numbers?: ");

    scanf("%d", &N);


    for(int i=0; i<N; i++){
        printf("Input %d: ", i+1);
        scanf("%d", &cmd);
        EnQueue(&queue, cmd);
        SortQueue(&queue, i+1);

        for(int j=0; j<i+1; j++){
            printf("%d", queue.items[j]);
        }

        CalculateMedian(queue.items, i+1);
    }
}