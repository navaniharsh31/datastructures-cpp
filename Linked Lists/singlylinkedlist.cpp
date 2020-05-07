#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *first;

public:
    LinkedList()
    {
        first = NULL;
    }
    void create();
    void display();
    void insertBeg();
    void insertEnd();
    void insertBefore();
    void insertAfter();
    void deleteE();
    void deleteBefore();
    void deleteAfter();
    void reverse();
    void length();
    void search();
    void sort();
};

void LinkedList::create()
{
    Node *n, *p;
    int val;
    cout << "\nEnter number ( -1 to stop ) ";
    cin >> val;
    while (val != -1)
    {
        n = new Node();
        n->data = val;
        n->next == NULL;
        if (first == NULL)
        {
            first = n;
        }
        else
        {
            p = first;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = n;
        }
        cout << "Enter number ";
        cin >> val;
    }
}

void LinkedList::display()
{
    Node *p;
    if (first != NULL)
    {
        p = first;
        cout << "\n";
        while (p != 0)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
    else
    {
        cout << "\nEmpty Linked List";
    }
    cout<<endl;
}

void LinkedList::insertBeg(){
    Node *n;
    int val;
    cout << "\nEnter number ";
    cin >> val;
    n = new Node;
    n->data = val;
    if(first == NULL){
        first = n;
        n->next = NULL;
    }
    else{
        n->next=first;
        first = n;
    }
}

void LinkedList::insertEnd(){
    Node *n, *p;
    int val;
    cout << "\nEnter number ";
    cin >> val;
    p = first;
    n = new Node;
    n->data = val;
    while(p->next!=NULL)
        p = p->next;
    p->next = n;
    n->next = NULL;
}

void LinkedList::insertBefore(){
    Node *p, *n;
    int num, val;
    cout<<"\nEnter the element (insert before) ";
    cin>>num;
    cout<<"\nEnter value to insert before "<<num<<" ";
    cin>>val;
    p = first;
    n = new Node;
    n->data = val;
    while(p->next->data!=num)
        p = p->next;
    n->next = p->next;
    p->next = n;
}

void LinkedList::insertAfter(){
    Node *p, *n;
    int num,val;
    cout<<"\nEnter the element (insert after) ";
    cin>>num;
    cout<<"\nEnter value to insert after "<<num<<" ";
    cin>>val;
    p = first;
    n = new Node;
    n->data = val;
    while(p->data != num)
        p = p->next;
    n->next = p->next;
    p->next = n;
}

void LinkedList::deleteE(){
    Node *p, *q;
    int val;
    cout<<"Enter the number to be deleted ";
    cin>>val;
    p = first;
    if(p->data == val){
        first = first->next;
        delete(p);
    }
    else{
        while(p->data!=val){
            q = p;
            p = p->next;
        }
        q->next = p -> next;
        delete(p);
    }
}

void LinkedList::deleteBefore(){
    Node *p, *q;
    int val;
    cout<<"Enter element (delete before) ";
    cin>>val;
    p = first;
    while(p->next->data!=val){
        q = p;
        p=p->next;
    }
    q->next = p -> next;
    delete(p);
}

void LinkedList::deleteAfter(){
    Node *p, *q;
    int val;
    cout<<"Enter element (delete after) ";
    cin>>val;
    p = first;
    if(first->data == val){
        q = first->next;
        first->next = q->next;
        delete(q);
    }
    else{
        while(p->data!=val){
            p = p->next;
            q = p->next;
        }
        p->next = q->next;
        delete(q);
    }
}

void LinkedList::reverse(){
    Node *p, *q, *r;
    q = r = NULL;
    p = first;
    while(p!=NULL){
        r = p->next;
        p->next = q;
        q=p;
        p = r;
    }
    first = q;
}

void LinkedList::length(){
    int index=0;
    Node *p ;
    p = first;
    while(p!=NULL){
        index++;
        p = p->next;
    }
    cout<<endl<<index<<endl;
}

void LinkedList::search(){
    int val, index = 0;
    Node *p;
    cout<<"\nEnter the element to be searched ";
    cin>>val;
    p = first;
    while(p->data!=val){
        index++;
        p = p->next;
    }
    cout<<"\nFound at index "<<index<<endl;
}

void LinkedList::sort(){
    Node *p, *q;
    int temp;
    p = first;
    while(p->next!=NULL){
        q = p;
        p = p->next;
        if(p->data<q->data){
            temp = p->data;
            p->data = q->data;
            q->data = temp;
        }
    }
}

int main()
{
    int option;
    LinkedList *l;
    l = new LinkedList();
    do{
        cout<<"\n1. Insert\n";
        cout<<"2. Insert at beginning\n";
        cout<<"3. Insert at end\n";
        cout<<"4. Insert before\n";
        cout<<"5. Insert after\n";
        cout<<"6. Delete element\n";
        cout<<"7. Delete before\n";
        cout<<"8. Delete after\n";
        cout<<"9. Reverse\n";
        cout<<"10. Length of LL\n";
        cout<<"11. Search\n";
        cout<<"12. Sort\n";
        cout<<"13. Display\n";
        cout<<"Enter your choice ";
        cin>>option;
        switch (option)
        {
            case 1:
                l->create();
                break;
            
            case 2:
                l->insertBeg();
                break;

            case 3:
                l->insertEnd();
                break;

            case 4:
                l->insertBefore();
                break;

            case 5:
                l->insertAfter();
                break;

            case 6:
                l->deleteE();
                break;

            case 7:
                l->deleteBefore();
                break;

            case 8:
                l->deleteAfter();
                break;

            case 9:
                l->reverse();
                break;

            case 10:
                l->length(); 
                break;

            case 11:
                l->search();
                break;

            case 12:
                l->sort();
                break;

            case 13:
                l->display();
                break;

            default:
                break;
        }

    }while(option!=14);
    return 0;
}