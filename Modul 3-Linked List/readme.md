# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Irshad Benaya Fardeca</p>

# Dasar Teori
PENGERTIAN LINKED LIST
Linked list adalah suatu bentuk struktur data yang berupa sekumpulan elemen data yang bertipe sama dimana tiap elemen saling berkaita atau dihubungkan dengan elemen lain melalui suatu pointer. Pointer itu sendiri adalah alamat elemen data yang tersimpan di memori. Penggunaan pointer untuk mengacu elemen berakibat elemen-elemen bersebelahan secara logik walau tidak bersebelahan secara fisik di memori.

Linked list terdiri dari node-node (simpul-simpul) yang saling terhubung(linked). Simpul berupa struct, sedangkan link berupa komponen yang bertipe pointer ke simpul. Ada dua jenis pointer yang digunakan, yaitu head (menunjukkan alamat pointer paling depan) dan tail (menunjukkan simpul terakhir). Operasi penambahan atau penghapusan sebuah simpul akan mengubah nilai pointer link nya. Sedangkan pointer link di simpul terkahir diberi nilai null.

SINGLE LINKED LIST
Pada list jenis ini, tiap node nya memiliki field yang berisi pointer ke node berikutnya dan juga memiliki field yang berisi data. Akhir linked list ditandai dengan node terakhir yang menunjuk ke null yang akan digunakan sebagai kondisi berhenti saat pembacaan linked list.

DOUBLE LINKED LIST
Merupakan linked list dengan menggunakan pointer, dimana setiap nodememiliki tiga buah field, yaitu : field pointer yang menunjuk ke pointer berikutnya, field pointer yang menunjuk ke pointer sebelumnya dan field yang berisi data dari node tersebut. Semenatara pointer next dan prev-nya menunjuk ke null.[1]

## Guided 
### 1. Single Linked List
```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
    // komponen/member
    int data;
    Node *next;
};

Node *head;
Node *tail;
// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}

// Pengecekan
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}

// Tambah Depan
void insertDepan(int nilai)
{
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
void insertBelakang(int nilai)
{
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
int hitungList()
{
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
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
        bantu = head;
        int nomor = 1;
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
    Node *hapus;
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false)
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi)
{
    Node *hapus, *bantu, *bantu2;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                bantu2 = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
        delete hapus;
    }
}

// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == false)
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Tengah
void ubahTengah(int data, int posisi)
{
    Node *bantu;
    if (isEmpty() == false)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Belakang
void ubahBelakang(int data)
{
    if (isEmpty() == false)
    {
        tail->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void clearList()
{
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil()
{
    Node *bantu;
    bantu = head;
    if (isEmpty() == false)
    {
        while (bantu != NULL)
        {
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

int main()
{
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
![Screenshot 2024-03-27 191109](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/4dac6728-daad-447b-83c2-a1364a9f5685)

Program ini merupakan contoh implementasi Single Linked List Non-Circular.Program ini memiliki beberapa fungsi, yaitu mengatur head dan tail menjadi NULL untuk menunjukkan list kosong, mengecek apakah list kosong, menambahkan node baru di depan, belakang, atau di posisi tertentu di tengah list, menghapus node pertama, terakhir, atau di posisi tertentu di tengah list, mengubah data node pertama, terakhir, atau di posisi tertentu di tengah list, menghitung jumlah node dalam list dan menampilkan data semua node dalam list.


### 2. Double Linked List
```C++
#include <iostream>
using namespace std;

/// PROGRAM DOUBLE LINKED LIST NON-CIRCULAR

class Node {
    public:int data;
    Node* prev;
    Node* next;
};

//
class DoublyLinkedList {
        public:
        Node* head;
        Node* tail;
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
    }

    //Menambah data 
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } 
        else {
            tail = newNode;
        }
        head = newNode;
    }

    //Menghapus data
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } 
        else {
            tail = nullptr;
        }
        delete temp;
    }

    //Menggupdate data
    bool update(int oldData, int newData) {
        Node* current = head;while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    //Menghapus semua data
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    //Menampilkan data
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};


int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }

            //Mengakhiri program
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```
#### Output:
Program ini adalah implementasi Double Linked List Non-Circular. Double Linked List adalah struktur data yang mirip dengan Single Linked List, namun setiap node memiliki dua pointer: prev dan next. Pointer prev menunjuk ke node sebelumnya, dan pointer next menunjuk ke node berikutnya. Program ini memiliki beberapa fungsi, yaitu menambahkan node baru dengan data data di depan list, menghapus node pertama dari list, mencari node dengan data oldData dan memperbaruinya dengan newData, menghapus semua node dari list dan menampilkan data semua node dalam list.

![Screenshot 2024-03-27 210243](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/82ff8ebe-b3ab-42f2-a5bd-79077ace672b)
![Screenshot 2024-03-27 210513](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/45643b28-fa44-4c1a-9a6d-c1d3ba992f6d)


## Unguided 
### 1. Soal mengenai Single Linked List
Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut:
a. Masukkan data sesuai urutan berikut. (Gunakan insert depan, belakang atau tengah). Data pertama yang dimasukkan adalah nama dan usia anda.

[Nama_anda] [Usia_anda]
John 19
Jane 20
Michael 18
Yusuke 19
Akechi 20
Hoshino 18
Karin 18

b. Hapus data Akechi
c. Tambahkan data berikut diantara John dan Jane : Futaba 18
d. Tambahkan data berikut diawal : Igor 20
e. Ubah data Michael menjadi : Reyn 18
f. Tampilkan seluruh data

```C++
//Irshad Benata Fardeca
//2311102199
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
    // komponen/member
    string nama;
    int umur;
    Node *next;
};

