//
// Created by roxph on 9/30/2023.
//
#include <iostream>
using namespace std;
typedef struct node{
    int info;
    struct node* left;
    struct node* right;
}Node;
void Init(Node* &proot){
    proot = nullptr;
}
int isEmpty(Node* proot){
    return (proot == nullptr);
}
Node* createNode(int data){
    Node* newNode = new Node;
    newNode->info = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}
void insertBST(Node* &proot, int x){
    if(isEmpty(proot))
        proot = createNode(x);
    else{
        if(x < proot->info)
            insertBST(proot->left,x);
        else if (x > proot->info)
            insertBST(proot->right,x);
    }
}
void Inorder(Node* proot){
    if(!isEmpty(proot)){
        Inorder(proot->left);
        cout << proot->info << " ";
        Inorder(proot->right);
    }
}
// tim gia tri min benh phai = sat trai
Node* minvalueNode(Node* proot){
    Node* temp = proot;
    while (temp->left != nullptr){
        temp = temp->left;
    }
    return temp;

}
Node* removeBST(Node* &proot, int x){
    if (proot == nullptr)
        return proot;
    if(x < proot->info)
            proot->left = removeBST(proot->left,x);
    else if(x > proot->info)
            proot->right = removeBST(proot->right,x);
    else{
        if (proot->left == nullptr && proot->right == nullptr){
            delete proot;
            return nullptr;
        }
        else if(proot->left == nullptr){
            Node* temp = proot->right;
            delete proot;
            return temp;
        }
        else if(proot->right == nullptr){
            Node* temp = proot->left;
            delete proot;
            return temp;
        }
        Node* temp = minvalueNode(proot->right);
        proot->info = temp->info;
        proot->right = removeBST(proot->right,temp->info);

    }
    return proot;
}
void printMenu(){
    cout << "--------MENU--------" << endl;
    cout << "[1] - Insert" << endl;
    cout << "[2] - Remove" << endl;
    cout << "[3] - ShowBST" << endl;
    cout << "[4] - Exit" << endl;


}
void Menu(Node* &proot){
    printMenu();
    Init(proot);
    int ins,remv, choice;
    Node* temp;
    while(true){
        cout << "Your Chose: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Input to insert: ";
                cin >> ins;
                insertBST(proot,ins);
                break;
            case 2:
                cout << "Input to remove: ";
                cin >> remv;
                temp = removeBST(proot,remv);
                insertBST(proot,temp->info);
                break;
            case 3:
                Inorder(proot);
                break;
            case 4:
                exit(0);
            default:
                cout << "Error";
        }
    }
}

int main(){
    Node* proot;
    Menu(proot);
    return 0;
}