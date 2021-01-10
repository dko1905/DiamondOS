.POSIX:

include config.mk

all: options program

options:
	@echo Program build options:
	@echo "CFLAGS  = $(MYCFLAGS)"
	@echo "LDFLAGS = $(MYLDFLAGS)"
	@echo "CC      = $(CC)"

program:
	$(MAKE) -C src CONFIG_MK="`pwd`/config.mk" INC="`pwd`" all
	cp src/program program

clean:
	rm -f program
	$(MAKE) -C src CONFIG_MK="`pwd`/config.mk" INC="`pwd`" clean

.PHONY: all options program clean
