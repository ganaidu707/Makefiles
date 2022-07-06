IDIR =../include

CC=gcc
CFLAGS=-I$(IDIR)

DEPS = $(IDIR)/*.h
OBJ = main.o json.o valgrind.o 

LIBS=-lsqlite3 -ljson-c

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

target: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
		
clean:
	rm -rf	*.o *.db target
