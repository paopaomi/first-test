//
//  tmp_uuid.c
//  demo
//
//  Created by Gloria on 2019/7/7.
//  Copyright © 2019 Gloria. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Create random UUID
 *
 * @param buf - buffer to be filled with the uuid string
 */
void random_uuid(char *buf)
{
    const char *c = "89ab";
    int n;
    for( n = 0; n < 16; ++n )
    {
        int b = rand()%255;
        switch( n )
        {
            case 6:
                sprintf(buf, "4%x", b%15 );
                break;
            case 8:
                sprintf(buf, "%c%x", c[rand()%strlen(c)], b%15 );
                break;
            default:
                sprintf(buf, "%02x", b);
                break;
        }
        
        buf += 2;
        switch( n )
        {
            case 3:
            case 5:
            case 7:
            case 9:
                *buf++ = '-';
                break;
        }
    }
    *buf = 0;
}

int main()
{
    int i = 0;
    char guid[37];
    
    while(i<10)
    {
        random_uuid(guid);
        printf("guid = %s\n", guid);
        i++;
    }
    
    return 0;
}
