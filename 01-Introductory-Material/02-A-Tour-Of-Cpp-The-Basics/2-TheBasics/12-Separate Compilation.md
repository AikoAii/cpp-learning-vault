---
title: Separate Compilation
aliases:
  - Header Files
  - Compilation Units
tags:
  - cpp
  - fundamentals
  - softwareengineering
  - modularity
  - concept
status: learning
difficulty: medium
created: 2026-05-19
updated: 2026-05-19
source: "The C++ Programming Language (4th Edition)"
---

# Separate Compilation

---

# Ringkasan

C++ mendukung:
```text
separate compilation
```

Artinya:
- code dibagi ke beberapa file
- tiap file dikompilasi terpisah
- interface dan implementation dipisahkan

Konsep ini sangat penting untuk:
- software besar
- modularity
- faster compilation
- team collaboration

---

# Intuisi

Bayangkan project besar seperti:
- game engine
- browser
- operating system

Mustahil semuanya berada di:
```text
1 file besar
```

Karena:
- compile terlalu lama
- maintenance sulit
- collaboration kacau

Maka program dibagi menjadi:
- modules
- components
- interfaces

dan dikompilasi:
```text
secara terpisah
```

---

# Konsep Inti

## Separate Compilation

Separate compilation berarti:
```text
setiap source file dapat dikompilasi sendiri
```

---

## Header File

Header file:
```text
berisi declarations/interface
```

Biasanya:
```text
.h
```

Contoh:

```cpp
Vector.h
```

---

## Source File

Source file:
```text
berisi definitions/implementation
```

Biasanya:
```text
.cpp
```

Contoh:

```cpp
Vector.cpp
```

---

## Interface

Interface menjelaskan:
- apa yang tersedia
- bagaimana digunakan

Tanpa memperlihatkan:
- implementation detail

---

## Implementation

Implementation berisi:
- actual code
- algorithms
- internal logic

---

## #include

Directive:

```cpp
#include "Vector.h"
```

berarti:
```text
masukkan isi file header
```

ke source file saat preprocessing.

---

## Compilation Unit

Setelah preprocessing,
setiap `.cpp` file menjadi:
```text
compilation unit
```

yang dikompilasi compiler secara independen.

---

## Reusability

Header memungkinkan:
- interface digunakan banyak file
- implementation tetap terpisah

---

# Penjelasan Teknis

## Typical File Structure

### Header File

```cpp
// Vector.h
class Vector
{
public:
    Vector(int s);

    double& operator[](int i);

    int size();

private:
    double* elem;
    int sz;
};
```

Berisi:
- declarations
- interface

---

### Source File

```cpp
// Vector.cpp
#include "Vector.h"
```

Berisi:
- function definitions
- implementation

---

### User File

```cpp
// user.cpp
#include "Vector.h"
```

Menggunakan:
- interface
- tanpa tahu implementation detail

---

## Why Include Header in .cpp?

Contoh:

```cpp
#include "Vector.h"
```

di:
```cpp
Vector.cpp
```

Tujuannya:
- memastikan declaration dan definition konsisten
- compiler dapat mendeteksi mismatch

---

## Compilation Flow

Flow sederhana:

```text
user.cpp
↓
compile
↓
user.o

Vector.cpp
↓
compile
↓
Vector.o

link
↓
executable
```

---

## Physical vs Logical Modularity

### Logical Modularity

Menggunakan:
- classes
- namespaces
- interfaces

---

### Physical Modularity

Menggunakan:
- files
- separate compilation
- libraries

---

## Library as Separate Code

Library sebenarnya hanyalah:
```text
separately compiled code
```

Contoh:
- STL
- math library
- graphics library

---

# Contoh Kode C++

## Header File

```cpp
// Vector.h

class Vector
{
public:
    Vector(int s);

    int size();

private:
    int sz;
};
```

---

## Source File

```cpp
// Vector.cpp

#include "Vector.h"

Vector::Vector(int s)
    : sz{s}
{
}

int Vector::size()
{
    return sz;
}
```

---

## User File

```cpp
// user.cpp

#include "Vector.h"

int main()
{
    Vector v(5);
}
```

---

# Complexity

| Operation | Complexity |
|---|---|
| compilation per file | depends on file size |
| linking | depends on project size |
| interface inclusion | preprocessing cost |

---

# Istilah Penting

| Term | Meaning |
|---|---|
| header file | file berisi declarations |
| source file | file berisi definitions |
| compilation unit | hasil preprocessing source file |
| interface | cara menggunakan module |
| implementation | detail internal module |
| linking | menggabungkan object files |
| module | bagian program independen |

---

# Pitfall

## Putting Definitions in Header Accidentally

Jika non-inline definitions ditaruh di header:
- multiple definitions
- linker errors

---

## Forgetting Include Guards

Tanpa protection:
```cpp
#include
```

bisa menyebabkan:
```text
duplicate declarations
```

---

## Mixing Interface and Implementation

Header sebaiknya:
- hanya declarations
- bukan full implementation

---

## Circular Includes

Contoh:

```text
A.h includes B.h
B.h includes A.h
```

Dapat menyebabkan:
```text
dependency problems
```

---

# Best Practice

## Keep Headers Clean

Header:
- interface only
- minimal dependencies

---

## Separate Declaration and Definition

GOOD:
- `.h` → declarations
- `.cpp` → definitions

---

## Include What You Use

Jangan:
```text
include berlebihan
```

Karena memperlambat compilation.

---

## Design Stable Interfaces

Interface sebaiknya:
- kecil
- jelas
- stable

---

# Related Concepts

- [[Modularity]]
- [[CompilationModel]]
- [[Classes]]
- [[HeaderFiles]]
- [[Libraries]]
- [[Linker]]
- [[Interfaces]]
- [[SoftwareArchitecture]]

---

# Key Takeaways

- C++ mendukung separate compilation
- Header files berisi declarations
- Source files berisi definitions
- Interface dan implementation dipisahkan
- Separate compilation meningkatkan modularity
- Libraries hanyalah separately compiled code

---

# Summary

Separate compilation adalah fondasi penting software engineering di C++.

Konsep ini memungkinkan:
- scalable projects
- reusable modules
- faster compilation
- better maintainability

Hampir semua project C++ modern menggunakan:
- header files
- source files
- modular architecture
- separate compilation.