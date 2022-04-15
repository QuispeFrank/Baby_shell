#ifndef _SHELL_H_
#define _SHELL_H_
	/* std libraries */
	#include <stdlib.h>
	#include <stdio.h>
	#include <stddef.h>
	 #include <signal.h>
	#include <unistd.h>
	#include <sys/types.h>
	#include <sys/wait.h>
	#include <string.h>
	/* Global environemnt */
	extern char **environ;

	/* functions */
	char **_copyenv(void);

	int _strlen(const char *s);
	char *_strcpy(char *dest, const char *src);
	char *_strcat(char *dest, const char *src);
	char *_strncat(char *dest, const char *src, size_t n);

	char *spaces(char *input);
	char *_strchr(char *s, char c);
	int _strspn(char *s, char *accept);
	int _strcmp(char *s1, char *s2);
	int _strncmp(const char *s1, const char *s2, size_t n);

	char **strtok_emulator(char *str, char *delim);
	int cuenta_letras(char *str, char *delim);
	int cuenta_los_tokens(char *str, char *delim);
	
	void valid_exec(char **av);
	char *promp(void);

	char **validation(char **arv);
	void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

	char **arv_to_execute(char **arv1, char *total);
	char **arv_for_execute(char **arv);
	void free_env(void);

	void _execve(char **argVec);
	void _free(char **av);
	char **tokenizer(char *input, char *delim);
#endif

