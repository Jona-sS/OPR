# Aufruf linux: make -f makefilename <--- bei Windows
# Aufruf win:   mingw32-make -f makefilename
# -B: Build all; Alle Ziele ohne Bedingungen erstellen
#

SCHALTER = g++
SCHALTERADDS = -std=c++2a -Wall -Wextra -O2

game.exe: Game.o ComputerPlayer.o HumanPlayer.o RockPaperScissor_nosolution.o ShapeGenerator.o utils.o
	$(SCHALTER) $(SCHALTERADDS) -o game.exe Game.o ComputerPlayer.o HumanPlayer.o RockPaperScissor_nosolution.o ShapeGenerator.o utils.o

RockPaperScissor_nosolution.o: RockPaperScissor_nosolution.cpp Game.h
	$(SCHALTER) $(SCHALTERADDS) -c -o RockPaperScissor_nosolution.o RockPaperScissor_nosolution.cpp

Game.o: Game.cpp Game.h utils.h HumanPlayer.h ComputerPlayer.h
	$(SCHALTER) $(SCHALTERADDS) -c -o Game.o Game.cpp

ComputerPlayer.o: ComputerPlayer.cpp ComputerPlayer.h ShapeGenerator.h utils.h
	$(SCHALTER) $(SCHALTERADDS) -c -o ComputerPlayer.o ComputerPlayer.cpp


HumanPlayer.o: HumanPlayer.cpp HumanPlayer.h 
	$(SCHALTER) $(SCHALTERADDS) -c -o HumanPlayer.o HumanPlayer.cpp

	
ShapeGenerator.o: ShapeGenerator.cpp ShapeGenerator.h 
	$(SCHALTER) $(SCHALTERADDS) -c -o ShapeGenerator.o ShapeGenerator.cpp


utils.o: utils.cpp utils.h
	$(SCHALTER) $(SCHALTERADDS) -c -o utils.o utils.cpp
