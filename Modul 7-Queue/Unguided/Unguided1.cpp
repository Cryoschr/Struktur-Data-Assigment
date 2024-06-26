//Irshad Benaya Fardeca
//2311102199

#include <iostream>
using namespace std;

//deklarasi
struct antrianTeller{
  string data;

  antrianTeller *next;
};

//maks antrian
int maksimalAntrianTeller = 5;
antrianTeller *head, *tail, *cur, *del, *newNode;

//menghitung banyak antrian
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

//mengecek apakah penuh
bool isFull(){
  if( countQueue() == maksimalAntrianTeller ){
    return true;
  }else{
    return false;
  }
}

//mengecek apakah kosong
bool isEmpty(){
  if( countQueue() == 0 ){
    return true;
  }else{
    return false;
  }
}

//memasukkan kedalam antrian
void enqueueAntrian(string data){
  if( isFull() ){
    cout << "Antrian Penuh" << endl;
  }else{
    
    if( isEmpty() ){
      head = new antrianTeller();
      head->data = data;
      head->next = NULL;
      tail = head;
    }else{
      newNode = new antrianTeller();
      newNode->data = data;
      newNode->next = NULL;
      tail->next = newNode;
      tail = newNode;
    }

  }

}

//mengluarkan darri antrian
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

//menghapus semua antrian
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

//menampilkan antrian
void viewQueue(){
  cout << "Data Antrian Teller : " << endl;
    cur = head;
    int nomor = 1;
    while( nomor <= maksimalAntrianTeller ){
      
      if( cur != NULL ){
        cout << nomor << ". " << cur->data << endl;
        cur = cur->next;
      }else{
        cout << nomor << ". " << "(kosong)" << endl;
      }
      nomor++;
    }
}


int main(){

  enqueueAntrian("Andi");
  enqueueAntrian("Maya");
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