# Variables
CXX = g++
CXXFLAGS = -Wall -std=c++14
LIBNAME = IdealHotelShowerLib
EXE = IdealHotelShower
SRC_LIB = IdealHotelShower.cpp
SRC_EXE = main.cpp

# Object files
OBJ_LIB = $(SRC_LIB:.cpp=.o)
OBJ_EXE = $(SRC_EXE:.cpp=.o)

# Build rules
all: $(EXE)

# Build the shared library
$(LIBNAME).dll: $(OBJ_LIB)
	$(CXX) -shared $(OBJ_LIB) -o $(LIBNAME).dll

$(LIBNAME).so: $(OBJ_LIB)
	$(CXX) -shared $(OBJ_LIB) -o $(LIBNAME).so

# Rule to build the executable
$(EXE): $(OBJ_EXE) $(LIBNAME).dll
	$(CXX) $(CXXFLAGS) $(OBJ_EXE) -L. -l:$(LIBNAME).dll -o $(EXE)

# Generic rule for building object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -fPIC

# Rule to clean object, executable, and library files
clean:
	rm -f $(OBJ_LIB) $(OBJ_EXE) $(EXE) $(LIBNAME).dll $(LIBNAME).so
