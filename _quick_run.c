#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
// https://stackoverflow.com/questions/744766/how-to-compare-ends-of-strings-in-c
int str_ends_with(const char *str, const char *suffix)
{
    if (!str || !suffix)
        return 0;
    size_t lenstr = strlen(str);
    size_t lensuffix = strlen(suffix);
    if (lensuffix >  lenstr)
        return 0;
    return strncmp(str + lenstr - lensuffix, suffix, lensuffix) == 0;
}


int main(int argc, char* argv[]){
    if(argc < 2){
        printf("Too less args!\n");
        return 0;
    }

    char* execute_name = argv[1];
    if(!str_ends_with(execute_name, ".c")){
		strcat(execute_name, ".c");
	}

	int len = strlen(execute_name) + 1;

	char opt_name[len - 2];
	memcpy(opt_name, execute_name, len - 2 - 1);
	opt_name[len - 2 - 1] = '\0';
	
	// printf(execute_name);
	
    char* gcc_args[] = {
        "gcc",
        execute_name,   // 源文件
        "-o", opt_name, // 输出的可执行文件名，可自定义
        NULL            // execvp 要求以 NULL 结尾
    };

    pid_t pid = fork();
    if(pid == 0){
        // 子进程：执行 gcc
        execvp("gcc", gcc_args);
        // 只有 exec 失败才会走到这里
        perror("execvp gcc failed");
        exit(1);
    }

    // 父进程：等待 gcc 编译完成
    int status;
    waitpid(pid, &status, 0);

    if(!WIFEXITED(status) || WEXITSTATUS(status) != 0){
        printf("编译失败！\n");
        return 1;
    }

    char run_path[len + 2];
    snprintf(run_path, sizeof(run_path), "./%s", opt_name);

    char* run_args[] = { run_path, NULL  };
    execvp(run_path, run_args);

    // 只有 exec 失败才会走到这里
    perror("execvp run failed");
    return 1;

	
}
