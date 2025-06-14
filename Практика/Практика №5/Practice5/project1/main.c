#include <8051.h>
void main()
{
unsigned char i,j,c;
unsigned char *str = "00";
unsigned char row[5] = {0xFE, 0xFD, 0xFB, 0xF7};
unsigned char col[5] = {0x1E, 0x1D, 0x1B, 0x17};
unsigned char *num[16] = {"1","2","3","A",
						  "4","5","6","B",
						  "7","8","9","C",
						  "*","0","#","D"};
P0 = 0x38;
P2 = 0x1;
P2 = 0x0;
P0 = 0x80;
P2 = 0x1;
P2 = 0x0;
while(1){
for(i=0;i<4;i++)
{	
	P3=col[i];
	for(j=0;j<4;j++)
	{
	if(P1 == row[j])
	{
		str = num[i+j*4];
		for(c=0;c<1;c++)
		{  
			P0 = str[c];
			P2 = 0x3;
			P2 = 0x2;
		}
	}
	}
}
}

}
