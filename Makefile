CC = g++
CFLAGS = -std=c++11 -Wall

# List of header files
HEADER_FILES = hotel.h pet.h room.h reservation.h payment.h

# List of source files
SOURCE_FILES = main.cpp hotel.cpp pet.cpp room.cpp reservation.cpp payment.cpp

# Object files
OBJECTS = $(patsubst %.cpp,obj/%.o,$(SOURCE_FILES))

# Executable name
EXECUTABLE = main

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE)

obj/%.o: %.cpp $(HEADER_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

