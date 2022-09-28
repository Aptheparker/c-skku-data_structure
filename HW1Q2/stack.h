#define MAX_STACK 1000

typedef enum { false, true } bool;
typedef int Data;
typedef struct {
  Data items[MAX_STACK]; 
  int top;
} Stack;

// Make stack empty.
void InitStack(Stack *pstack); 
// Check whether stack is full. 
bool IsFull(Stack *pstack);
// check whether stack is empty. 
bool IsEmpty(Stack *pstack);
// Read the item at the top.
Data Peek(Stack *pstack);
// Insert an item at the top.
void Push(Stack *pstack, Data item); 
// Remove the item at the top.
void Pop(Stack *pstack);

// Make stack empty.
void InitStack(Stack *pstack)
{
    pstack->top = -1;
}

// Check whether stack is full.
bool IsFull(Stack *pstack)
{
  return pstack->top == MAX_STACK - 1; 
}

// check whether stack is empty
bool IsEmpty(Stack *pstack)
{
    return pstack->top == -1;
}

// Read the item at the top.
Data Peek(Stack *pstack)
{
  if (IsEmpty(pstack))
    exit(1); //error: empty stack
  return pstack->items[pstack->top];
}

// Insert an item at the top.
void Push(Stack *pstack, Data item) {
    if (IsFull(pstack))
        exit(1); //error: stack full
    pstack->items[++(pstack->top)] = item;
}

// Remove the item at the top.
void Pop(Stack *pstack) {
    if (IsEmpty(pstack))
        exit(1); //error: empty stack
    --(pstack->top);
}