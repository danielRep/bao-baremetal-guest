/**
 * SPDX-License-Identifier: GPL-2.0
 * Copyright (c) Bao Project and Contributors. All rights reserved.
 */

#include <psi5s_uart.h>
//#include <clocks.h>
#include <cpu.h>

#define LINFlexD_FRAME_ERROR_INT        (0x100)
#define LINFlexD_BUFFER_OVERRUN_INT     (0x80)
#define LINFlexD_RECEIVED_INT           (0X8)

#define clk_freq  (48000000U)

#define LIN_9_TX 0
#define LIN_9_RX 1
#define LIN_0_TX 2
#define LIN_0_RX 3

// ------- Specify Uart to be used -------
#define UART_TX_USED LIN_0_TX
#define UART_RX_USED LIN_0_RX
#define LinflexD_instance   0   // only 0 or 9 available
// ---------------------------------------

extern uint32_t CGM0_GetAC8_SelValue(const MC_CGM_0_Type * base);
//extern clock_user_config_t clock_InitConfig0;

linflexd_uart_state_t linflexdUartState0;

linflexd_uart_user_config_t linflexdUartInitConfig0 = {
    .transferType = LINFLEXD_UART_USING_INTERRUPTS,
    .baudRate = 115200UL,
    .parityCheck = false,
    .parityType = LINFLEXD_UART_PARITY_EVEN,
    .stopBitsCount = LINFLEXD_UART_ONE_STOP_BIT,
    .wordLength = LINFLEXD_UART_8_BITS,
    .rxDMAChannel = 0UL,
    .txDMAChannel = 0UL
};

 /* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0}
- pin_list:
  - {pin_num: AD2, peripheral: LINFlexD_0, signal: txd, pin_signal: PC_09}
  - {pin_num: AC3, peripheral: LINFlexD_0, signal: rxd, pin_signal: PC_10}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

#define NUM_OF_CONFIGURED_PINS0         7
/* Array of pin configuration structures */
pin_settings_config_t g_pin_mux_InitConfigArr0[NUM_OF_CONFIGURED_PINS0] =
{
    {           // Tx   LINFLEXD9
        .base                        = SIUL2_5,
        .pinPortIdx                  = 150u,
        .mux                         = PORT_MUX_ALT1,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .receiverSel                 = PORT_RECEIVER_ENABLE_DIFFERENTIAL_VREF,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL4,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
    },
    {           // Rx   LINFLEXD9
        .base                        = SIUL2_5,
        .pinPortIdx                  = 151u,// 42u
        .mux                         = PORT_MUX_AS_GPIO, // 0
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .receiverSel                 = PORT_RECEIVER_ENABLE_DIFFERENTIAL_VREF,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL4,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .intConfig                   =
        {
            .intEdgeSel              = SIUL2_INT_DISABLE
        },
        .inputMux[0]                 = PORT_INPUT_MUX_ALT2,
        .inputMuxReg[0]              = 466u,//0u,
        .inputMux[1]                 = PORT_INPUT_MUX_NO_INIT,
        .inputMux[2]                 = PORT_INPUT_MUX_NO_INIT,
        .inputMux[3]                 = PORT_INPUT_MUX_NO_INIT,
        .inputMux[4]                 = PORT_INPUT_MUX_NO_INIT,
        .inputMux[5]                 = PORT_INPUT_MUX_NO_INIT,
        .inputMux[6]                 = PORT_INPUT_MUX_NO_INIT,
        .inputMux[7]                 = PORT_INPUT_MUX_NO_INIT,
        .interleaveBase              = NULL,
    },
    {           // Tx   LINFLEXD0
        .base                        = SIUL2_0,
        .pinPortIdx                  = 0u,
        .mux                         = PORT_MUX_ALT1,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .receiverSel                 = PORT_RECEIVER_ENABLE_DIFFERENTIAL_VREF,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL4,
        .inputBuffer                 = PORT_INPUT_BUFFER_DISABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_ENABLED,
    },
    {           // Rx   LINFLEXD0
        .base                        = SIUL2_0,
        .pinPortIdx                  = 1u,// 42u
        .mux                         = PORT_MUX_AS_GPIO,
        .safeMode                    = PORT_SAFE_MODE_DISABLED,
        .receiverSel                 = PORT_RECEIVER_ENABLE_DIFFERENTIAL_VREF,
        .pullConfig                  = PORT_INTERNAL_PULL_NOT_ENABLED,
        .slewRateCtrlSel             = PORT_SLEW_RATE_CONTROL4,
        .inputBuffer                 = PORT_INPUT_BUFFER_ENABLED,
        .openDrain                   = PORT_OPEN_DRAIN_DISABLED,
        .outputBuffer                = PORT_OUTPUT_BUFFER_DISABLED,
        .intConfig                   =
        {
            .intEdgeSel              = SIUL2_INT_DISABLE
        },
        .inputMux[0]                 = PORT_INPUT_MUX_ALT2,
        .inputMuxReg[0]              = 47u,//559u,
        .inputMux[1]                 = PORT_INPUT_MUX_NO_INIT,
        .inputMux[2]                 = PORT_INPUT_MUX_NO_INIT,
        .inputMux[3]                 = PORT_INPUT_MUX_NO_INIT,
        .inputMux[4]                 = PORT_INPUT_MUX_NO_INIT,
        .inputMux[5]                 = PORT_INPUT_MUX_NO_INIT,
        .inputMux[6]                 = PORT_INPUT_MUX_NO_INIT,
        .inputMux[7]                 = PORT_INPUT_MUX_NO_INIT,
        .interleaveBase              = NULL,
    }
};


