SCHALTER = g++
SCHALTERADDS = -std=c++2a -Wall -Wextra -O2

main.exe: faculty.o course.o person.o student.o faculty.h student.h course.h person.h
	$(SCHALTER) $(SCHALTERADDS) -o main.exe main.cpp faculty.o course.o person.o student.o

faculty.o: faculty.cpp faculty.h student.h course.h
	$(SCHALTER) $(SCHALTERADDS) -c -o faculty.o faculty.cpp
	
student.o: student.cpp student.h course.h person.h
	$(SCHALTER) $(SCHALTERADDS) -c -o student.o student.cpp

course.o: course.cpp course.h 
	$(SCHALTER) $(SCHALTERADDS) -c -o course.o course.cpp

person.o: person.cpp person.h 
	$(SCHALTER) $(SCHALTERADDS) -c -o person.o person.cpp
