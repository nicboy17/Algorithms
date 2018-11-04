CC          =	gcc
# Flags that are sent to the compiler
# Do not change these
CFLAGS      =	-Wall -ansi -pedantic -g

#Directories where the compiler can find things
INCLUDES    = -Iinclude

all : testing program


testing :
	gcc $(CFLAGS) src/linkedList.c src/stack.c src/testing.c -o bin/runTests -Iinclude


program: 
	gcc $(CFLAGS) src/linkedList.c src/stack.c src/simulation.c -o bin/simulation -Iinclude

clean:
	@ rm *.o



