---
title: Structures
aliases:
  - Struct
  - Data Structures
tags:
  - cpp
  - fundamentals
  - oop
  - memory
  - concept
status: learning
difficulty: medium
created: 2026-05-19
updated: 2026-05-19
source: "The C++ Programming Language (4th Edition)"
---

# Structures

---

# Ringkasan

`struct` digunakan untuk:
- mengelompokkan data
- membentuk custom types
- merepresentasikan object sederhana

Structure adalah langkah awal menuju:
- abstraction
- classes
- object-oriented programming

Section ini juga memperkenalkan:
- dynamic memory
- `new`
- member access
- references
- pointers to structs

---

# Intuisi

Struct dapat dibayangkan seperti:

```text
template object
```

yang menggabungkan beberapa data menjadi:
```text
satu kesatuan logical
```

Contoh:

Daripada:

```cpp
int size;
double* data;
```

terpisah,

kita gabungkan menjadi:

```cpp
struct Vector
{
    int sz;
    double* elem;
};
```

Sehingga:
- data lebih terorganisir
- lebih mudah dipakai
- lebih mudah dipahami

---

# Konsep Inti

## struct

`struct` adalah:
```text
user-defined type
```

yang berisi:
- data members
- representasi object

---

## Data Members

Contoh:

```cpp
struct Vector
{
    int sz;
    double* elem;
};
```

Member:
- `sz`
- `elem`

disebut:
```text
data members
```

---

## Object of Struct

Contoh:

```cpp
Vector v;
```

Artinya:
- membuat object bertipe `Vector`

---

## Representation

`Vector` direpresentasikan dengan:

| Member | Purpose |
|---|---|
| `sz` | jumlah elemen |
| `elem` | pointer ke data |

---

## Pointer Member

```cpp
double* elem;
```

berarti:
```text
pointer ke array double
```

Pointer digunakan karena:
- ukuran vector dynamic
- memory dialokasikan saat runtime

---

## Dynamic Memory Allocation

Contoh:

```cpp
v.elem = new double[s];
```

`new`:
- mengalokasikan memory
- dari heap/free store
- saat runtime

---

## Heap / Free Store

Heap adalah:
```text
dynamic memory area
```

Digunakan ketika:
- ukuran object tidak diketahui saat compile time
- object perlu hidup lebih lama

---

## Reference Parameter

Contoh:

```cpp
Vector& v
```

berarti:
```text
reference ke object Vector
```

Function dapat:
- memodifikasi object asli
- tanpa copy object

---

## Member Access Operator

### Dot Operator

```cpp
v.sz
```

Digunakan untuk:
- object langsung
- references

---

### Arrow Operator

```cpp
pv->sz
```

Digunakan untuk:
- pointer ke struct/class

---

## Array Access

```cpp
v.elem[i]
```

berarti:
- akses element array
- melalui pointer

---

# Penjelasan Teknis

## Struct Layout

Struct biasanya disimpan:
```text
contiguously in memory
```

Setiap member memiliki:
- offset memory
- alignment rules

---

## Why Use Pointers Inside Struct?

Karena:

```cpp
double* elem;
```

memungkinkan:
- dynamic size
- flexible storage
- runtime allocation

Tanpa pointer:
- ukuran harus fixed

---

## Dynamic Allocation Flow

```text
new double[s]
↓
allocate heap memory
↓
return pointer
↓
store pointer in elem
```

---

## Reference Semantics

Contoh:

```cpp
void vector_init(Vector& v, int s)
```

Tanpa reference:
- object dicopy
- perubahan tidak mempengaruhi object asli

Dengan reference:
- function bekerja langsung pada object asli

---

## Dot vs Arrow

| Syntax | Used For |
|---|---|
| `.` | object/reference |
| `->` | pointer |

---

## Encapsulation Problem

Version awal `Vector` masih:
```text
fully exposed
```

User dapat:
- mengakses data langsung
- merusak invariants

Ini alasan mengapa:
```text
classes
```

nantinya diperlukan.

---

# Contoh Kode C++

## Basic Struct

```cpp
struct Point
{
    int x;
    int y;
};
```

---

## Vector Example

```cpp
struct Vector
{
    int sz;
    double* elem;
};
```

---

## Dynamic Allocation

```cpp
Vector v;

v.elem = new double[10];
v.sz = 10;
```

---

## Access Members

```cpp
cout << v.sz;
```

---

## Pointer Access

```cpp
Vector* pv = &v;

cout << pv->sz;
```

---

## Reference Parameter

```cpp
void reset(Vector& v)
{
    v.sz = 0;
}
```

---

# Complexity

| Operation | Complexity |
|---|---|
| member access | O(1) |
| array indexing | O(1) |
| dynamic allocation | depends on allocator |

---

# Istilah Penting

| Term | Meaning |
|---|---|
| struct | user-defined type |
| member | data di dalam struct |
| heap | dynamic memory area |
| allocation | pemesanan memory |
| reference | alias object |
| encapsulation | menyembunyikan implementation detail |
| representation | cara object disimpan |

---

# Pitfall

## Uninitialized Pointer

Salah:

```cpp
Vector v;
cout << v.elem[0];
```

Karena:
```text
elem belum menunjuk memory valid
```

---

## Memory Leak

Contoh:

```cpp
v.elem = new double[10];
```

tanpa:
```cpp
delete[]
```

akan menyebabkan:
```text
memory leak
```

---

## Direct Data Exposure

Semua member `struct` default-nya:
```text
public
```

User dapat:
- memodifikasi data bebas
- merusak object state

---

## Confusing `.` and `->`

Salah:

```cpp
pv.sz
```

Jika:
```cpp
pv
```

adalah pointer.

---

# Best Practice

## Gunakan Struct untuk Simple Data Types

GOOD:
- Point
- Vector
- Record

---

## Gunakan References untuk Large Objects

Prefer:

```cpp
Vector&
```

daripada:
```cpp
Vector
```

untuk menghindari copying.

---

## Initialize Members Properly

GOOD:

```cpp
Vector v {};
```

atau gunakan constructor nanti.

---

## Prefer STL Containers

Daripada membuat vector manual:

```cpp
std::vector<double>
```

lebih aman dan modern.

---

# Related Concepts

- [[UserDefinedTypes]]
- [[Pointers]]
- [[References]]
- [[DynamicMemory]]
- [[HeapMemory]]
- [[Classes]]
- [[Encapsulation]]
- [[Vectors]]

---

# Key Takeaways

- `struct` adalah user-defined type
- Struct mengelompokkan data menjadi satu object
- Pointer memungkinkan dynamic memory
- `new` mengalokasikan memory di heap
- `.` digunakan untuk object access
- `->` digunakan untuk pointer access
- References memungkinkan modification tanpa copying

---

# Summary

Structures adalah langkah awal menuju abstraction di C++.

Struct memungkinkan programmer:
- membangun custom data types
- mengorganisasi data
- merepresentasikan object dunia nyata

Section ini juga memperkenalkan fondasi penting:
- dynamic memory
- references
- pointers
- object representation

yang nantinya menjadi dasar:
- classes
- RAII
- STL
- modern C++ abstractions.