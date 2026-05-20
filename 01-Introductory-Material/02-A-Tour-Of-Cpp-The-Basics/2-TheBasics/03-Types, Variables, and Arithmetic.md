---
title: Types, Variables, and Arithmetic
aliases:
  - Variables and Types
  - Basic Types
tags:
  - cpp
  - fundamentals
  - concept
  - types
  - variables
status: learning
difficulty: easy
created: 2026-05-19
updated: 2026-05-19
source: "The C++ Programming Language (4th Edition)"
---

# Types, Variables, and Arithmetic

---

# Ringkasan

C++ adalah bahasa dengan static type system.

Setiap:
- variable
- object
- expression

memiliki type yang menentukan:
- nilai yang dapat disimpan
- operasi yang valid
- representasi memory

Section ini memperkenalkan:
- variables
- declarations
- fundamental types
- arithmetic operators
- initialization
- type conversions
- `auto`

---

# Intuisi

Type di C++ seperti:
```text
aturan penggunaan object
```

Contoh:

```cpp
int x = 10;
```

berarti:
- `x` adalah integer
- `x` dapat melakukan arithmetic integer
- compiler memahami bagaimana menyimpan dan memproses `x`

Type membantu compiler:
- mengecek validitas program
- mengoptimisasi code
- mencegah kesalahan

---

# Konsep Inti

## Declaration

Declaration memperkenalkan nama ke program.

Contoh:

```cpp
int inch;
```

Artinya:
- ada variable bernama `inch`
- type-nya `int`

---

## Type

Type menentukan:
- himpunan nilai
- operasi valid
- representasi memory

Contoh:
- `int`
- `double`
- `char`
- `bool`

---

## Object

Object adalah:
```text
memory yang menyimpan value
```

---

## Value

Value adalah:
```text
bits interpreted according to a type
```

Bits yang sama bisa memiliki arti berbeda tergantung type.

---

## Variable

Variable adalah:
```text
named object
```

Contoh:

```cpp
int age = 20;
```

`age` adalah nama untuk object integer.

---

## Fundamental Types

C++ menyediakan primitive built-in types:

| Type | Description |
|---|---|
| `bool` | true / false |
| `char` | character |
| `int` | integer |
| `double` | floating-point |

---

## Hardware Mapping

Fundamental types berhubungan langsung dengan hardware.

Contoh:
- `char` biasanya 1 byte
- `int` sering 4 byte
- ukuran type bergantung implementation

Gunakan:

```cpp
sizeof(int)
```

untuk mengetahui ukuran type.

---

## Arithmetic Operators

Operator arithmetic dasar:

| Operator | Meaning |
|---|---|
| `+` | addition |
| `-` | subtraction |
| `*` | multiplication |
| `/` | division |
| `%` | modulus |

---

## Comparison Operators

Operator comparison:

| Operator | Meaning          |
| -------- | ---------------- |
| `==`     | equal            |
| `!=`     | not equal        |
| `<`      | less than        |
| `>`      | greater than     |
| `<=`     | less or equal    |
| `>=`     | greater or equal |

---

## Assignment vs Equality

Penting:

```cpp
=
```

adalah assignment.

Sedangkan:

```cpp
==
```

adalah equality comparison.

---

## Type Conversion

C++ melakukan implicit conversion antar basic types.

Contoh:

```cpp
double d = 2.2;
int i = 7;

d = d + i;
```

`i` otomatis dikonversi menjadi `double`.

---

## Narrowing Conversion

Contoh:

```cpp
int i = 7.2;
```

Nilai:
```cpp
7.2
```

dipotong menjadi:
```cpp
7
```

Ini disebut:
```text
narrowing conversion
```

---

## Brace Initialization

Modern C++ merekomendasikan:

```cpp
int x {10};
```

karena lebih aman.

Contoh:

```cpp
int x {7.2};
```

akan menghasilkan:
```text
compile-time error
```

---

## auto Keyword

`auto` memungkinkan compiler menentukan type otomatis.

