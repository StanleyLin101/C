#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MaxLineLen 1024
#define MaxWordLen 1024
int main(int argc,char* argv[])
{
    char line[MaxLineLen];
    int old_pattern_wordcnt ;
    if(argc == 4)
    {
        old_pattern_wordcnt = strlen(argv[2]);
    }
    if(argc == 3)
    {
        old_pattern_wordcnt = strlen(argv[1]);
    }
    char *ptr;
    char *temp_ptr;
    if(((strcmp(argv[1],"-s")==0 ||strcmp(argv[1],"-e")==0) && argc == 4)|| argc == 3)
    {
        while(fgets(line,MaxLineLen,stdin))
        {
            ptr=line;
            while(*ptr)
            {
                if(argc == 3)
                {
                    char *substr = argv[1];
                    temp_ptr = strstr(ptr, substr);
                    if(temp_ptr)
                    {
                        while(temp_ptr - ptr)
                        {
                            printf("%c",*ptr);
                            ptr++;
                        }
                        printf("%s",argv[2]);
                        ptr = temp_ptr + old_pattern_wordcnt;
                    }
                    else
                    {
                        printf("%s",ptr);
                        break;
                    }
                }
                if(strcmp(argv[1],"-s")==0 && argc == 4)
                {
                    char *substr = argv[2];
                    temp_ptr = strstr(ptr, substr);
                    if(temp_ptr)
                    {
                        while(temp_ptr - ptr)
                        {
                            printf("%c",*ptr);
                            ptr++;
                        }
                        printf("%s",argv[3]);
                        ptr = temp_ptr + old_pattern_wordcnt;
                    }
                    else
                    {
                        printf("%s",ptr);
                        break;
                    }
                }
                if(strcmp(argv[1],"-e")==0 && argc == 4)
                {
                    char *substr = argv[2];
                    temp_ptr = strstr(ptr, substr);
                    int temp_ptr_ptr_dis = 0;
                    char *qtr = ptr;
                    if(temp_ptr && (isspace(*(temp_ptr+old_pattern_wordcnt)) || *(temp_ptr+old_pattern_wordcnt) == '\t' || *(temp_ptr+old_pattern_wordcnt) == '\n' ))
                    {
                        while(temp_ptr - ptr)
                        {
                            printf("%c",*ptr);
                            ptr++;
                            temp_ptr_ptr_dis ++;
                        }
                        if(isspace(*(qtr+temp_ptr_ptr_dis-1)) ||*(qtr+temp_ptr_ptr_dis-1) == '\t'||!*(qtr+temp_ptr_ptr_dis-1))
                        {
                            printf("%s",argv[3]);
                            ptr = temp_ptr + old_pattern_wordcnt;
                        }
                        else
                        {
                            printf("%c",*ptr);
                            ptr++;
                        }
                    }
                    else
                    {
                        if(temp_ptr)
                        {
                            printf("%c",*ptr);
                            ptr++;
                        }
                        else
                        {
                            printf("%s",ptr);
                            break;
                        }
                    }
                }
            }
        }
    }
    else
    {
        printf("選項錯誤\n");
        exit(1);
    }
    return 0;
}
