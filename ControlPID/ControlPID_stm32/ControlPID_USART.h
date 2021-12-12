/*
 * File: ControlPID_USART.h
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

#ifndef RTW_HEADER_ControlPID_USART_h_
#define RTW_HEADER_ControlPID_USART_h_
#include "STM32_Config.h"

/* USART2_Tx_Initialization declaration. */
void USART2_Tx_Initialization(void);

/**
 * @brief USART Tx State structures definition
 */
typedef enum {
  SERIAL_TX_ON = 0x00,                 /*!< Tx serial communication started. */
  SERIAL_TX_OK = 0x01,               /*!< Tx serial communication terminated. */
  SERIAL_TX_OFF = 0x02                 /*!< Tx serial communication stopped. */
} SERIAL_TxStatusTypeDef;

/**
 * @brief SERIAL data information
 */
typedef struct SERIAL_TxConf {
  uint16_t nb2Send;                    /*!< Nb of char to send*/
  uint16_t nbSent;                     /*!< Nb sent char*/
  uint16_t nbMsgLost;       /*!< Nb lost msg (not enough space in ring buffer)*/
  uint16_t buffSize;                   /*!< Size of send ring buffer*/
  uint8_t* pTx_BuffStart;              /*!< point to ring buffer*/
  uint8_t* pTx_BuffEnd;                /*!< point to end ring buffer*/
  uint8_t* pTx_W;                      /*!< point to free space*/
  uint8_t* pTx_R;                      /*!< point to char to send*/
  void (* CopyData)(struct SERIAL_TxConf* pConf, uint8_t* pSrc, uint16_t
                    dataLength);
  void (* SendData)(struct SERIAL_TxConf* pConf);
  __IO SERIAL_TxStatusTypeDef txStatus;/*!< Usart send communication status.*/
  __IO uint8_t txLock;                 /*!< lock data access */
} SERIAL_TxConfTypeDef;

/* USART2 HAL handler. */
extern UART_HandleTypeDef huart2;

/* USART2 send configuration. */
extern SERIAL_TxConfTypeDef USART2_TxConf;
void TX_CopyData(struct SERIAL_TxConf*, uint8_t*, uint16_t);

/* USART2_TX_SendData declaration. */
void USART2_TX_SendData(struct SERIAL_TxConf*);

#endif                                 /* RTW_HEADER_ControlPID_USART_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] ControlPID_USART.h
 */
