VPATH = src
CPPFLAGS = -I/usr/include/SDL2
CXXFLAGS = -std=c++17
LDLIBS = -lSDL2

OBJECTS = disc-sim.o

disc_sim : $(OBJECTS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o disc_sim $(OBJECTS) $(LDLIBS)
	rm $(OBJECTS)

.PHONY : rmobj
rmobj :
	rm $(OBJECTS)
