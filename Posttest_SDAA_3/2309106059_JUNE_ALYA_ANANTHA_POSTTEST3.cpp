#include <iostream>

using namespace std;

struct travel
{

    string jenis_bus;
    string besar_muatan;
    string harga;
    travel *next;

};
travel bus[100];

struct pemesanan
{
    
    string nama_pemesan;
    string no_hp_pemesan;
    int tanggal_pemesanan;
    int bulan_pemesanan;
    int tahun_pemesanan;
    string jenis_bus;
    string harga;
    int harga_total;
    pemesanan *next;

};
pemesanan order[100];

int jml_data = 0;
int idx_bus, idx_pemesanan, idx;

void lihat_data_bus(travel *&head)
{
    travel *temp = head;
    int nomor = 1;

    if (temp == nullptr)
    {
        cout << "" << endl;
        cout << "Data bus masih kosong." << endl;
        return;
    }

    cout << "Berikut Jenis bus yang Available Beserta Harganya." << endl;
    while (temp != nullptr) 
    {
        cout << nomor << ". " << temp->jenis_bus << " | " << "Maximal Menampung " << temp->besar_muatan << " Orang" << " | Rp. " << temp->harga << endl;
        temp = temp->next;
        nomor++;
    }
    cout << "" << endl;

}

int total_harga(int *harga_bus, int &jml_tiket)
{

    if (jml_tiket == 1)
    {
        return *harga_bus;
    }

    else
    {
        jml_tiket = jml_tiket - 1;
        return *harga_bus + total_harga(harga_bus, jml_tiket);
    }
}

void tambah_data(travel *&head)
{
    string jenis;
    string muatan;
    string hrga;

    travel *baru = new travel;

    cin.ignore();
    cout << "" << endl;
    cout << "Masukkan Jenis Bus yang Ingin Dipesan: ";
    fflush(stdin);
    getline(cin, jenis);
    cout << "Masukkan Muatan Maximal Bus (Berapa Orang) : ";
    fflush(stdin);
    getline(cin, muatan);
    cout << "Harga Tiket Bus: ";
    fflush(stdin);
    getline(cin, hrga);

    baru->jenis_bus = jenis;
    baru->besar_muatan = muatan;
    baru->harga = hrga;
    baru->next = head;
    head = baru;

    cout << "" << endl;
}

void edit_data(travel *&head)
{
    string jenis;
    string muatan;
    string hrga;

    travel *temp = head;

    if (head == nullptr)
    {
        cout << "" << endl;
        cout << "Data bus masih kosong." << endl;
        return;
    }

    cout << "" << endl;
    lihat_data_bus(head);
    cout << "Masukkan urutan bus yang ingin diedit: " << endl;
    cin >> idx;


    for (int i = 1; i < idx; i++)
    {
        temp = temp->next;
    }

    cin.ignore();
    cout << "Masukkan Jenis Bus: ";
    fflush(stdin);
    getline(cin, jenis);
    cout << "Masukkan Muatan Maximal Bus (Berapa Orang) : ";
    fflush(stdin);
    getline(cin, muatan);
    cout << "Harga Tiket Bus: ";
    fflush(stdin);
    getline(cin, hrga);

    temp->jenis_bus = jenis;
    temp->besar_muatan = muatan;
    temp->harga = hrga;

    cout << "Data bus berhasil diedit." << endl;
    cout << "" << endl;
}

void hapus_data(travel *&head)
{
    travel *temp = head;

    if (head == nullptr)
    {
        cout << "" << endl;
        cout << "Data bus masih kosong." << endl;
        return;
    }

    cout << "" << endl;
    lihat_data_bus(head);
    cout << "Masukkan urutan bus yang ingin dihapus: " << endl;
    cin >> idx;

    for (int i = 1; i < idx - 1; i++)
    {
        temp = temp->next;
    }

    travel *hapus = temp->next;
    temp->next = hapus->next;
    delete hapus;
    
    cout << "" << endl;
}

void lihat_orderan()
{
    int total;

    cout << "Berikut List Orderan Kurir Motor yang telah dibuat." << "\n" << endl;
    for (int i = 0; i < jml_data && !order[i].nama_pemesan.empty(); i++)
    {
        cout << i + 1 << ". Nama: " << order[i].nama_pemesan << "\n" 
        << "Nomor Telepon: " << order[i].no_hp_pemesan << "\n" 
        << "Tanggal Berangkat Bus: " << order[i].tanggal_pemesanan << "/" << order[i].bulan_pemesanan << "/" << order[i].tahun_pemesanan << "\n"
        << "Total Harga Tiket: Rp. " << order[i].harga_total << endl;

    }

}

