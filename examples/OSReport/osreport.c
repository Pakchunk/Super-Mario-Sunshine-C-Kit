#include "inc/sms.h"

int OnUpdate(MarDirector* director) 
{    
    int (*GameUpdate)(MarDirector* director) = GetObjectFunction(director, Director_GameUpdate);

    MarioActor* mario = *gpMarioAddress;

    //Print Mario's position on DPad Up press
    if (mario)
    {
        if (ControllerOne->buttons & PRESS_DU)
        {
            // New line (\n) MUST be included at the end or else it won't work for some reason.
            OSReport("DpadUP Button Pressed\n");
            OSReport("X: %.2f Y: %.2f Z: %.2f\n", mario->position.x, mario->position.y, mario->position.z);
        }
    }

    return GameUpdate(director);
}

void OnSetup(MarDirector* director)
{
    MarDirector_SetupObjects(director);	//Run replaced branch

    //Print when OnSetup is called
    OSReport("OnSetup called\n");
}