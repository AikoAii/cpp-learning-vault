---
title: Enumerations
aliases:
  - Enum
  - Enum Class
tags:
  - cpp
  - fundamentals
  - oop
  - concept
status: learning
difficulty: easy
created: 2026-05-19
updated: 2026-05-19
source: "The C++ Programming Language (4th Edition)"
---

# Enumerations

---

# Ringkasan

Enumeration (`enum`) digunakan untuk:
- merepresentasikan sekumpulan nilai tetap
- membuat code lebih readable
- mengurangi magic numbers
- meningkatkan type safety

Modern C++ merekomendasikan:
```cpp
enum class
```

karena:
- strongly typed
- scoped
- lebih aman

---

# Intuisi

Daripada menggunakan:

```cpp
int traffic = 1;
```

yang tidak jelas artinya,

lebih baik:

```cpp
TrafficLight::green
```

karena:
- lebih readable
- lebih meaningful
- lebih aman

Enumeration membantu compiler memahami:
```text
nilai mana yang valid
```

---

# Konsep Inti

## Enumeration

Enumeration adalah:
```text
user-defined type
```

yang berisi:
```text
sekumpulan named constants
```

---

## enum class

Contoh:

```cpp
enum class Color
{
    red,
    blue,
    green
};
```

`enum class` adalah:
```text
strongly typed enumeration
```

---

## Enumerators

Nilai di dalam enum disebut:
```text
enumerators
```

Contoh:

```cpp
red
blue
green
```

---

## Scoped Enumerators

Enumerator berada di dalam scope enum.

Contoh:

```cpp
Color::red
```

dan:

```cpp
TrafficLight::red
```

adalah:
```text
dua nilai berbeda
```

---

## Strong Typing

`enum class` mencegah:
- implicit conversion
- accidental mixing
- integer confusion

---

## Type Safety

Contoh invalid:

```cpp
Color c = TrafficLight::red;
```

Compiler menolak karena:
- type berbeda
- unsafe conversion

---

## No Implicit Integer Conversion

Contoh invalid:

```cpp
int x = Color::red;
```

Karena:
```text
Color bukan int
```

---

## Plain Enum

C++ lama memiliki:

```cpp
enum Color
{
    red,
    blue
};
```

Disebut:
```text
plain enum
```

Kurang aman karena:
- implicit conversion ke int
- enumerator tidak scoped

---

## Operator Overloading

Karena enum adalah:
```text
user-defined type
```

kita dapat mendefinisikan operator sendiri.

Contoh:

```cpp
operator++
```

untuk:
```cpp
TrafficLight
```

---

# Penjelasan Teknis

## Why enum class Matters?

`enum class` diperkenalkan untuk memperbaiki:
- namespace pollution
- accidental conversions
- weak typing pada plain enum

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
- mengakses member dalam scope tertentu

Contoh:

```cpp
Color::red
```

---

## Enumeration Underlying Type

Secara internal:
- enum biasanya disimpan sebagai integer
- tetapi abstraction tetap dijaga compiler

---

## Comparison Operations

Secara default enum mendukung:
- assignment
- initialization
- comparison

Contoh:

```cpp
if (light == TrafficLight::red)
```

---

## State Machine Style

Enum sering digunakan untuk:
```text
state representation
```

Contoh:
- traffic lights
- game states
- parser states
- UI modes

---

## Custom Operators

Contoh:

```cpp
++light;
```

dapat dibuat dengan:
```cpp
operator++
```

Ini memungkinkan:
- custom transitions
- domain-specific behavior

---

# Contoh Kode C++

## Basic enum class

```cpp
enum class Color
{
    red,
    blue,
    green
};
```

---

## Using Enumerators

```cpp
Color c = Color::red;
```

---

## Comparison

```cpp
if (c == Color::blue)
{
    cout << "blue\n";
}
```

---

## Traffic Light Example

```cpp
enum class TrafficLight
{
    green,
    yellow,
    red
};
```

---

## Operator Overloading

```cpp
TrafficLight& operator++(TrafficLight& t)
{
    switch (t)
    {
    case TrafficLight::green:
        return t = TrafficLight::yellow;

    case TrafficLight::yellow:
        return t = TrafficLight::red;

    case TrafficLight::red:
        return t = TrafficLight::green;
    }

    return t;
}
```

---

# Complexity

| Operation | Complexity |
|---|---|
| enum comparison | O(1) |
| assignment | O(1) |
| switch dispatch | O(1) |

---

# Istilah Penting

| Term | Meaning |
|---|---|
| enumeration | sekumpulan named constants |
| enumerator | nilai di dalam enum |
| strongly typed | type tidak mudah tercampur |
| scoped | nama berada di scope tertentu |
| type safety | perlindungan dari misuse type |
| state machine | sistem perubahan state |

---

# Pitfall

## Using Plain enum Accidentally

Plain enum:

```cpp
enum Color
```

lebih rawan:
- name collision
- implicit conversion
- bugs

---

## Forgetting Scope

Salah:

```cpp
Color c = red;
```

Benar:

```cpp
Color c = Color::red;
```

---

## Mixing Different Enums

Salah:

```cpp
Color c = TrafficLight::red;
```

Karena:
```text
type berbeda
```

---

## Missing switch Cases

Contoh:

```cpp
switch (light)
```

tanpa menangani semua state.

Dapat menyebabkan:
```text
undefined logic path
```

---

# Best Practice

## Prefer enum class

Gunakan:

```cpp
enum class
```

bukan:
```cpp
enum
```

untuk modern C++.

---

## Use Meaningful Names

GOOD:

```cpp
TrafficLight
```

BAD:

```cpp
TL
```

---

## Use Enum for Finite States

Cocok untuk:
- modes
- states
- categories
- options

---

## Handle All Cases

Pastikan:
```cpp
switch
```

menangani seluruh enumerators.

---

# Related Concepts

- [[UserDefinedTypes]]
- [[Classes]]
- [[TypeSafety]]
- [[ScopeResolutionOperator]]
- [[OperatorOverloading]]
- [[SwitchStatement]]
- [[StateMachines]]

---

# Key Takeaways

- Enumeration merepresentasikan named constants
- `enum class` lebih aman daripada plain enum
- Enumerators bersifat scoped
- enum class mencegah implicit conversions
- Enum sangat cocok untuk state representation
- Operator dapat dioverload untuk enum

---

# Summary

Enumerations membantu membuat code:
- lebih readable
- lebih aman
- lebih expressive

`enum class` adalah modern C++ solution untuk:
- type safety
- scoped constants
- finite state modeling

Konsep ini sangat sering digunakan dalam:
- game development
- system programming
- UI systems
- parsers
- embedded systems.