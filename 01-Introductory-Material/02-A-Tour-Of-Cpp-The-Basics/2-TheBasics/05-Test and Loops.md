---
title: Tests and Loops
aliases:
  - Control Flow
  - Selection and Iteration
tags:
  - cpp
  - fundamentals
  - concept
  - controlflow
status: learning
difficulty: easy
created: 2026-05-19
updated: 2026-05-19
source: "The C++ Programming Language (4th Edition)"
---

# Tests and Loops

---

# Ringkasan

C++ menyediakan control flow statements untuk:
- selection
- decision making
- looping
- repeated execution

Section ini memperkenalkan:
- `if`
- `switch`
- `while`
- input/output flow
- Boolean logic

---

# Intuisi

Program tidak selalu berjalan lurus dari atas ke bawah.

Kadang program harus:
- memilih aksi tertentu
- mengulang proses
- merespons input user

Control flow memungkinkan program:
```text
mengambil keputusan
```

dan:

```text
mengulang tindakan
```

berdasarkan kondisi.

---

# Konsep Inti

## Boolean

Type:

```cpp
bool
```

merepresentasikan:
- `true`
- `false`

Biasanya digunakan untuk:
- conditions
- tests
- decisions

---

## if Statement

`if` digunakan untuk:
```text
conditional execution
```

Artinya:
- kode dijalankan hanya jika condition bernilai `true`

Contoh:

```cpp
if (answer == 'y')
{
    return true;
}
```

---

## Equality Comparison

Operator:

```cpp
==
```

digunakan untuk:
```text
membandingkan dua nilai
```

Contoh:

```cpp
answer == 'y'
```

berarti:
- apakah `answer` sama dengan `'y'`

---

## Character Literal

Contoh:

```cpp
'y'
```

disebut:
```text
character literal
```

Karakter tunggal menggunakan:
```cpp
''
```

bukan:
```cpp
""
```

---

## Input Stream

```cpp
cin
```

adalah:
```text
standard input stream
```

Digunakan untuk:
- membaca input user
- menerima data dari terminal

---

## Output Stream

```cpp
cout
```

adalah:
```text
standard output stream
```

Digunakan untuk:
- menampilkan output
- menulis text ke terminal

---

## Input Operator

Operator:

```cpp
>>
```

berarti:
```text
get from stream
```

Contoh:

```cpp
cin >> answer;
```

Artinya:
- membaca input
- menyimpan ke `answer`

---

## switch Statement

`switch` digunakan untuk:
```text
multi-way selection
```

Artinya:
- memilih aksi berdasarkan beberapa kemungkinan value

---

## case Label

Contoh:

```cpp
case 'y':
```

berarti:
- jalankan code jika value cocok

---

## default Case

```cpp
default:
```

dijalankan jika:
- tidak ada `case` yang cocok

Mirip:
```text
fallback branch
```

---

## while Loop

`while` digunakan untuk:
```text
repeated execution
```

selama condition bernilai:
```cpp
true
```

---

## Increment Operator

```cpp
++tries;
```

berarti:

```cpp
tries = tries + 1;
```

Digunakan untuk:
- counting
- loops
- iteration

---

# Penjelasan Teknis

## Basic if Flow

```text
condition
↓
true ? execute : skip
```

---

## switch Flow

```text
evaluate value
↓
match case
↓
execute branch
```

`switch` cocok untuk:
- fixed discrete values
- menu systems
- command handling

---

## while Loop Flow

```text
check condition
↓
true → execute loop body
↓
repeat
```

Loop berhenti saat:
```cpp
condition == false
```

---

## Stream-Based Input

Contoh:

```cpp
cin >> answer;
```

Type variable menentukan:
- format input yang diterima
- cara parsing dilakukan compiler/library

---

## Newline Character

```cpp
\n
```

adalah:
```text
newline character
```

Efek:
- pindah ke baris baru

---

# Contoh Kode C++

## Basic if Statement

```cpp
if (x > 0)
{
    cout << "positive\n";
}
```

---

## switch Statement

```cpp
switch (grade)
{
case 'A':
    cout << "Excellent\n";
    break;

case 'B':
    cout << "Good\n";
    break;

default:
    cout << "Unknown\n";
}
```

---

## while Loop

```cpp
int i = 0;

while (i < 5)
{
    cout << i << "\n";
    ++i;
}
```

---

## User Input Example

```cpp
char answer;

cin >> answer;

if (answer == 'y')
{
    cout << "continue\n";
}
```

---

# Complexity

| Operation | Complexity |
|---|---|
| if statement | O(1) |
| switch statement | O(1) average |
| while loop | depends on iterations |

---

# Istilah Penting

| Term | Meaning |
|---|---|
| condition | expression bernilai true/false |
| branch | jalur eksekusi |
| iteration | satu pengulangan loop |
| control flow | arah eksekusi program |
| stream | aliran data input/output |
| loop body | kode di dalam loop |

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

## Infinite Loop

Contoh:

```cpp
while (true)
{
}
```

Loop:
- tidak pernah berhenti
- terus berjalan

---

## Forgetting Increment

Salah:

```cpp
while (i < 5)
{
    cout << i;
}
```

Karena:
```cpp
i
```

tidak berubah.

---

## Missing break in switch

Contoh:

```cpp
case 'A':
    cout << "A";
```

tanpa:
```cpp
break;
```

dapat menyebabkan:
```text
fallthrough
```

---

# Best Practice

## Gunakan switch untuk Fixed Choices

GOOD:
- menu
- commands
- enum handling

---

## Gunakan while untuk Repetition

Cocok untuk:
- retry logic
- input validation
- repeated processing

---

## Gunakan Nama Variable Jelas

GOOD:

```cpp
char answer;
```

BAD:

```cpp
char a;
```

---

## Hindari Complex Conditions

GOOD:

```cpp
if (is_valid)
```

BAD:

```cpp
if ((x > 0 && y < 5) || z == 10)
```

jika terlalu kompleks.

---

# Related Concepts

- [[BooleanExpressions]]
- [[Expressions]]
- [[Variables]]
- [[ArithmeticOperators]]
- [[ComparisonOperators]]
- [[Functions]]
- [[InputStreams]]
- [[OutputStreams]]

---

# Key Takeaways

- `if` digunakan untuk conditional execution
- `switch` digunakan untuk multi-way branching
- `while` digunakan untuk looping
- `cin` membaca input
- `cout` menampilkan output
- conditions menggunakan Boolean expressions
- loops sangat penting dalam programming

---

# Summary

Tests dan loops adalah fondasi control flow di C++.

Konsep ini memungkinkan program:
- membuat keputusan
- merespons input
- mengulang proses
- mengontrol execution flow

Semua software modern bergantung pada:
- branching
- iteration
- conditional logic.