#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
  int fd = open("./myfifo", O_RDONLY);
  if (fd < 0)
  {
    perror("open");
    return 1;
  }

    printf("open ok!\n");
  while (1)
  {
    char buf[1024] = {0};
    ssize_t read_size = read(fd, buf, sizeof(buf) - 1);
    if (read_size < 0)
    {
      perror("read");
      return 1;
    }

    if (read_size == 0)
    {
      perror("read done");
      return 0;
    }
    buf[read_size] = '\0';
    printf("%s\n", buf);
  }
  close(fd);
  return 0;
}
