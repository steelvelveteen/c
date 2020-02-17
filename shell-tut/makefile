objs = parser.o line_reader.o main.o

main: $(objs)
	gcc $(objs) -o main

line_reader.o: line_reader.h line_reader.c
	gcc -c line_reader.c

parser.o: parser.h parser.c
	gcc -c parser.c

main.o: main.c
	gcc -c main.c

clean:
	rm $(objs)

clean-all:
	rm $(objs) main
