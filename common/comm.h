#ifdef _COMM_H_
#define _COMM_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define PATH_NAME "/TMP"
#define PROJ_ID Ox8888

createMsgQueue();
getMsgQueue();
sendMsg();
recvMsg();
destoryMsgQueue();


#endif
