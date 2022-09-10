/*******************************************************************************
* File Name: BUT_DOWN.h  
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

#if !defined(CY_PINS_BUT_DOWN_ALIASES_H) /* Pins BUT_DOWN_ALIASES_H */
#define CY_PINS_BUT_DOWN_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define BUT_DOWN_0			(BUT_DOWN__0__PC)
#define BUT_DOWN_0_PS		(BUT_DOWN__0__PS)
#define BUT_DOWN_0_PC		(BUT_DOWN__0__PC)
#define BUT_DOWN_0_DR		(BUT_DOWN__0__DR)
#define BUT_DOWN_0_SHIFT	(BUT_DOWN__0__SHIFT)
#define BUT_DOWN_0_INTR	((uint16)((uint16)0x0003u << (BUT_DOWN__0__SHIFT*2u)))

#define BUT_DOWN_INTR_ALL	 ((uint16)(BUT_DOWN_0_INTR))


#endif /* End Pins BUT_DOWN_ALIASES_H */


/* [] END OF FILE */
