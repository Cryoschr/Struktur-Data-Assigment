# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Irshad Benaya Fardeca</p>

# Dasar Teori
#### Linked list non-circular
Linked list non-circular memiliki node pertama (head) dan terakhir (tail) yang tidak terhubung satu sama lain. Pointer terakhir (tail) dari daftar terkait ini selalu bernilai "NULL" sebagai pertanda data terakhir dalam list-nya.[2]
#### Linked list circular
Linked list circular adalah linked list dimana bagian alamat dari node terakhir akan menyimpan alamat dari node pertama, tidak seperti pada linked list single yang pada bagian alamat node terakhir menyimpan nilai khusus, NULL. Ketika menelusuri linked list sirkular, kita bisa mulai dari node manapun dan menyusuri list ke segala arah, karena linked list circular tidak memiliki node pertama atau terakhir. Deklarasi memori untuk merepresentasikan linked list circular sama dengan deklarasi memori untuk linked list non circular.[1]


## Guided 
### 1. Linked List Non Circular
```C++
#include <iostream> 
using namespace std; 

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node 
struct Node { 
    int data; 
    Node *next; 
}; 
Node *head; 
Node *tail; 

// Inisialisasi Node 
void init() { 
    head = NULL; 
    tail = NULL; 
}

// Pengecekan 
bool isEmpty() { 
    if (head == NULL) 
    return true; 
    else 
    return false;
} 

// Tambah Depan 
void insertDepan(int nilai) { 
    // Buat Node baru 
    Node *baru = new Node; 
    baru->data = nilai; 
    baru->next = NULL; 
    if (isEmpty() == true) 
    { 
        head = tail = baru; 
        tail->next = NULL; 
    } 
    else 
    { 
        baru->next = head; 
        head = baru; 
    } 
} 

// Tambah Belakang 
void insertBelakang(int nilai) { 
    // Buat Node baru 
    Node *baru = new Node; 
    baru->data = nilai; 
    baru->next = NULL; 
    if (isEmpty() == true) 
    { 
        head = tail = baru; 
        tail->next = NULL; 
    }
    else 
    { 
        tail->next = baru; 
        tail = baru; 
    } 
} 

// Hitung Jumlah List 
int hitungList() { 
    Node *hitung; 
    hitung = head; 
    int jumlah = 0; 
    while (hitung != NULL) 
    { 
        jumlah++; 
        hitung = hitung->next; 
    } 
    return jumlah; 
} 

// Tambah Tengah 
void insertTengah(int data, int posisi) 
{ 
    if (posisi < 1 || posisi > hitungList()) { 
        cout << "Posisi diluar jangkauan" << endl;
    } 
    else if (posisi == 1) { 
        cout << "Posisi bukan posisi tengah" << endl;
    } 
    else{ 
        Node *baru, *bantu; 
        baru = new Node(); 
        baru->data = data; 
        // tranversing 
        bantu = head; 
        int nomor = 1; 
        while (nomor < posisi - 1) { 
            bantu = bantu->next; 
            nomor++; 
        } 

        baru->next = bantu->next; 
        bantu->next = baru; 
    } 
} 

// Hapus Depan 
void hapusDepan() { 
    Node *hapus; 
    if (isEmpty() == false) { 
        if (head->next != NULL) { 
            hapus = head; 
            head = head->next;
        } 
        else { 
        } 
    } 
    else { 
        delete hapus; 
        head = tail = NULL; 
        cout << "List kosong!" << endl;
    } 
} 

// Hapus Belakang 
void hapusBelakang() { 
    Node *hapus; 
    Node *bantu; 
    if (isEmpty() == false) { 
        if (head != tail) { 
            hapus = tail; 
            bantu = head; 
            while (bantu->next != tail) { 
                bantu = bantu->next; 
            } 
            tail = bantu; 
            tail->next = NULL;
        }
        else { 
        } 
    } 
    else { 
        delete hapus; 
        head = tail = NULL;
        cout << "List kosong!" << endl; 
    } 
} 

// Hapus Tengah 
void hapusTengah(int posisi) { 
    Node *bantu, *hapus, *sebelum; 
    if (posisi < 1 || posisi > hitungList()) { 
        cout << "Posisi di luar jangkauan" << endl;
    } 
    else if (posisi == 1) { 
        cout << "Posisi bukan posisi tengah" << endl;
    } 
    else { 
        int nomor = 1; 
        bantu = head; 
        while (nomor <= posisi) { 
            if (nomor == posisi - 1) {
                sebelum = bantu; 
            } 
            if (nomor == posisi) { 
                hapus = bantu; 
            } 
                bantu = bantu->next; 
                nomor++; 
        } 
        sebelum->next = bantu; 
        delete hapus; 
    } 
} 

// Ubah Depan 
void ubahDepan(int data) { 
    if (isEmpty() == 0) { 
        head->data = data; 
    } 
    else { 
        cout << "List masih kosong!" << endl;
    } 
} 

// Ubah Tengah 
void ubahTengah(int data, int posisi) { 
    Node *bantu; 
    if (isEmpty() == 0) {
        if (posisi < 1 || posisi > hitungList()) { 
            cout << "Posisi di luar jangkauan" << endl; } 
        else if (posisi == 1) { 
            cout << "Posisi bukan posisi tengah" << endl; } 
        else { 
            bantu = head; 
            int nomor = 1; 
            while (nomor < posisi) { 
                bantu = bantu->next; 
                nomor++; 
            } 
            bantu->data = data; 
        } 
    } 
    else { 
        cout << "List masih kosong!" << endl; 
    } 
} 

// Ubah Belakang 
void ubahBelakang(int data) { 
    if (isEmpty() == 0) { 
        tail->data = data; 
    }
    else { 
        cout << "List masih kosong!" << endl;
    } 
}

// Hapus List 
void clearList() { 
    Node *bantu, *hapus; 
    bantu = head; 
    while (bantu != NULL) { 
        hapus = bantu; 
        bantu = bantu->next; 
        delete hapus; 
    } 
    head = tail = NULL; 
    cout << "List berhasil terhapus!" << endl;
} 

// Tampilkan List 
void tampil() { 
    Node *bantu; 
    bantu = head; 
    if (isEmpty() == false) { 
        while (bantu != NULL) { 
            cout << bantu->data << ends; 
            bantu = bantu->next; 
        }
    cout << endl; 
    } 
    else { 
        cout << "List masih kosong!" << endl;
    } 
} 

int main() { 
    init(); 
    insertDepan(3); 
    tampil(); 
    insertBelakang(5); 
    tampil(); 
    insertDepan(2); 
    tampil(); 
    insertDepan(1); 
    tampil(); 
    hapusDepan(); 
    tampil(); 
    hapusBelakang(); 
    tampil(); 
    insertTengah(7, 2); 
    tampil(); 
    hapusTengah(2); 
    tampil(); 
    ubahDepan(1); 
    tampil(); 
    ubahBelakang(8); 
    tampil(); 
    ubahTengah(11, 2); 
    tampil();
return 0; 
} 
```
#### Output:
![Screenshot 2024-04-03 101552](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/77d5d57a-3d5c-45e0-87aa-3ec59cbac1d8)
Program di atas merupakan single linked list non-circular Linked list ini terdiri dari struktur Node. Pointer head dan tail digunakan untuk menunjuk ke node pertama dan terakhir. Berbagai operasi seperti inisialisasi, pengecekan, penambahan, penghapusan, perubahan data, dan pencetakan data dapat dilakukan pada linked list.

