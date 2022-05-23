CC=g++
flags=-std=c++11 -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self
exe=prog

$(exe): main.o arena.o peleador.o objeto.o fight.o
	$(CC) $(flags) main.o arena.o peleador.o objeto.o fight.o -o $(exe)

main.o: main.cpp
	$(CC) $(flags) -c main.cpp -o main.o

arena.o: arena.cpp arena.h
	$(CC) $(flags) -c arena.cpp -o arena.o

peleador.o: peleador.cpp peleador.h
	$(CC) $(flags) -c peleador.cpp -o peleador.o

objeto.o: objeto.cpp objeto.h
	$(CC) $(flags) -c objeto.cpp -o objeto.o

fight.o: fight.cpp fight.h
	$(CC) $(flags) -c fight.cpp -o fight.o

run: $(exe)
	.\$(exe)

clean:
	del $(exe) *.o