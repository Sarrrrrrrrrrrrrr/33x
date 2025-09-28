#include <iostream>
#include <string>
using namespace std;

string angkaKeTulisan(int n) {
    string angka[] = {"nol", "satu", "dua", "tiga", "empat", "lima",
                      "enam", "tujuh", "delapan", "sembilan", "sepuluh", "sebelas"};

    if (n < 12) {
        return angka[n];
    } else if (n < 20) {
        return angka[n - 10] + " belas";
    } else if (n < 100) {
        int puluh = n / 10;
        int satuan = n % 10;
        string teks = angka[puluh] + " puluh";
        if (satuan > 0) teks += " " + angka[satuan];
        return teks;
    } else if (n == 100) {
        return "seratus";
    }
    return "di luar jangkauan";
}

int main() {
    int x;
    cout << "Masukkan angka (0-100): ";
    cin >> x;

    cout << x << " : " << angkaKeTulisan(x) << endl;
    return 0;
}
