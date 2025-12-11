[UJIAN TENGAH SEMESTER
PRAKTIKUM STRUKTUR DATA
CLO 3]

Identitas Pengumpul

Nama: [Abisar Fathir]

NIM: [103112400068]

Kelas: [12-05-01]

1. Kode Program

Berikut adalah kode program untuk [Mengurutkan dan menambahkan nomor dari belakang].

(Silakan ganti bahasa dan kode di bawah ini sesuai tugas Anda)

```File: Dll.cpp
#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
Memanggil Var data, next, prev dan head.
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

2. Penjelasan Kode
Void insertlast(int data) {
 kode didalam insertLast  if (head == NULL) {
        head = newNode;
        return;
    } Kode berikut mengecek apakah list sudah ada isinya atau belum{

    } Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
        
    }
    temp->next = newNode;
} Dan di kode Berikut jika List isinya dan tidak null maka temp akan menunjuk next sebagai NewNode yang akan dijadikan Head sebagai list data paling belakang{

}


void deleteNode(int data) {
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
}Seperti namanya DeleteNode disini digunakan Untuk melakukan Delete jika list data kosong maka akan menjadi null{

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
Cout << akan menampilkan data list dengan menunjuk data yang ditunjukk temp

3. Output Program

Berikut adalah hasil eksekusi program (output) ketika dijalankan.
```
Contoh Output 1 (Input Bilangan Genap):

===== Program Pengecek Ganjil/Genap =====
Masukkan sebuah bilangan bulat: 42
42 adalah bilangan GENAP.


Contoh Output 2 (Input Bilangan Ganjil):

===== Program Pengecek Ganjil/Genap =====
Masukkan sebuah bilangan bulat: 77
77 adalah bilangan GANJIL.


(Tips: Anda juga bisa menyertakan screenshot/gambar output di bagian ini jika diperlukan, seperti ini:)
```

4. Penjelasan Lanjutan (Analisis Output)

Sesuai permintaan Anda ("Penjelasan Lagi"), bagian ini menganalisis mengapa output yang dihasilkan sudah benar:

Pada Output 1: User memasukkan 42. Ketika 42 dibagi 2, sisa baginya adalah 0 ($42 \div 2 = 21$ sisa $0$). Karena sisa baginya 0, kondisi if (angka % 2 == 0) terpenuhi (True), sehingga program mencetak "adalah bilangan GENAP".

Pada Output 2: User memasukkan 77. Ketika 77 dibagi 2, sisa baginya adalah 1 ($77 \div 2 = 38$ sisa $1$). Karena sisa baginya bukan 0, kondisi if tidak terpenuhi, dan program menjalankan blok else, sehingga mencetak "adalah bilangan GANJIL".

Kedua kasus uji (test case) tersebut menunjukkan bahwa logika operator modulus (%) telah diimplementasikan dengan benar untuk membedakan bilangan ganjil dan genap.

5. Kesimpulan

Berdasarkan implementasi dan pengujian kode di atas, dapat disimpulkan bahwa:

Konsep percabangan (selection) menggunakan if-else sangat fundamental untuk membuat program yang dapat mengambil keputusan berdasarkan kondisi tertentu.

Operator Aritmetika Modulus (%) adalah alat yang efektif untuk menentukan keterbagian, yang dalam kasus ini digunakan untuk memvalidasi apakah suatu bilangan ganjil atau genap berdasarkan sisa baginya dengan 2.

Program telah berhasil memenuhi spesifikasi tugas, yaitu menerima input dari user dan memberikan output yang benar sesuai dengan status ganjil/genap dari input tersebut.
