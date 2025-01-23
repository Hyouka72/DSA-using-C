#include <iostream>
#include <cstdlib>
using namespace std;

int top = -1;                                                                                      //Initialize Stack
int stack[100];                                                        

void push(int maxSize);                                                                            //Initialize push fucntion
void pop();                                                                                        //Initialize pop fucntion
void display();                                                                                    //Initialize display fucntion

int main() {
    int n, maxSize;
    cout << "Basic Operation of Stack" << endl;
    cout << "Enter the size of stack\n=>";
    cin >> maxSize;

    while (true) {
        cout << "\nEnter your choice\n 1 for push\n 2 for pop\n 3 for display\n 4 for exit\n\n=>";  //Menu for the operation
        cin >> n;
        switch (n) {
            case 1:                                                                                 //For push operation
                push(maxSize);
                cout << "Pushed" << endl;
                break;
            case 2:                                                                                 //For Pop Operation
                pop();
                cout << "Popped" << endl;
                break;
            case 3:                                                                                 //For Display Operation
                cout << "\nDisplay" << endl;
                display();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

void push(int maxSize) {
    int a;

    if (top == maxSize - 1) {
        cout << "Stack is full" << endl;
    } else {
        cout << "Enter the value to be pushed\n=>";
        cin >> a;
        top = top + 1;
        stack[top] = a;
    }
}

void pop() {
    if (top == -1) {
        cout << "Stack is underflow" << endl;
    } else {
        top = top - 1;
    }
}

void display() {
    if (top == -1) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "\nHere are the entered values:" << endl;
        for (int i = 0; i <= top; i++) {
            cout << "=>" << stack[i] << endl;
        }
    }
}
