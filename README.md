# UNO Console Game

## Description

This project is the final assignment for an introductory programming class in C. It is a console-based game that simulates the popular card game UNO. The game supports multiple players, includes an AI option, and implements core UNO mechanics like drawing cards, playing special cards (Skip, Reverse, Draw Two, Wild, and Draw Four), and managing turn order.

## Contents

- **main.c**  
  Contains the main game loop, handling player turns, input/output, and overall game flow.
- **other.c**  
  Implements game logic such as deck generation, shuffling, drawing and playing cards, and AI behavior.
- **other.h**  
  Declares the card structure and prototypes for all game functions.
- **deck.txt** (optional)  
  A file with a predefined deck configuration used when not generating a new deck.
- **README.md**  
  This file, which documents the project details and lessons learned.

## Features

- **Complete UNO Mechanics:**  
  Implements core rules including special cards (Skip, Reverse, Draw Two, Wild, and Draw Four).
- **Multi-Player Support:**  
  Allows for 2–10 players, with an option to designate one player as an AI.
- **Dynamic Deck Handling:**  
  Supports generating a new shuffled deck or loading a deck from an external file.
- **Linked List Hand Management:**  
  Utilizes linked lists to efficiently manage each player's hand.
- **Console-Based User Interface:**  
  Provides text-based card displays and prompts for interactive gameplay.

## Technology

- **Programming Language:**  
  C
- **Development Tools:**  
  - GCC (or any standard C compiler)  
  - Standard C libraries (stdio, stdlib, string, etc.)
- **Concepts Demonstrated:**  
  - File I/O for reading deck configurations  
  - Dynamic memory allocation and pointer manipulation  
  - Linked list data structures for managing game state  
  - Basic AI implementation and game control flow

## Lessons

- **Memory Management:**  
  Enhanced skills in dynamic allocation and pointer operations in C.
- **Data Structure Implementation:**  
  Gained experience in implementing and manipulating linked lists for dynamic data (i.e., players' hands).
- **Game Logic Development:**  
  Learned how to structure and manage complex game flow, including handling special card rules.
- **Debugging & Problem-Solving:**  
  Overcame challenges with pointer arithmetic and file I/O, leading to improved debugging strategies.

## Overview / Retrospective

- **What Went Well:**  
  - Successfully implemented all major UNO game mechanics.  
  - The use of linked lists for hand management proved effective and educational.  
  - The project met all requirements for a functional, interactive console game.
- **Areas for Improvement:**  
  - Enhance error handling for user inputs and file operations.  
  - Refactor the code for better modularity and readability. (It was first real coding project lo, very messy)
  - Improve the AI logic to create a more challenging opponent. (Hardly AI tbh, just a couple of basic strategies)
- **Future Enhancements:**  
  - Develop a graphical user interface (GUI) for an improved user experience.  
  - Extend AI capabilities with more advanced decision-making strategies.  
  - Incorporate unit testing and further code refactoring to improve maintainability.

