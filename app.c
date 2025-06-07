/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It 
    implements the logic of the application's state machine and it may call 
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************

#include "app.h"
#include <xc.h>


// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.
    
    Application strings and buffers are be defined outside this structure.
*/

APP_DATA appData;


// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/
/*void TimerCallBack(uintptr_t context, uint32_t tickCount)
{
         Toggle LED       
        BSP_LEDToggle(BSP_LED_3);
        
}*/ // HAVE COMMENTED THIS OUT...

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

int nBT1Press =0;

void APP_Initialize ( void )
{
    /* Put the application into its initial state */
    appData.state = APP_STATE_INIT;
                
}

uint32_t ButtonPressed=0;

/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{
    
   /* Take appropriate action, depending on the current state. */
    switch (appData.state)
    {

        /* Initial state is to create the timer object for periodic alarm */
        case APP_STATE_INIT:
        {
            BSP_LEDStateSet(BSP_LED_1,BSP_LED_STATE_OFF);
            BSP_LEDStateSet(BSP_LED_2,BSP_LED_STATE_OFF);
            BSP_LEDStateSet(BSP_LED_3,BSP_LED_STATE_OFF);
            
            if(BSP_SWITCH_STATE_PRESSED==BSP_SwitchStateGet(BSP_SWITCH_1))
            {
                
                if(SYS_TMR_TickCountGet()-ButtonPressed > 300)
                {
                    appData.state=APP_STATE_LED1;
                    ButtonPressed = SYS_TMR_TickCountGet();
                }
                
            }
            else if(BSP_SWITCH_STATE_PRESSED==BSP_SwitchStateGet(BSP_SWITCH_2))
            {
      
                if(SYS_TMR_TickCountGet()-ButtonPressed > 300)
                {
                    appData.state=APP_STATE_LED3;
                    ButtonPressed = SYS_TMR_TickCountGet();
                }
           
            }
            
            break;
        }

        /* LED will be toggled in Timer Callback function, 
         * so nothing is there to be done in this state */
        case APP_STATE_LED1:
        {
            
            BSP_LEDStateSet(BSP_LED_1,BSP_LED_STATE_ON);
            
            if(BSP_SWITCH_STATE_PRESSED==BSP_SwitchStateGet(BSP_SWITCH_1))
            {
                if(SYS_TMR_TickCountGet()-ButtonPressed > 300)
                {
                    appData.state=APP_STATE_LED2;
                    ButtonPressed = SYS_TMR_TickCountGet();
                    BSP_LEDStateSet(BSP_LED_1,BSP_LED_STATE_OFF);
                }
                
            }
            else if(BSP_SWITCH_STATE_PRESSED==BSP_SwitchStateGet(BSP_SWITCH_2))
            {
                if(SYS_TMR_TickCountGet()-ButtonPressed > 300)
                {
                    appData.state=APP_STATE_INIT;
                    ButtonPressed = SYS_TMR_TickCountGet();
                    
                }
               
            }
            
            break;
            
        }
        case APP_STATE_LED2:
        {
            
            BSP_LEDStateSet(BSP_LED_2,BSP_LED_STATE_ON);
            
            if(BSP_SWITCH_STATE_PRESSED==BSP_SwitchStateGet(BSP_SWITCH_1))
            {
                if(SYS_TMR_TickCountGet()-ButtonPressed > 300)
                {
                    appData.state=APP_STATE_LED3;
                    ButtonPressed = SYS_TMR_TickCountGet();
                    BSP_LEDStateSet(BSP_LED_2,BSP_LED_STATE_OFF);
                }
                
            }
            else if(BSP_SWITCH_STATE_PRESSED==BSP_SwitchStateGet(BSP_SWITCH_2))
            {
                if(SYS_TMR_TickCountGet()-ButtonPressed > 300)
                {
                    appData.state=APP_STATE_LED1;
                    ButtonPressed = SYS_TMR_TickCountGet();
                    BSP_LEDStateSet(BSP_LED_2,BSP_LED_STATE_OFF);
                    
                }
            }  
            break;
            
        }
        case APP_STATE_LED3:
        {
            BSP_LEDStateSet(BSP_LED_3,BSP_LED_STATE_ON);
            
            if(BSP_SWITCH_STATE_PRESSED==BSP_SwitchStateGet(BSP_SWITCH_1))
            {
                if(SYS_TMR_TickCountGet()-ButtonPressed > 300)
                {
                    appData.state=APP_STATE_INIT;
                    ButtonPressed = SYS_TMR_TickCountGet();
                    BSP_LEDStateSet(BSP_LED_3,BSP_LED_STATE_OFF);
                }
            }
                
            
            else if(BSP_SWITCH_STATE_PRESSED==BSP_SwitchStateGet(BSP_SWITCH_2))
            {
                if(SYS_TMR_TickCountGet()-ButtonPressed > 300)
                {
                    appData.state=APP_STATE_LED2;
                    ButtonPressed = SYS_TMR_TickCountGet();
                    BSP_LEDStateSet(BSP_LED_3,BSP_LED_STATE_OFF);
                    
                }
                
            }
            
            break;
            
        }
        
        
        
        
        /* Should not come here during normal operation */
        default:
        {
            break;
        }

    }
    
}
 

/*******************************************************************************
 End of File
 */
