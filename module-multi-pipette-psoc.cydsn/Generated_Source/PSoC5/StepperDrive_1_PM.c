/*******************************************************************************
* File Name: StepperDrive_1_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "StepperDrive_1.h"

static StepperDrive_1_backupStruct StepperDrive_1_backup;


/*******************************************************************************
* Function Name: StepperDrive_1_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  StepperDrive_1_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void StepperDrive_1_SaveConfig(void) 
{

    #if(!StepperDrive_1_UsingFixedFunction)
        #if(!StepperDrive_1_PWMModeIsCenterAligned)
            StepperDrive_1_backup.PWMPeriod = StepperDrive_1_ReadPeriod();
        #endif /* (!StepperDrive_1_PWMModeIsCenterAligned) */
        StepperDrive_1_backup.PWMUdb = StepperDrive_1_ReadCounter();
        #if (StepperDrive_1_UseStatus)
            StepperDrive_1_backup.InterruptMaskValue = StepperDrive_1_STATUS_MASK;
        #endif /* (StepperDrive_1_UseStatus) */

        #if(StepperDrive_1_DeadBandMode == StepperDrive_1__B_PWM__DBM_256_CLOCKS || \
            StepperDrive_1_DeadBandMode == StepperDrive_1__B_PWM__DBM_2_4_CLOCKS)
            StepperDrive_1_backup.PWMdeadBandValue = StepperDrive_1_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(StepperDrive_1_KillModeMinTime)
             StepperDrive_1_backup.PWMKillCounterPeriod = StepperDrive_1_ReadKillTime();
        #endif /* (StepperDrive_1_KillModeMinTime) */

        #if(StepperDrive_1_UseControl)
            StepperDrive_1_backup.PWMControlRegister = StepperDrive_1_ReadControlRegister();
        #endif /* (StepperDrive_1_UseControl) */
    #endif  /* (!StepperDrive_1_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: StepperDrive_1_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  StepperDrive_1_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void StepperDrive_1_RestoreConfig(void) 
{
        #if(!StepperDrive_1_UsingFixedFunction)
            #if(!StepperDrive_1_PWMModeIsCenterAligned)
                StepperDrive_1_WritePeriod(StepperDrive_1_backup.PWMPeriod);
            #endif /* (!StepperDrive_1_PWMModeIsCenterAligned) */

            StepperDrive_1_WriteCounter(StepperDrive_1_backup.PWMUdb);

            #if (StepperDrive_1_UseStatus)
                StepperDrive_1_STATUS_MASK = StepperDrive_1_backup.InterruptMaskValue;
            #endif /* (StepperDrive_1_UseStatus) */

            #if(StepperDrive_1_DeadBandMode == StepperDrive_1__B_PWM__DBM_256_CLOCKS || \
                StepperDrive_1_DeadBandMode == StepperDrive_1__B_PWM__DBM_2_4_CLOCKS)
                StepperDrive_1_WriteDeadTime(StepperDrive_1_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(StepperDrive_1_KillModeMinTime)
                StepperDrive_1_WriteKillTime(StepperDrive_1_backup.PWMKillCounterPeriod);
            #endif /* (StepperDrive_1_KillModeMinTime) */

            #if(StepperDrive_1_UseControl)
                StepperDrive_1_WriteControlRegister(StepperDrive_1_backup.PWMControlRegister);
            #endif /* (StepperDrive_1_UseControl) */
        #endif  /* (!StepperDrive_1_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: StepperDrive_1_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  StepperDrive_1_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void StepperDrive_1_Sleep(void) 
{
    #if(StepperDrive_1_UseControl)
        if(StepperDrive_1_CTRL_ENABLE == (StepperDrive_1_CONTROL & StepperDrive_1_CTRL_ENABLE))
        {
            /*Component is enabled */
            StepperDrive_1_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            StepperDrive_1_backup.PWMEnableState = 0u;
        }
    #endif /* (StepperDrive_1_UseControl) */

    /* Stop component */
    StepperDrive_1_Stop();

    /* Save registers configuration */
    StepperDrive_1_SaveConfig();
}


/*******************************************************************************
* Function Name: StepperDrive_1_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  StepperDrive_1_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void StepperDrive_1_Wakeup(void) 
{
     /* Restore registers values */
    StepperDrive_1_RestoreConfig();

    if(StepperDrive_1_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        StepperDrive_1_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
