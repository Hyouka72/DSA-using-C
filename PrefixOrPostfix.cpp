#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

const int MAX = 100;

// Integer stack implementation
class IntStack {
    int data[MAX];
    int topIndex;
public:
    IntStack() { topIndex = -1; }

    void push(int x) { data[++topIndex] = x; }
    int pop() { return data[topIndex--]; }
    int top() { return data[topIndex]; }
    bool empty() { return topIndex == -1; }
};

// Function to perform arithmetic operations
int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b; // Assumes no divide by 0
        default: return 0;
    }
}

// Evaluate postfix expression (e.g., "23*5+")
int evaluatePostfix(const string& expr) {
    IntStack s;
    for (char c : expr) {
        if (c == ' ') continue;

        if (isdigit(c)) {
            s.push(c - '0');  // convert char to int
        } else {
            int b = s.pop();
            int a = s.pop();
            s.push(applyOp(a, b, c));
        }
    }
    return s.top();
}

// Evaluate prefix expression (e.g., "+*23 5")
int evaluatePrefix(const string& expr) {
    IntStack s;
    for (int i = expr.length() - 1; i >= 0; i--) {
        char c = expr[i];
        if (c == ' ') continue;

        if (isdigit(c)) {
            s.push(c - '0');
        } else {
            int a = s.pop();
            int b = s.pop();
            s.push(applyOp(a, b, c));
        }
    }
    return s.top();
}

// Main program
int main() {
    string expr;
    char choice;

    cout << "Enter expression (no spaces between digits and operators): ";
    cin >> expr;

    cout << "Is this (p)refix or (P)ostfix? (Enter 'p' or 'P'): ";
    cin >> choice;

    int result = 0;
    if (choice == 'P')
        result = evaluatePostfix(expr);
    else if (choice == 'p')
        result = evaluatePrefix(expr);
    else {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    cout << "Result: " << result << endl;
    return 0;
}
