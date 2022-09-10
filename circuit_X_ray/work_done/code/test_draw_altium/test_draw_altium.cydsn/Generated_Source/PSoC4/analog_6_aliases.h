/*******************************************************************************
* File Name: analog_6.h  
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

#if !defined(CY_PINS_analog_6_ALIASES_H) /* Pins analog_6_ALIASES_H */
#define CY_PINS_analog_6_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define analog_6_0			(analog_6__0__PC)
#define analog_6_0_PS		(analog_6__0__PS)
#define analog_6_0_PC		(analog_6__0__PC)
#define analog_6_0_DR		(analog_6__0__DR)
#define analog_6_0_SHIFT	(analog_6__0__SHIFT)
#define analog_6_0_INTR	((uint16)((uint16)0x0003u << (analog_6__0__SHIFT*2u)))

#define analog_6_INTR_ALL	 ((uint16)(analog_6_0_INTR))


#endif /* End Pins analog_6_ALIASES_H */


/* [] END OF FILE */
