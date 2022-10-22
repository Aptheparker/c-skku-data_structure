#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h" //structure of linked list

int main(void) {
  int N;
  int cursor = 0;
  int kor = 0; //check if it is korean

  scanf("%d", &N); //get number of loop

  DoubleLinkedList list; //link

  InitList(&list); //initialize the list

  for (int i = 0; i < N; i++) {
    char s[20], c;
    getchar(); //what to do
    scanf("%s", s);
    if(s[0]=='a' || s[0]=='m'){ //add or move
      getchar();
      scanf("%c",&c);
    }
    if (s[0] == 'a') { //add
      if (c == '_') { //add space
        InsertMiddle(&list, cursor, ' ', kor);
        cursor++;
      } else { //add char
        InsertMiddle(&list, cursor, c, kor);
        cursor++;
      }
    } else if (s[0] == 'm') { //move
      if (c == 'l') { //move left
        if(cursor!=0){
          cursor--;  
        }
      } else { //move right
        if(cursor!=list.len){
          cursor++;
        }
      }
    } else if (s[0] == 'e') { //erase
      if(cursor!=0){
        RemoveMiddle(&list,cursor-1);
        cursor--;
      }
    } else if (s[0] == 'l') { //language
      kor = 1;
      i--;
    }
  }

  Node *cur;
  cur=list.head;
  for(int i=0;i<(list.len);i++){ //print the result
    cur=cur->next;
    if(cur->lang==1){ //if lang == 1
      switch (cur->item)
      {
        case 'a':
          printf("ㅁ");
          break;
        
        case 'b':
          printf("ㅠ");
          break;

        case 'c':
          printf("ㅊ");
          break;

        case 'd':
          printf("ㅇ");
          break;

        case 'e':
          printf("ㄷ");
          break;

        case 'f':
          printf("ㄹ");
          break;

        case 'g':
          printf("ㅎ");
          break;

        case 'h':
          printf("ㅗ");
          break;

        case 'i':
          printf("ㅑ");
          break;

        case 'j':
          printf("ㅓ");
          break;

        case 'k':
          printf("ㅏ");
          break;

        case 'l':
          printf("ㅣ");
          break;

        case 'm':
          printf("ㅡ");
          break;

        case 'n':
          printf("ㅜ");
          break;

        case 'o':
          printf("ㅐ");
          break;

        case 'p':
          printf("ㅔ");
          break;

        case 'q':
          printf("ㅂ");
          break;

        case 'r':
          printf("ㄱ");
          break;

        case 's':
          printf("ㄴ");
          break;

        case 't':
          printf("ㅅ");
          break;

        case 'u':
          printf("ㅕ");
          break;

        case 'v':
          printf("ㅍ");
          break;

        case 'w':
          printf("ㅈ");
          break;

        case 'x':
          printf("ㅌ");
          break;

        case 'y':
          printf("ㅛ");
          break;

        case 'z':
          printf("ㅋ");
          break;

        default:
          printf("%c",cur->item);
          break;
      }
    }
    else{
      printf("%c",cur->item); //if lang == 0
    }
  }
  return 0;
}