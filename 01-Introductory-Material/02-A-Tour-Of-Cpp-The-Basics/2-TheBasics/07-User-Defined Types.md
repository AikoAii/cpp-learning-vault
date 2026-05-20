---
title: User-Defined Types
aliases:
  - Abstraction Mechanisms
  - Custom Types
tags:
  - cpp
  - fundamentals
  - oop
  - concept
status: learning
difficulty: medium
created: 2026-05-19
updated: 2026-05-19
source: "The C++ Programming Language (4th Edition)"
---

# User-Defined Types

---

# Ringkasan

C++ tidak hanya menyediakan:
- built-in types
- low-level operations

Tetapi juga menyediakan:
```text
abstraction mechanisms
```

yang memungkinkan programmer membuat:
- custom types
- reusable abstractions
- high-level systems

Type seperti ini disebut:
```text
user-defined types
```

Contohnya:
- classes
- structs
- enumerations

---

# Intuisi

Built-in types seperti:

```cpp
int
double
char
```

ibarat:
```text
bahan mentah
```

Sedangkan user-defined types adalah:
```text
alat atau mesin yang dibangun dari bahan tersebut
```

Contoh:

Daripada hanya memakai:
```cpp
int
```

kita bisa membuat:

```cpp
class Vector
```

yang:
- memiliki data sendiri
- memiliki operations sendiri
- memiliki rules sendiri

---

# Konsep Inti

## Built-in Types

Built-in types adalah type bawaan bahasa.

Contoh:

| Type | Description |
|---|---|
| `int` | integer |
| `double` | floating-point |
| `char` | character |
| `bool` | Boolean |

Built-in types:
- low-level
- dekat dengan hardware
- sangat efficient

---

## Limitation of Built-in Types

Built-in types tidak cukup untuk:
- GUI systems
- game engines
- databases
- networking
- scientific computing

Karena aplikasi modern membutuhkan:
- abstraction
- encapsulation
- reusable components

---

## Abstraction

Abstraction berarti:
```text
menyembunyikan detail implementasi
```

dan menyediakan:
```text
interface yang lebih mudah digunakan
```

---

## User-Defined Types

User-defined types adalah:
```text
types created by programmers
```

Dibangun menggunakan:
- built-in types
- abstraction mechanisms

---

## Classes

Class memungkinkan programmer:
- menggabungkan data
- menggabungkan behavior
- membuat custom abstractions

Contoh:

```cpp
class Vector
{
};
```

---

## Enumerations

Enumeration (`enum`) digunakan untuk:
```text
sekumpulan named constants
```

Contoh:

```cpp
enum Color
{
    red,
    green,
    blue
};
```

---

## Representation and Operations

Setiap user-defined type memiliki:
- representation
- operations
- invariants

Contoh:

```cpp
class BankAccount
```

memiliki:
- balance
- deposit()
- withdraw()

---

## High-Level Facilities

C++ sengaja:
- menyediakan low-level foundation
- membiarkan programmer membangun abstraction sendiri

Ini adalah filosofi penting C++:
```text
zero-overhead abstraction
```

---

# Penjelasan Teknis

## Why User-Defined Types Matter?

Tanpa user-defined types:
- program besar menjadi sulit
- code sulit dipelihara
- abstraction sulit dibuat

User-defined types memungkinkan:
- modularity
- scalability
- reusable systems

---

## C++ Design Philosophy

C++ tidak memaksa:
```text
high-level runtime system
```

Sebaliknya:
- programmer membangun abstraction sendiri
- abstraction tetap efficient

---

## Standard Library as Example

Sebagian besar STL adalah:
```text
user-defined types
```

Contoh:
- `std::vector`
- `std::string`
- `std::map`

Ini menunjukkan bahwa:
- abstraction C++ sangat powerful
- library besar bisa dibangun menggunakan bahasa itu sendiri

---

## Encapsulation

User-defined types membantu:
```text
encapsulation
```

Artinya:
- implementation detail disembunyikan
- user hanya memakai interface

---

## Reusability

Custom types memungkinkan:
- reusable code
- reusable abstractions
- reusable architecture

---

# Contoh Kode C++

## Simple Struct

```cpp
struct Point
{
    int x;
    int y;
};
```

---

## Simple Class

```cpp
class Rectangle
{
public:
    int width;
    int height;
};
```

---

## Enumeration

```cpp
enum Direction
{
    north,
    south,
    east,
    west
};
```

---

## Using User-Defined Type

```cpp
Point p;

p.x = 10;
p.y = 20;
```

---

# Complexity

| Operation | Complexity |
|---|---|
| member access | O(1) |
| enum comparison | O(1) |
| object construction | depends on implementation |

---

# Istilah Penting

| Term | Meaning |
|---|---|
| abstraction | menyembunyikan detail kompleks |
| encapsulation | menyatukan data dan behavior |
| interface | cara menggunakan object |
| implementation | detail internal object |
| reusable | dapat digunakan ulang |
| representation | cara object disimpan di memory |

---

# Pitfall

## Thinking Built-in Types Are Enough

Program modern hampir selalu membutuhkan:
- abstraction
- custom types
- reusable structures

---

## Poor Abstraction Design

Class buruk:
- terlalu banyak responsibility
- unclear interface
- tightly coupled

---

## Exposing Internal Data

Contoh buruk:

```cpp
class BankAccount
{
public:
    double balance;
};
```

Karena:
- data terlalu terbuka
- sulit menjaga invariants

---

## Confusing struct and class

Di C++:
- `struct`
- `class`

hampir sama.

Perbedaan utama:
- default access modifier

---

# Best Practice

## Model Real Concepts with Types

GOOD:

```cpp
class Matrix
class Image
class Player
```

Daripada:
```cpp
int data[1000];
```

---

## Keep Interfaces Simple

Class sebaiknya:
- mudah digunakan
- jelas responsibility-nya

---

## Hide Implementation Details

Gunakan:
- encapsulation
- private members
- clear interfaces

---

## Design Reusable Abstractions

Tujuan utama abstraction:
```text
reusability
```

---

# Related Concepts

- [[Classes]]
- [[Structs]]
- [[Enumerations]]
- [[Abstraction]]
- [[Encapsulation]]
- [[ObjectOrientedProgramming]]
- [[STLOverview]]
- [[Templates]]

---

# Key Takeaways

- Built-in types bersifat low-level
- User-defined types memungkinkan abstraction
- Classes dan enums adalah user-defined types
- Abstraction adalah inti modern C++
- STL sebagian besar terdiri dari user-defined types
- User-defined types memungkinkan reusable systems

---

# Summary

User-defined types adalah fondasi abstraction di C++.

Konsep ini memungkinkan programmer:
- membangun high-level systems
- membuat reusable abstractions
- menyembunyikan complexity
- mendesain software scalable

Hampir seluruh modern C++:
- STL
- frameworks
- engines
- libraries

dibangun menggunakan abstraction mechanisms ini.