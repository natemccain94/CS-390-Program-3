# Nate McCain
# CS 390
# 10/18/2017
#
# Makefile
#
# Usage:
# 	make -f Makefile	by default make will find this file and
#				build its first target
#
#	make -f Makefile clean	build the clean target
#	make -f Makefile tar	build the tar target
#
########################################################################

main: main.o ProjectThreeFunctions.o
	gcc -o main main.o ProjectThreeFunctions.o

main.o: main.c ProjectThreeFunctions.h
	gcc -c main.c

ProjectThreeFunctions.o: ProjectThreeFunctions.c ProjectThreeFunctions.h
	gcc -c ProjectThreeFunctions.c

clean: 
	rm *.o

tar: 
	tar -cvf main.tar *.c *.h