#include <iostream>
using namespace std;

int main() { 
    float hargaProduk = 50000.0f;

    float* ptrHarga ;
    ptrHarga = &hargaProduk;

    cout << "Harga produk: " << hargaProduk << endl;
    cout << "Alamat harga produk: " << &hargaProduk << endl;

    cout <<"\n...Memberikan diskon 10% melalui pointer..." << endl;
    *ptrHarga = *ptrHarga *0.9;
    cout << "Harga setelah diskon: Rp" << hargaProduk << endl;
    return 0;
}