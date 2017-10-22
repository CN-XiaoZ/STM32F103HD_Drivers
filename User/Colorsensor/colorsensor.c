#include "./IIC/IIC.h"
#include "./Colorsensor/colorsensor.h"
#include "./delay/delay.h"

void WhiteBalance(int light)
{
    int n;
    n = 0x01;
    n = (light << 4) | n;
    Order(DeviceAddr, ConfigAddr, n);
}

void Light(int light)
{
    int n;
    n = 0x00;
    n = (light << 4) | n;
    Order(DeviceAddr, ConfigAddr, n);
}

int GetColor(void)
{
    int CR, CG, CB;
    u8 color[9] = {0};
    GetData(DeviceAddr, RAddr, color, 1);
    CR = color[0];
    delay_ms(50);
    GetData(DeviceAddr, GAddr, color, 1);
    CG = color[0];
    delay_ms(50);
    GetData(DeviceAddr, BAddr, color, 1);
    CB = color[0];
    delay_ms(50);
    if (CR > CG && CR > CB)
        return 1; //红色
    if (CG > CB && CG > CR)
        return 2; //绿色
    if (CB > CR && CB > CG)
        return 3; //蓝色
}