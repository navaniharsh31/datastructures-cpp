#include <iostream>

using namespace std;

class Stack{
    private:
        int top;
        int *S;
        int size;
    public:
        Stack(int size){
            this->size = size;
            top = -1;
            S = new int[size];
        }
        void push();
        bool isEmpty();
        int pop();
        int peek();
        void display();
};

void Stack::push(){
    int val;
    cout<<"\nEnter the number to be pushed: ";
    cin>>val;
    if (top>=size-1){
        cout<<"Stack overflow";
        return;
    }
    else{
        top++;
        S[top] = val;   
    }
}

int Stack::pop(){
    int temp;
    if(top==-1){
        cout<<"Stack underflow";
        return -1;
    }
    else{
        temp = S[top];
        top--;
        return temp;
    }
}

int Stack::peek(){
    if(top==-1){
        cout<<"Stack underflow";
        return -1;
    }
    else
        return S[top];
}

bool Stack::isEmpty(){
    return top==-1;    
}


void Stack::display(){
    int i;
    if(!isEmpty()){
        for(i=top;i>=0;i--)
            cout<<S[i]<<" ";
    }
    else
        cout<<"Stack empty";
}

int main(){
    Stack *s;
    int n, option;
    cout<<"Enter the size of the stack"<<endl;
    cin>>n;
    s = new Stack(n);
    do{
        cout<<"\n\n1. Push an element";
        cout<<"\n2. Pop an element";
        cout<<"\n3. Peek an element";
        cout<<"\n4. Display stack";
        cout<<"\n\nEnter your choice: ";
        cin>>option;

        switch (option)
        {
            case 1:
                s->push();
                break;
            case 2:
                cout<<s->pop()<<endl;
                break;
            case 3:
                cout<<s->peek()<<endl;
                break;
            case 4:
                s->display();
                break;
        
        default:
            break;
        }
    }while(option!=5);
    return 0;
}