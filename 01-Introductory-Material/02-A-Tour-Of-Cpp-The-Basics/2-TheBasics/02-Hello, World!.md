---
title: Hello World
aliases:
  - Minimal C++ Program
tags:
  - cpp
  - fundamentals
  - concept
  - helloworld
status: learning
difficulty: easy
created: 2026-05-19
updated: 2026-05-19
source: The C++ Programming Language (4th Edition)
---
# Hello World

---

# Ringkasan

Program C++ paling minimal terdiri dari:

- fungsi `main()`
    
- body function menggunakan `{}`
    
- executable entry point
    

Semua program C++ dimulai dari:

```cpp
int main()
{
}
```

---

# Intuisi

`main()` adalah:

```text
starting point program
```

Saat executable dijalankan:

- operating system memanggil `main()`
    
- execution dimulai dari sana
    
- seluruh flow program berasal dari `main()`
    

---

# Konsep Inti

## Minimal Program

Program C++ terkecil:

```cpp
int main()
{
}
```

Program ini:

- valid
    
- dapat dikompilasi
    
- tidak melakukan apa-apa
    

---

## Function

`main` adalah function.

Function digunakan untuk:

- mengelompokkan logic
    
- membagi program
    
- reusable behavior
    

---

## Curly Braces

Curly braces:

```cpp
{
}
```

menandakan:

- beginning of scope
    
- end of scope
    
- grouped statements
    

---

## Comments

Comment dimulai dengan:

```cpp
//
```

Contoh:

```cpp
// this is a comment
```

Comment:

- dibaca manusia
    
- diabaikan compiler
    

---

## Program Entry Point

Setiap program C++ harus memiliki:

```cpp
main()
```

Tanpa `main()`:

- executable program tidak dapat dibuat
    
- linker biasanya menghasilkan error
    

---

## Return Value

`main()` biasanya mengembalikan:

```cpp
int
```

Contoh:

```cpp
int main()
{
    return 0;
}
```

Makna:

|Value|Meaning|
|---|---|
|`0`|success|
|nonzero|failure/error|

---

## Hello World Program

Contoh program output sederhana:

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello, World!\n";
}
```

---

## #include

```cpp
#include <iostream>
```

Digunakan untuk:

- memasukkan declarations
    
- menggunakan standard stream I/O
    

Tanpa ini:

```cpp
std::cout
```

akan tidak dikenali compiler.

---

## std::cout

```cpp
std::cout
```

adalah standard output stream.

Digunakan untuk:

- menampilkan output
    
- menulis text ke terminal
    

---

## Stream Operator

Operator:

```cpp
<<
```

berarti:

```text
put data into stream
```

Contoh:

```cpp
std::cout << "Hello";
```

---

## String Literal

```cpp
"Hello, World!"
```

adalah:

```text
string literal
```

Yaitu sequence karakter di dalam double quotes.

---

## Newline Character

```cpp
\n
```

adalah newline character.

Efek:

- pindah ke baris baru
    

---

## Namespace Qualification

```cpp
std::cout
```

`std::` menunjukkan bahwa:

- `cout` berada di namespace standard library
    

---

## using namespace std

Contoh:

```cpp
using namespace std;
```

Membuat nama dari namespace `std` dapat digunakan tanpa:

```cpp
std::
```

Contoh:

```cpp
cout << "Hello";
```

---

## Functions and Reusability

Program besar dibangun dari banyak function.

Contoh:

```cpp
#include <iostream>
using namespace std;

double square(double x)
{
    return x * x;
}

void print_square(double x)
{
    cout << "the square of " << x
         << " is " << square(x)
         << "\n";
}

int main()
{
    print_square(1.234);
}
```

---

## Return Type

Return type menentukan:

- jenis value yang dikembalikan function
    

Contoh:

```cpp
double square(double x)
```

mengembalikan:

```cpp
double
```

---

## void Function

```cpp
void
```

berarti:

- function tidak mengembalikan value
    

Contoh:

```cpp
void print_square(double x)
```

---

# Penjelasan Teknis

## Basic Execution Flow

```text
OS
↓
main()
↓
function calls
↓
program execution
```

---

## Function Call

Contoh:

```cpp
square(x)
```

berarti:

- memanggil function
    
- mengirim argument
    
- menerima return value
    

---

## Standard Library Dependency

`iostream` adalah bagian dari:

```text
C++ Standard Library
```

Library ini menyediakan:

- streams
    
- formatting
    
- console I/O
    

---

# Contoh Kode C++

## Minimal Program

```cpp
int main()
{
}
```

---

## Hello World

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello, World!\n";
}
```

---

## Function Example

```cpp
#include <iostream>
using namespace std;

double square(double x)
{
    return x * x;
}

int main()
{
    cout << square(5.0) << "\n";
}
```

---

# Complexity

|Operation|Complexity|
|---|---|
|Function call|O(1)|
|Output operation|depends on output size|

---

# Pitfall

## Lupa `main()`

Error umum:

```text
undefined reference to main
```

---

## Lupa `#include <iostream>`

Menyebabkan:

```text
cout not declared
```

---

## Salah Menggunakan Namespace

Contoh salah:

```cpp
cout << "Hello";
```

Tanpa:

```cpp
using namespace std;
```

atau:

```cpp
std::cout
```

---

## Salah Return Type

Contoh:

```cpp
void square()
{
    return 5;
}
```

Invalid karena:

```cpp
void
```

berarti tidak mengembalikan value.

---

# Best Practice

## Gunakan Explicit Namespace

Prefer:

```cpp
std::cout
```

untuk code modern dan scalable.

---

## Pisahkan Logic ke Function

Hindari semua logic di `main()`.

Gunakan:

- reusable functions
    
- modular structure
    
- clean organization
    

---

## Gunakan Meaningful Function Names

GOOD:

```cpp
print_square()
```

BAD:

```cpp
ps()
```

---

# Related Concepts

- [[CompilationModel]]
    
- [[Functions]]
    
- [[ProgramStructure]]
    
- [[Namespaces]]
    
- [[StandardLibrary]]
    
- [[Expressions]]
    
- [[TypeSystem]]
    
- [[SourceFiles]]
    

---

# Key Takeaways

- Semua program C++ dimulai dari `main()`
    
- Curly braces menentukan scope
    
- Comment diabaikan compiler
    
- `iostream` menyediakan standard I/O
    
- `std::cout` digunakan untuk output
    
- Function membantu modularity
    
- `void` berarti tidak mengembalikan value
    
- Namespace membantu organization
    

---

# Summary

Hello World memperkenalkan fondasi program C++:

- function
    
- scope
    
- output
    
- namespace
    
- standard library
    
- execution flow
    

Konsep-konsep ini menjadi dasar untuk:

- modular programming
    
- abstraction
    
- software engineering di C++.