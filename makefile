# Compiler
CC := g++

# The Target Binary Program
TARGET := networkApp

# C++ Compiler Flags
CXXFLAGS := -g -Wall -Wextra -std=c++17

# Source Files
SOURCES := date.cpp contact.cpp misc.cpp person.cpp network.cpp test_network.cpp

# Object Files
OBJECTS := $(SOURCES:.cpp=.o)

# The Main Target
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) -pthread -lstdc++fs

# To obtain object files
%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(OBJECTS) $(TARGET)

# Non-File Targets
.PHONY: clean
