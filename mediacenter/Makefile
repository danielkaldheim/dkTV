CC=g++
SRCS=main.cpp
OBJS=mediacenter
CFLAGS= `sdl2-config --cflags --libs`

all: clean mediacenter
$(OBJS):
		$(CC) $(SRCS) $(CFLAGS) -o $(OBJS)
clean:
		if [ -f mediacenter ]; then rm mediacenter; fi;\
		touch dumb.o; rm *o;
