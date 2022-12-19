CXX=g++
CXXFLAGS=-std=c++14 -Wall -MMD -Werror=vla
OBJECTS=main.o expression.o stack.o
DEPENDS=${OBJECTS:.o=.d} 
EXEC=RPN

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean
clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
