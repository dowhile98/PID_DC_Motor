/*
 * File: ControlPID_TIM.c
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

#include "ControlPID.h"
#include "ControlPID_TIM.h"

/* Number of configured TIMER. */
uint16_t G_TIM_Count = 0;

/* Array of TIMER information. */
TIM_ConfTypeDef* G_TIM_Conf[2];
TIM_HandleTypeDef* G_TIM_Handler[2];

/* TIM15 informations. */
TIM_ConfTypeDef TIM15_Conf;

/* TIM15 polling timeout value. Number of Solver loop. (can be changed). */
uint32_t G_TIM15_PollTimeOut = 10;

/* TIM6 informations. */
TIM_ConfTypeDef TIM6_Conf;

/* TIM6 polling timeout value. Number of Solver loop. (can be changed). */
uint32_t G_TIM6_PollTimeOut = 10;

/*******************************************************************************
 * Function Name  : TIM_PeriodElapsedCustomCallback
 * Description    : Timer callback for update event
 * Input          : TIM_HandleTypeDef*   TIM IC handle
 *******************************************************************************/
void TIM_PeriodElapsedCustomCallback(TIM_HandleTypeDef *htim)
{
  TIM_ConfTypeDef * pConf = G_TIM_Conf[0];
  TIM_HandleTypeDef* pHandler = G_TIM_Handler[0];

  {
    uint16_t idx = 0;
    for (idx = 0;idx < 2;idx++) {
      pHandler = G_TIM_Handler[idx];
      if (pHandler == htim) {
        pConf = G_TIM_Conf[idx];
        break;
      }
    }
  }

  if (pHandler == htim) {
    if (pConf->ItUpFcn != NULL) {
      /* Call update function for TIM6. */
      pConf->ItUpFcn();
    }
  }
}

/**
 * @brief  Period elapsed callback in non blocking mode
 * @param  htim TIM handle
 * @retval None
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  extern void TIM_PeriodElapsedCustomCallback(TIM_HandleTypeDef *htim);

  /* Handle this event from model side. */
  TIM_PeriodElapsedCustomCallback(htim);
}

/*******************************************************************************
 * Function Name  : TIM6_ItUpFcn
 * Description    : TIM6 update interrupt
 * Input          : None
 * TIM6_ItUpFcn is called from TIM_PeriodElapsedCustomCallback function
 * in ControlPID_TIM.c file.
 *******************************************************************************/
void TIM6_ItUpFcn()
{
  {
    /* Output and update for function-call system: '<Root>/ISR lectura rads//s' */
    {
      uint8_T buffer[15];
      int32_T i;
      static const char_T b[9] = "%.2f\\r\\n";
      char_T b_p[9];
      ControlPID_DW.rads = ControlPID_DW.pulses * 60.0 / 1.2 *
        6.2831853071795862 / 60.0;
      ControlPID_DW.pulses = 0.0 * ControlPID_DW.rads;
      for (i = 0; i < 15; i++) {
        buffer[i] = 0U;
      }

      ControlPID_B.Buff = getBuffPtr(buffer);
      for (i = 0; i < 9; i++) {
        b_p[i] = b[i];
      }

      ControlPID_B.NbChar = sprintf(buffer, b_p, ControlPID_DW.rads);

      {
        if (ControlPID_B.NbChar != 0) {
          /* Copy data to send. */
          TX_CopyData(&USART2_TxConf, (uint8_t*)ControlPID_B.Buff, (uint16_t)
                      ControlPID_B.NbChar);
        }

        if (USART2_TxConf.nb2Send) {
          ControlPID_B.USART_Send = 0;
          USART2_TX_SendData(&USART2_TxConf);
        }

        if (USART2_TxConf.txStatus != SERIAL_TX_ON) {
          ControlPID_B.USART_Send = USART2_TxConf.nbSent;
        }
      }

      ControlPID_DW.stateControl = 1.0;
    }
  }
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] ControlPID_TIM.c
 */
