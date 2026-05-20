---
title: Static Assertions
aliases:
  - static_assert
  - Compile-Time Assertions
tags:
  - cpp
  - fundamentals
  - optimization
  - templates
  - concept
status: learning
difficulty: medium
created: 2026-05-19
updated: 2026-05-19
source: "The C++ Programming Language (4th Edition)"
---

# Static Assertions

---

# Ringkasan

`static_assert` digunakan untuk:
- memvalidasi asumsi saat compile time
- mendeteksi error lebih awal
- memastikan constraint program benar

Berbeda dengan exceptions:
- exceptions → runtime
- static_assert → compile-time

---

# Intuisi

Daripada program gagal saat runtime:

```text
lebih baik gagal saat compile time
```

Jika compiler sudah bisa mengetahui:
- sesuatu invalid
- assumption salah
- type tidak cocok

maka:
```text
program seharusnya tidak boleh dikompilasi
```

Itulah tujuan:
```cpp
static_assert
```

---

# Konsep Inti

## Assertion

Assertion adalah:
```text
statement tentang sesuatu yang harus benar
```

---

## static_assert

`static_assert` adalah:
```text
compile-time assertion
```

Syntax:

```cpp
static_assert(condition, message);
```

---

## Compile-Time Validation

`static_assert` bekerja:
```text
saat compilation
```

Bukan:
```text
runtime
```

---

## Constant Expression Requirement

Condition pada `static_assert` harus berupa:
```text
constant expression
```

Artinya:
- nilainya diketahui compiler
- sebelum program berjalan

---

## Compiler Error Message

Jika assertion gagal:
- compilation gagal
- compiler menampilkan message

---

## Type Constraints

`static_assert` sangat penting dalam:
```text
generic programming
```

untuk memastikan:
- type valid
- template assumptions benar

---

# Penjelasan Teknis

## Basic Syntax

```cpp
static_assert(condition, "message");
```

Jika:
```cpp
condition == false
```

maka:
```text
compiler error
```

---

## sizeof Example

:contentReference[oaicite:0]{index=0}

```cpp
static_assert(4 <= sizeof(int),
              "integers are too small");
```

Artinya:
- `int` minimal 4 bytes

Jika tidak:
- compilation dihentikan

---

## Why Compile-Time Checks Better?

Compile-time errors:
- lebih cepat ditemukan
- lebih murah diperbaiki
- lebih aman

dibanding:
```text
runtime failures
```

---

## constexpr Relationship

Karena:
```cpp
static_assert
```

membutuhkan:
```text
constant expressions
```

maka sangat erat dengan:
- `constexpr`
- compile-time evaluation

---

## Invalid Runtime Variable

Contoh invalid:

```cpp
static_assert(speed < C, "too fast");
```

Jika:
```cpp
speed
```

adalah runtime variable.

Karena compiler:
```text
tidak mengetahui nilainya saat compile time
```

---

## Valid constexpr Example

:contentReference[oaicite:1]{index=1}

```cpp
constexpr double local_max = 160.0 / (60 * 60);

static_assert(local_max < C,
              "can't go that fast");
```

Valid karena:
- semua nilainya compile-time constants

---

## Generic Programming Usage

`static_assert` sering digunakan dalam:
- templates
- type traits
- metaprogramming

untuk:
- membatasi valid types
- menghasilkan clearer compiler errors

---

# Contoh Kode C++

## Basic static_assert

```cpp
static_assert(sizeof(int) >= 4,
              "int too small");
```

---

## constexpr Example

```cpp
constexpr int max_size = 64;

static_assert(max_size > 0,
              "invalid size");
```

---

## Type Validation

```cpp
static_assert(sizeof(double) == 8,
              "unexpected double size");
```

---

## Template Constraint Example

```cpp
template<typename T>
void process()
{
    static_assert(sizeof(T) > 0,
                  "invalid type");
}
```

---

# Complexity

| Operation | Complexity |
|---|---|
| static_assert evaluation | compile-time |
| runtime overhead | O(0) |
| assertion failure | compilation stops |

---

# Istilah Penting

| Term | Meaning |
|---|---|
| assertion | statement yang harus benar |
| compile-time | saat compilation |
| runtime | saat program berjalan |
| constant expression | expression yang diketahui compiler |
| constexpr | compile-time evaluable |
| template constraint | batasan pada template type |

---

# Pitfall

## Using Runtime Values

Salah:

```cpp
int x = 5;

static_assert(x > 0, "error");
```

Karena:
```cpp
x
```

bukan compile-time constant.

---

## Overusing static_assert

Tidak semua validation cocok:
- compile-time

Sebagian harus:
- runtime checking

---

## Confusing Exceptions and static_assert

| Mechanism | Time |
|---|---|
| `static_assert` | compile-time |
| exceptions | runtime |

---

## Weak Error Messages

Buruk:

```cpp
static_assert(x > 0, "error");
```

Lebih baik:
```cpp
static_assert(x > 0,
              "size must be positive");
```

---

# Best Practice

## Use static_assert for Compile-Time Guarantees

GOOD:
- type assumptions
- platform assumptions
- template constraints

---

## Write Clear Messages

Compiler errors harus:
- descriptive
- actionable

---

## Prefer Compile-Time Validation When Possible

Compile-time checking:
- lebih aman
- lebih cepat
- mengurangi runtime bugs

---

## Combine with constexpr

`constexpr` + `static_assert` adalah kombinasi penting modern C++.

---

# Related Concepts

- [[Constants]]
- [[Constexpr]]
- [[CompileTimeEvaluation]]
- [[Templates]]
- [[TypeSystem]]
- [[Exceptions]]
- [[GenericProgramming]]

---

# Key Takeaways

- `static_assert` melakukan compile-time validation
- Condition harus berupa constant expression
- Compile-time errors lebih baik daripada runtime errors
- `static_assert` sangat penting dalam templates
- `constexpr` sering digunakan bersama `static_assert`
- Tidak ada runtime overhead

---

# Summary

Static assertions memungkinkan programmer:
- memvalidasi assumptions lebih awal
- menghentikan invalid programs saat compilation
- membuat template errors lebih jelas
- meningkatkan correctness

Konsep ini sangat penting dalam:
- generic programming
- metaprogramming
- library design
- modern C++ abstractions.