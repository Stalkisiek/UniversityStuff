#
# make: all, clean, tar  
#
#=========================================================================
DIR = `basename $(CURDIR)`
#------------------------
NAME1 = a
FNAME1 = temp.txt
FNAME2 = temp1.txt
#----------------------
EXEC1 = $(NAME1)
OBJS1 = $(NAME1).o
#----------------------
#############################
COFLAGS = -Wall -O
LDFLAGS = -Wall -O
CO = gcc
LD = $(CO)
#############################
%.o: %.c
	$(CO) $(COFLAGS) -c $<
#############################
.PHONY: all
all: $(EXEC1)
#############################
$(EXEC1): $(OBJS1)
	 $(LD) -o $@ $(LDFLAGS) $^
#############################
.PHONY: run
run: $(EXEC1)
	./$(EXEC1) $(FNAME1) $(FNAME2)
	wait
	diff $(FNAME1) $(FNAME2)
#############################
.PHONY: clean tar
# Porzadki
EXECS = $(EXEC1)
clean:                                                     
	rm -f *.o  *~ $(EXECS)
#=========================================================================
# Archiwizacja i kompresja
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
#=========================================================================