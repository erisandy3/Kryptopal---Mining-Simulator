//KryptoPal - Simulator Mining
//Oleh: Kelompok 12 untuk Kuliah Pemrograman Lanjut Teknik Komputer FTUI (ENCE602003)
//      Afif Yudhistira - 2006522631
//      Binar Qalbu Cimuema - 2006526296
//      M. Hafiz Widyawan - 2006468762
//      Syamsul Erisandy Arief - 2006577611

//Kontribusi: 
//           Afif Yudhistira: fungsi mining
//			     Binar Qalbu Cimuema: fungsi main (dengan bantuan Syamsul Erisandy Arief)
//			     M. Hafiz Widyawan: fungsi dispPanduan dan display menu
//			     Syamsul Erisandy Arief: pengaturan akun (dengan bantuan Binar Qalbu Cimuema dan M. Hafiz Widyawan)

#include <stdlib.h>

#include <string.h>

#include <stdio.h>

#include <omp.h>

struct listAkun {
  int urutan;
  char nama[100];
  char uname[100];
  char pass[100];
  float saldo;
  struct listAkun * next;

}* head;

void dispPanduan() {
  printf("\tKryptoPal - Simulator Mining Cryptocurrency\n");
  printf("\tSelamat datang di halaman panduan program kami.\n");

  printf("\tPanduan Program\n");
  printf("\tUntuk menggunakan program ini, harap mengikuti instruksi di bawah ini:\n");
  printf("\tOpsi 1\n");
  printf("\t     Pada opsi ini, Anda akan membuat akun baru.\n");
  printf("\t     Jika membuat akun baru terpilih, data data yang diminta adalah:\n");
  printf("\t     - Nama, yaitu nama anda.\n");
  printf("\t     - Username, yaitu nama pengguna Anda.\n");
  printf("\t     - Password, yaitu kata sandi Anda\n");
  printf("\t     Setelah itu, untuk kembali ke tampilan utama, Anda dapat memasukkan angka 0.\n");
  printf("\tOpsi 2\n");
  printf("\t	 Pada opsi ini, Anda bisa mencari akun yang sudah Anda buat sebelumnya.\n");
  printf("\t     Setelah itu, untuk kembali ke tampilan utama, Anda dapat memasukkan angka 0.\n");
  printf("\tOpsi 3\n");
  printf("\t	 Pada opsi ini, Anda bisa menghapus akun yang sudah Anda buat sebelumnya.\n");
  printf("\t     Setelah itu, untuk kembali ke tampilan utama, Anda dapat memasukkan angka 0.\n");
  printf("\tOpsi 4\n");
  printf("\t     Pada opsi ini, Anda dapat mengubah username atau kata sandi akun Anda.\n");
  printf("\t     Pilih opsi 1 untuk mengubah username dan opsi 2 untuk mengubah kata sandi.\n");
  printf("\t     Anda akan diminta username atau kata sandi yang lama serta barunya.\n");
  printf("\t     Penggantian berhasil dilakukan jika muncul kata 'Berhasil' pada program.\n");
  printf("\t     Setelah itu, untuk kembali ke tampilan user, Anda dapat memasukkan angka 0.\n");
  printf("\tOpsi 5\n");
  printf("\t	 Pada opsi ini, Anda bisa melihat semua akun yang sudah Anda buat sebelumnya.\n");
  printf("\t     Setelah itu, untuk kembali ke tampilan utama, Anda dapat memasukkan angka 0.\n");
  printf("\tOpsi 6\n");
  printf("\t	 Pada opsi ini, Anda bisa melakukan mining Cryptocurrency.\n");
  printf("\t	 Anda akan diminta untuk memasukkan nomor urut Anda dan jumlah proses mining yang ingin Anda lakukan\n");
  printf("\t	 Disarankan untuk melakukan 10.000 proses ke atas.\n");
  printf("\t	 Mining berhasil dilakukan jika muncul kata 'Berhasil' pada program.\n");
  printf("\t	 PERINGATAN : Mining akan membebankan cpu hingga 100%* sampai proses mining selesai.\n");
  printf("\t     *CATATAN : Beban 100% hanya didapatkan jika penggunakan intel .\n");
  printf("\t     Setelah itu, untuk kembali ke tampilan user, Anda dapat memasukkan angka 0.\n");
  printf("\tOpsi 7\n");
  printf("\t	 Pada opsi ini, Anda bisa menyimpan data akun anda ke file.txt.\n");
  printf("\t     Setelah itu, untuk kembali ke tampilan utama, Anda dapat memasukkan angka 0.\n");
  printf("\tOpsi 8\n");
  printf("\t     Pada opsi ini, akan dimunculkan panduan dalam menjalankan program. \n");
  printf("\t     Setelah itu, untuk kembali ke tampilan utama, Anda dapat memasukkan angka 0.\n");
  printf("\tOpsi 0\n");
  printf("\t     Pada opsi ini, Anda dapat keluar dari program.\n");

}

void displayMenu() {
  printf("==========KryptoPal - Cryptocurrency Mining Simulation==========\n");
  printf("1. Buat Akun\n");
  printf("2. Pencarian Akun\n");
  printf("3. Hapus Akun\n");
  printf("4. Update Akun\n");
  printf("5. Display Akun\n");
  printf("6. Mulai Mining\n");
  printf("7. Simpan Data Akun ke File .txt\n");
  printf("8. Display Panduan\n");
  printf("0. Keluar\n");

  printf("\nSilahkan pilih opsi sesuai nomor: ");
}

