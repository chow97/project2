all: project2.cpp
	g++ -g -o app project2.cpp

run: all
	./app

clean: 
	rm app

