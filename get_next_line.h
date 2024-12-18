/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saskin <saskin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:54:44 by saskin            #+#    #+#             */
/*   Updated: 2024/12/18 20:04:46 by saskin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
char *get_new_buffer(char *buffer);
int found_new_line(char *buffer);
char *ft_strjoin(char *s1, char *s2);
char *ft_strchr(const char *s, int c);
char *ft_strdup(const char *s1);
size_t ft_strlen(const char *s);
char *read_line(int fd, char *remainder);
char *get_new_line(char *buffer);
char *get_next_line(int fd);
#endif
