#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
pid_t pid = fork();
if (pid == 0) {
printf("Parent Process ID : %d\n", getppid());
printf("Child Process ID : %d\n", getpid());
}
else {     
wait(NULL);
printf("In Parent Process\n");
printf("Parent Process ID : %d\n", getppid()); 
printf("Child Process ID : %d\n", pid);
}
return 0;
}
