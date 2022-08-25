#include <stdio.h>
#include <stdlib.h>
#define max 10

// definations 
typedef struct queue{
    char name[30] ; 
    int priority ; 
}queue;

void enqueue(queue  *, queue new , int *f , int *r) ;
void dequeue(queue * , int *f ,int *r) ; 
void peek(queue  *, int *f , int *r , int pos) ; 
void display(queue * , int *f , int *r) ;  
int isFull(queue * , int *f , int *r) ;
int isEmpty(queue * , int *f ,int *r) ; 
void sort(queue *s , int *f ,int *r) ; 



int main() 
{
    int n ; 
    queue new ; 
    queue s[max]  ; 
    int f = -1 , r = -1 ;
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
                printf("Enter the name and priority \n"); 
                scanf("%s%d",&new.name , &new.priority) ; 
                enqueue(s , new , &f ,&r) ; 
                break;
            case 2 :
                dequeue(s , &f ,&r); 
                break; 
            case 3 :
                printf("Enter the position you want to peek\n") ; 
                scanf("%d",&n) ; 
                peek(s , &f ,&r , n) ; 
                break;
            case 4 :
                display(s , &f , &r) ; 
                break;
            case 5 :
                exit(0) ;
            default :
                printf("Invalid choice\n"); 
        }
    }
}

void enqueue(queue *s ,queue new , int *f , int *r){
    if(isFull(s , f , r)){
        printf("The Queue is full!\n") ;
    }
    else if(isEmpty(s , f , r)) {
        *r = *f = 0;
        s[*r] = new ;
    }
    else{
        *r = *r + 1 ; 
        s[*r] = new ;
        sort(s, f ,r) ; 
    }  
}

void dequeue(queue *s, int *f ,int *r){
    if(isEmpty(s , f , r)){
        printf("The Queue is empty!");
    }
    else if(*r == *f){
        *r = *f = -1 ;
    }
    else {
        *f = *f + 1 ;
    }
}

void peek(queue *s ,int *f , int *r , int pos){
    printf("Element at position %d is %s\n",pos , (s+ *f+ pos -1)->name );
}

void display(queue *s , int *f , int *r)
{
    for(int i = *f  ; i <= *r ; i++){
        printf("%s->",(s + i)->name ) ; 
    }
}

int isFull(queue *s , int *f , int *r)
{
    if(*r == max - 1){
        return 1 ;
    }
    else {
        return 0 ; 
    }
}

int isEmpty(queue *s , int *f , int *r)
{
    if(*f == -1 || *r == -1){
        return 1 ;
    }
    else {
        return 0 ; 
    }
}

void sort(queue *s , int *f ,int *r)
{
    queue t ; 
    for(int i = 0; i < *r - *f   ; i++){
        for(int j = *f ; j < *r - i ; j++){
            if(s[j].priority < s[j+1].priority){
                t = s[j] ; 
                s[j] = s[j+1] ;
                s[j+1]=t ;
            }
        }
    }
}

