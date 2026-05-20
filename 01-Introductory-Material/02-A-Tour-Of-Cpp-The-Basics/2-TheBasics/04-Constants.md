---
title: Constants
aliases:
  - const and constexpr
tags:
  - cpp
  - fundamentals
  - concept
  - optimization
status: learning
difficulty: medium
created: 2026-05-19
updated: 2026-05-19
source: "The C++ Programming Language (4th Edition)"
---

# Constants

---

# Ringkasan

C++ memiliki dua konsep utama untuk immutability:

- `const`
- `constexpr`

Keduanya digunakan untuk:
- keamanan program
- design clarity
- optimization
- compile-time guarantees

Tetapi tujuan mereka berbeda:
- `const` → tidak boleh diubah
- `constexpr` → harus bisa dievaluasi saat compile time

---

# Intuisi

Bayangkan:

```text
const
= read-only object
```

sedangkan:

```text
constexpr
= compile-time computable value
```

`const` fokus pada:
```text
immutability
```

`constexpr` fokus pada:
```text
compile-time evaluation
```

---

# Konsep Inti

## const

`const` berarti:
```text
nilai tidak boleh diubah
```

Contoh:

```cpp
const int dmv = 17;
```

Compiler akan mencegah:

```cpp
dmv = 20;
```

---

## constexpr

`constexpr` berarti:
```text
must be computable at compile time
```

Contoh:

```cpp
constexpr double pi = 3.14159;
```

Nilai dihitung compiler sebelum program berjalan.

---

## Immutable Objects

Object immutable:
- state tidak berubah
- lebih aman
- lebih mudah dipahami
- membantu optimization

---

## Compile-Time Evaluation

Compile-time evaluation berarti:
- expression dihitung compiler
- bukan saat runtime

Keuntungan:
- faster execution
- safer constants
- better optimization

---

# Penjelasan Teknis

## const Example

```cpp
const int dmv = 17;
```

Artinya:
- `dmv` adalah constant
- tidak dapat dimodifikasi

---

## Non-Constant Variable

```cpp
int var = 17;
```

`var`:
- mutable
- bukan constant expression

---

## constexpr Example

:contentReference[oaicite:0]{index=0}

```cpp
constexpr double max1 = 1.4 * square(dmv);
```

Valid jika:
```cpp
square(17)
```

adalah constant expression.

---

## constexpr Failure

```cpp
constexpr double max2 = 1.4 * square(var);
```

Error karena:

```cpp
var
```

bukan compile-time constant.

---

## Runtime const

```cpp
const double max3 = 1.4 * square(var);
```

Valid karena:
- `const` tidak wajib compile-time
- boleh runtime evaluation

---

## const Function Parameters

```cpp
double sum(const vector<double>& v);
```

Artinya:
- function tidak akan memodifikasi `v`

Ini sangat penting untuk:
- interface safety
- API design
- avoiding accidental modification

---

## constexpr Functions

Function bisa dibuat:

```cpp
constexpr double square(double x)
{
    return x * x;
}
```

Agar dapat dipakai dalam:
```text
constant expressions
```

---

## constexpr Function Rules

constexpr function harus:
- sederhana
- deterministic
- dapat dievaluasi compiler

Pada C++ modern aturan ini lebih fleksibel dibanding C++ lama.

---

## constexpr with Runtime Arguments

Contoh:

```cpp
double x = 5;

square(x);
```

Tetap valid.

Tetapi:
- hasilnya runtime
- bukan constant expression

---

## Where Constant Expressions Are Required?

Beberapa tempat membutuhkan compile-time constants:

- array bounds
- template arguments
- `case` labels
- constexpr variables

---

# Contoh Kode C++

## Basic const

```cpp
const int age = 20;
```

---

## constexpr Variable

```cpp
constexpr double pi = 3.14159;
```

---

## constexpr Function

:contentReference[oaicite:1]{index=1}

```cpp
constexpr int square(int x)
{
    return x * x;
}
```

---

## Runtime vs Compile-Time

```cpp
int x = 10;

const int a = x;
constexpr int b = x; // error
```

---

## const Reference

```cpp
void print(const std::string& s)
{
    std::cout << s;
}
```

---

# Complexity

| Operation | Complexity |
|---|---|
| const access | O(1) |
| constexpr evaluation | compile-time |
| runtime evaluation | O(1) |

---

# Pitfall

## Confusing const and constexpr

Salah asumsi:

```text
const = compile-time constant
```

Tidak selalu benar.

---

## constexpr with Runtime Values

Salah:

```cpp
int x = 5;
constexpr int y = x;
```

Karena:
```cpp
x
```

bukan compile-time constant.

---

## Forgetting const Correctness

Contoh buruk:

```cpp
void print(std::string& s)
```

Jika function tidak mengubah data:
gunakan:

```cpp
const std::string&
```

---

## Overusing constexpr

Tidak semua value perlu:
```cpp
constexpr
```

Gunakan saat:
- benar-benar constant
- dibutuhkan compile-time

---

# Best Practice

## Prefer const by Default

Jika variable tidak berubah:
gunakan:

```cpp
const
```

---

## Use constexpr for True Constants

GOOD:

```cpp
constexpr int max_size = 1024;
```

---

## Use const References

Untuk object besar:

```cpp
const std::vector<int>&
```

agar:
- tidak copy object
- tetap aman

---

## Maintain Const Correctness

Const correctness:
- meningkatkan readability
- membantu compiler
- mengurangi bugs

---

# Related Concepts

- [[Initialization]]
- [[Variables]]
- [[TypeSystem]]
- [[Functions]]
- [[References]]
- [[CompileTimeEvaluation]]
- [[Templates]]
- [[Optimization]]

---

# Key Takeaways

- `const` berarti immutable
- `constexpr` berarti compile-time evaluable
- compile-time evaluation meningkatkan optimization
- const correctness sangat penting di modern C++
- constexpr functions dapat digunakan di compile-time maupun runtime

---

# Summary

Constants adalah fondasi penting modern C++.

`const` membantu:
- safety
- readability
- interface design

`constexpr` membantu:
- compile-time computation
- optimization
- stronger guarantees

Konsep ini sangat penting untuk:
- templates
- generic programming
- optimization
- modern C++ design.