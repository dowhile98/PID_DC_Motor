/*
 * File: ControlPID.h
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

#ifndef RTW_HEADER_ControlPID_h_
#define RTW_HEADER_ControlPID_h_
#include "ControlPID_TIM.h"
#include "ControlPID_USART.h"
#include "STM32_Config.h"
#include "ControlPID_External_Functions.h"
#include "ControlPID_EXTI.h"
#ifndef ControlPID_COMMON_INCLUDES_
# define ControlPID_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ControlPID_COMMON_INCLUDES_ */

#include "ControlPID_types.h"

/* GPIOB output mask value declaration. */
extern uint16_t GPIOB_maskWrite;

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T duty;                         /* '<S8>/duty' */
  uint32_T Buff;                       /* '<S1>/MATLAB Function1' */
  uint16_T USART_Send;                 /* '<S1>/USART_Send' */
  uint16_T NbChar;                     /* '<S1>/MATLAB Function1' */
} B_ControlPID;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S9>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S7>/Discrete-Time Integrator' */
  real_T stateControl;                 /* '<Root>/para realizar el control' */
  real_T Ref;                          /* '<Root>/referencia' */
  real_T rads;                         /* '<Root>/velocidad (rad//s)' */
  real_T pulses;                       /* '<Root>/pulsos del encoder' */
} DW_ControlPID;

/* Real-time Model Data Structure */
struct tag_RTM_ControlPID {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_ControlPID ControlPID_B;

/* Block states (default storage) */
extern DW_ControlPID ControlPID_DW;

/* Model entry point functions */
extern void ControlPID_initialize(void);
extern void ControlPID_step(void);

/* Real-time Model object */
extern RT_MODEL_ControlPID *const ControlPID_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S9>/Data Type Duplicate' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ControlPID'
 * '<S1>'   : 'ControlPID/ISR lectura rads//s'
 * '<S2>'   : 'ControlPID/PID'
 * '<S3>'   : 'ControlPID/lectura pulsos encoder '
 * '<S4>'   : 'ControlPID/task'
 * '<S5>'   : 'ControlPID/ISR lectura rads//s/MATLAB Function'
 * '<S6>'   : 'ControlPID/ISR lectura rads//s/MATLAB Function1'
 * '<S7>'   : 'ControlPID/PID/PID'
 * '<S8>'   : 'ControlPID/PID/Subsystem'
 * '<S9>'   : 'ControlPID/PID/PID/Discrete Derivative'
 */
#endif                                 /* RTW_HEADER_ControlPID_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] ControlPID.h
 */
