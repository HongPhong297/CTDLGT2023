//
// Created by roxph on 9/30/2023.
//
#include <iostream>
#include <algorithm>
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
// xuat ds tang dan LNR
void LNR(Node* proot){
    if(!isEmpty(proot)){
        LNR(proot->left);
        cout << proot->info << " ";
        LNR(proot->right);
    }
}
// xuat ds giam dan RNL
void RNL(Node* proot){
    if(!isEmpty(proot)){
        RNL(proot->right);
        cout << proot->info << " ";
        RNL(proot->left);
    }
}
// 3 cay nhi phan day du
bool fullBinaryTree(Node* proot){
    // Nếu cây rỗng, đó cũng là một cây nhị phân đầy đủ
    if (proot == nullptr) {
        return true;
    }

    // Nếu một trong hai con là rỗng, cây không đầy đủ
    if ((proot->left == nullptr && proot->right != nullptr) ||
        (proot->left != nullptr && proot->right == nullptr)) {
        return false;
    }

    // Kiểm tra đệ quy cho cả hai nhánh con
    return fullBinaryTree(proot->left) && fullBinaryTree(proot->right);
}
// xac dinh nut cha cua nut co khoa x
Node* fatherOfX(Node* proot, int x){
    if(proot == nullptr)
        return nullptr;

    if(proot->left != nullptr && proot->left->info == x)
        return proot;

    if(proot->right != nullptr && proot->right->info == x)
        return proot;

    Node* leftResult = fatherOfX(proot->left, x);
    if(leftResult != nullptr)
        return leftResult;

    Node* rightResult = fatherOfX(proot->right, x);
    if(leftResult != nullptr)
        return rightResult;
}
int demSoNutLa(Node* proot){
    if(proot == nullptr)
        return 0;
    int temp = 0;
    if(proot->left == nullptr && proot->right == nullptr)
        return 1 + demSoNutLa(proot->left) + demSoNutLa(proot->right);

    return demSoNutLa(proot->left) + demSoNutLa(proot->right);
}
int demNutGiua(Node* proot){
    if(proot == nullptr)
        return 0;
    int temp = 0;
    if(proot->left != nullptr || proot->right != nullptr)
        temp += 1;
    temp += demNutGiua(proot->left);
    temp += demNutGiua(proot->right);
    return temp;
}

int kichThuocCay(Node* proot){
    if(proot == nullptr)
        return 0;
    return 1 + kichThuocCay(proot->left) + kichThuocCay(proot->right);
}
//do xau cua 1 gt
int DepthOfNode(Node* root, int value, int depth = 0) {
    if (root == nullptr) {
        return -1; // Nút không tồn tại trong cây
    }

    if (root->info == value) {
        return depth; // Đã tìm thấy nút và trả về độ sâu
    }

    // Nếu giá trị cần tìm nằm ở bên trái nút hiện tại
    if (value < root->info) {
        return DepthOfNode(root->left, value, depth + 1);
    }

    // Nếu giá trị cần tìm nằm ở bên phải nút hiện tại
    return DepthOfNode(root->right, value, depth + 1);
}
// chieu cao cay
int treeHight(Node* proot){
    if(proot == nullptr)
        return -1;
    int left = treeHight(proot->left);
    int right = treeHight(proot->right);

    return 1 + max(left,right);
}
int findMax(Node* proot){
    if (proot == nullptr)
        return INT_MIN;
    int max = proot->info;
    int leftMax = findMax(proot->left);
    int righttMax = findMax(proot->right);

    if (leftMax > max)
        max = leftMax;
    if (righttMax > max)
        max = righttMax;
    return max;
}
int findMin(Node* proot){
    if (proot == nullptr)
        return INT_MAX;
    int min = proot->info;
    int leftMin = findMin(proot->left);
    int righttMin = findMin(proot->right);

    if (leftMin < min)
        min = leftMin;
    if (righttMin < min)
        min = righttMin;
    return min;
}
int Tong(Node* proot){
    if (proot == nullptr)
        return 0;
    int tong = 0;
    if(proot != nullptr)
        tong += proot->info;
    tong += Tong(proot->left);
    tong += Tong(proot->right);
    return tong;
}
int main(){
    Node* proot;
    Init(proot);
    int a[11] = {8,3,10,1,6,4,7,14,17,9,20};
    int b[3] = {8,3,10};
    for(int i = 0; i < 11; ++i){
        insertBST(proot,a[i]);
    }
    return 0;
}