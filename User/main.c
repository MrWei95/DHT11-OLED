#include "main.h"

char str[20];
uint8_t DHT_Buffer[5];

int main(void)
{
	OLED_Init();
	OLED_ShowChinese(20, 15, "温度");
	OLED_ShowChinese(20, 33, "湿度");
	
	while(1)
	{
		if(DHT_Get_Temp_Humi_Data(DHT_Buffer))						//成功收到返回值
		{
			sprintf(str, ":%d.%d", DHT_Buffer[2], DHT_Buffer[3]);	//温度
			OLED_ShowString(54, 15, (uint8_t *)str, OLED_8X16);
			OLED_Update();
			sprintf(str, ":%d.%d", DHT_Buffer[0], DHT_Buffer[1]);	//湿度
			OLED_ShowString(54, 33, (uint8_t *)str, OLED_8X16);
			OLED_Update();
		}
		delay_ms(1000);				//每秒刷新
	}
}
