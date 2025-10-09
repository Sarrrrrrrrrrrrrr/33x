#include <iostream>
using namespace std;

int main() {
    int bukuPerHari[7] = {2,1,3,2,4,5,1}; // Jumlah buku yang dibaca setiap hari dalam seminggu
    int totalBuku = 0;

    cout << "laporan baca buku mingguan:" << endl;

    for(int i = 0; i < 7; i++) {
        cout << "hari ke -" << i + 1 << ":" << bukuPerHari[i] << " buku" << endl;
        totalBuku += bukuPerHari[i];
    }
}