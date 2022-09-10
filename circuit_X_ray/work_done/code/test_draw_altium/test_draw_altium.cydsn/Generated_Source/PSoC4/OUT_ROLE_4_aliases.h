/*******************************************************************************
* File Name: OUT_ROLE_4.h  
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

#if !defined(CY_PINS_OUT_ROLE_4_ALIASES_H) /* Pins OUT_ROLE_4_ALIASES_H */
#define CY_PINS_OUT_ROLE_4_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define OUT_ROLE_4_0			(OUT_ROLE_4__0__PC)
#define OUT_ROLE_4_0_PS		(OUT_ROLE_4__0__PS)
#define OUT_ROLE_4_0_PC		(OUT_ROLE_4__0__PC)
#define OUT_ROLE_4_0_DR		(OUT_ROLE_4__0__DR)
#define OUT_ROLE_4_0_SHIFT	(OUT_ROLE_4__0__SHIFT)
#define OUT_ROLE_4_0_INTR	((uint16)((uint16)0x0003u << (OUT_ROLE_4__0__SHIFT*2u)))

#define OUT_ROLE_4_INTR_ALL	 ((uint16)(OUT_ROLE_4_0_INTR))


#endif /* End Pins OUT_ROLE_4_ALIASES_H */


/* [] END OF FILE */
