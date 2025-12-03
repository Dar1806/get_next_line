#include "get_next_line.h"

int	main()
{
	int	fd;
	fd = open("test.txt", O_RDONLY);
	printf("%d\n", fd);
	return (fd);
}