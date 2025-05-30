// Untuk input output
#include <iostream>
// Menyedeiakan fungsi untuk melakukan validasi string
#include <string>
// Menyediakan stream string yang bisa digunakan untuk mengubah antara string dan tipe data lain, seperti integer atau float.
#include <sstream>
// Mengakses tipe data untuk pengelolaan waktu (durasi, waktu saat ini, dll.)
#include <chrono>
// Menyediakan fungsi untuk menundah thread
#include <thread>

using namespace std;

#define MAX_SPAREPART 100
#define MAX_USER 10

/*
Mendeklarasikan struct User untuk menyimpan data user yang terdaftar
User memiliki 3 field:
- username: untuk menyimpan username user
- password: untuk menyimpan password user
- role: untuk menyimpan peran user (inventaris atau kasir)
*/
struct User {
  string username;
  string password;
  string role;
};

/*
Mendeklarasikan struct Sparepart untuk menyimpan data sparepart yang ada dalam inventaris
Sparepart memiliki 4 field:
- idProduct: untuk menyimpan id produk sparepart
- name: untuk menyimpan nama sparepart
- stock: untuk menyimpan jumlah sparepart yang ada dalam inventaris
- price: untuk menyimpan harga sparepart per item
*/
struct Sparepart {
  string idProduct;
  string name;
  int stock;
  int price;
};

/*
Mendeklarasikan struct SparepartChart untuk menyimpan data sparepart yang ada dalam keranjang
SparepartChart memiliki 2 field:
- sparepart: untuk menyimpan data sparepart yang ada dalam keranjang
- quantity: untuk menyimpan jumlah sparepart yang ada dalam keranjang
*/
struct SparepartChart {
  Sparepart sparepart;
  int quantity;
};


bool isStringEmpty(string &valueOne, string &valueTwo);

bool isStringEmpty(string &value);

void registerMenu(User *user[], int &currentUser);

void loginMenu(User *user[], Sparepart *sparepart[], int &currentUser, int &currentSparepart, SparepartChart *sparepartChart[], int &currentSparepartChart);

void mainMenuInventory(Sparepart *sparepart[], int &currentSparepart);

void addSparepart(Sparepart *sparepart[], int &currentSparepart);

void printSparepart(Sparepart *sparepart[], int &currentSparepart);

void changeStockSparepart(Sparepart *sparepart[], int &currentSparepart);

void deleteSparepart(Sparepart *sparepart[], int &currentSparepart);

void showSparepart(Sparepart *sparepart[], int &currentSparepart);

void mainMenuCashier(Sparepart *sparepart[], int &currentSparepart, SparepartChart *sparepartChart[], int &currentSparepartChart);

void addToChart(Sparepart *sparepart[], int &currentSparepart, SparepartChart *sparepartChart[], int &currentSparepartChart);

void changeQuantity(SparepartChart *sparepartChart[], int &currentSparepartChart);

void deleteFromChart(SparepartChart *sparepartChart[], int &currentSparepartChart);

void confirmTransaction(Sparepart *sparepart[], int &currentSparepart, SparepartChart *sparepartChart[], int &currentSparepartChart);

void selectionSort(Sparepart *sparepart[], int &currentSparepart, string key);

int binarySearch(Sparepart *sparepart[], int &currentSparepart, string targetId);

int binarySearch(SparepartChart *sparepart[], int &currentSparepartChart, string targetId);

bool convertStringToInt(string &input, int &output);

void clearScreen();

void pause(int detik);

int main() {
  /*Deklarasi array struct untuk menyimpan data utama program*/
  // Menyimpan data sparepart motor
  Sparepart sparepart[MAX_SPAREPART];
  // Menyimpan data user yang terdaftar           
  User user[MAX_USER];
  // Menyimpan data sparepart yang masuk ke keranjang                          
  SparepartChart sparepartChart[MAX_SPAREPART];

  /*Deklarasi array pointer ke struct untuk manipulasi data secara dinamis*/
  // Pointer ke data sparepart
  Sparepart *sparepartPtr[MAX_SPAREPART];
  // Pointer ke data user           
  User *userPtr[MAX_USER];
  // Pointer ke data sparepartChart                         
  SparepartChart *sparepartChartPtr[MAX_SPAREPART]; 

  // Inisialisasi pointer agar menunjuk ke masing-masing elemen dalam array struct sparepart
  for (int i = 0; i < MAX_SPAREPART; i++) {
    sparepartPtr[i] = &sparepart[i];
  }

  // Inisialisasi pointer agar menunjuk ke masing-masing elemen dalam array struct user
  for (int i = 0; i < MAX_USER; i++) {
    userPtr[i] = &user[i]; 
  }

  // Inisialisasi pointer agar menunjuk ke masing-masing elemen dalam array struct sparepartChart
  for (int i = 0; i < MAX_SPAREPART; i++) {
    sparepartChartPtr[i] = &sparepartChart[i];
  }

  // Deklarasi variabel currentSparepart untuk menyimpan jumlah sparepart yang terdafatar dalam sistem
  int currentSparepart = 15;

  // Deklarasi variabel currentSparepartChart untuk menyimpan jumlah sparepart dalam keranjang
  int currentSparepartChart = 0;

  // Deklarasi variabel currentUser untuk menyimpan jumlah user yeng terdaftar dalam sistem
  int currentUser = 2;

  // Menambah data sparepart
  sparepart[0].idProduct = "P0001";
  sparepart[0].name = "AHM Oil SPX-2 800ML";
  sparepart[0].stock = 100; 
  sparepart[0].price = 70000;

  sparepart[1].idProduct = "P0002";
  sparepart[1].name = "Motul Oil Green 800ML";
  sparepart[1].stock = 45; 
  sparepart[1].price = 144000;

  sparepart[2].idProduct = "P0003";
  sparepart[2].name = "Federal Matic 30 800ML";
  sparepart[2].stock = 35; 
  sparepart[2].price = 50000;

  sparepart[3].idProduct = "P0004";
  sparepart[3].name = "Shell Advance AX7 Matic 1L";
  sparepart[3].stock = 80; 
  sparepart[3].price = 65000;

  sparepart[4].idProduct = "P0005";
  sparepart[4].name = "Yamalube Matic Oil 800ML";
  sparepart[4].stock = 60; 
  sparepart[4].price = 52000;

  sparepart[5].idProduct = "P0006";
  sparepart[5].name = "Castrol Power1 10W-40 1L";
  sparepart[5].stock = 50; 
  sparepart[5].price = 73000;

  sparepart[6].idProduct = "P0007";
  sparepart[6].name = "Top 1 Action Matic 800ML";
  sparepart[6].stock = 40; 
  sparepart[6].price = 47000;

  sparepart[7].idProduct = "P0008";
  sparepart[7].name = "Pertamina Enduro Matic-G 800ML";
  sparepart[7].stock = 70; 
  sparepart[7].price = 49000;

  sparepart[8].idProduct = "P0009";
  sparepart[8].name = "Motul Scooter Expert LE 10W-40 1L";
  sparepart[8].stock = 30; 
  sparepart[8].price = 85000;

  sparepart[9].idProduct = "P0010";
  sparepart[9].name = "Shell Advance Ultra Scooter 10W-40 1L";
  sparepart[9].stock = 55; 
  sparepart[9].price = 98000;

  sparepart[10].idProduct = "P0011";
  sparepart[10].name = "Repsol Moto Scooter 4T 10W-40 1L";
  sparepart[10].stock = 25; 
  sparepart[10].price = 92000;

  sparepart[11].idProduct = "P0012";
  sparepart[11].name = "ENEOS City Motor Oil 10W-30 800ML";
  sparepart[11].stock = 45; 
  sparepart[11].price = 57000;

  sparepart[12].idProduct = "P0013";
  sparepart[12].name = "Fastron Matic SAE 10W-30 800ML";
  sparepart[12].stock = 38; 
  sparepart[12].price = 60000;

  sparepart[13].idProduct = "P0014";
  sparepart[13].name = "Mobil Super Moto Matic 10W-30 800ML";
  sparepart[13].stock = 48; 
  sparepart[13].price = 59000;

  sparepart[14].idProduct = "P0015";
  sparepart[14].name = "Liqui Moly Molygen 10W-30 1L";
  sparepart[14].stock = 20; 
  sparepart[14].price = 110000;
  
  user[0].username = "aaa";
  user[0].password = "aaa";
  user[0].role = "inventaris";

  user[1].username = "dapa";
  user[1].password = "dapa";
  user[1].role = "kasir";

  while (true) {
    try {
      // Menjeda program selama 1 detik untuk memberikan jeda sebelum menampilkan menu
      pause(1);
      // Memanggil fungsi untuk membersihkan layar
      clearScreen();
      // Deklarasi variabel choiceUser untuk menampung konversi pilihan user
      int choiceUser;

      // Deklarasi variabel inputUser untuk menampung pilihan user berupa string
      string inputUser;

      // Menampilkan Menu
      cout << "\n=========================================\n";
      cout << "|            MotoTech Garage            |\n";
      cout << "=========================================\n";
      cout << "|  1  | Register Kasir                  |\n";
      cout << "|---------------------------------------|\n";
      cout << "|  2  | Login                           |\n";
      cout << "|---------------------------------------|\n";
      cout << "|  3  | Keluar                          |\n";
      cout << "=========================================\n";

      // Prompt meminta pilihan user
      cout << "Masukkan pilihan Anda : ";

      // Membaca input string dari user
      getline(cin, inputUser);

      /*Deklarasi variabel resultConvert untuk menampung hasil convert string
      resultConvert akan bernilai true jika convert berhasil dan bernilai false jika gagal
      convertStringToInt akan mengconvert nilai dari inputUser dan menyimpan nilai hasil convert ke choiceUser
      */
      bool resultConvert = convertStringToInt(inputUser, choiceUser);

      // Melakukan validasi terhadapa resultConvert, akan melakukan throw error jika convert gagal
      if (!resultConvert) {
        throw invalid_argument("Harap inputkan angka!");
      }

      // Melakukan pengecekan pilihan user yang telah diconvert ke integer
      switch (choiceUser) {
        case 1: {
          clearScreen();  
          // Masuk ke dalam menu register
          registerMenu(userPtr, currentUser);
        }
        break;
        case 2 : {
          clearScreen();
          // Masuk ke dalam menu login
          loginMenu(userPtr, sparepartPtr, currentUser, currentSparepart, sparepartChartPtr, currentSparepartChart);
        }
        break;
        case 3 : {
          // Keluar dari program
          cout << "\n+-------------------+\n";
          cout << "|      KELUAR       |\n";
          cout << "+-------------------+\n";
          break;
        }
        default: {
          // Menampilkan pesan kesalahan input pilihan
          cout << "\n+----------------------------------------+\n";
          cout << "|   Maaf, pilihan Anda tidak tersedia!   |\n";
          cout << "+----------------------------------------+\n";
          break;
        }
      }
      // Jika input pilihan user == 3 atau kesempatan login habis, makan program berhenti
      if (choiceUser == 3){
        break;
      }
    }
    // Code ini akan dijalankan jika user memasukkan huruf pada input pilihan
    catch(const invalid_argument& e){
      cout << "\n+-------------------------------+\n";
      cout << "|    " << e.what() << "      |\n";
      cout << "+-------------------------------+\n";
    }
  }
}

