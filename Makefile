DIRINCLUDE=./include
DIROBJETO=./obj
CC=g++
CFLAGS=-I$(DIRINCLUDE) -g -lSDL

_DEPEND = ""
DEPEND = $(patsubst %,$(DIRINCLUDE)/%,$(_DEPEND))

_OBJETO = main.o
OBJETO = $(patsubst %,$(DIROBJETO)/%,$(_OBJETO))

$(DIROBJETO)/%.o: %.cpp $(DEPEND)
	$(CC) -c -o $@ $< $(CFLAGS)

obj/main.o: main.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

./obj/video_manager.o: video_manager.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

all: main.out

main.out: ./obj/main.o ./obj/video_manager.o
	$(CC) -o ./bin/$@ $^ $(CFLAGS)