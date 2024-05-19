//Irshad Benaya Fardeca
//2311102199

#include <iostream>
using namespace std;

//deklarasi
struct antrianMahasiswa{
  string nama;
  string nim;

  antrianMahasiswa *next;
};

//maks data
int maksimalAntrianMahasiswa = 5;
antrianMahasiswa *head, *tail, *cur, *del, *newNode;

//menghitung data
int countQueue(){
  if( head == NULL ){
    return 0;
  }else{
    int banyak = 0;
    cur = head;
    while( cur != NULL ){
      cur = cur->next;
      banyak++;
    }
    return banyak;
  }
}

//mengecek data apakah penuh
bool isFull(){
  if( countQueue() == maksimalAntrianMahasiswa ){
    return true;
  }else{
    return false;
  }
}

//mengecek data apakah kosong
bool isEmpty(){
  if( countQueue() == 0 ){
    return true;
  }else{
    return false;
  }
}

//memasukkan data ke dalam queue
void enqueueAntrian(string nama, string nim){
  if( isFull() ){
    cout << "Antrian Penuh" << endl;
  }else{
    
    if( isEmpty() ){
      head = new antrianMahasiswa();
      head->nama = nama;
      head->nim = nim;
      head->next = NULL;
      tail = head;
    }else{
      newNode = new antrianMahasiswa();
      newNode->nama = nama;
      newNode->nim = nim;
      newNode->next = NULL;
      tail->next = newNode;
      tail = newNode;
    }

  }

}

//mengeluarkan data dari queue
void dequeueAntrian(){
  if( isEmpty() ){
    cout << "Antrian kosong" << endl;
  }else{
    del = head;
    head = head->next;
    del->next = NULL;
    delete del;
  }
}

//menghapus semua data
void clearQueue(){
  if( isEmpty() ){
    cout << "Antrian kosong" << endl;
  }else{
    cur = head;
    while( cur != NULL ){
      del = cur;
      cur = cur->next;
      del->next = NULL;
      delete del;
    }
    head = NULL;
    tail = NULL;
  }
}

//menampilkan queue
void viewQueue(){
  cout << "Daftar Antrian Mahasiswa : " << endl;
    cur = head;
    int nomor = 1;
    while( nomor <= maksimalAntrianMahasiswa ){
      
      if( cur != NULL ){
        cout << nomor << ". " << cur->nama << "_" << cur->nim << endl;
        cur = cur->next;
      }else{
        cout << nomor << ". " << "(kosong)" << endl;
      }
      nomor++;
    }
}


int main(){

  enqueueAntrian("Maya", "2311102188");
  enqueueAntrian("Sela", "2311102189");
  enqueueAntrian("Andi", "2311102190");
  enqueueAntrian("Irshad", "2311102199");
  enqueueAntrian("Ani", "231103288");
  viewQueue();
  cout << "Jumlah antrian = " << countQueue() << endl;

  dequeueAntrian();
  viewQueue();
  cout << "Jumlah antrian = " << countQueue() << endl;

  dequeueAntrian();
  viewQueue();
  cout << "Jumlah antrian = " << countQueue() << endl;

  clearQueue();
  viewQueue();
  cout << "Jumlah antrian = " << countQueue() << endl;


return 0;
}