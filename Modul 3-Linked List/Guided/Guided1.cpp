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
    // Buat Node newNode
    Node *newNode = new Node;
    newNode->data = nilai;
    newNode->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = newNode;
        tail->next = NULL;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

// Tambah Belakang
void insertBelakang(int nilai)
{
    // Buat Node newNode
    Node *newNode = new Node;
    newNode->data = nilai;
    newNode->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = newNode;
        tail->next = NULL;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
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
        Node *newNode, *cur;
        newNode = new Node();
        newNode->data = data;
        // tranversing
        cur = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            cur = cur->next;
            nomor++;
        }
        newNode->next = cur->next;
        cur->next = newNode;
    }
}

// del Depan
void delDepan()
{
    Node *del;
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            del = head;
            head = head->next;
            delete del;
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

// del Belakang
void delBelakang()
{
    Node *del;
    Node *cur;
    if (isEmpty() == false)
    {
        if (head != tail)
        {
            del = tail;
            cur = head;
            while (cur->next != tail)
            {
                cur = cur->next;
            }
            tail = cur;
            tail->next = NULL;
            delete del;
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

// del Tengah
void delTengah(int posisi)
{
    Node *del, *cur, *before;
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
        cur = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                before = cur;
            }
            if (nomor == posisi)
            {
                del = cur;
            }
            cur = cur->next;
            nomor++;
        }
        before->next = cur;
        delete del;
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
    Node *cur;
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
            cur = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                cur = cur->next;
                nomor++;
            }
            cur->data = data;
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

// del List
void clearList()
{
    Node *cur, *del;
    cur = head;
    while (cur != NULL)
    {
        del = cur;
        cur = cur->next;
        delete del;
    }
    head = tail = NULL;
    cout << "List berhasil terdel!" << endl;
}

// Tampilkan List
void tampil()
{
    Node *cur;
    cur = head;
    if (isEmpty() == false)
    {
        while (cur != NULL)
        {
            cout << cur->data << ends;
            cur = cur->next;
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
    delDepan();
    tampil();
    delBelakang();
    tampil();
    insertTengah(7, 2);
    tampil();
    delTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
}