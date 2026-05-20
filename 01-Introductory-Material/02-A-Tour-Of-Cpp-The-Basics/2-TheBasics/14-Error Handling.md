---
title: Error Handling
aliases:
  - Runtime Errors
  - Error Management
tags:
  - cpp
  - fundamentals
  - softwareengineering
  - abstraction
  - bug
  - concept
status: learning
difficulty: medium
created: 2026-05-19
updated: 2026-05-19
source: "The C++ Programming Language (4th Edition)"
---

# Error Handling

---

# Ringkasan

Error handling adalah proses:
- mendeteksi error
- mencegah error
- menangani error

C++ menggunakan:
- type system
- abstractions
- modularity
- libraries

untuk membantu mengurangi kesalahan program.

Ide utama Stroustrup:
```text
higher-level abstractions reduce bugs
```

---

# Intuisi

Semakin rendah level code:

```cpp
char*
int*
manual memory
```

semakin besar kemungkinan:
- bug
- invalid states
- runtime errors

Sedangkan abstraction seperti:

```cpp
std::string
std::vector
std::map
```

membantu:
- membatasi misuse
- membuat intent lebih jelas
- membantu compiler mendeteksi error

---

# Konsep Inti

## Error Handling

Error handling berarti:
```text
cara software menghadapi kondisi salah
```

Contoh:
- invalid input
- null pointer
- file tidak ditemukan
- out-of-bounds access

---

## Compile-Time Error

Error yang ditemukan:
```text
oleh compiler
```

Contoh:

```cpp
int x = "hello";
```

---

## Runtime Error

Error yang terjadi:
```text
saat program berjalan
```

Contoh:
- division by zero
- invalid memory access
- failed allocation

---

## Type System as Protection

Type system membantu:
- mencegah misuse
- memvalidasi operations
- menangkap error lebih awal

Contoh:

```cpp
std::string
```

lebih aman dibanding:
```cpp
char*
```

---

## Abstraction Reduces Errors

High-level abstractions:
- menyederhanakan code
- membatasi kemungkinan salah
- meningkatkan readability

---

## Modularity

Modularity membantu:
- mengisolasi bugs
- membatasi complexity
- mempermudah debugging

---

## Libraries

Library abstractions seperti:
- `std::vector`
- `std::map`
- `std::regex`

sudah:
- diuji
- dioptimisasi
- lebih aman

---

## Error Detection vs Error Handling

Kadang:
- error terdeteksi di satu tempat
- tetapi ditangani di tempat lain

Ini umum pada:
- modular software
- large systems
- libraries

---

# Penjelasan Teknis

## Why Low-Level Code Dangerous?

Contoh:

```cpp
char* p;
```

rawan:
- dangling pointers
- buffer overflow
- memory corruption

---

## Why High-Level Types Safer?

Contoh:

```cpp
std::vector<int>
```

memberikan:
- size management
- memory safety abstraction
- cleaner interface

---

## Compiler Assistance

Dengan type system kuat,
compiler dapat:
- menolak invalid operations
- memeriksa consistency
- mengurangi runtime failures

---

## Separation of Concerns

Pada software besar:
- detection
- reporting
- recovery

sering dipisahkan.

Contoh:
```text
library mendeteksi error
application menangani error
```

---

## Error Handling Standards

Project besar membutuhkan:
- consistent error strategy
- predictable behavior
- common conventions

---

## Abstraction and Reliability

Semakin baik abstraction:
- semakin kecil surface area bugs
- semakin mudah reasoning terhadap code

---

# Contoh Kode C++

## Compile-Time Type Safety

```cpp
int x = "hello"; // error
```

---

## Safer Container

```cpp
std::vector<int> numbers;
```

Lebih aman dibanding:
```cpp
int* data;
```

---

## Error Prevention Through Types

```cpp
std::string name = "Aiko";
```

lebih aman dibanding:
```cpp
char* name;
```

---

## Logical Validation

```cpp
if (index < vec.size())
{
    cout << vec[index];
}
```

---

# Complexity

| Operation | Complexity |
|---|---|
| compile-time checking | compiler dependent |
| runtime validation | O(1) typical |
| abstraction overhead | usually minimal |

---

# Istilah Penting

| Term | Meaning |
|---|---|
| compile-time | saat compilation |
| runtime | saat program berjalan |
| abstraction | penyederhanaan complexity |
| modularity | pemisahan program menjadi bagian kecil |
| type safety | perlindungan dari misuse type |
| runtime error | error saat execution |
| bug | kesalahan program |

---

# Pitfall

## Overusing Low-Level Code

Contoh:
- raw pointers
- manual memory
- C-style arrays

lebih rawan bug.

---

## Reinventing Standard Library

Membuat:
```cpp
custom vector
custom string
```

tanpa alasan kuat dapat:
- meningkatkan bugs
- mengurangi reliability

---

## Ignoring Type System

Contoh:
- casts berlebihan
- unsafe conversions
- weak abstractions

---

## Delayed Error Detection

Semakin lambat error ditemukan:
- semakin mahal debugging
- semakin sulit maintenance

---

# Best Practice

## Prefer High-Level Abstractions

GOOD:
- `std::vector`
- `std::string`
- `std::map`

---

## Let the Compiler Help You

Gunakan:
- strong typing
- const correctness
- abstractions

---

## Design Safe Interfaces

Interface sebaiknya:
- jelas
- sulit disalahgunakan
- type-safe

---

## Reuse Tested Libraries

Jangan reinvent:
- containers
- algorithms
- parsers

kecuali benar-benar diperlukan.

---

# Related Concepts

- [[TypeSystem]]
- [[UserDefinedTypes]]
- [[Classes]]
- [[Modularity]]
- [[Abstraction]]
- [[Libraries]]
- [[CompileTimeErrors]]
- [[RuntimeErrors]]

---

# Key Takeaways

- Error handling jauh lebih besar daripada sekadar syntax
- Type system membantu mencegah banyak error
- High-level abstractions mengurangi bug
- Libraries membantu reliability
- Modularity mempermudah error isolation
- Compiler adalah alat penting untuk error detection

---

# Summary

Error handling di C++ bukan hanya tentang:
- exceptions
- error codes

Tetapi juga tentang:
- abstraction design
- type safety
- modularity
- software architecture

Modern C++ berusaha:
```text
mencegah error sejak awal
```

melalui:
- strong typing
- abstractions
- reusable libraries
- safer interfaces.