#pragma once
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define ROW 3
#define COL 3

typedef struct zanziqi
{
    int array[3][3];
    int win;
}sanziqi;

void Init(sanziqi **san);
void Print(sanziqi *san);
void PlayMove(sanziqi **san);
void Menu1();
void Menu2();
int IsWine(sanziqi *san);
void ComputerMove(sanziqi *san);
