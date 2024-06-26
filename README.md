# Limited SIC/XE Assembler
### Niko Perry

## File Manifest
  - pass1.h
  - pass1.cpp
  - pass2.h
  - pass2.cpp
  - optab.cpp
  - asxe.cpp
  - Makefile
  - README

## Compile Instructions
  - Use "make" to compile project
  - Use "./scanner <filename.txt>" to run program
  - Use "make clean" to remove all files created during compilation

## Operating Instructions
  - The compiled program expects the input file name as a command-line argument.
  - There can be multiple input files

## Novel/Significant Design Decisions
  - Use of maps (SYMTAB, LITTAB, MNEMONICTAB, OPTAB) for symbol, literal, mnemonic, and opcode information.
  - Modular design with separate pass1 and pass2 functions for assembling the input file.
  - Handling of different directive types (BYTE, WORD, RESW, RESB) and instruction formats (Type 1, Type 2, Type 3/4).

## Extra Features/Functionality
  - Error handling for duplicate symbols and invalid opcodes.

## Known Deficiencies/Bugs
  - Lack of extensive error checking for malformed input files.
  - Limited support for advanced instruction formats or addressing modes.
  - Possible performance issues with large input files due to sequential processing.

## Lessons Learned
  - Importance of modular design and separation of concerns in complex projects.
  - Practical usage of C++ STL containers (maps, vectors) for managing symbol tables and data structures.
  - Enhanced understanding of assembly language concepts and the two-pass assembler approach.
