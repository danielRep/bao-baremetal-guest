
#include <linflexd_uart.h>

#define NULL ((void *)0)
/* Array of pointers to UART driver runtime state structures */
//static linflexd_uart_state_t * s_uartLINFlexDStatePtr[LINFlexD_INSTANCE_COUNT] = {NULL};


uint32_t CGM0_GetAC8_SelValue(const MC_CGM_0_Type * base)
{
    return ((base->MUX[8].CSS & MC_CGM_0_CSS_SELSTAT_MASK) >> MC_CGM_0_CSS_SELSTAT_SHIFT);
}


/*!
 * @brief Sets the word length.
 *
 * This function sets the word length in UART mode.
 * Should be called only when the module is in init mode.
 *
 * @param base LINFlexD base pointer.
 * @param length UART mode word length.
 */
void LINFLEXD_SetUartWordLength(LINFlexD_Type *base, linflexd_uart_word_length_t length)
{
    uint32_t regValTemp;

    regValTemp = base->UARTCR;
    regValTemp &= ~(LINFlexD_UARTCR_WL0_MASK);
    regValTemp |= LINFlexD_UARTCR_WL0((uint32_t)length & 1U);
    regValTemp &= ~(LINFlexD_UARTCR_WL1_MASK);
    regValTemp |= LINFlexD_UARTCR_WL1(((uint32_t)length >> 1U) & 1U);
    base->UARTCR = regValTemp;
}


/*!
 * @brief Sets the transmission data field length/FIFO depth.
 *
 * This function sets either the transmission data field length or the number of bytes in the Tx FIFO, according to
 * the current transmission mode.
 * Should be called only when the module is in init mode.
 *
 * @param base LINFlexD base pointer.
 * @param length data field length/FIFO depth.
 */
void LINFLEXD_SetTxDataFieldLength(LINFlexD_Type *base, uint8_t length)
{
    uint32_t regValTemp;

    regValTemp = base->UARTCR;
    regValTemp &= ~(LINFlexD_UARTCR_TDFL_TFC_MASK);
    regValTemp |= LINFlexD_UARTCR_TDFL_TFC(length);
    base->UARTCR = regValTemp;
}


/*!
 * @brief Sets the reception data field length/FIFO depth.
 *
 * This function sets either the reception data field length or the number of bytes in the Rx FIFO, according to
 * the current reception mode.
 *
 * @param base LINFlexD base pointer.
 * @param length data field length/FIFO depth.
 */
void LINFLEXD_SetRxDataFieldLength(LINFlexD_Type *base, uint8_t length)
{
    uint32_t regValTemp;

    regValTemp = base->UARTCR;
    regValTemp &= ~(LINFlexD_UARTCR_RDFL_RFC_MASK);
    regValTemp |= LINFlexD_UARTCR_RDFL_RFC(length);
    base->UARTCR = regValTemp;
}


/*!
 * @brief Enables/disables parity bit.
 *
 * This function enables or disables the parity bit from UART bytes.
 * Should be called only when the module is in init mode.
 *
 * @param base LINFlexD base pointer.
 * @param enable true - enable parity queuing/checking, false - disable parity queuing/checking.
 */
void LINFLEXD_SetParityControl(LINFlexD_Type *base, bool enable)
{
    uint32_t regValTemp;

    regValTemp = base->UARTCR;
    regValTemp &= ~(LINFlexD_UARTCR_PCE_MASK);
    regValTemp |= LINFlexD_UARTCR_PCE(enable ? 1UL : 0UL);
    base->UARTCR = regValTemp;
}

/*!
 * @brief Sets the number of stop bits for Rx.
 *
 * This function sets the number of stop bits for received bytes.
 *
 * @param base LINFlexD base pointer.
 * @param stopBitsCount number of stop bits.
 */
