#include <iostream>
#include <string>

using namespace std;

class Node {
public:
	//isi disini 
	string namaProduk;
	int jumlahProduk;
	string tipeProduk;
	Node* next;

	Node(string nama, int jumlah, string tipe) {
		namaProduk = nama;
		jumlahProduk = jumlah;
		tipeProduk = tipe;
		next = NULL; 
	}
};

class ManajemenProduk {
private:
	Node* head;
public:
	ManajemenProduk() {
	head = NULL;
	}

	void tambahProduk() {
		string nama;
		int jumlah;
		string tipe;

		cout << "========== TAMBAH PRODUK ==========" << endl;
		cout << "Nama Produk : ";
		getline(cin, nama);
		cout << "Jumlah Produk : ";
		cin >> jumlah;
		cin.ignore(); // Membersihkan buffer input 
		cout << "Tipe Produk : ";
		getline(cin, tipe);
		
		Node* newNode = new Node(nama, jumlah, tipe);

		if (head == NULL) {
			head = newNode;
		}
		else {
			Node* current = head;
			while (current->next != NULL) {
				current = current->next;
			}
			current->next = newNode;
		}

		cout << "Produk berhasil ditambahkan!" << endl;
	}

	void tampilkanSemuaProduk() {		//linked list
		cout << "========== SEMUA DATA PRODUK ==========" << endl;
		if (head == NULL) {
			cout << "Belum ada data produk yang tersimpan." << endl;
		}
		else {
			Node* current = head;
			//isi disini 
			while (current != NULL) {
				cout << "Nama Produk : " << current->namaProduk << endl;
				cout << "Jumlah Produk : " << current->jumlahProduk << endl;
				cout << "Tipe Produk : " << current->tipeProduk << endl;
				cout << endl;
				current = current->next; 
			}
		}
	}


	void cariProdukByNama() {		//linear search
		cout << "========== CARI PRODUK BERDASARKAN NAMA ==========" << endl;
		if (head == NULL) {
			cout << "Belum ada data produk yang tersimpan." << endl;
		}
		else {
			string targetNama;
			cout << "Nama Produk yang dicari: ";
			getline(cin, targetNama);
			Node* current = head;

			int posisi = 0;
			bool ditemukan;

			while (current != NULL) {
				posisi++;
				if (current->namaProduk == targetNama) {
					cout << "Produk ditemukan pada urutan ke-" << posisi << endl;
					ditemukan = true;
					break;
				}
				//isi disini 
				current = current->next;
			}
			if (current == NULL) {
				cout << "Nama produk " << targetNama << " TIDAK DITEMUKAN" << endl;
			}
		}
	}



	void algorithmaSortByJumlahProduk() {		//bubblesort
		if (head == NULL || head->next == NULL) {
			return; // Tidak perlu sorting jika hanya terdapat 0 atau 1 node 
		}
		bool swaped;
		Node* current;
		Node* last = NULL;

		current = head;
		//isi disini 
		while (current->next != last) {
			if (current->jumlahProduk > current->next->jumlahProduk) {
				swap(current, current->next);
				swaped = true;
			}
		}
	}
};

int main() {
	ManajemenProduk manajemenProduk; 
	int pilihan;

	do {
		cout << "========== APLIKASI MANAJEMEN DATA PRODUK ==========" << endl;
		cout << "1. Tambah Produk" << endl;
		cout << "2. Tampilkan Semua Produk" << endl;
		cout << "3. Cari Produk berdasarkan Nama" << endl;
		cout << "4. Urutkan Produk berdasarkan Jumlah" << endl;
		cout << "5. Keluar" << endl;
		cout << "Pilihan: ";
		cin >> pilihan;
		cin.ignore();
		switch (pilihan) {
		case 1:
			manajemenProduk.tambahProduk();
			break;
		case 2:
			manajemenProduk.tampilkanSemuaProduk();
			break;
		case 3:
			manajemenProduk.cariProdukByNama();
			break;
		case 4:
			manajemenProduk.algorithmaSortByJumlahProduk();
			break;
		case 5:
			cout << "Terima kasih! Program selesai." << endl;
			break;
		default:
			cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
		}
		cout << endl;
	} while (pilihan != 5);
	return 0;
}

// 2. linked list(traversal), linear search dan bubblesort
// 3. jadi pada gambar pada urutan ke 0-2 adalah data kosong, maka data yang paling depan adalah data ke3(10) dan data yang paling belakang adalah data ke4(15)
// karna algoritma queue menggunakan prinsip FIFO(First In First Out) maka data yang akan keluar/dapat diambil adalah data yang ke3(10) terlebih dahulu
//berikut penulisan algoritmanya
//  1.	Jika antrean kosong:
//		a.Atur FRONT = 0.
//2.	Increment REAR sebesar 1.
//3.	Simpan elemen pada posisi indeks REAR dalam array.

// 4. saat kita ingin mengambil data namun hanya ada 1 akses yaitu dari sisi atas/depan, 
// maka dari itu kita menggunakan prinsip LIFO(Last In First Out)
// 5a. kedalaman struktur nya adalah 5
// 5b. inorder = 15 20 25 31 32 35 30 48 50 66 67 69 65 94 99 98 70 90