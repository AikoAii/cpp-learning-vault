---
title: Pointers, Arrays, and Loops
aliases:
  - Pointers and Arrays
  - Range Based Loops
tags:
  - cpp
  - fundamentals
  - memory
  - concept
status: learning
difficulty: medium
created: 2026-05-19
updated: 2026-05-19
source: "The C++ Programming Language (4th Edition)"
---

# Pointers, Arrays, and Loops

---

# Ringkasan

Section ini memperkenalkan:
- arrays
- pointers
- references
- loops
- range-based loops
- pointer arithmetic
- `nullptr`

Konsep-konsep ini adalah fondasi:
- memory manipulation
- low-level programming
- STL
- iterators
- modern C++

---

# Intuisi

Pointer dapat dibayangkan sebagai:

```text
alamat menuju object di memory
```

Sedangkan array adalah:

```text
sekumpulan object berurutan di memory
```

Loop digunakan untuk:
- traversal
- iteration
- processing sequence

Hubungan ketiganya sangat erat:
- pointer bisa berjalan di array
- loop bisa mengakses array
- references mempermudah akses object

---

# Konsep Inti

## Array

Contoh:

```cpp
char v[6];
```

Artinya:
- array berisi 6 elemen `char`
- index dimulai dari `0`

Elemen:
```text
v[0] sampai v[5]
```

---

## Array Indexing

C++ menggunakan:
```text
zero-based indexing
```

Artinya:
- elemen pertama index `0`
- elemen terakhir `size - 1`

---

## Pointer

Contoh:

```cpp
char* p;
```

Artinya:
```text
pointer ke char
```

Pointer menyimpan:
- address memory
- lokasi object

---

## Address Operator

Operator:

```cpp
&
```

berarti:
```text
address of
```

Contoh:

```cpp
&p
```

menghasilkan:
- address variable `p`

---

## Dereference Operator

Operator:

```cpp
*
```

berarti:
```text
contents of pointer
```

Contoh:

```cpp
*p
```

berarti:
- object yang ditunjuk pointer

---

## Pointer Initialization

Contoh:

```cpp
char* p = &v[3];
```

Artinya:
- `p` menunjuk elemen ke-4 array

Karena:
```text
index dimulai dari 0
```

---

## Reference

Contoh:

```cpp
int& r = x;
```

Reference berarti:
```text
alias ke object lain
```

Berbeda dengan pointer:
- tidak perlu dereference `*`
- tidak bisa dipindah ke object lain

---

## Declarator Operators

Dalam declaration:

| Syntax | Meaning |
|---|---|
| `T*` | pointer to T |
| `T&` | reference to T |
| `T[]` | array of T |

---

## for Loop

Contoh:

```cpp
for (auto i = 0; i != 10; ++i)
```

Loop digunakan untuk:
- repeated execution
- traversal
- iteration

---

## Range-Based for Loop

Modern C++ menyediakan:

```cpp
for (auto x : v)
```

Artinya:
```text
untuk setiap element di v
```

Lebih:
- clean
- readable
- safer

---

## Reference in Range Loop

Contoh:

```cpp
for (auto& x : v)
```

Perbedaan penting:

| Syntax | Behavior |
|---|---|
| `auto x` | copy value |
| `auto& x` | reference to original |

---

## nullptr

`nullptr` berarti:
```text
pointer tidak menunjuk object manapun
```

Contoh:

```cpp
int* p = nullptr;
```

---

## Null Pointer Check

Contoh:

```cpp
if (p == nullptr)
```

Digunakan untuk:
- safety checking
- avoiding invalid dereference

---

# Penjelasan Teknis

## Array Memory Layout

Array disimpan:
```text
contiguously in memory
```

Artinya:
- elemen bersebelahan
- memory berurutan

Ini penting untuk:
- performance
- cache locality
- pointer arithmetic

---

## Pointer Arithmetic

Contoh:

```cpp
++p;
```

Artinya:
- pointer berpindah ke elemen berikutnya

Bukan:
```text
+1 byte
```

