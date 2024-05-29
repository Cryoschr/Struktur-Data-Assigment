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

