/*******************************************************************************
* File Name: BUT_DOWN.h  
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

#if !defined(CY_PINS_BUT_DOWN_H) /* Pins BUT_DOWN_H */
#define CY_PINS_BUT_DOWN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "BUT_DOWN_aliases.h"


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
} BUT_DOWN_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   BUT_DOWN_Read(void);
void    BUT_DOWN_Write(uint8 value);
uint8   BUT_DOWN_ReadDataReg(void);
#if defined(BUT_DOWN__PC) || (CY_PSOC4_4200L) 
    void    BUT_DOWN_SetDriveMode(uint8 mode);
#endif
void    BUT_DOWN_SetInterruptMode(uint16 position, uint16 mode);
uint8   BUT_DOWN_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void BUT_DOWN_Sleep(void); 
void BUT_DOWN_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(BUT_DOWN__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define BUT_DOWN_DRIVE_MODE_BITS        (3)
    #define BUT_DOWN_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - BUT_DOWN_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the BUT_DOWN_SetDriveMode() function.
         *  @{
         */
        #define BUT_DOWN_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define BUT_DOWN_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define BUT_DOWN_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define BUT_DOWN_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define BUT_DOWN_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define BUT_DOWN_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define BUT_DOWN_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define BUT_DOWN_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define BUT_DOWN_MASK               BUT_DOWN__MASK
#define BUT_DOWN_SHIFT              BUT_DOWN__SHIFT
#define BUT_DOWN_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in BUT_DOWN_SetInterruptMode() function.
     *  @{
     */
        #define BUT_DOWN_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define BUT_DOWN_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define BUT_DOWN_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define BUT_DOWN_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(BUT_DOWN__SIO)
    #define BUT_DOWN_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(BUT_DOWN__PC) && (CY_PSOC4_4200L)
    #define BUT_DOWN_USBIO_ENABLE               ((uint32)0x80000000u)
    #define BUT_DOWN_USBIO_DISABLE              ((uint32)(~BUT_DOWN_USBIO_ENABLE))
    #define BUT_DOWN_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define BUT_DOWN_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define BUT_DOWN_USBIO_ENTER_SLEEP          ((uint32)((1u << BUT_DOWN_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << BUT_DOWN_USBIO_SUSPEND_DEL_SHIFT)))
    #define BUT_DOWN_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << BUT_DOWN_USBIO_SUSPEND_SHIFT)))
    #define BUT_DOWN_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << BUT_DOWN_USBIO_SUSPEND_DEL_SHIFT)))
    #define BUT_DOWN_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(BUT_DOWN__PC)
    /* Port Configuration */
    #define BUT_DOWN_PC                 (* (reg32 *) BUT_DOWN__PC)
#endif
/* Pin State */
#define BUT_DOWN_PS                     (* (reg32 *) BUT_DOWN__PS)
/* Data Register */
#define BUT_DOWN_DR                     (* (reg32 *) BUT_DOWN__DR)
/* Input Buffer Disable Override */
#define BUT_DOWN_INP_DIS                (* (reg32 *) BUT_DOWN__PC2)

/* Interrupt configuration Registers */
#define BUT_DOWN_INTCFG                 (* (reg32 *) BUT_DOWN__INTCFG)
#define BUT_DOWN_INTSTAT                (* (reg32 *) BUT_DOWN__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define BUT_DOWN_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(BUT_DOWN__SIO)
    #define BUT_DOWN_SIO_REG            (* (reg32 *) BUT_DOWN__SIO)
#endif /* (BUT_DOWN__SIO_CFG) */

/* USBIO registers */
#if !defined(BUT_DOWN__PC) && (CY_PSOC4_4200L)
    #define BUT_DOWN_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define BUT_DOWN_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define BUT_DOWN_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define BUT_DOWN_DRIVE_MODE_SHIFT       (0x00u)
#define BUT_DOWN_DRIVE_MODE_MASK        (0x07u << BUT_DOWN_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins BUT_DOWN_H */


/* [] END OF FILE */
