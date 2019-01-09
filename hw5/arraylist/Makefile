
DEPENDS = .depends

CC = gcc
#CCFLAGS = -O2 -march=pentium3 -Wall -MMD
#CCFLAGS = -O2 -march=pentium4 -Wall -MMD
CCFLAGS = -std=c99 -g3 -march=pentium3 -Wall -MMD -MF $(DEPENDS) -DMALLOC_CHECK_=1

INCLUDES = -I.

# What we're generating

MAIN_SOURCE = al_test.c arraylist.c compare_func.c print_func.c

SOURCE = $(MAIN_SOURCE)

MAINFILE = main

.SUFFIXES: .c .o

.c.o:
	$(CC) $(INCLUDES) $(CCFLAGS) -c $<

# the stuff

OBJECTS = $(SOURCE:.c=.o)

$(MAINFILE):	$(OBJECTS)
		$(CC) $(INCLUDES) $(CCFLAGS) $(OBJECTS) -o $@ $(LIBRARIES)

.PHONY: clean
clean:
	rm -f $(OBJECTS)
	touch $(DEPENDS)

.PHONY: distclean
distclean:
	rm -f $(OBJECTS) $(MAINFILE)
	touch $(DEPENDS)

include $(DEPENDS)
