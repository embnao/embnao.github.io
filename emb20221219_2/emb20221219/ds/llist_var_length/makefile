# 文本编译的规则
# 倒序

# 定义变量 $(name)取变量 $@取目标文件 $^所有依赖文件
OBJ=myobj
SRC=main.o dlist.o
CINCLUDE_PATH=./

$(OBJ):$(SRC)
# gcc -o $OBJ $(SRC)
	gcc -o $@ $^ -I$(CINCLUDE_PATH)

# 没有.o文件
main.o:main.c
	gcc -c -o main.o main.c -I$(CINCLUDE_PATH)
dlist.o:dlist.c
	gcc -c -o dlist.o dlist.c -I$(CINCLUDE_PATH)

# 伪目标
clean:
	rm main.o dlist.o obj

