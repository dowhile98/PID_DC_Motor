/*
 * File: ControlPID_EXTI.h
 *
 * Code generated for Simulink model :ControlPID.
 *
 * Model version      : 1.14
 * Simulink Coder version    : 9.3 (R2020a) 18-Nov-2019
 * TLC version       : 9.3 (Jan 23 2020)
 * C/C++ source code generated on  : Sun Dec 12 17:23:16 2021
 *
 * Target selection: stm32.tlc
 * Embedded hardware selection: STM32CortexM
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 *
 *
 * ******************************************************************************
 * * attention
 * *
 * * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
 * * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 * *
 * ******************************************************************************
 */

#ifndef RTW_HEADER_ControlPID_EXTI_h_
#define RTW_HEADER_ControlPID_EXTI_h_
#include "STM32_Config.h"

/* Exti function pointer array declaration */
extern void (*EXTI_Callback[16])(void);
extern void EXTI0_Callback(void);

#endif                                 /* RTW_HEADER_ControlPID_EXTI_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] ControlPID_EXTI.h
 */
