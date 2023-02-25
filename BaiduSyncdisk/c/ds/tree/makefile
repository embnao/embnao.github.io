main : main.o tree.o
	gcc -o $@ $^ && rm *.o && ./main

edit :
	vim *.c *.h -p

clean :
	rm -rf *.o main

clear :
	rm *.c *.h