void psi5_uart_disable(volatile struct Psi5s_Uart * ptr_uart){

	uint32_t ctrl_reg = ptr_uart->control;					
	ctrl_reg &= ((~UART_CR_UARTEN) | (~UART_CR_TXE) | (~UART_CR_RXE));	
	ptr_uart->control = ctrl_reg;						

}


void psi5_uart_enable(volatile struct Psi5s_Uart * ptr_uart){

	uint32_t ctrl_reg = ptr_uart->control;				
	ctrl_reg |= (UART_CR_UARTEN | UART_CR_TXE | UART_CR_RXE);	
	ptr_uart->control = ctrl_reg;				

}


/*!
 * @brief Requests LINFlexD module to enter init mode.
 *
 * This function enters initialization mode.
 *
 * @param base LINFlexD base pointer.
 */
static inline void LINFLEXD_EnterInitMode(LINFlexD_Type *base)
{
    uint32_t regValTemp;

    regValTemp = base->LINCR1;
    regValTemp &= ~(LINFlexD_LINCR1_SLEEP_MASK);
    regValTemp |= LINFlexD_LINCR1_INIT(1UL);
    base->LINCR1 = regValTemp;
}


/*!
 * @brief Requests LINFlexD module to enter normal mode.
 *
 * This function enters normal mode. *
 *
 * @param base LINFlexD base pointer.
 */
static inline void LINFLEXD_EnterNormalMode(LINFlexD_Type *base)
{
    uint32_t regValTemp;

    regValTemp = base->LINCR1;
    regValTemp &= ~(LINFlexD_LINCR1_SLEEP_MASK);
    regValTemp &= ~(LINFlexD_LINCR1_INIT_MASK);
    base->LINCR1 = regValTemp;
}


static inline void LINFLEXD_SetIntegerBaudRate(LINFlexD_Type *base, uint32_t ibr)
{
    uint32_t regValTemp;

    regValTemp = base->LINIBRR;
    regValTemp &= ~(LINFlexD_LINIBRR_IBR_MASK);
    regValTemp |= LINFlexD_LINIBRR_IBR(ibr);
    base->LINIBRR = regValTemp;
}


static inline linflexd_state_t LINFLEXD_GetLinState(const LINFlexD_Type * base)
{
    //uint8_t state = (uint8_t)((base->LINSR & LINFlexD_LINSR_LINS_MASK) >> LINFlexD_LINSR_LINS_SHIFT);
    uint32_t state = (uint32_t)((base->LINSR & LINFlexD_LINSR_LINS_MASK) >> LINFlexD_LINSR_LINS_SHIFT);
    return (linflexd_state_t)state;
}

/*!
 * @brief Sets the LINFlexD mode.
 *
 * This function sets LIN or UART mode, based on the parameter received.
 *
 * @param base LINFlexD base pointer.
 * @param mode LINFlexD mode - UART/LIN.
 */
static inline void LINFLEXD_SetMode(LINFlexD_Type *base, linflexd_mode_t mode)
{
    uint32_t regValTemp;

    regValTemp = base->UARTCR;
    regValTemp &= ~(LINFlexD_UARTCR_UART_MASK);
    regValTemp |= LINFlexD_UARTCR_UART((uint32_t)mode);
    base->UARTCR = regValTemp;
}


//void psi5s_uart_set_baud_rate(volatile struct Psi5s_Uart * ptr_uart, uint32_t baud_rate){

bool /*status_t*/ LINFLEXD_UART_DRV_SetBaudRate(LINFlexD_Type * base, uint32_t baudrate)
{
    uint32_t mantissa;
    bool resetIdle = false;

    /* Compute the values for baud rate divider mantissa and fraction */
    mantissa = clk_freq / (baudrate * DEFAULT_OSR);

    if (LINFLEXD_GetLinState(base) != LINFlexD_STATE_INIT_MODE)
    {
        /* Request init mode and wait until the mode entry is complete */
        LINFLEXD_EnterInitMode(base);
        //while (LINFLEXD_GetLinState(base) != LINFlexD_STATE_INIT_MODE) {}

        resetIdle = true;
    }

    /* Write the computed values to registers */
    LINFLEXD_SetIntegerBaudRate(base, mantissa);

    if (resetIdle == true)
    {
        /* Enter normal mode */
        LINFLEXD_EnterNormalMode(base);
    }

    return true;//STATUS_SUCCESS;
}

