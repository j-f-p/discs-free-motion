VPATH = src
CPPFLAGS = -pthread
CXXFLAGS = -I/usr/include/SDL2 -std=c++17 -Wall -O2
LDLIBS = -lSDL2

OBJECTS = disc.o disc-sim.o display.o renderFillCirc.o model.o

disc_sim : $(OBJECTS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o disc_sim $(OBJECTS) $(LDLIBS)
	rm $(OBJECTS)

disc.o : disc.h
disc-sim.o : model.h
display.o : display.h model.h
renderFillCirc.o : renderFillCirc.h
model.o : model.h

.PHONY : rmobj
rmobj :
	rm $(OBJECTS)
