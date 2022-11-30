all:
	g++ -g -O2 -pthread -march=native main.cpp -o main.o -lntl -lgmp -lm
	./main.o < input.txt > output.txt
	rm main.o