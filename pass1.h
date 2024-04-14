#ifndef PASS1_H
#define PASS1_H

#include <map>
#include <string>

using namespace std;

// Structure to hold information about each line of code
struct LineInfo {
    string label;
    string opcode;
    string operand;
    int address;
    string objectCode;
};

// Symbol table map (label -> address)
extern map<string, int> SYMTAB;

// Literal table map (label -> address)
extern map<string, int> LITTAB;

// Declaration of OPTAB (defined externally in another source file)
extern std::map<std::string, std::pair<std::string, int> > OPTAB;

// Function declarations for pass1
void pass1(const string& filename, const string& moduleName);
void initializeOPTAB();
bool isOpcode(const std::string& label);

#endif // PASS1_H
