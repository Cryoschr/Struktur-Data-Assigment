# <h1 align="center">Laporan Praktikum Modul Hash Table</h1>
<p align="center">Irshad Benaya Fardeca</p>

# Dasar Teori
### Hash Table
Sebuah struktur data yang menyimpan dan mengambil data menggunakan sistem pasangan kunci-nilai.
Struktur ini memiliki kompleksitas waktu rata-rata O(1) untuk insert, search and delete. Dalam kasus terburuk, bekerja dengan kompleksitas waktu O(n). Hash table memiliki beberapa operasi seperti berikut: 
1. Insert: Menyisipkan key-value pair ke dalam map.
2. Search: Mencari nilai berdasarkan sebuah ket.
3. Delete: Menghapus key-value pair dari peta berdasarkan key.[1]
4. Update: Memperbarui data dalam hash table dengan mencari data menggunakan
fungsi hash, dan kemudian memperbarui data yang ditemukan.
5. Traversal: Melalui seluruh hash table untuk memproses semua data yang ada dalam
tabel.[2]

##### Collision dalam Hashing
Dalam hal ini, fungsi hash digunakan untuk menemukan indeks dari array. Hash value digunakan untuk membuat indeks untuk key dalam tabel hash. Fungsi hash dapat mengembalikan nilai hash yang sama untuk dua atau lebih key. Ketika dua atau lebih key memiliki hash value yang sama, collision akan terjadi. Untuk menangani collision ini, kita dapat menggunakan tenik collision resolution. Ada dua teknik yaitu :

1. Separate chaining (open hashing)
Metode ini melibatkan linked list dari slot tempat collision terjadi, kemudian menambahkan key baru ke daftar tersebut. Separate cahining adalah istilah yang digunakan untuk menggambarkan bagaimana daftar slot yang terhubung ini menyerupai rantai. Metode ini lebih sering digunakan ketika kita tidak yakin dengan jumlah key yang akan ditambahkan atau dihapus.

2. Open addressing (closed hashing)
Untuk mencegah collision dalam hash table, open addresing digunakan sebagai teknik collision resolution. Tidak ada key yang disimpan di tempat lain selain hash table. Akibatnya, ukuran hash table tidak pernah sama dengan atau kurang dari jumlah key. Selain itu, teknik ini juga dikenal sebagai closed hashing.

    Linear probing: Ini melibatkan melakukan penyelidikan linier untuk slot berikutnya ketika collison terjadi dan terus melakukannya sampai slot kosong ditemukan.
    
    Quadratic probing: Ketika terjadi collision dalam hal ini, melakukan probing untuk slot ke-i2-nd pada iterasi ke-i, dan terus melakukannya sampai slot kosong ditemukan.
    
    Double hashing: Dalam hal ini, menggunakan algoritma hashing yang berbeda, dan pada iterasi ke-i, mencari (i * hash 2(x)). Penentuan dua fungsi hash membutuhkan lebih banyak waktu. Meskipun tidak ada masalah pengelompokan.[3]

## Guided 
### 1. Guided 1
```C++
#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

// Fungsi hash sederhana
int hash_func(int key) {
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Node {
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class hash table
class HashTable {
private:
    Node** table;
public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }
    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
        }
    }
    delete[] table;
}

// Insertion
void insert(int key, int value) {
    int index = hash_func(key);
    Node* current = table[index];
    while (current != nullptr) {
        if (current->key == key) {
            current->value = value;
            return;
        }
        current = current->next;
    }
    Node* node = new Node(key, value);
    node->next = table[index];
    table[index] = node;
}

// Searching
int get(int key) {
    int index = hash_func(key);
    Node* current = table[index];
    while (current != nullptr) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

// Deletion
void remove(int key) {
    int index = hash_func(key);
    Node* current = table[index];
    Node* prev = nullptr;
    while (current != nullptr) {
        if (current->key == key) {
            if (prev == nullptr) {
                table[index] = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Traversal
void traverse() {
    for (int i = 0; i < MAX_SIZE; i++) {
        Node* current = table[i];
        while (current != nullptr) {
                cout << current->key << ": " << current->value << endl;

                current = current->next;
            }
        }
    }
};

int main() {

    HashTable ht;

    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;

    // Deletion
    ht.remove(4);

    // Traversal
    ht.traverse();

    return 0;
}
```
#### Output:
![Screenshot 2024-04-09 233034](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/114b1958-b536-4990-bcc6-207ca8599985)