### 2. Linked List Circular
```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST CIRCULAR
// Deklarasi Struct Node
struct Node
{
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

//iinisialisasi node
void init()
{
    head = NULL;
    tail = head;
}

// Pengecekan
int isEmpty()
{
    if (head == NULL)
        return 1; // true
    else
        return 0; // false
}

// Buat Node Baru
void buatNode(string data)
{
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList()
{
    bantu = head;
    int jumlah = 0;

    while (bantu != NULL)
    {
        jumlah++;
        bantu = bantu->next;
    }

    return jumlah;
}

// Tambah Depan
void insertDepan(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah Belakang
void insertBelakang(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }

        tail->next = baru;
        baru->next = head;
    }
}

// Tambah Tengah
void insertTengah(string data, int posisi)
{
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        baru->data = data;
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Depan
void hapusDepan()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;

        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
            
            delete hapus;
        }
        else
        {

            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            hapus->next = NULL;

            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;

            delete hapus;
        }
        else
        {
            while (hapus->next != head)
            {
                hapus = hapus->next;
            }
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            tail->next = head;
            hapus->next = NULL;

            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi)
{
    if (isEmpty() == 0)
    {
        // transversing
        int nomor = 1;
        bantu = head;

        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;

        delete hapus;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void clearList()
{
    if (head != NULL)
    {
        hapus = head->next;

        while (hapus != head)
        {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil()
{
    if (isEmpty() == 0)
    {
        tail = head;
        do
        {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

int main(){
    init();
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();

    return 0;
}
```
#### Output:
![Screenshot 2024-04-03 101846](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/286a3b3f-ab46-48dd-bc5e-6bd9adf99da1)
Program di atas merupakan single linked list circular. Single linked list circular terdiri dari struktur Node. Pointer head dan tail digunakan untuk menunjuk ke node pertama dan terakhir. Berbagai operasi seperti inisialisasi, pengecekan data, penambahan data, penghapusan data, dan menampilkan data dapat dilakukan pada program tersebut. Perbedaan utama dengan single linked list non-circular terletak pada node terakhir yang menunjuk ke node pertama.


