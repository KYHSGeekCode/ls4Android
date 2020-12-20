#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

int listdir(const char *path)
{
    struct dirent *entry; 
    DIR *dp;
    dp = opendir(path);
    if (dp == NULL) 
    { 
        perror("opendir");
        return -1; 
    } 
    while((entry = readdir(dp)))
    {
        puts(entry->d_name);
        printf("%d\r\n",entry->d_type);
    }
    closedir(dp); 
    return 0;
}

int main(int argc, char **argv)
{
    listdir(argv[1]);
    return 0;
}
