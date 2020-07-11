CC = g++

exec:	main.o graphics.o tris.o
	$(CC)	main.o graphics.o tris.o -o exec -L /usr/local/include/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system
	
graphics.o:	graphics.cpp tris.o
	$(CC)	-c graphics.cpp -I /usr/locale/include/SFML/include

main.o:	main.cpp
	$(CC)	-c main.cpp -I /usr/locale/include/SFML/include

tris.o: tris.cpp
	$(CC)	-c tris.cpp

run:
	export LD_LIBRARY_PATH=/usr/local/lib && ./exec

clean:
	rm graphic.o exec
