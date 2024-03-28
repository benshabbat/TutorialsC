
#define MAX_SIZE 1000 // Maximum size of the stack
typedef struct {
    int* data;
    int top;
} MyStack;

MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->data = (int*)malloc(MAX_SIZE * sizeof(int));
    stack->top = -1;
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    obj->top++;
    obj->data[obj->top] = x;
}

int myStackPop(MyStack* obj) {
    int topValue = obj->data[obj->top];
    obj->top--;
    return topValue;
}

int myStackTop(MyStack* obj) {
    return obj->data[obj->top];
}

bool myStackEmpty(MyStack* obj) {
    return obj->top == -1;
}

void myStackFree(MyStack* obj) {
    free(obj->data);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/