#include <stdio.h>
#include <stdlib.h>

// definations 
typedef struct queue{
    int size ; 
    int f ; 
    int b ; 
    int *arr ; 
}queue;

void enqueue(queue  *, int) ;
void dequeue(queue *) ; 
void peek(queue  *, int) ; 
void display(queue *) ;  
int isFull(queue *) ;
int isEmpty(queue * ) ; 



int main() 
{
    int n , new; 
    queue s  ; 
    s.size = 100 ; 
    s.f = s.b = -1 ; 
    s.arr = (int *)malloc(sizeof(int)*s.size) ; 
    while(1){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n") ; 
        printf("Enter your choice:\n");
        scanf("%d",&n) ; 
        switch(n){
            case 1 : 
                printf("Enter the data\n"); 
                scanf("%d",&new) ; 
                enqueue(&s , new) ; 
                break;
            case 2 :
                dequeue(&s); 
                break; 
            case 3 :
                printf("Enter the position you want to peek\n") ; 
                scanf("%d",&new) ; 
                peek(&s , new) ; 
                break;
            case 4 :
                display(&s) ; 
                break;
            case 5 :
                exit(0) ;
            default :
                printf("Invalid choice\n"); 
        }
    }
}

void enqueue(queue *s , int new){
    if(isFull(s)){
        printf("The Queue is full!\n") ;
    }
    else if(isEmpty(s)){
        s->f=s->b=0 ; 
        s->arr[s->b] = new ;
    }
    else{
        s->b = s->b + 1 ; 
        s->arr[s->b] = new ; 
    }  
}

void dequeue(queue *s){
    if(isEmpty(s)){
        printf("The Queue is empty!");
    }
    else if(s->b == s->f){
        printf("Deleted item is %d\n",s->arr[s->f] ) ;
        s->b=s->f=-1 ;
    }
    else {
        printf("Deleted item is %d\n",s->arr[s->f] ) ;
        s->f++ ; 
    }
}

void peek(queue *s , int pos){
    printf("Element at position %d is %d\n",pos , *(s->arr + s->f + pos));
}

void display(queue *s){
    for(int i = s->f ; i <= s->b ; i++){
        printf("%d->",*(s->arr + i) ) ; 
    }
    printf("\n") ; 
}

int isFull(queue *s){
    if(s->b == s->size -1){
        return 1 ;
    }
    else {
        return 0 ; 
    }
}

int isEmpty(queue *s){
    if(s->b == -1 && s->f == -1){
        return 1 ;
    }
    else {
        return 0 ; 
    }
}