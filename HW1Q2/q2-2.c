#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

//check if the mountain is balanced.
bool IsMountBalanced(char* exp, int len, int* total_height);

//
void whatline(char* string, int* line, int len){
  int templine=0;
  for(int i=0;i<len;i++){
    if(string[i]=='/'){
      if(string[i-1]=='/'){
        templine++;
        line[i]=templine;
      }else{
        line[i]=templine;
      }
    }
    else if(string[i]=='\\'){
      if(string[i-1]=='\\'){
        templine--;
        line[i]=templine;
      }
      else{
        line[i]=templine;
      }
    }
  }
}

int main() {
  char str[1000];
  int line[1000]={0};
  int total_height=0;
  scanf("%s",str);
  bool check=IsMountBalanced(str,strlen(str),&total_height);
  whatline(str,line,strlen(str));
  for(int i=total_height-1;i>=0;i--){
    for(int j=0;j<strlen(str);j++){
      if(line[j]==i){
        printf("%c",str[j]);
      }
      else{
        printf(" ");
      }
    }
    printf("\n");
  }
  
  return 0;
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