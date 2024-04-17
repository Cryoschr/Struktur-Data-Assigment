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