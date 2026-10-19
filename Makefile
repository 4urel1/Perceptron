Main: main.c perceptron.o dataset.o
	gcc -g main.c perceptron.o dataset.o -o main -Wall -Wextra


dataset.o: dataset.c dataset.h
	gcc -g -Wall -Wextra dataset.c -c -o dataset.o

perceptron.o: perceptron.c perceptron.h
	gcc -g -Wall -Wextra perceptron.c -c -o perceptron.o


clean:
	rm -f *.o
	rm -f main