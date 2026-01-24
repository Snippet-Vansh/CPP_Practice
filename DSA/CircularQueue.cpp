#include<iostream>
using namespace std;
struct queue{
    int size;
    int f;
    int r;
    int *arr;
};
// int ifull(struct queue *q){
//     if((q->r+1)%q->size==q->f){
//         return 1;
//     }
//     return 0;
// }
int dequeue(struct queue *q){
    int val = -1;
    if((q->f  == q->r)){s
       cout<<"the queue is empty"<<endl;
    }
    else{
        q->f = (q->f+1)%q->size;
        val = q->arr[q->f]; 
    }
    return val;
}
void enqueue(struct queue *q, int val) 
{
    if((q->r+1)%q->size==q->f)
    {
        cout<<"Queue is full"<<endl;
    }else{
        q->r = (q->r+1)%q->size;
        q->arr[q->r]= val;
        cout<<"enqueue element:"<<val<<endl;
    }
}

int main() {
    struct queue q;
    q.size = 5;
    q.f= q.r = 0;
    q.arr = new int[q.size];
    enqueue(&q,12);
    enqueue(&q,15);

    cout<<"dequeue element:"<<dequeue(&q)<<endl;
    cout<<"dequeue element:"<<dequeue(&q)<<endl;
    enqueue(&q,66);
    enqueue(&q,45);
    

    


}