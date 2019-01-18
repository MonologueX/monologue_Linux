#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>

#define IPC_KEY 0x12345678
#define TYPE_S 1
#define TYPE_C 2

struct msgbuf {
    long mtype;
    char mtext[1024];
};

int main()
{
    int msg_id = -1;
    msg_id = msgget(IPC_KEY, IPC_CREAT | 0644);
    if (msg_id < 0)
    {
        perror("msgget error");
        return -1;
    }
    while (1)
    {
        /* 先发送，后接收 */
        struct msgbuf buf;

        memset(&buf, 0x00, sizeof(struct msgbuf));
        buf.mtype = TYPE_C;
        scanf("%s", buf.mtext);
        msgsnd(msg_id, &buf, 1024, 0);

        memset(&buf, 0x00, sizeof(struct msgbuf));
        msgrcv(msg_id, &buf, 1024, TYPE_S, 0);
        printf("serve say:[%s]\n", buf.mtext);
    }
    msgctl(msg_id, IPC_RMID, NULL);
    return 0;
}
