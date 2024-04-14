// pass2.cpp

#include "pass2.h"
#include "pass1.h" // Include pass1.h to access LineInfo struct, SYMTAB, and OPTAB
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <bitset>



using namespace std;

// Pass 2 function to complete the listing file and assemble instructions
void pass2(const string& moduleName) {
    // Open input file
    string filename = moduleName + ".l";
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open input file " << filename << endl;
        exit(EXIT_FAILURE);
    }

    // Temporary file to store modified contents
    ofstream outputFile("temp.txt"); 
    if (!outputFile) {
        cerr << "Error: Failed to create the temporary file." << endl;
        return;
    }

    // Read through the input file again to generate the object code and assemble instructions
    string line;
    string current_Loc;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        LineInfo info;

        // Remove the newline character from end of line
        removeNewlines(line);

        // Parse the line into label, opcode, and operand
        ss >> current_Loc >> info.label >> info.opcode >> info.operand;

        // Check if line starts with a label or opcode
        if (isOpcode(info.label)) {
            info.operand = info.opcode;
            info.opcode = info.label;
            info.label.clear();
        }

        // Check if the opcode is a type 4 instruction
        bool type4 = (info.opcode[0] == '+');

        // Generate object code for instructions
        if (info.opcode == "START" || info.label == "BASE" || info.label == "END" || info.opcode == "RESW" || info.opcode == "RESB") {
            // No object code to add
            outputFile << line  << endl;

        } else if (OPTAB.find(info.opcode) != OPTAB.end() || type4) {
            // Set flags and addresses
            string displacement = "";
            string targetAddress = "000";
            string ni_flag = "00";
            string x_flag = "0";
            string bp_flag = "00";
            string e_flag = "0";
            string subStr = ",X";

            // Check X flag
            if (info.operand.find(subStr) != string::npos) {
                x_flag = "1";
                // Separate operand from X
                size_t pos = info.operand.find(',');
                info.operand = info.operand.substr(0, pos);
            }
       
            if (!type4) {
                // Type 3 instruction
                // Instruction with opcode found in OPTAB
                string opcode = OPTAB[info.opcode].first;
                int disp = 0;   // Default displacement
                
                if (info.opcode == "RSUB") {
                    ni_flag = "11"; // Set RSUB to direct addr mode

                } else if (!info.operand.empty()) {
                    // Check for different addressing modes (implement as needed)
                    
                    if (info.operand[0] == '#') {
                        // Immediate addressing mode
                        ni_flag = "01";
                        info.operand = info.operand.substr(1); // Ignore #

                    } else if (info.operand[0] == '@') {
                        // Indirect addressing mode
                        ni_flag = "10";
                        info.operand = info.operand.substr(1); // Ignore @
                    } else {    
                        // Direct addressing mode
                        ni_flag = "11";                      
                    }

                    // Calculate displacement    
                    if (!isInteger(info.operand)) {
                        disp = calculateDisplacement(info.operand, current_Loc, bp_flag);
                    } else {
                        disp = stoi(info.operand, nullptr, 16);
                    }                    
                }
                // Construct object code
                info.objectCode = extractFirst6Bits(opcode) + ni_flag + x_flag + bp_flag + e_flag;
                stringstream hexStream;
                hexStream << hex << uppercase << setw(3) << setfill('0') << disp;
                displacement = hexStream.str();
                info.objectCode = binaryToHex(info.objectCode) + displacement;
                outputFile << line +  "\t\t" + info.objectCode << endl;

            } else {
                // Type 4 instruction
                string opcode = OPTAB[info.opcode.substr(1)].first; // Ignore "+"
                string e_flag = "1";
                // Check addressing mode
                if (info.operand[0] == '#') {
                    // Immediate addressing mode
                    ni_flag = "01";
                    info.operand = info.operand.substr(1); // Ignore "#"

                } else if (info.operand[0] == '@') {
                    //Indirect addressing mode
                    ni_flag = "10";
                    info.operand = info.operand.substr(1);
                } else {
                    // Direct addressing mode
                    ni_flag = "11";
                }

                // Construct object code
                info.objectCode = extractFirst6Bits(opcode) + ni_flag + x_flag + bp_flag + e_flag;
                info.objectCode = binaryToHex(info.objectCode);
                
                // Format output
                stringstream hexStream;
                string literal = info.operand.substr(3, info.operand.size() - 4);
                if (LITTAB.find(literal) != LITTAB.end()) {  // Handle literal
                    hexStream << hex << uppercase << setw(5) << setfill('0') << LITTAB[literal];
                    displacement = hexStream.str();
                    outputFile << line +  "\t";
                } else if (isInteger(info.operand)){ // Handle integer
                    displacement = info.operand;
                    hexStream << hex << uppercase << setw(5) << setfill('0') << displacement;
                    outputFile << line;
                } else { // Handle label
                    hexStream << hex << uppercase << setw(5) << setfill('0') << SYMTAB[info.operand];
                    outputFile << line;
                }
                
                displacement = hexStream.str();
                outputFile << "\t\t" + info.objectCode + displacement << endl;

            }
            
        } else if (info.opcode == "BYTE" || info.opcode == "WORD" || info.label == "*") {
            // Check if opcode is a literal
            if (info.label == "*") {  
                info.operand = info.opcode.substr(1);   
                info.opcode = "BYTE";
                outputFile << line + "\t\t\t"; // Format object code
            } 
            
            // Handle BYTE and WORD directives (generate object code based on operand)
            if (info.opcode == "BYTE") {
                // Extract constant from operand (e.g., X'05', C'HELLO')
                string constant = info.operand.substr(2, info.operand.size() - 3);
                if (info.operand[0] == 'X') {
                    // Hexadecimal constant
                    info.objectCode = constant;
                } else if (info.operand[0] == 'C') {
                    // Character constant (convert characters to ASCII hex values)
                    stringstream ss;
                    for (char& c : constant) {
                        ss << uppercase << hex << int(c);
                    }
                    info.objectCode = ss.str();
                }
                
            } else if (info.opcode == "WORD") {
                // Integer constant (convert to 6-digit hexadecimal)
                int value = stoi(info.operand);
                info.objectCode = to_string(value);
            }
            // Write to listing file
            outputFile << "\t\t" + info.objectCode << endl; // Format object code

        } else {
            // Invalid opcode
            cerr << "Error: Invalid opcode '" << info.opcode << "' found" << current_Loc << endl;
            exit(EXIT_FAILURE);
        }
    }

    inputFile.close();
    outputFile.close();

    // Replace the original file with the updated file
    if (rename("temp.txt", filename.c_str()) != 0) {
        cerr << "Error: Failed to replace the original file." << endl;
        return;
    }  
}

