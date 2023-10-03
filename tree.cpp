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
void createTree(Node* &proot, int a[], int begin, int end){
    if(begin > end)
        return;
    int i = (begin + end) / 2;
    proot = createNode(a[i]);
    createTree(proot->left, a, begin, i - 1);
    createTree(proot->right, a, i+1, end);
}
// LNR
void Inorder(Node* proot){
    if(!isEmpty(proot)){
        Inorder(proot->left);
        cout << proot->info << " ";
        Inorder(proot->right);
    }
}
// NLR
void Preoder(Node* proot){
    if (!isEmpty(proot)){
        cout << proot->info << " ";
        Preoder(proot->left);
        Preoder(proot->right);
    }
}
// LRN
void Postoder(Node* proot){
    if (!isEmpty(proot)){
        Postoder(proot->left);
        Postoder(proot->right);
        cout << proot->info << " ";
    }
}
// dem so nodes tren cay
int countNodes(Node* proot){
    if (isEmpty(proot))
        return 0;
    int n = 1;
    n = n + countNodes(proot->left);
    n = n + countNodes(proot->right);
    return n;
}
// dem so nodes co gia tri >  x
int coutNodeX(Node* proot, int x){
    if(isEmpty(proot))
        return 0;
    int temp = 0;
    if (proot->info > x)
        temp = 1;
    temp = temp + coutNodeX(proot->left,x);
    temp = temp + coutNodeX(proot->right,x);
    return temp;
}
// dem so nodes la tren cay
int coutLeafNodes(Node* proot){
    if (isEmpty(proot))
        return 0;
    int n = 0;
    if (proot->left == nullptr && proot->right == nullptr)
        n += 1;
    n = n + coutLeafNodes(proot->left);
    n = n + coutLeafNodes(proot->right);
    return n;
}
// dem so nut la co gia tri nho hon Y
int coutLeafNodesY(Node* proot, int y){
    if (isEmpty(proot))
        return 0;
    int n = 0;
    if (proot->left == nullptr && proot->right == nullptr && proot->info < y)
        n += 1;
    n = n + coutLeafNodesY(proot->left,y);
    n = n + coutLeafNodesY(proot->right,y);

    return  n;
}
int main(){
    Node* proot;
    int a[5] = {1,5,9,2,6};
    Init(proot);
    createTree(proot,a,0,4);
    Inorder(proot);
    cout << endl << "So nodes tren cay = " << countNodes(proot) << endl;
    cout << "So nodes > 3 = " << coutNodeX(proot,3) << endl;
    cout << "So nut la = " << coutLeafNodes(proot) << endl;
    cout << "So nut la nho hon y = " << coutLeafNodesY(proot,10);
    return 0;
}