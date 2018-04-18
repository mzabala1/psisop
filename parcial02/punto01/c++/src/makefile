LDFLAGS=-lpthread

bridgeProblem: main.o bridge.o threadArg.o
	$(CXX) -o $@ $^ -lpthread

main.o: main.cpp bridge.h

bridge.o: bridge.cpp bridge.h

threadArg.o: threadArg.cpp threadArg.h

clean:
	rm -f *.o *.*~ *~ bridgeProblem
