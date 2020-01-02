VPATH = src
CPPFLAGS = -pthread
CXXFLAGS = -I/usr/include/SDL2 -std=c++17 -Wall -O3
LDLIBS = -lSDL2

OBJECTS = disc.o disc-sim.o display.o model.o renderFillCirc.o

disc_sim : $(OBJECTS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o discs_freeMotion $(OBJECTS) $(LDLIBS)
	rm $(OBJECTS)

disc.o : disc.h display.h
disc-sim.o : display.h model.h
display.o : display.h model.h renderFillCirc.h
model.o : display.h model.h
renderFillCirc.o : renderFillCirc.h

.PHONY : rmobj
rmo :
	rm $(OBJECTS)
