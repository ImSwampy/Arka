# Project : Arka

## Description

This project have for purpose to be low level, fast and versatile. Introducing new features such as CoreLaunch: similar to docker, the program will be compiled and start on a custom OS, with the needed files and requirements. Alternate Testing: an interpreter to debug the code faster and easier, and the compiler will be used to deployment only **However, some errors might happen only when built.**

We also wanted to make this programming language easy to learn, with some advanced concepts such as pointers, memory write & read, websocket, threads and more.

As advantages, it benefits from the low level languages static typing, and hardware management.

## Goals
    - **Create the compiler**
        - Tokenizer
        - Parser
        - Error handling
        - IR
        - Executable
    - **Create the interpreter**
        - Tokenizer
        - Parser
        - Error Handling
    - **Command line tool**
        - Make compiling and interpreting easier
        - Debugger
        - More building tools
    - **.arkonfig**
        - File based project management. 
        - Imports, parameters and configuration settings 
        - Custom commands, run and build configurations
    - **Osark**
        - Lightweight OS, built from scratch that will run on the side of the main OS
        - Linux Based Kernel?
        - Platform independent
        - Share resources with the main OS
- ## Details
    - **Languages used**
      - The whole project will be based on C++, for its efficiency.
      - Assembly will also be used for lower level programming like linker or assembler.
    - **Syntax**
      - Arka's syntax will be familiar with C++ or Rust, aiming to be easy to learn and understand.
    - **Features**
      - Direct Memory Management
      - Manual Pointers, Stack and Heap Memory usage, coupled with a limited garbage collection to prevent unexpected errors
      - Websockets, with REST API Support, JSON encoding, threading and more


- ## Informations
  - The Project is just at its beginning. There may be some errors related to compatibility errors or just code errors.