tetapi:
```text
+ sizeof(type)
```

---

## C-Style Strings

Contoh:

```cpp
char* p
```

sering digunakan sebagai:
```text
zero-terminated character array
```

Akhir string ditandai:
```cpp
'\0'
```

---

## Dereferencing

Contoh:

```cpp
*p
```

Compiler:
- mengambil address dari pointer
- membaca object di address tersebut

Jika pointer invalid:
```text
undefined behavior
```

---

## Range-for Semantics

Contoh:

```cpp
for (auto x : v)
```

Setiap iterasi:
- value dicopy ke `x`

Sedangkan:

```cpp
for (auto& x : v)
```

- `x` mereferensikan element asli

---

# Contoh Kode C++

## Basic Array

```cpp
int numbers[5] = {1,2,3,4,5};
```

---

## Pointer Example

```cpp
int x = 10;
int* p = &x;

cout << *p;
```

---

## for Loop

```cpp
for (int i = 0; i < 5; ++i)
{
    cout << i << '\n';
}
```

---

## Range-Based Loop

```cpp
int v[] = {1,2,3,4};

for (auto x : v)
{
    cout << x << '\n';
}
```

---

## Reference Loop

```cpp
for (auto& x : v)
{
    ++x;
}
```

---

## nullptr

```cpp
int* p = nullptr;

if (p == nullptr)
{
    cout << "empty pointer\n";
}
```

---

# Complexity

| Operation | Complexity |
|---|---|
| array access | O(1) |
| pointer dereference | O(1) |
| loop traversal | O(n) |

---

# Istilah Penting

| Term | Meaning |
|---|---|
| dereference | mengakses object melalui pointer |
| address | lokasi memory |
| contiguous memory | memory berurutan |
| traversal | menjelajahi sequence |
| iteration | satu langkah loop |
| reference | alias object |
| null pointer | pointer tanpa target valid |

---

# Pitfall

## Dereferencing nullptr

Salah:

```cpp
int* p = nullptr;
cout << *p;
```

Dapat menyebabkan:
```text
undefined behavior
```

---

## Array Out of Bounds

Salah:

```cpp
int v[5];
v[10] = 1;
```

Karena:
```text
index invalid
```

---

## Forgetting Reference in Range Loop

Contoh:

```cpp
for (auto x : v)
{
    ++x;
}
```

Tidak mengubah array asli karena:
```text
x hanyalah copy
```

---

## Dangling Pointer

Pointer menunjuk memory invalid.

Ini salah satu bug paling berbahaya di C++.

---

# Best Practice

## Prefer Range-Based Loops

GOOD:

```cpp
for (auto& x : v)
```

Lebih:
- clean
- safer
- readable

---

## Initialize Pointers

GOOD:

```cpp
int* p = nullptr;
```

BAD:

```cpp
int* p;
```

---

## Check nullptr Before Dereference

Gunakan:

```cpp
if (p)
```

atau:

```cpp
if (p != nullptr)
```

---

## Prefer References When Ownership Tidak Berubah

References:
- lebih aman
- lebih readable
- lebih idiomatic modern C++

---

# Related Concepts

- [[Arrays]]
- [[Pointers]]
- [[References]]
- [[Loops]]
- [[RangeBasedFor]]
- [[Variables]]
- [[MemoryModel]]
- [[TypeSystem]]

---

# Key Takeaways

- Array menyimpan element secara berurutan di memory
- Pointer menyimpan address object
- `*` digunakan untuk dereference
- `&` digunakan untuk mengambil address
- Range-based loops lebih modern dan readable
- `nullptr` merepresentasikan empty pointer
- References adalah alias object

---

# Summary

Pointers, arrays, dan loops adalah fondasi penting C++.

Konsep ini memungkinkan:
- direct memory access
- efficient traversal
- low-level programming
- abstraction mechanisms
- STL iterator model

Memahami section ini sangat penting sebelum:
- dynamic memory
- STL containers
- iterators
- generic programming
- advanced C++.