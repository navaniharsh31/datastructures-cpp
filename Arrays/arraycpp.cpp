#include <iostream>

using namespace std;

class Array{
    private:
        int size;
        int length;
        int *A;                                          //Array in heap
    public:
        Array(){                                         //Default constructor          
            size = 0;
            length = 0;
            A = new int[size];  
        }
        Array(int size){                                 //Parameterised constructer
            this->size = size;
            length = 0;
            A = new int[size];
        }
        void insert();
        void display();
        void insertAt();
        void insertBefore();
        void insertAfter();
        void deleteElement();
        int linearSearch();
        void sum();
        void max();
        void min();
        void reverse();
        void sort();
};


void Array::insert(){
    int n, i;
    cout<<"Enter the number of elements to be inserted"<<endl;
    cin>>n;
    for(i=0; i<n; i++){
        cout<<"Element "<< i+1<<" ";
        cin>>A[i];
    }
    length = n;
}

void Array::display(){
    int i;
    for(i=0; i<length; i++){
        cout<<A[i]<<" ";
    }
}

void Array::insertAt(){
    int index, x;
    cout<<endl<<"Enter the element and index at which you want to insert";
    cin>>x;
    cin>>index;
    if (index<=length){
        A[index] = x;
        
    }
    else
    {
        cout<<"Index out of range\n";
    }
}

void Array::insertBefore(){
    int i, index, flag = 0,x,e;
    cout<<"\nEnter the element to be added\n";
    cin>>x;
    cout<<"\nEnter the element before which you want to insert";
    cin>>e;
    for (i = 0; i < length; i++)
    {
        if (e == A[i])
        {
            flag = 1;
            index = i ;
            break;
        }
    }
    if (flag == 1)
    {
        for (i = length; i > index; i--)
        {
            A[i] = A[i - 1];
        }
        A[index] = x;
        length++;
    }
    else if (flag == 0)
    {
        cout<<"\nElement Not found";
    }
}

void Array::insertAfter(){
    int i, index, flag = 0,x,e;
    cout<<"\nEnter the element to be added\n";
    cin>>x;
    cout<<"\nEnter the element before which you want to insert";
    cin>>e;
    for (i = 0; i < length; i++)
    {
        if (e == A[i])
        {
            flag = 1;
            index = i + 1;
            break;
        }
    }
    if (flag == 1)
    {
        for (i = length; i > index; i--)
        {
            A[i] = A[i - 1];
        }
        A[index] = x;
        length++;
    }
    else if (flag == 0)
    {
        cout<<"\nElement Not found";
    }
}

void Array::deleteElement(){
    int index, temp, i;
    cout<<"\nEnter the index to be deleted ";
    cin>>index;
    if(index>=0 && index<length){    
        temp = A[index];
        for(i=index; i<length; i++){
            A[i] = A[i+1];
        }
        length--;
    }
}

int Array::linearSearch(){
    int i, x;
    cout<<"\nEnter the element to be searched";
    cin>>x;
    for (i=0; i<=length;i++){
        if (A[i] == x)
            return i;
    }
    return -1;
}

void Array::sum(){
    int i, sum = 0;
    for(i=0; i<length; i++){
        sum = sum + A[i];
    }
    cout<<"\nSum is "<<sum;
}

void Array::max(){
    int i, max = A[0];
    for (i=0; i<length; i++){
        if(A[i] > max)
            max = A[i];
    }
    cout<<"\nMax element is "<<max;
}

void Array::min(){
    int i, min = A[0];
    for (i=0; i<length; i++){
        if(A[i] < min)
            min = A[i];
    }
    cout<<"\nMin element is "<<min;
}

void Array::reverse(){
    int i, *B,j;
    B = new int[size];
    for(i=length-1, j=0; i>=0; i--,j++){
        B[j] = A[i];
    }

    for(i=0; i<length; i++){
        A[i] = B[i];
    }
    display();
}

void Array::sort(){
    int i, j, temp;
    for(i = 0; i < length; i++)
    {
        for(j = 0; j < length-i-1; j++)
        {
            if( A[j] > A[j+1])
            {
                // swap the elements
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            } 
        }
    }
    display();
}
int main(){
    Array *arr;
    int n, option;
    cout<<"Enter the size of the array"<<endl;
    cin>>n ;
    arr = new Array(n);
    do
    {
        cout<<"\nMenu\n";
        cout<<"1. Insert\n";
        cout<<"2. Insert At\n";
        cout<<"3. Insert Before\n";
        cout<<"4. Insert After\n";
        cout<<"5. Delete\n";
        cout<<"6. Search (Linear Search)\n";
        cout<<"7. Sum\n";
        cout<<"8. Max\n";
        cout<<"9. Min\n";
        cout<<"10. Reverse\n";
        cout<<"11. Sort (Bubble sort)\n";
        cout<<"12. Display\n";
        cout<<"13.Exit\n";

        cout<<"Enter your choice ";
        cin>>option;
        cout<<endl;

        switch (option)
        {
            case 1:
                    arr->insert();
                    break;
            case 2:
                    arr->insertAt();
                    break;
            case 3:
                    arr->insertBefore();
                    break;
            case 4:
                    arr->insertAfter();
                    break;
            case 5:
                    arr->deleteElement();
                    break;
            case 6:                 
                    cout<<"\nElement found at Index: "<<arr->linearSearch();
                    break;
            case 7:
                    arr->sum();
                    break;
            case 8:
                    arr->max();
                    break;
            case 9:
                    arr->min();
                    break;
            case 10:
                    arr->reverse();
                    break;
            case 11:
                    arr->sort();
                    break;
            case 12:
                    arr->display();
                    break;
            default:
                    cout<<"Invalid";
        }
    }while(option<13);


    return 0;
}