//}

void clock_init(LINFlexD_Type * base){
    uint32_t *clock_mux = 0;
    switch(((uint32_t) base)){
        case LINFlexD_0_BASE:
        case LINFlexD_1_BASE:
        case LINFlexD_2_BASE:
            clock_mux = (uint32_t *) (MC_CGM_0 + MUX_CSC_4_OFFSET);
            break;
        case LINFlexD_3_BASE:
        case LINFlexD_4_BASE:
        case LINFlexD_5_BASE:
            clock_mux = (uint32_t *) (MC_CGM_1 + MUX_CSC_4_OFFSET);
            break;
        case LINFlexD_6_BASE:
        case LINFlexD_7_BASE:
        case LINFlexD_8_BASE:
            clock_mux = (uint32_t *) (MC_CGM_4 + MUX_CSC_8_OFFSET);
            break;
        case LINFlexD_9_BASE:
        case LINFlexD_10_BASE:
        case LINFlexD_11_BASE:
            clock_mux = (uint32_t *) (MC_CGM_5 + MUX_CSC_2_OFFSET);
            break;
        default: break;
    }
    *clock_mux = 0x00000000;
    *clock_mux |= SAFE_CLK_MASK(1);
    clock_mux = clock_mux + MUX_DIV0_OFFSET;
    *clock_mux = 0x80000000;
}

void psi5_uart_init(volatile struct Psi5s_Uart * ptr_uart) {

    LINFlexD_Type * base;
    linflexd_uart_user_config_t *uartUserConfig = &linflexdUartInitConfig0;

    PINS_Init(&g_pin_mux_InitConfigArr0[UART_TX_USED]);     //LIN0
    PINS_Init(&g_pin_mux_InitConfigArr0[UART_RX_USED]);

    base = (LINFlexD_Type *) s_LINFlexDBase[LinflexD_instance];

    clock_init(base);
    
    /* Request init mode and wait until the mode entry is complete */
    LINFLEXD_EnterInitMode(base);

    /* Set UART mode */
    LINFLEXD_SetMode(base, LINFlexD_UART_MODE);

    /* Set the baud rate */
    LINFLEXD_UART_DRV_SetBaudRate(base, 115200);

    /* Set word length */
    LINFLEXD_SetUartWordLength(base, uartUserConfig->wordLength);
    LINFLEXD_SetTxDataFieldLength(base, (uint8_t)((uint8_t)uartUserConfig->wordLength >> 1U));
    LINFLEXD_SetRxDataFieldLength(base, (uint8_t)((uint8_t)uartUserConfig->wordLength >> 1U));

    /* Set parity */
    LINFLEXD_SetParityControl(base, false);
    
        /* Enable FIFO for DMA based communication, or buffer mode for interrupt based communication */
    if (uartUserConfig->transferType == LINFLEXD_UART_USING_DMA)
    {
        LINFLEXD_SetTxMode(base, LINFLEXD_UART_RXTX_FIFO_MODE);
        LINFLEXD_SetRxMode(base, LINFLEXD_UART_RXTX_FIFO_MODE);
        LINFLEXD_SetRxEnable(base, 1);
    }
    else
    {
        LINFLEXD_SetTxMode(base, LINFLEXD_UART_RXTX_BUFFER_MODE);
        LINFLEXD_SetRxMode(base, LINFLEXD_UART_RXTX_BUFFER_MODE);
        LINFLEXD_SetRxEnable(base, 1);
    }

        /* Enter normal mode */
    LINFLEXD_EnterNormalMode(base);

        /* Enable error interrupts */
    //LINFLEXD_SetInterruptMode(base, LINFlexD_FRAME_ERROR_INT, true);
    //LINFLEXD_SetInterruptMode(base, LINFlexD_BUFFER_OVERRUN_INT, true);

        /* Enable Rx interrupt */
    LINFLEXD_SetInterruptMode(base, LINFlexD_RECEIVED_INT, true);
    LINFLEXD_SetRxEnable(base, 1);
}


uint32_t psi5_uart_getc(volatile struct Psi5s_Uart * ptr_uart){

	uint32_t data = 0;

	//wait until there is data in FIFO
	while(!(ptr_uart->flag & UART_FR_RXFE));

	data = ptr_uart->data;

    //limpar flag
	return data;

}


void psi5_uart_putc(volatile struct Psi5s_Uart * ptr_uart, int8_t c){

	uint8_t ca = c;
    LINFLEXD_UART_DRV_SendData(LinflexD_instance, &ca, 1);

}


void psi5_uart_puts(volatile struct Psi5s_Uart * ptr_uart,const char *s){
	while (*s)
	{
		psi5_uart_putc(ptr_uart,*s++);
	}

}
