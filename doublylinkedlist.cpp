#include <iostream>
using namespace std;

// Define doubly linked list node
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Head pointer
Node* head = nullptr;

// Insert at beginning
void insertAtBeginning(int value) {
    Node* newNode = new Node{value, nullptr, head};
    if (head != nullptr)
        head->prev = newNode;
    head = newNode;
}

// Insert at end
void insertAtEnd(int value) {
    Node* newNode = new Node{value, nullptr, nullptr};

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at a specific position (1-based index)
void insertAtPosition(int value, int position) {
    if (position < 1) {
        cout << "Invalid position!\n";
        return;
    }

    if (position == 1) {
        insertAtBeginning(value);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Position out of bounds!\n";
        return;
    }

    Node* newNode = new Node{value, temp, temp->next};

    if (temp->next != nullptr)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Display the list
void displayList() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "Doubly Linked List (forward): ";
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Menu
void showMenu() {
    cout << "\n--- Doubly Linked List Menu ---\n";
    cout << "1. Insert at beginning\n";
    cout << "2. Insert at end\n";
    cout << "3. Insert at specific position\n";
    cout << "4. Display list\n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
}

// Main function
int main() {
    int choice, value, position;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value and position: ";
                cin >> value >> position;
                insertAtPosition(value, position);
                break;
            case 4:
                displayList();
                break;
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
