#include "comm.h"

int createMsgQueue()
{
    key_t k = ftok(PATH_NAME, PROJ_ID);
    if (k < 0)
    {
        printf(ftok error);
        return -1;
    }

    int msgid =(k, )
}
