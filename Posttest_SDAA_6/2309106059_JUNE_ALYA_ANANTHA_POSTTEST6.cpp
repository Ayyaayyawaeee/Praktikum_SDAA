#include <iostream>
#include <cmath>

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
    int nomor_pesanan;
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
    cout << "Masukkan Jenis Bus: ";
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
    cout << "Masukkan nomor_pesanan bus yang ingin diedit: " << endl;
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
    // cout << "Masukkan nomor_pesanan bus yang ingin dihapus: " << endl;
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
    for (int i = 0; i < jml_order && !temp->nama_pemesan.empty(); i++)
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
            if (cur->nomor_pesanan < pivot->nomor_pesanan)
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
            if (cur->nomor_pesanan > pivot->nomor_pesanan)
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

void quickSort_nomor_pesanan(pemesanan **headRef, bool ascending)
{
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef), ascending);
    return;
}

struct pemesanan *partisi(struct pemesanan *head, struct pemesanan *end, struct pemesanan **newHead, struct pemesanan **newEnd) // Untuk sort berdasarkan tanggal
{
    struct pemesanan *pivot = end;
    struct pemesanan *prev = NULL, *cur = head, *tail = pivot;

    while (cur != pivot)
    {
         if (cur->nomor_pesanan < pivot->nomor_pesanan)
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

    if ((*newHead) == NULL)
    {
        (*newHead) = pivot;
    }

    (*newEnd) = tail;
    return pivot;
}

struct pemesanan *quickSort(struct pemesanan *head, struct pemesanan *end)
{

    if (!head || head == end)
    {
        return head;
    }
    pemesanan *newHead = NULL, *newEnd = NULL;

    struct pemesanan *pivot = partisi(head, end, &newHead, &newEnd);

    if (newHead != pivot)
    {

        struct pemesanan *tmp = newHead;
        while (tmp->next != pivot)
        {
            tmp = tmp->next;
            tmp->next = NULL;

            newHead = quickSort(newHead, tmp);
            tmp = getTail(newHead);
            tmp->next = pivot;
        }

        pivot->next = quickSort(pivot->next, newEnd);
        return newHead;
    }
}

void quickSort_tanggal(pemesanan **headRef)
{
    (*headRef) = quickSort(*headRef, getTail(*headRef));
    return;
}

void badCharHeuristic(string str, int size, int badChar[256])
{

    for (int i = 0; i < 256; i++)
        badChar[i] = -1;

    for (int i = 0; i < size; i++)
        badChar[(int)str[i]] = i;
}

int boyerMooreSearch(string txt, string pat)
{
    int m = pat.size();
    int n = txt.size();

    int badChar[256];

    badCharHeuristic(pat, m, badChar);

    int s = 0;
    while (s <= (n - m))
    {
        int j = m - 1;

        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        if (j < 0)
        {
            return s;
            s += (s + m < n) ? m - badChar[txt[s + m]] : 1;
        }
        else
            s += max(1, j - badChar[txt[s + j]]);
    }

    return -1;
}

int fibMonaccianSearch(pemesanan *HEAD, int x, int n) 
{
    quickSort_nomor_pesanan(&HEAD, 1);

    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;

    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    pemesanan *curr = HEAD;
    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fibMMm2, n - 1);

        pemesanan *temp = HEAD;
        for (int j = 0; j < i; j++) {
            if (temp == nullptr) break;
            temp = temp->next;
        }

        if (temp && temp->nomor_pesanan < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }

        else if (temp && temp->nomor_pesanan > x) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }

        else {
            if (temp && temp->nomor_pesanan == x) {
                return i;
            }
        }
    }

    if (fibMMm1 && curr && curr->nomor_pesanan == x) {
        return offset + 1;
    }

    return -1;
}

int createDate(pemesanan *&HEAD) 
{
    pemesanan *temp = HEAD;
    return temp->tahun_pemesanan * 10000 + temp->bulan_pemesanan * 100 + temp->tanggal_pemesanan;
};

