VPATH = src
CPPFLAGS = -I/usr/include/SDL2
CXXFLAGS = -std=c++17
LDLIBS = -lSDL2

OBJECTS = disc.o disc-sim.o display.o fillCirc.o

disc_sim : $(OBJECTS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o disc_sim $(OBJECTS) $(LDLIBS)
	rm $(OBJECTS)

disc.o : disc.h
disc-sim.o : fillCirc.h
display.o : display.h
fillCirc.o : fillCirc.h

.PHONY : rmobj
rmobj :
	rm $(OBJECTS)
