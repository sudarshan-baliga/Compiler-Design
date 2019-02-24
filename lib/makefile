lexer_output: lexer.o readSrc.o
	g++ lexer.o readSrc.o -o output
lexer: lexer.cpp
	g++ -c lexer.cpp
reader: readSrc.cpp
	g++ -c readSrc.cpp
clean: 
	rm readSrc.o lexer.o