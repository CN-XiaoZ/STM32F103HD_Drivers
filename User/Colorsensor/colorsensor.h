#ifndef __COLORSENSOR_H
#define __COLORSENSOR_H

#define DeviceAddr 0xb4
#define RAddr 0x0c
#define GAddr 0x0d
#define BAddr 0x0e
#define ConfigAddr 0x10
#define Order Single_WriteI2C_byte
#define GetData Single_ReadI2C

void WhiteBalance(int light);
void Light(int light);
int GetColor(void);


#endif
