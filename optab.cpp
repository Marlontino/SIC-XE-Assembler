#include "pass1.h"  // Include pass1.h to access OPTAB declaration
#include <map>
#include <string>
#include <iostream>


// Definition of OPTAB map
std::map<std::string, std::pair<std::string, int> > OPTAB;

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
	OPTAB.insert(std::make_pair("ADD", std::make_pair("18", 3)));
	OPTAB.insert(std::make_pair("ADDF", std::make_pair("58", 3)));
	OPTAB.insert(std::make_pair("ADDR", std::make_pair("90", 2)));
	OPTAB.insert(std::make_pair("AND", std::make_pair("40", 3)));
	OPTAB.insert(std::make_pair("CLEAR", std::make_pair("B4", 2)));
	OPTAB.insert(std::make_pair("COMP", std::make_pair("28", 3)));
	OPTAB.insert(std::make_pair("COMPF", std::make_pair("88", 3)));
	OPTAB.insert(std::make_pair("COMPR", std::make_pair("A0", 2)));
	OPTAB.insert(std::make_pair("DIV", std::make_pair("24", 3)));
	OPTAB.insert(std::make_pair("DIVF", std::make_pair("64", 3)));
	OPTAB.insert(std::make_pair("DIVR", std::make_pair("9C", 2)));
	OPTAB.insert(std::make_pair("FIX", std::make_pair("C4", 1)));
	OPTAB.insert(std::make_pair("FLOAT", std::make_pair("C0", 1)));
	OPTAB.insert(std::make_pair("HIO", std::make_pair("F4", 1)));
	OPTAB.insert(std::make_pair("J", std::make_pair("3C", 3)));
	OPTAB.insert(std::make_pair("JEQ", std::make_pair("30", 3)));
	OPTAB.insert(std::make_pair("JGT", std::make_pair("34", 3)));
	OPTAB.insert(std::make_pair("JLT", std::make_pair("38", 3)));
	OPTAB.insert(std::make_pair("JSUB", std::make_pair("48", 3)));
	OPTAB.insert(std::make_pair("LDA", std::make_pair("00", 3)));
	OPTAB.insert(std::make_pair("LDB", std::make_pair("68", 3)));
	OPTAB.insert(std::make_pair("LDCH", std::make_pair("50", 3)));
	OPTAB.insert(std::make_pair("LDF", std::make_pair("70", 3)));
	OPTAB.insert(std::make_pair("LDL", std::make_pair("08", 3)));
	OPTAB.insert(std::make_pair("LDS", std::make_pair("6C", 3)));
	OPTAB.insert(std::make_pair("LDT", std::make_pair("74", 3)));
	OPTAB.insert(std::make_pair("LDX", std::make_pair("04", 3)));
	OPTAB.insert(std::make_pair("LPS", std::make_pair("D0", 3)));
	OPTAB.insert(std::make_pair("MUL", std::make_pair("20", 3)));
	OPTAB.insert(std::make_pair("MULF", std::make_pair("60", 3)));
	OPTAB.insert(std::make_pair("MULR", std::make_pair("98", 2)));
	OPTAB.insert(std::make_pair("NORM", std::make_pair("C8", 1)));
	OPTAB.insert(std::make_pair("OR", std::make_pair("44", 3)));
	OPTAB.insert(std::make_pair("RD", std::make_pair("D8", 3)));
	OPTAB.insert(std::make_pair("RMO", std::make_pair("AC", 2)));
	OPTAB.insert(std::make_pair("RSUB", std::make_pair("4C", 3)));
	OPTAB.insert(std::make_pair("SHIFTL", std::make_pair("A4", 2)));
	OPTAB.insert(std::make_pair("SHIFTR", std::make_pair("A8", 2)));
	OPTAB.insert(std::make_pair("SIO", std::make_pair("F0", 1)));
	OPTAB.insert(std::make_pair("SSK", std::make_pair("EC", 3)));
	OPTAB.insert(std::make_pair("STA", std::make_pair("0C", 3)));
	OPTAB.insert(std::make_pair("STB", std::make_pair("78", 3)));
	OPTAB.insert(std::make_pair("STCH", std::make_pair("54", 3)));
	OPTAB.insert(std::make_pair("STF", std::make_pair("80", 3)));
	OPTAB.insert(std::make_pair("STI", std::make_pair("D4", 3)));
	OPTAB.insert(std::make_pair("STL", std::make_pair("14", 3)));
	OPTAB.insert(std::make_pair("STS", std::make_pair("7C", 3)));
	OPTAB.insert(std::make_pair("STSW", std::make_pair("E8", 3)));
	OPTAB.insert(std::make_pair("STT", std::make_pair("84", 3)));
	OPTAB.insert(std::make_pair("STX", std::make_pair("10", 3)));
	OPTAB.insert(std::make_pair("SUB", std::make_pair("1C", 3)));
	OPTAB.insert(std::make_pair("SUBF", std::make_pair("5C", 3)));
	OPTAB.insert(std::make_pair("SUBR", std::make_pair("94", 2)));
	OPTAB.insert(std::make_pair("SVC", std::make_pair("B0", 2)));
	OPTAB.insert(std::make_pair("TD", std::make_pair("E0", 3)));
	OPTAB.insert(std::make_pair("TIO", std::make_pair("F8", 1)));
	OPTAB.insert(std::make_pair("TIX", std::make_pair("2C", 3)));
	OPTAB.insert(std::make_pair("TIXR", std::make_pair("B8", 2)));
	OPTAB.insert(std::make_pair("WD", std::make_pair("DC", 3)));
	// Mnemonics
	OPTAB.insert(std::make_pair("A", std::make_pair("0", -1)));
	OPTAB.insert(std::make_pair("X", std::make_pair("1", -1)));
	OPTAB.insert(std::make_pair("L", std::make_pair("2", -1)));
	OPTAB.insert(std::make_pair("B", std::make_pair("3", -1)));
	OPTAB.insert(std::make_pair("S", std::make_pair("4", -1)));
	OPTAB.insert(std::make_pair("T", std::make_pair("5", -1)));
	OPTAB.insert(std::make_pair("F", std::make_pair("6", -1)));
	OPTAB.insert(std::make_pair("PC", std::make_pair("8", -1)));
	OPTAB.insert(std::make_pair("SW", std::make_pair("9", -1)));

}

void initializeMNEMONICTAB () {
    MNEMONICTAB.insert(std::make_pair("A","0"));
    MNEMONICTAB.insert(std::make_pair("X","1"));
    MNEMONICTAB.insert(std::make_pair("L","2"));
    MNEMONICTAB.insert(std::make_pair("B","3"));
    MNEMONICTAB.insert(std::make_pair("S","4"));
    MNEMONICTAB.insert(std::make_pair("T","5"));
    MNEMONICTAB.insert(std::make_pair("F","6"));
    MNEMONICTAB.insert(std::make_pair("PC","8"));
    MNEMONICTAB.insert(std::make_pair("SW","9"));
}