#ifndef _SHELL_H_
#define _SHELL_H_

	/* std libraries */
	#include <stdlib.h>
	#include <stdio.h>
	#include <stddef.h>
	#include <unistd.h>
	#include <sys/types.h>
	#include <sys/wait.h>

	typedef struct list_s
	{
		char *path_dir;
		struct list_s *next;
	} dir_t;

	/* Global environemnt */
	extern char **environ;
	char **PATH;

	/* my_environ.c */
	void copy_env();
	void free_env(void);
	dir_t *_linked_path(char **paths);
	char **_paths(char *nombre);
	char *_getenv(const char *name);

	/* string_functions_1.c */
	char *_strcat(char *dest, const char *src);
	char *_strncat(char *dest, const char *src, size_t n);
	char *_strchr(char *s, char c);
	int _strlen(const char *s);
	int _strcmp(char *s1, char *s2);

	/* string_functions_2.c */
	unsigned int _strspn(char *s, char *accept);
	char *_strcpy(char *dest, const char *src);
	int _strncmp(const char *s1, const char *s2, size_t n);
	char *_strdup(const char *str);

	/* tiktok.c */
	char **strtok_emulator(char *str, char *delim);
	int cuenta_letras(char *str, char *delim);
	int cuenta_los_tokens(char *str, char *delim);
	void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

	/* single_linked_list.c */
	size_t print_list(const dir_t *h);
	dir_t *add_node_end(dir_t **head, const char *str);
	void free_list(dir_t *head);

	char *promp(void);

	char *spaces(char *input);


	/* fress.c */
	void _free(char **av);

	char **tokenizer(char *input, char *delim);
	
	int reinit_environ(char **ptr);

	int _getenv_index(char *name);

	char *getenv_format(char **av);
	

#endif
