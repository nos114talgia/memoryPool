# Simple Memory Pool

A lightweight, thread-safe, and high-performance memory pool implementation in C++17. This project uses the **Singleton Pattern** to manage fixed-size memory blocks, providing an efficient alternative to frequent dynamic memory allocations.

## Features

- **Fixed-Size Block Allocation**: Minimizes memory fragmentation by managing memory in uniform blocks.
- **Thread-Safety**: Uses `std::mutex` and `std::lock_guard` to ensure safe concurrent access across multiple threads.
- **Singleton Pattern**: Provides a global access point for memory management.
- **Efficient Deallocation**: Calculates block indices in $O(1)$ time using pointer arithmetic.

## Project Structure

- `memoryPool.h`: Header file containing the class definition and Singleton interface.
- `memoryPool.cpp`: Implementation of allocation, deallocation, and initialization logic.
- `CMakeLists.txt`: Build configuration file.
