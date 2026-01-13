# Base Converter (2-36)

![Language](https://img.shields.io/badge/language-C++17-blue)
![License](https://img.shields.io/badge/license-MIT-green)

High-performance numerical base converter written in C++. It handles conversions between any base from binary (2) to hexatrigesimal (36), ensuring precision and speed.

## 🚀 Features
- **Universal Conversion:** Converts from any Base X to Base Y (where 2 <= X, Y <= 36).
- **Input Validation:** robust error handling for invalid digits within a specific base.
- **Modern C++:** Uses standard library features for efficient memory management.

## 🛠️ Installation & Usage

### Prerequisites
- A C++ Compiler (g++, clang, or MSVC)
- CMake (optional, for building)

### Building
```bash
g++ main.cpp -o converter
./converter
```

## 🧮 How it Works
The algorithm uses a two-step process to ensure accuracy:

Normalization: Converts the source number to Decimal (Base 10) using positional notation.

Transformation: Converts the decimal value to the target base using the Euclidean division algorithm.

👤 Author
Caio Toledo - [LinkedIn](https://www.linkedin.com/in/caio-toledo-sousa)