void pemesanan_bus()
{
    string nama, no_telp;
    int tiket, harga_bus, hasil, pilih2, total_tiket,tanggal, bulan, tahun;

    while (pilih2 != 0)
    {

        cout << "" << endl;
        for (int i = 0; i < jml_data && !bus[i].jenis_bus.empty(); i++)
        {
            cout << i + 1 << ". " << bus[i].jenis_bus << " | " << bus[i].besar_muatan << " | Rp. " << bus[i].harga << endl;
        }
        cout << "0. Keluar" << endl;
        cout << "Masukkan Jenis Bus yang Ingin Dipilih" << endl;
        cin >> pilih2;

        if (pilih2 <= jml_data && !bus[pilih2 - 1].jenis_bus.empty())
        {
            cin.ignore();
            cout << "" << endl;
            cout << "Masukkan Nama Pemesan: " << endl;
            getline(cin, nama);
            fflush stdin;
            cout << "Masukkan Nomor Telepon Pemesan: " << endl;
            getline(cin, no_telp);
            fflush stdin;
            cout << "Masukkan Tanggal Keberangkatan: " << endl;
            cin >> tanggal;
            fflush stdin;
            cout << "Masukkan Bulan Keberangkatan (Masukkan dalam bentuk angka, ex: Juni = 6): " << endl;
            cin >> bulan;
            fflush stdin;
            cout << "Masukkan Tahun Keberangkatan: " << endl;
            cin >> tahun;
            fflush stdin;
            cout << "Masukkan Jumlah Tiket yang Ingin Dibeli: " << endl;
            cin >> tiket;
            total_tiket = tiket;
            

            order[idx_pemesanan].nama_pemesan = nama;
            order[idx_pemesanan].no_hp_pemesan = no_telp;
            order[idx_pemesanan].tanggal_pemesanan = tanggal;
            order[idx_pemesanan].bulan_pemesanan = bulan;
            order[idx_pemesanan].tahun_pemesanan = tahun;

            idx = pilih2;
            harga_bus = stoi(bus[idx - 1].harga);
            hasil = total_harga(&harga_bus, total_tiket);
            order[idx_pemesanan].harga_total = hasil;
            order[idx_pemesanan].jenis_bus = bus[idx - 1].jenis_bus;
            order[idx_pemesanan].harga = bus[idx - 1].harga;

            cout << "" << endl;
            cout << "Berikut Pesanan Anda: " << "\n" << "\n"
            << "Nama Pemesan: " << nama << "\n"
            << "Nomor Telepon Pemesan: " << no_telp << "\n"
            << "Jenis Kurir :" << order[idx_pemesanan].jenis_bus << "\n"
            << "Tanggal Keberangkatan :" << tanggal << "/" << bulan << "/" << tahun << "\n"
            << "Total Tiket yang Dibeli: " << tiket << "\n"
            << "Harga Bus: " << bus[idx - 1].harga << "\n"
            << "Total Harga: " << hasil << "\n"
            << "" << "\n"
            << "Terima Kasih Telah Menggunakan Layanan Kami" << endl;
            cout << "" << endl;

            idx_pemesanan++;

        }
        else if (pilih2 == 0)
        {
            cout << "" << endl;

            break;
        }               
        else
        {
            cout << "Input tidak valid!" << endl;
        }
    }
}

void menu_admin (travel *&head, pemesanan *&HEAD)
{

    string pilihan;

    while (pilihan != "6")
    {
        cout << "" << endl;
        cout << "1. Lihat Data Bus" << endl;
        cout << "2. Tambah Data" << endl;
        cout << "3. Hapus Data" << endl;
        cout << "4. Edit Data" << endl;
        cout << "5. Lihat Orderan" << endl;
        cout << "6. Keluar" << endl;
        cout << "Masukkan pilihan anda: " << endl;
        cin >> pilihan;

            if (pilihan == "1")
            {
                lihat_data_bus(head);
            }
            else if (pilihan == "2")
            {
                tambah_data(head);
            }
            else if (pilihan == "3")
            {
                hapus_data(head);
            }
            else if (pilihan == "4")
            {
                edit_data(head);
            }
            else if (pilihan == "5")
            {
                lihat_orderan();
            }
            else if (pilihan == "6")
            {
                cout << "Anda telah keluar dari menu admin." << endl;

            }
            else
            {
                cout << "Pilihan anda salah" << endl;
            }
        }

}

void menu_pemesan(travel *&head, pemesanan *&HEAD)
{

    string pilihan;

    while (pilihan != "3")
    {
        cout << "" << endl;
        cout << "1. Lihat List Harga" << endl;
        cout << "2. Buat Pesanan" << endl;
        cout << "3. Keluar" << endl;
        cout << "Masukkan pilihan anda: " << endl;
        cin >> pilihan;

            if (pilihan == "1")
            {
                lihat_data_bus(head);
            }
            else if (pilihan == "2")
            {
                pemesanan_bus();
            }
            else if (pilihan == "3")
            {
                cout << "" << endl;
            }
            else
            {
                cout << "Pilihan anda salah" << endl;
            }
    }

}

int main()
{
    travel *head = nullptr;
    pemesanan *HEAD = nullptr;

    string pilihan;

    while (pilihan != "3")
    {
        cout << "" << endl;
        cout << "1. Admin" << endl;
        cout << "2. Pengguna" << endl;
        cout << "3. Keluar" << endl;
        cout << "Masukkan pilihan anda: " << endl;
        cin >> pilihan;
        fflush (stdin);
        cout << "" << endl;

        if (pilihan == "1")
            {
                cin.ignore();
                int coba;
                coba = 0;
                while (coba < 3)
                {
                    string pass;
                    cout << "Masukkan Password: " << endl;
                    getline(cin, pass);

                    if (pass == "admin")
                        {
                            cout << "" << endl;
                            cout << "Berhasil Login!!" << endl;
                            menu_admin(head, HEAD);
                            break;
                        }
                    else
                        {
                            cout << "Password anda salah" << endl;
                        }
                    if (coba == 2)
                        {
                            cout << "Percobaan mencapai batas maksimal. Coba lagi nanti." << endl;
                            return 0;
                        }
                        coba++;
                }    
                
                
            }
        else if (pilihan == "2")
            {
                menu_pemesan(head, HEAD);
            }
        else if (pilihan == "3")
            {
                cout << "Anda memilih Keluar" << endl;
                return 0;
            }
        else
            {
                cout << "Pilihan anda tidak tersedia" << endl;
            }
    }

}