// Fungsi untuk menjeda program selama detik tertentu
void pause(int detik) {
  // "::" Nama nya adalah scope resolution operator, fungsinya untuk mengakses variabel, fungsi dari namespace atau anggota class tertentu
  this_thread::sleep_for(chrono::seconds(detik));
}

void clearScreen() {
  // Menggunakan sistem untuk membersihkan layar
  system("clear || cls");
}

/*
Fungsi untuk mengonversi string menjadi integer
Mengembalikan true jika konversi berhasil dan tidak ada karakter sisa setelah angka
"result >> output" akan mencoba membaca integer dari string input dan menyimpannya ke output
"result.eof()" akan memeriksa apakah sudah mencapai akhir dari string input, kalau terdapat 
huruf pada string input, maka akan mengembalikan false
*/
bool convertStringToInt(string &input, int &output) {
  stringstream result(input);
  return (result >> output && result.eof());
}

/*
Fungsi untuk melakukan selection sort pada array pointer Sparepart berdasarkan key tertentu
Parameter:
- sparepart[]: array pointer ke struct Sparepart
- currentSparepart: jumlah data sparepart yang ada
- key: field yang digunakan sebagai dasar pengurutan ("idProduct", "name", "stock", "price")
*/
void selectionSort(Sparepart *sparepart[], int &currentSparepart, string key) {
  // Melakukan perulangan sebanyak element yang ada dalam sparepart
  for (int i = 0; i < currentSparepart - 1; i++) {
    // Deklarasi variabel min untuk menampung indeks dengan element yang paling kecil disetiap perulangannya
    int min = i;
    for (int j = i + 1; j < currentSparepart; j++) {
      bool condition = false;

      // Menentukan kondisi berdasarkan key pengurutan
      if (key == "idProduct") {
        condition = sparepart[j]->idProduct < sparepart[min]->idProduct;
      } else if (key == "name") {
        condition = sparepart[j]->name < sparepart[min]->name;
      } else if (key == "stock") {
        condition = sparepart[j]->stock < sparepart[min]->stock;
      } else if (key == "price") {
        condition = sparepart[j]->price < sparepart[min]->price;
      }

      // Melakukan update variabel min dengan indeks element yang memiliki nilai lebih kecil
      if (condition) {
        min = j;
      }
    }

    // Menukar element saat ini dengan element dengan indeks min
    Sparepart *temp = sparepart[i];
    sparepart[i] = sparepart[min];
    sparepart[min] = temp;
  }
}

/*
Fungsi untuk melakukan binary search pada array pointer Sparepart
Mengembalikan index jika ditemukan, atau -1 jika tidak ditemukan
*/
int binarySearch(Sparepart *sparepart[], int &currentSparepart, string targetId) {
  // Menetapkan indeks batas kiri dalam pencarian
  int left = 0;
  // Menetapkan indeks batas kanan dalam pencarian
  int right = currentSparepart - 1;

  // Lakukan iterasi jika ada element dalam array yang digunakan
  while (left <= right) {

    // Menetapkan nilai tengah
    int mid = left + (right - left) / 2;

    // Periksa apakah element dengan indeks nilai mid sama dengan element yang dicari
    if (sparepart[mid]->idProduct == targetId) {
      // Data ditemukan kembalikan indeks tengah
      return mid;
    } 
    
    // Periksa apakah niali element dengan indeks mid lebih kecil dari nilai yang dicari
    else if (sparepart[mid]->idProduct < targetId) {
      // Pindahkan batas kiri ke kanan jika target lebih besar
      left = mid + 1;
    } else {
      // Pindahkan batas kanan ke kiri jika target lebih kecil
      right = mid - 1;
    }
  }
  // Data tidak ditemukan
  return -1;
}

/*
Fungsi untuk melakukan binary search pada array pointer SparepartChart
Mengembalikan index jika ditemukan, atau -1 jika tidak ditemukan
*/
int binarySearch(SparepartChart *sparepart[], int &currentSparepartChart, string targetId) {
  // Menetapkan indeks batas kiri dalam pencarian
  int left = 0;
  // Menetapkan indeks batas kanan dalam pencarian
  int right = currentSparepartChart - 1;

  // Lakukan iterasi jika ada element dalam array yang digunakan
  while (left <= right) {

    // Menetapkan nilai tengah
    int mid = left + (right - left) / 2;

    // Periksa apakah element dengan indeks nilai mid sama dengan element yang dicari
    if (sparepart[mid]->sparepart.idProduct == targetId) {
      // Data ditemukan kembalikan indeks tengah
      return mid;
    } 

    // Periksa apakah niali element dengan indeks mid lebih kecil dari nilai yang dicari
    else if (sparepart[mid]->sparepart.idProduct < targetId) {
      // Pindahkan batas kiri ke kanan jika target lebih besar
      left = mid + 1;
    } else {
      // Pindahkan batas kanan ke kiri jika target lebih kecil
      right = mid - 1;
    }
  }
  // Data tidak ditemukan
  return -1;
}

