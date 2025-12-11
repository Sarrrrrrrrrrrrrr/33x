

## 1. Nama, NIM, Kelas
- **Nama**: Abisar Fathir
- **NIM**: 103112400068
- **Kelas**: IF-12-05

## 2. Motivasi Belajar Struktur Data
Agar Saya bisa mengaplikasikan materi-materi struktur data ke game yang akan saya buat nanti

## 3. Dasar Teori
Array adalah struktur data yang menyimpan banyak elemen dengan tipe yang sama dan diakses melalui indeks. Untuk memudahkan pengolahan, program dipecah ke dalam fungsi atau prosedur agar lebih terstruktur dan mudah dipahami. Pointer adalah variabel yang menyimpan alamat memori dari variabel lain sehingga bisa mengakses dan mengubah nilai asli secara langsung. Dalam program stok buku, array menyimpan data awal, fungsi menghitung dan mencari stok terkecil, sedangkan pointer dipakai untuk mengembalikan alamat stok tersebut. Hasilnya, elemen terkecil bisa langsung diubah nilainya, membuktikan bahwa kombinasi array, fungsi, dan pointer membuat program lebih efisien.

## 4. Guided
### 4.1 Guided 1
[Program ini digunakan untuk menghitung nilai rata-rata dari nilai tugas dan UTS seorang siswa, menampilkan profil siswa, lalu memberikan tambahan bonus nilai sebesar 5 poin]  


bagian 1
#include <iostream>
using namespace std;
int bukuPerHari[7] = {2,1,3,2,4,5,1};
int totalBuku = 0;

Kita awali dengan memanggil library iostream dan menggunakan namespace std agar fungsi Input/Output (cout dan endl) bisa bekerja. Kemudian, kita mendeklarasikan data utama yaitu array bukuPerHari[7], yang bertipe integer untuk menyimpan 7 nilai (buku per hari). Terakhir, kita menyiapkan variabel penampung bernama totalBuku yang diinisialisasi nol; variabel ini siap menjadi akumulator untuk hasil akhir penjumlahan.

bagian 2

cout << "laporan baca buku mingguan:" << endl;

Kode cout digunakan untuk mencetak string "laporan baca buku mingguan:". Penggunaan endl di akhir memastikan ada newline sehingga laporan harian di bagian logika inti tidak tercampur dengan judul pembuka.

bagian 3

for(int i = 0; i < 7; i++)
cout << "hari ke -" << i + 1 << ":" << bukuPerHari[i] << " buku" << endl;
totalBuku += bukuPerHari[i];

disini codingan menggunakan perulangan for yang diatur untuk berjalan tepat 7 kali (dari indeks i=0 sampai i=6). Dalam setiap putaran loop, terjadi dua aksi utama:

1.Menampilkan Detail Harian

2.Akumulasi Total:

Proses ini akan berjalan terus menerus (iteratif) hingga seluruh data 7 hari selesai diproses. Setelah loop berakhir, variabel totalBuku sudah menyimpan total akhir dari semua buku yang dibaca.


## Lampiran Foto Laporan

Output :
![Output Image](image.png)

### 4.2 Guided 2

Bagian 1:

#include <iostream>
using namespace std;

int main() { 
    float hargaProduk = 50000.0f;

    float* ptrHarga;
    ptrHarga = &hargaProduk;

    cout << "Harga produk: " << hargaProduk << endl;
    cout << "Alamat harga produk: " << &hargaProduk << endl;

    [odingan yang ini adalah untuk mendeklarasikan variabel *hargaProduk* sebagai data awal dan ptrHarga sebagai pointer(ditandai dengan *) yang akan menampung memori alamat si hargaProduk]

Bagian 2

cout <<"\n...Memberikan diskon 10% melalui pointer..." << endl;
    *ptrHarga = *ptrHarga *0.9;

[Fokus kita ada pada baris *ptrHarga = *ptrHarga * 0.9;. Operator * di depan pointer disebut Dereference Operator. Ini berarti: "Akses lokasi memori yang ditunjuk oleh ptrHarga, dan ganti nilainya." Dengan operasi ini, kita berhasil menghitung diskon 10% dan langsung mengubah nilai di alamat memori hargaProduk secara tidak langsung.]

bagian 3

cout << "Harga setelah diskon: Rp" << hargaProduk << endl;
    return 0;
}

[Program akan menampilkan kembali nilai dari variabel hargaProduk melalui cout. Karena pointer sudah mengubah data di memori pada langkah sebelumnya, output yang ditampilkan adalah Rp45.000 (Rp50.000 dikurangi 10%). Ini membuktikan bahwa perubahan melalui pointer itu permanen pada variabel aslinya.]

Output: 
![Process Output](image-1.png)

### 4.3 Guided 3

bagian 1
[Bagian ini berisi fungsi yang tugasnya murni mengolah data dan mengembalikan hasil. ]

float hitungratarata(int nilaiTugas, int nilaiUTS) {
    return (nilaiTugas + nilaiUTS) / 2.0f;
}

[Fungsi ini menerima nilai tugas dan UTS sebagai salinan. Ia hanya menghitung rata-rata dan mengembalikan nilainya (return). Nilai asli tugas dan uts di main() tidak berubah.]


 bagian 2

 void beriNilaiBonus(float & nilai) {
    nilai += 5.0f; 

[Perhatikan simbol Ampersand (&) pada parameter float & nilai. Itu artinya fungsi ini menerima alamat memori dari variabel nilaiAkhir di main(). Ketika perintah nilai += 5.0f; dijalankan, ia langsung menembak ke alamat memori asli, sehingga nilai nilaiAkhir di main() langsung bertambah 5.0!]

bagian 3

void cetakProfil(string nama, float nilai) { ... }
}

