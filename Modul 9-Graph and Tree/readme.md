# <h1 align="center">Laporan Praktikum Modul Stack</h1>
<p align="center">Irshad Benaya Fardeca</p>
<p align="center">S1-IF-11E</p>
<p align="center"> 2311102199</p>

# Dasar Teori
Pohon adalah struktur data non-linear yang populer di mana elemen data atau node direpresentasikan dalam urutan hirarki. Di sini, salah satu node ditampilkan sebagai node akar dari pohon, dan node yang tersisa dibagi menjadi dua himpunan yang terputus-putus sehingga setiap himpunan merupakan bagian dari sub-pohon. Pohon membuat proses pencarian menjadi sangat mudah, dan pemrograman rekursifnya membuat program menjadi lebih optimal dan mudah dimengerti.

Pohon biner adalah bentuk paling sederhana dari sebuah pohon. Pohon biner terdiri dari sebuah simpul akar dan dua subpohon yang dikenal sebagai subpohon kiri dan subpohon kanan, di mana kedua subpohon tersebut juga merupakan pohon biner. Setiap node dalam sebuah pohon terdiri dari tiga bagian, yaitu bagian paling kiri menyimpan sebuah pointer yang menunjuk ke subpohon kiri, bagian tengah akan terdiri dari elemen data, dan bagian paling kanan menyimpan sebuah pointer yang menunjuk ke subpohon kanan. Akar adalah elemen paling atas dari pohon. Ketika tidak ada node dalam sebuah pohon, yaitu ketika ROOT = NULL, maka pohon tersebut disebut pohon kosong.

Sebagai contoh, perhatikan sebuah pohon biner di mana R adalah simpul akar dari pohon tersebut. KIRI dan KANAN masing-masing adalah sub-pohon kiri dan kanan dari R. A ditetapkan sebagai simpul akar dari pohon tersebut. Node B dan C masing-masing adalah anak kiri dan kanan dari A. Node B, D, E, dan G merupakan sub-pohon kiri dari akar. Demikian pula, node C, F, H, dan I merupakan sub-pohon kanan dari akar.

Keuntungan dari sebuah pohon
1. Proses pencarian sangat cepat di pohon.
2. Penyisipan dan penghapusan elemen menjadi lebih mudah dibandingkan dengan struktur data lainnya.

Pohon biner adalah struktur data hirarkis di mana setiap simpul memiliki paling banyak dua anak, yaitu anak kiri dan anak kanan. Dalam pohon biner, derajat setiap simpul paling banyak dua. Pohon biner digunakan untuk mengimplementasikan pohon pencarian biner, yang digunakan untuk pencarian dan penyortiran yang efisien. Pohon biner adalah subtipe populer dari pohon k-ary, di mana k adalah 2.

Sebuah graf adalah sebuah pohon umum tanpa hubungan orang tua dan anak. Graf adalah struktur data non-linear yang terdiri dari simpul, juga disebut node, dan sisi yang menghubungkan simpul-simpul tersebut satu sama lain. Dalam sebuah graf, setiap hubungan yang kompleks dapat terjadi. Sebuah graf G dapat didefinisikan sebagai himpunan berhingga dari V simpul dan E sisi. Oleh karena itu, G (V, E) di mana V adalah himpunan simpul dan E adalah himpunan sisi. Graf digunakan dalam berbagai aplikasi matematika dan ilmu komputer. Tidak seperti simpul akar pada pohon, graf tidak memiliki simpul akar, melainkan simpul-simpul tersebut dapat dihubungkan dengan simpul manapun pada graf. Dua buah node disebut sebagai tetangga ketika mereka terhubung melalui sebuah sisi.

## Guided 
### 1. Graph
```C++
#include <iostream>
#include <iomanip> 
using namespace std;

string simpul[7] = { 
    "Ciamis",  
    "Bandung",  
    "Bekasi",  
    "tasikmalaya", 
    "Cianjur",  
    "Purwokerto",  
    "Yogyakarta" 
};

int busur[7][7] = { 
    {0, 7, 8, 0, 0, 0, 0}, 
    {0, 0, 5, 0, 0, 15, 0}, 
    {0, 6, 0, 0, 5, 0, 0}, 
    {0, 5, 0, 0, 2, 4, 0}, 
    {23, 0, 0, 10, 0, 0, 8}, 
    {0, 0, 0, 0, 7, 0, 3}, 
    {0, 0, 0, 0, 9, 4, 0} 
};

void tampilGraph(){ 
    for (int baris = 0; baris <7; baris ++){ 
        cout <<" " << setiosflags (ios::left)<<setw (15) << simpul [baris] << " : "; 
            for (int kolom = 0; kolom<7; kolom++){ 
                if (busur[baris][kolom]!=0){ 
                    cout << " " << simpul[kolom]<< "(" << busur[baris][kolom]  << ")"; 
            } 
        } 
        cout << endl; 
    }
} 

int main(){ 
    tampilGraph();
return 0; 
}


```
#### Output:
![Screenshot 2024-05-29 092252](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/5ac64067-74cb-4e68-bee4-00198e7a3c82)
Kode C++ yang diberikan menampilkan representasi graf terarah dengan menggunakan adjacency matrix. Array simpul menyimpan nama-nama simpul, dan matriks busur menyimpan bobot antar simpul. Fungsi tampilGraph() iterasi melalui setiap simpul dan tetangganya, mencetak nama simpul dan nama-nama tetangganya beserta bobot busur yang menghubungkan mereka. Fungsi main() memanggil fungsi tampilGraph() untuk menampilkan representasi graf. Kode ini hanya menunjukkan graf terarah dan dapat dimodifikasi untuk graf tidak terarah dan menambahkan fitur lain seperti mencari jalur terpendek.

