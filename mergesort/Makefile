CC = gcc-7
CFLAGS = -lm -O3 -Wall -Wextra -Wchkp -Wdouble-promotion -Wmissing-braces -Wparentheses -Wunknown-pragmas -Wunsafe-loop-optimizations -Wconversion -Wlogical-op -Wredundant-decls -fmax-errors=7 -std=c11

# gcc in OS X is linked to clang !
# To use the real gcc change the CC value
# (CC = gcc) -> (CC = gcc-6)
#  ^ clang       ^ gcc
# It seems that clang complains about the '-lm' flag:
# clang: warning: -lm: 'linker' input unused [-Wunused-command-line-argument]

../bin/mergesort: mergesort.o
	$(CC) -o ../bin/mergesort mergesort.o $(CFLAGS)

mergesort.o: mergesort.c
	$(CC) -c mergesort.c  $(CFLAGS)

clean:
	rm *.o