/*
Fungsi validasi string (dua input)
Mengembalikan true jika salah satu atau kedua string kosong
*/
bool isStringEmpty(string &valueOne, string &valueTwo) {
  // Mengecek apakah string pertama dan kedua kosong
  if (valueOne.empty() || valueTwo.empty() ){
    return true;
  } else {
    return false;
  }
}

/*
Fungsi validasi string (satu input)
Mengembalikan true jika string kosong
*/
bool isStringEmpty(string &value) {
  // Mengecek apakah string kosong
  if (value.empty()){
    return true;
  } else {
    return false;
  }
}

/*
Fungsu untuk menampilkan menu registrasi user baru
*/
void registerMenu(User *user[], int &currentUser) {
  // Deklarasi variabel username untuk menampung username
  string usernameRegister;
  // Deklarasi variabel password untuk menampung password user
  string passwordRegister;

    // Header
    cout << endl <<"+-----------------------------+\n";
    cout << "|         REGISTRASI          |\n";
    cout << "+-----------------------------+\n";

    // Form username
    cout << "| Masukkan Username           |\n";
    cout << "+-----------------------------+\n";
    cout << "+-> ";
    // Mengambil input username dari user
    getline(cin, usernameRegister);

    // Form password
    cout << "+-----------------------------+\n";
    cout << "| Masukkan Password           |\n";
    cout << "+-----------------------------+\n";
    cout << "+-> ";
    // Mengambil input password dari user
    getline(cin, passwordRegister);

  if (isStringEmpty(usernameRegister, passwordRegister)){
    // Menampilkan pesan kesalahan input username dan password
    cout << "\n+----------------------------------------------+\n";
    cout << "|  Masukkan Username dan Password yang valid!  |\n";
    cout << "+----------------------------------------------+\n";
  } else {
    // Mengassigning username, password, dan role ke array pointer of struct User
    user[currentUser]->username = usernameRegister;
    user[currentUser]->password = passwordRegister;
    user[currentUser]->role = "kasir";

    // Melakukan increment jumlah user yang terdaftar
    currentUser++;

    // Menampilkan pesan berhasil registrasi
    cout << "\n+-----------------------------+\n";
    cout << "|  Registrasi Berhasil!       |\n";
    cout << "+-----------------------------+\n";
  }
}

/*
Fungsi untuk menjalankan menu login
Fungsi ini akan meminta user untuk memasukkan username dan password
*/
void loginMenu(User *user[], Sparepart *sparepart[], int &currentUser, int &currentSparepart, SparepartChart *sparepartChart[], int &currentSparepartChart) {
  while (true) {
    
    // Deklarasi variabel username untuk menampung username
    string usernameLogin;
  
    // Deklarasi variabel password untuk menampung password user
    string passwordLogin;

    // Header Login
    cout << endl <<"+-----------------------------+\n";
    cout << "|           LOGIN             |\n";
    cout << "+-----------------------------+\n";

    // Input Username
    cout << "| Masukkan Username           |\n";
    cout << "+-----------------------------+\n";
    cout << "+-> ";
    // Mengambil input username dari user
    getline(cin, usernameLogin);

    // Input Password
    cout << "+-----------------------------+\n";
    cout << "| Masukkan Password          |\n";
    cout << "+-----------------------------+\n";
    cout << "+-> ";
    // Mengambil input password dari user
    getline(cin, passwordLogin);
    
    // Deklarasi variabel isExist untuk mengecek username dan password
    bool isExistCashier = false;
    bool isExistInventoryStaff = false;

    // Melakukan perulangan untuk mengecek apakah username dan password yang dimasukkan sesuai dengan data yang ada
    for (int i = 0; i < currentUser; i++) {
      // Mengecek usernam dan password dengan role inventaris
      if (user[i]->username == usernameLogin && user[i]->password == passwordLogin && user[i]->role == "inventaris") {
        
        // Jika username dan password ditemukan ubah variable isExistInventoryStaff
        isExistInventoryStaff = true;

        // Menampilkan pesan berhasil login
        cout << "\n+-----------------------------+\n";
        cout << "|       Login Berhasil!       |\n";
        cout << "+-----------------------------+\n";
        break;
      }
      // Mengecek usernam dan password dengan role kasir
      if (user[i]->username == usernameLogin && user[i]->password == passwordLogin && user[i]->role == "kasir") {
        
        // Jika username dan password ditemukan ubah variable isExistCashier
        isExistCashier = true;

        // Menampilkan pesan berhasil login
        cout << "\n+-----------------------------+\n";
        cout << "|       Login Berhasil!       |\n";
        cout << "+-----------------------------+\n";
        break;
      }
    }
    
    if (isExistInventoryStaff) {
      // Memanggil fungsi untuk menampilkan menu utama inventaris
      mainMenuInventory(sparepart, currentSparepart);
      break;
    }else if (isExistCashier) {
      // Memanggil fungsi untuk menampilkan menu utama cashier
      mainMenuCashier(sparepart, currentSparepart, sparepartChart, currentSparepartChart);
      break;
    } else {
      // Menampilkan pesan kesalahan input username dan password
      cout << "\n+------------------------------------------------------+\n";
      cout << "|   Username atau Password yang Anda masukkan salah!   |\n";
      cout << "+------------------------------------------------------+\n";
      break;
    }
  }
}

