all:  paxic pvm

paxic: paxic.o paxi_parser.tab.o lex.yy.o hash_table.o string_list.o
	gcc -o paxic paxic.o paxi_parser.tab.o lex.yy.o hash_table.o string_list.o
	
paxi_parser.tab.c: paxi_parser.y hash_table.o
	bison -d paxi_parser.y

pvm: pvm.o
	gcc -o pvm pvm.o

%.o: %.c
	gcc -O0 -g -o $@ -c $<
	
lex.yy.c: paxi_scanner.l
	flex paxi_scanner.l

clean:
	rm -f *.o  paxic pvm hash_table_driver 
