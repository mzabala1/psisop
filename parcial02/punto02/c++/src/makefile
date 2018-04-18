LDFLAGS=-lpthread
CXXFLAGS=-std=c++11
batch: batch.o card.o line.o util.o concurrency.o
	$(CXX) -o $@ $^ -lpthread

batch.o: batch.cpp card.h line.h

card.o: card.cpp card.h

line.o: line.cpp line.h card.h

util.o: util.cpp util.h card.h line.h

concurrency.o: concurrency.cpp concurrency.h card.h line.h

clean:
	rm -f *.o *.cpp~ *.h~ batch
