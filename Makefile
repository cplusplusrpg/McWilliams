CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))

all: $(OBJ_FILES)
	g++ -o McWilliams $^

obj/%.o: src/%.cpp
	g++ -c -o $@ $<
