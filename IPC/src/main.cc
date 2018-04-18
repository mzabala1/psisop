#ifndef __SIMPLESEMAPHORE_H_
#include <SimpleSemaphore.h>
#define __SIMPLESEMAPHORE_H_
#endif

#ifndef __SHAREDMEMORY_H_
#include <SharedMemory.h>
#define __SHAREDMEMORY_H_
#endif

#ifndef __IOSTREAM__
#include <iostream>
#define __IOSTREAM__
#endif


int main() {
	SimpleSemaphore sem("/sem");
	SharedMemory<int> sm("/mem");
	int &i = sm();

	cerr << "Esperando por el Wait" << endl;
	sem.Wait();
	cerr << "Ingresé a la sección crítica" << endl;
	sleep(10);
	i++;
	sem.Signal();
	cerr << "Terminé la sección crítica" << endl;
	cerr << "i: " << i << endl;
	return 0;
}
