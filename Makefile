CXX = g++
CXXFLAGS = -std=c++11

SRC = Entry.cpp Directory.cpp SingleLineFile.cpp MultiLineFile.cpp Terminal.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

all: terminal

terminal: $(OBJ)
	$(CXX) $(CXXFLAGS) -o terminal $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o terminal
