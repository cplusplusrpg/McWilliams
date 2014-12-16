CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
CPP_FLAGS := -std=c++11

all: $(OBJ_FILES)
	g++ $(CPP_FLAGS) -o mcwilliams $^

obj/%.o: src/%.cpp
	g++ $(CPP_FLAGS) -c -o $@ $<
