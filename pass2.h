#ifndef PASS2_H
#define PASS2_H

#include <string>

// Function prototype for pass2
void pass2(const std::string& moduleName);
void removeNewlines(std::string& str);
bool isInteger(const std::string& s);
std::string extractFirst6Bits(const std::string& hexOpcode);
std::string binaryToHex(const std::string& binaryString);
int calculateDisplacement(const std::string& hexString, const std::string& locctr, std::string& bp);


#endif // PASS2_H