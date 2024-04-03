//Irshad Benaya Fardeca
//2311102199


#include <iostream>
using namespace std;

struct Node {
    string produk;
    float harga;
    Node* prev;
    Node* next;
};

class linkedList {
private:
    Node* head;
    Node* tail;
public:
    linkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void tambahData(string nama, float harga) {
        Node* baru = new Node;
        baru->produk = nama;
        baru->harga = harga;
        baru->prev = nullptr;
        baru->next = nullptr;

        if (head == nullptr) {
            head = tail = baru;
        } else {
            tail->next = baru;
            baru->prev = tail;
            tail = baru;
        }
    }

    void hapusData(string nama) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->produk == nama) {
                if (temp == head && temp == tail) {
                    head = tail = nullptr;
                } else if (temp == head) {
                    head = head->next;
                    head->prev = nullptr;
                } else if (temp == tail) {
                    tail = tail->prev;
                    tail->next = nullptr;
                } else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                delete temp;
                return;
            }
            temp = temp->next;
        }
        cout << "Produk tidak ditemukan!" << endl;
    }

    void update(string nama, string namaBaru, float hargaBaru) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->produk == nama) {
                temp->produk = namaBaru;
                temp->harga = hargaBaru;
                return;
            }
            temp = temp->next;
        }
        cout << "Produk tidak ditemukan!" << endl;
    }

    void tambahDataTertentu(string nama, float harga, string produkBaru) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->produk == produkBaru) {
                Node* baru = new Node;
                baru->produk = nama;
                baru->harga = harga;
                baru->prev = temp;
                baru->next = temp->next;
                if (temp->next != nullptr) {
                    temp->next->prev = baru;
                }
                temp->next = baru;
                return;
            }
            temp = temp->next;
        }
        cout << "Produk tidak ditemukan!" << endl;
    }

    void hapusDataTertentu(string nama) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->produk == nama) {
                if (temp == head) {
                    head = head->next;
                    head->prev = nullptr;
                } else if (temp == tail) {
                    tail = tail->prev;
                    tail->next = nullptr;
                } else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                delete temp;
                return;
            }
            temp = temp->next;
        }
        cout << "Produk tidak ditemukan!" << endl;
    }

    void hapusSeluruhData() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* temp = temp;
            temp = temp->next;
            delete temp;
        }
        head = tail = nullptr;
    }

    void tampilkanData() {
        Node* temp = head;
        cout << "Nama Produk  ||\t Harga " << endl;
        while (temp != nullptr) {
            cout << temp->produk << "\t" << temp->harga << endl;
            temp = temp->next;
        }
    }
};

int main() {
    linkedList list;
    list.tambahData("Originote", 60000);
    list.tambahData("Somethinc", 150000);
    list.tambahData("Skintific", 100000);
    list.tambahData("Wardah", 50000);
    list.tambahData("Hanasui", 30000);

    int pilihan;
    string nama, namaBaru, produkBaru;
    float harga, hargaBaru;

    do {
        cout << "Toko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        cout << "Pilih nomor: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Nama Produk: ";
                cin >> nama;
                cout << "Harga: ";
                cin >> harga;
                list.tambahData(nama, harga);
                list.tampilkanData();
                break;
            case 2:
                cout << "Nama Produk yang akan dihapus: ";
                cin >> nama;
                list.hapusData(nama);
                list.tampilkanData();
                break;
            case 3:
                cout << "Nama Produk yang akan diupdate: ";
                cin >> nama;
                cout << "Nama Baru: ";
                cin >> namaBaru;
                cout << "Harga Baru: ";
                cin >> hargaBaru;
                list.update(nama, namaBaru, hargaBaru);
                list.tampilkanData();
                break;
            case 4:
                cout << "Nama Produk: ";
                cin >> nama;
                cout << "Harga: ";
                cin >> harga;
                cout << "Setelah Produk: ";
                cin >> produkBaru;
                list.tambahDataTertentu(nama, harga, produkBaru);
                list.tampilkanData();
                break;
            case 5:
                cout << "Nama Produk yang akan dihapus: ";
                cin >> nama;
                list.hapusDataTertentu(nama);
                list.tampilkanData();
                break;
            case 6:
                list.hapusSeluruhData();
                cout << "Seluruh data telah dihapus." << endl;
                break;
            case 7:
                list.tampilkanData();
                break;
            case 8:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 8);

    return 0;
}