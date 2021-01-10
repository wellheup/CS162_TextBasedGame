CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += O3
LDFLAGS = -lboost_date_time

#you can use either {} or () to contain sets of instructions

OBJS = main.o isValidInput.o menuShell.o Bridge.o CargoBay.o CrewQuarters.o Engines.o EscapePods.o Hydroponics.o Laboratories.o LifeSupport.o OuterSpace.o Item.o Inventory.o Space.o World.o Game.o

SRCS = isValidInput.cpp menuShell.cpp main.cpp Bridge.cpp CargoBay.cpp CrewQuarters.cpp Engines.cpp EscapePods.cpp Hydroponics.cpp Laboratories.cpp LifeSupport.cpp OuterSpace.cpp Item.cpp Inventory.cpp Space.cpp World.cpp Game.cpp

HEADERS = isValidInput.hpp menuShell.hpp Bridge.hpp CargoBay.hpp CrewQuarters.hpp Engines.hpp EscapePods.hpp Hydroponics.hpp Laboratories.hpp LifeSupport.hpp OuterSpace.hpp Item.hpp Inventory.hpp Space.hpp World.hpp Game.hpp

DOCUMENTS = 

#target: dependencies
#	rules to build

main: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o main

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean: ${OBJS}
	rm -f *.o main 

#zip: ${SRCS} ${HEADERS} ${DOCUMENTS}
#	lab9_Wellheuser_Phillip.zip ${HEADERS}${SRCS}${DOCUMENTS}

#all: clean 