/*
Fungsi untuk menampilkan menu utama inventaris sparepart
*/
void mainMenuInventory(Sparepart *sparepart[], int &currentSparepart) {
  while (true) {
    try {
      // Menjeda program selama 1 detik untuk memberikan jeda sebelum menampilkan menu
      pause(1);
      // Memanggil fungsi untuk membersihkan layar
      clearScreen();

      // Deklarasi variabel choiceUser untuk menampung konversi pilihan user
      int choiceUser;

      // Deklarasi variabel inputUser untuk menampung pilihan user berupa string
      string inputUser;
      cout << endl <<"==============================================\n";
      cout << "|           MENU INVENTARIS SPAREPART         |\n";
      cout << "==============================================\n";
      cout << "|  1  | Tambah Sparepart                      |\n";
      cout << "|  2  | Tampilkan Sparepart                   |\n";
      cout << "|  3  | Ubah Stok Sparepart                   |\n";
      cout << "|  4  | Hapus Sparepart                       |\n";
      cout << "|  5  | Keluar                                |\n";
      cout << "==============================================\n";

      // Prompt meminta pilihan user
      cout << "Masukkan pilihan Anda : ";

      // Membaca input string dari user
      getline(cin, inputUser);

      /*Deklarasi variabel resultConvert untuk menampung hasil convert string
      resultConvert akan bernilai true jika convert berhasil dan bernilai false jika gagal
      convertStringToInt akan mengconvert nilai dari inputUser dan menyimpan nilai hasil convert ke choiceUser
      */
      bool resultConvert = convertStringToInt(inputUser, choiceUser);

      // Melakukan validasi terhadapa resultConvert, akan melakukan throw error jika convert gagal
      if (!resultConvert) {
        throw invalid_argument("Harap inputkan angka!");
      }

      // Melakukan pengecekan pilihan user yang telah diconvert ke integer
      switch (choiceUser) {
        case 1:
          // Memanggil fungsi untuk membersihkan layar
          clearScreen();  

          // Menampilkan header untuk tambah sparepart
          cout << endl <<"+===========================+\n";
          cout << "|     TAMBAH SPAREPART      |\n";
          cout << "+===========================+\n";

          // Mengecek apakah sparepart sudah mencapai batas maksimal
          if (currentSparepart < MAX_SPAREPART){

            // Memanggil fungsi untuk menambahkan sparepart
            addSparepart(sparepart, currentSparepart);
          } else {
            // Menampilkan pesan gagal menambahkan sparepart karena inventaris penuh
            cout << "\n+------------------------------------------------------+\n";
            cout << "|  Tidak bisa menambahkan sparepart: inventaris penuh! |\n";
            cout << "+------------------------------------------------------+\n";
          }
          break;
        case 2: 
          cout << endl;
          // Mengecek apakah ada sparepart yang bisa ditampilkan
          if (currentSparepart == 0) {

            // Menampilkan pesan tidak ada sparepart yang bisa ditampilkan
            cout << "\n+----------------------------------------------+\n";
            cout << "|  Tidak ada sparepart yang dapat ditampilkan! |\n";
            cout << "+----------------------------------------------+\n";
          } else {
            // Memanggil fungsi untuk menampilkan sparepart
            showSparepart(sparepart, currentSparepart);
          }
          break;
        case 3:
          // Memanggil fungsi untuk membersihkan layar  
          clearScreen();
          // Menampilkan header untuk ubah stok sparepart
          cout << endl << "+===========================+\n";
          cout << "|    UBAH STOK SPAREPART    |\n";
          cout << "+===========================+\n";

          // Mengecek apakah ada sparepart yang bisa diubah stoknya
          if (currentSparepart == 0) {

            // Menampilkan pesan tidak ada sparepart yang bisa diubah
            cout << "\n+---------------------------------------------+\n";
            cout << "|  Tidak ada data sparepart yang bisa diubah! |\n";
            cout << "+---------------------------------------------+\n";
          } else {

            //Menampilkan sparepart yang ada dalam inventaris
            printSparepart(sparepart, currentSparepart);

            // Memanggil fungsi untuk mengubah stok sparepart
            changeStockSparepart(sparepart, currentSparepart);
          }
          break;
        case 4:
          // Memanggil fungsi untuk membersihkan layar  
          clearScreen();
          // Menampilkan header untuk hapus sparepart
          cout << endl <<"+===========================+\n";
          cout << "|      HAPUS SPAREPART      |\n";
          cout << "+===========================+\n";

          // Mengecek apakah ada sparepart yang bisa dihapus
          if (currentSparepart == 0) {

            // Menampilkan pesan tidak ada sparepart yang bisa dihapus
            cout << "\n+---------------------------------------------+\n";
            cout << "|  Tidak ada sparepart yang bisa dihapus!     |\n";
            cout << "+---------------------------------------------+\n";
          } else {
            // Menampilkan sparepart yang ada dalam inventaris
            printSparepart(sparepart, currentSparepart);

            //Memanggil fungsi untuk menghapus sparepart
            deleteSparepart(sparepart, currentSparepart);
          }
          break;
        case 5:
          // Keluar dari program
          cout << "\n+----------------------------------+\n";
          cout << "|   Keluar dari MENU INVENTARIS!   |\n";
          cout << "+----------------------------------+\n";
          break;
        default:
          // Menampilkan pesan kesalahan input pilihan
          cout << "\n+----------------------------------------+\n";
          cout << "|   Maaf, pilihan Anda tidak tersedia!   |\n";
          cout << "+----------------------------------------+\n";
          break;
      }

      // Keluar dari menu inventaris jika pilihan user == 5
      if (choiceUser == 5) {
        break;
      }
    }
    // Code block dibawah ini akan dijalankan jika user memasukkan huruf pada input pilihan
    catch(const invalid_argument& e){
      cout << "\n+-------------------------------+\n";
      cout << "|    " << e.what() << "      |\n";
      cout << "+-------------------------------+\n";
    }
    
  }
}

/*
Fungsi untuk menambahkan sparepart baru ke dalam inventaris
*/
void addSparepart(Sparepart *sparepart[], int &currentSparepart) {
  try{
    // Deklarasi variabel idProuct untuk menampung idProuct sparepart
    string idProuct;
    // Deklarasi variabel name untuk menampung nama sparepart
    string name;
    // Deklarasi variabel stock, menampung kuantitas sparepart setelah dikonversi
    int stock;
    // Deklarasi variabel price untuk menampung harga sparepart setelah dikonversi
    int price;

    // Deklarasi variabel inputStcok untuk menampung input stock sparepart
    string inputStock;

    // Deklarasi variabel inputPirce untuk menampung input harga sparepart
    string inputPirce;

    // Melakukan input id produk sparepart
    cout << "\nMasukkan id produk sparepart : ";
    // Mengabaikan newline character dari input sebelumnya
    getline(cin, idProuct);

    // Melakukan input nama sparepart
    cout << "Masukkan nama sparepart : ";
    getline(cin, name);

    // Melakukan input jumlah sparepart
    cout << "Masukkan jumlah sparepart : ";
    getline(cin, inputStock);

    // Melakukan input harga sparepart
    cout << "Masukkan total harga per item : ";
    getline(cin, inputPirce);

    /*
    Deklarasi variabel resultConvert untuk menampung hasil convert string
    resultConvert akan bernilai true jika convert berhasil dan bernilai false jika gagal
    convertStringToInt akan mengconvert nilai dari inputStock 
    dan menyimpan nilai hasil convert ke stock
    */
    bool resultConvertStock = convertStringToInt(inputStock, stock);

    /*
    Deklarasi variabel resultConvert untuk menampung hasil convert string
    resultConvert akan bernilai true jika convert berhasil dan bernilai false jika gagal
    convertStringToInt akan mengconvert nilai dari inputPirce 
    dan menyimpan nilai hasil convert ke price
    */
    bool resultConvertPrice = convertStringToInt(inputPirce, price);

    // Melakukan validasi semua input
    if (price < 500 || stock < 0 || isStringEmpty(name, idProuct)) {
      // Menampilkan pesan kesalah input
      cout << "\n+------------------------------------------------------------------+\n";
      cout << "| Masukkan id, nama, jumlah, dan total harga sparepart yang valid! |\n";
      cout << "+------------------------------------------------------------------+\n";

    } else {

      /*
      Melakukan validasi terhadapa resultConvert, akan melakukan 
      throw error jika convert gagal
      */
      if (!resultConvertStock || !resultConvertPrice) {
        throw invalid_argument("Harap masukkan angka pada input stock dan harga!");
      }

      // Append semua field ke dalam array masing-masing
      sparepart[currentSparepart]->idProduct = idProuct;
      sparepart[currentSparepart]->name = name;
      sparepart[currentSparepart]->stock = stock;
      sparepart[currentSparepart]->price = price;

      // Melakukan increment pada banyaknya produk
      currentSparepart++;

      // Menampilkan pesan berhasil menambahkan sparepart
      cout << "\n+----------------------------------+\n";
      cout << "|  Berhasil menambahkan sparepart! |\n";
      cout << "+----------------------------------+\n";
    }
  }
  /*
  Code block di bawah ini akan dijalankan jika user memasukkan
  huruf pada input stock dan price
  */
  catch(const invalid_argument& e){
    cout << "\n+----------------------------------------------------------+\n";
    cout << "|    " << e.what() << "      |\n";
    cout << "+----------------------------------------------------------+\n";
  }
  
}

