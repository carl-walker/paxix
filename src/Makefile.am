#! Flags passed to the compiler
AM_CFLAGS = -Wpedantic -Wall -std=c99
AM_LDFLAGS = 
AM_YFLAGS = -d -t
AM_LFLAGS =


#! Setup (must be listed BEFORE the program sources)
SUFFIXES = .c .h .y .l
BUILT_SOURCES = paxi_parser.h
CLEANFILES = paxi_parser.h paxi_parser.c paxi_scanner.c
EXTRA_DIST = string_list.h symbol_table.h


#! List of binaries to produce
bin_PROGRAMS = paxic pvm
paxic_SOURCES = paxic.c string_list.c symbol_table.c paxi_parser.y paxi_scanner.l
paxic_LDD = -ly -lfl

pvm_SOURCES = pvm.c

