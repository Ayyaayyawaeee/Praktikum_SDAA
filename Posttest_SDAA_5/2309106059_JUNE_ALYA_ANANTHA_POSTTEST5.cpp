#include <iostream>

using namespace std;

struct travel
{

    string jenis_bus;
    string besar_muatan;
    string harga;
    travel *next;
};
// travel bus[100];

struct pemesanan
{
    int urutan;
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
// pemesanan order[100];
int jml_order = 0;
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

void tambah_data(travel *&head) // push untuk stack
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
    jml_data++;
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

void hapus_data(travel *&head) // pop untuk stack
{
    travel *temp = head;

    if (head == nullptr)
    {
        cout << "" << endl;
        cout << "Data bus masih kosong." << endl;
        return;
    }

    // cout << "" << endl;
    // lihat_data_bus(head);
    // cout << "Masukkan urutan bus yang ingin dihapus: " << endl;
    // cin >> idx;

    // for (int i = 1; i < idx - 1; i++)
    // {
    //     temp = temp->next;
    // }

    // travel *hapus = temp->next;
    // temp->next = hapus->next;
    // delete hapus;
    head = head->next;
    delete temp;

    cout << "" << endl;
    cout << "Data bus berhasil dihapus." << endl;
}

void lihat_orderan(pemesanan *HEAD)
{
    int total;
    pemesanan *temp = HEAD;
    cout << "Berikut List Orderan Kurir Motor yang telah dibuat." << "\n"
         << endl;
    for (int i = 0; i < jml_data && !temp->nama_pemesan.empty(); i++)
    {
        cout << i + 1 << ". Nama: " << temp->nama_pemesan << "\n"
             << "Nomor Telepon: " << temp->no_hp_pemesan << "\n"
             << "Tanggal Berangkat Bus: " << temp->tanggal_pemesanan << "/" << temp->bulan_pemesanan << "/" << temp->tahun_pemesanan << "\n"
             << "Total Harga Tiket: Rp. " << temp->harga_total << endl;
    }
}
struct pemesanan *getTail(struct pemesanan *cur)
{
    while (cur != NULL && cur->next != NULL)
    {
        cur = cur->next;
    }
    return cur;
}
struct pemesanan *partition(struct pemesanan *head, struct pemesanan *end, struct pemesanan **newHead, struct pemesanan **newEnd, bool ascending)
{
    struct pemesanan *pivot = end;
    struct pemesanan *prev = NULL, *cur = head, *tail = pivot;

    while (cur != pivot)
    {
        if (ascending = 1)
        {
            if (cur->urutan < pivot->urutan)
            {

                if ((*newHead) == NULL)
                {
                    (*newHead) = cur;
                }
                prev = cur;
                cur = cur->next;
            }
            else
            {
                if (prev)
                {
                    prev->next = cur->next;
                }
                struct pemesanan *tmp = cur->next;
                cur->next = NULL;
                tail->next = cur;
                tail = cur;
                cur = tmp;
            }
        }else{
            if (cur->urutan > pivot->urutan)
            {

                if ((*newHead) == NULL)
                {
                    (*newHead) = cur;
                }
                prev = cur;
                cur = cur->next;
            }
            else
            {
                if (prev)
                {
                    prev->next = cur->next;
                }
                struct pemesanan *tmp = cur->next;
                cur->next = NULL;
                tail->next = cur;
                tail = cur;
                cur = tmp;
            }
        }
    }

    if ((*newHead) == NULL)
    {
        (*newHead) = pivot;
    }
    // Update newEnd to the current last node
    (*newEnd) = tail;
    // Return the pivot node
    return pivot;
}
struct pemesanan *quickSortRecur(struct pemesanan *head, struct pemesanan *end, bool ascending)
{

    if (!head || head == end)
    {
        return head;
    }
    pemesanan *newHead = NULL, *newEnd = NULL;

    struct pemesanan *pivot = partition(head, end, &newHead, &newEnd, ascending);

