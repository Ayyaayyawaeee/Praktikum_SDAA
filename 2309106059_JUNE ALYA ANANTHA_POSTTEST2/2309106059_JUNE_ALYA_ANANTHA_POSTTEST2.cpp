#include <iostream>

using namespace std;

struct travel
{

    string jenis_bus;
    string besar_muatan;
    string harga;

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

};
pemesanan order[100];

int jml_data = 0;
int idx_bus, idx_pemesanan, idx;

void lihat_data_bus()
{

    cout << "Berikut Jenis bus yang Available Beserta Harganya." << endl;
    cout << "" << endl;
    for (int i = 0; i < jml_data && !bus[i].jenis_bus.empty(); i++)
    {
        cout << i + 1 << ". " << bus[i].jenis_bus << " | " << "Maximal Menampung " << bus[i].besar_muatan << " Orang" << " | Rp. " << bus[i].harga << endl;
    }

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

void tambah_data()
{
    lihat_data_bus();

    string jenis;
    string muatan;
    string hrga;

    cin.ignore();
    cout << "Masukkan Jenis Bus yang Ingin Dipesan: ";
    fflush(stdin);
    getline(cin, jenis);
    cout << "Masukkan Muatan Maximal Bus (Berapa Orang) : ";
    fflush(stdin);
    getline(cin, muatan);
    cout << "Harga Tiket Bus: ";
    fflush(stdin);
    getline(cin, hrga);

    bus[idx_bus].jenis_bus = jenis;
    bus[idx_bus].besar_muatan = muatan;
    bus[idx_bus].harga = hrga;

    idx_bus++;

    jml_data++;
    cout << "" << endl;
}

void edit_data()
{
    lihat_data_bus();

    string jenis;
    string muatan;
    string hrga;

    cout << "Masukkan urutan bus yang ingin diedit: " << endl;
    cin >> idx;
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

    bus[idx - 1].jenis_bus = jenis;
    bus[idx - 1].besar_muatan = muatan;
    bus[idx - 1].harga = hrga;

    jml_data++;
    cout << "" << endl;
}

void hapus_data()
{
    lihat_data_bus();

    cout << "Masukkan urutan kurir yang ingin dihapus: " << endl;
    cin >> idx;
    for (int i = idx - 1; i < idx_bus; i++)
    {
        bus[i].jenis_bus = bus[i + 1].jenis_bus;
        bus[i].besar_muatan = bus[i + 1].besar_muatan;
        bus[i].harga = bus[i + 1].harga;

    }

        bus[idx_bus].jenis_bus = "";
    string pilihan;  
        bus[idx_bus].besar_muatan = "";
        bus[idx_bus].harga = "";

        idx_bus--;
    
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

void menu_admin ()
{

    string pilihan;

    while (pilihan != "6")
    {
        cout << "" << endl;
        cout << "1. Lihat Data Kurir" << endl;
        cout << "2. Tambah Data" << endl;
        cout << "3. Hapus Data" << endl;
        cout << "4. Edit Data" << endl;
        cout << "5. Lihat Orderan" << endl;
        cout << "6. Keluar" << endl;
        cout << "Masukkan pilihan anda: " << endl;
        cin >> pilihan;

            if (pilihan == "1")
            {
                lihat_data_bus();
            }
            else if (pilihan == "2")
            {
                tambah_data();
            }
            else if (pilihan == "3")
            {
                hapus_data();
            }
            else if (pilihan == "4")
            {
                edit_data();
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

void menu_pemesan()
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
                lihat_data_bus();
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
    bus[0].jenis_bus = "Bus Mini";
    bus[0].besar_muatan = "12";
    bus[0].harga = "60000";

    bus[1].jenis_bus = "Bus Reguler";
    bus[1].besar_muatan = "23";
    bus[1].harga = "40000";

    bus[2].jenis_bus = "Bus Pariwisata";
    bus[2].besar_muatan = "30";
    bus[2].harga = "120000";

    jml_data = sizeof(bus) / sizeof(bus[0]);
    for (int i = 0; i < jml_data && !bus[i].jenis_bus.empty(); i++)
    {
        idx_bus++;
    }

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
                            menu_admin();
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
                menu_pemesan();
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