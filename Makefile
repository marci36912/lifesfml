SFML = ../SFML-2.6.0
LSFML=-L$(SFML)/lib -lsfml-graphics -lsfml-window -lsfml-system
ISFML=-I$(SFML)/include -I$(HEADERS)
BUILD=./build
SRC=./src
HEADERS=./src/headers
COMPILE=g++ -c $< $(ISFML) -o .

life: $(BUILD)/main.o $(BUILD)/grid.o $(BUILD)/gridmanager.o 
	g++ -std=c++17 $^ $(LSFML) -o ./$@ 

$(BUILD)/%.o: $(SRC)/%.cpp 
	$(COMPILE)/$@

clear:
	rm -rf ./life $(BUILD)/*

run:
	export LD_LIBRARY_PATH=$(SFML)/lib && ./life

.PHONY: clear run
