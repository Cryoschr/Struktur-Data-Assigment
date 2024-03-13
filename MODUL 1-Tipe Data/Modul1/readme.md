# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Irshad Benaya Fardeca</p>

# Dasar Teori

Tipe data adalah adalah sebuah pengklasifikasian data berdasarkan jenis data. Tipe data digunakan agar kompiler tahu bagaimana data akan digunakan. Tipe data yang akan dipelajari, yaitu:
1. Tipe data Primitif
2. Tipe data Abstrak
3. Tipe data Koleksi

## Tipe Data Primiitf
Tipe data primitif adalah tipe data yang telah ditentukan oleh sistem. Banyak bahasa pemrograman dapat menyediakan tipe data primitif, tetapi jumlah bit yang dialokasikan untuk setiap bit berbeda-beda tergantung pada bahasa pemrograman, compiler, dan sistem operasi yang digunakan. Contoh tipe data primitif
adalah :
a. Int : adalah tipe data yang digunakan untuk menyimpan bilangan bulat
seperti 12, 1, 4, dan sebagainya.
b. Float : tipe data yang digunakan untuk menyimpan bilangan desimal
seperti 1.5, 2.1, 3.14, dan sebagainya.
c. Char : berfungsi untuk menyimpan data berupa sebuah huruf. Biasanya
digunakan untuk simbol seperti A, B, C dan seterusnya
d. Boolean : tipe data ini digunakan untuk menyimpan nilai boolean yang
hanya memiliki dua nilai yaitu true dan false.

## Tipe Data Abstrak
Programer menciptakan tipe data abstrak, juga dikenal sebagai tipe data abstrak (ADT). Tipe data abstrak dapat berisi lebih dari satu tipe data, sehingga nilainya dapat beragam. Pada bahasa C++, fitur Class adalah fitur Program Orientasi Objek (OPP), sedangkan pada bahasa C, fitur data struktur struktur berfungsi untuk membungkus tipe data di dalamnya sebagai anggota. Menurut learn.microsoft.com, perbedaan antara Struct dan Class terletak pada cara mereka diakses secara default: Struct bersifat publik sedangkan Class bersifat privat.

## Tipe Data Koleksi
Tipe data koleksi, juga dikenal sebagai "tipe data koleksi", digunakan untuk mengelompokkan dan menyimpan sejumlah nilai atau objek secara bersamaan. Tipe data koleksi memungkinkan Anda menyimpan, mengelola, dan mengakses sejumlah besar data secara terstruktur. Ada beberapa tipe data koleksi yang umum
digunakan dalam pemrograman, antara lain adalah:
a. Array: Array adalah struktur data statis yang menyimpan elemen tipe data yang sama dan dapat diakses dengan menggunakan indeks. Array memiliki ukuran tetap yang ditetapkan saat deklarasi.
b. Vector: Jika bentuk std::vector digunakan dalam C/C++, vector digunakan oleh Standard Template Library (STL). Vector, seperti array, memiliki kemampuan untuk menyimpan data dalam bentuk elemen, dan alokasi memorinya dilakukan otomatis dan bersebelahan. Pada C/C++, vektor juga memiliki fitur pelengkap seperti akses elemen, iterator, kapasitas, dan modifikasi.
c. Map: Map menyerupai array tetapi memiliki index yang memungkinkan tipe data selain integer. Indeks ini disebut "key" dan digunakan pada std::map. Tree Self-Balancing digunakan, terutama Tree Red-Black.[1]

## Guided 
### 1. Tipe Data Primitif
![Screenshot 2024-03-13 195838](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/ed78b313-4ec7-4d3d-872b-93375c8acecb)
#### Output:
![Screenshot 2024-03-13 200005](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/cb78ac7c-1f02-4e21-9df3-0dcbaa548705)
Program ini berfungsi seperti kalkulator biasa. Pertama, program meminta pengguna untuk memasukkan operator (+, -, *, atau /) diikuti oleh dua angka. Kemudian, menggunakan pernyataan switch, program memeriksa operator yang dimasukkan dan melakukan operasi aritmatika yang sesuai (penjumlahan, pengurangan, perkalian, atau pembagian) pada dua angka yang diberikan oleh pengguna. Jika pengguna memasukkan operator yang tidak valid selain yang didukung, program akan menampilkan hasilnya. 

