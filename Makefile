LIB_SOURCES=$(wildcard lib/**/*.c lib/*.c)
LANG_SOURCES=lex.yy.c parse.tab.c main.c

BISON=/usr/local/Cellar/bison/3.0.2/bin/bison

calculator: bison flex all

bison: parse.y
	$(BISON) -d parse.y

flex:
	flex lex.l

all:
	$(CC) -o calculator $(LIB_SOURCES) $(LANG_SOURCES) -ll

clean:
	rm -f parse.tab.*
	rm -f lex.yy.c
	rm -f ./calculator

run:
	./calculator
