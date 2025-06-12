CC      := gcc
CFLAGS  := -O3 -mwindows
LDFLAGS := 
LDLIBS  := -lraylib -lgdi32 -lwinmm

TARGET := build/video.exe
BUILD_SRCS = build/main.c build/video.c build/sound.c

all: prepare $(TARGET) run

$(TARGET): $(BUILD_SRCS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

build/sound.c: res/sound.wav | prepare
	( echo "#include \"sound.h\"" ; xxd -n sound_wav -i $< ) > $@

build/video.c: res/video.gif | prepare
	( echo "#include \"video.h\"" ; xxd -n video_gif -i $< ) > $@

prepare:
	mkdir -p build
	cp src/* build/

run: $(TARGET)
	./build/video.exe

clean:
	rm -rf build

.PHONY: all prepare run clean