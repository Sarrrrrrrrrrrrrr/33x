#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertLast(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            newNode->prev = nullptr;
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertBefore(int beforeValue, int newValue) {
        if (head == nullptr) {
            cout << "List kosong!" << endl;
            return;
        }

        Node* current = head;
        
        while (current != nullptr && current->data != beforeValue) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Elemen " << beforeValue << " tidak ditemukan!" << endl;
            return;
        }
        
        Node* newNode = new Node();
        newNode->data = newValue;

        if (current == head) {
            newNode->prev = nullptr;
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else {
            newNode->prev = current->prev;
            newNode->next = current;
            current->prev->next = newNode;
            current->prev = newNode;
        }
    }

    void printForward() {
        if (head == nullptr) {
            cout << "List kosong!" << endl;
            return;
        }

        Node* current = head;
        cout << "NULL <-> ";
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << " <-> ";
            }
            current = current->next;
        }
        cout << " <-> NULL" << endl;
    }

    void printReverse() {
        if (tail == nullptr) {
            cout << "List kosong!" << endl;
            return;
        }

        Node* current = tail;
        cout << "NULL <-> ";
        while (current != nullptr) {
            cout << current->data;
            if (current->prev != nullptr) {
                cout << " <-> ";
            }
            current = current->prev;
        }
        cout << " <-> NULL" << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insertLast(10);
    dll.insertLast(20);
    dll.insertLast(30);
    dll.insertLast(40);

    cout << "List Forward:" << endl;
    dll.printForward();
    cout << "\nList Reverse:" << endl;
    dll.printReverse();

    cout << "\nInsert 15 sebelum 20:" << endl;
    dll.insertBefore(20, 15);
    dll.printForward();
    dll.printReverse();

    cout << "\nInsert 5 sebelum 10:" << endl;
    dll.insertBefore(10, 5);
    dll.printForward();
    dll.printReverse();

    cout << "\nInsert 35 sebelum 40:" << endl;
    dll.insertBefore(40, 35);
    dll.printForward();
    dll.printReverse();

    return 0;
}