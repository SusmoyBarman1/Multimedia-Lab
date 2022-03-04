#include<bits/stdc++.h>
using namespace std;

void RLE(string str)
{
	int len = 0;
	int checkASCII[256] = {0};
	
	// performing RLE
	for(int i=0; str[i] != '\0'; i++)
	{
		len++;
		checkASCII[str[i]] = checkASCII[str[i]] + 1;
		//printf("%c=%d, checkASCII[%d]=%d\n", str[i], str[i], i, checkASCII[str[i]]); 
	}
	
	// Calculating probability
	double probabilityCH[256];
	for(int i=0; i<256; i++)
	{
		if(checkASCII[i] > 0)
		{
			probabilityCH[i] = checkASCII[i] / (double)len;
			printf("%c%d, probability: %lf\n", i, checkASCII[i], probabilityCH[i]);
		}
	}
	
	// performing arithmetic coding
	double upper = 0; 
	double lower = 0;
	double tempUpper = 0;
	double diff = 1;
	for(int i=0; str[i] != '\0'; i++)
	{
		int chStr = str[i];
		printf("\ndiff = %lf\n\n", diff);
		
		for(int i=0; i<256; i++)
		{
			if(checkASCII[i] > 0)
			{
				lower = tempUpper;
				upper = lower + (diff * probabilityCH[i]);
				printf("ch=%c, lower=%lf, upper=%lf, tempUpper=%lf\n", i, lower, upper, tempUpper);
				if(chStr == i)
				{
					diff = upper - lower;
					printf("\nLooking for new character.....\n\n");
					break;
				}
				else
				{
					tempUpper = upper;
				}
			}
		}
	}
	
	
	printf("\n\nThe Codeword is between [%lf, %lf)\n", lower, upper);
}

int main()
{
	string str;
	getline(cin, str);
	RLE(str);
	
	return 0;
}
