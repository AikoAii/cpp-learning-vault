---
title: Introductory Material Index
aliases:
  - Part I Index
tags:
  - cpp
  - fundamentals
  - concept
status: learning
difficulty: easy
created: 2026-05-19
updated: 2026-05-19
source: The C++ Programming Language (4th Edition)
---

# Introductory Material

> "A Tour of C++" adalah gambaran besar ekosistem C++ sebelum masuk ke detail teknis mendalam.

---

# Overview

Part ini berfungsi untuk:
- membangun mental model C++
- memahami filosofi bahasa
- mengenali pola modern C++
- memahami hubungan antar konsep inti
- mengenali style idiomatic C++

---

# Learning Sections

## Chapter 2 — A Tour of C++: The Basics

### Introduction
- [[WhatIsCpp]]
- [[PhilosophyOfCpp]]
- [[CompilationModel]]

### The Basics
- [[HelloWorld]]
- [[ProgramStructure]]
- [[Variables]]
- [[FundamentalTypes]]
- [[Constants]]
- [[Expressions]]
- [[IfStatement]]
- [[Loops]]
- [[Pointers]]
- [[Arrays]]
- [[References]]

### User-Defined Types
- [[Structs]]
- [[Classes]]
- [[Enumerations]]

### Modularity
- [[SeparateCompilation]]
- [[HeaderFiles]]
- [[Namespaces]]
- [[ErrorHandling]]

### Postscript
- [[ModernCppOverview]]
- [[STLPreview]]

### Advice
- [[CppLearningStrategy]]
- [[CommonPitfalls]]

---

## Chapter 3 — A Tour of C++: Abstraction Mechanisms

### Classes
- [[ConcreteTypes]]
- [[AbstractTypes]]
- [[VirtualFunctions]]
- [[ClassHierarchies]]

### Copy and Move
- [[CopySemantics]]
- [[MoveSemantics]]
- [[ResourceManagement]]
- [[OwnershipModel]]

### Templates
- [[TemplateBasics]]
- [[FunctionTemplates]]
- [[FunctionObjects]]
- [[VariadicTemplates]]
- [[GenericProgramming]]

### Advice
- [[AbstractionGuidelines]]
- [[RAIIPrinciples]]

---

## Chapter 4 — Containers and Algorithms

### Libraries
- [[STLOverview]]
- [[StdNamespace]]

### Strings
- [[StringBasics]]
- [[StringView]]

### Stream I/O
- [[InputStreams]]
- [[OutputStreams]]

### Containers
- [[Vector]]
- [[List]]
- [[Map]]
- [[UnorderedMap]]

### Algorithms
- [[STLAlgorithms]]
- [[Iterators]]
- [[Predicates]]

### Advice
- [[STLBestPractices]]
- [[IteratorPitfalls]]

---

## Chapter 5 — Concurrency and Utilities

### Resource Management
- [[UniquePtr]]
- [[SharedPtr]]
- [[RAII]]

### Concurrency
- [[ThreadBasics]]
- [[Tasks]]
- [[Futures]]
- [[Mutex]]

### Utilities
- [[Pair]]
- [[Tuple]]
- [[TypeTraits]]

### Regular Expressions
- [[RegexBasics]]

### Math
- [[RandomNumbers]]
- [[ComplexNumbers]]
- [[NumericLimits]]

### Advice
- [[ConcurrencyPitfalls]]
- [[SmartPointerGuidelines]]

---

# Suggested Learning Flow

```text
Basics
↓
Memory
↓
Classes
↓
RAII
↓
Templates
↓
STL
↓
Algorithms
↓
Concurrency
```

---

# Important Concepts

## Fundamental Core
- [[Pointers]]
- [[References]]
- [[RAII]]
- [[MoveSemantics]]
- [[Templates]]

## STL Core
- [[Vector]]
- [[Iterators]]
- [[STLAlgorithms]]

## Engineering Core
- [[Namespaces]]
- [[SeparateCompilation]]
- [[ErrorHandling]]

---

# Review Strategy

## Daily
- 1–3 atomic notes
- review backlinks
- revisit pitfalls

## Weekly
- revisit index
- update related concepts
- improve examples

---

# Key Takeaways

- C++ adalah multi-paradigm language
- Abstraction dan performance berjalan bersama
- Resource management adalah inti modern C++
- STL adalah fondasi idiomatic C++
- Understanding > memorization

---

# Related Concepts

- [[Roadmap]]
- [[LearningGoals]]
- [[CppLearningStrategy]]

---

# Summary

Part I berfungsi sebagai:
- conceptual overview
- mental model builder
- roadmap menuju modern C++

Fokus utama:
- memahami hubungan konsep
- memahami filosofi desain C++
- membangun fondasi untuk chapter berikutnya