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
	OPTAB.insert(std::make_pair("ADD", std::make_pair("18", 1)));
	OPTAB.insert(std::make_pair("ADDF", std::make_pair("58", 1)));
	OPTAB.insert(std::make_pair("ADDR", std::make_pair("90", 1)));
	OPTAB.insert(std::make_pair("AND", std::make_pair("40", 1)));
	OPTAB.insert(std::make_pair("CLEAR", std::make_pair("B4", 1)));
	OPTAB.insert(std::make_pair("COMP", std::make_pair("28", 1)));
	OPTAB.insert(std::make_pair("COMPF", std::make_pair("88", 1)));
	OPTAB.insert(std::make_pair("COMPR", std::make_pair("A0", 1)));
	OPTAB.insert(std::make_pair("DIV", std::make_pair("24", 1)));
	OPTAB.insert(std::make_pair("DIVF", std::make_pair("64", 1)));
	OPTAB.insert(std::make_pair("DIVR", std::make_pair("9C", 1)));
	OPTAB.insert(std::make_pair("FIX", std::make_pair("C4", 1)));
	OPTAB.insert(std::make_pair("FLOAT", std::make_pair("C0", 1)));
	OPTAB.insert(std::make_pair("HIO", std::make_pair("F4", 1)));
	OPTAB.insert(std::make_pair("J", std::make_pair("3C", 1)));
	OPTAB.insert(std::make_pair("JEQ", std::make_pair("30", 1)));
	OPTAB.insert(std::make_pair("JGT", std::make_pair("34", 1)));
	OPTAB.insert(std::make_pair("JLT", std::make_pair("38", 1)));
	OPTAB.insert(std::make_pair("JSUB", std::make_pair("48", 1)));
	OPTAB.insert(std::make_pair("LDA", std::make_pair("00", 1)));
	OPTAB.insert(std::make_pair("LDB", std::make_pair("68", 1)));
	OPTAB.insert(std::make_pair("LDCH", std::make_pair("50", 1)));
	OPTAB.insert(std::make_pair("LDF", std::make_pair("70", 1)));
	OPTAB.insert(std::make_pair("LDL", std::make_pair("08", 1)));
	OPTAB.insert(std::make_pair("LDS", std::make_pair("6C", 1)));
	OPTAB.insert(std::make_pair("LDT", std::make_pair("74", 1)));
	OPTAB.insert(std::make_pair("LDX", std::make_pair("04", 1)));
	OPTAB.insert(std::make_pair("LPS", std::make_pair("D0", 1)));
	OPTAB.insert(std::make_pair("MUL", std::make_pair("20", 1)));
	OPTAB.insert(std::make_pair("MULF", std::make_pair("60", 1)));
	OPTAB.insert(std::make_pair("MULR", std::make_pair("98", 1)));
	OPTAB.insert(std::make_pair("NORM", std::make_pair("C8", 1)));
	OPTAB.insert(std::make_pair("OR", std::make_pair("44", 1)));
	OPTAB.insert(std::make_pair("RD", std::make_pair("D8", 1)));
	OPTAB.insert(std::make_pair("RMO", std::make_pair("AC", 1)));
	OPTAB.insert(std::make_pair("RSUB", std::make_pair("4C", 1)));
	OPTAB.insert(std::make_pair("SHIFTL", std::make_pair("A4", 1)));
	OPTAB.insert(std::make_pair("SHIFTR", std::make_pair("A8", 1)));
	OPTAB.insert(std::make_pair("SIO", std::make_pair("F0", 1)));
	OPTAB.insert(std::make_pair("SSK", std::make_pair("EC", 1)));
	OPTAB.insert(std::make_pair("STA", std::make_pair("0C", 1)));
	OPTAB.insert(std::make_pair("STB", std::make_pair("78", 1)));
	OPTAB.insert(std::make_pair("STCH", std::make_pair("54", 1)));
	OPTAB.insert(std::make_pair("STF", std::make_pair("80", 1)));
	OPTAB.insert(std::make_pair("STI", std::make_pair("D4", 1)));
	OPTAB.insert(std::make_pair("STL", std::make_pair("14", 1)));
	OPTAB.insert(std::make_pair("STS", std::make_pair("7C", 1)));
	OPTAB.insert(std::make_pair("STSW", std::make_pair("E8", 1)));
	OPTAB.insert(std::make_pair("STT", std::make_pair("84", 1)));
	OPTAB.insert(std::make_pair("STX", std::make_pair("10", 1)));
	OPTAB.insert(std::make_pair("SUB", std::make_pair("1C", 1)));
	OPTAB.insert(std::make_pair("SUBF", std::make_pair("5C", 1)));
	OPTAB.insert(std::make_pair("SUBR", std::make_pair("94", 1)));
	OPTAB.insert(std::make_pair("SVC", std::make_pair("B0", 1)));
	OPTAB.insert(std::make_pair("TD", std::make_pair("E0", 1)));
	OPTAB.insert(std::make_pair("TIO", std::make_pair("F8", 1)));
	OPTAB.insert(std::make_pair("TIX", std::make_pair("2C", 1)));
	OPTAB.insert(std::make_pair("TIXR", std::make_pair("B8", 1)));
	OPTAB.insert(std::make_pair("WD", std::make_pair("DC", 1)));

}

int main() {
    initializeOPTAB();

    // Accessing values
    std::cout << "Opcode for ADD: " << OPTAB["ADD"].first << ", Value: " << OPTAB["ADD"].second << std::endl;
    std::cout << "Opcode for ADDF: " << OPTAB["ADDF"].first << ", Value: " << OPTAB["ADDF"].second << std::endl;


    return 0;
}