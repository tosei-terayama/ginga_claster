# Makefile #
OBJS = main.o memory_allocate2d.o initialize.o planet_class.o \
		calc_acce.o middle_point.o update.o
HEADERS = main.h planet_class.h
OPTS = -std=c++1z -O3

main: $(OBJS)
	g++ -o $@ $(OBJS)

%.o: %.cpp $(HEADERS)
	g++ -c $< $(HEADERS) $(OPTS)