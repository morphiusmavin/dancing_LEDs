/* dancing leds 
	stack from left
	stack from right
	stack from left (reverse)
	stack from right (reverse)
	sym pattern (3x)
*/

#include <stdio.h>

unsigned char mask[4] = { 0x81, 0x42, 0x24, 0x18 };

int main(void)
{
	int i;
	int j;
	int k;
	int m;
	unsigned char test;
	unsigned char test2;
	unsigned char mask2;
	
	j = 0;
//	printf("\nstack from left\n");
	test = test2 = 0;
	for(k = 0;k < 8;k++)
	{
		mask2 = 0x80;
		for(i = 0;i < 8-k;i++)
		{
			test |= mask2;
			mask2 >>= 1;
			printf("0x%x, ",test | test2);
			test = 0;
			j++;
		}
		mask2 = 0x80;
		mask2 >>= 7-k;
		test2 |= mask2;
		printf("\n");
	}

	printf("\n");		
	printf("total: %d\n",j);

	test = 0;
	printf("0x%x, ",test);
	j++;
//	printf("\nstack from right\n");
	test = test2 = 0;
	for(k = 0;k < 8;k++)
	{
		mask2 = 1;
		for(i = 0;i < 8-k;i++)
		{
			test |= mask2;
			mask2 <<= 1;
			printf("0x%x, ",test | test2);
			test = 0;
			j++;
		}
		mask2 = 1;
		mask2 <<= 7-k;
		test2 |= mask2;
		printf("\n");
	}

	printf("\n");		
	printf("total: %d\n",j);

//	printf("\nstack from left (reverse)\n");
	test = 0xff;
	test2 = 0xff;
	for(k = 0;k < 8;k++)
	{
		mask2 = 0x80;
		for(i = 0;i < 8-k;i++)
		{
			test &= ~mask2;
			mask2 >>= 1;
			printf("0x%x, ",test & test2);
			test = 0xff;
			j++;
		}
		mask2 = 0x80;
		mask2 >>= 7-k;
		test2 &= ~mask2;
		printf("\n");
	}

	printf("\n");		
	printf("total: %d\n",j);

	test = 0xff;
	printf("0x%x, ",test);
	j++;
//	printf("\nstack from right (reverse)\n");
	test2 = 0xff;
	for(k = 0;k < 8;k++)
	{
		mask2 = 1;
		for(i = 0;i < 8-k;i++)
		{
			test &= ~mask2;
			mask2 <<= 1;
			printf("0x%x, ",test & test2);
			test = 0xff;
			j++;
		}
		mask2 = 1;
		mask2 <<= 7-k;
		test2 &= ~mask2;
		printf("\n");
	}

	printf("\n");		
	printf("total: %d\n",j);

//	printf("\nsym pattern\n");
	for(k = 0;k < 3;k++)
	{
		test = 0;
		
		for(i = 0;i < 4;i++)
		{
			test |= mask[i];
			printf("0x%x, ",test);
			printf("0x%x, ",test);
			test = 0;
			j+= 2;
		}
		printf("\n");
		for(i = 2;i >= 0;i--)
		{
			test |= mask[i];
			printf("0x%x, ",test);
			printf("0x%x, ",test);
			test = 0;
			j+= 2;
		}
		printf("\n");
	}
	for(k = 0;k < 3;k++)
	{
		test = 0xff;
		for(i = 0;i < 4;i++)
		{
			test &= ~mask[i];
			printf("0x%x, ",test);
			printf("0x%x, ",test);
			test = 0xff;
			j++;
		}
		printf("\n");
		for(i = 2;i >= 0;i--)
		{
			test &= ~mask[i];
			printf("0x%x, ",test);
			printf("0x%x, ",test);
			test = 0xff;
			j++;
		}
		printf("\n");
	}
	printf("\n");		
	printf("total: %d\n",j);

//	printf("\nsingle digit from right w/ opp moving bit\n");
	
	test2 = 0x80;
	for(k = 0;k < 8;k++)
	{
		test = 0;
		mask2 = 1;

		for(i = 0;i < 8;i++)
		{
			test |= mask2;
			mask2 <<= 1;
			printf("0x%x, ",test | test2);
			test = 0;
			j++;
		}
		test2 >>= 1;
		printf("\n");
	}
	
	printf("\n");		
	printf("total: %d\n",j);

//	printf("\nsingle digit from left w/ opp moving bit\n");
	test2 = 1;
	for(k = 0;k < 8;k++)
	{
		mask2 = 0x80;
		test = 0;
		for(i = 0;i < 8;i++)
		{
			test |= mask2;
			mask2 >>= 1;
			printf("0x%x, ",test | test2);
			test = 0;
			j++;
		}
		test2 <<= 1;
		printf("\n");
	}
	
}	
