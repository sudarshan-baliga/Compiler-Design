main: ex.o lexer.o readSrc.o ex.o
	g++ lexer.o readSrc.o ex.o -o output
lexer: lexer.cpp
	g++ -c lexer.cpp read
reader: readSrc.cpp
	g++ -c readSrc.cpp
ex: ex.cpp
	g++ -c ex.cpp
clean: 
	rm readSrc.o lexer.o ex.o