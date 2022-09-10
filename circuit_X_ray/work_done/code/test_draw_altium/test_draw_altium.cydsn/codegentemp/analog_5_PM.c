/*******************************************************************************
* File Name: analog_5.c  
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
#include "analog_5.h"

static analog_5_BACKUP_STRUCT  analog_5_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: analog_5_Sleep
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
*  \snippet analog_5_SUT.c usage_analog_5_Sleep_Wakeup
*******************************************************************************/
void analog_5_Sleep(void)
{
    #if defined(analog_5__PC)
        analog_5_backup.pcState = analog_5_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            analog_5_backup.usbState = analog_5_CR1_REG;
            analog_5_USB_POWER_REG |= analog_5_USBIO_ENTER_SLEEP;
            analog_5_CR1_REG &= analog_5_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(analog_5__SIO)
        analog_5_backup.sioState = analog_5_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        analog_5_SIO_REG &= (uint32)(~analog_5_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: analog_5_Wakeup
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
*  Refer to analog_5_Sleep() for an example usage.
*******************************************************************************/
void analog_5_Wakeup(void)
{
    #if defined(analog_5__PC)
        analog_5_PC = analog_5_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            analog_5_USB_POWER_REG &= analog_5_USBIO_EXIT_SLEEP_PH1;
            analog_5_CR1_REG = analog_5_backup.usbState;
            analog_5_USB_POWER_REG &= analog_5_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(analog_5__SIO)
        analog_5_SIO_REG = analog_5_backup.sioState;
    #endif
}


/* [] END OF FILE */
