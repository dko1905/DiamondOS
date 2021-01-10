.POSIX:

include $(CONFIG_MK)

OBJECTS = main.o

all: program

.c.o:
	$(CC) $(MYCFLAGS) -I $(INC) -c $<

boot:
	$(MAKE) -C boot CONFIG_MK=$(CONFIG_MK) INC=$(INC) all

program: $(OBJECTS) boot
	$(CC) $(OBJECTS) boot/*.o -o program $(MYLDFLAGS)

clean:
	$(MAKE) -C boot CONFIG_MK=$(CONFIG_MK) INC=$(INC) clean
	rm -f program $(OBJECTS)

.PHONY: all clean boot
