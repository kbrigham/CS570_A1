//============================================================================
// Name        : A1.cpp
// Author      : Katie Brigham
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "A1.h"

//
//#include <iostream>
//#include <fstream>
//#include <stdlib.h>
//#include <cerrno>
//#include <semaphore.h>
//#include <pthread.h>

using namespace std;
sem_t sem;
ofstream outFile;

void error(std::string msg) {
	std::cerr << "Error " << errno << " - " << msg << "\n";
}
void createShared(){
	outFile.open ("SHARED.txt");
	outFile << (int)getpid() << "\r\n";
	outFile.close();
}
void createSem(){
	if (sem_init(&sem, 0, 1) !=0) {
		error("Error creating semaphore");
		exit(1);
	}
}
void createThreads(int threadCount){
	int thread;
	pthread_t threads[threadCount];
	for (int i=0; i<threadCount; i++) {
		if ( thread = pthread_create(&threads[i], NULL, &printThreadID, (void*)i) != 0){
			error("An error has occurred creating thread.");
		}
		if (pthread_join(threads[i], NULL) !=0) {
						error("An error has occurred joining thread.");
						exit(1);
		}
		exit(1);
	}
}
void printThreadID(void* num){
    outFile.open ("SHARED.txt");
	outFile << (int)getpid() << "\r\n";
	outFile.close();
	cout << "Thread " << (int)num << " is running.\n";
	exit(0);
}
void runProcess(){
	//if thread is even
	//sem_wait every 2
		printThreadID();
	//if thread is odd
	//sem_wait every 3
		printThreadID()

	}
int main() {
	int threadcount = 10;

	createShared();
	createSem();
	createThreads(threadCount);
	runProcess();
	sem_destroy();
}