void masuk(int urutan, char * nama, char * uname, char * pass, float saldo) {

  struct listAkun * insert = (struct listAkun * ) malloc(sizeof(struct listAkun));
  insert -> urutan = urutan;
  strcpy(insert -> nama, nama);
  strcpy(insert -> uname, uname);
  strcpy(insert -> pass, pass);
  insert -> saldo = saldo;
  insert -> next = NULL;

  if (head == NULL) {
    head = insert;
  } else {
    insert -> next = head;
    head = insert;
  }

}
void cari(int urutan) {
  struct listAkun * temp = head;
  while (temp != NULL) {
    if (temp -> urutan == urutan) {
      printf("Detail Akun %d\n", temp -> urutan);
      printf("Name: %s\n", temp -> nama);
      printf("Username: %s\n", temp -> uname);
      printf("Saldo: %.8f\n", temp -> saldo);
      return;
    }
    temp = temp -> next;
  }
  printf("Data akun tidak ditemukan\n");
}

void update(int urutan) {

  struct listAkun * temp = head;
  while (temp != NULL) {

    if (temp -> urutan == urutan) {
      printf("Akun %d ditemukan\n", urutan);
      printf("Enter new name: ");
      scanf("%s", temp -> nama);
      printf("Enter new username: ");
      scanf("%s", temp -> uname);
      printf("Enter new password: ");
      scanf("%s", temp -> pass);
      return;
    }
    temp = temp -> next;

  }
  printf("Data akun tidak ditemukan\n");

}

void updatesaldo(int urutan, float saldobaru) {

  struct listAkun * temp = head;
  while (temp != NULL) {

    if (temp -> urutan == urutan) {

      temp -> saldo += saldobaru;
      printf("Saldo Anda telah berhasil diperbarui!\n");

      return;
    }
    temp = temp -> next;

  }
  printf("Data akun tidak ditemukan\n");

}
void hapus(int urutan) {
  struct listAkun * temp1 = head;
  struct listAkun * temp2 = head;
  while (temp1 != NULL) {

    if (temp1 -> urutan == urutan) {

      if (temp1 == temp2) {
        head = head -> next;
        free(temp1);
      } else {
        temp2 -> next = temp1 -> next;
        free(temp1);
      }

      printf("Data telah dihapus\n");
      return;

    }
    temp2 = temp1;
    temp1 = temp1 -> next;

  }
  printf("Data akun tidak ditemukan\n");

}

void display() {
  struct listAkun * temp = head;
  while (temp != NULL) {

    printf("No. Urut %d\n", temp -> urutan);
    printf("Nama: %s\n", temp -> nama);
    printf("Username: %s\n", temp -> uname);
    printf("Password: %s\n", temp -> pass);
    printf("Saldo: %0.8f\n\n", temp -> saldo);
    temp = temp -> next;

  }
}

int mining(int limit) {
  double start, end;
  double runTime;
  start = omp_get_wtime();
  int num = 1, primes = 0;

  #pragma omp parallel for schedule(dynamic) reduction(+: primes)
  for (num = 1; num <= limit; num++) {
    int i = 2;
    while (i <= num) {
      if (num % i == 0)
        break;
      i++;
    }
    if (i == num)
      primes++;
  }

  end = omp_get_wtime();
  runTime = end - start;
  printf("Mining telah menghitung %d bilangan prima dibawah %d dalam %g detik\n", primes, limit, runTime);
}

int main() {
  head = NULL;
  int opsi;
  char nama[100];
  char uname[100];
  char pass[100];
  char address[100];
  char temp;
  int urutan = 0, limcount, urutemp;
  float saldo, saldonew, limit;

  FILE * kpw, * kpr;
  kpw = fopen("D:\\KryptoPal.txt", "a");
  kpr = fopen("D:\\KryptoPal.txt", "r");

  do {
    displayMenu();
    printf("\nMasukkan opsi: ");
    scanf("%d", & opsi);
    system("cls");
    switch (opsi) {
    case 1:
      printf("Enter name: ");
      scanf("%s", nama);
      fflush(stdin);
      printf("Enter username: ");
      scanf("%s", uname);
      printf("Enter password: ");
      scanf("%s", pass);
      saldo = 0;
      urutan += 1;
      masuk(urutan, nama, uname, pass, saldo);
      break;
    case 2:
      printf("Masukkan no. urut yang ingin dicari: ");
      scanf("%d", & urutan);
      cari(urutan);
      break;
    case 3:
      printf("Masukkan no.urut yang ingin dihapus: ");
      scanf("%d", & urutan);
      hapus(urutan);
      break;
    case 4:
      printf("Masukkan no.urut yang ingin diperbarui: ");
      scanf("%d", & urutan);
      update(urutan);
      break;
    case 5:
      display();
      break;
    case 6:
      printf("Masukkan no. urutan Anda: ");
      scanf("%d", & urutemp);
      printf("Masukkan jumlah proses yang Anda ingin lakukan (proses bil.prima): ");
      scanf("%f", & limit);
      mining(limit);
      limcount += limit;
      saldonew = limit / 200000;
      updatesaldo(urutemp, saldonew);
      break;
    case 7:
      fprintf(kpw, "\nDetail Akun %d:\nName: %s\nUsername: %s\nPassword: %s\nSaldo%d: %.8f\nEOA%d", urutan, nama, uname, pass, urutan, saldonew, urutan);
      fclose(kpw);
      printf("Data Anda telah berhasil disimpan!\n");
      break;
    case 8:
      dispPanduan();
      break;
    }

  } while (opsi != 0);
  return 0;
}
