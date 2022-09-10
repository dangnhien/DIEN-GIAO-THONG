/*******************************************************************************
* File Name: analog_4.h  
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

#if !defined(CY_PINS_analog_4_H) /* Pins analog_4_H */
#define CY_PINS_analog_4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "analog_4_aliases.h"


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
} analog_4_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   analog_4_Read(void);
void    analog_4_Write(uint8 value);
uint8   analog_4_ReadDataReg(void);
#if defined(analog_4__PC) || (CY_PSOC4_4200L) 
    void    analog_4_SetDriveMode(uint8 mode);
#endif
void    analog_4_SetInterruptMode(uint16 position, uint16 mode);
uint8   analog_4_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void analog_4_Sleep(void); 
void analog_4_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(analog_4__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define analog_4_DRIVE_MODE_BITS        (3)
    #define analog_4_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - analog_4_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the analog_4_SetDriveMode() function.
         *  @{
         */
        #define analog_4_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define analog_4_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define analog_4_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define analog_4_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define analog_4_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define analog_4_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define analog_4_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define analog_4_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define analog_4_MASK               analog_4__MASK
#define analog_4_SHIFT              analog_4__SHIFT
#define analog_4_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in analog_4_SetInterruptMode() function.
     *  @{
     */
        #define analog_4_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define analog_4_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define analog_4_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define analog_4_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(analog_4__SIO)
    #define analog_4_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(analog_4__PC) && (CY_PSOC4_4200L)
    #define analog_4_USBIO_ENABLE               ((uint32)0x80000000u)
    #define analog_4_USBIO_DISABLE              ((uint32)(~analog_4_USBIO_ENABLE))
    #define analog_4_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define analog_4_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define analog_4_USBIO_ENTER_SLEEP          ((uint32)((1u << analog_4_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << analog_4_USBIO_SUSPEND_DEL_SHIFT)))
    #define analog_4_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << analog_4_USBIO_SUSPEND_SHIFT)))
    #define analog_4_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << analog_4_USBIO_SUSPEND_DEL_SHIFT)))
    #define analog_4_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(analog_4__PC)
    /* Port Configuration */
    #define analog_4_PC                 (* (reg32 *) analog_4__PC)
#endif
/* Pin State */
#define analog_4_PS                     (* (reg32 *) analog_4__PS)
/* Data Register */
#define analog_4_DR                     (* (reg32 *) analog_4__DR)
/* Input Buffer Disable Override */
#define analog_4_INP_DIS                (* (reg32 *) analog_4__PC2)

/* Interrupt configuration Registers */
#define analog_4_INTCFG                 (* (reg32 *) analog_4__INTCFG)
#define analog_4_INTSTAT                (* (reg32 *) analog_4__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define analog_4_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(analog_4__SIO)
    #define analog_4_SIO_REG            (* (reg32 *) analog_4__SIO)
#endif /* (analog_4__SIO_CFG) */

/* USBIO registers */
#if !defined(analog_4__PC) && (CY_PSOC4_4200L)
    #define analog_4_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define analog_4_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define analog_4_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define analog_4_DRIVE_MODE_SHIFT       (0x00u)
#define analog_4_DRIVE_MODE_MASK        (0x07u << analog_4_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins analog_4_H */


/* [] END OF FILE */
