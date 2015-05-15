CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = cc3k
OBJECTS = main.o map.o cell.o entity.o character.o player.o shade.o drow.o vampire.o troll.o goblin.o mover.o display.o enemy.o human.o dwarf.o elf.o orc.o merchant.o halfling.o dragon.o potion.o gold.o status.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean
clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
