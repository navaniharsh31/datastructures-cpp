#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
};

class BST{
    private:
        Node *root;
    public:
        BST(){
            root = NULL;
        }
        void create();
        Node *getRoot(){
            return root;
        }
        void preorder(Node *root);
        void inorder(Node *root);
        void postorder(Node *root);    
        bool search();
        void deleteE();
        void display();
};

void BST::preorder(Node *root){
    if (root){
    cout<<root->data<<" ";
    preorder(root->lchild);
    preorder(root->rchild);
    }
}

void BST::inorder(Node *root){
    if (root){
    inorder(root->lchild);
    cout<<root->data<<" ";
    inorder(root->rchild);
    }
}

void BST::postorder(Node *root){
    if (root){
    postorder(root->lchild);
    postorder(root->rchild);
    cout<<root->data<<" ";
    }
}

bool BST::search(){
    Node *p = root;
    int key;
    cout<<"\nEnter key to be searched ";
    cin>>key;
    while(p!=NULL){
        if(key>p->data){
            p = p->rchild;
        }
        else if (key<p->data){
            p = p->lchild;
        }
        else return true;
    }
    return false;
}

void BST::create(){
    int key;
    Node *p, *q, *n;
    p=root;
    cout<<"Enter the value to be inserted: ";
    cin>>key;
    if(root == NULL){
        n = new Node;
        n->data = key;
        n->lchild = NULL;
        n->rchild = NULL;
        root = n;
        return;
    }

    while(p!=NULL){
        q=p;
        if(key<p->data)
            p = p->lchild;
        else if (key> p->data)
            p = p->rchild;
        else
            return;
    }

    n = new Node;
    n->data = key;
    n->lchild = NULL;
    n->rchild = NULL;

    if(key<q->data)
        q->lchild = n;
    else 
        q->rchild = n;

}



int main(){
    BST *b;
    b = new BST();
    int option;
    do{
        cout<<"\n1. Insert\n";
        cout<<"2. Preorder\n";
        cout<<"3. Ineorder\n";
        cout<<"4. Postorder\n";
        cout<<"5. Search\n";
        cout<<"Enter option ";
        
        cout<<"";
        cin>>option;
        switch (option)
        {
        case 1:
            b->create();
            break;
        
        case 2:
            b->preorder(b->getRoot());
            break;
        
        case 3:
            b->inorder(b->getRoot());
            break;
        case 4:
            b->postorder(b->getRoot());
            break;

        case 5:
            if (b->search()){
                cout<<"\n Found!";
            }
            else
            {
                cout<<"\nNot found!";
            }
            

        default:
            break;
        }

    }while(option!=4);
}