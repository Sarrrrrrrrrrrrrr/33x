#include <iostream>

using namespace std;

typedef int infotype;

struct Node {
    infotype data;
    Node* prev;
    Node* next;
};

struct List {
    Node* first;
    Node* last;
};

void createList(List &L);
bool isEmpty(List L);
Node* allocateNode(infotype data);
void insertFirst(List &L, Node* newNode);
void insertLast(List &L, Node* newNode);
void printForward(List L);
void printBackward(List L);
int countElements(List L);

void smartInsert(List &L, infotype data);
void conditionalDelete(List &L);
int deleteByValue(List &L, infotype value);
void deleteAll(List &L);

void deleteFirst(List &L);
void deleteLast(List &L);
void insertAfter(Node* prevNode, Node* newNode);


void createList(List &L) {
    L.first = nullptr;
    L.last = nullptr;
}

bool isEmpty(List L) {
    return L.first == nullptr;
}

Node* allocateNode(infotype data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void insertFirst(List &L, Node* newNode) {
    if (isEmpty(L)) {
        L.first = newNode;
        L.last = newNode;
    } else {
        newNode->next = L.first;
        L.first->prev = newNode;
        L.first = newNode;
    }
}

void insertLast(List &L, Node* newNode) {
    if (isEmpty(L)) {
        insertFirst(L, newNode);
    } else {
        newNode->prev = L.last;
        L.last->next = newNode;
        L.last = newNode;
    }
}

void insertAfter(Node* prevNode, Node* newNode) {
    if (prevNode != nullptr) {
        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        if (prevNode->next != nullptr) {
            prevNode->next->prev = newNode;
        }
        prevNode->next = newNode;
    }
}

void deleteFirst(List &L) {
    if (!isEmpty(L)) {
        Node* delNode = L.first;
        if (L.first == L.last) {
            L.first = nullptr;
            L.last = nullptr;
        } else {
            L.first = L.first->next;
            L.first->prev = nullptr;
        }
        delete delNode;
    }
}

void deleteLast(List &L) {
    if (!isEmpty(L)) {
        Node* delNode = L.last;
        if (L.first == L.last) {
            deleteFirst(L);
        } else {
            L.last = L.last->prev;
            L.last->next = nullptr;
            delete delNode;
        }
    }
}

void printForward(List L) {
    Node* current = L.first;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void printBackward(List L) {
    Node* current = L.last;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}

int countElements(List L) {
    int count = 0;
    Node* current = L.first;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}


void smartInsert(List &L, infotype data) {
    Node* newNode = allocateNode(data);
    
    if (isEmpty(L)) {
        insertFirst(L, newNode);
        cout << "Smart Insert: List kosong, insert " << data << " di first" << endl;
        return;
    }
    
    if (data % 2 != 0 && data < 5) {
        insertFirst(L, newNode);
        cout << "Smart Insert: " << data << " < 5, insert di first" << endl;
        return;
    }
    
    if (data % 2 == 0) {
        insertLast(L, newNode);
        cout << "Smart Insert: " << data << " genap, insert di last" << endl;
        return;
    }

    if (data % 2 != 0 && data >= 5) {
        Node* current = L.first;

        while (current != nullptr) {
            if (current->data == 5 && current->next != nullptr && current->next->data == 7) {
                 insertAfter(current, newNode);
                 cout << "Smart Insert: " << data << " di antara 5 dan 7" << endl;
                 return;
            }
            current = current->next;
        }
        
        insertLast(L, newNode);
        cout << "Smart Insert: " << data << " ganjil >= 5, posisi khusus tidak ditemukan, insert di last" << endl;
        return;
    }
}

void conditionalDelete(List &L) {
    Node* current = L.first;
    Node* temp = nullptr;
    int count = 0;
    
    while (current != nullptr) {
        if (current->data % 2 != 0) {
            count++;
            
            if (current == L.first) {
                temp = current->next;
                deleteFirst(L);
                current = temp;
                continue;
            } 
            
            if (current == L.last) {
                deleteLast(L);
                current = nullptr;
                break;
            }
            
            current->prev->next = current->next;
            current->next->prev = current->prev;
            temp = current->next;
            delete current;
            current = temp;

        } else {
            current = current->next;
        }
    }
    
    cout << "Conditional Delete: " << count << " elemen ganjil dihapus" << endl;
}

int deleteByValue(List &L, infotype value) {
    Node* current = L.first;
    Node* temp = nullptr;
    int count = 0;
    
    while (current != nullptr) {
        if (current->data == value) {
            count++;
            
            if (current == L.first) {
                temp = current->next;
                deleteFirst(L);
                current = temp;
                continue;
            }
            if (current == L.last) {
                deleteLast(L);
                current = nullptr;
                break;
            }
            
            current->prev->next = current->next;
            current->next->prev = current->prev;
            temp = current->next;
            delete current;
            current = temp;
        } else {
            current = current->next;
        }
    }
    return count;
}

void deleteAll(List &L) {
    Node* current = L.first;
    Node* temp = nullptr;
    int count = countElements(L);
    
    while (current != nullptr) {
        temp = current->next;
        delete current;
        current = temp;
    }
    L.first = nullptr;
    L.last = nullptr;
    
    cout << "Semua elemen (" << count << ") berhasil dihapus" << endl;
}


int main() {
    List L;
    createList(L);

    cout << "ADVANCED OPERATIONS" << endl;
    cout << "========================================" << endl;

    // --- SMART INSERT DEMO ---
    cout << "SMART INSERT DEMO" << endl;
    
    smartInsert(L, 5); 
    smartInsert(L, 3); 
    smartInsert(L, 8); 
    smartInsert(L, 6); 
    smartInsert(L, 4); 
    smartInsert(L, 7); 
    
    cout << "\nHasil Smart Insert:" << endl;
    cout << "Forward: ";
    printForward(L);
    cout << "Backward: ";
    printBackward(L);
    
    cout << "----------------------------------------" << endl;

    // --- CONDITIONAL DELETE DEMO ---
    cout << "CONDITIONAL DELETE DEMO" << endl;
    cout << "Sebelum Conditional Delete: ";
    printForward(L);
    
    conditionalDelete(L);
    
    cout << "Setelah Conditional Delete: ";
    printForward(L);
    
    cout << "----------------------------------------" << endl;

    // --- DELETE BY VALUE DEMO ---
    cout << "DELETE BY VALUE DEMO" << endl;
    
    insertLast(L, allocateNode(6));
    
    int deletedCount = deleteByValue(L, 6);
    cout << "Nilai 6 berhasil dihapus. Jumlah: " << deletedCount << endl;
    
    deletedCount = deleteByValue(L, 10);
    if (deletedCount == 0) {
        cout << "Nilai 10 tidak ditemukan" << endl;
    }
    
    cout << "List akhir: ";
    printForward(L);
    
    cout << "----------------------------------------" << endl;

 
    cout << "DELETE ALL DEMO" << endl;
    
    deleteAll(L);
    
    cout << "List setelah Delete All: ";
    printForward(L);

    return 0;
}