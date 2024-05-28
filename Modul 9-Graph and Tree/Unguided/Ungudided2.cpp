#include <iostream>
#include <iomanip> 
using namespace std;



 

int main(){

int jumlah, b,c;

string simpul[jumlah];

int busur[7][7] = { 
    {0, 7, 8, 0, 0, 0, 0}, 
    {0, 0, 5, 0, 0, 15, 0}, 
    {0, 6, 0, 0, 5, 0, 0}, 
    {0, 5, 0, 0, 2, 4, 0}, 
    {23, 0, 0, 10, 0, 0, 8}, 
    {0, 0, 0, 0, 7, 0, 3}, 
    {0, 0, 0, 0, 9, 4, 0} 
};
    cout << "Silahkan masukkan jumlah simpul : ";
    cin >> jumlah;


    cout << "Silahkan masukkan nama simpul" << endl;
    for (int i=0; i<jumlah; i++){
        cout << "Simpul " << i+1 << " : ";
        cin >> simpul[i];
    }
    cout << "Silahakan masukkan bobot antar simpul";
    cin >> b >> c;
    

        cout << setw (21);
    for (int i=0; i<jumlah; i++){
        cout << "   " <<simpul[i];
    }
    cout << endl;

    for (int baris = 0; baris < jumlah; baris ++){ 
        cout <<" " << setiosflags (ios::left) <<setw (15) << simpul [baris] << " : " << ends; 
            for (int kolom = 0; kolom < 7; kolom++){ 

                    cout << "   " << "(" << busur[baris][kolom]  << ")"; 
            
        } 
        cout << endl; 
    }
return 0; 
}

