CC=g++
# Adapt the variables below to your needs:

EXE=snake
CPP= clement/Main.cpp clement/fruit.cpp clement/playground.cpp clement/snake.cpp clement/MainWindowsSDL.cpp
HPP= clement/fruit.hpp clement/playground.hpp clement/snake.hpp clement/MainWindowsSDL.hpp

# The default is build the executable file:
default: $(EXE)

# The executable file must be rebuilt if source files changed:
$(EXE): $(CPP) $(HPP)
	$(CC) $(CPP) -lSDL2 -o $(EXE)

# Run of the (always up-to-date) executable:
run: $(EXE)
	./$(EXE)

# Build the UML diagram as a PNG image:
uml/classes.png: $(HPP)
	./uml/mk_uml.sh $@ $^

# Count the number of lines of code:
nblines:
	@wc -l $(CPP) $(HPP)
