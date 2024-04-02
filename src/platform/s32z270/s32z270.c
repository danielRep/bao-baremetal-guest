#include <psi5s_uart.h>
#include <linflexd_uart.h>


struct Psi5s_Uart *uart  = /*(LINFlexD_Type*)*/ (void*) 0x40170000;    //Linflexd0
// struct Psi5s_Uart *uart  = /*(LINFlexD_Type*)*/ (void*) 0x42980000;    //Linflexd9

struct LINFlexD{
    uint32_t LINCR1;          /**< LIN Control Register 1, offset: 0x0 */
    uint32_t LINIER;          /**< LIN Interrupt Enable Register, offset: 0x4 */
    uint32_t LINSR;           /**< LIN Status Register, offset: 0x8 */
    uint32_t LINESR;          /**< LIN Error Status Register, offset: 0xC */
    uint32_t UARTCR;          /**< UART Mode Control Register, offset: 0x10 */
    uint32_t UARTSR;          /**< UART Mode Status Register, offset: 0x14 */
    uint32_t LINTCSR;         /**< LIN Time-Out Control Status Register, offset: 0x18 */
    uint32_t LINOCR;          /**< LIN Output Compare Register, offset: 0x1C */
    uint32_t LINTOCR;         /**< LIN Time-Out Control Register, offset: 0x20 */
    uint32_t LINFBRR;         /**< LIN Fractional Baud Rate Register, offset: 0x24 */
    uint32_t LINIBRR;         /**< LIN Integer Baud Rate Register, offset: 0x28 */
    uint32_t LINCFR;          /**< LIN Checksum Field Register, offset: 0x2C */
    uint32_t LINCR2;          /**< LIN Control Register 2, offset: 0x30 */
    uint32_t BIDR;            /**< Buffer Identifier Register, offset: 0x34 */
    uint32_t BDRL;            /**< Buffer Data Register Least Significant, offset: 0x38 */
    uint32_t BDRM;            /**< Buffer Data Register Most Significant, offset: 0x3C */
    uint8_t RESERVED_0[12];
    uint32_t GCR;             /**< Global Control Register, offset: 0x4C */
    uint32_t UARTPTO;         /**< UART Preset Timeout Register, offset: 0x50 */
    uint32_t UARTCTO;         /**< UART Current Timeout Register, offset: 0x54 */
    uint32_t DMATXE;          /**< DMA Tx Enable Register, offset: 0x58 */
    uint32_t DMARXE;          /**< DMA Rx Enable Register, offset: 0x5C */
};

void uart_init(void)
{
    psi5_uart_init(uart);
    psi5_uart_enable(uart);

    return;
}

void uart_putc(char c)
{
    psi5_uart_putc(uart, c);
}

char uart_getchar(void)
{
    return psi5_uart_getc(uart);
}

void uart_enable_rxirq(){

}

void uart_clear_rxirq(){
    // struct LINFlexD *temp = (void*) 0x42980000;
    struct LINFlexD *temp = (void*) 0x40170000;
    //while(!(temp->UARTSR & 0x200));
    unsigned char data = temp->BDRM;
    temp->UARTSR |= 4;
}
