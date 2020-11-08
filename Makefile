CXX = gcc
# Update these paths to match your installation
# You may also need to update the linker option rpath, which sets where to look for
# the SDL2 libraries at runtime to match your install
SDL_LIB = -L/usr/local/lib -lSDL2 -Wl,-rpath=/usr/local/lib
SDL_INCLUDE = -I/usr/local/include
# You may need to change -std=c++11 to -std=c++0x if your compiler is a bit older
CXXFLAGS = -c -Wall $(SDL_INCLUDE)
LDFLAGS = $(SDL_LIB)
EXE = main.x

all: $(EXE)

$(EXE): main.o cpu.o opcodes.o graphics.o sdl_helper_functions.o
	$(CXX) main.o cpu.o opcodes.o graphics.o sdl_helper_functions.o $(LDFLAGS) -o $@

main.o: main.c mem.h cpu.h opcodes.h graphics.h
	$(CXX) $(CXXFLAGS) main.c -o main.o

cpu.o: cpu.c cpu.h mem.h opcodes.h graphics.h
	$(CXX) $(CXXFLAGS) cpu.c -o cpu.o

opcodes.o: opcodes.c opcodes.h cpu.h mem.h
	$(CXX) $(CXXFLAGS) opcodes.c -o opcodes.o

graphics.o: graphics.c sdl_helper_functions.h

sdl_helper_functions.o: sdl_helper_functions.c
	$(CXX) $(CXXFLAGS) $< -o sdl_helper_functions.o

clean:
	rm *.o && rm $(EXE)