# Compiler
CC := g++

# The Target Binary Program
TARGET := networkApp

# Flags
CFLAGS := -g -Wall -Wextra

# Source Files
SOURCES := date.cpp contact.cpp misc.cpp person.cpp network.cpp test_network.cpp

# Object Files
OBJECTS := $(SOURCES:.cpp=.o)

# The Main Target
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

# To obtain object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(OBJECTS) $(TARGET)

# Non-File Targets
.PHONY: clean
