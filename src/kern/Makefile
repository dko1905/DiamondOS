.POSIX:

include $(CONFIG_MK)

OBJECTS =

all: $(OBJECTS) init

.c.o:
	$(CC) $(MYCFLAGS) -I $(INC) -c $<

init:
	$(MAKE) -C init CONFIG_MK=$(CONFIG_MK) INC="$(INC)" all

clean:
	$(MAKE) -C init CONFIG_MK=$(CONFIG_MK) INC="$(INC)" clean
	rm -f $(OBJECTS)

.PHONY: all clean init