void LINFLEXD_SetRxStopBitsCount(LINFlexD_Type *base, linflexd_uart_stop_bits_count_t stopBitsCount)
{
    uint32_t regValTemp;

    regValTemp = base->UARTCR;
    regValTemp &= ~(LINFlexD_UARTCR_SBUR_MASK);
    regValTemp |= LINFlexD_UARTCR_SBUR(stopBitsCount);
    base->UARTCR = regValTemp;
}


/*!
 * @brief Sets the number of stop bits for Tx.
 *
 * This function sets the number of stop bits for transmitted bytes.
 * Should be called only when the module is in init mode.
 *
 * @param base LINFlexD base pointer.
 * @param defaultOffset - true - use the memory map defined in the header file to access the register;
 *                      - false - use custom memory map to access the register.
 * @param stopBitsCount number of stop bits.
 */
void LINFLEXD_SetTxStopBitsCount(LINFlexD_Type *base, linflexd_uart_stop_bits_count_t stopBitsCount,
                                               bool defaultOffset)
{
    uint32_t regValTemp;
    (void)defaultOffset;
    regValTemp = base->GCR;
    regValTemp &= ~(LINFlexD_GCR_STOP_MASK);
    regValTemp |= LINFlexD_GCR_STOP(stopBitsCount);
    base->GCR = regValTemp;
}


/*!
 * @brief Sets the transmission mode (FIFO/Buffer).
 *
 * This function sets the transmission mode (FIFO/Buffer).
 * Should be called only when the module is in init mode.
 *
 * @param base LINFlexD base pointer.
 * @param mode tx mode: FIFO/Buffer.
 */
void LINFLEXD_SetTxMode(LINFlexD_Type *base, linflexd_uart_rxtx_mode_t mode)
{
    uint32_t regValTemp;

    regValTemp = base->UARTCR;
    regValTemp &= ~(LINFlexD_UARTCR_TFBM_MASK);
    regValTemp |= LINFlexD_UARTCR_TFBM((uint32_t)mode);
    base->UARTCR = regValTemp;
}

/*!
 * @brief Sets the reception mode (FIFO/Buffer).
 *
 * This function sets the reception mode (FIFO/Buffer).
 * Should be called only when the module is in init mode.
 *
 * @param base LINFlexD base pointer.
 * @param mode rx mode: FIFO/Buffer.
 */
void LINFLEXD_SetRxMode(LINFlexD_Type *base, linflexd_uart_rxtx_mode_t mode)
{
    uint32_t regValTemp;

    regValTemp = base->UARTCR;
    regValTemp &= ~(LINFlexD_UARTCR_RFBM_MASK);
    regValTemp |= LINFlexD_UARTCR_RFBM((uint32_t)mode);
    base->UARTCR = regValTemp;
}

void LINFLEXD_SetRxEnable(LINFlexD_Type *base, uint32_t enable)
{
    uint32_t regValTemp;

    regValTemp = base->UARTCR;
    regValTemp |= LINFlexD_UARTCR_RxEn(enable);
    base->UARTCR = regValTemp;

    regValTemp = base->LINIER;
    regValTemp = (uint32_t) LINIER_DRIE;    
    base->LINIER = regValTemp;
}

/*!
 * @brief Enables/disables an UART interrupt.
 *
 * This function configures whether the UART event will trigger an interrupt.
 *
 * @param base LINFlexD base pointer.
 * @param intSrc UART interrupt source.
 * @param enable true - enable interrupt, false - disable interrupt.
 */
void LINFLEXD_SetInterruptMode(LINFlexD_Type * base, uint32_t/*linflexd_interrupt_t*/ intSrc, bool enable)
{
    uint32_t regValTemp;

    regValTemp = base->LINIER;
    if (enable)
    {
        regValTemp |= (uint32_t)intSrc;
    }
    else
    {
        regValTemp &= ~(uint32_t)intSrc;
    }
    base->LINIER = regValTemp;
}