/*
Fungsi ini digunakan untuk menampilkan menu yang nanti digunakan 
untuk menampilkan sparepart yang ada dalam inventaris
*/
void showSparepart(Sparepart *sparepart[], int &currentSparepart) {
  
  try {
    /*
    Mengecek apakah spareapart yang ada dalam inventaris berjumlah 1,
    Jika iya maka tidak perlu dilakukan sorting, langsung tampilkan sparepart
    */
    if (currentSparepart == 1) {
    
      // Menampilkan sparepart yang ada dalam inventaris
      printSparepart(sparepart, currentSparepart);
    } else {
      // Memanggil fungsi untuk membersihkan layar
      clearScreen();
      // Deklarasi variabel choiceUser untuk menampung konversi pilihan user
      int choiceUser;
      // Deklarasi variabel inputUser untuk menampung pilihan user setelah dikonversi
      string inputUser;
    
      // Menu Tampilkan Sparepart
      cout << "==============================================\n";
      cout << "|          TAMPILKAN SPAREPART - SORTING      |\n";
      cout << "==============================================\n";
      cout << "|  No |               Opsi                    |\n";
      cout << "----------------------------------------------\n";
      cout << "|  1  | Sort berdasarkan Nama (A - Z)         |\n";
      cout << "|  2  | Sort berdasarkan Harga (Dari Termurah)|\n";
      cout << "|  3  | Sort berdasarkan Stok (Dari Terkecil) |\n";
      cout << "==============================================\n";
      
      // Input pilihan user
      cout << "Masukkan pilihan Anda : ";

      // Membaca input string dari user
      getline(cin, inputUser);
      
      /*Deklarasi variabel resultConvert untuk menampung hasil convert string
      resultConvert akan bernilai true jika convert berhasil dan bernilai false jika gagal
      convertStringToInt akan mengconvert nilai dari inputUser dan menyimpan nilai hasil convert ke choiceUser
      */
      bool resultConvert = convertStringToInt(inputUser, choiceUser);

      // Melakukan validasi terhadapa resultConvert, akan melakukan throw error jika convert gagal
      if (!resultConvert) {
        throw invalid_argument("Harap masukkan angka pada input pilihan!");
      }

      string enter;
      // Melakukan pengecekan pilihan user yang telah diconvert ke integer
      switch (choiceUser) {
        case 1:
          // Melakukan sorting berdasarkan nama sparepart
          selectionSort(sparepart, currentSparepart, "name");
          cout << endl << "Sort by Name (A-Z)" << endl;
            
          // Menampilkan sparepart yang telah diurutkan berdasarkan nama
          printSparepart(sparepart, currentSparepart);

          // Menunggu input dari user sebelum melanjutkan
          getline(cin, enter);
          break;
        case 2:
          // Melakukan sorting berdasarkan harga sparepart
          selectionSort(sparepart, currentSparepart, "price");
          cout << endl << "Sort by Price (Ascending)" << endl;

          // Menampilkan sparepart yang telah diurutkan berdasarkan harga
          printSparepart(sparepart, currentSparepart);

          // Menunggu input dari user sebelum melanjutkan
          getline(cin, enter);
          break;
        case 3:
          // Melakukan sorting berdasarkan stok sparepart
          selectionSort(sparepart, currentSparepart, "stock");
          cout << endl << "Sort by Stock (Ascending)" << endl;

          // Menampilkan sparepart yang telah diurutkan berdasarkan stok
          printSparepart(sparepart, currentSparepart);

          // Menunggu input dari user sebelum melanjutkan
          getline(cin, enter);
          break;
        default:
          // Menampilkan pesan kesalahan input pilihan
          cout << "\n+----------------------------------------+\n";
          cout << "|   Maaf, pilihan Anda tidak tersedia!   |\n";
          cout << "+----------------------------------------+\n";
          break;
      }
    }
  }
  // Code block dibawah ini akan dijalankan jika user memasukkan huruf pada input pilihan
  catch(const invalid_argument& e){
    cout << "\n+------------------------------------------------+\n";
    cout << "|    " << e.what() << "    |\n";
    cout << "+------------------------------------------------+\n";
  }
}

/*
Menampilkan sparepart yang ada dalam inventaris ke terminal
*/
void printSparepart(Sparepart *sparepart[], int &currentSparepart) {
  // Menampilkan header tabel
  cout << "+----+--------------+------------------------------------------+--------+-------------+" << endl;
  cout << "| No | ID Product   | Sparepart                                | Stok   | Harga       |" << endl;
  cout << "+----+--------------+------------------------------------------+--------+-------------+" << endl;

  // Melakukan perulangan sebanyak jumlah sparepart yang ada
  for (int i = 0; i < currentSparepart; i++) {

    // Menampilkan nomor sparepart, ID produk, nama sparepart, stok, dan harga
    cout << "| " << i + 1;
    i + 1 < 10 ? cout << "  " : cout << " ";

    cout << "|    " << sparepart[i]->idProduct << "     ";

    cout << "| " << sparepart[i]->name;
    for (int j = sparepart[i]->name.length(); j < 40; j++) {
      cout << " ";
    }
    cout << " | " << sparepart[i]->stock;
    if (sparepart[i]->stock < 10 ) {
      cout << "     ";
    } else if (sparepart[i]->stock < 100) {
      cout << "    ";
    } else {
      cout << "   ";
    }
    cout << " | " << sparepart[i]->price;
    if (sparepart[i]->price < 10000) {
      cout << "       ";
    } else if (sparepart[i]->price < 100000) {
      cout << "      ";
    } else {
      cout << "     ";
    }
    cout << " |" << endl;
  }
  // Menutup tabel
  if (currentSparepart != 0) {
    cout << "+----+--------------+------------------------------------------+--------+-------------+" << endl;
  }
}

/*
Fungsi untuk mengubah stok sparepart yang ada dalam inventaris
*/
void changeStockSparepart(Sparepart *sparepart[], int &currentSparepart) {

  try {
    // Deklarasi variabel indexSparepart untuk menampung index sparepart setelah dikonversi
    int indexSparepart;
    // Deklarasi variabel inputIndex untuk menampung input index sparepart
    string inputIndex;

    // Melakukan input index sparepart
    cout << "Masukkan No sparepart : ";
    getline(cin, inputIndex);

    /*Deklarasi variabel resultConvert untuk menampung hasil convert string
    resultConvert akan bernilai true jika convert berhasil dan bernilai false jika gagal
    convertStringToInt akan mengconvert nilai dari inputIndex 
    dan menyimpan nilai hasil convert ke indexSparepart
    */
    bool resultConvert = convertStringToInt(inputIndex, indexSparepart);

    // Melakukan validasi terhadapa resultConvert, akan melakukan throw error jika convert gagal
    if (!resultConvert) {
      throw invalid_argument("Harap masukkan angka pada input no sparepart!");
    }

    // Memvalidasi index sparepart
    if (indexSparepart > 0 && indexSparepart <= currentSparepart) {
      // Deklarasi variabel newStock untuk menampung stok sparepart yang baru setelah dikonversi
      int newStock;
      // Dekalrasi variabel inputnewStock untuk menampung input stok sparepart yang baru
      string inputnewStock;

      // Melakukan input stok sparepart yang baru
      cout << "Masukkan stok sparepart : ";
      getline(cin, inputnewStock);

      /*Deklarasi variabel resultConvert untuk menampung hasil convert string
      resultConvert akan bernilai true jika convert berhasil dan bernilai false jika gagal
      convertStringToInt akan mengconvert nilai dari inputnewStock 
      dan menyimpan nilai hasil convert ke newStock
      */
      bool resultConvertStock = convertStringToInt(inputnewStock, newStock);

      // Melakukan validasi terhadapa resultConvert, akan melakukan throw error jika convert gagal
      if (!resultConvertStock) {
        throw invalid_argument("Harap masukkan angka pada saat input stok baru!");
      }

      if (newStock < 0) {
        // Menampilkan pesan gagal memperbarui stok sparepart
        cout << "\n+-----------------------------------+\n";
        cout << "| Gagal memperbarui stok sparepart! |\n";
        cout << "+-----------------------------------+\n";
      } else {
        // Mengubah stok sparepart
        sparepart[indexSparepart - 1]->stock = newStock;

        // Menampilkan pesan berhasil mengubah stok sparepart
        cout << "\n+---------------------------+\n";
        cout << "|  Berhasil mengubah stok!  |\n";
        cout << "+---------------------------+\n";
      }
    } else {
      // Menampilkan pesan kesalahan input index sparepart
      cout << "\n+----------------------------------+\n";
      cout << "|   Nomor sparepart tidak valid!   |\n";
      cout << "+----------------------------------+\n";
    }
  }
  /*
  Code block di bawah ini akan dijalankan jika user memasukkan
  huruf pada input index sparepart atau stok baru sparepart
  */
  catch(const invalid_argument& e){

    // Melakukan pengecekan apakah pesan error yang dilempar adalah karena input stok
    // Jika iya, tampilkan pesan khusus untuk error input stok
    if (e.what() == "Harap masukkan angka pada saat input stok baru!") {
      cout << "\n+----------------------------------------------------------+\n";
      cout << "|     " << e.what() << "     |\n";
      cout << "+----------------------------------------------------------+\n";
    } else {
      cout << "\n+-----------------------------------------------------+\n";
      cout << "|    " << e.what() << "    |\n";
      cout << "+-----------------------------------------------------+\n";
    }
  }
}

