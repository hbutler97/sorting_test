CC := $(CROSS_COMPILE)g++

#CFLAGS := -Itclap -Ofast  -std=c++11  -W -Wall -Werror -Wwrite-strings -pedantic
CFLAGS := -Itclap -Ofast  -std=c++11  

LDFLAGS=

SOURCES=$(wildcard *.cpp)
HEADERS=$(wildcard *.h)

OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=sort_test

all: $(SOURCES) $(HEADERS) $(EXECUTABLE)


$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o: 
	$(CC) -c $(CFLAGS) $< -o $@


clean:
	rm *.o
	rm $(EXECUTABLE)



