output: main.o ./lib/lexer.o ./lib/readSrc.o ./lib/parsingTable.o ./lib/ll1Parser.o
	g++ main.o ./lib/lexer.o ./lib/readSrc.o ./lib/parsingTable.o ./lib/ll1Parser.o -o output
lexer: ./lib/lexer.cpp
	g++ -c ./lib/lexer.cpp read
reader: ./lib/readSrc.cpp
	g++ -c ./lib/readSrc.cpp
parserable: ./lib/parsingTable.cpp
	g++ -c ./lib/parsingTable.cpp
parser: ./lib/ll1Parser.cpp
	g++ -c ./lib/ll1Parser.cpp
main: main.cpp
	g++ -c main.cpp
clean: 
	rm ./lib/output.o ./lib/readSrc.o ./lib/lexer.o ./lib/parsingTable.o ./lib/ll1Parser.o ./output 2> /dev/null
