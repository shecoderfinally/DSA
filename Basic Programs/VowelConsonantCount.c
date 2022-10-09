/* C Program to count vowels and consonants in a String */
 
#include <stdio.h>
 
int main()
{
  	char str[100];
  	char *s = str;
  	int vowels, consonants;
  	vowels = consonants = 0;
 
  	printf("\n Please Enter any String :  ");
  	gets(str);
  	
  	while (*s)
  	{
  		if(*s == 'a' || *s == 'e' || *s == 'i' || *s == 'o' || *s == 'u' ||
		*s == 'A' || *s == 'E' || *s == 'I' || *s == 'O' || *s == 'U')  
		{
  			vowels++;  	
 		}
  		else
    		consonants++;
    	s++;
	}
    printf("\n Number of Vowels in this String = %d", vowels);  
	printf("\n Number of Consonants in this String = %d", consonants);   	
  
  	return 0;
}
