TARGET = console-rpg.app

CC = gcc
CFLAGS  = -g -Wall -O2
LDFLAGS = -lncurses

SOURCEDIR  := src
INCLUDEDIR := include
LIBDIR     := lib
BUILDDIR   := build

SOURCES  := $(shell find $(SOURCEDIR) -name '*.c')
SOURCES  := $(patsubst $(SOURCEDIR)/%.c,%.c,$(SOURCES))
OBJECTS  := $(addprefix $(BUILDDIR)/,$(SOURCES:%.c=%.o))

SUBDIRS  := $(dir $(SOURCES))
MKDIRS   := $(addprefix $(BUILDDIR)/,$(SUBDIRS))

.PHONY: all build run clean tags

all: build $(TARGET)

build:
	@mkdir -p $(MKDIRS)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LDFLAGS) -o $(TARGET)

$(BUILDDIR)/%.o: $(SOURCEDIR)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -c $< $(LDFLAGS) -o $@

run:
	@./$(TARGET)

clean:
	@rm -rf $(BUILDDIR)
	@rm $(TARGET)

tags:
	@ctags -R
