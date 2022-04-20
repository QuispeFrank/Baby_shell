#ifndef _SHELL_H_
#define _SHELL_H_

	/* std libraries */
	#include <stdlib.h>
	#include <stdio.h>
	#include <stddef.h>
	#include <unistd.h>
	#include <sys/types.h>
	#include <sys/wait.h>

	/**
	 * struct list_s - linked paths
	 * @path_dir: Pointer to one path directory. 
	 * @next: a pointer to the next node.
	 *
	 * Description: a linked list that contains all the
	 * directories contained in $PATH.
	 */
	typedef struct list_s
	{
		char *path_dir;
		struct list_s *next;
	} dir_t;

	/* Global environemnt */
	extern char **environ;
	char **PATH;

	/* my_environ.c */
	int already_exist_then_replace(char **av);
	char **douptr_cpy(char **dest, char **src);
	char **_dupdou_pointer_from(char **src);
	char *_getenv(const char *name);
	void free_env(void);

	/* my_environ2.c */
	char *_getenv_format(char **av);
	int _setenv(char **av);
	int reinit_environ(char **ptr);
	int _getenv_index(char *name);
	int _unsetenv(char **av);

	/* my_environ3.c */
	void copy_env();
	char **_paths(char *nombre);
	dir_t *_linked_path(char **paths);

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

	/* single_linked_list.c */
	size_t print_list(const dir_t *h);
	dir_t *add_node_end(dir_t **head, const char *str);
	void free_list(dir_t *head);

	/* promp.c */
	char *promp(void);

	/* spaces.c */
	char *spaces(char *input);

	/* fress.c */
	void _free(char **av);

	/* tokens.c */
	char **tokenizer(char *input, char *delim);

#endif
