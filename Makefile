# Compiler and flags
CC      := gcc

ifeq ($(OS),Windows_NT)
	EXE     := .exe
	LDLIBS  := -lraylib -lgdi32 -lwinmm
	CFLAGS  := -O3 -mwindows
else
	EXE     :=
	LDLIBS  := -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
	CFLAGS  := -O3
endif

TARGET      := build/video$(EXE)
BUILD_SRCS  := build/main.c build/video.c build/sound.c

all: prepare $(TARGET) run

$(TARGET): $(BUILD_SRCS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

build/sound.c: res/sound.wav | prepare
	( echo "#include \"sound.h\"" ; xxd -n sound_wav -i $< ) > $@

build/video.c: res/video.gif | prepare
	( echo "#include \"video.h\"" ; xxd -n video_gif -i $< ) > $@

prepare:
	mkdir -p build
	cp src/* build/

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf build

.PHONY: all prepare run clean
