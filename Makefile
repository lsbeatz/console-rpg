TARGET = console-rpg.app

CC = gcc
CFLAGS  = -g -Wall -O2
LDFLAGS = 

SOURCEDIR  := src
INCLUDEDIR := src
LIBDIR     := lib
BUILDDIR   := build

SOURCES  := $(shell find $(SOURCEDIR) -name '*.c')
SOURCES  := $(patsubst $(SOURCEDIR)/%.c,%.c,$(SOURCES))
OBJECTS  := $(addprefix $(BUILDDIR)/,$(SOURCES:%.c=%.o))

SUBDIRS  := $(dir $(SOURCES))

.PHONY: all build run clean tags

all: build $(TARGET)

build:
	@mkdir -p $(BUILDDIR)
	@mkdir -p $(BUILDDIR)/$(SUBDIRS)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJECTS) -o $(TARGET)

$(BUILDDIR)/%.o: $(SOURCEDIR)/%.c
	$(CC) $(CFLAGS) $(LDFLAGS) -I$(INCLUDEDIR) -c $< -o $@

run:
	@./$(TARGET)

clean:
	@rm -rf $(BUILDDIR)
	@rm $(TARGET)

tags:
	@ctags -R