[Fungsi sederhana ini bertugas menampilkan data nama dan nilai. Dipakai dua kali (sebelum dan sesudah bonus) untuk membandingkan hasilnya.]

bagian 4

int main() {
    // ... inisialisasi dan hitung nilaiAkhir
    cetakProfil(NamaSiswa, nilaiAkhir); // Tampilkan profil awal

    // Panggil Call by Reference, nilaiAkhir berubah permanen
    beriNilaiBonus(nilaiAkhir); 

    cetakProfil(NamaSiswa, nilaiAkhir); // Tampilkan profil akhir (nilai sudah bertambah)
    return 0;
}

[Bagian main() menunjukkan perbandingan: setelah memanggil beriNilaiBonus(nilaiAkhir), output nilaiAkhir yang dicetak kedua kalinya sudah menunjukkan nilai yang bertambah, membuktikan Call by Reference sukses memodifikasi data.]

Output:
![Output Process](image-2.png)
## 5. Unguided
### 5.1 Unguided 1
[ Codingan berisi jadi 3 bagian 

Bagian 1:
#include <iostream>
#include <string>
using namespace std;

void cetakStok(int arr[], int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ((i == size - 1) ? "" : " ,");
    }
    cout << " ]" << endl;
}

int hitungTotalStok(int arr[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

[void cetakStok(int arr[], int size): Tugasnya murni tampilan. Fungsi ini menerima array dan ukurannya, lalu menampilkan seluruh isinya dalam format yang rapi di konsol.

int hitungTotalStok(int arr[], int size): Tugasnya perhitungan. Fungsi ini menjumlahkan semua elemen array yang diterima, lalu mengembalikan nilai totalnya.]

Bagian 2:
int* cariStokPalingSedikit(int arr[], int size) {
    int* ptrPalingSedikit = &arr[0];
    
    for (int i = 1; i < size; i++) {
        if (arr[i] < *ptrPalingSedikit) {
            ptrPalingSedikit = &arr[i]; 
        }
    }
    return ptrPalingSedikit;
}

void tambahStokBonus(int* ptrStok) {
    *ptrStok += 10;
}

[int* cariStokPalingSedikit(int arr[], int size): Fungsi ini melakukan analisis alamat. Ia menggunakan pointer (int*) untuk menyisir array dan mencari elemen dengan nilai terkecil. Begitu ditemukan, ia mengembalikan alamat memori (&arr[i]) dari elemen tersebut ke main().

void tambahStokBonus(int* ptrStok): Fungsi ini melakukan modifikasi data. Ia menerima alamat dari stok terendah, lalu menggunakan Dereference Operator (*) pada *ptrStok += 10;. Ini berarti nilai di alamat memori asli (bukan salinan) langsung ditambah 10, membuat perubahan ini permanen pada array di main().]

Bagian 3:
   int main() 
    int stokBuku[] = {12, 8, 25, 5, 18};
    int jumlahJenisBuku = 5;

    cout << "Stok Buku Awal:" << endl;
    cetakStok(stokBuku, jumlahJenisBuku);

    int total = hitungTotalStok(stokBuku, jumlahJenisBuku);
    cout << "Total semua stok buku: " << total << endl;

    int* ptrStokRendah = cariStokPalingSedikit(stokBuku, jumlahJenisBuku);
    
    tambahStokBonus(ptrStokRendah); 

    cout << "\nStok Buku Setelah Penambahan Bonus:" << endl;
    cetakStok(stokBuku, jumlahJenisBuku);

    return 0;
[Program ini dimulai dengan membuat array stokBuku berisi data awal. Data tersebut pertama-tama dicetak dan dihitung totalnya. Setelah itu, program mencari elemen stok paling sedikit dan menyimpan alamatnya ke pointer. Alamat tersebut lalu dikirim ke fungsi untuk menambah bonus, sehingga nilai stok terkecil di array asli langsung berubah. Terakhir, array dicetak kembali dan terlihat bahwa hanya elemen terkecil yang berubah, membuktikan bahwa pointer bisa mengubah data secara langsung dan efisien.]

output:
[program output](image-3.png)
]


## 6. Kesimpulan
[ mempelajari bahwa pointer di C++ memberikan kontrol penuh atas memori. Ini memungkinkan kita untuk membuat fungsi yang efisien (tidak perlu menyalin data besar) dan melakukan modifikasi yang presisi pada data asli, yang merupakan keterampilan kunci dalam pemrograman sistem berkinerja tinggi.]

## 7. Referensi
Ramadhana, Ilmi, and Bambang Sujatmiko. "Pengembangan Aplikasi Kamus Bahasa Pemrograman C++ Berbasis Android Untuk Meningkatkan Kompetensi Kognitif Mata Kuliah Struktur Data." IT-Edu: Jurnal Information Technology and Education 3.1 (2018). https://doi.org/10.26740/it-edu.v3i1.24755

Anita Sindar, R. M. S. Struktur Data Dan Algoritma Dengan C++. Vol. 1. CV. AA. RIZKY, 2019. https://books.google.com/books?hl=id&lr=&id=GP_ADwAAQBAJ&oi=fnd&pg=PA23&dq=c%2B%2B+struktur+data&ots=86j8RlZQeV&sig=l0bNTnoJd9vDNJT69nmFF3c_GZA