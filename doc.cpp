#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Hàm kiểm tra xem một ký tự có phải là toán tử hay không
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Hàm ưu tiên của các toán tử
int getPriority(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

// Hàm chuyển biểu thức trung tố sang biểu thức hậu tố
string infixToPostfix(string infix) {
    stack<char> operatorStack;
    string postfix = "";
    for (char c : infix) {
        if (isalnum(c)) {
            // Nếu là toán hạng, thêm vào biểu thức hậu tố
            postfix += c;
        } else if (c == '(') {
            // Nếu là dấu mở ngoặc, đẩy vào stack
            operatorStack.push(c);
        } else if (c == ')') {
            // Nếu là dấu đóng ngoặc, pop các toán tử từ stack vào biểu thức hậu tố
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop(); // Loại bỏ dấu mở ngoặc khớp
        } else if (isOperator(c)) {
            // Nếu là toán tử
            while (!operatorStack.empty() && operatorStack.top() != '(' &&
                   getPriority(operatorStack.top()) >= getPriority(c)) {
                // Pop và thêm các toán tử có ưu tiên cao hơn vào biểu thức hậu tố
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    // Pop tất cả toán tử còn lại từ stack vào biểu thức hậu tố
    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

int main() {
    string infixExpression;
    cout << "Nhập biểu thức trung tố: ";
    cin >> infixExpression;

    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Biểu thức hậu tố: " << postfixExpression << endl;

    return 0;
}
