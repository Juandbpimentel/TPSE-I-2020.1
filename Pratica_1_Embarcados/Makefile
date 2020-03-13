all: app

app: Projeto.o cinema.o compartilhadas.o geresessoes.o
	gcc obj/Projeto.o obj/cinema.o obj/compartilhadas.o obj/geresessoes.o -o bin/app.out
	gcc obj/Projeto.o obj/cinema.o obj/compartilhadas.o obj/geresessoes.o -o bin/app.exe

Projeto.o: src/Projeto.c
	gcc -c src/Projeto.c -Iinc -o obj/Projeto.o

cinema.o: src/cinema.c
	gcc -c src/cinema.c -Iinc -o obj/cinema.o

compartilhadas.o: src/compartilhadas.c
	gcc -c src/compartilhadas.c -Iinc -o obj/compartilhadas.o

geresessoes.o: src/geresessoes.c
	gcc -c src/geresessoes.c -Iinc -o obj/geresessoes.o

clean:
	rm obj/Projeto.o obj/cinema.o obj/compartilhadas.o obj/geresessoes.o bin/app.exe bin/app.out