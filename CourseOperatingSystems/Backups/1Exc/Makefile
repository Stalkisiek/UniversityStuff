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
EXEC2 = $(NAME2).x
OBJS2 = $(NAME2).o

NAME3 = c
EXEC3 = $(NAME3).x
OBJS3 = $(NAME3).o

NAME4 = d
EXEC4 = $(NAME4).x
OBJS4 = $(NAME4).o

NAME5 = e
EXEC5 = $(NAME5).x
OBJS5 = $(NAME5).o

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
$(EXEC3): $(OBJS3) $(LIBS3)
	$(LD) -o $@ $(LFLAGS) $^
$(EXEC4): $(OBJS4) $(LIBS4)
	$(LD) -o $@ $(LFLAGS) $^
$(EXEC5): $(OBJS5) $(LIBS5)
	$(LD) -o $@ $(LFLAGS) $^
# wywolywanie poszczegolnych programow wzgledem komend
.PHONY: run1
run1: $(EXEC1)
#$gcc -o $(EXEC1) $(OBJS1)
	./$(EXEC1)

.PHONY: run2
run2: $(EXEC2)
#$gcc -o $(EXEC2) $(OBJS2)
	./$(EXEC2)

.PHONY: run3
run3: $(EXEC3)
#$gcc -o $(EXEC3) $(OBJS3)
	./$(EXEC3); sleep 4
.PHONY: run4
run4: $(EXEC4)
#$gcc -o $(EXEC4) $(OBJS4)
	./$(EXEC4)

.PHONY: run5
run5: $(EXEC5)
#$gcc -o $(EXEC5) $(OBJS5)
	./$(EXEC5)

# czyszczenie i archiwizacja
.PHONY: clean tar
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out; rm -rf ${LIB_DIR}
# Archiwizacja i kompresja
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
