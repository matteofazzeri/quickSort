CC=g++
CFLAGS=-I.
DEPS = apa.h
OBJ = mainAPA.o FromFile.o auxFunction.o LVquicksort.o
INPUTFILE = quicksortTest.txt
OUTPUTFILE = results.txt
EXE = toRun

run: $(EXE)
	./$^ $(INPUTFILE)
	python3 plot.py

%.o: %.c $(DEPS)
	clean
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm $(OBJ) $(EXE) $(INPUTFILE) $(OUTPUTFILE) plot.png