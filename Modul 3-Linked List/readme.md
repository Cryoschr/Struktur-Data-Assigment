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
Program di atas merupakan contoh implementasi Single Linked List Non-Circular dalam bahasa C++. Single Linked List adalah struktur data yang terdiri dari kumpulan node yang saling terhubung dengan pointer. Node adalah elemen penyusun Single Linked List yang menyimpan data dan pointer ke node berikutnya.

Program ini memiliki beberapa fungsi untuk memanipulasi Single Linked List, seperti:

Inisialisasi: Mengatur head dan tail menjadi NULL untuk menunjukkan list kosong.
Memeriksa Keberadaan: Mengecek apakah list kosong.
Penambahan Node: Menambahkan node baru di depan, belakang, atau di posisi tertentu di tengah list.
Penghapusan Node: Menghapus node pertama, terakhir, atau di posisi tertentu di tengah list.
Perubahan Data: Mengubah data node pertama, terakhir, atau di posisi tertentu di tengah list.
Penghitungan: Menghitung jumlah node dalam list.
Penampilan Data: Menampilkan data semua node dalam list.


### 2. Double Linked List
```C++
#include <iostream>
using namespace std;

/// PROGRAM DOUBLE LINKED LIST
// Deklarasi Struct Node
struct Node
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
Program di atas merupakan implementasi Double Linked List Non-Circular dalam bahasa C++. Double Linked List adalah struktur data yang mirip dengan Single Linked List, namun setiap node memiliki dua pointer: prev dan next. Pointer prev menunjuk ke node sebelumnya, dan pointer next menunjuk ke node berikutnya.

Kelas DoublyLinkedList mendefinisikan Double Linked List dengan member head dan tail yang menunjuk ke node pertama dan terakhir. Konstruktor menginisialisasi head dan tail menjadi nullptr (menandakan list kosong).

Fungsi push(int data) menambahkan node baru dengan data data di depan list. Fungsi pop() menghapus node pertama dari list. Fungsi update(int oldData, int newData) mencari node dengan data oldData dan memperbaruinya dengan newData. Fungsi deleteAll() menghapus semua node dari list. Fungsi display() menampilkan data semua node dalam list.

Fungsi-fungsi di main() menampilkan menu interaktif untuk menambah, menghapus, memperbarui, menghapus semua, dan menampilkan data dalam list. Berdasarkan pilihan pengguna, program memanggil fungsi terkait pada objek list yang merupakan instance dari kelas DoublyLinkedList.


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

```
#### Output:


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

```
#### Output:


## Kesimpulan


## Referensi
[1] Johnson Sihombing, “PENERAPAN STACK DAN QUEUE PADA ARRAY DAN LINKED LIST DALAM JAVA”, INFOKOM, vol. 7, no. 2, pp. 15-24, Dec. 2019.
