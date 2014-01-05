SRCS=gtkplayer.c gtkplayertester.c
OBJS=gtkplayer.o gtkplayertester.o
CFLAGS= -g -I. `pkg-config --cflags --libs gtk+-2.0`
LDFLAGS= `pkg-config --libs gtk+-2.0`

all: clean gtkplayertester
$(OBJS):
	$(CC) $(CFLAGS) -c $(SRCS)
gtkplayertester: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)
clean:
	if [ -f gtkplayertester ]; then rm gtkplayertester; fi;\
	touch dumb.o; rm *o;
