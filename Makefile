INCLUDE := -I ./include/
LIBRARY := -lncurses
#FILES   := src/core/core.c  src/core/console.c src/core/pstring.c src/core/ram.c src/core/ram.c src/core/util.c src/core/console_shell.c
FILES   := src/core/console.c src/core/core.c src/core/pstring.c src/core/ram.c src/core/util.c
LINKS   := console.o core.o pstring.o ram.o util.o


ALL:
	$(CC) -c $(INCLUDE) $(LIBRARY) $(FILES)
	$(CC) $(INCLUDE) $(LIBRARY) $(LINK) src/app.c -o paw
clean:
	rm -rf *.o