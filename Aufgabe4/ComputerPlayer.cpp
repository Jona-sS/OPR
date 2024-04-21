#include "ComputerPlayer.h"
#include "ShapeGenerator.h"
shape_type ComputerPlayer::make_turn()
{
//
// TODO 2 Start
//
// Statt r�ckgabewert "scissor" bitte verwenden Sie Shape Generator Klasse
	ShapeGenerator shapeGen;
	return shapeGen.generate();
	//return shape_type::scissor;
//
// TODO 2 End
//

}