Program ini mendefinisikan fungsi hash sederhana untuk menghitung indeks hash untuk key yang diberikan. Struktur Node digunakan untuk mewakili node individual dalam hash table, yang menyimpan key, value, dan pointer ke node berikutnya. Fungsi main, menunjukkan contoh penggunaan fungsi insert, get, remove, dan traverse, dan akhirnya mencetak konten hash table.


### 2. Guided 2
```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int TABLE_SIZE = 11;
string name;
string phone_number;

// Struktur data untuk setiap node
class HashNode {
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

// Class hash
class HashMap {
    private:
        vector<HashNode*> table[TABLE_SIZE];
    public:
        int hashFunc(string key) {
            int hash_val = 0;
            for (char c : key) {
                hash_val += c;
            }
        return hash_val % TABLE_SIZE;
        }

        //Menmbah data
        void insert(string name, string phone_number) {
            int hash_val = hashFunc(name);
            
            for (auto node : table[hash_val]) {
                if (node->name == name) {
                    node->phone_number = phone_number;
                    return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }
    
    //menghapus data
    void remove(string name) {
        int hash_val = hashFunc(name);

        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    //Mencari nomer telepom
    string searchByName(string name) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                return node->phone_number;
            }
        }
        return "";
    }

    //Menamplkan
    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
                for (auto pair : table[i]) {
                if(pair != nullptr){
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap employee_map;

    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;

    employee_map.remove("Mistah");

    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;
    cout << "Hash Table : " << endl;

    employee_map.print();

    return 0;
}
```
#### Output:
![Screenshot 2024-04-09 233135](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/915815d3-3a15-4f4f-b4d8-747c8f9d3c55)

Program ini mengimplementasikan direktori telepon sederhana menggunakan hash table. Hash table menyimpan pasangan nama dan nomor telepon, memungkinkan pencarian dan penyisipan data yang efisien. Fungsi hashFunc menghitung index hash table berdasarkan nama. insert menambahkan data ke hash table, memperbarui nomor telepon jika nama sudah ada. remove menghapus data berdasarkan nama. searchByName mencari nomor telepon berdasarkan nama. print menampilkan isi hash table.


## Unguided

### 1. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan :
a. Setiap mahasiswa memiliki NIM dan nilai.
b. Program memiliki tampilan pilihan menu berisi poin C.
c. Implementasikan fungsi untuk menambahkan data baru, menghapus data,
mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai
(80 – 90).