Contoh:

```cpp
auto i = 123;
```

Compiler menyimpulkan:
```cpp
i -> int
```

---

## Compound Assignment

Operator singkat:

| Operator | Equivalent |
|---|---|
| `x += y` | `x = x + y` |
| `x -= y` | `x = x - y` |
| `x *= y` | `x = x * y` |

---

## Increment and Decrement

Contoh:

```cpp
++x;
--x;
```

Digunakan untuk:
- increment
- decrement

Sangat umum dalam loops.

---

# Penjelasan Teknis

## Static Typing

C++ adalah:
```text
statically typed language
```

Artinya:
- type diketahui compiler
- sebelum runtime

Keuntungan:
- error detection lebih awal
- optimisasi lebih baik
- safer code

---

## sizeof Operator

Contoh:

```cpp
sizeof(char)
```

Biasanya menghasilkan:

```cpp
1
```

Sedangkan:

```cpp
sizeof(int)
```

sering:
```cpp
4
```

tetapi implementation-defined.

---

## Initialization Styles

C++ mendukung beberapa style:

```cpp
int a = 10;
int b(10);
int c {10};
```

Modern C++ lebih memilih:
```cpp
{}
```

karena:
- lebih konsisten
- mencegah narrowing

---

## Why auto Matters?

`auto` penting untuk:
- generic programming
- long type names
- templates
- STL iterators

Contoh modern C++:

```cpp
auto it = vec.begin();
```

---

# Contoh Kode C++

## Basic Variables

```cpp
int age = 20;
double pi = 3.14;
char grade = 'A';
bool valid = true;
```

---

## Arithmetic

```cpp
int x = 10;
int y = 3;

int sum = x + y;
int product = x * y;
```

---

## Comparison

```cpp
if (x > y)
{
    // do something
}
```

---

## Brace Initialization

```cpp
int x {10};
double pi {3.14};
```

---

## auto

```cpp
auto name = 'A';
auto number = 42;
auto value = 3.14;
```

---

# Complexity

| Operation | Complexity |
|---|---|
| arithmetic operations | O(1) |
| comparisons | O(1) |
| assignments | O(1) |

---

# Pitfall

## Confusing `=` and `==`

Salah:

```cpp
if (x = 5)
```

Benar:

```cpp
if (x == 5)
```

---

## Narrowing Conversion

Contoh:

```cpp
int x = 3.9;
```

Data:
```cpp
0.9
```

hilang.

---

## Uninitialized Variables

Salah:

```cpp
int x;
```

langsung digunakan tanpa value.

---

## Overusing auto

Hindari:

```cpp
auto x = some_complex_expression();
```

jika type penting untuk readability.

---

# Best Practice

## Prefer Brace Initialization

Gunakan:

```cpp
int x {10};
```

karena lebih aman.

---

## Initialize Variables Immediately

GOOD:

```cpp
int age {20};
```

BAD:

```cpp
int age;
```

---

## Use Meaningful Names

GOOD:

```cpp
int score;
```

BAD:

```cpp
int s;
```

---

## Use auto Wisely

Gunakan `auto`:
- jika type obvious
- untuk long template types
- STL iterators

---

# Related Concepts

- [[StaticTyping]]
- [[TypeSystem]]
- [[Initialization]]
- [[TypeConversions]]
- [[ArithmeticOperators]]
- [[ComparisonOperators]]
- [[AutoKeyword]]
- [[Expressions]]

---

# Key Takeaways

- Semua object memiliki type
- Type menentukan operasi valid
- Variables adalah named objects
- C++ memiliki fundamental built-in types
- Brace initialization lebih aman
- `auto` membantu type deduction
- Arithmetic dan comparison operators sangat fundamental

---

# Summary

Section ini memperkenalkan fondasi semantic C++:
- types
- variables
- objects
- initialization
- operators
- type conversions

Konsep-konsep ini menjadi dasar:
- expressions
- functions
- classes
- templates
- STL
- modern C++ programming.