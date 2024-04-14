//asxe.cpp
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <vector>
#include <map>
#include <string>
#include "pass1.h"
#include "pass2.h"

using namespace std;

// Main program to execute pass 1 and pass 2
int main(int argc, char *argv[]) {
    // Check if the correct number of command-line arguments are provided
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file1> [<input_file2> ...]" << endl;
        return EXIT_FAILURE;
    }

    // Process each input file with pass 1
    for (int i = 1; i < argc; ++i) {
        // Extract module name (filename without extension) for EXTDEF/EXTREF handling
        string filename = argv[i];
        string moduleName = filename.substr(0, filename.find_last_of('.'));
        pass1(filename, moduleName); // Execute pass 1 for the current input file
        pass2(moduleName);
    }

    // Process each input file with pass 2
    // Assuming pass2 function and related data structures are also defined similarly in pass2.cpp and pass2.h

    return EXIT_SUCCESS;
}