// Function to remove newline characters from a string
void removeNewlines(string& str) {
    str.erase(remove(str.begin(), str.end(), '\n'), str.end());
    str.erase(remove(str.begin(), str.end(), '\r'), str.end());
}

bool isInteger(const std::string& s) {
    try {
        std::stoi(s);
        return true;
    } catch (...) {
        return false;
    }
}

// Function to extract the first 6 bits from a hexadecimal opcode
string extractFirst6Bits(const string& hexOpcode) {
    // Convert hexadecimal to binary
    bitset<8> binaryOpcode(stoi(hexOpcode, 0, 16));
    string first6Bits = binaryOpcode.to_string().substr(0, 6);

    return first6Bits;
}

// Function to convert a binary string to its hexadecimal representation
string binaryToHex(const string& binaryString) {
    // Convert each group of 4 binary digits to its hexadecimal representation
    stringstream hexStream;
    for (size_t i = 0; i < binaryString.length(); i += 4) {
        bitset<4> binaryGroup(binaryString.substr(i, 4));
        hexStream << hex << uppercase << binaryGroup.to_ulong();
    }

    return hexStream.str();
}

// Function to calculate displacement of instruction
int calculateDisplacement(const string& hexString, const string& locctr, string& bp) {
    // Get address of next instruction

    
    // Convert hexadecimal strings to integers
    int pc = stoi(locctr, nullptr, 16) + 3;
    int ta = SYMTAB[hexString];
    int disp = ta - pc;
    // Calculate displacement                        
    if ( -2048 <= disp && disp <= 2047) {
    // PC relative
        bp = "01";                                                    
    } else { // Out of pc range, base relative 
        bp = "10";
        // Get base address
        int br = SYMTAB["BASE"];
        disp = ta - br;                            
    }
    // Prepare negative decimal to convert to base relative hex
    if (disp < 0){
        disp = 4095 + disp;
    }
    return disp;  
}
