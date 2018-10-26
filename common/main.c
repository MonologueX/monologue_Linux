#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "main.h"

int CreateMsg()
{
  key_t key = ftok(FILEPATH, PROJ_ID);
  if (key < 0)
  {
    perror("ftok");
    return -1;
  }
  int msgid = msggent(key, IPC_CREAT | IPC_EXCL, 0666);
  if (msgid < 0)
  {
    perror("msgget");
    return -1;
  }
  return msgid;
}

int OpenMsg();

int DestoryMsg();

int SendMsg();

int RecvMsg();
