#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<iostream>
#include<string.h>
#define EXE_DIR "/usr/local/lib/docxit/"

using namespace std;

#define TAGUSAGE "\
Usage:  docxit tag                                  show all tags\n\
        docxit tag <tag_name>                       tag current commit\n\
        docxit tag <tag_name> <full_commit_key>     tag specified commit\n\
        docxit tag -d <tag_name> [<tag_name> ...]   delete tags\n"

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        char *argv1[] = {(char *)"showTag", argv[1],NULL};
        if(execv(EXE_DIR"showTag", argv1) == -1)
        {
            perror(EXE_DIR"showTag");
            exit(0);
        }
    }
    else if(argc < 4)
    {
        char *argv1[] = {(char *)"createTag", argv[1], argv[2], NULL};
        if(execv(EXE_DIR"createTag", argv1) == -1)
        {
            perror(EXE_DIR"createTag");
            exit(0);
        }
    }
    else if(strcmp(argv[2], "-d") == 0)
    {
        for(int i = 3; i < argc; i++)
        {
            char *argv1[] = {(char *)"deleteTag", argv[1], argv[i], NULL};
            if(execv(EXE_DIR"deleteTag", argv1) == -1)
            {
                perror(EXE_DIR"deleteTag");
                exit(0);
            }
        }
    }
    else
    {
        char *argv1[] = {(char *)"createTag", argv[1], argv[2], argv[3], NULL};
        if(execv(EXE_DIR"createTag", argv1) == -1)
        {
            perror(EXE_DIR"createTag");
            exit(0);
        }
    }
}