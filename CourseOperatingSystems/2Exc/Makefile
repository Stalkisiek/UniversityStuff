## Makefile
# W nano jesli damy "option" + "P" zobaczymy zaznaczone spacje oraz tabulatory
.SUFFIXES: .c .cpp .o .x .h
DIR = $(notdir $(CURDIR))
SYSNAME = $(shell uname -s)
# Rozbicie na programy i obiekty 
NAME1 = a
EXEC1  = $(NAME1).x  
OBJS1  = $(NAME1).o

NAME2 = b
EXEC2  = $(NAME2).x
OBJS2  = $(NAME2).o

# Flagi kompilacji i linkera
CFLAGS = -Wall -std=c99 -pedantic -O -fPIC
LFLAGS = -Wall -std=c99 -pedantic -O

LDLIBS = -lm

CO = gcc
LD = $(CO)
AR = ar
ARFLAGS = rsv
%.o: %.c %.h
	$(CO) $(CFLAGS) -c $<
%.o: %.c
	$(CO) $(CFLAGS) -c $<

# dla kazdego
.PHONY: all
all: $(EXEC1) $(EXEC2)
$(EXEC1): $(OBJS1) $(LIBS1)
	$(LD) -o $@ $(LFLAGS) $^

$(EXEC2): $(OBJS2) $(LIBS2)
	$(LD) -o $@ $(LFLAGS) $^

# wywolywanie programu
.PHONY: run1 run2

#dodanie argunetow do wywolania
run1: $(EXEC1) $(EXEC2) 

#uruchomienie programu z argumentem
	./$(EXEC1) $(EXEC2) 

run2: $(EXEC2)

# czyszczenie i archiwizacja
.PHONY: clean tar
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out; rm -rf ${LIB_DIR}
# Archiwizacja i kompresja
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
