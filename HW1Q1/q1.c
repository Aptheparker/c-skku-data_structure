//include
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

//sort the list and give the new list to the main function
void sortList(int *list, int N);

//main func
int main(){
    int N;
    int cmd;
    Queue queue;
    int list[100000]={};
    InitQueue(&queue);
    printf("How many numbers?: ");
    scanf("%d", &N); //get the input for size of the list


    for(int i=0; i<N; i++){
        printf("Input %d: ", i+1);
        scanf("%d", &cmd); //get the input
        list[i] = cmd;
        sortList(list, i);
        EnQueue(&queue,list[i/2]);
        printf("Output %d: %d\n", i+1, Peek(&queue));//give the output
        DeQueue(&queue);
    }
}

//sort the list
void sortList(int *list, int N){
  for(int i=0;i<N;i++){
    for(int j=0;j<N-i;j++){
      if(list[j]>list[j+1]){
        int temp=list[j];
        list[j]=list[j+1];
        list[j+1]=temp;
      }
    }
  }
}