#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void print_str(const char *s)
{
	while (*s)
		write(1, s++, 1);
	write(1, "\n", 1);
}

void print_nbr(int n)
{
	char c;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		print_nbr(n / 10);
	c = '0' + (n % 10);
	write(1, &c, 1);
}

char add_one(unsigned int i, char c)
{
	(void)i;
	return (c + 1);
}

void add_one_char(unsigned int i, char *c)
{
	(void)i;
	*c += 1;
}

void print_content(void *ptr)
{
	if (ptr)
		print_str((char *)ptr);
}

void *dup_content(void *ptr)
{
	char *copy = ft_strdup((char *)ptr);
	if (!copy)
		return NULL;
	return copy;
}

int main(void)
{
	char s1[50] = "Hello";
	char *str, *dup, *joined, **split;
	t_list *lst, *node;

	// Part 1 Tests
	print_nbr(ft_isalpha('A')); write(1, "\n", 1);
	print_nbr(ft_isdigit('9')); write(1, "\n", 1);
	print_nbr(ft_isalnum('z')); write(1, "\n", 1);
	print_nbr(ft_isascii(127)); write(1, "\n", 1);
	print_nbr(ft_isprint(32)); write(1, "\n", 1);
	print_nbr(ft_strlen("42SG")); write(1, "\n", 1);
	ft_memset(s1, 'X', 3); print_str(s1);
	ft_bzero(s1, 5); print_str(s1);
	ft_memcpy(s1, "Test", 4); print_str(s1);
	ft_memmove(s1 + 1, s1, 4); print_str(s1);
	print_nbr(ft_strlcpy(s1, "ABCDE", 5)); write(1, "\n", 1);
	print_nbr(ft_strlcat(s1, "XYZ", 10)); write(1, "\n", 1);
	print_nbr(ft_toupper('a')); write(1, "\n", 1);
	print_nbr(ft_tolower('Z')); write(1, "\n", 1);
	print_str(ft_strchr("abcde", 'c'));
	print_str(ft_strrchr("abcdeabc", 'a'));
	print_nbr(ft_strncmp("abc", "abd", 2)); write(1, "\n", 1);
	print_str((char *)ft_memchr("abcde", 'c', 5));
	print_nbr(ft_memcmp("abc", "abd", 3)); write(1, "\n", 1);
	print_str(ft_strnstr("Hello42Singapore", "42", 10));
	print_nbr(ft_atoi("123")); write(1, "\n", 1);
	char *calloc_mem = ft_calloc(5, 1); calloc_mem[0] = 'A'; print_str(calloc_mem); free(calloc_mem);
	dup = ft_strdup("copy me"); print_str(dup); free(dup);

	// Part 2 Tests
	str = ft_substr("42Piscine", 2, 4); print_str(str); free(str);
	joined = ft_strjoin("Hello", "World"); print_str(joined); free(joined);
	str = ft_strtrim("  Hello  ", " "); print_str(str); free(str);
	split = ft_split("split this string", ' ');
	for (int i = 0; split[i]; i++) { print_str(split[i]); free(split[i]); }
	free(split);
	str = ft_itoa(-42); print_str(str); free(str);
	str = ft_strmapi("abc", add_one); print_str(str); free(str);
	char buf[] = "XYZ";
	ft_striteri(buf, add_one_char); print_str(buf);
	ft_putchar_fd('A', 1); write(1, "\n", 1);
	ft_putstr_fd("Test string", 1); write(1, "\n", 1);
	ft_putendl_fd("Hello there", 1);
	ft_putnbr_fd(-123, 1); write(1, "\n", 1);

	// Bonus Tests

	// Test ft_lstdelone safely
	t_list *temp = ft_lstnew(ft_strdup("Standalone"));
	ft_lstdelone(temp, free);

	// Main list tests
	lst = ft_lstnew(ft_strdup("First"));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("Second")));
	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("Zero")));
	print_nbr(ft_lstsize(lst)); write(1, "\n", 1);
	print_str((char *)ft_lstlast(lst)->content);
	node = ft_lstnew(ft_strdup("Third"));
	ft_lstadd_back(&lst, node);
	ft_lstiter(lst, print_content);

	// Map and clear
	t_list *mapped = ft_lstmap(lst, dup_content, free);
	ft_lstclear(&mapped, free);
	ft_lstclear(&lst, free);

	return 0;
}
