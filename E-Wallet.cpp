#include <iostream>  //Memasukkan library iostream untuk input output
#include <string>    //Memasukkan library string untuk menggunakan tipe data string
#include <vector>    //Agar bisa menggunakan vector, yaitu daftar dinamis untuk riwayat transfer
#include <iomanip>   //Agar bisa mengatur tampilan angka, seperti 2 angka di belakang koma
using namespace std; //Agar tidak usah menulis std:: setiap di depan cout dan cin

// Struktur data untuk menyimpan informasi dompet
struct Dompet {     //Membuat struct bernama Dompet
    string pemilik; //Membuat isi struct bernama pemilik dengan tipe data string
    string pin;     //Mmebuat isi struct bernama pin dengan tipe data string
    double saldo;   //Membuat isi struct bernama saldo dengan tipe data double
};                  //Menutup struktur struct bernama Dompet

int main() {                  //Membuat fungsi utama
    Dompet wallet;            //Membuat objek wallet dari struct dompet
    wallet.saldo = 0;         //Membuat saldo menjadi 0
    vector<string> riwayat;   //Membuat vector atau daftar kosong bernama riwayat untuk riwayat transfer

    cout << "Masukkan nama pemilik dompet: "; //Mencetak output "Masukkan nama pemilik dompet
    getline(cin, wallet.pemilik);             //Mengambil dan membaca input dari user

    cout << "Buat PIN untuk dompet Anda: ";   //Mencetak output "Buat PIN untuk dompet anda
    getline(cin, wallet.pin);                 //Mengambil dan membaca input dari user

    string inputPin;                              //Membuat variabel inputPin untuk menyimpan PIN yang akan di masukkan
    cout << "Masukkan PIN untuk akses dompet: ";  //Mencetak output "Masukkan PIN untuk akses dompet"
    getline(cin, inputPin);                       //Mengambil dan membaca input pin dari user

    if (inputPin != wallet.pin) {                      //Jika PIN yang di masukkan bukan/tidak sama dengan PIN yang sudah di simpan maka:
        cout << "PIN salah! Akses ditolak." << endl;   //Mencetak output "PIN salah! Akses ditolak: 
        return 0;                                      //Mengakhiri program
    }                                                  //Menutup blok if

    int pilihan;
    do {
        cout << "\n=== APLIKASI DOMPET DIGITAL ===" << endl;
        cout << "1. Lihat Saldo" << endl;
        cout << "2. Tambah Saldo (Deposit)" << endl;
        cout << "3. Kurangi Saldo (Tarik)" << endl;
        cout << "4. Transfer" << endl;
        cout << "5. Lihat Riwayat Transfer" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih (1-6): ";
        cin >> pilihan;
        cin.ignore();

        cout << fixed << setprecision(2); // Format saldo

        if (pilihan == 1) {
            cout << "\nSaldo Anda saat ini: Rp" << wallet.saldo << endl;
        } 
        else if (pilihan == 2) {
            double tambah;
            cout << "Masukkan jumlah yang ingin ditambah: Rp";
            cin >> tambah;
            if (tambah < 0) {
                cout << "Jumlah tidak boleh negatif!" << endl;
            } else {
                wallet.saldo += tambah;
                cout << "Saldo berhasil ditambah!" << endl;
            }
        } 
        else if (pilihan == 3) {
            double tarik;
            cout << "Masukkan jumlah yang ingin ditarik: Rp";
            cin >> tarik;
            if (tarik < 0) {
                cout << "Jumlah tidak boleh negatif!" << endl;
            } else if (tarik > wallet.saldo) {
                cout << "Saldo tidak mencukupi!" << endl;
            } else {
                wallet.saldo -= tarik;
                cout << "Penarikan berhasil!" << endl;
            }
        } 
        else if (pilihan == 4) {
            string penerima;
            double jumlah;
            cin.ignore();
            cout << "Masukkan nama penerima: ";
            getline(cin, penerima);
            cout << "Masukkan jumlah transfer: Rp";
            cin >> jumlah;

            if (jumlah < 0) {
                cout << "Jumlah tidak boleh negatif!" << endl;
            } else if (jumlah > wallet.saldo) {
                cout << "Saldo tidak mencukupi untuk transfer!" << endl;
            } else {
                wallet.saldo -= jumlah;
                cout << "Transfer ke " << penerima << " sebesar Rp" << jumlah << " berhasil!" << endl;
                riwayat.push_back("Transfer ke " + penerima + " sebesar Rp" + to_string(jumlah));
            }
        } 
        else if (pilihan == 5) {
            if (riwayat.empty()) {
                cout << "Belum ada riwayat transfer." << endl;
            } else {
                cout << "\n=== Riwayat Transfer ===" << endl;
                for (const string& r : riwayat) {
                    cout << "- " << r << endl;
                }
            }
        } 
        else if (pilihan == 6) {
            cout << "Terima kasih telah menggunakan Dompet Digital!" << endl;
        } 
        else {
            cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 6);

    return 0;
}
