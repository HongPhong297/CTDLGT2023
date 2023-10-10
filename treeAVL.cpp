//
// Created by roxph on 10/5/2023.
//
#include "iostream"
#include "vector"
using namespace std;
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
    int height;
}Node;
void Init(Node *&proot){
    proot = nullptr;
}
Node *createNode(int data){
    Node *newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    newNode->height = 1;
    return newNode;
}
int getHeight(Node* proot){
    if(proot == nullptr)
        return 0;
    return proot->height;
}
int balanceFactor(Node* proot){
    if(proot == nullptr)
        return 0;
    return getHeight(proot->left) - getHeight(proot->right);
}
Node* rotateLeft(Node *p){
    Node *rightOfp = p->right;
    Node *left1 = rightOfp->left;
    // xoay
    rightOfp->left = p;
    p->right = left1;

    p->height = max(getHeight(p->left), getHeight(p->right)) + 1;
    rightOfp->height = max(getHeight(rightOfp->left), getHeight(rightOfp->right)) + 1;

    return rightOfp;
}
Node* rotateRight(Node *p){
    Node *leftOfp = p->left;
    Node *right1 = leftOfp->right;
    // xoay
    leftOfp->right = p;
    p->left = right1;
    p->height = max(getHeight(p->left), getHeight(p->right)) + 1;
    leftOfp->height = max(getHeight(leftOfp->left), getHeight(leftOfp->right)) + 1;

    return leftOfp;
}
Node* balance(Node* p){
    p->height = max(getHeight(p->left), getHeight(p->right)) + 1;
    if(balanceFactor(p) > 1){
        if(getHeight(p->left->left) >= getHeight(p->left->right)){
            return rotateRight(p);
        }
        else{
            p->left = rotateLeft(p->left);
            return rotateRight(p);
        }
    }
    if(balanceFactor(p) < -1) {
        // Trường hợp con phải nặng hơn hoặc cân bằng, thực hiện xoay trái
        if (getHeight(p->right->right) >= getHeight(p->right->left)) {
            return rotateLeft(p);
        }
            // Trường hợp con phải nhẹ hơn, thực hiện xoay phải cho con phải trước, sau đó xoay trái cho nút gốc
        else {
            p->right = rotateLeft(p->right);
            return rotateLeft(p);
        }
    }
    return p;
}
Node* insert(Node *p, int x){
    if(p == nullptr)
        return createNode(x);
    if(x < p->data)
        p->left = insert(p->left,x);
    else if(x > p->data){
        p->right = insert(p->right,x);
    }
    p->height = max(getHeight(p->left), getHeight(p->right)) + 1;

    return balance(p);
}
// tim gia tri min benh phai = sat trai
Node*  minvalueNode(Node* proot){
    Node* temp = proot;
    while (temp->left != nullptr){
        temp = temp->left;
    }
    return temp;

}
Node* removeBST(Node* &proot, int x){
    if (proot == nullptr)
        return proot;
    if(x < proot->data)
        proot->left = removeBST(proot->left,x);
    else if(x > proot->data)
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
        proot->data = temp->data;
        proot->right = removeBST(proot->right,temp->data);

    }
    return balance(proot);
}
Node* createAVL(int a[], int n){
    Node * proot = nullptr;
    for(int i = 0; i < n; i++){
        proot = insert(proot,a[i]);
    }

    return proot;
}
void Inorder(Node* proot){
    if(proot != nullptr){
        Inorder(proot->left);
        cout << proot->data << " ";
        Inorder(proot->right);
    }
}
void Menu(Node *&proot){
    Init(proot);
    int choice,number,remv;
    vector<int> v;
    while(true){
        cout << "Your Chose: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Input number: ";
                cin >> number;
                proot = insert(proot,number);
                break;
            case 2:
                cout << "Input to remove: ";
                cin >> remv;
                proot = removeBST(proot,remv);
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
void printMenu(){
    cout << "--------MENU--------" << endl;
    cout << "[1] - Input to AVL from Arr" << endl;
    cout << "[2] - Remove" << endl;
    cout << "[3] - ShowAVL" << endl;
    cout << "[4] - Exit" << endl;
}
int main(){
    Node *proot;
    Menu(proot);
    return 0;
}
