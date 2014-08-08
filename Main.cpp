#include<iostream>
#include<string>
#include<ctime>
#include<windows.h>
#include <dos.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

using namespace std;
#include"CarMove.h"

int main()
{
	HideCursor();											/*隐藏光标输入*/
	setColor(0x000F,0x0000);								/*改变颜色*/
	RUN();

	return 0;
}