# Aufruf linux: make -f makefilename <--- bei Windows
# Aufruf win:   mingw32-make -f makefilename
# -B: Build all; Alle Ziele ohne Bedingungen erstellen
#

SCHALTER = g++
SCHALTERADDS = -std=c++2a -Wall -Wextra -O2

main.exe: main.o audio.o 
	$(SCHALTER) $(SCHALTERADDS) -o main.exe main.o audio.o
audio.o: audio.cpp 
	$(SCHALTER) $(SCHALTERADDS) -c -o audio.o audio.cpp
main.o: main.cpp 
	$(SCHALTER) $(SCHALTERADDS) -c -o main.o main.cpp
