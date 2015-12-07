/*******************************************************************************
* File Name: Bumper_Register.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware to read the value of a Status 
*  Register.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Bumper_Register.h"

#if !defined(Bumper_Register_sts_intr_sts_reg__REMOVED) /* Check for removal by optimization */


/*******************************************************************************
* Function Name: Bumper_Register_Read
********************************************************************************
*
* Summary:
*  Reads the current value assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The current value in the Status Register.
*
*******************************************************************************/
uint8 Bumper_Register_Read(void) 
{ 
    return Bumper_Register_Status;
}


/*******************************************************************************
* Function Name: Bumper_Register_InterruptEnable
********************************************************************************
*
* Summary:
*  Enables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Bumper_Register_InterruptEnable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    Bumper_Register_Status_Aux_Ctrl |= Bumper_Register_STATUS_INTR_ENBL;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: Bumper_Register_InterruptDisable
********************************************************************************
*
* Summary:
*  Disables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Bumper_Register_InterruptDisable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    Bumper_Register_Status_Aux_Ctrl &= (uint8)(~Bumper_Register_STATUS_INTR_ENBL);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: Bumper_Register_WriteMask
********************************************************************************
*
* Summary:
*  Writes the current mask value assigned to the Status Register.
*
* Parameters:
*  mask:  Value to write into the mask register.
*
* Return:
*  None.
*
*******************************************************************************/
void Bumper_Register_WriteMask(uint8 mask) 
{
    #if(Bumper_Register_INPUTS < 8u)
    	mask &= ((uint8)(1u << Bumper_Register_INPUTS) - 1u);
	#endif /* End Bumper_Register_INPUTS < 8u */
    Bumper_Register_Status_Mask = mask;
}


/*******************************************************************************
* Function Name: Bumper_Register_ReadMask
********************************************************************************
*
* Summary:
*  Reads the current interrupt mask assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The value of the interrupt mask of the Status Register.
*
*******************************************************************************/
uint8 Bumper_Register_ReadMask(void) 
{
    return Bumper_Register_Status_Mask;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
