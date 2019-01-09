
DEPENDS = .depend

CC = g++
CCFLAGS = -O2 -Wall -MMD

# What we're generating

OBJECTS = calc.o main.o

MAINFILE = main

.SUFFIEXES: .c .o

.cpp.o:
	$(CC) $(CCFLAGS) -c $<

# the stuff


$(MAINFILE):	$(OBJECTS)
		$(CC) $(CCFLAGS) $(OBJECTS) -o $@ $(LIBRARIES)

.PHONY: clean
clean:
	rm -f $(OBJECTS) \
	touch $(DEPENDS)

.PHONY: distclean
distclean:
	rm -f $(OBJECTS) $(MAINFILE) \
	touch $(DEPENDS)