## Unguided
Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user.
### 1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa, berikut contoh tampilan output dari nomor 1:
• Tampilan Menu:
PROGRAM SINGLE LINKED LIST NON-CIRCULAR
1. Tambah Depan
2. Tambah Belakang
3. Tambah Tengah
4. Ubah Depan
5. Ubah Belakang
6. Ubah Tengah
7. Hapus Depan
8. Hapus Belakang
9. Hapus Tengah
10. Hapus List
11. TAMPILKAN
0. KELUAR
Pilih Operasi :

• Tampilan Operasi Tambah:
-Tambah Depan-

Masukkan Nama :
Masukkan NIM :

Data telah ditambahkan


-Tambah Tengah-

Masukkan Nama :
Masukkan NIM :
Masukkan Posisi :

Data telah ditambahkan


• Tampilan Operasi Hapus:
-Hapus Belakang-

Data (nama mahasiswa yang dihapus) berhasil dihapus


-Hapus Tengah-

Masukkan posisi :

Data (nama mahasiswa yang dihapus) berhasil dihapus


• Tampilan Operasi Ubah:
-Ubah Belakang-

Masukkan nama :

Masukkan NIM :
Data (nama lama) telah diganti dengan data (nama baru)


-Ubah Belakang-

Masukkan nama :
Masukkan NIM :
Masukkan posisi :

Data (nama lama) telah diganti dengan data (nama baru)


• Tampilan Operasi Tampil Data:
DATA MAHASISWA

NAMA NIM
Nama1 NIM1
Nama2 NIM2

*Buat tampilan output sebagus dan secantik mungkin sesuai kreatifitas anda
masing-masing, jangan terpaku pada contoh output yang diberikan

```C++
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
        cout << "Data berhasil ditambahkan" << endl;
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
        cout << "Data berhasil ditambahkan" << endl;
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
            cout << "Data berhasil ditambahkan" << endl;
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
        cout << "Data berhasil ditambahkan" << endl;
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
        cout << "| Nama" << "   |   " << "NIM |" << endl;
        do {
            cout <<"| " << tail->nama << "   |   " << tail->nim << " |" << endl;
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
```
#### Output:

### 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah)

Nama NIM
Jawad 23300001
[Nama Anda] [NIM Anda]
Farrel 23300003
Denis 23300005
Anis 23300008
Bowo 23300015
Gahar 23300040
Udin 23300048
Ucok 23300050
Budi 23300099

3. Lakukan perintah berikut:
a) Tambahkan data berikut diantara Farrel dan Denis:
Wati 2330004
b) Hapus data Denis
c) Tambahkan data berikut di awal:
Owi 2330000
d) Tambahkan data berikut di akhir:
David 23300100
e) Ubah data Udin menjadi data berikut:
Idin 23300045
f) Ubah data terkahir menjadi berikut:
Lucy 23300101
g) Hapus data awal
h) Ubah data awal menjadi berikut:
Bagas 2330002
i) Hapus data akhir
j) Tampilkan seluruh data

#### Output:
![Screenshot 2024-04-04 000201](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/d9424227-f5a9-4548-99c6-986e8222387f)
![Screenshot 2024-04-04 000332](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/1b4a1302-7e88-42e6-beeb-7b7d6843e996)
![Screenshot 2024-04-04 000417](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/3b56fbc9-8dc3-459b-9eaf-53e45bebb718)
![Screenshot 2024-04-04 000500](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/fc1fdaa9-9c6c-4f3b-9147-491f5c34b0a6)
![Screenshot 2024-04-04 000547](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/9b0e8523-b9c2-4f83-8292-83ee3e7bf1cb)
![Screenshot 2024-04-04 000801](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/32e93d0a-236e-4d9d-8e5c-5eda0553829f)
![Screenshot 2024-04-04 000834](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/e299cc46-ffad-48f4-86ae-e9a576dfb685)
![Screenshot 2024-04-04 000903](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/577e145e-63a8-4682-808b-6660139fb670)
![Screenshot 2024-04-04 000940](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/a6648d95-034b-4577-8b96-b4577c49fffb)
![Screenshot 2024-04-04 001006](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/f37b0788-ac1c-4fc5-88ec-9b6952840670)
Program di atas merupakan program menu linked list circular untuk menyimpan data nama dan NIM mahasiswa. Program ini memungkinkan user untuk melakukan berbagai operasi seperti penambahan data di depan, belakang, dan tengah, penghapusan data di depan, belakang, dan tengah, mengubah data di depan, belakang, dan tengah, menghapus list serta menampilkan seluruh data.

## Kesimpulan
Perbedaan dari Linked list circular dan non-circular terletak pada node terakhirnya. Linked list circular memiliki node terakhir yang menunjuk ke node pertama, sehingga membentuk lingkaran, sedangkan linked list non-circular memiliki node terakhir yang menunjuk ke NULL.

## Referensi
[1] Malhotra, D., Malhotra, N. (2019). Data Structures and Program Design Using C++. Germany: Mercury Learning and Information.
[2] MODUL 4 LINKED LIST CIRCULAR DAN NON CIRCULAR
