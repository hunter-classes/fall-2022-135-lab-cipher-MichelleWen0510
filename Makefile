main: main.o caesar.o decrypt.o
	g++ -o main main.o caesar.o decrypt.o

tests: tests.o caesar.o decrypt.o
	g++ -o tests tests.o caesar.o decrypt.o

caesar.o: caesar.cpp caesar.h decrypt.h

decrypt.o: decrypt.cpp decrypt.h

main.o: main.cpp caesar.h

tests.o: tests.cpp doctest.h caesar.h

clean:
	rm -f *.o
	rm main
