#include <stdio.h>
int main()
{
	char s[81];
	int i;
	if(fgets(s, 81, stdin))
	for(i=0; s[i]; i++)
	
		if(s[i]=='a'||s[i]=='b')s[i]-=32;
		
	puts(s);
 	return 0;
 }
