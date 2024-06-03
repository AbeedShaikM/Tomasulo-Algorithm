CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
SRCDIR = .
BUILDDIR = build
TARGET = my_program

SRCS := $(wildcard $(SRCDIR)/**/*.cpp)
SRCS += $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -MMD -MP -c -o $@ $<

clean:
	$(RM) -r $(BUILDDIR) $(TARGET)

-include $(DEPS)
