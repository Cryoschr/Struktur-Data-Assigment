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

void showChild(Pohon *node) {
    if (node) {
        if (node->left)
            cout << "\nChild Kiri : " << node->left->data;
        else
            cout << "\nChild Kiri : (tidak punya Child kiri)";

        if (node->right)
            cout << "\nChild Kanan : " << node->right->data;
        else
            cout << "\nChild Kanan : (tidak punya Child kanan)";
    } else {
        cout << "\nNode yang ditunjuk tidak ada!";
    }
}

int main() {
    char data;
    int pilihan;
    char parentData;
    Pohon *node = NULL;

    do {
        cout << "\nMenu:\n";
        cout << "1. Buat Node Root\n";
        cout << "2. Tambah Node Kiri\n";
        cout << "3. Tambah Node Kanan\n";
        cout << "4. Update Node\n";
        cout << "5. Retrieve Node\n";
        cout << "6. Find Node\n";
        cout << "7. PreOrder Traversal\n";
        cout << "8. InOrder Traversal\n";
        cout << "9. PostOrder Traversal\n";
        cout << "10. Hapus SubTree\n";
        cout << "11. Hapus Seluruh Tree\n";
        cout << "12. Cek Karakteristik Tree\n";
        cout << "13. Tampilkan Anak Node\n";
        cout << "14. Tampilkan Descendant Node\n";
        cout << "15. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data untuk root: ";
                cin >> data;
                buatNode(data);
                break;
            case 2:
                    cout << "Masukkan data untuk node kiri: ";
                    cin >> data;
                    cout << "Masukkan data parent: ";
                    cin >> parentData;
                    node = root;
                    while (node && node->data != parentData) {
                        node = (node->left ? node->left : node->right);
                    }
                    insertLeft(data, node);
                break;
            case 3:
                    cout << "Masukkan data untuk node kanan: ";
                    cin >> data;
                    cout << "Masukkan data parent: ";
                    cin >> parentData;
                    node = root;
                    while (node && node->data != parentData) {
                        node = (node->left ? node->left : node->right);
                    }
                    insertRight(data, node);
                break;
            case 4:
                    cout << "Masukkan data node yang ingin diupdate: ";
                    char oldData;
                    cin >> oldData;
                    cout << "Masukkan data baru: ";
                    cin >> data;
                    node = root;
                    while (node && node->data != oldData) {
                        node = (node->left ? node->left : node->right);
                    }
                    update(data, node);
                break;
            case 5:

                    cout << "Masukkan data node yang ingin di-retrieve: ";
                    cin >> data;
                    node = root;
                    while (node && node->data != data) {
                        node = (node->left ? node->left : node->right);
                    }
                    retrieve(node);
                break;
            case 6:
                    cout << "Masukkan data node yang ingin dicari: ";
                    cin >> data;
                    node = root;
                    while (node && node->data != data) {
                        node = (node->left ? node->left : node->right);
                    }
                    find(node);
                break;
            case 7:
                cout << "\nPreOrder :" << endl;
                preOrder(root);
                cout << "\n" << endl;
                break;
            case 8:
                cout << "\nInOrder :" << endl;
                inOrder(root);
                cout << "\n" << endl;
                break;
            case 9:
                cout << "\nPostOrder :" << endl;
                postOrder(root);
                cout << "\n" << endl;
                break;
            case 10:
                    cout << "Masukkan data node yang subtreenya ingin dihapus: ";
                    cin >> data;
                    node = root;
                    while (node && node->data != data) {
                        node = (node->left ? node->left : node->right);
                    }
                    deleteSub(node);
                break;
            case 11:
                clear();
                break;
            case 12:
                characteristic();
                break;
            case 13:
                    cout << "Masukkan data node: ";
                    cin >> data;
                    node = root;
                    while (node && node->data != data) {
                        node = (node->left ? node->left : node->right);
                    }
                    showChild(node);
                break;
            case 14:
                    cout << "Masukkan data node: ";
                    cin >> data;
                    node = root;
                    while (node && node->data != data) {
                        node = (node->left ? node->left : node->right);
                    }
                break;
            case 15:
                cout << "Keluar..." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 15);
}