Node *head;
Node *tail;
// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}

// Pengecekan
bool apakahKosong()
{
    if (head == NULL)
        return true;
    else
        return false;
}

// Tambah Depan
void addDepan(string huruf, int angka)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->nama = huruf;
    baru->umur = angka;
    baru->next = NULL;
    if (apakahKosong() == true)
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
void addBelakang(string huruf,int angka)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->nama = huruf;
    baru->umur = angka;
    baru->next = NULL;
    if (apakahKosong() == true)
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
int hitungList()
{
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
void addTengah(string huruf, int umur, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru, *current;
        baru = new Node();
        baru->nama = huruf;
        baru->umur = umur;
        // tranversing
        current = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            current = current->next;
            nomor++;
        }
        baru->next = current->next;
        current->next = baru;
    }
}

// Hapus Tengah
void delTengah(int posisi)
{
    Node *hapus, *current, *current2;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        current = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                current2 = current;
            }
            if (nomor == posisi)
            {
                hapus = current;
            }
            current = current->next;
            nomor++;
        }
        current2->next = current;
        delete hapus;
    }
}

// Ubah Tengah
void ubahTengah(string huruf, int umur, int posisi)
{
    Node *current;
    if (apakahKosong() == false)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            current = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                current = current->next;
                nomor++;
            }
            current->nama = huruf;
            current->umur = umur;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// menampilkankan List
void menampilkan()
{
    Node *current;
    current = head;
    if (apakahKosong() == false)
    {
        while (current != NULL)
        {
            cout << current->nama << " ";
            cout << current->umur << ends;
            current = current->next;
            cout << endl;
        }
        cout << endl;
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

int main()
{
    init();
    addDepan("Irshad", 18);
    addBelakang("Karin", 18);
    addTengah("John", 19, 2);
    addTengah("Jane", 20, 3);
    addTengah("Michael", 18, 4);
    addTengah("Yusuke", 19, 5);
    addTengah("Akechi", 20, 6);
    addTengah("Hoshino", 18, 7);
    menampilkan();
    delTengah(6);
    menampilkan();
    addTengah("Futaba", 18, 3);
    menampilkan();
    addDepan("Igor", 20);
    menampilkan();
    ubahTengah("Reyn", 18, 6);
    menampilkan();
    return 0;
}
```
#### Output:
![Screenshot 2024-03-27 190808](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/43e5fc90-62f1-4199-8bd3-b41c24efb9f4)
Program single linked list non circular ini adalah program untuk menyimpan nama dan usia mahasiswa. Dalam program ini user dapat menghapus data mahasiswa, menambahkan data mahasiswa, mengubah data mahsiswa dan menampilkan data seluruh mahasiswa.

### 2. Soal mengenai Double Linked List
Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.

Nama Produk Harga
Originote 60.000
Somethinc 150.000
Skintific 100.000
Wardah 50.000
Hanasui 30.000

Case:
1. Tambahkan produk Azarine dengan harga 65000 diantara
Somethinc dan Skintific
2. Hapus produk wardah
3. Update produk Hanasui menjadi Cleora dengan harga 55.000
4. Tampilkan menu seperti dibawah ini
Toko Skincare Purwokerto
1. Tambah Data
2. Hapus Data
3. Update Data
4. Tambah Data Urutan Tertentu
5. Hapus Data Urutan Tertentu
6. Hapus Seluruh Data
7. Tampilkan Data
8. Exit
Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah
ini :

Nama Produk Harga
Originote 60.000
Somethinc 150.000
Azarine 65.000
Skintific 100.000
Cleora 55.000

```C++
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
```
#### Output:
![Screenshot 2024-03-27 233113](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/98dbb405-27c0-4368-91b4-0aa898f2fdf1)
![Screenshot 2024-03-27 233138](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/41b50562-f3b3-4c71-b46c-d2adc2b47e4b)
![Screenshot 2024-03-27 233156](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/f4420130-040b-4dc6-ab31-0842ba8fea1b)
![Screenshot 2024-03-27 233208](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/97dfc2c2-046f-4940-8d86-62095ba0e462)
![Screenshot 2024-03-27 233224](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/7c7a42e3-2852-4ec1-8872-78094d1ebf13)
Program double linked list non circular ini merupakan program untuk manajamen data produk. Program bisa menambahkan data, menghapus data, menambahkan data di urutan tertentu, manghapus data di urutan tertentu, menghapus seluruh data dan menampilkan seluruh data

## Kesimpulan
Linked list merupakan struktur data yang terdiri dari elemen-elemen data yang terhubung satu sama lain dengan pointer. Linked list memiliki dua jenis utama: Single Linked List dan Double Linked List. Pada Single Linked List, setiap node memiliki pointer ke node berikutnya dan data. Node terakhir memiliki pointer null. Sedangkan pada Double Linked List, setiap node memiliki pointer ke node berikutnya, node sebelumnya, dan data. Node pertama memiliki pointer null untuk node sebelumnya, dan node terakhir memiliki pointer null untuk node berikutnya. Linked list memiliki keuntungan dan kekurangan. Keuntungannya adalah penambahan dan penghapusan elemen mudah dilakukan di tengah list, dan memori yang digunakan lebih efisien dibandingkan array. Kekurangannya adalah akses elemen acak lebih lambat dibandingkan array, dan membutuhkan memori lebih banyak dibandingkan array karena pointer.

## Referensi
[1] Johnson Sihombing, “PENERAPAN STACK DAN QUEUE PADA ARRAY DAN LINKED LIST DALAM JAVA”, INFOKOM, vol. 7, no. 2, pp. 15-24, Dec. 2019.
