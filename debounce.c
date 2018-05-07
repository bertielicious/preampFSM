/*
 * File:   debounce.c
 * Author: Phil
 *
 * Created on 05 May 2018, 21:52
 */


#include <xc.h>
#include "config.h"
#include "debounce.h"
#include <stdbool.h>


bool debounce(bool button) 
{
    
    switch (currentState)
    {
        case off:
            if (button == notPressed)
            {
                currentState = off;
                return 0;
            }
            else
            {
                currentState = bouncingOn;
                return 0;
            }
            break;
            
        case bouncingOn:
            if (button == notPressed)
            {
                currentState = off;
                return 0;
            }
            else
            {
                currentState = on;
                return 1;
            }
            break;
            
        case on:
            if (button == notPressed)
            {
                currentState = bouncingOff;
                return 0;
            }
            else
            {
                currentState = on;
                return 1;  
            }
            
            case bouncingOff:
                if (button == notPressed)
                {
                    currentState = on;
                    return 0;
                }
                else
                {
                    currentState = off;
                    return 0;
                }
    }
}
