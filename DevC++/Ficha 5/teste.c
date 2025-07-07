#include <stdio.h>

char *oQueFaz(char *str);

int main() {
	char teste[] = "Prroovva de EExxammmee";
	oQueFaz(teste);
	printf(teste);
}

char *oQueFaz(char *str) {
    int i, j = 0;
    for (i = 0; str[i] != '\0'; i++) 
        if (str[i] != str[j]) 
			str[++j] = str[i];
        
    str[++j] = '\0';
    return str;
}
