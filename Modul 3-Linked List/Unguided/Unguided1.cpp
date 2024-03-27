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