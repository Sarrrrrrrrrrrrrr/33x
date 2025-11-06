#include "stack.h" // Mengimpor header file stack.h yang berisi definisi struktur dan konstanta

using namespace std; // Menggunakan namespace standard untuk fungsi input/output

// fungsi untuk membuat stack baru dengan menginiaslisasi top = nil 
void CreateStack (Stack &S) {
    S.top = Nil; // Inisialisasi top dengan nilai Nil (biasanya - 1) untuk menandakan stack Kosong

}
// Fungsi untuk mengecke apakah stack kosong
bool isEmpty(Stack S) {
    return S.top == Nil; // Menembalikan true jika top bernilai Nil, Flase jika tidak
}

bool isFull(Stack S) {
    return S.top == MaxEl -1;  // Mengembalikan true jika top mencapai batas maksimum 
}

// Fungsi untuk menambah elemen ke dalam stack(push)
void push(Stack &S, infotype x) {   
    if (!isFull(S)) { // Cek apakah stack belum penuh
        S.top++;
    S.info[S.top] = x ;
 } else { 
    cout << "stack Penuh!" << endl; // Tampilkan pesan jika stack penuh
 }
} 

//fungsi untuk mengamil elemen teratas dari stack (pop)

infotype pop(Stack &S) {
 infotype x = -999; // inisialisasi nilai default jika stack kosong
 if (!isEmpty(S)) { 
    // cek apakah stack tidak kosong
    x = S.info[S.top];
    S.top--; 
 } else {
    cout << "stack Kosong!" << endl; //Tampilkan pesan jika stack kosong
 }
 return x; // kembalikan nilai yang diambil
}

void printInfo (Stack S) {
    if (isEmpty(S)) { // cek apakah kosong
cout << "stack Kosong" << endl; // Tampilkan pesan jika kosong
    } else { 
        cout << "[TOP]" ; // Tampilakn penanda posisi top
        for (int i = S.top; i >= 0; i--) { // Loop dari top sampai dasar stack
            cout << S.info[i] << " "; // tampilkan setiap elemen
        }
    }
}

void balikStack (Stack &S) {
    if (!isEmpty(S)) {
        Stack temp1, temp2;
        CreateStack(temp1); CreateStack(temp2); // Inisiasi kedua stack temporary

        while (!isEmpty(S)) {push(temp1 , pop(S));} //Pindahkan semua elemen ke temp1 (urutan terbalik)

        while (! isEmpty(temp1)) { push(S, pop(temp1));} //Pindahkan ke temp2 (urutan terbalik lagi)
        while (! isEmpty(temp2)) { push(S, pop(temp2));} // Kembalikan ke stack asal (urutan sudah benar)
    } 
}

