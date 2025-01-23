#include<iostream>
using namespace std;
class queue{

int* arr;
int front;
int rear;
int n;

public:
queue(int size)         //construct || initialize of queue
{
    arr= new int[size];
    front = -1;
    rear = -1;
    n=size;
}

void enqueue(int x){
      if(rear == n-1){
        cout<<"The Queue is full"<<endl;
    }
    else{
         rear++;
        arr[rear]=x;
        if (front==-1)
        {
            front++;
        }
    }   
}

void dequeue(){
    if(front==-1 || front>rear){
        cout<<"The Queue is Empty"<<endl;
    }
    else{
        front++;
    }
    
}

void Display(){
    if(front==-1 || front>rear){
        cout<<"The Queue is Empty"<<endl;
    }
    else{
    cout<<"Here are the entered data:"<<endl;
    for (int i = front; i < rear+1; i++)
    {
        cout<<"=>"<<arr[i]<<endl;
    }
    }
    
    
}

};


int main(){
    queue q(1);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(2);
    q.Display();

    return 0;
}