#include "tree.h"

int main() {
    adrNode root;
    createTree_103012400173(root);

    int menu = -1;

    while (menu != 0) {

        cout << "\n===== MENU KATALOG PRODUK =====\n";
        cout << "1. Tambahkan Produk\n";
        cout << "2. Tampilkan Produk (Urutan ID)\n";
        cout << "3. Cari Berdasarkan ID\n";
        cout << "4. Cari Berdasarkan Nama\n";
        cout << "5. Ubah Informasi Produk\n";
        cout << "6. Hapus Produk\n";
        cout << "7. Urutkan Berdasarkan Harga\n";
        cout << "8. Urutkan Berdasarkan Nama\n";
        cout << "9. Hitung Total Stok\n";
        cout << "10. Produk Stok Terendah\n";
        cout << "11. Simpan Data ke File\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> menu;

        if (menu == 1) {
            int id, stock;
            float price;
            string name;

            cout << "ID: ";
            cin >> id;
            cout << "Nama: ";
            cin >> name;
            cout << "Harga: ";
            cin >> price;
            cout << "Stok: ";
            cin >> stock;

            insertNode_103012400173(root,
                createNode_103012400173(id, name, price, stock));

            cout << "Produk berhasil ditambahkan!\n";
        }

        else if (menu == 2) {
            cout << "\n=== Daftar Produk (Inorder / berdasarkan ID) ===\n";
            cout << "ID    |   " << "Nama   |   " << "Harga   |   " << "Stok   |   " << "Total Harga" << endl;
            displayInorder_103012400173(root);
        }

        else if (menu == 3) {
            int id;
            cout << "Masukkan ID: ";
            cin >> id;

            adrNode p = searchByID_103012400173(root, id);
            if (p)
                cout << "Ditemukan: " << p->name << " | Harga: " << p->price << " | Stok: " << p->stock << endl;
            else
                cout << "Produk tidak ditemukan!\n";
        }

        else if (menu == 4) {
            string name;
            cout << "Masukkan nama: ";
            cin >> name;

            adrNode p = searchByName_103012400173(root, name);
            if (p)
                cout << "Ditemukan ID: " << p->id << " | Harga: " << p->price << " | Stok: " << p->stock << endl;
            else
                cout << "Produk tidak ditemukan!\n";
        }

        else if (menu == 5) {
            int id, stock;
            float price;
            string name;

            cout << "ID yang diubah: ";
            cin >> id;
            cout << "Nama baru: ";
            cin >> name;
            cout << "Harga baru: ";
            cin >> price;
            cout << "Stok baru: ";
            cin >> stock;

            if (updateProduct_103012400173(root, id, name, price, stock))
                cout << "Data berhasil diperbarui.\n";
            else
                cout << "ID tidak ditemukan.\n";
        }

        else if (menu == 6) {
            int id;
            cout << "ID yang dihapus: ";
            cin >> id;

            root = deleteNode_103012400173(root, id);
            cout << "Jika ID ditemukan, produk sudah dihapus.\n";
        }

        else if (menu == 7) {
            cout << "=== Urutan Harga (butuh array, tetapi array dihapus dari spesifikasi) ===\n";
            cout << "Tidak dapat dilakukan tanpa array.\n";
        }

        else if (menu == 8) {
            cout << "=== Urutan Nama (butuh array, tetapi array dihapus dari spesifikasi) ===\n";
            cout << "Tidak dapat dilakukan tanpa array.\n";
        }

        else if (menu == 9) {
            cout << "Total stok semua produk = "
                 << totalStock_103012400173(root) << endl;
        }

        else if (menu == 10) {
            adrNode p = minStock_103012400173(root);
            if (p)
                cout << "Produk dengan stok terendah: " << p->name << " (" << p->stock << ")\n";
            else
                cout << "Tidak ada produk!\n";
        }

        else if (menu == 11) {
            cout << "Tidak bisa menyimpan file karena fstream tidak boleh digunakan.\n";
        }

    }

    cout << "Program selesai.\n";
    return 0;
}
