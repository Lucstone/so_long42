/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:06:30 by lnaidu            #+#    #+#             */
/*   Updated: 2022/11/15 10:18:30 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst2;
	const char		*src2;
	size_t			i;

	i = 0;
	src2 = (const char *)src;
	dst2 = (unsigned char *)dst;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst);
}
/*
int main()
{
	char	str[] = "coucou";
	char	str2[] = "";

	char	str3[] = "coucou";
	char	str4[] = "";

	memcpy(str, str2, 3);
	printf("%s\n", str);

	ft_memcpy(str3, str4, 3);
	printf("%s\n", str3);

	return (0);
}*/
