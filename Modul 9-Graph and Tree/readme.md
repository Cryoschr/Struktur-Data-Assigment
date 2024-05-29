# <h1 align="center">Laporan Praktikum Modul Stack</h1>
<p align="center">Irshad Benaya Fardeca</p>
<p align="center">S1-IF-11E</p>
<p align="center"> 2311102199</p>

# Dasar Teori
1. Graf
    Sebuah graf adalah sebuah pohon umum tanpa hubungan orang tua dan anak. Graf adalah struktur data non-linear yang terdiri dari simpul, juga disebut node, dan sisi yang menghubungkan simpul-simpul tersebut satu sama lain. Dalam sebuah graf, setiap hubungan yang kompleks dapat terjadi. Sebuah graf G dapat didefinisikan sebagai himpunan berhingga dari V simpul dan E sisi. Oleh karena itu, G (V, E) di mana V adalah himpunan simpul dan E adalah himpunan sisi. Graf digunakan dalam berbagai aplikasi matematika dan ilmu komputer. Tidak seperti simpul akar pada pohon, graf tidak memiliki simpul akar, melainkan simpul-simpul tersebut dapat dihubungkan dengan simpul manapun pada graf. Dua buah node disebut sebagai tetangga ketika mereka terhubung melalui sebuah sisi.[1]
Jenis-jenis Graph:
a. Graph berarah (directed graph): Urutan simpul mempunyai arti. Misal busur AB adalah e1 sedangkan busur BA adalah e8.
b. Graph tak berarah (undirected graph): Urutan simpul dalam sebuah busur tidak
diperhatikan. Misal busur e1 dapat disebut busur AB atau BA.
c. Weight Graph : Graph yang mempunyai nilai pada tiap edgenya.[2]
   
2. Tree
    Tree adalah struktur data non-linear yang populer di mana elemen data atau node direpresentasikan dalam urutan hirarki. Di sini, salah satu node ditampilkan sebagai node akar dari Tree, dan node yang tersisa dibagi menjadi dua himpunan yang terputus-putus sehingga setiap himpunan merupakan bagian dari sub-Tree. Tree membuat proses pencarian menjadi sangat mudah, dan pemrograman rekursifnya membuat program menjadi lebih optimal dan mudah dimengerti.
    Binary Tree adalah bentuk paling sederhana dari sebuah Tree. Binary Tree terdiri dari sebuah simpul akar dan dua subTree yang dikenal sebagai subTree kiri dan subTree kanan, di mana kedua subTree tersebut juga merupakan Binary Tree. Setiap node dalam sebuah Tree terdiri dari tiga bagian, yaitu bagian paling kiri menyimpan sebuah pointer yang menunjuk ke subTree kiri, bagian tengah akan terdiri dari elemen data, dan bagian paling kanan menyimpan sebuah pointer yang menunjuk ke subTree kanan. Akar adalah elemen paling atas dari Tree. Ketika tidak ada node dalam sebuah Tree, yaitu ketika ROOT = NULL, maka Tree tersebut disebut Tree kosong.
Keuntungan dari sebuah Tree:
1. Proses pencarian sangat cepat di Tree.
2. Penyisipan dan penghapusan elemen menjadi lebih mudah dibandingkan dengan struktur data lainnya.[1]
Operasi pada Tree:
a. Create: digunakan untuk membentuk binary tree baru yang masih kosong.
b. Clear: digunakan untuk mengosongkan binary tree yang sudah ada atau menghapus semua node pada binary tree.
c. isEmpty: digunakan untuk memeriksa apakah binary tree masih kosong atau tidak.
d. Insert: digunakan untuk memasukkan sebuah node kedalam tree.
e. Find: digunakan untuk mencari root, parent, left child, atau right child dari suatu nnode dengan syarat tree tidak boleh kosong.
f. Update: digunakan untuk mengubah isi dari node yang ditunjuk oleh pointer ncurrent dengan syarat tree tidak boleh kosong.
g. Retrive: digunakan untuk mengetahui isi dari node yang ditunjuk pointer current dengan syarat tree tidak boleh kosong.
h. Delete Sub: digunakan untuk menghapus sebuah subtree (node beserta seluruh descendant-nya) yang ditunjuk pointer current dengan syarat tree tidak boleh kosong.
i. Characteristic: digunakan untuk mengetahui karakteristik dari suatu tree. Yakni size, height, serta average lenght-nya.
j. Traverse: digunakan untuk mengunjungi seluruh node-node pada tree dengan cara traversal. Terdapat 3 metode traversal yang dibahas dalam modul ini yakni Pre-Order, In-Order, dan Post-Order.


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
Program yang diberikan menampilkan representasi graf terarah dengan menggunakan adjacency matrix. Array simpul menyimpan nama-nama simpul, dan matriks busur menyimpan bobot antar simpul. Fungsi tampilGraph() iterasi melalui setiap simpul dan tetangganya, mencetak nama simpul dan nama-nama tetangganya beserta bobot busur yang menghubungkan mereka. Fungsi main() memanggil fungsi tampilGraph() untuk menampilkan representasi graf.

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
Program ini mengimplementasikan struktur data pohon biner dengan fungsi-fungsi untuk pembuatan, manipulasi, dan penelusuran. Pohon biner diwakili dengan struktur Pohon yang berisi data, pointer ke anak kiri dan kanan, dan pointer ke parent. Fungsi init() menginisialisasi pohon, buatNode() membuat node baru, insertLeft() dan insertRight() menambahkan node ke child kiri dan kanan, update() memperbarui data node, retrieve() dan find() menampilkan informasi node, preOrder(), inOrder(), dan postOrder() melakukan penelusuran pohon dengan urutan pre-order, in-order, dan post-order. deleteTree(), deleteSub(), dan clear() menghapus node dan subtree. size() menghitung jumlah node, height() menghitung tinggi pohon, dan characteristic() menampilkan informasi karakteristik pohon. Fungsi main() mendemonstrasikan penggunaan fungsi-fungsi tersebut untuk membangun pohon, melakukan operasi pada node, melakukan penelusuran, dan menampilkan informasi karakteristik pohon.

