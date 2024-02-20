//Number of Students Unable to Eat Lunch
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue{
    int size;
    int* arr;
    int head;
    int tail;
}Queue;

Queue* create_queue(int size){
    Queue* qu = (Queue* )malloc(sizeof(Queue));
    qu -> size = size;
    qu -> arr = (int* )malloc(size*sizeof(int));
    qu -> head = -1;
    qu -> tail = -1;
    return qu;
}

bool is_empty(Queue* qu){
    return qu -> head > qu -> tail || qu -> head == -1 ? true:false;  
}

void push_queue(Queue* qu, int value){
    if (qu -> tail == -1){
        qu -> head += 1;
        qu -> tail += 1;
    }
    else{
        qu -> tail += 1;
    }
    qu -> arr[qu->tail] = value;
}

int pop_queue(Queue* qu){
    if (is_empty(qu)){
        return -1;
    }
    qu -> head += 1;
    return qu -> arr[qu -> head - 1];
}

void free_queue(Queue* qu){
    free(qu -> arr);
    free(qu);
}

int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    Queue* qu = create_queue(studentsSize*studentsSize);
    for (int i = 0; i<studentsSize; i++){
        push_queue(qu, students[i]);
    }
    int j = 0;
    int rep = 0;
    while(sandwichesSize !=0){
      int num = pop_queue(qu);
      if (sandwiches[j] == num){
        sandwichesSize -= 1;
        j += 1;
        rep = 0;
      }
      else{
        push_queue(qu, num);
        rep += 1;
      }
      if (sandwichesSize == 0){
        free_queue(qu);
        return 0;
      } 
      else if(sandwichesSize == rep){
        free_queue(qu);
        return rep;
      } 
    }
    return 0;
}
