### Cara Kompilasi:

Command untuk membuat `fungsi.o`:
```bash
g++ -c fungsi.c -o fungsi.o
```
*Bendera `-c` memberi tahu compiler untuk hanya mengompilasi sampai tahap object file, jangan di-link dulu.*

Command untuk membuat`main-o`:
```bash
g++ -c main.c -o main.o
```

Sekarang gunakan `linker` untuk membuar `executable` bermama `program`:
```bash
g++ fungsi.o main.o -o program
```

jalankan program:
```bash
./program
```

*Output akan menampilkan  `Hasil petambahan`.*