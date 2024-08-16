# get_next_line - 42Porto Common Core

## Introduction

**get_next_line** is a project at 42Porto aimed at developing a function that reads a line from a file descriptor. This project is essential for mastering file input/output in C and helps you understand buffer management and memory allocation, which are crucial for efficient data processing.

## Project Overview

In this project, you will implement the `get_next_line` function, which reads and returns the next line from a file descriptor. The function must handle different edge cases, such as reading from multiple file descriptors simultaneously and managing memory efficiently to avoid leaks.

### Key Learning Outcomes

- **File I/O in C**: Deepen your understanding of how file descriptors work and how to manage them.
- **Buffer Management**: Learn to handle buffers efficiently to manage large files and streams of data.
- **Memory Allocation**: Gain experience with dynamic memory allocation and ensuring your program is free from memory leaks.

## Project Structure

The project involves implementing:

- **Reading Functionality**: A function to read from a file descriptor until a newline or EOF is encountered.
- **Buffer Handling**: Efficiently managing buffers to store partial reads and handle large inputs.
- **Multiple Descriptors**: Support reading from multiple file descriptors without losing track of the data.

## Importance for Future Projects

The `get_next_line` function is a fundamental tool in many other projects and programming tasks. Mastering this project will give you the skills necessary to handle complex input and output operations in C, which are common in system programming and software development.

## Conclusion

The `get_next_line` project is a vital step in your journey through C programming at 42. By completing this project, you will gain critical skills in file handling, memory management, and efficient coding practices that will serve you well in advanced projects.

---

### Usage

To compile the library, run:

```bash
make
