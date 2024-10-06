#include <iostream>
#include <string>

using namespace std;

const int batas = 100;

void tampilkanDaftarNilai(const string namaSiswa[], const string mataPelajaran[], const float nilaiSiswa[], int jumlah) {
    if (jumlah == 0) {
        cout << "Tidak ada nilai siswa dalam daftar" << endl;
        return;
    }

    cout << "Daftar Nilai Siswa : " << endl << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << ". Nama: " << namaSiswa[i];
        cout << ", Mata Pelajaran: " << mataPelajaran[i];
        cout << ", Nilai: " << nilaiSiswa[i] << endl;
    }
    cout << endl;
}

void tampilkanMenu() {
    cout << endl << "===== Menu Pengelolaan Nilai Siswa =====" << endl;
    cout << "1. Tambah Nilai Siswa" << endl;
    cout << "2. Tampilkan Daftar Nilai Siswa" << endl;
    cout << "3. Hapus Nilai Siswa" << endl;
    cout << "4. Update Nilai Siswa" << endl;
    cout << "5. Keluar" << endl;
    cout << "========================================" << endl;
}

void tambahNilaiSiswa(string namaSiswa[], string mataPelajaran[], float nilaiSiswa[], int& jumlah){
    if(jumlah >= batas){
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
        return;
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

void updateNilaiSiswa(string namaSiswa[], string mataPelajaran[], float nilaiSiswa[], int jumlah){
    if(jumlah == 0){
        cout << "Tidak ada data nilai siswa untuk diupdate" << endl;
        return;
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
  string namaSiswa[batas];
  string mataPelajaran[batas];
  float nilaiSiswa[batas];
  int jumlahSiswa = 0;
  int pilihan;

  do {
      tampilkanMenu();
      cout<<"Pilih menu : ";
      cin>>pilihan;
      cout<<endl;

      switch (pilihan) {
          case 1 :
          tambahNilaiSiswa(namaSiswa, mataPelajaran, nilaiSiswa, jumlahSiswa);
          break;

          case 2 :
          tampilkanDaftarNilai(namaSiswa, mataPelajaran, nilaiSiswa, jumlahSiswa);
          break;

          case 3 :
          hapusNilaiSiswa(namaSiswa, mataPelajaran, nilaiSiswa, jumlahSiswa);
          break;

          case 4 :
          updateNilaiSiswa(namaSiswa, mataPelajaran, nilaiSiswa, jumlahSiswa);
          break;

          case 5 : 
          cout<<"Anda telah keluar dari program"<<endl;
          cout <<"Terima Kasih telah menggunakan program kami >_<"<<endl;
            break;

          default :
          cout<<"Pilihan tidak valid. Coba lagi."<<endl;
      }
  }while(pilihan != 5);

      return 0;
}
