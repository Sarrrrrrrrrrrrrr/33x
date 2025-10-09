#include <iostream>
#include <string>
using namespace std;

float hitungratarata(int nilaiTugas, int nilaiUTS) {
    return (nilaiTugas + nilaiUTS) / 2.0f;

}

void cetakProfil(string nama, float nilai) {
    cout << "Nama: " << nama << endl;
    cout << "Nilai: " << nilai << endl;


}

void beriNilaiBonus(float & nilai) {
    nilai += 5.0f; 
}

int main() {
    string NamaSiswa = "Budi";
    int tugas = 80, uts = 90;
    float nilaiAkhir = hitungratarata(tugas, uts);
    cout << "profil awal:" << endl;
    cetakProfil(NamaSiswa, nilaiAkhir);

    cout << "\n...memberikan nilai bonus..." << endl;
    beriNilaiBonus(nilaiAkhir);

    cout << "\nprofil setelah bonus:" << endl;
    cetakProfil(NamaSiswa, nilaiAkhir);

    return 0;

}