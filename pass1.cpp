// pass1.cpp

#include "pass1.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <iomanip>
#include <cstdlib>

using namespace std;

std::map<std::string, int> SYMTAB;

// Pass 1 function to process the input file and build the symbol table
void pass1(const string& filename, const string& moduleName) {
    SYMTAB.clear(); // Reset SYMTAB
    // Open file
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open input file " << filename << endl;
        exit(EXIT_FAILURE);
    }

    // Create .l output file
    string listingFilename = moduleName + ".l";
    ofstream listingFile(listingFilename);
    if (!listingFile) {
        cerr << "Error: Failed to create the listing file." << endl;
        return;
    }

    // Create .st output file
    string symbolTableFilename = moduleName + ".st";
    ofstream symbolTableFile(symbolTableFilename);
    if (!symbolTableFile) {
        cerr << "Error: Failed to create the symbol table file." << endl;
        return;
    }

    // Initialize OPTAB
    initializeOPTAB();

    // Process sic file
    string line;
    int locctr = 0; // Location counter
    string baseRegister;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        LineInfo info;
        // Ignore lines starting with "."
        if (line.empty() || line[0] == '.') {
            continue; 
        }

        // Parse the line into label, opcode, and operand
        ss >> info.label >> info.opcode >> info.operand;

        // Write to listing file
        listingFile << hex << uppercase << setfill('0') << setw(4) << locctr << '\t' + line << endl;

        // Check if line starts with a label or opcode
        if (isOpcode(info.label)) {
            info.operand = info.opcode;
            info.opcode = info.label;
            info.label.clear();
        }

        // Update SYMTAB
        if (!info.label.empty()) {
            // Check if label is already in SYMTAB (duplicate symbol error)
            if (SYMTAB.find(info.label) != SYMTAB.end()) {
                cerr << "Error: Duplicate symbol '" << info.label << "' found" << endl;
                exit(EXIT_FAILURE);
            }
            // Update base register
            if (info.label == "BASE") {
                 baseRegister = info.opcode;
            } else {
                // Add label to SYMTAB with current locctr
                SYMTAB[info.label] = locctr;
                // Write label to SYMTAB file
                symbolTableFile << info.label << "\t" << hex << uppercase << setfill('0') << setw(4) << locctr << endl;
            }
        }

        // Increment locctr based on opcode and operand
        if (info.opcode == "START") {
            // Set starting address from operand
            locctr = stoi(info.operand, nullptr, 16); // Assuming operand is in hex
        } else if (info.opcode == "END") {
            // End of program
            break;
        } else if (info.opcode == "BYTE") {
            // Increment locctr based on length of BYTE constant
            string operand = info.operand;
            if (operand[0] == 'C') {
                locctr += operand.length() - 3; // Length excluding 'C' and quotes
            } else if (operand[0] == 'X') {
                locctr += (operand.length() - 3) / 2; // Length excluding 'X' and quotes
            } else {
                cerr << "Error: Invalid BYTE directive" << endl;
                exit(EXIT_FAILURE);
            }
        } else if (info.opcode == "WORD") {
            // Increment locctr by 3 (one word = 3 bytes)
            locctr += 3;
        } else if (info.opcode == "RESW") {
            // Increment locctr by 3 * number of words specified in operand
            int numWords = stoi(info.operand);
            locctr += 3 * numWords;
        } else if (info.opcode == "RESB") {
            // Increment locctr by number of bytes specified in operand
            int numBytes = stoi(info.operand);
            locctr += numBytes;
        } else if (info.opcode.substr(0, 1) == "+") {
            // Type 4 instruction
            locctr += 4;
        
        } else if (info.label == "BASE") {
            // Locctr stays the same
            continue;
        }
        else {
            // Increment locctr by default instruction length (assuming standard instruction)
            locctr += 3; // Assuming standard instruction length in bytes
        }     
    }
    // Upadate base register's address
    SYMTAB["BASE"] = SYMTAB[baseRegister];

    // Close input and output files
    inputFile.close();
    listingFile.close();
    symbolTableFile.close();
}