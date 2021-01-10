.POSIX:

include $(CONFIG_MK)

OBJECTS = main.o

all: diamond.elf

.c.o:
	$(CC) $(MYCFLAGS) $(INC) -c $<

boot:
	$(MAKE) -C boot CONFIG_MK=$(CONFIG_MK) INC="$(INC)" all

diamond.elf: $(OBJECTS)
	$(LD) $(MYLDFLAGS) $(OBJECTS) -o diamond.elf

clean:
	$(MAKE) -C boot CONFIG_MK=$(CONFIG_MK) INC="$(INC)" clean
	rm -f diamond.elf $(OBJECTS)

.PHONY: all clean boot
