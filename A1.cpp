//============================================================================
// Name        : A1.cpp
// Author      : Katie Brigham, Shawn Vega
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "A1.h"

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

void *printThreadID(void* num){
    if((int)num % 2 ==0)
        sleep(2);
    else
        sleep(3);
    //We make sure we're the only ones to have access to the file.
    sem_wait(&sem);
    //then we open it.
    outFile.open ("SHARED.txt", ofstream::app);
	outFile << (int)num << "\r\n"; //write tid to file
	outFile.close(); 
	cout << "Thread " << (int)num << " is running.\n";
    sem_post(&sem);
	pthread_exit(NULL);
}

void createThreads(int threadCount){
	int thread;
	pthread_t threads[threadCount];
    //We create the threads
	for (int i=0; i<threadCount; i++) {
		if ( thread = pthread_create(&threads[i], NULL, &printThreadID, (void*)i) != 0){
			error("An error has occurred creating thread.");
		}
    }
    //We wait for all the threads to finish
    for (int i=0; i<threadCount; i++){
		if (pthread_join(threads[i], NULL) !=0) {
						error("An error has occurred joining thread.");
						exit(1);
		}
	}
}

int main() {
	int threadCount = 10;

	createShared();
	createSem();
	createThreads(threadCount);
	sem_destroy(&sem);
}



