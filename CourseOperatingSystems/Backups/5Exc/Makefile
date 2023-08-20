DIR = `basename $(CURDIR)`
FIFO = /tmp/myfifo
NAME1 = zad5a
NAME2 = producent
NAME3 = konsument
EXEC1 = $(NAME1)
OBJS1 = $(NAME1).o
EXEC2 = $(NAME2)
OBJS2 = $(NAME2).o
EXEC3 = $(NAME3)
OBJS3 = $(NAME3).o

COFLAGS = -Wall
LDFLAGS = -Wall
CO = gcc
LD = $(CO)

%.o: %.c
	$(CO) $(COFLAGS) -c $<

.PHONY: all
all: $(EXEC1) $(EXEC2) $(EXEC3)

$(EXEC1): $(OBJS1)
	$(LD) -o $@ $(LDFLAGS) $^

$(EXEC2): $(OBJS2)
	$(LD) -o $@ $(LDFLAGS) $^

$(EXEC3): $(OBJS3)
	$(LD) -o $@ $(LDFLAGS) $^

.PHONY: run1
run1: $(EXEC1)
	./$(EXEC1) $(ARGS)
	wait
	diff $(ARGS)

.PHONY: run2
run2: $(EXEC2) $(EXEC3)
	rm -f ./$(dst)
	if test ! -p $(FIFO); then \
		mkfifo -m 0666 $(FIFO); \
	fi
	xterm -hold -title $(NAME2) -e ./$(EXEC2) ./$(src) $(FIFO) &
	xterm -hold -title $(NAME3) -e ./$(EXEC3) ./$(dst) $(FIFO)
	clear
	wait
	diff ./$(src) ./$(dst)
	rm $(FIFO)

.PHONY: clean
clean:
	rm -f *.o *~ $(EXEC1) $(EXEC2) $(EXEC3)

.PHONY: tar
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz $(DIR))
