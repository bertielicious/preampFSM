/*
 * File:   main.c
 * Author: Phil
 *
 * Created on 04 May 2018, 21:28
 */


#include <xc.h>
#include <stdio.h>
#include <stdbool.h>
#include "config.h"
#include "main.h"
#include "init_ports.h"
#include "config_osc.h"
#include "putch.h"
#include "set_usart.h"
#include "transmit_character.h"
#include "transmit_data.h"
#include "write_command.h"
#include "write_data.h"
#include "debounce.h"

void main(void) 
{
    int i = 0;
    init_ports();
    config_osc();
    set_usart();
    bool button_state = notPressed;
    while(1)
    {
        button_state = debounce(DT);
        LED = button_state;
        if(DT != DT)
        {
            printf("DT = %d\n",DT);
        }
    }
        
}
