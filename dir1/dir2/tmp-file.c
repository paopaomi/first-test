//
//  tmp-file.c
//
//
//  Created by Gloria on 2019/7/28.
//  Copyright © 2019 Gloria. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define FILE_EXIST        0
#define FILE_NOT_EXIST    -1

/* ≈–∂œŒƒº˛ «∑Ò¥Ê‘⁄ */
int is_file_exist(char* filename)
{
    /* ≈–∂œŒƒº˛ «∑Ò¥Ê‘⁄ */
    if (access(filename, F_OK) != 0)
    {
        printf("file %s not exsit!\n", filename);
        return FILE_NOT_EXIST;
    }
    else
    {
        return FILE_EXIST;
    }
}

void stitch_whole_filename(char *whole_name,char *path, char *name)
{
    memset(whole_name, 0, strlen(whole_name));
    
    strcpy(whole_name, path);
    strcat(whole_name, name);
}

//FILE **file_process(int file_num,char **src_filename,char *dir)
FILE **file_process(int file_num)
{
    int i;
    char filename[256] ;
    long content_length;
    FILE **fp;
    fp = (FILE **)malloc(sizeof(FILE *)*file_num);

    for(i=0;i<file_num;i++)
    {
        fp[i] = NULL;
       // stitch_whole_filename(filename, dir, src_filename[i]);
        
        strcpy(filename,"tmp-file.c");
        if (is_file_exist(filename) == FILE_NOT_EXIST)
        {
            return NULL;
        }
        
        fp[i] = fopen(filename, "rb+");
        if (fp[i] == NULL)
        {
            printf("open file %s error!\n", filename);
            return NULL;
        }
        
        /* ªÒ»°Œƒº˛¥Û–° */
        fseek(fp[i], 0, SEEK_END);
        content_length += ftell(fp[i]);
        rewind(fp[i]);
        printf("fp[%d] address:0x%x,len: %d\n",i,&fp[i],content_length);
    }
    return fp;
}


int main()
{
    int i;
    FILE **fp;
    fp = file_process(5);
    printf("fp address:0x%x\n",fp);
    
    
    for (i = 0; i < 5; i++)
    {
        fclose(fp[i]);
        fp[i] = NULL;
    }
    free(fp);
    fp = NULL;
    return 0;
}