/*
Menghapus sparepart dari inventaris
*/
void deleteSparepart(Sparepart *sparepart[], int &currentSparepart) {
  try{
    // Deklarasi variabel indexSparepart untuk menampung index sparepart setelah dikonversi
    int indexSparepart;
    // Deklarasi variabel inputIndex untuk menampung input index sparepart
    string inputIndex;

    // Melakukan input index sparepart
    cout << "Masukkan No sparepart : ";
    getline(cin, inputIndex);

    /*Deklarasi variabel resultConvert untuk menampung hasil convert string
    resultConvert akan bernilai true jika convert berhasil dan bernilai false jika gagal
    convertStringToInt akan mengconvert nilai dari inputIndex 
    dan menyimpan nilai hasil convert ke indexSparepart
    */
    bool resultConvert = convertStringToInt(inputIndex, indexSparepart);
    
    // Melakukan validasi terhadapa resultConvert, akan melakukan throw error jika convert gagal
    if (!resultConvert) {
      throw invalid_argument("Harap masukkan angka pada input no sparepart!");
    }

    // Memvalidasi index sparepart
    if (indexSparepart > 0 && indexSparepart <= currentSparepart) {

      // Menggeser elemen-elemen dalam array sparepart
      for (int i = indexSparepart - 1; i < currentSparepart - 1; i++) {
        sparepart[i] = sparepart[i + 1];
      }
      // Mengurangi jumlah sparepart yang ada dalam inventaris
      currentSparepart--;

      // Menampilkan pesan berhasil menghapus sparepart
      cout << "\n+-----------------------------------------+\n";
      cout << "|      Berhasil menghapus sparepart!      |\n";
      cout << "+-----------------------------------------+\n";
    } else {
      // Menampilkan pesan kesalahan input index sparepart
      cout << "\n+----------------------------------+\n";
      cout << "|   Nomor sparepart tidak valid!   |\n";
      cout << "+----------------------------------+\n";
    }
  }
  /*
  Code block di bawah ini akan dijalankan jika user memasukkan
  huruf pada index sparepart
  */
  catch(const invalid_argument& e){
    cout << "\n+-----------------------------------------------------+\n";
    cout << "|    " << e.what() << "    |\n";
    cout << "+-----------------------------------------------------+\n";
  }
  
}

/*
Fungsi untuk menampilkan menu utama cashier
*/
void mainMenuCashier(Sparepart *sparepart[], int &currentSparepart, SparepartChart *sparepartChart[], int &currentSparepartChart) {
  while (true) {
    try {
      // Menjeda program selama 1 detik untuk memberikan jeda sebelum menampilkan menu
      pause(1);
      // Memanggil fungsi untuk membersihkan layar
      clearScreen();

      // Menampilkan sparepart dalam keranjang belanjaan
      // Menampilkan header tabel
      cout << endl <<"===========================================================================================" << endl;
      cout << "                                   KERANJANG BELANJA                                       " << endl;
      cout << "===========================================================================================" << endl;
      cout << "+----+--------------+------------------------------------------+-----------+--------------+" << endl;
      cout << "| No | ID Product   | Sparepart                                | Kuantitas | Harga/satuan |" << endl;
      cout << "+----+--------------+------------------------------------------+-----------+--------------+" << endl;
      // Menampilkan data sparepart dalam tabel
      for (int i = 0; i < currentSparepartChart; i++) {
        // Menampilkan nomor sparepart, ID produk, nama sparepart, kuantitas, dan harga
        cout << "| " << i + 1;
        i + 1 < 10 ? cout << "  " : cout << " ";
        cout << "|    " << sparepartChart[i]->sparepart.idProduct << "     ";
        cout << "| " << sparepartChart[i]->sparepart.name;
        for (int j = sparepartChart[i]->sparepart.name.length(); j < 40; j++) {
          cout << " ";
        }
        cout << " |  " << sparepartChart[i]->quantity;
        if (sparepartChart[i]->quantity < 10 ) {
          cout << "       ";
        } else if (sparepartChart[i]->quantity < 100) {
          cout << "      ";
        } else {
          cout << "     ";
        }
        cout << " | " << sparepartChart[i]->sparepart.price;
        if (sparepartChart[i]->sparepart.price < 10000) {
          cout << "       ";
        } else if (sparepartChart[i]->sparepart.price < 100000) {
          cout << "      ";
        } else {
          cout << "     ";
        }
        cout << "  |" << endl;
      }
        // Melakukan pengecekan apakah ada sparepart dalam keranjang belanja
        if (currentSparepartChart != 0) {
          // Deklarasi variabel totalPrice untuk menampung total harga sparepart dalam keranjang belanja
          int totalPrice = 0;

          // Menghitung total harga sparepart dalam keranjang belanja
          for (int i = 0; i < currentSparepartChart; i++) {
            // Menghitung total harga sparepart dalam keranjang belanja
            totalPrice += sparepartChart[i]->sparepart.price * sparepartChart[i]->quantity;
          }
          cout << "+----+--------------+------------------------------------------+-----------+--------------+" << endl;
          cout << "|                                                            Total Harga : Rp. " << totalPrice;
          if (totalPrice < 10000) {
            cout << "       |" << endl;
          } else if (totalPrice < 100000) {
            cout << "      |" << endl;
          } else {
            cout << "     |" << endl;
          }

          // Menutup tabel
          cout << "+-----------------------------------------------------------------------------------------+" << endl;
        }
      
      
      // Deklarasi variabel choiceUser untuk menampung pilihan user setelah dikonversi
      int choiceUser;
      // Deklarasi variabel inputUser untuk menampung pilihan user berupa string
      string inputUser;
      // Menampilkan Menu
      cout << endl  << "===============================================\n";
      cout << "|            MENU CASHIER SPAREPART            |\n";
      cout << "===============================================\n";
      cout << "|  1  | Tambah Ke Daftar Belanja               |\n";
      cout << "|  2  | Ubah Kuantitas                         |\n";
      cout << "|  3  | Hapus Dari Daftar Belanja              |\n";
      cout << "|  4  | Transaksi Selesai                      |\n";
      cout << "|  5  | Keluar                                 |\n";
      cout << "===============================================\n";
      cout << "Masukkan pilihan Anda : ";
      
      // Membaca input string dari user
      getline(cin, inputUser);
      
      /*Deklarasi variabel resultConvert untuk menampung hasil convert string
      resultConvert akan bernilai true jika convert berhasil dan bernilai false jika gagal
      convertStringToInt akan mengconvert nilai dari inputUser 
      dan menyimpan nilai hasil convert ke choiceUser
      */
      bool resultConvert = convertStringToInt(inputUser, choiceUser);
      
      // Melakukan validasi terhadapa resultConvert, akan melakukan throw error jika convert gagal
      if (!resultConvert) {
        throw invalid_argument("Harap masukkan angka pada input pilihan!");
      }
      switch (choiceUser) {
        case 1:
          // Memanggil fungsi untuk membersihkan layar  
          clearScreen();
          // Menampilkan header untuk tambah sparepart ke daftar belanja
          cout << "+============================+\n";
          cout << "|  TAMBAH KE DAFTAR BELANJA  |\n";
          cout << "+============================+\n";
          // Mengecek apakah ada data sparepart yang bisa ditambahkan ke keranjang
          if (currentSparepart != 0){
            // Memanggil fungsi untuk menambahkan sparepart ke keranjang belanja
            addToChart(sparepart, currentSparepart, sparepartChart, currentSparepartChart);
          } else {
            // Menampilkan pesan gagal menambahkan sparepart ke keranjang karena inventaris kosong
            cout << "\n+------------------------------------------------------+\n";
            cout << "|  Tidak bisa tambah ke keranjang: inventaris kosong! |\n";
            cout << "+------------------------------------------------------+\n";
          }
          break;
        case 2:
          // Menampilkan header untuk ubah kuantitas sparepart dalam keranjang
          cout << "+===========================+\n";
          cout << "|      UBAH KUANTITAS       |\n";
          cout << "+===========================+\n";
          // Mengecek apakah ada sparepart dalam keranjang belanja
          if (currentSparepartChart == 0) {
            // Menampilkan pesan tidak ada sparepart dalam keranjang untuk diubah
            cout << "\n+---------------------------------------------------------+\n";
            cout << "|    Tidak ada sparepart dalam keranjang untuk diubah!    |\n";
            cout << "+---------------------------------------------------------+\n";
          } else {
            // Memanggil fungsi untuk mengubah kuantitas sparepart dalam keranjang
            changeQuantity(sparepartChart, currentSparepartChart);
          }
          break;
        case 3:
          // Menampilkan header untuk hapus sparepart dari daftar belanja
          cout << "+===========================+\n";
          cout << "| HAPUS DARI DAFTAR BELANJA |\n";
          cout << "+===========================+\n";
          // Mengecek apakah ada sparepart dalam keranjang belanja
          if (currentSparepartChart == 0) {
            // Menampilkan pesan tidak ada sparepart dalam keranjang untuk dihapus
            cout << "\n+---------------------------------------------------------+\n";
            cout << "|  Tidak ada sparepart dalam keranjang yang bisa dihapus! |\n";
            cout << "+---------------------------------------------------------+\n";
          } else {
            // Memanggil fungsi untuk menghapus sparepart dari keranjang belanja
            deleteFromChart(sparepartChart, currentSparepartChart);
          }
          break;
        case 4:
          // Mengecek apakah ada sparepart dalam keranjang belanja
          if (currentSparepartChart == 0) {
            // Menampilkan pesan tidak ada sparepart dalam keranjang untuk dikonfirmasi
            cout << "\n+----------------------------------------------------------------+\n";
            cout << "|  Tidak ada sparepart yang terdaftar dalam keranjang belanja!   |\n";
            cout << "+----------------------------------------------------------------+\n";
          } else {
            // Memanggil fungsi untuk mengkonfirmasi transaksi
            confirmTransaction(sparepart, currentSparepart, sparepartChart, currentSparepartChart);
          }
          break;
        case 5:
          // Keluar dari program
          cout << "\n+----------------------------+\n";
          cout << "|   Keluar dari MENU KASIR!  |\n";
          cout << "+----------------------------+\n";
          break;
        default:
          // Menampilkan pesan kesalahan input pilihan
          cout << "\n+----------------------------------------+\n";
          cout << "|   Maaf, pilihan Anda tidak tersedia!   |\n";
          cout << "+----------------------------------------+\n";
          break;
      }
      // Keluar dari menu cashier jika pilihan user == 5
      if (choiceUser == 5) {
        break;
      }
    }
    // Code block dibawah ini akan dijalankan jika user memasukkan huruf pada input pilihan
    catch(const invalid_argument& e){
      cout << "\n+------------------------------------------------+\n";
      cout << "|    " << e.what() << "    |\n";
      cout << "+------------------------------------------------+\n";
    }
  }
}

