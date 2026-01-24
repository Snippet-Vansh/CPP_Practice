#include<iostream>
using namespace std;
 
struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};
 
 
int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
 
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
 
void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
       cout<<"enqueued element: "<<val<<endl;
    }
}
 
int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
       cout<<"the queue is empty"<<endl;
    }
    else{
        q->f++;
        a = q->arr[q->f]; 
    }
    return a;
}
 
int main(){
    struct queue q;
    q.size = 10;
    q.f = q.r = 0;
    q.arr = new int[q.size];
    
    // Enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1); 
cout << "Dequeuing element " << dequeue(&q) << endl;
cout << "Dequeuing element " << dequeue(&q) << endl;
cout << "Dequeuing element " << dequeue(&q) << endl;

    enqueue(&q, 45);
    enqueue(&q, 56);
    enqueue(&q, 76);
 
//     if(isEmpty(&q)){
//         printf("Queue is empty\n");
//     }
//     if(isFull(&q)){
//         printf("Queue is full\n");
//     }
 
//     return 0;
}
