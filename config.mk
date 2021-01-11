# Version
VERSION = 0.0.0

# Customize to fit your system
PKG_CONFIG = pkg-config

# Paths
PREFIX = /usr/local

# Includes and libs
INCS = #`$(PKG_CONFIG) --cflags zlib`
LIBS = #`$(PKG_CONFIG) --libs zlib`

# Flags
MYCPPFLAGS = -DVERSION=\"$(VERSION)\"
MYCFLAGS = -std=gnu99 -Wall -Wextra -pedantic \
           $(INCS) $(MYCPPFLAGS) $(CPPFLAGS) $(CFLAGS) \
           -ffreestanding -fno-stack-protector -fno-pic -mno-80387 \
           -mno-mmx -mno-3dnow -mno-sse -mno-sse2 -mcmodel=kernel \
           -mno-red-zone -nostdinc -Wno-language-extension-token
MYLDFLAGS = $(LIBS) \
            -Tlinker.ld -static -nostdlib -no-pie
