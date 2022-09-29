#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

//check if the mountain is balanced.
bool IsMountBalanced(char* exp, int len, int* total_height);
//check the current height of the mountain.
void current_height(char* string, int len, int* height_level);

int main() {
  char mountain[1000]; //input
  int height_level[1000];
  int total_height=0;

  printf("Your input: ");
  scanf("%s",mountain);
  bool check=IsMountBalanced(mountain,strlen(mountain),&total_height);
  current_height(mountain,strlen(mountain), height_level);
  if(check == true){
    for(int i=total_height-1;i>=0;i--){
      for(int j=0;j<strlen(mountain);j++){
        if(height_level[j]==i){
          printf("%c",mountain[j]);
        }
        else{
          printf(" ");
        }
      }
    printf("\n");
    }
  }
  else{
    printf("Not a mountain.");
  }
}

//the function to check if the mountain is balanced.
bool IsMountBalanced(char* exp, int len, int* total_height){
  Stack stack;
  int current_height=0;

  InitStack(&stack);
  for(int i=0;i<len;i++){
    if(exp[i]=='/'){
      Push(&stack,exp[i]);
      current_height++;
      if(*total_height<current_height){
        *total_height=current_height;
      }
    }
    else if(exp[i]=='\\'){
      if(IsEmpty(&stack)){
        return false;
      }
      else{
        Pop(&stack);
        current_height--;
      }
    }
  }
  if(IsEmpty(&stack)){
    return true;
  }
  else{
    return false;
  }
}

void current_height(char* mountain, int len, int* height_level){
  int temp=0;

  for(int i=0;i<len;i++){
    if(mountain[i]=='/'){
      if(mountain[i-1]=='/'){ //if the previous one was the same. 
        temp++;
        height_level[i]=temp;
      }else{
        height_level[i]=temp;
      }
    }
    else if(mountain[i]=='\\'){
      if(mountain[i-1]=='\\'){ //if the previous one was the same.
        temp--;
        height_level[i]=temp;
      }
      else{
        height_level[i]=temp;
      }
    }
  }
}