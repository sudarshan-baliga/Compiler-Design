main: demo.o lexer.o readSrc.o parsingTable.o ll1Parser.o
	g++ demo.o lexer.o readSrc.o parsingTable.o ll1Parser.o -o output
lexer: lexer.cpp
	g++ -c lexer.cpp read
reader: readSrc.cpp
	g++ -c readSrc.cpp
parserable: parsingTable.cpp
	g++ -c parsingTable.cpp
parser: ll1Parser.cpp
	g++ -c ll1Parser.cpp
demo: demo.cpp
	g++ -c demo.cpp
clean: 
	rm readSrc.o lexer.o ex.o