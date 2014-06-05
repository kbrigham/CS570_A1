//============================================================================
// Name        : A1.h
// Author      : Katie Brigham MASC1420, Shawn Vega MASC1440
// Description : Assignment 1, CS570 Summer 2014
//============================================================================

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cerrno>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#ifndef A1_H_
#define A1_H_

void error(std::string msg);
void createShared();
void createSem();
void *printThreadID(void*);
void createThreads(int);
void runProcess();
int main();

#endif /* A1_H_ */