    if (newHead != pivot)
    {

        struct pemesanan *tmp = newHead;
        while (tmp->next != pivot)
        {
            tmp = tmp->next;
            tmp->next = NULL;

            newHead = quickSortRecur(newHead, tmp, ascending);
            tmp = getTail(newHead);
            tmp->next = pivot;
        }
        // Recur for the list after the pivot element
        pivot->next = quickSortRecur(pivot->next, newEnd, ascending);
        return newHead;
    }
}
void quickSort(pemesanan **headRef, bool ascending)
{
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef), ascending);
    return;
}

void pemesanan_bus(pemesanan *HEAD, travel *head) // Enqueue untuk Queue
{
    string nama, no_telp;
    int tiket, harga_bus, hasil, pilih2, total_tiket, tanggal, bulan, tahun;

    while (pilih2 != 0)
    {

        cout << "" << endl;
        lihat_data_bus(head);
        // for (int i = 0; i < jml_data && !travel->jenis_bus.empty(); i++)
        // {
        //     cout << i + 1 << ". " << bus[i].jenis_bus << " | " << bus[i].besar_muatan << " | Rp. " << bus[i].harga << endl;
        // }
        cout << "0. Keluar" << endl;
        cout << "Masukkan Jenis Bus yang Ingin Dipilih" << endl;
        cin >> pilih2;

        pemesanan *order_baru = new pemesanan;
        travel *temp = head;

        for (int i = 1; i < pilih2; i++)
        {
            temp = temp->next;
        }

        if (pilih2 <= jml_data && !temp->jenis_bus.empty())
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
            jml_order = jml_order + 1;

            order_baru->urutan = jml_data;
            order_baru->nama_pemesan = nama;
            order_baru->no_hp_pemesan = no_telp;
            order_baru->tanggal_pemesanan = tanggal;
            order_baru->bulan_pemesanan = bulan;
            order_baru->tahun_pemesanan = tahun;

            idx = pilih2;
            harga_bus = stoi(temp->harga);
            hasil = total_harga(&harga_bus, total_tiket);
            order_baru->harga_total = hasil;
            order_baru->jenis_bus = temp->jenis_bus;
            order_baru->harga = temp->harga;

            cout << "" << endl;
            cout << "Berikut Pesanan Anda: " << "\n"
                 << "\n"
                 << "Urutan : "<< jml_order << "\n"
                 << "Nama Pemesan: " << nama << "\n"
                 << "Nomor Telepon Pemesan: " << no_telp << "\n"
                 << "Jenis Kurir :" << order_baru->jenis_bus << "\n"
                 << "Tanggal Keberangkatan :" << tanggal << "/" << bulan << "/" << tahun << "\n"
                 << "Total Tiket yang Dibeli: " << tiket << "\n"
                 << "Harga Bus: " << temp->harga << "\n"
                 << "Total Harga: " << hasil << "\n"
                 << "" << "\n"
                 << "Terima Kasih Telah Menggunakan Layanan Kami" << endl;
            cout << "" << endl;

            if (HEAD == nullptr)
            {
                HEAD = order_baru;
                return;
            }
            pemesanan *temp_order = HEAD;
            while (temp_order->next != nullptr)
            {
                temp_order = temp_order->next;
            }
            temp_order->next = order_baru;

            // idx_pemesanan++;
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

void menu_admin(travel *&head, pemesanan *&HEAD)
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
        cout << "6. Lihat Orderan Acending" << endl;
        cout << "7. Lihat Orderan Descending" << endl;
        cout << "8. Keluar" << endl;
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
            lihat_orderan(HEAD);
        }
        else if (pilihan == "6")
        {
            quickSort(&HEAD, 1);
            lihat_orderan(HEAD);
        }
        else if (pilihan == "7")
        {
            quickSort(&HEAD, 0);
            lihat_orderan(HEAD);
        }

        else if (pilihan == "8")
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
            pemesanan_bus(HEAD, head);
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
        fflush(stdin);
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