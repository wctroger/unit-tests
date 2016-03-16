EXEC = bin-swap bin-bubble
.PHONY: all
all: $(EXEC)

CC ?= gcc
CFLAGS = -std=gnu99 -Wall -O2 -g
LDFLAGS =

OBJS := \
	swap.o \
	bubble.o \
	stub.o

RES := \
	result-bubble \
	result-swap

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

bin-%: %.o stub.o
	$(CC) -o $@ $^ $(LDFLAGS)

check: $(EXEC)
	bash test-swap.sh data-swap.in result-swap
	bash test-bubble.sh data-bubble.in result-bubble

clean:
	$(RM) $(EXEC) $(OBJS) $(RES)
