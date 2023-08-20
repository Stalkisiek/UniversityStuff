## Makefile
# W nano jesli damy "option" + "P" zobaczymy zaznaczone spacje oraz tabulatory
.SUFFIXES: .c .cpp .o .x .h
DIR = $(notdir $(CURDIR))
SYSNAME = $(shell uname -s)
# Rozbicie na programy i obiekty 
CHECK = signalChecker
CHECKEXEC  = $(CHECK).x
CHECKOBJS = $(CHECK).o

NAME1 = a
EXEC1  = $(NAME1).x  
OBJS1  = $(NAME1).o

NAME2 = b
EXEC2  = $(NAME2).x
OBJS2  = $(NAME2).o

###Program 3

NAME3 = c
EXEC3  = $(NAME3).x
OBJS3  = $(NAME3).o

NAME4 = help1
EXEC4  = $(NAME4).x
OBJS4  = $(NAME4).o


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
all: $(EXEC1) $(CHECKEXEC) $(EXEC2) $(EXEC3) $(EXEC4) $(EXEC5)
$(EXEC1): $(OBJS1) $(LIBS1)
	$(LD) -o $@ $(LFLAGS) $^

$(CHECKEXEC): $(CHECKOBJS) $(CHECKLIBS)
	$(LD) -o $@ $(LFLAGS) $^

$(EXEC2): $(OBJS2) $(LIBS2)
	$(LD) -o $@ $(LFLAGS) $^

$(EXEC3): $(OBJS3) $(LIBS3)
	$(LD) -o $@ $(LFLAGS) $^

$(EXEC4): $(OBJS4) $(LIBS4)
	$(LD) -o $@ $(LFLAGS) $^



# wywolywanie programu
.PHONY: run1 run2

#dodanie argumentow do wywolania
PROCESS := $(word 2,$(MAKECMDGOALS))
SIGNAL := $(word 3,$(MAKECMDGOALS))
run1: $(EXEC1) 

#uruchomienie programu z argumentem
	./$(EXEC1) $(PROCESS) $(SIGNAL)

#run2: $(EXEC2) $(EXEC1)
#	./$(EXEC2) $(PROCESS) $(SIGNAL)
run2: $(EXEC2) $(EXEC1)
	gcc $(NAME2).c -o $(NAME2).x
	#gcc $(NAME1).c -o $(NAME1).x
	./$(EXEC2) $(PROCESS) $(SIGNAL)

.PHONY: run3

HOWMANY = $(word 4,$(MAKECMDGOALS))

run3: $(EXEC3) $(EXEC1) $(EXEC4)
	gcc $(NAME3).c -o $(NAME3).x
	clear
	./$(EXEC3) $(HOWMANY) $(PROCESS) $(SIGNAL)

.PHONY: check
#uruchomienie programu check
check: $(CHECKEXEC)
	gcc $(CHECK).c -o $(CHECK).x
	./$(CHECKEXEC) 


# czyszczenie i archiwizacja
.PHONY: clean tar
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out; rm -rf ${LIB_DIR}
# Archiwizacja i kompresja
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
