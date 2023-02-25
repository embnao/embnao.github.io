var_1=main
var_2=seqlist

$(var_1) : $(var_1).o $(var_2).o
	gcc -Wall -o $@ $^ && rm -rf *.o && ./$(var_1)

edit :
	vim *.c *.h -p

clean :
	rm -rf *.o $(var_1)
