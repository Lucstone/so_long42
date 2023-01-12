/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:41:52 by lnaidu            #+#    #+#             */
/*   Updated: 2022/11/15 10:53:36 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}
/*
int main() {

    const char * source = "The C Language";
    char * destination;
    char * pointer;
    int length = strlen( source );

    destination = (char *) malloc( sizeof( char) * (length+1) );
    strcpy( destination, source );

    while (pointer = strchr( destination, 'a' ) ) {
        *pointer = 'A';
    }

    printf( "Result : %s\n", destination );

    free( destination );

    return 0;
}*/