## Unguided
### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.
```C++
#include <iostream>
#include <iomanip> 
using namespace std;

int jumlah_2311102199;
int bobot;
string namaSimpul;

int main(){
//input jumlah simpul
    cout << "Silahkan masukkan jumlah simpul : ";
    cin >> jumlah_2311102199;

//dearasi array
string simpul[jumlah_2311102199];
int busur[jumlah_2311102199][jumlah_2311102199];

//input nama simpul
    cout << "Silahkan masukkan nama simpul" << endl;
    for(int i=0; i<jumlah_2311102199; i++){
        cout << "Simpul " << i+1 << " : ";
        cin >> namaSimpul;
        simpul[i] = namaSimpul;
    }

//input bobot simpul
    cout << "Silahkan Masukkan bobot antar simpul" << endl;
    for (int i = 0; i < jumlah_2311102199; i++){
        for (int j = 0; j < jumlah_2311102199; j++){
            cout << simpul[i] << " --> " << simpul[j] << " = ";
            cin >> bobot;
            busur[i][j] = bobot;
        }
    }

//menampilkan graf
    cout << setw(10) << " ";
    for (int i = 0; i<jumlah_2311102199; i++){
        cout << setw(10) << simpul[i];
    }
    cout << endl;

    for (int i = 0; i < jumlah_2311102199; i++){
        cout << setw(10) << simpul[i];
        for (int j = 0; j < jumlah_2311102199; j++){
            cout << setw(10) << busur[i][j];
        }
        cout << endl;
    }

return 0; 
}


```
#### Output:
![Screenshot 2024-05-29 214855](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/d521d5a2-1dc4-46fe-9523-45de2cd6b33c)
Program ini pertama meminta pengguna untuk memasukkan jumlah simpul dalam graf. Kemudian, program membuat dua array: yang pertama untuk menyimpan nama simpul dan yang kedua untuk menyimpan bobot sisi. Setelah itu, program meminta pengguna untuk memasukkan nama untuk setiap simpul dan bobot untuk setiap sisi. Terakhir, program menampilkan representasi graf dalam bentuk matriks, yang menunjukkan bobot sisi antara setiap pasangan simpul.

### 2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!
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

// Menampilkan Child dan Descendant dari Node yang Diinputkan
void displayChildren(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\nChild Node " << node->data << " : " << endl;
            if (node->left)
                cout << "Child Kiri : " << node->left->data << endl;
            else
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            if (node->right)
                cout << "Child Kanan : " << node->right->data << endl;
            else
                cout << "Child Kanan : (tidak punya Child kanan)" << endl;
        }
    }
}

void displayDescendants(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\nDescendants of Node " << node->data << " :" << endl;
            preOrder(node->left);
            preOrder(node->right);
            cout << endl;
        }
    }
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
    displayChildren(nodeF);
    displayDescendants(nodeB);
}
```
#### Output:
![Screenshot 2024-05-29 225616](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/6b51b852-45a2-4aac-bbda-a58bb7a2bf08)
![Screenshot 2024-05-29 225636](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/59eb1480-5b06-4ffc-8a97-27d0c38d9765)

Program ini mendefinisikan struktur bernama Pohon untuk mewakili node dalam pohon biner, beserta berbagai fungsi untuk mengelolanya. Fungsi-fungsi tersebut meliputi inisialisasi (init()), pengecekan pohon kosong (isEmpty()), pembuatan node baru (newPohon()), pembuatan node root (buatNode()), penyisipan node sebagai anak (insertLeft(), insertRight()), pembaruan data node (update()), pengambilan data node (retrieve()), pencarian node tertentu (find()), penelusuran pohon (pre-order, in-order, post-order), penghapusan subtree (deleteSub()), pembersihan seluruh pohon (clear()), analisis karakteristik pohon (size(), height(), characteristic()), tampilan anak dari suatu node (tampilkanChildren()), dan tampilan keturunan dari suatu node (tampilkanDescendants()).

## Kesimpulan
Graf digunakan untuk merepresentasikan hubungan antar objek, di mana setiap objek dapat terhubung dengan objek lain tanpa batasan. Graf dapat diklasifikasikan menjadi graf berarah, graf tak berarah, dan graf terbobot. Graf banyak digunakan dalam berbagai aplikasi, seperti jejaring sosial, pemetaan jalan, dan pemodelan data.

Pohon digunakan untuk merepresentasikan data hierarki, di mana terdapat hubungan atas-bawah antar objek. Pohon memiliki struktur yang lebih terstruktur dibandingkan graf, dengan satu node akar dan node-node lain yang terhubung dengan node akar atau node lain. Pohon banyak digunakan dalam berbagai aplikasi, seperti silsilah keluarga, skema turnamen, dan struktur organisasi.

## Referensi
[1] Malhotra, D., & Malhotra, N. (2019). Data Structures and Program Design Using C++. Mercury Learning and Information.
[2] MODUL 9 GRAPH AND TREE
