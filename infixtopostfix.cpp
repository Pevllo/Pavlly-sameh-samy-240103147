#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const int MAX_SIZE = 100;

class IntStack {
private:
    int data[MAX_SIZE];
    int top;

public:
    IntStack(){
        top=-1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        data[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return data[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return data[top];
    }
};

class CharStack {
private:
    char data[MAX_SIZE];
    int top;

public:
    CharStack(){
        top=-1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(char value) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        data[++top] = value;
    }

    char pop() {
        if (isEmpty()) {
            return '\0';
        }
        return data[top--];
    }

    char peek() {
        if (isEmpty()) {
            return '\0';
        }
        return data[top];
    }
};

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

string infixToPostfix(string expression) {
    CharStack stack;
    string postfix = "";

    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];

        if (c == ' ')
            continue;

        if (isdigit(c)) {
            postfix += c;
            postfix += ' ';
        }
        else if (c == '(') {
            stack.push(c);
        }
        else if (c == ')') {
            // Pop operators from the stack and add them to postfix until '(' is found.
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix += stack.pop();
                postfix += ' ';
            }
            if (!stack.isEmpty() && stack.peek() == '(') {
                stack.pop();
            }
            else {
                cout << "Error: Mismatched parentheses!" << endl;
                return "";
            }
        }
        else if (isOperator(c)) {
            while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(c)) {
                postfix += stack.pop();
                postfix += ' ';
            }
            stack.push(c);
        }
        else {
            cout << "Error: Invalid character '" << c << "' in expression!" << endl;
            return "";
        }
    }

    while (!stack.isEmpty()) {
        char op = stack.pop();
        if (op == '(') {
            cout << "Error: Mismatched parentheses!" << endl;
            return "";
        }
        postfix += op;
        postfix += ' ';
    }

    return postfix;
}

int evaluatePostfix(string expression) {
    IntStack stack;

    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];

        if (c == ' ')
            continue;

        if (isdigit(c)) {
            stack.push(c - '0'); 
        }
        else if (isOperator(c)) {
            if (stack.isEmpty()) {
                cout << "Error: Not enough operands for operator '" << c << "'!" << endl;
                return 0;
            }
            int operand2 = stack.pop();

            if (stack.isEmpty()) {
                cout << "Error: Not enough operands for operator '" << c << "'!" << endl;
                return 0;
            }
            int operand1 = stack.pop();

            int result;
            switch (c) {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                if (operand2 == 0) {
                    cout << "Error: Division by zero!" << endl;
                    return 0;
                }
                result = operand1 / operand2;
                break;
            default:
                cout << "Error: Invalid operator!" << endl;
                return 0;
            }
            stack.push(result);
        }
    }

    if (stack.isEmpty()) {
        cout << "Error: Empty expression!" << endl;
        return 0;
    }

    int finalResult = stack.pop();

    if (!stack.isEmpty()) {
        cout << "Error: Too many operands in expression!" << endl;
        return 0;
    }

    return finalResult;
}

int main() {
    string infixExpression;

    cout << "Stack Calculator Program" << endl;
    cout << "Enter an infix expression (e.g., 3+5*2 or (3+5)*2): ";
    getline(cin, infixExpression);

    string postfixExpression = infixToPostfix(infixExpression);

    if (postfixExpression.empty()) {
        cout << "\nConversion failed due to errors." << endl;
        return 1;
    }

    cout << "Postfix Expression: " << postfixExpression << endl;

    int result = evaluatePostfix(postfixExpression);

    cout << "Final Result: " << result << endl;


    return 0;
}
