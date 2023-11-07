#include "debug.h"
#include "board.h"

/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */
int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

    SystemCoreClockUpdate();

    Delay_Init();

    board_led_init();

    USART_Printf_Init(115200);
    printf("SystemClk:%d\r\n",SystemCoreClock);
    printf( "ChipID:%08x\r\n", DBGMCU_GetCHIPID() );

    while(1)
    {
        Delay_Ms(500);
        board_led_toggle();
    }
}
