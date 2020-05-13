#include <iostream>

using namespace std;

class Queue{
    private:
        int front;
        int rear;
        int size;
        int *Q;
    public:
        Queue(int size){
            this->size = size;
            Q = new int[size];
            front = rear = -1;
        }
        void enqueue();
        void dequeue();
        void display();
};

void Queue::enqueue(){
    int val;
    cout<<"\nEnter number to enqueue ";
    cin>>val;
    if(rear == size - 1){
        cout<<"\nQueue Full!";
    }
    else{
        rear++;
        Q[rear] = val;
    }
}

void Queue::dequeue(){
    int x = -1;
    if(front == rear)
        cout<<"\nQueue Empty!";
    else{
        front++;
        x = Q[front];
    }
    cout<<x<<" was removed";
}

void Queue::display(){
    for(auto i=front+1; i<=rear; i++)
        cout<<Q[i]<<" ";
}

int main(){
    Queue *q;
    int n, option;
    cout<<"Enter the size of the queue "<<endl;
    cin>>n;
    q = new Queue(n);
    do{
        cout<<"\n\n1. Enqueue";
        cout<<"\n2. Dequeue";
        cout<<"\n3. Display";
        cout<<"\n\nEnter your choice: ";
        cin>>option;

        switch (option)
        {
            case 1:
                q->enqueue();
                break;
            case 2:
                q->dequeue();
                break;
            case 3:
                q->display();
                break;
        
        default:
            break;
        }
    }while(option!=4);
    return 0;
}