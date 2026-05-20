---
title: Modularity
aliases:
  - Modular Programming
  - Interface and Implementation
tags:
  - cpp
  - fundamentals
  - softwareengineering
  - abstraction
  - concept
status: learning
difficulty: medium
created: 2026-05-19
updated: 2026-05-19
source: "The C++ Programming Language (4th Edition)"
---

# Modularity

---

# Ringkasan

Program C++ modern terdiri dari:
- banyak file
- banyak components
- banyak abstractions

Untuk mengelola complexity tersebut,
C++ menggunakan:
```text
modularity
```

Konsep utamanya:
- interface
- implementation
- declarations
- definitions
- separation of concerns

---

# Intuisi

Bayangkan software besar seperti:
```text
kota besar
```

Tidak mungkin semua:
- jalan
- listrik
- gedung
- sistem

dibangun dalam:
```text
1 file besar
```

Program besar harus:
- dibagi menjadi bagian kecil
- memiliki tanggung jawab jelas
- memiliki interface jelas

Itulah:
```text
modularity
```

---

# Konsep Inti

## Modularity

Modularity berarti:
```text
membagi program menjadi bagian terpisah
```

Tujuannya:
- easier maintenance
- scalability
- team collaboration
- reusable components

---

## Interface

Interface adalah:
```text
cara menggunakan suatu component
```

Interface menjelaskan:
- apa yang tersedia
- bagaimana menggunakannya

Tanpa memperlihatkan:
- detail implementation

---

## Implementation

Implementation adalah:
```text
cara internal component bekerja
```

Biasanya:
- disembunyikan
- dapat berubah tanpa memengaruhi user

---

## Declaration

Declaration:
```text
memberi tahu compiler sesuatu exists
```

Contoh:

```cpp
double sqrt(double);
```

Ini hanya:
- declaration
- bukan implementation

---

## Definition

Definition:
```text
implementasi nyata object/function
```

Contoh:

```cpp
double sqrt(double d)
{
    // implementation
}
```

---

## Class Interface

Contoh:

```cpp
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

Public members:
```text
interface
```

Private members:
```text
implementation details
```

---

## Separate Compilation

C++ memungkinkan:
- declaration di satu tempat
- definition di tempat lain

Ini disebut:
```text
separate compilation
```

---

## Library

Library adalah:
```text
collection of reusable code
```

Contoh:
```cpp
sqrt()
```

berasal dari:
```text
standard library
```

---

# Penjelasan Teknis

## Why Modularity Important?

Tanpa modularity:
- codebase menjadi chaos
- maintenance sulit
- compilation lambat
- collaboration sulit

---

## Declaration vs Definition

### Declaration

```cpp
double sqrt(double);
```

Hanya memberi tahu:
- nama function
- parameter
- return type

---

### Definition

```cpp
double sqrt(double d)
{
    return d;
}
```

Memberikan:
- actual implementation

---

## Compiler and Linker Relationship

Compiler:
- memproses declarations
- memeriksa validitas penggunaan

Linker:
- menyatukan definitions

---

## Class Member Definitions

Contoh:

```cpp
int Vector::size()
{
    return sz;
}
```

Syntax:

```cpp
Vector::
```

disebut:
```text
scope resolution operator
```

Artinya:
- function milik class `Vector`

---

## Encapsulation Through Modularity

Dengan modularity:
- implementation dapat berubah
- interface tetap sama

Ini sangat penting untuk:
- large-scale software
- API stability

---

## Standard Library Philosophy

Standard library bukan:
```text
magic compiler feature
```

Tetapi:
```text
ordinary C++ code
```

yang kebetulan:
- reusable
- standardized
- tersedia untuk semua programmer

---

# Contoh Kode C++

## Function Declaration

```cpp
double sqrt(double);
```

---

## Function Definition

```cpp
double sqrt(double d)
{
    return d;
}
```

---

## Class Declaration

```cpp
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

## Member Function Definition

```cpp
int Vector::size()
{
    return sz;
}
```

---

# Complexity

| Operation | Complexity |
|---|---|
| function call | O(1) |
| member access | O(1) |
| separate compilation | improves scalability |

---

# Istilah Penting

| Term | Meaning |
|---|---|
| modularity | membagi program menjadi bagian kecil |
| interface | cara menggunakan component |
| implementation | detail internal component |
| declaration | pemberitahuan existence |
| definition | implementasi nyata |
| compilation unit | file yang dikompilasi |
| library | reusable collection of code |

---

# Pitfall

## Mixing Interface and Implementation

Contoh buruk:
- semua code dalam satu file besar
- implementation exposed everywhere

---

## Overexposing Private Details

Jika implementation:
- terlalu terbuka
- tightly coupled

maka:
- sulit maintenance
- sulit refactor

---

## Confusing Declaration and Definition

Salah asumsi:

```cpp
double sqrt(double);
```

sudah memiliki implementation.

Padahal:
```text
itu hanya declaration
```

---

## Duplicated Definitions

Jika definition muncul:
- lebih dari sekali

dapat menyebabkan:
```text
linker errors
```

---

# Best Practice

## Separate Interface and Implementation

GOOD:
- header files untuk declarations
- source files untuk definitions

---

## Keep Interfaces Small

Interface sebaiknya:
- jelas
- minimal
- stable

---

## Hide Implementation Details

Gunakan:
```cpp
private:
```

untuk representation internal.

---

## Use Libraries

Jangan reinvent:
- vector
- string
- algorithms

Gunakan STL.

---

# Related Concepts

- [[CompilationModel]]
- [[Classes]]
- [[Encapsulation]]
- [[HeaderFiles]]
- [[SeparateCompilation]]
- [[Libraries]]
- [[ScopeResolutionOperator]]
- [[SoftwareArchitecture]]

---

# Key Takeaways

- Modularity membagi software menjadi bagian kecil
- Interface dan implementation harus dipisahkan
- Declaration berbeda dengan definition
- Class membantu encapsulation
- Separate compilation penting untuk software besar
- Standard library hanyalah reusable C++ code

---

# Summary

Modularity adalah fondasi software engineering modern di C++.

Konsep ini memungkinkan:
- scalable systems
- maintainable codebases
- reusable abstractions
- clean architecture

Tanpa modularity,
program besar akan:
- sulit dipahami
- sulit dikembangkan
- sulit dipelihara.