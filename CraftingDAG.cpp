#include <iostream>

using namespace std;

class CraftingDAG {
private:
    string namaItem[10];//Array penyimpan nama bahan
    int hubMatrix[10][10];//Matriks Ketetanggaan (Arah Graf)
    int inDegree[10];//Array penyimpan jumlah prasyarat (panah masuk)
    int jumlahItem;
    
    //Variabel untuk Queue
    int antrean[10];
    int front;
    int rear;
};