### 2. Tipe Data Abstrak
![Screenshot 2024-03-13 200127](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/5507d3d7-e4b3-4a54-80e0-d04da49421cc)
#### Output:
![Screenshot 2024-03-13 200207](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/b384c6e6-cf9b-46f6-b4b4-14e107a6799e)
Program ini menunjukkan bagaimana struct dapat digunakan untuk menyimpan data siswa. Program menciptakan struct "Mahasiswa" dengan tiga anggota: nama, alamat, dan usia. Kemudian, program membuat dua variabel "Mahasiswa", yang disebut mhs1 dan mhs2, dan mengisi nilai-nilai anggota struct untuk masing-masing. Terakhir, program mencetak nilai-nilai anggota struct untuk mhs1 dan mhs2.

### 3. Tipe Data Koleksi
![Screenshot 2024-03-13 200235](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/b3fd81df-8fbf-4add-8a18-38c636acaa17)
#### Output:
![Screenshot 2024-03-13 200308](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/2bb029c8-7831-40c3-a74c-d9bc3eb98fff)
Program ini menunjukkan cara menyimpan dan mencetak lima nilai integer dengan array.


## Unguided 
### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!
![Screenshot 2024-03-13 201223](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/aff30260-17fd-45ca-964f-c9f6dbe37507)
#### Output:
![Screenshot 2024-03-13 201311](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/27c0b3c0-82b5-4912-864f-67071346b61f)
Program ini dapat menghitung luas dan keliling lingkaran. Pertama, program mendefinisikan dua fungsi, yaitu luas dan keliling. Fungsi luas menerima jari-jari lingkaran sebagai input dan mengembalikan nilai luas lingkaran. Fungsi keliling juga menerima jari-jari lingkaran sebagai input dan mengembalikan nilai keliling lingkaran. Dalam fungsi main, program meminta pengguna untuk memasukkan jari-jari lingkaran. Kemudian, program memanggil fungsi luas dan keliling dengan jari-jari lingkaran Selanjutnya, hasil dari kedua fungsi tersebut dicetak ke layar.
### Kesimpulan
Tipe data primitif adalah tipe data dasar yang disediakan oleh bahasa pemrograman. Setiap bahasa pemrograman memiliki set tipe data primitifnya sendiri, dengan kemungkinan perbedaan dalam jumlah bit yang dialokasikan untuk setiap tipe. Contoh tipe data primitif:
1. Int: Untuk menyimpan bilangan bulat (12, 1, 4, dll.)
2. Float: Untuk menyimpan bilangan desimal (1.5, 2.1, 3.14, dll.)
3. Char: Untuk menyimpan satu huruf (A, B, C, dll.)
4. Boolean: Untuk menyimpan nilai true atau false

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya
### Class  
![Screenshot 2024-03-13 201447](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/1128b966-f496-488f-b19b-56cc9dd3f57a)
#### Output:
![Screenshot 2024-03-13 201516](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/74fb0666-eed7-47ce-b0f2-3cb8dc9aa649)
Dalam program, sebuah class bernama Murid dibuat. Class ini memiliki tiga variabel: nama, usia, dan nim. Selain itu, sebuah prosedur bernama cetak() digunakan untuk mencetak nilai dari ketiga variabel tersebut. Di dalam fungsi main(), sebuah objek baru dari class Murid dibuat dan diberi nama murid. Nilai dari variabel nama, usia, dan nim dari objek murid kemudian diubah. Terakhir, prosedur cetak() dari objek murid dipanggil untuk mencetak nilai dari ketiga variabel
### Fungsi
Class adalah salah satu dari konsep OOP yang digunakan untuk membungkus data abstraksi procedural sebagai deskripsi tergeneralisir atau rancangan dari sebuah object untuk mendefinisikan atau menggambarkan isi dan tingkah laku sebagai entitas dari object.
Keuntungan Class:
1. Class membantu dalam membangun program yang lebih terstruktur dan mudah dimengerti.
2. Class dapat menampung member variabel, function, constructor, destructor, overloading, dan lain-lain.
3. Selain definisi class, kita juga bisa membuat relasi seperti inheritance dan overriding[3]
### Struct
![Screenshot 2024-03-13 201723](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/3aa27c19-6ebb-4fa3-a7c7-4e2b0ecaeefb)
#### Output:
![Screenshot 2024-03-13 201755](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/70a6d0c6-bc4d-4cd0-bd09-f26212b10132)
Program ini mengajarkan cara menggunakan dan membuat struct (struktur) dalam bahasa C++. Pertama, program mendeklarasikan struct bernama motor. Struktur ini memiliki dua variabel anggota, atau variabel anggota, yaitu merek dan jenis. Variabel ini bertipe string, yang berarti mereka memiliki kemampuan untuk menyimpan teks. Program kemudian menghasilkan item baru dari struct motor. Setelah Anda mendaftarkan nama motor, program mengisi variabel merek dan jenis pada objek motor, seperti "Honda" untuk merek dan "Beat" untuk jenis. Terakhir, program mencetak nilai variabel merek dan jenis pada objek motor ke layar.
## Fungsi
Structure adalah kumpulan dari beberapa variabel dalam satu nama. Variabel-variabel yang ada di dalam structure dapat memiliki tipe data yang sama atau berbeda. Dengan menggunakan structure, kita dapat membentuk tipe data baru yang merupakan gabungan dari beberapa variabel.
Keuntungan Struct:
1. Struct membantu dalam membangun program yang lebih terstruktur dan mudah dimengerti.
2. Dapat menampung member variabel, function, constructor, destructor, dan lain-lain.
3. Dapat digunakan untuk merepresentasikan data yang terkait, seperti data mahasiswa, data kendaraan, dan sebagainya.
Jadi, struct memungkinkan kita untuk mengelompokkan variabel-variabel terkait menjadi satu kesatuan, sehingga mempermudah pengelolaan data dalam program.[4]

### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map.
![Screenshot 2024-03-13 201836](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/8986318c-73f1-434f-8bc4-18bcac9a7941)
#### Output:
![Screenshot 2024-03-13 201857](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/291307ba-c309-488a-ad04-ce714b1891d7)
Untuk menyimpan data nama dan usia individu, program ini menggunakan struktur data map. Pertama, program membuat map kosong bernama u, dan kemudian menambahkan tiga elemen ke map, masing-masing berisi key (nama) dan value (usia). Sebuah string dan nilainya adalah integer. Untuk iterasi melalui semua elemen map, program menggunakan loop untuk menampilkan isi map setelah elemen ditambahkan. Di dalam loop, program mengambil kunci dan nilai dari setiap elemen dan mencetaknya ke layar.
### Perbedaan Array dan Map
Array adalah struktur data yang digunakan untuk menyimpan sekumpulan elemen dengan tipe data yang sama. Elemen-elemen dalam array disimpan pada lokasi memori yang berdekatan, sehingga memudahkan akses dan manipulasi data. Setiap elemen dalam array diakses menggunakan indeks, yaitu bilangan bulat yang menunjukkan posisi elemen dalam array. Indeks biasanya dimulai dari 0, sehingga elemen pertama dalam array memiliki indeks 0, elemen kedua memiliki indeks 1, dan seterusnya.
Map, adalah struktur data yang menyimpan elemen dalam bentuk pasangan kunci-nilai. Setiap elemen memiliki nilai kunci yang unik dan nilai yang terkait dengannya. Hal ini memungkinkan akses cepat ke nilai berdasarkan kuncinya, mirip dengan kamus yang menghubungkan kata dengan definisinya. Salah satu karakteristik penting dari map adalah tidak ada dua elemen yang dapat memiliki kunci yang sama. Ini berarti bahwa setiap kunci hanya dapat dikaitkan dengan satu nilai, mencegah duplikasi dan meningkatkan efisiensi dalam menemukan data.
Jadi,  Array digunakan untuk menyimpan elemen dengan indeks berurutan, sedangkan map digunakan untuk menghubungkan kunci dengan nilai-nilai terkait.[2]

## Kesimpulan
Tipe data yang dipelajari kali ini ada 3, yaitu tipe data primitif, tipe data abstarak dan tipe data koleksi. Untuk tipe data primitif sendiri terdapat tipe data int, float, char, boolean. Tipe data abstrak terdiri dari tipe data class, struct dan tipe data koleksi yang umum diganakan adlah array, vector dan map. Semua tipe data yang telah disebutkan sebelumnya memiliki peran masing-masing dalam pemrograman.

## Referensi
##### [1]Modul 1-Tipe Data
##### [2]GeeksForGeeks dapat diakses dari https://www.geeksforgeeks.org/difference-between-array-and-map/
##### [3]Belajar c++ dapat diakses dari https://www.belajarcpp.com/tutorial/cpp/class/
##### [4]Belajar c++ dapat diakses dari https://www.belajarcpp.com/tutorial/c/structure/
