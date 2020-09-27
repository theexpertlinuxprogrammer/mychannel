CC := gcc
SRCDIR := .
BUILDDIR := ../bin
IFDIR := -I../../app/pluginif
CFLAGS := -fPIC -g -Wall
LDFLAGS = -shared
TARGET := $(BUILDDIR)/plugin.so
 
SRCEXT := c
SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
DEPS := $(OBJECTS:.o=.deps)
 
$(TARGET): $(OBJECTS)
	@echo " Linking..."; $(CC) $(LDFLAGS) $^ -o $(TARGET)
 
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@echo " CC $<"; $(CC) $(CFLAGS) $(IFDIR) -MD -MF $(@:.o=.deps) -c -o $@ $<
 
clean:
	@echo " Cleaning..."; rm -f $(BUILDDIR)/*.o $(BUILDDIR)/*.deps $(BUILDDIR)/$(TARGET)
 
-include $(DEPS)
 
.PHONY: clean

