CXX = g++
CXXFLAGS = -std=c++14 -Werror=vla -MMD -g
OBJECTS = main.o cell.o chamber.o character.o defense.o door.o dragonhoard.o drow.o dwarf.o elf.o enemy.o generate.o goblin.o gold.o grid.o halfing.o hp.o human.o item.o merchant.o merchantgold.o normalgold.o offence.o orc.o passageway.o player.o potion.o shade.o smallgold.o stairway.o subject.o tile.o troll.o vampire.o wall.o
DEPENDS = ${OBJECTS .o=.d}
EXEC = cc3k

$EXEC:${OBJECTS}
		${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean
clean:
	rm ${OBJECTS} ${EXEC}
