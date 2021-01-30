FLAGS = -Wall -std=c++17
OBJS = obj/main.o obj/Animation.o obj/Directive.o
EXE = main

program: $(OBJS)
	g++ $(OBJS) -o $(EXE)

obj/main.o: main.cxx
	g++ $(FLAGS) -c main.cxx -o obj/main.o

obj/Animation.o: Animation.h Animation.cxx
	g++ $(FLAGS) -c Animation.cxx -o obj/Animation.o

obj/Directive.o : Directives/Directive.cxx
	g++ $(FLAGS) -c Directives/Directive.cxx -o obj/Directive.o

clean:
	rm $(OBJS) $(EXE)
