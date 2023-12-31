#include "stm32f10x.h"
#include "delay.h"
#include "OLED.h"
#include "Timer.h"
#include "USART_Helper.h"
#include "MPU6500.h"
#include "stdio.h"
#include "AHT20.h"
#include "RTC_Helper.h"
#include "HWInterface.h"
#include "AnoPTv8.h"
#include "WS2812.h"
#include "BMP280_Helper.h"
#include "W25Qxx_Helper.h"
#include "../Rsc/image_qq.h"
#include "test.h"
#include "lcd.h"
#include "GUI.h"
#include "Touch.h"
#include "../Rsc/pic.h"

W25Qxx_Helper W25Q64_Data_main(GPIO_Pin_6);
void HardWareInit()
{
    delay_ms(200);
    //  WS2812_Init();
    LED_Init();
    USART_Helper_Init();
    OLED_Init();
    W25Q64_Data_main.Init();
    LCD_Init();

    // LCD_SetWindows(0, 0, 32 - 1, 32 - 1); // 窗口设置
    TP_Init();
    // AHT20_Init();
    //     RTC_Helper_Init();
    //     OLED_ShowNum(1,1,MPU6500_DMP_Init(),1);
    MPU6500_Init();

    // BMP280_Helper_Init();

    // printf("%s", "hello world");
}

uint8_t databuf[14];
void AnoPTv8TxFrameF1(float pitch, float yaw, float roll)
{
    databuf[0]  = BYTE0(pitch);
    databuf[1]  = BYTE1(pitch);
    databuf[2]  = BYTE2(pitch);
    databuf[3]  = BYTE3(pitch);
    databuf[4]  = BYTE0(yaw);
    databuf[5]  = BYTE1(yaw);
    databuf[6]  = BYTE2(yaw);
    databuf[7]  = BYTE3(yaw);
    databuf[8]  = BYTE0(roll);
    databuf[9]  = BYTE1(roll);
    databuf[10] = BYTE2(roll);
    databuf[11] = BYTE3(roll);
    AnoPTv8SendBuf(ANOPTV8DEVID_ALL, 0xF1, databuf, 12);
}
u32 i;
float value[3];
int main()
{
    HardWareInit();
    // Gui_LoadPicFromW25Qxx();
    //    LCD_DrawFillRectangle(0, 0, 50, 50);
    //    Gui_Drawbmp16(0, 0, gImage_test);
    //  Gui_DrawPic(100, 150, 40, 40, gImage_qq);
    OLED_ShowString(1, 1, "hello world");
    //  printf("hello world\t\n");

    // u8 ReadBuff[300] = {0};
    //  u8 writeBuff[10] = {0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19};
    // u8 writetest[300];
    // for (u16 i = 0; i < 300; i++) {
    //     writetest[i] = i;
    // }

    // W25Qxx_Helper_Write(24576 * 6, (u8 *)gImage_test, 24576);//24576*3 start

    // W25Q64_Data_main.Write(512, writetest, 300);
    // W25Q64_Data_main.Read(500, ReadBuff, 300);

    // OLED_ShowHexNum(2, 1, ReadBuff[0], 2);
    //   Touch_Test();
    AHT20_value AHT_value;
    //   MPU6500_Value MPU_value;
    //   MPU6500_StartAquire();
    //   OLED_ShowString(1, 1, "hello world");

    // SPI_Helper_WriteLen( 0x06, NULL, 0);
    // u8 ADDR[3] = {0x00, 0x00, 0x00};
    // SPI_Helper_WriteLen(GPIO_Pin_6, 0x02, ADDR, 3);
    // u8 Data[20] = {0x20, 0x80, 0x30};

    // u8 ReadCommend[3];
    // ReadCommend[0] = 0x00;
    // ReadCommend[1] = 0x00;
    // ReadCommend[2] = 0x00;
    // u8 Buff[20];
    // SPI_Helper_ReadLen(GPIO_Pin_6, 0x03, ReadCommend,);

    // OLED_ShowHexNum(3, 1, MPU6500_GetDeviceID(), 2);

    while (1) {
        // Gui_DrawPic(0, 0, 32, 32, gImage_test);

        // TP_Scan(0);
        // printf("x=%d\t\n,y=%d\t\n", tp_dev.x, tp_dev.y);
        //  AnoPTv8HwTrigger1ms();
        //   OLED_ShowHexNum(2, 1, MPU6500_GetAddr(), 2);
        //  OLED_ShowNum(2, 1, i++, 5);
        MPU6500_dmp_get_euler_angle(NULL, NULL, value, value + 1, value + 2);
        //  AnoPTv8TxFrameF1(value[0], value[1], value[2]);
        //  AnoPTv8HwTrigger1ms();
        printf("%s:%f\t\n", "pitch:", value[0]);
        printf("%s:%f\t\n", "roll:", value[1]);
        printf("%s:%f\t\n", "yaw:", value[2]);

        //AHT20_GetValue(&AHT_value);
        //    MPU6500_GetValue(&MPU_value);
        // printf("%s", "湿度:");
        // printf("%f\n", AHT_value.Humidity);
        // printf("%s", "温度:");
        // printf("%f\n", AHT_value.Temperature);
        //    printf("%s", "MPU输出:");
        //    printf("%f\t\n", MPU6500_GetTemperature());
        //   MPU6500_Send2Host(MPU_value.ACCEL_XOUT, MPU_value.ACCEL_YOUT, MPU_value.ACCEL_ZOUT,
        //                   MPU_value.GYRO_XOUT, MPU_value.GYRO_YOUT, MPU_value.GYRO_ZOUT);
        //   mpu_get_temperature(&temp, NULL);
        //   OLED_ShowNum(2, 1, temp, 10);

        // Delay_ms(100);
        // u8 i = 0 - 1;
        // while (i--) {
        // }
        LED_Turn();

        delay_ms(200);
    }
}