run: main
	./main

main: main.o cryptage.o decryptage.o
	gcc -o main main.o cryptage.o decryptage.o -Wall

cryptage.o: cryptage.c cryptage.h
	gcc -c -Wall cryptage.c
	
decryptage.o: decryptage.c decryptage.h
	gcc -c -Wall decryptage.c

main.o: main.c cryptage.h decryptage.h
	gcc -c -Wall main.c

clean:
	rm -f main
	rm *.o
