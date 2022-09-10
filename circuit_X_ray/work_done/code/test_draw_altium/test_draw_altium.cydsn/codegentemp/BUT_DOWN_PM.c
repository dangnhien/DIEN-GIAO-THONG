/*******************************************************************************
* File Name: BUT_DOWN.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "BUT_DOWN.h"

static BUT_DOWN_BACKUP_STRUCT  BUT_DOWN_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: BUT_DOWN_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet BUT_DOWN_SUT.c usage_BUT_DOWN_Sleep_Wakeup
*******************************************************************************/
void BUT_DOWN_Sleep(void)
{
    #if defined(BUT_DOWN__PC)
        BUT_DOWN_backup.pcState = BUT_DOWN_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            BUT_DOWN_backup.usbState = BUT_DOWN_CR1_REG;
            BUT_DOWN_USB_POWER_REG |= BUT_DOWN_USBIO_ENTER_SLEEP;
            BUT_DOWN_CR1_REG &= BUT_DOWN_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(BUT_DOWN__SIO)
        BUT_DOWN_backup.sioState = BUT_DOWN_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        BUT_DOWN_SIO_REG &= (uint32)(~BUT_DOWN_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: BUT_DOWN_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to BUT_DOWN_Sleep() for an example usage.
*******************************************************************************/
void BUT_DOWN_Wakeup(void)
{
    #if defined(BUT_DOWN__PC)
        BUT_DOWN_PC = BUT_DOWN_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            BUT_DOWN_USB_POWER_REG &= BUT_DOWN_USBIO_EXIT_SLEEP_PH1;
            BUT_DOWN_CR1_REG = BUT_DOWN_backup.usbState;
            BUT_DOWN_USB_POWER_REG &= BUT_DOWN_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(BUT_DOWN__SIO)
        BUT_DOWN_SIO_REG = BUT_DOWN_backup.sioState;
    #endif
}


/* [] END OF FILE */
