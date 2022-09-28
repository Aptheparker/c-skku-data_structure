#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

//check if the mountain is balanced.
bool IsMountBalanced(char* exp, int len, int* total_height);

//main function
int main() {
  char str[1000];
  int total_height=0;
  printf("Your input: ");
  //get the input
  scanf("%s",str);
  //check
  bool check=IsMountBalanced(str,strlen(str),&total_height);
  if(check==false){ //if not balanced, print 0
    printf("0");
  }
  else{ //if balanced, print the total height
    printf("The total height of the mountain is: %d", total_height);
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