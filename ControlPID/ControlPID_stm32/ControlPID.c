/*
 * File: ControlPID.c
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
#include "ControlPID_private.h"

/* GPIOB output mask value definition. */
uint16_t GPIOB_maskWrite;

/* Block signals (default storage) */
B_ControlPID ControlPID_B;

/* Block states (default storage) */
DW_ControlPID ControlPID_DW;

/* Real-time model */
RT_MODEL_ControlPID ControlPID_M_;
RT_MODEL_ControlPID *const ControlPID_M = &ControlPID_M_;

/* Model step function */
void ControlPID_step(void)
{
  real_T rtb_error;
  real_T rtb_TSamp;
  real_T rtb_v;
  real_T rtb_Saturation1;
  if (ControlPID_DW.stateControl == 1.0) {
    ControlPID_DW.stateControl = 0.0;
    rtb_error = ControlPID_DW.Ref - ControlPID_DW.rads;
    rtb_TSamp = 0.0008954 * rtb_error * 0.089540000000000008;
    rtb_v = ((rtb_TSamp - ControlPID_DW.UD_DSTATE) + 0.0121 * rtb_error) +
      ControlPID_DW.DiscreteTimeIntegrator_DSTATE;
    if (rtb_v > 8.37) {
      rtb_Saturation1 = 8.37;
    } else if (rtb_v < 0.0) {
      rtb_Saturation1 = 0.0;
    } else {
      rtb_Saturation1 = rtb_v;
    }

    ControlPID_B.duty = 100.0 * rtb_Saturation1 / 8.37;
    ControlPID_DW.UD_DSTATE = rtb_TSamp;
    ControlPID_DW.DiscreteTimeIntegrator_DSTATE += ((rtb_Saturation1 - rtb_v) *
      32.231404958677686 + 0.39 * rtb_error) * 0.01;

    {
      if (ControlPID_B.duty != TIM15_Conf.CH2_duty) {
        TIM15_Conf.CH2_duty = ControlPID_B.duty;
        if (ControlPID_B.duty >= 0) {
          /* Channel2 duty cycle is an input port. */
          __HAL_TIM_SET_COMPARE(&htim15,TIM_CHANNEL_2,(uint32_t)
                                (ControlPID_B.duty * (&htim15)->Instance->ARR /
            100));
        }
      }
    }
  }

  {
    /* Set GPIOB output mask value. */
    GPIOB_maskWrite = GPIOB->ODR;
    GPIOB_maskWrite &= 0xFFBD ;
    GPIOB_maskWrite |= (uint16_t)1.0 << 1;
    GPIOB_maskWrite |= (uint16_t)0.0 << 6;

    /* Write GPIOB input value */
    GPIOB->ODR = (uint16_t)GPIOB_maskWrite;
  }

  {
  }
}

