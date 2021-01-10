.POSIX:

include $(CONFIG_MK)

OBJECTS = main.o

all: program

.c.o:
	$(CC) $(MYCFLAGS) -I $(INC) -c $<

hello:
	$(MAKE) -C hello CONFIG_MK=$(CONFIG_MK) INC=$(INC) all

program: $(OBJECTS) hello
	$(CC) $(OBJECTS) hello/*.o -o program $(MYLDFLAGS)

clean:
	$(MAKE) -C hello CONFIG_MK=$(CONFIG_MK) INC=$(INC) clean
	rm -f program $(OBJECTS)

.PHONY: all clean hello
