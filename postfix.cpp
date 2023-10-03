#include <iostream>
using namespace std;


typedef struct node{
    char data;
    struct node* next;
}Node;
typedef Node Stack;
void Init(Stack *&s){
    s = nullptr;
}
int isEmpty(Stack* s){
    return (s == nullptr);
}
void Push(Stack *&s, char x){
    Node * newNode = new Node;
    newNode->data = x;
    newNode->next = s;
    s = newNode;
}
int Pop(Stack* &s, char &x){
    if(isEmpty(s))
        return 0;
    x = s->data;
    Node* temp = s;
    s = s->next;
    delete temp;
    return 1;
}
// đánh giá độ ưu tiên toán tử 
int Priority(char op){
        if(op == '+' || op == '-')
            return 1;
        else if(op == '*' || op == '/')
            return 2;
        return 0;
}
// Hàm kiểm tra xem một ký tự có phải là toán tử hay không
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
string infixToPostFix(string infix){
    Stack* s;
    Init(s);
    string Postfix = "";
    for(char c : infix){
        if(isalnum(c)){
            Postfix += c;
        }else if(c == '('){
            Push(s,c);
        }else if(c == ')'){
            char x;
            while(Pop(s,x) && x != '('){
                Postfix += x;
            }
        }else if(isOperator(c)){
            while(isEmpty(s) != 1 && Priority(s->data) >= Priority(c)){
                char x;
                Pop(s,x);
                Postfix += x;
            }
            Push(s,c);
        }
    }
    while(isEmpty(s) != 1){
        char x;
        Pop(s,x);
        Postfix += x;
    }
    return Postfix;
}
int main(){
    string Postfix;
    cin >> Postfix;
    cout << infixToPostFix(Postfix);
    return 0;
}