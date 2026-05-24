#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int		get_dict_size(char *dict);
char	*store_dict_to_buff(char *dict, int size);

int		get_dict_size(char *dict)
{
	int		fd;
	int		success_read;
	int		sum_read;
	char	buff[67];

	fd = open(dict, O_RDONLY);
	if (fd == -1)
		return (-1);
	success_read = read(fd, buff, 67);
	sum_read = 0;
	while (success_read > 0)
	{
		sum_read += success_read;
		success_read = read(fd, buff, 67);
	}
	close(fd);
	return (sum_read);
}

char	*store_dict_to_buff(char *dict, int size)
{
	int		fd;
	char	*buff;

	buff = malloc(size + 1);
	if (!buff)
		return ((void *)0);
	fd = open(dict, O_RDONLY);
	if (fd == -1)
	{
		free(buff);
		return ((void *)0);
	}
	read(fd, buff, size);
	buff[size] = '\0';
	close(fd);
	return (buff);
}