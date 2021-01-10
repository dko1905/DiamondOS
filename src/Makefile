.POSIX:

include $(CONFIG_MK)

OBJECTS = main.o

all: diamond.elf

.c.o:
	$(CC) $(MYCFLAGS) $(INC) -c $<

kern:
	$(MAKE) -C kern CONFIG_MK=$(CONFIG_MK) INC="$(INC)" all

diamond.elf: $(OBJECTS) kern
	$(LD) $(MYLDFLAGS) `find . -iname "*.o" -printf "%p "` -o diamond.elf

clean:
	$(MAKE) -C kern CONFIG_MK=$(CONFIG_MK) INC="$(INC)" clean
	rm -f diamond.elf $(OBJECTS)

.PHONY: all clean kern
