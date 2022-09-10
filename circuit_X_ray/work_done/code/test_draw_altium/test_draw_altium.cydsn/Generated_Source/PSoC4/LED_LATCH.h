/*******************************************************************************
* File Name: LED_LATCH.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_LED_LATCH_H) /* Pins LED_LATCH_H */
#define CY_PINS_LED_LATCH_H

#include "cytypes.h"
#include "cyfitter.h"
#include "LED_LATCH_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} LED_LATCH_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   LED_LATCH_Read(void);
void    LED_LATCH_Write(uint8 value);
uint8   LED_LATCH_ReadDataReg(void);
#if defined(LED_LATCH__PC) || (CY_PSOC4_4200L) 
    void    LED_LATCH_SetDriveMode(uint8 mode);
#endif
void    LED_LATCH_SetInterruptMode(uint16 position, uint16 mode);
uint8   LED_LATCH_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void LED_LATCH_Sleep(void); 
void LED_LATCH_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(LED_LATCH__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define LED_LATCH_DRIVE_MODE_BITS        (3)
    #define LED_LATCH_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - LED_LATCH_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the LED_LATCH_SetDriveMode() function.
         *  @{
         */
        #define LED_LATCH_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define LED_LATCH_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define LED_LATCH_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define LED_LATCH_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define LED_LATCH_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define LED_LATCH_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define LED_LATCH_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define LED_LATCH_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define LED_LATCH_MASK               LED_LATCH__MASK
#define LED_LATCH_SHIFT              LED_LATCH__SHIFT
#define LED_LATCH_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LED_LATCH_SetInterruptMode() function.
     *  @{
     */
        #define LED_LATCH_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define LED_LATCH_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define LED_LATCH_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define LED_LATCH_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(LED_LATCH__SIO)
    #define LED_LATCH_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(LED_LATCH__PC) && (CY_PSOC4_4200L)
    #define LED_LATCH_USBIO_ENABLE               ((uint32)0x80000000u)
    #define LED_LATCH_USBIO_DISABLE              ((uint32)(~LED_LATCH_USBIO_ENABLE))
    #define LED_LATCH_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define LED_LATCH_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define LED_LATCH_USBIO_ENTER_SLEEP          ((uint32)((1u << LED_LATCH_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << LED_LATCH_USBIO_SUSPEND_DEL_SHIFT)))
    #define LED_LATCH_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << LED_LATCH_USBIO_SUSPEND_SHIFT)))
    #define LED_LATCH_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << LED_LATCH_USBIO_SUSPEND_DEL_SHIFT)))
    #define LED_LATCH_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(LED_LATCH__PC)
    /* Port Configuration */
    #define LED_LATCH_PC                 (* (reg32 *) LED_LATCH__PC)
#endif
/* Pin State */
#define LED_LATCH_PS                     (* (reg32 *) LED_LATCH__PS)
/* Data Register */
#define LED_LATCH_DR                     (* (reg32 *) LED_LATCH__DR)
/* Input Buffer Disable Override */
#define LED_LATCH_INP_DIS                (* (reg32 *) LED_LATCH__PC2)

/* Interrupt configuration Registers */
#define LED_LATCH_INTCFG                 (* (reg32 *) LED_LATCH__INTCFG)
#define LED_LATCH_INTSTAT                (* (reg32 *) LED_LATCH__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define LED_LATCH_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(LED_LATCH__SIO)
    #define LED_LATCH_SIO_REG            (* (reg32 *) LED_LATCH__SIO)
#endif /* (LED_LATCH__SIO_CFG) */

/* USBIO registers */
#if !defined(LED_LATCH__PC) && (CY_PSOC4_4200L)
    #define LED_LATCH_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define LED_LATCH_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define LED_LATCH_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define LED_LATCH_DRIVE_MODE_SHIFT       (0x00u)
#define LED_LATCH_DRIVE_MODE_MASK        (0x07u << LED_LATCH_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins LED_LATCH_H */


/* [] END OF FILE */
