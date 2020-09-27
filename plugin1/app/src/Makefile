CC := gcc
SRCDIR := .
BUILDDIR := ../bin
IFDIR := -I../pluginif
CFLAGS := -g -Wall
DLFLAGS := -ldl
TARGET := $(BUILDDIR)/app
 
SRCEXT := c
SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
DEPS := $(OBJECTS:.o=.deps)
 
$(TARGET): $(OBJECTS)
	@echo " Linking..."; $(CC) $^ -o $(TARGET) $(DLFLAGS)
 
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@echo " CC $<"; $(CC) $(CFLAGS) $(IFDIR) -MD -MF $(@:.o=.deps) -c -o $@ $<
 
clean:
	@echo " Cleaning..."; rm -f $(BUILDDIR)/*.o $(BUILDDIR)/*.deps $(BUILDDIR)/$(TARGET)
 
-include $(DEPS)
 
.PHONY: clean

