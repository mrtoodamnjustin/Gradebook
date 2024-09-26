# Define compiler and flags
CXX = g++
CPPFLAGS = -I include -Wall

# Define directories
SRC = ./src
BIN = ./build
ODIR = ./build/obj

# Define file names
SRCS = $(SRC)/student.cpp $(SRC)/gradebook.cpp $(SRC)/main.cpp $(SRC)/course.cpp
OBJS = $(SRCS:$(SRC)/%.cpp=$(ODIR)/%.o)

# Define executable output name
EXEC = $(BIN)/Gradebook.exe

# Default target
all: $(BIN) $(ODIR) $(EXEC)

# Create BIN directory if it doesn't exist
$(BIN):
	@if not exist "$(BIN)" ( mkdir "$(BIN)" )

# Create ODIR directory if it doesn't exist
$(ODIR):
	@if not exist "$(ODIR)" ( mkdir "$(ODIR)" )

# Rule to compile the executable
$(EXEC): $(OBJS)
	$(CXX) $(CPPFLAGS) -o $@ $^

# Rule to compile object files
$(ODIR)/%.o: $(SRC)/%.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

# Run target
.PHONY: run
run: all
	$(EXEC)

# Clean rule
.PHONY: clean
clean:
	@if exist "$(ODIR)" ( rmdir /S /Q "$(ODIR)" )
	@if exist "$(BIN)" ( rmdir /S /Q "$(BIN)" )