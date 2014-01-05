SRCS=gtkplayer.c dkTV.c
OBJS=gtkplayer.o dkTV.o
CFLAGS= -g -I. `pkg-config --cflags --libs gtk+-2.0`
LDFLAGS= `pkg-config --libs gtk+-2.0`

all: clean dkTV
$(OBJS):
	$(CC) $(CFLAGS) -c $(SRCS)
dkTV: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)
clean:
	if [ -f dkTV ]; then rm dkTV; fi;\
	touch dumb.o; rm *o;
