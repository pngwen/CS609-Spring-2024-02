TARGETS=static_test hourglass_test circle_test

CXXFLAGS=-g `pkg-config sdl2 --cflags`
LDLIBS=`pkg-config sdl2 --libs`
CXX=g++
LD=g++
CC=g++

all: $(TARGETS)
static_test: canvas.o drawable.o static.o static_test.o
hourglass_test: canvas.o drawable.o hourglass.o hourglass_test.o
circle_test: canvas.o drawable.o circle.o circle_test.o
rectangle_test: canvas.o drawable.o rectangle.o rectangle_test.o

clean:
	rm -f $(TARGETS) *.o