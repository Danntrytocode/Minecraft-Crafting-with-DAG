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
    //metode utama Topological Sorting (Algoritma Kahn)
    void cariUrutanCrafting() {
        int hasilUrutan[10];
        int jumlahHasil = 0;

        //1.cari semua bahan dasar (in-degree 0) dan masukkan ke Antrean
        for(int i = 0; i < jumlahItem; i++) {
            if(inDegree[i] == 0) {
                antrean[rear] = i;
                rear++;
            }
        }
        //2.proses antrean selama masih ada isinya
        while(front < rear) {
            //Keluarkan item dari antrean paling depan
            int itemSekarang = antrean[front];
            front++;
            
            //Simpan item tersebut ke daftar hasil
            hasilUrutan[jumlahHasil] = itemSekarang;
            jumlahHasil++;
        
            //3.Hapus panah ke item turunan (kurangi in-degree mereka)
            for(int i = 0; i < jumlahItem; i++) {
                if(hubMatrix[itemSekarang][i] == 1) {
                    inDegree[i]--;
                    
                    //Jika prasyarat item turunan sudah habis (0), antrekan!
                    if(inDegree[i] == 0) {
                        antrean[rear] = i;
                        rear++;
                    }
                }
            }
        }
        //output hasil akhir
        cout << "==================================" << endl;
        cout << "Urutan Crafting Enchantment Table:" << endl;
        cout << "==================================" << endl;
        for(int i = 0; i < jumlahHasil; i++) {
            cout << i + 1 << ". " << namaItem[hasilUrutan[i]] << endl;
        }
    }
};

int main(){
    CraftingDAG minecraft;

    //Input Nilai Item
    int sugarCane = minecraft.tambahItem("Sugar Cane");
    int paper = minecraft.tambahItem("Paper");
    int leather = minecraft.tambahItem("Leather");
    int book = minecraft.tambahItem("Book");
    int diamond = minecraft.tambahItem("Diamond");
    int obsidian = minecraft.tambahItem("Obsidian");
    int enchantTable = minecraft.tambahItem("Enchantment Table");

    //Menambahkan Arah Resep (Bahan Baku -> Hasil)
    minecraft.tambahDependensi(sugarCane,paper);
    minecraft.tambahDependensi(paper,book);
    minecraft.tambahDependensi(leather,book);
    minecraft.tambahDependensi(book,enchantTable);
    minecraft.tambahDependensi(diamond,enchantTable);
    minecraft.tambahDependensi(obsidian,enchantTable);
}