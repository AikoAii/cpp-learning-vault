---
title: Invariants
aliases:
  - Class Invariants
  - Preconditions
tags:
  - cpp
  - fundamentals
  - oop
  - softwareengineering
  - bug
  - concept
status: learning
difficulty: medium
created: 2026-05-19
updated: 2026-05-19
source: "The C++ Programming Language (4th Edition)"
---

# Invariants

---

# Ringkasan

Invariant adalah:
```text
kondisi yang harus selalu benar
```

untuk suatu object atau system.

Dalam C++:
- constructor bertugas membangun invariant
- member functions harus menjaga invariant tetap valid

Konsep ini sangat penting untuk:
- correctness
- reliability
- safe abstractions
- robust software design

---

# Intuisi

Bayangkan object seperti:
```cpp
Vector
```

memiliki aturan:

```text
elem harus menunjuk array valid
sz harus >= 0
```

Jika aturan ini rusak:
- object menjadi invalid
- behavior tidak dapat diprediksi
- bugs muncul

Invariant adalah:
```text
aturan internal object
```

yang harus selalu dijaga.

---

# Konsep Inti

## Invariant

Invariant adalah:
```text
logical condition yang selalu harus benar
```

untuk object valid.

Contoh invariant pada `Vector`:

```text
elem points to valid memory
sz >= 0
```

---

## Preconditions

Precondition adalah:
```text
syarat sebelum function dijalankan
```

Contoh:

```text
index harus berada di range valid
```

---

## Postconditions

Postcondition adalah:
```text
kondisi setelah function selesai
```

yang harus tetap benar.

---

## Constructor Responsibility

Constructor bertugas:
```text
membangun object valid
```

Artinya:
- invariant harus benar setelah constructor selesai

---

## Member Function Responsibility

Member functions harus:
```text
menjaga invariant tetap valid
```

---

## Invalid State

Contoh:

```cpp
Vector v(-27);
```

menyebabkan:
```text
invalid object state
```

Karena:
```text
size negatif tidak masuk akal
```

---

## Defensive Validation

Constructor harus memvalidasi input:

```cpp
if (s < 0)
{
    throw length_error{};
}
```

---

## Exception-Based Protection

Jika invariant gagal dibangun:
- constructor melempar exception
- object tidak dibuat

Ini mencegah:
```text
partially invalid objects
```

---

# Penjelasan Teknis

## Why Invariants Important?

Tanpa invariant:
- object bisa berada pada state rusak
- functions menjadi tidak reliable
- debugging sangat sulit

---

## Vector Invariant

Pada `Vector`:

| Member | Invariant |
|---|---|
| `elem` | menunjuk memory valid |
| `sz` | non-negative |

---

## Preconditions in operator[]

Contoh:

```cpp
0 <= i < size()
```

adalah:
```text
precondition
```

untuk:
```cpp
operator[]
```

---

## Constructor Validation

Versi buruk:

```cpp
Vector::Vector(int s)
{
    elem = new double[s];
    sz = s;
}
```

Tidak memvalidasi:
```cpp
s
```

---

## Safer Constructor

Versi lebih aman:

```cpp
Vector::Vector(int s)
{
    if (s < 0)
    {
        throw length_error{};
    }

    elem = new double[s];
    sz = s;
}
```

---

## Resource Safety

Invariant sangat erat dengan:
```text
resource management
```

karena:
- memory harus valid
- ownership harus jelas
- cleanup harus benar

---

## Exception Safety

Jika constructor gagal:
- exception dilempar
- object tidak dianggap valid

Ini adalah bagian penting dari:
```text
RAII philosophy
```

---

# Contoh Kode C++

## Invalid Constructor

```cpp
Vector v(-5);
```

---

## Constructor Validation

```cpp
Vector::Vector(int s)
{
    if (s < 0)
    {
        throw std::length_error{};
    }

    elem = new double[s];
    sz = s;
}
```

---

## Precondition Check

```cpp
if (i < 0 || size() <= i)
{
    throw std::out_of_range{};
}
```

---

## Exception Handling

```cpp
try
{
    Vector v(-27);
}
catch (std::length_error&)
{
    cout << "invalid size\n";
}
```

---

# Complexity

| Operation | Complexity |
|---|---|
| invariant check | O(1) typical |
| constructor validation | O(1) |
| bounds checking | O(1) |

---

# Istilah Penting

| Term | Meaning |
|---|---|
| invariant | kondisi yang selalu harus benar |
| precondition | syarat sebelum function berjalan |
| postcondition | kondisi setelah function selesai |
| invalid state | state object rusak |
| validation | pengecekan correctness |
| resource management | pengelolaan memory/resource |

---

# Pitfall

## Ignoring Invariants

Jika invariant tidak dijaga:
- object menjadi corrupt
- bugs sulit dilacak

---

## Assuming User Input Is Valid

Buruk:

```cpp
Vector(int s)
{
    elem = new double[s];
}
```

tanpa validasi.

---

## Partial Object Construction

Jika constructor gagal:
- object bisa setengah valid
- sangat berbahaya

---

## Weak Preconditions

Function tanpa precondition jelas:
- sulit digunakan
- mudah disalahgunakan

---

# Best Practice

## Define Invariants Clearly

Selalu pikirkan:
```text
apa yang harus selalu benar?
```

---

## Validate Constructor Arguments

GOOD:

```cpp
if (size < 0)
```

---

## Maintain Invariants in Every Member Function

Setelah function selesai:
```text
object harus tetap valid
```

---

## Use Exceptions for Invalid States

Jika invariant tidak dapat dipenuhi:
```text
fail immediately
```

---

# Related Concepts

- [[Exceptions]]
- [[Classes]]
- [[Constructors]]
- [[RAII]]
- [[ErrorHandling]]
- [[Encapsulation]]
- [[ResourceManagement]]
- [[DefensiveProgramming]]

---

# Key Takeaways

- Invariant adalah kondisi yang harus selalu benar
- Constructor membangun invariant
- Member functions menjaga invariant
- Preconditions menentukan syarat penggunaan function
- Validation penting untuk safe abstractions
- Exceptions membantu mencegah invalid objects

---

# Summary

Invariants adalah fondasi penting dalam desain class modern C++.

Konsep ini membantu:
- menjaga correctness
- mencegah invalid states
- meningkatkan reliability
- membuat abstractions lebih aman

Sebagian besar modern C++ design:
- RAII
- STL
- exception safety
- resource management

dibangun di atas ide:
```text
objects should always remain valid
```