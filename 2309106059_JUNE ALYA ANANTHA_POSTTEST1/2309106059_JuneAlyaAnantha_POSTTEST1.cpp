#include <iostream>

using namespace std;

void Hanoi(int piringan, char menara_asal, char menara_tujuan, char menara_sementara) {
    if (piringan == 1) {
        cout << "Pindahkan piringan 1 dari " << menara_asal << " ke " << menara_tujuan << endl;
        return;
    }
    
    Hanoi(piringan - 1, menara_asal, menara_sementara, menara_tujuan);
    cout << "Pindahkan piringan " << piringan << " dari " << menara_asal << " ke " << menara_tujuan << endl;
    Hanoi(piringan - 1, menara_sementara, menara_tujuan, menara_asal);
}

int main() {
    int piringan;
    
    cout << "" << endl;
    cout << "Masukkan banyak piringan: ";
    cin >> piringan;
    
    cout << "Menara Asal = A" << endl;
    cout << "Menara Sementara = B" << endl;
    cout << "Menara Tujuan = C" << endl;
    cout << endl;
    
    cout << "Solusi perpindahan piringan:" << endl;
    Hanoi(piringan, 'A', 'C', 'B');
    
    return 0;
}