pemesanan *jumpSearch(pemesanan *HEAD, int targetDate) 
{
    quickSort_tanggal(&HEAD);

    if (!HEAD) return nullptr;

    pemesanan *current = HEAD;
    int step = sqrt(jml_order);
    int prev = 0;

    while (current && createDate(current) <= targetDate) {
        prev = current->nomor_pesanan;
        for (int i = 0; i < step && current; i++) 
        {
            current = current->next;
        }
        if (current == nullptr) 
        {
            return nullptr; 
        }
    }

    for (int i = prev; current && i < jml_order; i++) 
    {
        if (createDate(current) == targetDate) 
        {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void cari_pesanan(pemesanan *HEAD)
{
    int pilihan_pesanan;

    if (HEAD == nullptr)
    {
        cout << "Data pemesanan kosong." << endl;
        return;
    }

    pemesanan *temp = HEAD;

    while (temp != nullptr)
    {
        cout << "" << endl;
        cout << "1. Cari Berdasarkan Nama" << endl;
        cout << "2. Cari Berdasarkan Nomor Pesanan" << endl;
        cout << "3. Cari Berdasarkan Tanggal Keberangkatan" << endl;
        cout << "Masukkan pilihan: " << endl;
        cin >> pilihan_pesanan;

        if (pilihan_pesanan == 1)
        {
            string nama;
            cout << "" << endl;
            cout << "Masukkan nama pemesan yang ingin dicari: ";
            cin.ignore();
            getline(cin, nama);

            if (boyerMooreSearch(temp->nama_pemesan, nama) != -1)
            {
                cout << "" << endl;
                cout << "Pemesanan ditemukan:" << endl;
                cout << "Nama: " << temp->nama_pemesan << endl;
                cout << "Nomor Telepon: " << temp->no_hp_pemesan << endl;
                cout << "Tanggal Berangkat: " << temp->tanggal_pemesanan << "/" << temp->bulan_pemesanan << "/" << temp->tahun_pemesanan << endl;
                cout << "Jenis Bus: " << temp->jenis_bus << endl;
                cout << "Total Harga: Rp. " << temp->harga_total << endl;
                return;
            }
            temp = temp->next;

            cout << "Pemesanan atas nama " << nama << " tidak ditemukan." << endl;

        }
        else if (pilihan_pesanan == 2)
        {
            int n = 0;
            int nomor_pesanan;
            cout << "" << endl;
            cout << "Masukkan nomor pesanan: ";
            cin >> nomor_pesanan;
            
            pemesanan *temp_n = HEAD;
            while (temp_n->next != nullptr)
            {
                temp_n = temp_n->next;
                n++;
            }
            
            if (fibMonaccianSearch(HEAD, nomor_pesanan, n) != -1)
            {
                cout << "" << endl;
                cout << "Pemesanan ditemukan:" << endl;
                cout << "Nama: " << temp->nama_pemesan << endl;
                cout << "Nomor Telepon: " << temp->no_hp_pemesan << endl;
                cout << "Tanggal Berangkat: " << temp->tanggal_pemesanan << "/" << temp->bulan_pemesanan << "/" << temp->tahun_pemesanan << endl;
                cout << "Jenis Bus: " << temp->jenis_bus << endl;
                cout << "Total Harga: Rp. " << temp->harga_total << endl;
                return;
            }
            temp = temp->next;

            cout << "Pesanan nomor " << nomor_pesanan << " tidak ditemukan." << endl;
        }
        else if (pilihan_pesanan == 3)
        {
            int tanggal, bulan, tahun;

            cout << "" << endl;
            cout << "Masukkan Tanggal: ";
            cin >> tanggal;
            cout << "Masukkan Bulan: ";
            cin >> bulan;
            cout << "Masukkan Tahun: ";
            cin >> tahun;

            int targetDate = tahun * 10000 + bulan * 100 + tanggal;
            pemesanan *hasil = jumpSearch(HEAD, targetDate);

            if (hasil) 
            {
                cout << "" << endl;
                cout << "Pemesanan ditemukan:" << endl;
                cout << "Nama: " << temp->nama_pemesan << endl;
                cout << "Nomor Telepon: " << temp->no_hp_pemesan << endl;
                cout << "Tanggal Berangkat: " << temp->tanggal_pemesanan << "/" << temp->bulan_pemesanan << "/" << temp->tahun_pemesanan << endl;
                cout << "Jenis Bus: " << temp->jenis_bus << endl;
                cout << "Total Harga: Rp. " << temp->harga_total << endl;
                return;
            } else {
                temp = temp->next;
                cout << "Pesanan pada tanggal " << temp->tanggal_pemesanan << "/" << temp->bulan_pemesanan << "/" << temp->tahun_pemesanan << " tidak ditemukan." << endl;
            }
        }
        else
        {
            cout << "Input salah, silahkan masukkan pilihan yang valid." << endl;
        }
    }
}


void pemesanan_bus(pemesanan *&HEAD, travel *head) // Enqueue untuk Queue
{
    string nama, no_telp;
    int tiket, harga_bus, hasil, pilih2, total_tiket, tanggal, bulan, tahun;

    while (pilih2 != 0)
    {
        cout << "" << endl;
        lihat_data_bus(head);
        cout << "0. Keluar" << endl;
        cout << "Masukkan Jenis Bus yang Ingin Dipilih: ";
        cin >> pilih2;

        if (pilih2 == 0)
        {
            cout << "Keluar dari menu pemesanan." << endl;
            break;
        }

        pemesanan *order_baru = new pemesanan;
        travel *temp = head;

        for (int i = 1; i < pilih2; i++)
        {
            if (temp != nullptr)
            {
                temp = temp->next;
            }
        }

        if (pilih2 <= jml_data && temp != nullptr)
        {
            cin.ignore();
            cout << "Masukkan Nama Pemesan: ";
            getline(cin, nama);
            cout << "Masukkan Nomor Telepon Pemesan: ";
            getline(cin, no_telp);
            cout << "Masukkan Tanggal Keberangkatan: ";
            cin >> tanggal;
            cout << "Masukkan Bulan Keberangkatan (angka): ";
            cin >> bulan;
            cout << "Masukkan Tahun Keberangkatan: ";
            cin >> tahun;
            cout << "Masukkan Jumlah Tiket yang Ingin Dibeli: ";
            cin >> tiket;
            total_tiket = tiket;
            jml_order++;

            order_baru->nomor_pesanan = jml_order;
            order_baru->nama_pemesan = nama;
            order_baru->no_hp_pemesan = no_telp;
            order_baru->tanggal_pemesanan = tanggal;
            order_baru->bulan_pemesanan = bulan;
            order_baru->tahun_pemesanan = tahun;
            harga_bus = stoi(temp->harga);
            hasil = total_harga(&harga_bus, total_tiket);
            order_baru->harga_total = hasil;
            order_baru->jenis_bus = temp->jenis_bus;
            order_baru->harga = temp->harga;

            cout << "\nBerikut Pesanan Anda: " << endl;
            cout << "nomor_pesanan: " << jml_order << endl;
            cout << "Nama Pemesan: " << nama << endl;
            cout << "Nomor Telepon: " << no_telp << endl;
            cout << "Jenis Bus: " << order_baru->jenis_bus << endl;
            cout << "Tanggal Keberangkatan: " << tanggal << "/" << bulan << "/" << tahun << endl;
            cout << "Total Tiket: " << tiket << endl;
            cout << "Total Harga: " << hasil << endl;
            cout << "Terima Kasih Telah Memesan!" << endl;

            if (HEAD == nullptr)
            {
                HEAD = order_baru;
            }
            else
            {
                pemesanan *temp_order = HEAD;
                while (temp_order->next != nullptr)
                {
                    temp_order = temp_order->next;
                }
                temp_order->next = order_baru;
            }

            order_baru->next = nullptr;
        }
        else
        {
            cout << "Pilihan tidak valid!" << endl;
        }

    }
}


void menu_admin(travel *&head, pemesanan *&HEAD)
{

    string pilihan;

    while (pilihan != "8")
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
            quickSort_nomor_pesanan(&HEAD, 1);
            lihat_orderan(HEAD);
        }
        else if (pilihan == "7")
        {
            quickSort_nomor_pesanan(&HEAD, 0);
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

    while (pilihan != "4")
    {
        cout << "" << endl;
        cout << "1. Lihat List Harga" << endl;
        cout << "2. Buat Pesanan" << endl;
        cout << "3. Cari Pesanan" << endl;
        cout << "4. Keluar" << endl;
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
            cari_pesanan(HEAD);
        }
        else if (pilihan == "4")
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