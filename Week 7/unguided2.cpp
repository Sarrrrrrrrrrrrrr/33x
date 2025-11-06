#include <iostream>

using namespace std;

#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack {
    infotype info[MaxEl];
    int top;
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
void deleteByValue(Stack &S, infotype x);
void deleteAll(Stack &S);

void CreateStack (Stack &S) {
    S.top = Nil;
}

bool isEmpty(Stack S) {
    return S.top == Nil;
}

bool isFull(Stack S) {
    return S.top == MaxEl -1;
}

void push(Stack &S, infotype x) {   
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x ;
    }
} 

infotype pop(Stack &S) {
    infotype x = -999;
    if (!isEmpty(S)) { 
        x = S.info[S.top];
        S.top--; 
    }
    return x;
}

void printInfo (Stack S) {
    if (isEmpty(S)) {
        cout << "stack Kosong" << endl;
    } else { 
        cout << "[TOP] " ;
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack (Stack &S) {
    if (!isEmpty(S)) {
        Stack temp1; 
        CreateStack(temp1); 

        while (!isEmpty(S)) {push(temp1 , pop(S));} 

        while (! isEmpty(temp1)) { push(S, pop(temp1));} 
    } 
}

void pushAscending(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack Penuh, elemen " << x << " gagal dimasukkan." << endl;
        return;
    }
    
    Stack temp;
    CreateStack(temp);

    while (!isEmpty(S) && S.info[S.top] > x) {
        push(temp, pop(S));
    }

    push(S, x);

    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}

void deleteByValue(Stack &S, infotype x) {
    if (isEmpty(S)) {
        cout << "Stack Kosong. Penghapusan gagal." << endl;
        return;
    }

    Stack temp;
    CreateStack(temp);
    bool found = false;

    while (!isEmpty(S)) {
        infotype current = pop(S);
        if (current == x && !found) {
            found = true;
        } else {
            push(temp, current);
        }
    }

    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }

    if (found) {
        cout << "Nilai " << x << " berhasil dihapus" << endl;
    } else {
        cout << "Nilai " << x << " tidak ditemukan" << endl;
    }
}

void deleteAll(Stack &S) {
    int count = 0;
    while (!isEmpty(S)) {
        pop(S);
        count++;
    }
    cout << "Semua elemen (" << count << ") berhasil dihapus" << endl;
}

void makeInitialList(Stack &S) {
    CreateStack(S);
    push(S, 1);
    push(S, 2);
    push(S, 3);
    push(S, 2);
}

int main() {
    // --- Bagian 1: Uji coba fungsi awal dan Balik Stack ---
    cout << "Hello World" << endl;
    Stack S_init; 
    CreateStack(S_init);
    push(S_init, 3); 
    push(S_init, 4); 
    push(S_init, 8); 
    pop(S_init); 
    push(S_init, 2); 
    push(S_init, 3); 
    pop(S_init); 
    push(S_init, 9); 
    cout << "Stack S_init setelah operasi awal: ";
    printInfo(S_init);

    cout << "Balik stack S_init:" << endl;
    balikStack(S_init);
    printInfo(S_init);

    // --- Bagian 2: TASK 1: DELETE OPERATIONS (Sesuai Permintaan Gambar) ---
    Stack S_Delete;
    cout << "\nTASK 1: DELETE OPERATIONS" << endl;
    cout << "---------------------------------" << endl;

    makeInitialList(S_Delete);
    cout << "List awal: "; 
    printInfo(S_Delete); 

    deleteByValue(S_Delete, 2);
    cout << "Setelah deleteByValue(2): "; 
    printInfo(S_Delete); 

    deleteByValue(S_Delete, 5);
    cout << "List tetap: ";
    printInfo(S_Delete); 

    push(S_Delete, 4);
    push(S_Delete, 5);
    cout << "List setelah tambah data: ";
    printInfo(S_Delete);
    
    deleteAll(S_Delete);
    cout << "Setelah deleteAll: ";
    printInfo(S_Delete); 
    cout << "---------------------------------" << endl;

  
    Stack S_Asc;
    CreateStack(S_Asc);
    
    cout << "\nStack Ascending Test (Unguided 5.2):" << endl;
    pushAscending(S_Asc, 3);
    pushAscending(S_Asc, 4);
    pushAscending(S_Asc, 8);
    pushAscending(S_Asc, 2);
    pushAscending(S_Asc, 3);
    pushAscending(S_Asc, 9);

    cout << "Stack ascending (TOP -> bottom):" << endl;
    printInfo(S_Asc);
    
    return 0;
}