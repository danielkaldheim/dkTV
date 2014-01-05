SRCS=gtkplayer.c dktv.c
OBJS=gtkplayer.o dktv.o
CFLAGS= -g -I. `pkg-config --cflags --libs gtk+-2.0`
LDFLAGS= `pkg-config --libs gtk+-2.0`

all: clean dktv
$(OBJS):
	$(CC) $(CFLAGS) -c $(SRCS)
dktv: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)
clean:
	if [ -f dktv ]; then rm dktv; fi;\
	touch dumb.o; rm *o;
