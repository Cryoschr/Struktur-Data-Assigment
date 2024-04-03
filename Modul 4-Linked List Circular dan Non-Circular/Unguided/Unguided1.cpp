//Irshad Benaya Fardeca
//2311102199

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    string nim;
    Node* next;
};

class circularLinkedList {
private:
    Node* head;

public:
    circularLinkedList() {
        head = nullptr;
    }

    // Menambahkan di depan
    void tambahDepan(string nama, string nim) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->nim = nim;

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            newNode->next = head;
            last->next = newNode;
            head = newNode;
        }
        cout << "Node berhasil ditambahkan" << endl;
    }

    // Menambahkan di belakang
    void tambahBelakang(string nama, string nim) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->nim = nim;

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            last->next = newNode;
            newNode->next = head;
        }
        cout << "Node berhasil ditambahkan" << endl;
    }

    // Menambahkan di tengah
    void tambahTengah(string nama, string nim, int posisi) {
        if (posisi <= 0) {
            cout << "Bukan posisi tengah" << endl;
            return;
        }
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->nim = nim;

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            cout << "Node berhasil ditambahkan" << endl;
            return;
        }

        Node* tail = head;
        int count = 1;
        while (count < posisi - 1 && tail->next != head) {
            tail = tail->next;
            count++;
        }

        if (count < posisi - 1) {
            cout << "Bukan posisi tengah" << endl;
            return;
        }

        newNode->next = tail->next;
        tail->next = newNode;
        cout << "Node berhasil ditambahkan" << endl;
    }

    // Ubah data di depan
    void ubahDepan(string nama, string nim) {
        if (head == nullptr) {
            cout << "List Kosong" << endl;
            return;
        }
        head->nama = nama;
        head->nim = nim;
        cout << "Data berhasil diubah" << endl;
    }

    // Ubah data di belakang
    void ubahBelakang(string nama, string nim) {
        if (head == nullptr) {
            cout << "List Kosong" << endl;
            return;
        }
        Node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        tail->nama = nama;
        tail->nim = nim;
        cout << "Data berhasil diubah." << endl;
    }

    // Ubah data di tengah
    void ubahTengah(string nama, string nim, int posisi) {
        if (head == nullptr) {
            cout << "List Kosong" << endl;
            return;
        }
        Node* tail = head;
        int count = 1;
        while (count < posisi && tail->next != head) {
            tail = tail->next;
            count++;
        }
        if (count != posisi) {
            cout << "Bukan posisi tengah" << endl;
            return;
        }
        tail->nama = nama;
        tail->nim = nim;
        cout << "Data di posisi " << posisi << " berhasil diubah" << endl;
    }

    // Hapus data di depan
    void hapusDepan() {
        if (head == nullptr) {
            cout << "List Kosong" << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }
            Node* del = head;
            head = head->next;
            tail->next = head;
            delete del;
        }
        cout << "Data berhasil dihapus" << endl;
    }

    // Hapus data di belakang
    void hapusBelakang() {
        if (head == nullptr) {
            cout << "List Kosong" << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* tail = head;
            Node* prev = nullptr;
            while (tail->next != head) {
                prev = tail;
                tail = tail->next;
            }
            prev->next = head;
            delete tail;
        }
        cout << "Data berhasil dihapus" << endl;
    }

    // Hapus data di tengah
    void hapusTengah(int posisi) {
        if (head == nullptr) {
            cout << "List Kosong." << endl;
            return;
        }
        if (posisi <= 0) {
            cout << "Bukan posisi tengah" << endl;
            return;
        }
        Node* tail = head;
        Node* prev = nullptr;
        int count = 1;
        while (count < posisi && tail->next != head) {
            prev = tail;
            tail = tail->next;
            count++;
        }
        if (count != posisi) {
            cout << "Bukan posisi tengah" << endl;
            return;
        }
        if (tail == head) {
            hapusDepan();
            return;
        }
        prev->next = tail->next;
        delete tail;
        cout << "Data di posisi " << posisi << " berhasil dihapus" << endl;
    }

    // Hapus semua data
    void hapusSemua() {
        if (head == nullptr) {
            cout << "List Kosong" << endl;
            return;
        }
        Node* current = head;
        Node* next = nullptr;
        while (current->next != head) {
            next = current->next;
            delete current;
            current = next;
        }
        delete current;
        head = nullptr;
        cout << "Semua datan berhasil dihapus" << endl;
    }

    // Menampilkan
    void menampilkan() {
        if (head == nullptr) {
            cout << "List Kosong." << endl;
            return;
        }
        Node* tail = head;
        cout << "Nama" << "     " << "NIM" << endl;
        do {
            cout << tail->nama << tail->nim << endl;
            tail = tail->next;
        } while (tail != head);
    }
};

int main() {
    circularLinkedList list;
    int pilih;
    string nama, nim;
    int posisi;

    do {
        cout<< endl;
        cout << "PROGRAM SINGLE LINKED LIST CIRCULAR" << endl;
        cout << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl;
        cout << "11. Tampilkan Data" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih Operasi: ";
        cin >> pilih;
        cout<< endl;

        switch (pilih) {
            case 1:
                cout << "Masukkan Nama  : ";
                cin >> nama;
                cout << "Masukkan NIM   : ";
                cin >> nim;
                list.tambahDepan(nama, nim);
                break;
            case 2:
                cout << "Masukkan Nama   : ";
                cin >> nama;
                cout << "Masukkan NIM    : ";
                cin >> nim;
                list.tambahBelakang(nama, nim);
                break;
            case 3:
                cout << "Masukkan Nama   : ";
                cin >> nama;
                cout << "Masukkan NIM    : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                list.tambahTengah(nama, nim, posisi);
                break;
            case 4:
                cout << "Masukkan Nama   : ";
                cin >> nama;
                cout << "Masukkan NIM    : ";
                cin >> nim;
                list.ubahDepan(nama, nim);
                break;
            case 5:
                cout << "Masukkan Nama   : ";
                cin >> nama;
                cout << "Masukkan NIM    : ";
                cin >> nim;
                list.ubahBelakang(nama, nim);
                break;
            case 6:
                cout << "Masukkan Nama   : ";
                cin >> nama;
                cout << "Masukkan NIM    : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                list.ubahTengah(nama, nim, posisi);
                break;
            case 7:
                list.hapusDepan();
                break;
            case 8:
                list.hapusBelakang();
                break;
            case 9:
                cout << "Masukkan Posisi  : ";
                cin >> posisi;
                list.hapusTengah(posisi);
                break;
            case 10:
                list.hapusSemua();
                break;
            case 11:
                list.menampilkan();
                break;
            case 0:
                cout << "Thank You:]" << endl;
                break;
            default:
                cout << "Pilihan Tidak Valid:[" << endl;
                break;
        }
    } while (pilih != 0);

    return 0;
}