CC=g++
CFLAGS=-I.
DEPS = apa.h
OBJ = mainAPA.o FromFile.o auxFunction.o LVquicksort.o
OUTPUTFILE = results.txt
EXE = toRun

run: $(EXE)
	./$^ $(OUTPUTFILE)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm $(OBJ) $(EXE) $(OUTPUTFILE) plot.png