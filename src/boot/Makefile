.POSIX:

include $(CONFIG_MK)

OBJECTS = main.o

all: $(OBJECTS)

.c.o:
	$(CC) $(MYCFLAGS) $(INC) -c $<

clean:
	rm -f $(OBJECTS)

.PHONY: all clean