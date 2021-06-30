bin/main: header/color.hpp src/main.o src/menu.o header/text.o src/message.o
	mkdir -p bin
	g++ -o bin/main src/main.o src/menu.o header/text.o src/message.o -lncurses -std=c++14

src/main.o:src/main.cpp
	g++ -c -o src/main.o src/main.cpp

src/menu.o:src/menu.cpp src/menu.hpp
	g++ -c -o src/menu.o src/menu.cpp

header/text.o:header/text.hpp header/text.cpp
	g++ -c -o header/text.o header/text.cpp

src/message.o:src/message.cpp src/message.hpp
	g++ -c -o src/message.o src/message.cpp

clean:
	rm -rf src/*.o
	rm -rf header/*.o
	rm -rf *.o
