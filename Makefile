# Makefile for CS530 Assignment2
# Niko Perry, Sabrina Lee
# Makefile for assembling SIC/XE programs

# Compiler and compiler flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Executable name
TARGET = asxe

# Source files
SRCS = asxe.cpp pass1.cpp pass2.cpp optab.cpp

# Object files (generated during compilation)
OBJS = $(SRCS:.cpp=.o)

# Build target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^


# Clean target
clean:
	rm -f $(TARGET) $(OBJS) $(DEPS)

# Phony target to avoid conflicts with file names
.PHONY: all clean

# Default target
all: $(TARGET)

# End of Makefile
