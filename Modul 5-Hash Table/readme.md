# <h1 align="center">Laporan Praktikum Modul Hash Table</h1>
<p align="center">Irshad Benaya Fardeca</p>

# Dasar Teori
#### 


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

```

#### Output:
Program ini mengimplementasikan hash table untuk menyimpan data mahasiswa, dengan fungsi untuk menambahkan, menghapus, dan mencari data berdasarkan NIM dan nilai. Program memiliki menu untuk memilih operasi yang diinginkan. Data mahasiswa disimpan dalam struktur Node, yang berisi NIM dan nilai. Hash table diimplementasikan sebagai array of linked lists, di mana setiap index menyimpan node dengan hash index yang sama. Beberapa fungsi yang dapat dijalankan, yaitu menambahkan data baru ke hash table, menghapus data berdasarkan NIM,  mencari data berdasarkan NIM, mencari data berdasarkan rentang nilai.


## Kesimpulan


## Referensi

