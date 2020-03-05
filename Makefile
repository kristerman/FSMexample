SHELL       = /bin/sh
CXX          = /usr/bin/g++

SRC_PATH = src
RELDIR     := src

SRC_EXT = cpp

CXXFLAGS = -std=c++11 -pthread -Wall -Wextra
INCLUDES = -I include/ -I /usr/local/include
LDFLAGS = -pthread
TARGET  = states
SOURCES = $(shell find $(SRC_PATH) -name '*.$(SRC_EXT)' | sort -k 1nr | cut -f2-)
RELOBJS     = $(SOURCES:.cpp=.o)

.PHONY: all default release clean

default: release

all: release

release: releasebuild


##### RELEASE BUILD #############
releasebuild: $(RELOBJS)
		$(CXX)  $(LDFLAGS) -o "$(RELDIR)/$(TARGET)" $^

$(RELDIR)/%.o: %.cpp
		$(CXX) $(INCLUDES) $(CXXFLAGS) -c -o $@ $<

clean:
		$(RM) $(RELOBJS)
		-$(RM) $(RELDIR)/$(TARGET)