/*
 * A1.h
 *
 *  Created on: May 29, 2014
 *      Author: Katie Brigham, Shawn Vega
 */
/*
 * what do do here:
 * #defines
 * #includes
*/
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
