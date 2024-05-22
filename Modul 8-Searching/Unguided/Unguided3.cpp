//Irshad Benaya Fardeca
//2311102199

#include <iostream>

using namespace std;

int main() {
  int ukuran = 10;
  int data[ukuran] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
  int count = 0;

  for (int i = 0; i < ukuran; i++) {
    if (data[i] == 4) {
      count++;
    }
  }

  cout << "Data : ";
  for(int i; i<10; i++){
    cout << data[i] << " ";
  }
  cout << endl;

  cout << "Banyaknya angka 4 dalam data adalah: " << count << endl;

  return 0;
}