/*!
 * @brief Enables/disables transmitter.
 *
 * This function enables or disables the UART transmitter, based on the parameter received.
 * Should be called only when the module is in UART mode.
 *
 * @param base LINFlexD base pointer.
 * @param enable enable/disable transmitter.
 */
void LINFLEXD_SetTransmitterState(LINFlexD_Type *base, bool enable)
{
    uint32_t regValTemp;

    regValTemp = base->UARTCR;
    regValTemp &= ~(LINFlexD_UARTCR_TxEn_MASK);
    regValTemp |= LINFlexD_UARTCR_TxEn(enable ? 1UL : 0UL);
    base->UARTCR = regValTemp;
}

/*!
 * @brief Clears an UART interrupt flag.
 *
 * This function clears the UART status flag received as parameter.
 *
 * @param base LINFlexD base pointer.
 * @param flag UART status flag.
 */
void LINFLEXD_ClearStatusFlag(LINFlexD_Type * base, linflexd_uart_status_flag_t flag)
{
    base->UARTSR = flag;
}



/*!
 * @brief Sets the first byte of the tx data buffer.
 *
 * This function writes one byte to the tx data buffer.
 *
 * @param base LINFlexD base pointer.
 * @param data data byte.
 */
void LINFLEXD_SetTxDataBuffer1Byte(LINFlexD_Type * base, uint8_t data)
{
    uint32_t regValTemp;

    regValTemp = base->BDRL;
    regValTemp &= ~(LINFlexD_BDRL_DATA0_MASK);
    regValTemp |= LINFlexD_BDRL_DATA0(data);
    base->BDRL = regValTemp;
}


static inline uint8_t LINFLEXD_GetLinState(const LINFlexD_Type * base)
{
    uint8_t state = (uint8_t)((base->LINSR & LINFlexD_LINSR_LINS_MASK) >> LINFlexD_LINSR_LINS_SHIFT);
    return state;
}

void LINFLEXD_UART_DRV_PutData(uint32_t instance, const uint8_t * txBuff)
{
    LINFlexD_Type * base;

    base = s_LINFlexDBase[instance];

    /* Wait for transmission to end */
    while (LINFLEXD_GetLinState(base) == 7 || LINFLEXD_GetLinState(base) == 8);
    LINFLEXD_SetTxDataBuffer1Byte(base, *txBuff);

}

/*!
 * @brief Gets the first byte of the rx data buffer.
 *
 * This function retrieves one byte from the rx data buffer.
 *
 * @param base LINFlexD base pointer.
 * @return data byte.
 */
