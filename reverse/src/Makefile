CC := gcc
SRCDIR := .
BUILDDIR := ../bin
CFLAGS := -g -Wall
TARGET := $(BUILDDIR)/reverse
 
SRCEXT := c
SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
DEPS := $(OBJECTS:.o=.deps)

all: $(TARGET)
$(TARGET): $(OBJECTS)
	@echo " Linking..."; $(CC) $(CFLAGS) $^ -o $(TARGET)
 
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@echo " CC $<"; $(CC) $(CFLAGS) -MD -MF $(@:.o=.deps) -c -o $@ $<
 
clean:
	@echo " Cleaning..."; rm -f $(BUILDDIR)/*.o $(BUILDDIR)/*.deps $(BUILDDIR)/$(TARGET)
 
-include $(DEPS)
 
.PHONY: clean
