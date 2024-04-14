#include "pass1.h"  // Include pass1.h to access OPTAB declaration
#include <map>
#include <string>
#include <iostream>


// Definition of OPTAB map
std::map<std::string, std::string> OPTAB;

// Function to check if a given string is an opcode
bool isOpcode(const std::string& label) {
    std::string opcode = label;
    if (label[0] == '+') {
        opcode = label.substr(1); // Remove the '+' character
    }
    
    return OPTAB.find(opcode) != OPTAB.end();
}


// Function to initialize the OPTAB map
void initializeOPTAB() {
    OPTAB.insert(std::make_pair("ADD", "18"));
    OPTAB.insert(std::make_pair("ADDF", "58"));
    OPTAB.insert(std::make_pair("ADDR", "90"));
    OPTAB.insert(std::make_pair("AND", "40"));
    OPTAB.insert(std::make_pair("CLEAR", "B4"));
    OPTAB.insert(std::make_pair("COMP", "28"));
    OPTAB.insert(std::make_pair("COMPF", "88"));
    OPTAB.insert(std::make_pair("COMPR", "A0"));
    OPTAB.insert(std::make_pair("DIV", "24"));
    OPTAB.insert(std::make_pair("DIVF", "64"));
    OPTAB.insert(std::make_pair("DIVR", "9C"));
    OPTAB.insert(std::make_pair("FIX", "C4"));
    OPTAB.insert(std::make_pair("FLOAT", "C0"));
    OPTAB.insert(std::make_pair("HIO", "F4"));
    OPTAB.insert(std::make_pair("J", "3C"));
    OPTAB.insert(std::make_pair("JEQ", "30"));
    OPTAB.insert(std::make_pair("JGT", "34"));
    OPTAB.insert(std::make_pair("JLT", "38"));
    OPTAB.insert(std::make_pair("JSUB", "48"));
    OPTAB.insert(std::make_pair("LDA", "00"));
    OPTAB.insert(std::make_pair("LDB", "68"));
    OPTAB.insert(std::make_pair("LDCH", "50"));
    OPTAB.insert(std::make_pair("LDF", "70"));
    OPTAB.insert(std::make_pair("LDL", "08"));
    OPTAB.insert(std::make_pair("LDS", "6C"));
    OPTAB.insert(std::make_pair("LDT", "74"));
    OPTAB.insert(std::make_pair("LDX", "04"));
    OPTAB.insert(std::make_pair("LPS", "D0"));
    OPTAB.insert(std::make_pair("MUL", "20"));
    OPTAB.insert(std::make_pair("MULF", "60"));
    OPTAB.insert(std::make_pair("MULR", "98"));
    OPTAB.insert(std::make_pair("NORM", "C8"));
    OPTAB.insert(std::make_pair("OR", "44"));
    OPTAB.insert(std::make_pair("RD", "D8"));
    OPTAB.insert(std::make_pair("RMO", "AC"));
    OPTAB.insert(std::make_pair("RSUB", "4C"));
    OPTAB.insert(std::make_pair("SHIFTL", "A4"));
    OPTAB.insert(std::make_pair("SHIFTR", "A8"));
    OPTAB.insert(std::make_pair("SIO", "F0"));
    OPTAB.insert(std::make_pair("SSK", "EC"));
    OPTAB.insert(std::make_pair("STA", "0C"));
    OPTAB.insert(std::make_pair("STB", "78"));
    OPTAB.insert(std::make_pair("STCH", "54"));
    OPTAB.insert(std::make_pair("STF", "80"));
    OPTAB.insert(std::make_pair("STI", "D4"));
    OPTAB.insert(std::make_pair("STL", "14"));
    OPTAB.insert(std::make_pair("STS", "7C"));
    OPTAB.insert(std::make_pair("STSW", "E8"));
    OPTAB.insert(std::make_pair("STT", "84"));
    OPTAB.insert(std::make_pair("STX", "10"));
    OPTAB.insert(std::make_pair("SUB", "1C"));
    OPTAB.insert(std::make_pair("SUBF", "5C"));
    OPTAB.insert(std::make_pair("SUBR", "94"));
    OPTAB.insert(std::make_pair("SVC", "B0"));
    OPTAB.insert(std::make_pair("TD", "E0"));
    OPTAB.insert(std::make_pair("TIO", "F8"));
    OPTAB.insert(std::make_pair("TIX", "2C"));
    OPTAB.insert(std::make_pair("TIXR", "B8"));
    OPTAB.insert(std::make_pair("WD", "DC"));
}