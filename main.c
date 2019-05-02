#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int pw_len = 3;
	int last = pw_len-1;
	int i = 0;
	int tmp = 0;
	char *char_set = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	int char_set_len = strlen(char_set)-1;
	char *passwd_string = NULL;
	int *cipher_brute_force_count_list = NULL;
	
	cipher_brute_force_count_list = (int *)malloc(sizeof(int)*pw_len);
	memset(cipher_brute_force_count_list, 0, sizeof(int)*pw_len);
	
	passwd_string = (char *)malloc(sizeof(char)*(pw_len+1));
	memset(passwd_string, '\0', pw_len+1);
	memset(passwd_string, char_set[0], pw_len);
	
	// Brute Force passwd_stirng
	// Ex : len = 5
	// [0, 0, 0, 0, 0]  = "aaaaa"
	// [0, 0, 0, 0, 1]  = "aaaab"
	//       ...
	// [0, 0, 0, 0, 61] = "aaaa9"
	// [0, 0, 0, 1, 0]  = "aaaba"
	while(1){
		printf("%s \n", passwd_string);
		/*
		if(strcmp(passwd_string, "99999") == 0){
			printf("%s \n", passwd_string);
			break;
		}*/
		if(++cipher_brute_force_count_list[last] > char_set_len){
			for(i=last; i!=0; i--){
				if(cipher_brute_force_count_list[i] > char_set_len){
					tmp = ++cipher_brute_force_count_list[i-1];
					passwd_string[i-1] = char_set[tmp];
					cipher_brute_force_count_list[i] = 0;
					passwd_string[i] = char_set[0];
				}
			}
			if(cipher_brute_force_count_list[i] > char_set_len){
				break;
			}
		}
		tmp = cipher_brute_force_count_list[last];
		passwd_string[last] = char_set[tmp];
	}
	
	free(cipher_brute_force_count_list);
	free(passwd_string);
	
	return 0;
}
