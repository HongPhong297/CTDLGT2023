#include <iostream>
#include <queue>
#include <string>
using namespace std;
typedef struct BenhNhan{
    int stt;
    string hoten;
    int tuoi;
}bnhan;
typedef struct node{
    bnhan info;
    struct node* next;
}Node;

typedef struct QUEUE{
    Node* pHead;
    Node* pTail;
}Queue;
void Init(Queue* q){
    q->pHead = nullptr;
    q->pTail = nullptr;
}
int isEmpty(Queue* q){
    return (q->pHead == nullptr);
}
void Insert(Queue* q, bnhan x){
    Node* newNode = new Node;
    newNode->info = x;
    newNode->next = nullptr;
    if(isEmpty(q)){
        q->pHead  = newNode;
        q->pTail = newNode;
    }else{
        q->pTail->next = newNode;
        q->pTail = newNode;
    }
}

bnhan Remove(Queue* q, int &dakham){
    if(isEmpty(q)){
        bnhan empty = {-1, "", -1};
        return empty;
    }else{
        Node* temp = q->pHead;
        bnhan bn = temp->info;
        q->pHead = q->pHead->next;
        delete temp;
        dakham++;
        return bn;
    }
}
void displayQueue(Queue* q) {
    cout << "\t\t\nDANH SACH DOI KHAM BENH\n";
    if (!isEmpty(q)) {
        Node* temp = q->pHead;
        while (temp != nullptr) {        
            cout << temp->info.stt << " - " << temp->info.hoten << " - " << temp->info.tuoi << endl;
            temp = temp->next;
        }
    } else {
        cout << "Hang doi rong" << endl;
    }
}

void Addbnhan(Queue* q, int &stt){
    bnhan bn;
    bn.stt = stt++;
    fflush(stdin);
    cout << "Nhap ten benh nhan: ";
    cin >> bn.hoten;
    fflush(stdin);
    cout << "Nhap tuoi: ";
    cin >> bn.tuoi;
    Insert(q,bn);
    cout << "Them benh nhan thanh cong!\n";
}
void removeBnhan(Queue* q, int &dakham){
    if(!isEmpty(q)){
        bnhan x = Remove(q,dakham);
            cout << "Benh nhan tiep theo cho kham: \n";
            cout << "STT: " << x.stt << " " << "Ho ten: " << x.hoten << " " << "Tuoi: " << x.tuoi;
    }else{
        cout << "Khong con benh nhan nao cho kham\n";
    } 
}
int main(){
    Queue q;
    Init(&q);
    int choice;
    int stt = 1;
    int dakham = 0;
    while(true){
        cout << "\nMenu:\n";
        cout << "1. Them benh nhan vao hang doi\n";
        cout << "2. Lay benh nhan tiep theo cho kham\n";
        cout << "3. So luong nguoi da kham\n";
        cout << "4. Xuat danh sach benh nhan cho kham\n";
        cout << "5. Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> choice;
        switch (choice){
        case 1:
            Addbnhan(&q,stt);
            break;
        case 2:
            removeBnhan(&q,dakham);
            break;
        case 3:
            cout << "So luong nguoi da kham: " << dakham << endl;
            break;
        case 4:
            displayQueue(&q);         
            break;
        case 5:
            cout << "Ket thuc chuong trinh\n";      
            exit(0);
        default:
           cout << "Chon chuc nang ko hop le";
        }
    }
    return 0;
}