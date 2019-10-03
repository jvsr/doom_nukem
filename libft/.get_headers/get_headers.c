/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_headers.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/02 22:49:44 by pholster       #+#    #+#                */
/*   Updated: 2019/10/02 22:49:44 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

#include "get_headers.h"

t_header	*g_prv = NULL;
t_header	*g_head = NULL;

static void	add_header(char *line)
{
	char		*dup;
	t_header	*header;
	size_t		offset;

	dup = strdup(&line[10]);
	if (dup == NULL)
		exit(1);
	offset = (size_t)(strchr(dup, '\"')) - (size_t)dup;
	dup[offset] = '\0';
	header = (t_header *)malloc(sizeof(t_header));
	if (header == NULL)
		exit(1);
	header->name = dup;
	header->next = NULL;
	if (g_head == NULL)
		g_head = header;
	else
		g_prv->next = header;
	g_prv = header;
}

static void	get_headers(FILE *file)
{
	ssize_t	len;
	char	*line;

	len = 0;
	line = NULL;
	len = getline(&line, (size_t *)&len, file);
	while (len > 0)
	{
		if (strncmp(line, "#include \"", 10) == 0)
			add_header(line);
		len = 0;
		free(line);
		line = NULL;
		len = getline(&line, (size_t *)&len, file);
	}
}

static void	read_files(int argc, char **argv)
{
	size_t	i;
	FILE	*file;

	i = 0;
	while (i < (argc - 1))
	{
		file = fopen(argv[i + 2], "r");
		if (file == NULL)
		{
			dprintf(2, "Error(%d): %s - %s\n", errno, argv[2], strerror(errno));
			exit(errno);
		}
		get_headers(file);
		fclose(file);
		i++;
	}
}

static void	remove_duplicates(void)
{
	t_header	*cur;
	t_header	*next;

	cur = g_head;
	while (cur != NULL)
	{
		next = cur->next;
		while (next != NULL && strcmp(cur->name, next->name) == 0)
		{
			cur->next = next->next;
			free(next);
			next = cur->next;
		}
		cur = next;
	}
}

int			main(int argc, char **argv)
{
	char	*includes_path;

	argc--;
	if (argc == 0)
		dprintf(2, "Error: provide includes path and c files\n");
	if (argc == 0 || argc == 1)
		exit(1);
	includes_path = argv[1];
	read_files(argc, argv);
	sort_headers(&g_head);
	remove_duplicates();
	while (g_head != NULL)
	{
		printf("%s/%s\n", includes_path, g_head->name);
		g_head = g_head->next;
	}
	return (0);
}
