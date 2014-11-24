calculator: bison flex all

bison: parse.y
	bison -d parse.y

flex:
	flex lex.l

all:
	gcc -o calculator parse.tab.c lex.yy.c -ll

clean:
	rm -f parse.tab.*
	rm -f lex.yy.c
	rm -f ./calculator

run:
	./calculator
