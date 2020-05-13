#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class Queue{
    private:
        Node *front;
        Node *rear;
    public:
        Queue(){
            front = rear = NULL;
        }
        void enqueue();
        void dequeue();
        void search();
        void display();
};

void Queue::enqueue(){
    Node *n, *p;
    int val;
    cout<<"\nEnter element to enqueue ";
    cin>>val;
    n = new Node();
    n->data = val;
    n->next = NULL;
    if(front==NULL){
        front = rear = n;
    }
    else{
        rear->next = n;
        rear = n;
    }
}

void Queue::dequeue(){
    Node *p = front;
    if(front==rear)
        cout<<"\nQueue Empty!\n";
    else{
        cout<<p->data<<" was deleted\n";
        front = p->next;
        delete(p);
    }
}

void Queue::display(){
    Node *p;
    p=front;
    if(front==rear)
        cout<<"\nQueue Empty!\n";
    else{
        while(p!=NULL){
            cout<<p->data<<" ";
            p=p->next;
        }
    }
}

void Queue::search(){
    int index=0, val;
    Node *p=front;
    cout<<"\nEnter element to be searched: ";
    cin>>val;
    while(p->data!=val){
        index++;
        p=p->next;
    }
    cout<<"\nFound at "<<index;
}

int main(){
    Queue *q;
    int option;
    q = new Queue();
    do{
        cout<<"\n1. Enqueue";
        cout<<"\n2. Dequeue";
        cout<<"\n3. Search";
        cout<<"\n4. Display";
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
                q->search();
                break;
            case 4:
                q->display();
                break;
        
        default:
            break;
        }
    }while(option!=5);
    return 0;
}