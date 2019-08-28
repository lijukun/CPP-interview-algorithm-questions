/*  vs里找不到这个头文件  */
#include <unistd.h>
#include <sys/types.h>
int main()
{
	pid_t  pid = fork();
	if (pid < 0)
		printf("error in fork!");
	else if (pid == 0)
		printf("现在在子进程,我的进程号是%d\n", getpid());
	else
		printf("现在在父进程,我的进程号是 %\/n", getpid());

	return 0;
}