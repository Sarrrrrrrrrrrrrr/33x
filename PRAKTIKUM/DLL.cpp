#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node* prev;
};

Node* head = NULL;

Node* createNode(string data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertLast(string data) {
    Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void deleteNode(string data) {
    if (head == NULL) return;

    Node* temp = head;


    if (temp != NULL && temp->data == data) {
        head = temp->next;
        delete temp;
        return;
    }

    Node* prev = NULL;
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    delete temp;
}

void printList() {
    if (head == NULL) {
        cout << "List kosong\n";
        return;
    }

    Node* temp = head;
    cout << "Isi List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void printreverse() {
    if (head == NULL) {
        cout << "list Kosong\n";
        return;
    }
    Node* temp = head;
    while (temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
}

int main() {
    int input = 0;
    string data;

    
    while (true) {
        cout << "\n--- MENU LINKED LIST ---\n";
        cout << "1. Tambah Data di Belakang (Insert Last)\n";
        cout << "2. Hapus Data (Delete)\n";
        cout << "3. Tampilkan Data\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        
        cin >> input; // 

        if (input == 1) {
            cout << "Masukkan data yang ingin ditambahkan di belakang: ";
            cin >> data;
            insertLast(data);
            printList();
        } 
        else if (input == 2) {
            cout << "Masukkan data yang ingin dihapus: ";
            cin >> data;
            deleteNode(data);
            printList();
        } 
        else if (input == 3) {
            printList();
        }
        else if (input == 4) {
            cout << "PrintReverse.\n";
            printreverse();
        }
        else if (input == 5) {
            cout << "Kelar dah tuh";
            break;
        }
        else {
            cout << "Pilihan tidak valid.\n";
        }
    }
    return 0;
}