```C++
//Irshad Benaya Fardeca
//2311102199

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int ukuran = 11;
string nim;
int nilai;

// Struktur data untuk setiap node
class HashNode {
public:
    string nim;
    int nilai;

    HashNode(string nim, int nilai) {
        this->nim = nim;
        this->nilai = nilai;
    }
};

// Class hash
class HashMap {
    private:
        vector<HashNode*> table[ukuran];
    public:
        int hashFunc(string nim) {
            int nilaiHash = 0;
            for (char c : nim) {
                nilaiHash += c;
            }
        return nilaiHash % ukuran;
        }

        //Menmbah data
        void masukkan(string nim, int nilai) {
            int nilaiHash = hashFunc(nim);
            for (auto node : table[nilaiHash]) {
                if (node->nim == nim) {
                    node->nilai = nilai;
                    return;
            }
        }
        table[nilaiHash].push_back(new HashNode(nim, nilai));
    }
    
    //menghapus data
    void hapus(string nim) {
        int nilaiHash = hashFunc(nim);
        for (auto it = table[nilaiHash].begin(); it != table[nilaiHash].end(); it++) {
            if ((*it)->nim == nim) {
                table[nilaiHash].erase(it);
                return;
            }
        }
    }

    //Mencari nim
    void cariNim(string nim) {
        int nilaiHash = hashFunc(nim);
        for (auto node : table[nilaiHash]) {
            if (node->nim == nim) {
                cout<<node->nilai<<endl;
            }
        }
    }

    //Mencari nilai
    void cariNilai() {
        for (int i = 0; i < ukuran; i++){
            cout << i << ": ";
                for (auto pair : table[i]) {
                    if (pair !=nullptr){
                        if (pair->nilai >= 80 && pair->nilai <=90){
                            cout << pair->nim << endl;
                        }
                }
            }
        }
    }

    //Menamplkan
    void print() {
        for (int i = 0; i < ukuran; i++) {
            cout << i << ": ";
                for (auto pair : table[i]) {
                if(pair != nullptr){
                    cout << "[" << pair->nim << ", " << pair->nilai << "]";
                }
            }
            cout << endl;
        }
    }
};

 

int main(){

HashMap dataMahasiswa;
int pilihan;

do{
    cout<<endl;
    cout<<"     DATA MAHASISWA"<<endl;
    cout<<"1. Tambah Data"<<endl;
    cout<<"2. Hapus Data"<<endl;
    cout<<"3. Cari Data Berdasarkan NIM"<<endl;
    cout<<"4. Cari Data Berdsarkan Nilai"<<endl;
    cout<<"5. Menampilkan"<<endl;
    cout<<"0. Exit"<<endl;
    cout<<"Masukkan Pilihan : ";
    cin>>pilihan;
    cout<<endl;

    switch (pilihan){

    case 1:
    //menambahkan data baru
        cout<<"Masukkan NIM : ";
        cin>>nim;
        cout<<"Masukkan Nilai : ";
        cin>>nilai;
        dataMahasiswa.masukkan(nim,nilai);
        break;
    case 2:
    //menghapus data
        cout<<"Masukkan NIM akan anda hapus : ";
        cin>>nim;
        dataMahasiswa.hapus(nim);
        break;
    case 3:
    //mencari data berdasarkan NIM
        cout<<"Masukkan NIM yang anda cari : ";
        cin>>nim;
        cout<<"Nilai dari "<<nim<<" : ";
        dataMahasiswa.cariNim(nim);
        break;
    case 4:
    //mencari data berdasarkan nilai
        cout<<"NIM dengan nilai 80-90 : "<<endl;
        dataMahasiswa.cariNilai(); 
        break;
    case 5:
    //Menampilkan
        dataMahasiswa.print();
        break;
    case 0:
    //Exit
        cout<<endl;
        cout<<"Anda keluar";
        break;
    default:
        cout<<"Salah input";
        break;
    }
}while(pilihan != 0);
return 0;
}
```

#### Output:
#### Input data
![Screenshot 2024-04-17 210720](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/b5e2294d-a5c1-4053-a1a9-2e0dc74cfea8)
#### Menampilkan
![Screenshot 2024-04-17 210750](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/0f844b0d-7559-4e18-8525-2f1055f52e14)
#### Mencari data dengan NIM
![Screenshot 2024-04-17 211209](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/50994b29-1fed-44ae-9475-e706431cee9e)
#### Mencari data dengan nilai 80-90
![Screenshot 2024-04-17 211220](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/1212b53e-c646-42a3-9e56-24d4b5c91fba)
#### Menghapus data
![Screenshot 2024-04-17 211235](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/d88dd0eb-9274-4d61-ad84-0af58c38c737)

Program ini mengimplementasikan hash table untuk menyimpan data mahasiswa, dengan fungsi untuk menambahkan, menghapus, dan mencari data berdasarkan NIM dan nilai. Program memiliki menu untuk memilih operasi yang diinginkan. Data mahasiswa disimpan dalam struktur Node, yang berisi NIM dan nilai. Hash table diimplementasikan sebagai array of linked lists, di mana setiap index menyimpan node dengan hash index yang sama. Beberapa fungsi yang dapat dijalankan, yaitu menambahkan data baru ke hash table, menghapus data berdasarkan NIM,  mencari data berdasarkan NIM, mencari data berdasarkan rentang nilai 80-90.


## Kesimpulan
Hash table adalah struktur data yang efisien dan serbaguna untuk menyimpan dan mencari data berdasarkan key. Untuk operasi hash table ada beberapa yaitu :
1. insert
2. Delete
3. Search
4. Update
5. Traversal

Kekurangan dari hash table adalah kemungkinan terjadinya collision dan untuk menanganinnya ada dua teknik yaitu :
1. Separate chaining (Open Hashing)
2. Open addresing (Closed Hasing)

## Referensi
[1] Nordström, O., & Raivio, L. (2023). Performance evaluation of Multithreading, Hashtables, and Anonymous Functions for Rust and C++: in Game Development.

[2] MODUL 5 HASH TABLE

[3] Collision Resolution Techniques. Diakses pada 17 Mret 2024, dari https://www.geeksforgeeks.org/collision-resolution-techniques/