uint8_t LINFLEXD_GetRxDataBuffer1Byte(LINFlexD_Type * base)
{
    return (uint8_t)(base->BDRM & LINFlexD_BDRM_DATA4_MASK);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : LINFLEXD_UART_DRV_StartSendUsingInterrupts
 * Description   : Initiate (start) a transmit by beginning the process of
 * sending data and enabling the interrupt.
 * This is not a public API as it is called from other driver functions.
 *
 *END**************************************************************************/
uint32_t/*status_t*/ LINFLEXD_UART_DRV_StartSendUsingInterrupts(uint32_t instance,
                                                           const uint8_t * txBuff,
                                                           uint32_t txSize)
{
    LINFlexD_Type * base;

    base = s_LINFlexDBase[instance];

    /* Enable the transmitter */
    LINFLEXD_SetTransmitterState(base, true);

    /* Clear the tx empty flag to make sure the transmission of the first byte
     * doesn't occur right after enabling the tx interrupt
     */
    LINFLEXD_ClearStatusFlag(base, LINFlexD_UART_DATA_TRANSMITTED_FLAG);

    /* Enable transmission complete interrupt */
    //LINFLEXD_SetInterruptMode(base, 1 /*LINFlexD_DATA_TRANSMITTED_INT*/, true);

    /* Transmit the first word */
    LINFLEXD_UART_DRV_PutData(instance, txBuff);

    return 0;//STATUS_SUCCESS;
}



/*FUNCTION**********************************************************************
 *
 * Function Name : LINFLEXD_UART_DRV_SendData
 * Description   : This function sends data using LINFlexD module in UART mode
 * with non-blocking method.
 *
 * Implements    : LINFLEXD_UART_DRV_SendData_Activity
 *END**************************************************************************/
uint32_t/*status_t*/ LINFLEXD_UART_DRV_SendData(uint32_t instance,
                                    const uint8_t * txBuff,
                                    uint32_t txSize)
{
    uint32_t/*status_t*/ retVal = 0;
    retVal = LINFLEXD_UART_DRV_StartSendUsingInterrupts(instance, txBuff, txSize);
    return retVal;
}


#define SIUL2_NUM_OF_PIN_PORT           16u


void PINS_WritePin(GPIO_Type * const base,
                                 pins_channel_type_t pin,
                                 pins_level_type_t value)
{
    pins_channel_type_t pinsValues = (pins_channel_type_t)base->PGPDO;
    pinsValues &= (pins_channel_type_t)(~((pins_channel_type_t)1U << (15U - pin)));
    pinsValues |= (pins_channel_type_t)(((pins_channel_type_t)value & 1U) << (15U - pin));
    base->PGPDO = pinsValues;
}

void PINS_Init(const pin_settings_config_t * config)
{
    uint32_t pinsValues = 0U;
    uint8_t inputMuxIterator;

        /* Get the SIUL2 base for interrupt pin if using */
        //interruptBase = SIUL2_1;

	pinsValues |= SIUL2_1_MSCR_OBE(config->outputBuffer);
    pinsValues |= SIUL2_1_MSCR_ODE(config->openDrain);
    pinsValues |= SIUL2_1_MSCR_IBE(config->inputBuffer);
    pinsValues |= SIUL2_1_MSCR_SRE(config->slewRateCtrlSel);
    pinsValues |= SIUL2_1_MSCR_RCVR(config->receiverSel);
    pinsValues |= SIUL2_1_MSCR_SMC(config->safeMode);
    pinsValues |= SIUL2_1_MSCR_SSS(config->mux);

    /* Configure initial value for GPIO pin in GPIO mux */
    if ((PORT_MUX_AS_GPIO == config->mux) && (PORT_OUTPUT_BUFFER_ENABLED == config->outputBuffer))
    {
        PINS_WritePin((GPIO_Type *) config->base->MSCR[config->pinPortIdx], 
                        (pins_channel_type_t)(config->pinPortIdx % SIUL2_NUM_OF_PIN_PORT), pinsValues);
    }

    /* Write to Multiplexed Signal Configuration Register register */
    config->base->MSCR[config->pinPortIdx] = pinsValues;

    // INPUT (Rx) Config Only
    if (PORT_INPUT_BUFFER_ENABLED == config->inputBuffer)
    {
        for (inputMuxIterator = 0U; inputMuxIterator < FEATURE_SIUL2_INPUT_MUX_WIDTH; inputMuxIterator++)
        {
            /* Check if input mux information needs to be configured */
            if (config->inputMux[inputMuxIterator] != PORT_INPUT_MUX_NO_INIT)
            {
                /* Write to Input Mux register */
                config->base->IMCR[config->inputMuxReg[inputMuxIterator]] =
                                SIUL2_AE_IMCR_SSS(config->inputMux[inputMuxIterator]);
            }
        }


        //DEV_ASSERT(config->intConfig.eirqPinIdx < SIUL2_INTERRUPT_COUNT);
        /* Get the appropriate value follow index of pin interrupt */
        //pinIntValue = (1UL << config->intConfig.eirqPinIdx);
        
        /* Mask interrupts by clearing the EIREn bits in DIRER0 */
        //interruptBase->DIRER0 &= ~pinIntValue;
    }
}
