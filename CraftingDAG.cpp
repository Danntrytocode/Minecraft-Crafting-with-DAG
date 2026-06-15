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
public:
    //Constructor untuk inisialisasi nilai awal
    CraftingDAG() {
        jumlahItem = 0;
        front = 0;
        rear = 0;
        for(int i = 0; i < 10; i++) {
            inDegree[i] = 0;
            for(int j = 0; j < 10; j++) {
                hubMatrix[i][j] = 0;
            }
        }
    }
    //metode regis item baru
    int tambahItem(string nama) {
        namaItem[jumlahItem] = nama;
        jumlahItem++;
        return jumlahItem - 1;
    }
    //fungsi untuk menyambung panah/sisi
    void tambahDependensi(int indeksBahan, int indeksHasil) {
        hubMatrix[indeksBahan][indeksHasil] = 1;
        inDegree[indeksHasil]++; // Tambah jumlah prasyarat item hasil
    }
};