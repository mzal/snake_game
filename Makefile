CXX = g++
CXXFLAGS = -Wall -g
LIB = -lsfml-graphics -lsfml-window -lsfml-system
OBJS = main.o snake.o fruit.o

all: Snake

Snake: $(OBJS)
	$(CXX) $(CXXFLAGS) -o Snake $(OBJS) $(LIB)

main.o: main.cpp snake.hpp fruit.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp
snake.o: snake.hpp fruit.hpp
fruit.o: fruit.hpp

clean:
	rm $(OBJS)
