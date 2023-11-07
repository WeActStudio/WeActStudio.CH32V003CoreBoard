/*---------------------------------------
- WeAct Studio Official Link
- taobao: weactstudio.taobao.com
- aliexpress: weactstudio.aliexpress.com
- github: github.com/WeActStudio
- gitee: gitee.com/WeAct-TC
- blog: www.weact-tc.cn
---------------------------------------*/

#include "board.h"

void board_led_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
}

void board_led_toggle(void)
{
    GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_4) == Bit_SET ? GPIO_ResetBits(GPIOC, GPIO_Pin_4) : GPIO_SetBits(GPIOC, GPIO_Pin_4);
}

void board_led_set(uint8_t set)
{
    if (set)
        GPIO_SetBits(GPIOC, GPIO_Pin_4);
    else
        GPIO_ResetBits(GPIOC, GPIO_Pin_4);
}
