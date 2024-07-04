// Program to demo file operations
//
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int fd;
	int i, err = 0;
    char buf[10] = "";

	fd = creat("demo_file.txt", 0644);

	if (fd == -1)
	   printf("unable to create file\n");

	for (i = 0; i < 10; i++)
	   write(fd, "A", 1);

	close(fd);

	fd = open("demo_file.txt", O_RDONLY);

    err = lseek(fd, 5, SEEK_SET);

	if (err == -1)
           printf("Unable to seek\n");

	err = read(fd, buf, 5);

	if (err == -1)
		printf("read failed\n");

	printf("read: %s\n", buf);

    err = lseek(fd, 0, SEEK_END);

	if (err == -1)
           printf("Unable to seek to the EOF\n");

	err = read(fd, buf, 5);
	buf[err] = '\0'; // Null-terminate the buffer

	if (err == -1)
		printf("read failed\n");

	printf("read: %s\n", buf);
	close(fd);
}
