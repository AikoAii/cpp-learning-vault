---
title: Compilation Model
aliases:
  - C++ Compilation Pipeline
  - Build Process
tags:
  - cpp
  - fundamentals
  - concept
  - compilation
status: learning
difficulty: easy
created: 2026-05-19
updated: 2026-05-19
source: The C++ Programming Language (4th Edition)
---
# Compilation Model

---

# Ringkasan

C++ adalah bahasa compiled.

Source code tidak dijalankan langsung, tetapi diproses melalui:
1. compiler
2. object files
3. linker
4. executable

Model ini memungkinkan:
- performa tinggi
- optimisasi mendalam
- kontrol low-level
- scalable software systems

---

# Intuisi

Program C++ dapat dibayangkan seperti proses produksi:

```text
Source Code
↓
Compiler
↓
Object Files
↓
Linker
↓
Executable Program
```

Compiler menerjemahkan source code menjadi machine-oriented object files.

Linker kemudian menggabungkan seluruh object files menjadi executable final.

---

# Konsep Inti

## Compilation Pipeline

Alur dasar build process:

```text
source file
↓ compile
object file
↓ link
executable
```

Untuk program besar:

```text
source file 1 ─┐
               ├─ compile ─→ object files ─→ linker ─→ executable
source file 2 ─┘
```

---

## Compiler

Compiler bertugas:
- membaca source code
- melakukan type checking
- melakukan optimisasi
- menghasilkan object file

Contoh compiler:
- GCC
- Clang
- MSVC

---

## Object File

Object file berisi:
- machine code parsial
- symbol table
- relocation information

Object file belum bisa dijalankan langsung.

Biasanya berekstensi:
- `.o`
- `.obj`

---

## Linker

Linker bertugas:
- menggabungkan object files
- menyelesaikan symbol references
- menghasilkan executable final

Tanpa linker:
- fungsi antar file tidak dapat terhubung

---

## Executable Program

Executable:
- spesifik terhadap platform
- bergantung pada architecture
- bergantung pada operating system

Contoh:
- executable Linux tidak otomatis berjalan di Windows
- executable ARM berbeda dengan x86

---

## Source Code Portability

Yang biasanya portable adalah:
```text
source code
```

Bukan:
```text
compiled executable
```

Portability berarti:
source code yang sama dapat:
- dikompilasi
- dijalankan
- di berbagai platform

dengan sedikit atau tanpa perubahan.

---

## Core Language vs Standard Library

ISO C++ mendefinisikan dua komponen utama:

| Component | Example |
|---|---|
| Core Language | `int`, `for`, `while` |
| Standard Library | `vector`, `map`, `getline` |

---

## Standard Library

Standard library:
- ditulis menggunakan C++
- bukan bagian magic dari compiler
- menggunakan abstraction C++ itu sendiri

Ini menunjukkan bahwa:
- C++ cukup expressive
- C++ cukup efficient
- C++ mampu membangun sistem kompleks menggunakan dirinya sendiri

---

## Static Typing

C++ adalah:
```text
statically typed language
```

Artinya:
- type harus diketahui compiler
- sebelum program dijalankan

Contoh:

```cpp
int x = 10;
```

Compiler mengetahui:
- `x` bertipe `int`
- operasi valid terhadap `x`

---

## Type Determines Operations

Type menentukan:
- operasi yang valid
- representasi memory
- behavior object

Contoh:

```cpp
int x = 10;
x + 5;
```

Valid karena:
```cpp
int
```

mendukung arithmetic operations.

---

# Penjelasan Teknis

## Compilation Stages

Secara sederhana:

| Stage | Purpose |
|---|---|
| Preprocessing | menangani `#include`, macros |
| Compilation | menerjemahkan ke assembly |
| Assembly | menghasilkan object file |
| Linking | menggabungkan seluruh object file |

---

## Why Separate Compilation Matters?

Separate compilation memungkinkan:
- scalable software
- modular codebase
- faster incremental builds
- team collaboration

Ini sangat penting untuk:
- software engineering
- large systems
- libraries

---

# Contoh Kode C++

## Simple Program

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello, World!\n";
}
```

Build process:

```text
hello.cpp
↓ compile
hello.o
↓ link
hello executable
```

---

# Complexity

| Operation | Complexity |
|---|---|
| Compilation | depends on code size |
| Linking | depends on symbols/modules |

---

# Pitfall

## Menganggap C++ Interpreted

C++ bukan:
- Python
- JavaScript

C++ memerlukan compilation pipeline.

---

## Tidak Memahami Linker Errors

Kesalahan umum:

```text
undefined reference
```

Biasanya terjadi karena:
- implementation missing
- object file tidak ter-link
- symbol tidak ditemukan

---

## Menganggap STL Built-in Compiler Magic

STL sebagian besar hanyalah:
```text
ordinary C++ code
```

Ini penting untuk memahami:
- abstraction
- generic programming
- library design

---

# Best Practice

## Gunakan Separate Compilation

Pisahkan:
- declarations
- implementations
- modules

untuk:
- maintainability
- scalability

---

## Pahami Build Pipeline

Minimal pahami:
- compiler
- object file
- linker

Karena error C++ sering berasal dari:
- compilation stage
- linking stage

---

## Gunakan Standard Library

Prioritaskan:
- `std::vector`
- `std::string`
- `std::map`

daripada membangun ulang struktur dasar.

---

# Related Concepts

- [[SourceFiles]]
- [[SeparateCompilation]]
- [[HeaderFiles]]
- [[Linker]]
- [[BuildProcess]]
- [[StaticTyping]]
- [[TypeSystem]]
- [[StandardLibrary]]

---

# Key Takeaways

- C++ menggunakan compilation pipeline
- Compiler menghasilkan object files
- Linker menghasilkan executable
- Executable bersifat platform-specific
- Source code portability lebih penting daripada executable portability
- C++ terdiri dari core language dan standard library
- C++ adalah statically typed language

---

# Summary

Compilation model adalah fondasi cara kerja C++.

Memahami:
- compiler
- linker
- object files
- static typing

sangat penting untuk:
- debugging
- software engineering
- build systems
- advanced C++ understanding.