#include <stdio.h>
int main()
{
	char s[81];
	int i;
	/*считывание символов строки + ввод*/
	if(fgets(s, 81, stdin))
	
	/*пробегаемся по строке циклом и меняем а на А*/
	for(i=0; s[i]; i++){
		if(s[i]=='a') s[i] = s[i]-32;
	}
	
	/*пробегаемся по строке циклом и меняем b на B*/
	for(i=0; s[i]; i++){
		if(s[i]=='b') s[i] =s[i]-32;
	}
	
	/*Вывод строки*/
	puts(s);
 	return 0;
 }
