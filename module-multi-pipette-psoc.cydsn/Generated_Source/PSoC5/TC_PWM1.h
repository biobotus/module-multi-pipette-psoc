/*******************************************************************************
* File Name: TC_PWM1.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_TC_PWM1_H) /* Pins TC_PWM1_H */
#define CY_PINS_TC_PWM1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "TC_PWM1_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 TC_PWM1__PORT == 15 && ((TC_PWM1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    TC_PWM1_Write(uint8 value) ;
void    TC_PWM1_SetDriveMode(uint8 mode) ;
uint8   TC_PWM1_ReadDataReg(void) ;
uint8   TC_PWM1_Read(void) ;
uint8   TC_PWM1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define TC_PWM1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define TC_PWM1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define TC_PWM1_DM_RES_UP          PIN_DM_RES_UP
#define TC_PWM1_DM_RES_DWN         PIN_DM_RES_DWN
#define TC_PWM1_DM_OD_LO           PIN_DM_OD_LO
#define TC_PWM1_DM_OD_HI           PIN_DM_OD_HI
#define TC_PWM1_DM_STRONG          PIN_DM_STRONG
#define TC_PWM1_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define TC_PWM1_MASK               TC_PWM1__MASK
#define TC_PWM1_SHIFT              TC_PWM1__SHIFT
#define TC_PWM1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define TC_PWM1_PS                     (* (reg8 *) TC_PWM1__PS)
/* Data Register */
#define TC_PWM1_DR                     (* (reg8 *) TC_PWM1__DR)
/* Port Number */
#define TC_PWM1_PRT_NUM                (* (reg8 *) TC_PWM1__PRT) 
/* Connect to Analog Globals */                                                  
#define TC_PWM1_AG                     (* (reg8 *) TC_PWM1__AG)                       
/* Analog MUX bux enable */
#define TC_PWM1_AMUX                   (* (reg8 *) TC_PWM1__AMUX) 
/* Bidirectional Enable */                                                        
#define TC_PWM1_BIE                    (* (reg8 *) TC_PWM1__BIE)
/* Bit-mask for Aliased Register Access */
#define TC_PWM1_BIT_MASK               (* (reg8 *) TC_PWM1__BIT_MASK)
/* Bypass Enable */
#define TC_PWM1_BYP                    (* (reg8 *) TC_PWM1__BYP)
/* Port wide control signals */                                                   
#define TC_PWM1_CTL                    (* (reg8 *) TC_PWM1__CTL)
/* Drive Modes */
#define TC_PWM1_DM0                    (* (reg8 *) TC_PWM1__DM0) 
#define TC_PWM1_DM1                    (* (reg8 *) TC_PWM1__DM1)
#define TC_PWM1_DM2                    (* (reg8 *) TC_PWM1__DM2) 
/* Input Buffer Disable Override */
#define TC_PWM1_INP_DIS                (* (reg8 *) TC_PWM1__INP_DIS)
/* LCD Common or Segment Drive */
#define TC_PWM1_LCD_COM_SEG            (* (reg8 *) TC_PWM1__LCD_COM_SEG)
/* Enable Segment LCD */
#define TC_PWM1_LCD_EN                 (* (reg8 *) TC_PWM1__LCD_EN)
/* Slew Rate Control */
#define TC_PWM1_SLW                    (* (reg8 *) TC_PWM1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define TC_PWM1_PRTDSI__CAPS_SEL       (* (reg8 *) TC_PWM1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define TC_PWM1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) TC_PWM1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define TC_PWM1_PRTDSI__OE_SEL0        (* (reg8 *) TC_PWM1__PRTDSI__OE_SEL0) 
#define TC_PWM1_PRTDSI__OE_SEL1        (* (reg8 *) TC_PWM1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define TC_PWM1_PRTDSI__OUT_SEL0       (* (reg8 *) TC_PWM1__PRTDSI__OUT_SEL0) 
#define TC_PWM1_PRTDSI__OUT_SEL1       (* (reg8 *) TC_PWM1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define TC_PWM1_PRTDSI__SYNC_OUT       (* (reg8 *) TC_PWM1__PRTDSI__SYNC_OUT) 


#if defined(TC_PWM1__INTSTAT)  /* Interrupt Registers */

    #define TC_PWM1_INTSTAT                (* (reg8 *) TC_PWM1__INTSTAT)
    #define TC_PWM1_SNAP                   (* (reg8 *) TC_PWM1__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_TC_PWM1_H */


/* [] END OF FILE */
