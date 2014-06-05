###########################################################
# Makefile for CS570 Assignment #1
# File Name     : makefile
# Author        : Katie Brigham, Shawn Vega
# Class Accounts: masc1440
# Class         : CS 530, Fall 2013
# Assignment    : Assignment 1
# Version       : 0.1
# Copyright     : copyright 2014
# Description   : Programming Assignment 1 in C++
###########################################################
EXEC =sem
CC =g++
SOURCES=A1.cpp
FLAGS= -lpthread -lposix4

$(EXEC): 
	$(CC) -o $(EXEC) $(SOURCES) $(FLAGS)
	rm -f *.o

clean:
	rm -f *.o core a.out $(EXEC)

#######################[ EOF: Makefile ]###################