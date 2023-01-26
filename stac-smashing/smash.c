
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_authentication(char *pwd){

	int Auth_flag=0;
	char password[16];

	strcpy(password, pwd);

	if (strcmp(password, "Cyb3rTech!")==0) Auth_flag=1;
	if (strcmp(password, "AA@Ahmed")==0) Auth_flag=1;
	return Auth_flag;
}

int main(int argc, char *argv[]){

	if (check_authentication(argv[1])) {
		printf("\nAccess granted\n");
	}
	else
		printf("\nAccess denied\n");

}