### 2. Tree
```C++
#include <iostream>
using namespace std;

// PROGRAM BINARY TREE
// Deklarasi Pohon
struct Pohon {
    char data;
    Pohon *left, *right, *parent; //pointer
};

//pointer global
Pohon *root;

// Inisialisasi
void init() {
    root = NULL;
}

bool isEmpty() {
    return root == NULL;
}

Pohon *newPohon(char data) {
    Pohon *node = new Pohon();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

void buatNode(char data) {
    if (isEmpty()) {
        root = newPohon(data);
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    } else {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

Pohon *insertLeft(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->left != NULL) {
            cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        } else {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
            return baru;
        }
    }
}

Pohon *insertRight(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->right != NULL) {
        cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
        return NULL;
        } else {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
            return baru;
        }
    }
}

void update(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

void retrieve(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else {
            cout << "\nData node : " << node->data << endl;
        }
    }
}

void find(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else {
        cout << "\nData Node : " << node->data << endl;
        cout << "Root : " << root->data << endl;
            if (!node->parent)
                cout << "Parent : (tidak punya parent)" << endl;
            else
                cout << "Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << "Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "Sibling : " << node->parent->right->data << endl;
            else
                cout << "Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri : " << node->left->data << endl;
            if (!node->right)
                cout << "Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << "Child Kanan : " << node->right->data << endl;
        }
    }
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
        cout << " " << node->data << ", ";
        preOrder(node->left);
        preOrder(node->right);
        }
    }
}

// inOrder
void inOrder(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
        inOrder(node->left);
        cout << " " << node->data << ", ";
        inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << " " << node->data << ", ";
        }
    }
}

// Hapus Node Tree
void deleteTree(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            if (node != root) {
                if (node->parent->left == node)
                    node->parent->left = NULL;
                else if (node->parent->right == node)
                    node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
        if (node == root) {
            delete root;
            root = NULL;
        } else {
            delete node;
            }
        }
    }
}

// Hapus SubTree
void deleteSub(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data << " berhasil dihapus." << endl;
    }
}

// Hapus Tree
void clear() {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}
    // Cek Size Tree
int size(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    } else {
        if (!node) {
            return 0;
        } else {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Cek Height Level Tree
int height(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    } else {
        if (!node) {
        return 0;
        } else {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);

            if (heightKiri >= heightKanan) {
                return heightKiri + 1;
            } else {
                return heightKanan + 1;
            }
        }
    }
}

// Karakteristik Tree
void characteristic() {
    int s = size(root);
    int h = height(root);
    cout << "\nSize Tree : " << s << endl;
    cout << "Height Tree : " << h << endl;
    if (h != 0)
        cout << "Average Node of Tree : " << s / h << endl;
    else
        cout << "Average Node of Tree : 0" << endl;
}

int main() {
    init();
    buatNode('A');
    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ;
    
    nodeB = insertLeft('B', root);
    nodeC = insertRight('C', root);
    nodeD = insertLeft('D', nodeB);
    nodeE = insertRight('E', nodeB);
    nodeF = insertLeft('F', nodeC);
    nodeG = insertLeft('G', nodeE);
    nodeH = insertRight('H', nodeE);
    nodeI = insertLeft('I', nodeG);
    nodeJ = insertRight('J', nodeG);
    
    update('Z', nodeC);
    update('C', nodeC);
    retrieve(nodeC);
    find(nodeC);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n" << endl;
    cout << "InOrder :" << endl;
    inOrder(root);
    cout << "\n" << endl;
    cout << "PostOrder :" << endl;
    postOrder(root);
    cout << "\n" << endl;
    characteristic();
    deleteSub(nodeE);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n" << endl;
    characteristic();
}
```
#### Output:
![Screenshot 2024-05-29 092431](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/b82135e7-ad37-4f2b-913a-4e3e507b0e19)
![Screenshot 2024-05-29 092505](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/d26b23c5-bce6-4915-9143-d3769adae8b6)
Kode C++ ini mengimplementasikan struktur data pohon biner dengan fungsi-fungsi untuk pembuatan, manipulasi, dan penelusuran. Pohon biner diwakili dengan struktur Pohon yang berisi data, pointer ke anak kiri dan kanan, dan pointer ke parent. Fungsi init() menginisialisasi pohon, buatNode() membuat node baru, insertLeft() dan insertRight() menambahkan node ke child kiri dan kanan, update() memperbarui data node, retrieve() dan find() menampilkan informasi node, preOrder(), inOrder(), dan postOrder() melakukan penelusuran pohon dengan urutan pre-order, in-order, dan post-order. deleteTree(), deleteSub(), dan clear() menghapus node dan subtree. size() menghitung jumlah node, height() menghitung tinggi pohon, dan characteristic() menampilkan informasi karakteristik pohon. Fungsi main() mendemonstrasikan penggunaan fungsi-fungsi tersebut untuk membangun pohon, melakukan operasi pada node, melakukan penelusuran, dan menampilkan informasi karakteristik pohon.

## Unguided
### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.
```C++

```
#### Output:


### 2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!
```C++

```
#### Output:


## Kesimpulan


## Referensi
Malhotra, D., & Malhotra, N. (2019). Data Structures and Program Design Using C++. Mercury Learning and Information.
