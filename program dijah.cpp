#include <iostream>
#include <string>

using namespace std;

// Struktur untuk menyimpan informasi baju
struct Baju {
    string nama;
    float harga;
};

int main() {
    const int MAX_BAJU = 5;
    Baju daftarBaju[MAX_BAJU];

    // Mengisi informasi baju
    for (int i = 0; i < MAX_BAJU; ++i) {
        cout << "Masukkan nama baju ke-" << i + 1 << ": ";
        cin.ignore(); // Membersihkan buffer stdin
        getline(cin, daftarBaju[i].nama);
        cout << "Masukkan harga baju ke-" << i + 1 << ": ";
        cin >> daftarBaju[i].harga;
    }

    cout << "\n::::::::::::::::::::::::::::\n";
    cout << "\nSelamat datang di toko baju!\n";
    cout << "\n::::::::::::::::::::::::::::\n";

    int menu;
    do {
        cout << "\n===== Menu Toko Baju =====\n";
        cout << "1. Pilih Baju yang Dibeli\n";
        cout << "2. Tampilkan Semua Baju\n";
        cout << "3. Beli Baju\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu (1-4): ";
        cin >> menu;

        switch (menu) {
            case 1: // Pilih Baju yang Dibeli
                {
                    int nomorBaju;
                    cout << "Pilih nomor baju yang ingin dibeli: ";
                    cin >> nomorBaju;

                    if (nomorBaju >= 1 && nomorBaju <= MAX_BAJU) {
                        cout << "Anda memilih baju: " << daftarBaju[nomorBaju - 1].nama << endl;
                    } else {
                        cout << "Nomor baju tidak valid." << endl;
                    }
                }
                break;
            case 2: // Tampilkan Semua Baju
                cout << "\nDaftar Baju:\n";
                for (int i = 0; i < MAX_BAJU; ++i) {
                    cout << "Baju " << i + 1 << ": " << daftarBaju[i].nama << " - Harga: " << daftarBaju[i].harga << endl;
                }
                break;
            case 3: // Beli Baju
                {
                    int jumlahBeli;
                    float totalHarga = 0;
                    cout << "\nBerapa banyak baju yang ingin dibeli? ";
                    cin >> jumlahBeli;

                    for (int i = 0; i < jumlahBeli; ++i) {
                        int nomorBaju;
                        cout << "Pilih nomor baju yang ingin dibeli: ";
                        cin >> nomorBaju;

                        if (nomorBaju >= 1 && nomorBaju <= MAX_BAJU) {
                            totalHarga += daftarBaju[nomorBaju - 1].harga;
                            cout << "Baju " << nomorBaju << " telah ditambahkan ke keranjang." << endl;
                        } else {
                            cout << "Nomor baju tidak valid." << endl;
                            --i;
                        }
                    }

                    // Diskon baju
                    const float DISKON = 0.1;  // 10% diskon
                    if (totalHarga > 150) {
                        totalHarga *= (1 - DISKON);
                        cout << "\nAnda mendapatkan diskon 10%!" << endl;
                    } else {
                        cout << "\nTidak ada diskon karena tidak ." << endl;
                    }

                    // Menampilkan total harga setelah diskon
                    cout << "\nTotal harga setelah diskon: " << totalHarga << endl;
                }
                break;
            case 4: // Keluar
                cout << "Terima kasih! Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih kembali." << endl;
        }

    } while (menu != 4);

    return 0;
}