/* Model initialize function */
void ControlPID_initialize(void)
{
  {
    /* user code (Start function Header) */
    {
      /* TIM6 initialization. */
      /* Store TIM6 informations and its handler. */
      G_TIM_Conf[G_TIM_Count] = &TIM6_Conf;
      G_TIM_Handler[G_TIM_Count] = &htim6;
      G_TIM_Count++;

      /* Store TIM information. */
      TIM6_Conf.TIM_Prescaler = 79;
      TIM6_Conf.TIM_APBClock = 80000000;
      TIM6_Conf.TIM_ARR = 9999 - 1;
      TIM6_Conf.TIM_Clock = 1.0E+6;
      TIM6_Conf.TIM_Freq = 100.01;
      TIM6_Conf.CH1_duty = 0.0;
      TIM6_Conf.CH2_duty = 0.0;
      TIM6_Conf.CH3_duty = 0.0;
      TIM6_Conf.CH4_duty = 0.0;
      TIM6_Conf.CH1_type = UNKNOWN;
      TIM6_Conf.CH2_type = UNKNOWN;
      TIM6_Conf.CH3_type = UNKNOWN;
      TIM6_Conf.CH4_type = UNKNOWN;

      /* Interrupt handler default initialization. */
      TIM6_Conf.ItUpFcn = NULL;
      TIM6_Conf.ItTrgFcn = NULL;
      TIM6_Conf.ItComFcn = NULL;
      TIM6_Conf.ItBrkFcn = NULL;
      TIM6_Conf.ItCcFcn = NULL;

      /* Update interrupt function. */
      TIM6_Conf.ItUpFcn = TIM6_ItUpFcn;

      /* Auto-reload preload enable */
      /*****Bugzilla 63376 *****/
      /*SET_BIT((&htim6)->Instance->CR1,TIM_CR1_ARPE);*/

      /* Update register value with blockset value. */
      /* Prescaler. */
      __HAL_TIM_SET_PRESCALER(&htim6,TIM6_Conf.TIM_Prescaler);

      /* Autoreload: ARR. */
      __HAL_TIM_SET_AUTORELOAD(&htim6,9999 - 1);

      /* Update registers before start operation to come. */
      HAL_TIM_GenerateEvent(&htim6,TIM_EVENTSOURCE_UPDATE);
    }

    {
      /* TIM15 initialization. */
      /* Store TIM15 informations and its handler. */
      G_TIM_Conf[G_TIM_Count] = &TIM15_Conf;
      G_TIM_Handler[G_TIM_Count] = &htim15;
      G_TIM_Count++;

      /* Store TIM information. */
      TIM15_Conf.TIM_Prescaler = 39;
      TIM15_Conf.TIM_APBClock = 80000000;
      TIM15_Conf.TIM_ARR = 50 - 1;
      TIM15_Conf.TIM_Clock = 2.0E+6;
      TIM15_Conf.TIM_Freq = 40000.0;
      TIM15_Conf.CH1_duty = 0.0;
      TIM15_Conf.CH2_duty = 0.0;
      TIM15_Conf.CH3_duty = 0.0;
      TIM15_Conf.CH4_duty = 0.0;
      TIM15_Conf.CH1_type = UNKNOWN;
      TIM15_Conf.CH2_type = OUTPUT_PWM;
      TIM15_Conf.CH3_type = UNKNOWN;
      TIM15_Conf.CH4_type = UNKNOWN;

      /* Interrupt handler default initialization. */
      TIM15_Conf.ItUpFcn = NULL;
      TIM15_Conf.ItTrgFcn = NULL;
      TIM15_Conf.ItComFcn = NULL;
      TIM15_Conf.ItBrkFcn = NULL;
      TIM15_Conf.ItCcFcn = NULL;

      /* Auto-reload preload enable */
      /*****Bugzilla 63376 *****/
      /*SET_BIT((&htim15)->Instance->CR1,TIM_CR1_ARPE);*/

      /* Update register value with blockset value. */
      /* Prescaler. */
      __HAL_TIM_SET_PRESCALER(&htim15,TIM15_Conf.TIM_Prescaler);

      /* Autoreload: ARR. */
      __HAL_TIM_SET_AUTORELOAD(&htim15,50 - 1);

      /* Set CH2 Pulse value. */
      __HAL_TIM_SET_COMPARE(&htim15,TIM_CHANNEL_2,(uint32_t)((50 - 1)/2));

      /* Update registers before start operation to come. */
      HAL_TIM_GenerateEvent(&htim15,TIM_EVENTSOURCE_UPDATE);
    }

    /* user code (Start function Body) */

    /* USART2 initialization for send. */
    USART2_Tx_Initialization();

    {
      /* External interrupt function registering. */
      EXTI_Callback[0] = EXTI0_Callback;
    }

    {
      /* TIM6 Start. */
      /* Starts the TIM Base generation in interrupt mode. */
      HAL_TIM_Base_Start_IT(&htim6);

      /* Start interrupt for Update event*/
      HAL_TIM_Base_Start_IT(&htim6);
    }

    {
      /* TIM15 Start. */

      /* Wait for htim15 State READY. */
      while ((&htim15)->State == HAL_TIM_STATE_BUSY) {
      }

      HAL_TIM_PWM_Start(&htim15,TIM_CHANNEL_2);
    }
  }
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] ControlPID.c
 */
