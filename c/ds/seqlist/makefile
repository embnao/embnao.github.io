variable_1=main
variable_2=seqlist
variable_3=test_
variable_4=$(variable_3)$(variable_1)
variable_5=$(variable_3)$(variable_2)

$(variable_1) : $(variable_1).o $(variable_2).o
	gcc -o $@ $^ && rm -rf *.o && ./$(variable_1)
						  
mycc :
	gcc -o $(variable_1) $(variable_1).c $(variable_2).c
edit :
	vim $(variable_1).c $(variable_2).c $(variable_2).h -p

clean :
	rm -rf *.o $(variable_1)

clear :
	rm -rf $(variable_1).c $(variable_2).c $(variable_2).h

# 分割线===================================================分割线

tedit :
	vim $(variable_1).c $(variable_2).c $(variable_2).h  $(variable_4).c $(variable_5).c $(variable_5).h -p

tclear :
	rm -rf $(variable_1).c $(variable_2).c $(variable_2).h  $(variable_4).c $(variable_5).c $(variable_5).h
