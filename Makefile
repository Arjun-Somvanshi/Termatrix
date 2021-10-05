tmatrix: matrix.o matrix_engine.o libutil.o
	gcc matrix.o matrix_engine.o libutil.o -o tmatrix -lncurses
	rm *.o

matrix_engine.o: matrix_engine.c
	gcc -c matrix_engine.c

libutil.o: libutil.c
	gcc -c libutil.c

matrix.o: matrix.c
	gcc -c matrix.c


clean: 
	rm *.o tmatrix
