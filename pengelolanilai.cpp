#include <iostream>
#include <string>

using namespace std;

const int max = 100;

void tampilkanDaftarNilai(){

}

void tampilanMenu(){

}

void tambahNilaiSiswa(string namaSiswa[], string mataPelajaran[], float nilaiSiswa[], int& jumlah){
    if(jumlah >= max){
        cout << "Daftar siswa sudah penuh" << endl;
        cout << "Sistem tidak dapat menerima data nilai siswa lagi" << endl;
        cout << "Maaf atas ketidakmampuan kami";
    }

    cin.ignore();
    cout << "Masukkan Nama Siswa : ";
    getline(cin, namaSiswa[jumlah]);
    cout << "Masukkan Mata Pelajaran : ";
    getline(cin, mataPelajaran[jumlah]);
    cout << "Masukkan Nilai Siswa : ";
    cin >> nilaiSiswa[jumlah];

    jumlah++;
    cout << "Data nilai siswa berhasil ditambahkan!" << endl;
}

void hapusNilaiSiswa(string namaSiswa[], string mataPelajaran[], float nilaiSiswa[], int& jumlah){
    if (jumlah == 0){
        cout << "Tidak ada data nilai siswa untuk dihapus" << endl;
        break;
    }

    int opsi;
    tampilkanDaftarNilai(namaSiswa, mataPelajaran, nilaiSiswa, jumlah);
    cout << "Masukkan nomor data siswa yang ingin dihapus : ";
    cin >> opsi;

    if(opsi > 0 && opsi <= jumlah){
        for (int i = opsi - 1; i < jumlah - 1; i--){
            namaSiswa[i] = namaSiswa[i + 1];
            mataPelajaran[i] = mataPelajaran[i + 1];
            nilaiSiswa[i] = nilaiSiswa[i + 1];
        }
        jumlah--;
        cout << "Data nilai siswa telah berhasil dihapus dari daftar!" << endl;
    }
    else {
        cout << "\t\t" << "== MAAF ==" << endl;
        cout << "Nomor yang anda masukkan tidak valid, atau" << endl;
        cout << "Data pada nomor yang anda masukkan tidak ada.";
    }
}

void updateNilaiMahasiswa(string namaSiswa[], string mataPelajaran[], float nilaiSiswa[], int jumlah){
    if(jumlah == 0){
        cout << "Tidak ada data nilai siswa untuk diupdate" << endl;
        break;
    }

    int opsi;
    tampilkanDaftarNilai(namaSiswa, mataPelajaran, nilaiSiswa, jumlah);
    cout << "Masukkan nomor data siswa yang ingin diupdate : ";
    cin >> opsi;

    if(opsi > 0 && opsi <= jumlah){
        cin.ignore();

        cout << "________________________________________________" << endl;
        cout << "|                                              |" << endl;
        cout << "|  Tekan Enter jika tidak ingin mengubah data  |" << endl;
        cout << "|______________________________________________|" << endl << endl;

        string baru;
        cout << "Masukkan Nama Siswa baru : ";
        getline(cin, baru);
        if(baru.length() != 0) namaSiswa[opsi - 1] = baru;

        cout << "Masukkan Mata Pelajaran baru : ";
        getline(cin, baru);
        if(baru.length() != 0) mataPelajaran[opsi - 1] = baru;

        float nilainew;
        cout << "Masukkan Nilai baru : ";
        if(cin.peek() != '\n'){
            cin >> nilainew;
            nilaiSiswa[opsi - 1] = nilainew;
        }
        cin.ignore();

        cout << "Data nilai siswa telah berhasil diperbarui!" << endl;
    }
    else {
        cout << "\t\t" << "== MAAF ==" << endl;
        cout << "Nomor yang anda masukkan tidak valid, atau" << endl;
        cout << "Data pada nomor yang anda masukkan tidak ada.";
        }
}

int main(){
  
}
