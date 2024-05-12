//Irshad Benaya Fardeca
//2311102199

#include <iostream>
using namespace std;

struct Stack {
  char data[100];
  int top;

  Stack() {
    top = -1;
  }

  //apakah stack kosong
  bool isEmpty() {
    return top == -1;
  }

  //apakah stack penuh
  bool isFull() {
    return top == 99;
  }

//memasukkan data
  void push(char kata) {
    if (isFull()) {
      cout << "Stack penuh" << endl;
      return;
    }
    data[++top] = kata;
  }


  char pop() {
    if (isEmpty()) {
      cout << "Tidak ada data yang dihapus" << endl;
    }
    return data[top--];

  }
};

int main() {
  string kata;
  Stack tumpukan;

  //Input kata
  cout << "Masukkan kata: ";
  getline(cin, kata);

  // Memasukkan setiap karakter kata ke dalam stack
  for (char c : kata) {
    tumpukan.push(c);
  }

  // Membalik kata dengan mengeluarkan karakter dari stack
  kata = "";
  while (!tumpukan.isEmpty()) {
    kata += tumpukan.pop();
  }

  // Menampilkan kata yang dibalik
  cout << "Kata setelah dibalik: " << kata << endl;

  return 0;
}
