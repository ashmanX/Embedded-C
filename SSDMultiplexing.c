
#include <reg51.h>
#define SSD P1

void UARTInit()
{
		TMOD = 0x20;
		SCON = 0x50;
		TH1 = 0xFD;
		TR1 = 1;
}

void delay(int z)
{
    int x, y;
    for (x = 0; x < z; x++)
    {
        for (y = 0; y < 3000; y++)
        {
        }
    }
}

void display()
{
		unsigned char num[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
		unsigned char first,second,third,fourth,sum1,sum2;
	
		printf("Enter the first 16bit number :");
		first = ReadBytePC();
		second = ReadBytePC();
		printf("Enter the second 16bits number: ");
		third = ReadBytePC();
		fourth = ReadBytePC();
	
		sum1 = second + fourth;
		sum2 = first + third;
		while(1)
		{
				P2 = 0x7;
				SSD = num[(sum2 & 0xF0) >> 4];
				delay(1);
				P2 = 0x0;
			
				P2 = 0xB;
				SSD = num[sum2 & 0x0F];
				delay(1);	
				P2 = 0x0;
			
				P2 = 0xD;
				SSD = num[(sum1 & 0xF0) >> 4];
				delay(1);
				P2 = 0x0;
			
				P2 = 0xE;
				SSD = num[sum1 & 0x0F];
				delay(1);
				P2 = 0x0;
		}
	
}


void main()
{
		UARTInit();
		while(1)
		{
			display();
		}
}
