/*******************************************************************************
* File Name: BUT_TURN_OFF.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_BUT_TURN_OFF_ALIASES_H) /* Pins BUT_TURN_OFF_ALIASES_H */
#define CY_PINS_BUT_TURN_OFF_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define BUT_TURN_OFF_0			(BUT_TURN_OFF__0__PC)
#define BUT_TURN_OFF_0_PS		(BUT_TURN_OFF__0__PS)
#define BUT_TURN_OFF_0_PC		(BUT_TURN_OFF__0__PC)
#define BUT_TURN_OFF_0_DR		(BUT_TURN_OFF__0__DR)
#define BUT_TURN_OFF_0_SHIFT	(BUT_TURN_OFF__0__SHIFT)
#define BUT_TURN_OFF_0_INTR	((uint16)((uint16)0x0003u << (BUT_TURN_OFF__0__SHIFT*2u)))

#define BUT_TURN_OFF_INTR_ALL	 ((uint16)(BUT_TURN_OFF_0_INTR))


#endif /* End Pins BUT_TURN_OFF_ALIASES_H */


/* [] END OF FILE */
