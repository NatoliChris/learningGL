
CC=g++
STD=-std=c++11
LIBS=-lGLEW -lglfw -framework OPENGL

ERRORFLAGS=-Wall -Wextra  -Wparentheses -Wfloat-equal -Wshadow -Wmissing-field-initializers -Wmissing-declarations -Winline -g3
PEDANTIC=-pedantic
FLAGS=$(ERRORFLAGS) $(PEDANTIC)

SRCFILES=src/*.cpp
SRCDIR=src

OUTDIR=bin
OUTFILE=main

default: setup release

setup:
	mkdir -p $(OUTDIR)

normal:
	$(CC) $(STD) $(FLAGS) $(LIBS) $(SRCFILES) -o $(OUTDIR)/normal

debug:
	$(CC) -g3 $(STD) $(FLAGS) $(LIBS) $(SRCFILES) -o $(OUTDIR)/debug

release-debug:
	$(CC) -O3 -g3 $(STD) $(FLAGS) $(LIBS) $(SRCFILES) -o $(OUTDIR)/release-debug

release:
	$(CC) -O3 $(STD) $(FLAGS) $(LIBS) $(SRCFILES) -o $(OUTDIR)/release

all: debug release-debug release
