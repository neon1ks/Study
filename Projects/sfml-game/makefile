CC = g++
CPPFLAGS = -Wall -g `pkg-config sfml-all --cflags`
LDFLAGS = `pkg-config sfml-all --libs` -lm
SRCS = sfml-game.cpp player.cpp view.cpp map.cpp mission.cpp
OBJS = $(SRCS:.cpp=.o)
EXECUTABLE = sfml-game

.PHONY: clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) -o $(EXECUTABLE) $(OBJS) $(LDFLAGS)

clean:
	rm -f $(OBJS) $(EXECUTABLE)

