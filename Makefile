BISON=/usr/local/Cellar/bison/3.0.2/bin/bison

calculator: bison flex all

bison: parse.y
	$(BISON) -d parse.y

flex:
	flex lex.l

all:
	gcc -o calculator main.c parse.tab.c lex.yy.c -ll

clean:
	rm -f parse.tab.*
	rm -f lex.yy.c
	rm -f ./calculator

run:
	./calculator