void addToChart(Sparepart *sparepart[], int &currentSparepart, SparepartChart *sparepartChart[], int &currentSparepartChart) {
  try {
    // Deklarasi variabel inputIDProduct untuk menampung ID sparepart
    string inputIDProduct;

    // Deklarasi variabel quantity untuk menampung kuantitas sparepart setelah dikonversi
    int quantity;

    // Deklarasi variabel inputQuantity untuk menampung input kuantitas sparepart
    string inputQuantity;

    // Melakukan input ID produk sparepart
    cout << "Masukkan ID product sparepart : ";


    getline(cin, inputIDProduct);

    // Melakukan input kuantitas sparepart
    cout << "Masukkan kuantitas barang : ";
    getline(cin, inputQuantity);

    /*Deklarasi variabel resultConvertQuantity untuk menampung hasil convert string
    resultConvertQuantity akan bernilai true jika convert berhasil dan bernilai false jika gagal
    convertStringToInt akan mengconvert nilai dari inputQuantity 
    dan menyimpan nilai hasil convert ke quantity
    */
    bool resultConvertQuantity = convertStringToInt(inputQuantity, quantity);
    
    // Melakukan validasi semua input
    if (quantity < 0 || isStringEmpty(inputIDProduct)) {
      // Menampilkan pesan kesalahan input idProduct dan kuantitas
      cout << "\n+---------------------------------------------------------+\n";
      cout << "| Masukkan ID product dan kuantitas sparepart yang valid! |\n";
      cout << "+---------------------------------------------------------+\n";
    } else {

      // Melakukan validasi terhadapa resultConvertQuantity, akan melakukan throw error jika convert gagal
      if (!resultConvertQuantity) {
        throw invalid_argument("Harap masukkan angka pada input quantity!");
      }

      // Mencari apakah id produk yang diinputkan telah terdaftar ke dalam keranjang
      int isExistIDProductChart = binarySearch(sparepartChart, currentSparepartChart, inputIDProduct);

      // Jika sparepart dengan ID produk yang diinputkan sudah ada dalam keranjang maka tampilkan pesan
      if (isExistIDProductChart != -1) {
        // Menampilkan pesan bahwa sparepart sudah ada dalam keranjang
        cout << "\n+--------------------------------------------------+\n";
        cout << "|    Sparepart telah ditambahkan ke keranjang!     |\n";
        cout << "+--------------------------------------------------+\n"; 
      }

      // Jika sparepart dengan ID produk yang diinputkan belum ada dalam keranjang
      if (isExistIDProductChart == -1) {

        // Mencari apakah sparepart dengan ID produk yang diinputkan ada dalam inventaris
        int isExistIDProduct = binarySearch(sparepart, currentSparepart, inputIDProduct);

        // Jika sparepart dengan ID produk yang diinputkan ada dalam inventaris
        if (isExistIDProduct != -1) {

          // Menambahkan sparepart ke dalam keranjang
          sparepartChart[currentSparepartChart]->sparepart.idProduct = sparepart[isExistIDProduct]->idProduct;
          sparepartChart[currentSparepartChart]->sparepart.name = sparepart[isExistIDProduct]->name;
          sparepartChart[currentSparepartChart]->sparepart.price = sparepart[isExistIDProduct]->price;
          sparepartChart[currentSparepartChart]->sparepart.idProduct = sparepart[isExistIDProduct]->idProduct;
          sparepartChart[currentSparepartChart]->quantity = quantity;

          // Increment jumlah sparepart dalam keranjang
          currentSparepartChart++;

          // Menampilkan pesan berhasil menambahkan sparepart ke keranjang
          cout << "\n+--------------------------------------------------+\n";
          cout << "|   Berhasil menambahkan sparepart ke keranjang!   |\n";
          cout << "+--------------------------------------------------+\n";
        } 
        // Jika sparepart dengan ID produk yang diinputkan tidak ada dalam inventaris
        else if (isExistIDProduct == -1) {
          // Menampilkan pesan bahwa ID produk sparepart tidak ditemukan
          cout << "\n+-------------------------------------------------+\n";
          cout << "|   ID product sparepart tidak dapat ditemukan!   |\n";
          cout << "+-------------------------------------------------+\n";
        }
      }
      
    }
  }
  /*
  Code block di bawah ini akan dijalankan jika user memasukkan
  huruf pada input quantity
  */
  catch(const invalid_argument& e){
    cout << "\n+-------------------------------------------------+\n";
    cout << "|    " << e.what() << "    |\n";
    cout << "+-------------------------------------------------+\n";
  }
} 

