#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Struktur data untuk menyimpan informasi dompet
struct Dompet {
    string pemilik;
    string pin;
    double saldo;
};

int main() {
    Dompet wallet;
    wallet.saldo = 0;
    vector<string> riwayat;

    cout << "Masukkan nama pemilik dompet: ";
    getline(cin, wallet.pemilik);

    cout << "Buat PIN untuk dompet Anda: ";
    getline(cin, wallet.pin);

    string inputPin;
    cout << "Masukkan PIN untuk akses dompet: ";
    getline(cin, inputPin);

    if (inputPin != wallet.pin) {
        cout << "PIN salah! Akses ditolak." << endl;
        return 0;
    }

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