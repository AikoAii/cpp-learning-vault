---
title: Namespaces
aliases:
  - Namespace
  - Scope Management
tags:
  - cpp
  - fundamentals
  - softwareengineering
  - modularity
  - concept
status: learning
difficulty: easy
created: 2026-05-19
updated: 2026-05-19
source: "The C++ Programming Language (4th Edition)"
---

# Namespaces

---

# Ringkasan

Namespace digunakan untuk:
- mengorganisasi code
- menghindari name collision
- memisahkan logical components
- mendukung modular programming

Namespace sangat penting dalam:
- libraries
- large-scale software
- reusable components

---

# Intuisi

Bayangkan dua programmer membuat:

```cpp
class Vector
```

Jika semuanya berada di:
```text
global scope
```

maka:
```text
name conflict
```

akan terjadi.

Namespace bekerja seperti:
```text
folder untuk nama
```

Contoh:

```cpp
Math::Vector
Graphics::Vector
Physics::Vector
```

Sekarang:
- nama tetap sama
- tetapi context berbeda

---

# Konsep Inti

## Namespace

Namespace adalah:
```text
scope untuk mengelompokkan declarations
```

---

## Name Collision

Name collision terjadi ketika:
- dua entity memiliki nama sama
- berada di scope sama

Namespace mencegah masalah ini.

---

## Namespace Scope

Contoh:

```cpp
namespace MyCode
{
    class Vector {};
}
```

`Vector` sekarang berada di:
```text
MyCode scope
```

---

## Scope Resolution Operator

Operator:

```cpp
::
```

disebut:
```text
scope resolution operator
```

Digunakan untuk:
- mengakses nama dalam namespace/class

Contoh:

```cpp
std::cout
```

---

## Qualified Name

Contoh:

```cpp
std::cout
```

Disebut:
```text
qualified name
```

Karena:
- nama disertai namespace

---

## Global Namespace

Code di luar:
- class
- namespace
- function

berada di:
```text
global namespace
```

---

## Standard Library Namespace

Hampir seluruh STL berada di:

```cpp
std
```

Contoh:
- `std::vector`
- `std::string`
- `std::cout`

---

## using Directive

Contoh:

```cpp
using namespace std;
```

Artinya:
```text
membuat nama dari std visible
```

Sehingga:
```cpp
cout
```

bisa digunakan tanpa:
```cpp
std::
```

---

# Penjelasan Teknis

## Why Namespaces Important?

Program besar memiliki:
- ribuan nama
- banyak libraries
- banyak modules

Tanpa namespace:
```text
name conflicts akan sangat sering terjadi
```

---

## Namespace as Logical Organization

Namespace membantu:
- grouping related code
- modular architecture
- library isolation

---

## Qualified Access

Contoh:

```cpp
MyCode::main()
```

Artinya:
- akses `main`
- milik namespace `MyCode`

---

## Standard Library Design

STL ditempatkan di:
```cpp
std
```

untuk:
- menghindari conflict dengan user code
- menjaga organization

---

## using namespace std

Contoh:

```cpp
using namespace std;
```

mempermudah penulisan,
tetapi:
- dapat menyebabkan collisions
- kurang aman di project besar

---

## Nested Scope

C++ memiliki hierarchical scopes:

```text
global
  └── namespace
        └── class
              └── function
```

Compiler mencari nama:
- dari scope terdekat
- ke luar bertahap

---

# Contoh Kode C++

## Basic Namespace

```cpp
namespace Math
{
    int add(int a, int b)
    {
        return a + b;
    }
}
```

---

## Accessing Namespace Members

```cpp
int result = Math::add(2, 3);
```

---

## Standard Library Example

```cpp
std::cout << "Hello\n";
```

---

## using Directive

```cpp
using namespace std;

cout << "Hello\n";
```

---

## Multiple Namespaces

```cpp
namespace Graphics
{
    class Vector {};
}

namespace Physics
{
    class Vector {};
}
```

---

# Complexity

| Operation | Complexity |
|---|---|
| namespace lookup | compile-time |
| qualified access | O(1) |
| scope resolution | compile-time |

---

# Istilah Penting

| Term | Meaning |
|---|---|
| namespace | scope pengelompokan nama |
| scope | area visibility nama |
| qualified name | nama dengan namespace |
| name collision | konflik nama |
| global namespace | scope paling luar |
| using directive | membuat nama namespace visible |

---

# Pitfall

## Overusing using namespace std

Buruk untuk:
- header files
- large projects
- libraries

Karena dapat menyebabkan:
```text
name pollution
```

---

## Forgetting Namespace Qualification

Salah:

```cpp
cout << "Hello";
```

tanpa:
```cpp
using namespace std;
```

atau:
```cpp
std::cout
```

---

## Name Collisions

Tanpa namespace:
- library berbeda dapat bentrok

---

## Putting Everything in Global Namespace

Global namespace terlalu penuh:
- sulit maintain
- rawan collision

---

# Best Practice

## Prefer Explicit Qualification

GOOD:

```cpp
std::vector<int>
```

Lebih jelas dan aman.

---

## Use Namespaces for Libraries

Semua library sebaiknya memiliki:
```text
namespace sendiri
```

---

## Avoid using namespace std in Headers

Karena:
- memengaruhi seluruh file yang include header

---

## Group Related Components

Namespace sebaiknya:
- logical
- meaningful
- modular

---

# Related Concepts

- [[Modularity]]
- [[SeparateCompilation]]
- [[ScopeResolutionOperator]]
- [[Libraries]]
- [[Classes]]
- [[SoftwareArchitecture]]
- [[HeaderFiles]]

---

# Key Takeaways

- Namespace mengelompokkan declarations
- Namespace mencegah name collision
- `::` digunakan untuk qualified access
- STL berada di namespace `std`
- `using namespace` membuat nama visible
- Namespace sangat penting untuk modular software

---

# Summary

Namespaces adalah fondasi organization dan modularity di C++.

Konsep ini memungkinkan:
- scalable software
- reusable libraries
- safe naming
- cleaner architecture

Tanpa namespace,
large-scale C++ programming akan:
- rawan conflicts
- sulit diorganisasi
- sulit dipelihara.