/* 
Fungsi untuk mengubah kuantitas sparepart yang ada dalam keranjang belanjaan
*/
void changeQuantity(SparepartChart *sparepartChart[], int &currentSparepartChart) {
  try {
    // Deklarasi variabel indexSparepart untuk menampung index sparepart setelah dikonversi
    int indexSparepart;
    // Deklarasi variabel inputIndex untuk menampung input index sparepart
    string inputIndex;

    // Melakukan input index sparepart
    cout << "Masukkan no sparepart dalam keranjang : ";
    getline(cin, inputIndex);

    /*Deklarasi variabel resultConvertIndex untuk menampung hasil convert string
    resultConvertIndex akan bernilai true jika convert berhasil dan bernilai false jika gagal
    convertStringToInt akan mengconvert nilai dari inputIndex 
    dan menyimpan nilai hasil convert ke indexSparepart
    */
    bool resultConvertIndex = convertStringToInt(inputIndex, indexSparepart);

    // Melakukan validasi terhadapa resultConvertIndex, akan melakukan throw error jika convert gagal
    if (!resultConvertIndex) {
      throw invalid_argument("Harap masukkan angka pada input no sparepart!");
    }

    // Memvalidasi index sparepart
    if (indexSparepart > 0 && indexSparepart <= currentSparepartChart) {
      // Deklarasi variabel newQuantity untuk menampung kuantitas sparepart yang baru setelah dikonversi
      int newQuantity;
      // Deklarasi variabel inputNewQuantity untuk menampung input kuantitas sparepart yang baru
      string inputNewQuantity;

      // Melakukan input kuantitas sparepart yang baru
      cout << "Masukkan kuantitas sparepart : ";
      getline(cin, inputNewQuantity);

      /*Deklarasi variabel resultConvertNewQuantity untuk menampung hasil convert string
      resultConvertNewQuantity akan bernilai true jika convert berhasil dan bernilai false jika gagal
      convertStringToInt akan mengconvert nilai dari inputNewQuantity 
      dan menyimpan nilai hasil convert ke newQuantity
      */
      bool resultConvertNewQuantity = convertStringToInt(inputNewQuantity, newQuantity);

      // Melakukan validasi terhadapa resultConvert, akan melakukan throw error jika convert gagal
      if (!resultConvertNewQuantity) {
        throw invalid_argument("Harap masukkan angka pada input kuantitas baru!");
      }

      // Memvalidasi kuantitas sparepart yang baru
      // Jika kuantitas baru kurang dari 0, tampilkan pesan gagal memperbarui kuantitas
      if (newQuantity < 0) {
        // Menampilkan pesan gagal memperbarui kuantitas sparepart
        cout << "\n+--------------------------------------------------+\n";
        cout << "|      Gagal memperbarui kuantitas sparepart!      |\n";
        cout << "+--------------------------------------------------+\n";
      } else {
        // Mengubah kuantitas sparepart
        sparepartChart[indexSparepart - 1]->quantity = newQuantity;

        // Menampilkan pesan berhasil mengubah kuantitas sparepart
        cout << "\n+-----------------------------------------+\n";
        cout << "|      Berhasil mengubah kuantitas!       |\n";
        cout << "+-----------------------------------------+\n";
      }
    } else {
      // Menampilkan pesan kesalahan input index sparepart
      cout << "\n+----------------------------------+\n";
      cout << "|   Nomor sparepart tidak valid!   |\n";
      cout << "+----------------------------------+\n";
    }
  }
  /*
  Code block di bawah ini akan dijalankan jika user memasukkan
  huruf pada input index sparepart atau stok baru sparepart
  */
  catch(const invalid_argument& e){

    // Melakukan pengecekan apakah pesan error yang dilempar adalah karena input kuantitas
    // Jika iya, tampilkan pesan khusus untuk error input stok
    if (e.what() == "Harap masukkan angka pada input kuantitas baru!") {
      cout << "\n+----------------------------------------------------------+\n";
      cout << "|      " << e.what() << "     |\n";
      cout << "+----------------------------------------------------------+\n";
    } else {
      cout << "\n+-----------------------------------------------------+\n";
      cout << "|    " << e.what() << "    |\n";
      cout << "+-----------------------------------------------------+\n";
    }
  }
} 

/*
Fungsi untuk menghapus sparepart dari keranjang belanja
*/
void deleteFromChart(SparepartChart *sparepartChart[], int &currentSparepartChart){
  try {
    // Deklarasi variabel indexSparepart untuk menampung index sparepart setelah dikonversi
    int indexSparepart;
    // Deklarasi variabel inputIndex untuk menampung input index sparepart
    string inputIndex;

    // Melakukan input index sparepart
    cout << "Masukkan No sparepart : ";
    getline(cin, inputIndex);

    /*Deklarasi variabel resultConvertIndex untuk menampung hasil convert string
    resultConvertIndex akan bernilai true jika convert berhasil dan bernilai false jika gagal
    convertStringToInt akan mengconvert nilai dari inputIndex 
    dan menyimpan nilai hasil convert ke indexSparepart
    */
    bool resultConvertIndex = convertStringToInt(inputIndex, indexSparepart);

    // Melakukan validasi terhadapa resultConvertIndex, akan melakukan throw error jika convert gagal
    if (!resultConvertIndex) {
      throw invalid_argument("Harap masukkan angka pada input no sparepart!");
    }

    // Memvalidasi index sparepart
    if (indexSparepart > 0 && indexSparepart <= currentSparepartChart) {
      // Menggeser elemen-elemen dalam array sparepartChart
      for (int i = indexSparepart - 1; i < currentSparepartChart - 1; i++) {
        sparepartChart[i] = sparepartChart[i + 1];
      }

      // Mengurangi jumlah sparepart yang ada dalam keranjang
      currentSparepartChart--;

      // Menampilkan pesan berhasil menghapus sparepart dari keranjang
      cout << "\n+--------------------------------------------------+\n";
      cout << "|   Berhasil menghapus sparepart dari keranjang!   |\n";
      cout << "+--------------------------------------------------+\n";
    } else {
      // Menampilkan pesan kesalahan input index sparepart
      cout << "\n+----------------------------------+\n";
      cout << "|   Nomor sparepart tidak valid!   |\n";
      cout << "+----------------------------------+\n";
    }
  }
  /*
  Code block di bawah ini akan dijalankan jika user memasukkan
  huruf pada input index sparepart atau stok baru sparepart
  */
  catch(const invalid_argument& e){
    // Menampilkan pesan kesalahan input index sparepart
    cout << "\n+-----------------------------------------------------+\n";
    cout << "|    " << e.what() << "    |\n";
    cout << "+-----------------------------------------------------+\n";
  }
}

/*
Fungsi untuk mengkonfirmasi transaksi yang telah dilakukan
Jika transaksi telah selesai, maka stok sparepart dalam inventaris akan berkurang sesuai dengan kuantitas yang dibeli
*/
void confirmTransaction(Sparepart *sparepart[], int &currentSparepart, SparepartChart *sparepartChart[], int &currentSparepartChart) {
  // Melakukan perulangan sebanyak jumlah sparepart dalam keranjang belanja
  for (int i = 0; i < currentSparepartChart; ++i) {

    /*
    Mencari sparepart dalam inventaris berdasarkan ID produk, binary search 
    akan mengembalikan index sparepart yang sesuai
    */
    int indexSparepart = binarySearch(sparepart, currentSparepart, sparepartChart[i]->sparepart.idProduct);

    //Melakukan operasi pengurangan stok sparepart dalam inventaris dengan kuantitas yang dibeli
    sparepart[indexSparepart]->stock -= sparepartChart[i]->quantity;

    // Assigning sparepartChart ke nilai default
    sparepartChart[i]->sparepart.idProduct = "";
    sparepartChart[i]->sparepart.name = "";
    sparepartChart[i]->sparepart.price = 0;
    sparepartChart[i]->sparepart.stock = 0;
  }
  // Menetapkan jumlah sparepart dalam keranjang belanja menjadi 0
  currentSparepartChart = 0;

  // Menampilkan pesan transaksi selesai
  cout << "\n+------------------------+\n";
  cout << "|   Transaksi Selesai!   |\n";
  cout << "+------------------------+\n";
}
