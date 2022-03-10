#include<bits/stdc++.h>
using namespace std;

void RLE(string str)
{
	int count;
	int checkASCII[256] = {0};
	
	for(int i=0; str[i] != '\0'; i++)
	{
		if(checkASCII[str[i]] == 0)
		{
			count = 0;			
			for(int j=0; str[j]!='\0'; j++)
			{
				if(str[i]==str[j])
				{
					count++;
				}
			}
			checkASCII[str[i]] = 1;
			printf("%c%d ", str[i], count);
		}
	}
	
	//printf("\n\nDone\n");
}

int main()
{	
	freopen("rleInput.txt", "r", stdin);
	freopen("rleOutput.txt", "w", stdout);
	
	string str;
	//cout<<"Enter Message: ";
	getline(cin, str);
	RLE(str);
	
	return 0;
}
