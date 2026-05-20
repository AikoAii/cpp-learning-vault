---
title: Classes
aliases:
  - Class
  - Encapsulation
tags:
  - cpp
  - fundamentals
  - oop
  - abstraction
  - concept
status: learning
difficulty: medium
created: 2026-05-19
updated: 2026-05-19
source: "The C++ Programming Language (4th Edition)"
---

# Classes

---

# Ringkasan

`class` adalah mekanisme utama C++ untuk:
- abstraction
- encapsulation
- data hiding
- interface design

Class menggabungkan:
- data
- operations

menjadi:
```text
single logical type
```

Section ini memperkenalkan:
- public/private access
- constructors
- encapsulation
- member functions
- operator overloading
- abstraction design

---

# Intuisi

Struct biasa:

```cpp
struct Vector
{
    double* elem;
    int sz;
};
```

masih:
```text
fully exposed
```

User bisa:
- mengubah data bebas
- merusak object state
- memakai object secara salah

Class memperbaiki masalah itu dengan:
```text
hiding implementation details
```

dan hanya memperlihatkan:
```text
safe public interface
```

---

# Konsep Inti

## Class

Class adalah:
```text
user-defined type
```

yang memiliki:
- data members
- member functions
- access control

---

## Encapsulation

Encapsulation berarti:
- data dan behavior digabung
- implementation disembunyikan
- akses dikontrol melalui interface

Ini salah satu konsep inti:
```text
object-oriented programming
```

---

## Public Interface

Bagian:

```cpp
public:
```

dapat diakses:
- user class
- code luar

Interface mendefinisikan:
```text
cara menggunakan object
```

---

## Private Members

Bagian:

```cpp
private:
```

hanya dapat diakses:
- member functions class sendiri

Tujuan:
- melindungi representation
- menjaga invariants
- menghindari misuse

---

## Representation

Pada class `Vector`:

```cpp
double* elem;
int sz;
```

adalah:
```text
internal representation
```

User tidak perlu tahu:
- bagaimana data disimpan
- bagaimana memory diatur

---

## Constructor

Constructor adalah:
```text
special function untuk membuat object
```

Namanya sama dengan class:

```cpp
Vector(int s)
```

---

## Constructor Initialization List

Contoh:

```cpp
: elem{new double[s]}, sz{s}
```

disebut:
```text
member initializer list
```

Digunakan untuk:
- initialize members
- sebelum body constructor berjalan

---

## Member Function

Contoh:

```cpp
int size()
{
    return sz;
}
```

Member function:
- bekerja pada object class
- memiliki akses ke private members

---

## operator[]

Contoh:

```cpp
double& operator[](int i)
```

disebut:
```text
operator overloading
```

Membuat object dapat digunakan seperti array:

```cpp
v[i]
```

---

## Reference Return Type

```cpp
double&
```

berarti:
```text
return reference ke element asli
```

Bukan copy.

---

## Handle Pattern

Object `Vector` sebenarnya hanyalah:

| Member | Purpose |
|---|---|
| `elem` | pointer ke data |
| `sz` | jumlah elemen |

Sedangkan data sebenarnya berada:
```text
di heap/free store
```

Ini disebut:
```text
handle-body design
```

---

# Penjelasan Teknis

## Why Classes Matter?

Tanpa classes:
- data terlalu exposed
- sulit menjaga consistency
- sulit membuat abstraction besar

Class memungkinkan:
- modular design
- reusable systems
- scalable architecture

---

## Interface vs Implementation

C++ memisahkan:
- interface
- implementation

Interface:
```cpp
public:
```

Implementation:
```cpp
private:
```

Ini sangat penting untuk:
- maintainability
- API stability
- abstraction

---

## Dynamic Memory Inside Class

```cpp
new double[s]
```

mengalokasikan memory:
- saat runtime
- sesuai ukuran object

Karena:
- ukuran vector bisa berubah
- compile-time size tidak diketahui

---

## Why Constructor Important?

Tanpa constructor:
- object bisa uninitialized
- representation invalid

Constructor menjamin:
```text
object selalu valid setelah dibuat
```

---

## Operator Overloading

`operator[]` memungkinkan:

```cpp
v[i]
```

padahal sebenarnya:

```cpp
v.operator[](i)
```

Ini membuat syntax:
- natural
- readable
- mirip built-in types

---

## Missing Destructor

Code ini belum memiliki:
```cpp
destructor
```

Akibatnya:
```text
memory leak
```

karena:
```cpp
new
```

belum dipasangkan dengan:
```cpp
delete[]
```

---

# Contoh Kode C++

## Basic Class

```cpp
class Point
{
public:
    int x;
    int y;
};
```

---

## Vector Class

```cpp
class Vector
{
public:
    Vector(int s)
        : elem{new double[s]}, sz{s}
    {
    }

    double& operator[](int i)
    {
        return elem[i];
    }

    int size()
    {
        return sz;
    }

private:
    double* elem;
    int sz;
};
```

---

## Creating Object

```cpp
Vector v(5);
```

---

## Accessing Elements

```cpp
v[0] = 10.5;
```

---

## Using Member Function

```cpp
cout << v.size();
```

---

# Complexity

| Operation | Complexity |
|---|---|
| member access | O(1) |
| operator[] | O(1) |
| constructor allocation | O(n) |
| size() | O(1) |

---

# Istilah Penting

| Term | Meaning |
|---|---|
| encapsulation | menyembunyikan implementation |
| interface | cara menggunakan object |
| representation | internal data layout |
| constructor | function pembuat object |
| member function | function milik class |
| operator overloading | mendefinisikan behavior operator |
| invariant | kondisi object yang harus selalu valid |

---

# Pitfall

## Public Data Exposure

Contoh buruk:

```cpp
public:
    double* elem;
```

Karena:
- user bisa merusak object
- invariant sulit dijaga

---

## Memory Leak

Code ini:

```cpp
new double[s]
```

belum memiliki:
```cpp
delete[]
```

---

## Returning Copies Accidentally

Jika:

```cpp
double operator[](int i)
```

maka:
- return copy
- tidak bisa modify element langsung

---

## Missing Bounds Checking

```cpp
v[100]
```

masih bisa terjadi.

Belum ada:
```text
error handling
```

---

# Best Practice

## Hide Representation

Gunakan:
```cpp
private:
```

untuk implementation details.

---

## Design Clear Interfaces

User sebaiknya:
- tidak tahu internal implementation
- hanya memakai public functions

---

## Use Constructors

Pastikan object:
```text
selalu valid setelah dibuat
```

---

## Prefer STL Containers

Di code modern:
```cpp
std::vector
```

lebih aman dibanding implementasi manual.

---

# Related Concepts

- [[Structures]]
- [[Encapsulation]]
- [[Constructors]]
- [[DynamicMemory]]
- [[OperatorOverloading]]
- [[References]]
- [[ObjectOrientedProgramming]]
- [[Vectors]]

---

# Key Takeaways

- Class menyediakan encapsulation
- Public members membentuk interface
- Private members menyimpan implementation
- Constructor memastikan object valid
- operator[] memungkinkan array-like syntax
- Class membantu abstraction dan scalability

---

# Summary

Classes adalah fondasi abstraction modern C++.

Class memungkinkan programmer:
- menyembunyikan complexity
- menjaga object invariants
- membangun reusable systems
- mendesain scalable software

Konsep ini menjadi dasar:
- STL
- object-oriented programming
- RAII
- generic programming
- modern software engineering.