---
title: Exceptions
aliases:
  - Exception Handling
  - throw try catch
tags:
  - cpp
  - fundamentals
  - bug
  - softwareengineering
  - concept
status: learning
difficulty: medium
created: 2026-05-19
updated: 2026-05-19
source: "The C++ Programming Language (4th Edition)"
---

# Exceptions

---

# Ringkasan

Exceptions adalah mekanisme C++ untuk:
- melaporkan error
- memisahkan normal logic dan error handling
- menangani runtime failures secara sistematis

Konsep utama:
- `throw`
- `try`
- `catch`
- stack unwinding

---

# Intuisi

Bayangkan function seperti:

```cpp
v[i]
```

Jika:
```cpp
i
```

invalid,

siapa yang harus menangani?

- Vector tidak tahu solusi terbaik
- User kadang tidak bisa mendeteksi sebelumnya

Maka:
```text
Vector melaporkan error
```

dan:
```text
caller memutuskan apa yang harus dilakukan
```

Itulah ide dasar:
```text
exceptions
```

---

# Konsep Inti

## Exception

Exception adalah:
```text
runtime error signal
```

yang dikirim ketika:
- operasi gagal
- kondisi invalid terjadi
- program tidak dapat melanjutkan normal flow

---

## throw

Keyword:

```cpp
throw
```

digunakan untuk:
```text
melempar exception
```

Contoh:

```cpp
throw out_of_range{"Vector::operator[]"};
```

---

## try Block

Code yang mungkin menghasilkan exception ditempatkan di:

```cpp
try
{
}
```

---

## catch Block

`catch` digunakan untuk:
```text
menangani exception
```

Contoh:

```cpp
catch (out_of_range)
{
}
```

---

## Exception Type

Exception memiliki:
```text
type
```

Contoh:
- `out_of_range`
- `runtime_error`
- `bad_alloc`

Type membantu:
- categorizing errors
- selective handling

---

## Stack Unwinding

Saat exception dilempar:
- execution normal berhenti
- function calls dibatalkan mundur
- stack dibersihkan

Proses ini disebut:
```text
stack unwinding
```

---

## Runtime Error

Out-of-range access adalah:
```text
runtime error
```

karena:
- baru diketahui saat program berjalan

---

# Penjelasan Teknis

## Out-of-Range Access

Contoh:

```cpp
v[v.size()]
```

invalid karena:
- index terakhir adalah:
  
```cpp
v.size() - 1
```

---

## Exception Flow

Flow sederhana:

```text
throw exception
↓
stack unwinding
↓
find matching catch
↓
handle error
```

---

## Why Exceptions Useful?

Tanpa exceptions:
- error codes tersebar
- logic bercampur dengan validation
- readability menurun

Exceptions memisahkan:
- normal flow
- error flow

---

## Standard Library Exceptions

C++ STL menyediakan exception bawaan:

| Exception | Purpose |
|---|---|
| `out_of_range` | invalid index |
| `runtime_error` | runtime failures |
| `bad_alloc` | allocation failure |

---

## Stack Unwinding Details

Saat unwinding:
- local objects dihancurkan
- destructors dipanggil
- resources dibersihkan

Ini sangat penting untuk:
```text
RAII
```

---

## Exception Propagation

Jika function tidak menangani exception:
- exception diteruskan ke caller
- hingga ditemukan matching handler

---

# Contoh Kode C++

## Throwing Exception

```cpp
if (i < 0 || size() <= i)
{
    throw std::out_of_range{"Vector::operator[]"};
}
```

---

## try-catch Example

```cpp
try
{
    v[v.size()] = 7;
}
catch (std::out_of_range&)
{
    cout << "range error\n";
}
```

---

## Simple Runtime Validation

```cpp
if (x < 0)
{
    throw std::runtime_error{"negative value"};
}
```

---

# Complexity

| Operation | Complexity |
|---|---|
| normal execution | minimal overhead |
| throw exception | expensive |
| stack unwinding | depends on call depth |

---

# Istilah Penting

| Term | Meaning |
|---|---|
| exception | sinyal error runtime |
| throw | melempar exception |
| catch | menangani exception |
| try block | area monitoring exception |
| stack unwinding | pembatalan call stack |
| handler | code penanganan exception |
| propagation | penyebaran exception |

---

# Pitfall

## Using Exceptions for Normal Logic

Buruk:

```cpp
exceptions sebagai pengganti if
```

Exceptions hanya untuk:
```text
exceptional situations
```

---

## Catching Wrong Type

Contoh:

```cpp
catch (int)
```

padahal exception:
```cpp
out_of_range
```

Tidak akan tertangkap.

---

## Ignoring Exceptions

Jika exception tidak tertangani:
```text
program termination dapat terjadi
```

---

## Throwing Too Frequently

Exceptions:
- powerful
- tetapi expensive

Jangan digunakan untuk:
- normal control flow

---

# Best Practice

## Use Exceptions for Exceptional Errors

GOOD:
- invalid state
- failed allocation
- impossible operation

---

## Keep try Blocks Small

Agar:
- error source jelas
- debugging lebih mudah

---

## Use Standard Exceptions

Prefer:
- `std::out_of_range`
- `std::runtime_error`

daripada custom integer codes.

---

## Combine with RAII

RAII membantu:
- automatic cleanup
- safe unwinding
- leak prevention

---

# Related Concepts

- [[ErrorHandling]]
- [[RuntimeErrors]]
- [[Classes]]
- [[RAII]]
- [[StackUnwinding]]
- [[Functions]]
- [[StandardLibrary]]
- [[DynamicMemory]]

---

# Key Takeaways

- Exceptions digunakan untuk runtime error handling
- `throw` melempar exception
- `try` memonitor kemungkinan exception
- `catch` menangani exception
- Stack unwinding membersihkan call stack
- Exceptions memisahkan normal logic dan error handling
- STL menyediakan standard exception types

---

# Summary

Exceptions adalah mekanisme penting modern C++ untuk:
- systematic error handling
- cleaner code
- separation of concerns

Konsep ini bekerja sangat erat dengan:
- RAII
- destructors
- abstractions
- modular software design

Modern C++ menggunakan exceptions untuk:
- reliability
- safety
- maintainability
- robust software engineering.