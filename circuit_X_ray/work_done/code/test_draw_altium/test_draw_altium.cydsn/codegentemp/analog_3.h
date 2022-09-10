/*******************************************************************************
* File Name: analog_3.h  
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

#if !defined(CY_PINS_analog_3_H) /* Pins analog_3_H */
#define CY_PINS_analog_3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "analog_3_aliases.h"


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
} analog_3_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   analog_3_Read(void);
void    analog_3_Write(uint8 value);
uint8   analog_3_ReadDataReg(void);
#if defined(analog_3__PC) || (CY_PSOC4_4200L) 
    void    analog_3_SetDriveMode(uint8 mode);
#endif
void    analog_3_SetInterruptMode(uint16 position, uint16 mode);
uint8   analog_3_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void analog_3_Sleep(void); 
void analog_3_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(analog_3__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define analog_3_DRIVE_MODE_BITS        (3)
    #define analog_3_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - analog_3_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the analog_3_SetDriveMode() function.
         *  @{
         */
        #define analog_3_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define analog_3_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define analog_3_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define analog_3_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define analog_3_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define analog_3_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define analog_3_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define analog_3_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define analog_3_MASK               analog_3__MASK
#define analog_3_SHIFT              analog_3__SHIFT
#define analog_3_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in analog_3_SetInterruptMode() function.
     *  @{
     */
        #define analog_3_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define analog_3_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define analog_3_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define analog_3_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(analog_3__SIO)
    #define analog_3_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(analog_3__PC) && (CY_PSOC4_4200L)
    #define analog_3_USBIO_ENABLE               ((uint32)0x80000000u)
    #define analog_3_USBIO_DISABLE              ((uint32)(~analog_3_USBIO_ENABLE))
    #define analog_3_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define analog_3_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define analog_3_USBIO_ENTER_SLEEP          ((uint32)((1u << analog_3_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << analog_3_USBIO_SUSPEND_DEL_SHIFT)))
    #define analog_3_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << analog_3_USBIO_SUSPEND_SHIFT)))
    #define analog_3_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << analog_3_USBIO_SUSPEND_DEL_SHIFT)))
    #define analog_3_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(analog_3__PC)
    /* Port Configuration */
    #define analog_3_PC                 (* (reg32 *) analog_3__PC)
#endif
/* Pin State */
#define analog_3_PS                     (* (reg32 *) analog_3__PS)
/* Data Register */
#define analog_3_DR                     (* (reg32 *) analog_3__DR)
/* Input Buffer Disable Override */
#define analog_3_INP_DIS                (* (reg32 *) analog_3__PC2)

/* Interrupt configuration Registers */
#define analog_3_INTCFG                 (* (reg32 *) analog_3__INTCFG)
#define analog_3_INTSTAT                (* (reg32 *) analog_3__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define analog_3_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(analog_3__SIO)
    #define analog_3_SIO_REG            (* (reg32 *) analog_3__SIO)
#endif /* (analog_3__SIO_CFG) */

/* USBIO registers */
#if !defined(analog_3__PC) && (CY_PSOC4_4200L)
    #define analog_3_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define analog_3_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define analog_3_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define analog_3_DRIVE_MODE_SHIFT       (0x00u)
#define analog_3_DRIVE_MODE_MASK        (0x07u << analog_3_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins analog_3_H */


/* [] END OF FILE */
