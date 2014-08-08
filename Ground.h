

void setColor(unsigned short ForeColor=3,unsigned short BackGroundColor=0)   /*设置颜色函数*/
       //给参数默认值
{ 
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE); //
    SetConsoleTextAttribute(hCon,ForeColor|BackGroundColor); 
         
}



int Time_difference(int in_time,int now_time)
{									/*求时间差的函数*/
	int h,m,s,h2,m2,s2;

	h=in_time/10000;
	h2=now_time/10000;
	m=(in_time/100)%100;
	m2=(now_time/100)%100;
	s=in_time%100;
	s2=now_time%100;

	int time;

	if(s2-s<0)
	{
		time=s2+60-s;
		m2--;
	}
	else
		time=s2-s;
	
	if(m2-m<0)
	{
		time+=(m2+60-m)*100;
		h2--;
	}
	else
		time+=(m2-m)*100;
	
	if(h2-h<0)
		time+=(h2+24-h)*10000;
	else
		time+=(h2-h)*100;
	
	return time;
}

int Time_change(int x)
{
	int m;

	if(x/10000>0)
		m+=(x/10000)*3600;

	if((x/100)%100>0)
		m+=((x/100)%100)*60;

	return m+=x%100;
}

int Gettime()
{									                                	/*获取系统时间函数*/
	SYSTEMTIME sys;
	GetLocalTime(&sys); 
	return sys.wHour*10000+sys.wMinute*100+sys.wSecond;
}

void Create_ground(int ground[][12])
{												/*建立停车场*/
	
	int i,j;
	
	for(i=0;i<13;i++)                           /*墙*/
		for(j=0;j<12;j++)
			ground[i][j]=4;
	
	for(i=1;i<12;i++)                          /*过道*/            
		for(j=1;j<11;j++)
			ground[i][j]=2;
	
	for(i=2;i<11;i+=2)                         /*车位*/
		for(j=2;j<10;j++)
			ground[i][j]=0;
	
	ground[0][1]=6;
	ground[0][10]=6;
	ground[12][1]=5;
	ground[12][10]=5;
	
}

void show_ground(int gro[][12],int flag)
{												/*显示停车场*/
	int i,j,count=0;

	cout<<"\t\t\tThe Parking Management System\n"<<endl;
	for(i=0;i<13;i++)
	{                     
		for(j=0;j<12;j++)
		{
			if(j==0)
				cout<<"\t  ";
		
			if(gro[i][j]==0)
				cout<<" [ ] ";
			else if(gro[i][j]==1)
			{
				cout<<" [";
				setColor(0x00002,0x0000);
				cout<<"*";
				setColor(0X000F,0x0000);
				cout<<"] ";
				count--;
			}
			else if(gro[i][j]==2)
				cout<<" ... ";
			else if(gro[i][j]==3)
			{
				if(flag==3)
				{
					setColor(FOREGROUND_RED,0x0000);
					cout<<"  *  ";
					setColor(0X000F,0x0000);
				}
				else
				{
					setColor(0x0001,0x0000);
					cout<<"  *  ";
					setColor(0X000F,0x0000);
				}
			}
			else if(gro[i][j]==4)
				cout<<" XXX ";
			else if(gro[i][j]==5)
				cout<<" >>> ";
			else if(gro[i][j]==6)
				cout<<" <<< ";
		}
		cout<<endl;
	}
	cout<<"\n\tXXX: Wall\t>>>: Entrance\t <<<: EXIT\t[ ]: No car\t\n\t...: Aisle";
	setColor(0x0004,0x0000);
	cout<<"\t *";
	setColor(0x000F,0x0000);

	cout<<" : In_Car";
	setColor(0x0001,0x0000);
	cout<<"\t  *";
	setColor(0x000F,0x0000);

	cout<<" : Out_Car";

	cout<<"\t[";
	setColor(0x0002,0x0000);
	cout<<"*";
	setColor(0x000F,0x0000);
	cout<<"]: Occupied"<<endl;
	
}

int Menu(string s,int x[][12])
{														/*菜单选择效果函数*/
	int KEY=0,flag=1;

	cout<<"\n\t\t\t\t"<<s<<"\n\n\t\t\t\t  >>是 <-\n\t\t\t\t  >>否 ";
	while(1)
	{		
		if(KEY==72)
		{
			system("cls");
			show_ground(x,0);
			cout<<"\n\t\t\t\t"<<s<<"\n\n\t\t\t\t  >>是 <-\n\t\t\t\t  >>否 ";
			flag=1;
		}
		else if(KEY==80)
		{
			system("cls");
			show_ground(x,0);
			cout<<"\n\t\t\t\t"<<s<<"\n\n\t\t\t\t  >>是 \n\t\t\t\t  >>否 <-\n";
			flag=0;
		}
		if(KEY==13)
			return flag;
		KEY=getch();
	}
}

void HideCursor()																					/*隐藏光标*/
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void DisHideCursor()																				/*显示光标*/
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 1}; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}


int SystemMenu()
{																					/**系统菜单*/

	int KEY=0,flag=1,num=0;
	while(1)
	{
		switch(num)
		{
			case 0:{	system("cls");
			cout<<"\n\n\n\t\t    ***************************************"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    *        欢迎使用停车管理系统         *"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    ***************************************"<<endl;
			cout<<"      \n\t\t\t请使用上下键来选择您想使用的功能："<<endl;
			cout<<"     \n\t\t\t<*> 预览停车场               <-   "<<endl;
			cout<<"       \t\t\t<*> 运行系统                      "<<endl;
			cout<<"       \t\t\t<*> 查看您的车的停车情况          "<<endl;
			cout<<"       \t\t\t<*> 查看当前的停车历史记录        "<<endl;												
			cout<<"       \t\t\t<*> 退出系统                      "<<endl;
			flag=0;
			break;
					
		}
		case 1:
		{	
			system("cls");
			cout<<"\n\n\n\t\t    ***************************************"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    *        欢迎使用停车管理系统         *"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    ***************************************"<<endl;
			cout<<"      \n\t\t\t请使用上下键来选择您想使用的功能："<<endl;
			cout<<"     \n\t\t\t<*> 预览停车场                    "<<endl;
			cout<<"       \t\t\t<*> 运行系统                 <-   "<<endl;
			cout<<"       \t\t\t<*> 查看您的车的停车情况          "<<endl;
			cout<<"       \t\t\t<*> 查看当前的停车历史记录        "<<endl;												
			cout<<"       \t\t\t<*> 退出系统                      "<<endl;
			flag=1;
			break;
					
		}
		case 2:
		{
			system("cls");
			cout<<"\n\n\n\t\t    ***************************************"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    *        欢迎使用停车管理系统         *"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    ***************************************"<<endl;
			cout<<"     \n\t\t\t请使用上下键来选择您想使用的功能："<<endl;
			cout<<"     \n\t\t\t<*> 预览停车场                    "<<endl;
			cout<<"       \t\t\t<*> 运行系统                      "<<endl;
			cout<<"       \t\t\t<*> 查看您的车的停车情况     <-   "<<endl;
			cout<<"       \t\t\t<*> 查看当前的停车历史记录        "<<endl;												
			cout<<"       \t\t\t<*> 退出系统                      "<<endl;
			flag=2;
			break;
		}
		case 3:
		{
			system("cls");
			cout<<"\n\n\n\t\t    ***************************************"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    *        欢迎使用停车管理系统         *"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    ***************************************"<<endl;
			cout<<"     \n\t\t\t请使用上下键来选择您想使用的功能："<<endl;
			cout<<"     \n\t\t\t<*> 预览停车场                    "<<endl;
			cout<<"       \t\t\t<*> 运行系统                      "<<endl;
			cout<<"       \t\t\t<*> 查看您的车的停车情况          "<<endl;
			cout<<"       \t\t\t<*> 查看当前的停车历史记录   <-   "<<endl;												
			cout<<"       \t\t\t<*> 退出系统                      "<<endl;
			flag=3;
			break;
		}
		case 4:
		{
			system("cls");	
			cout<<"\n\n\n\t\t    ***************************************"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    *        欢迎使用停车管理系统         *"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    ***************************************"<<endl;
			cout<<"     \n\t\t\t请使用上下键来选择您想使用的功能："<<endl;
			cout<<"     \n\t\t\t<*> 预览停车场                    "<<endl;
			cout<<"       \t\t\t<*> 运行系统                      "<<endl;
			cout<<"       \t\t\t<*> 查看您的车的停车情况          "<<endl;
			cout<<"       \t\t\t<*> 查看当前的停车历史记录        "<<endl;												
			cout<<"       \t\t\t<*> 退出系统                 <-   "<<endl;
			flag=4;
			break;
		}
	}

		KEY=getch();
		if(KEY==13)
		{
			num=0;
		
			return flag;
		}
		KEY=getch();
		if(KEY==72)
		{
			if(num==0)
				continue;
			num--;
		}
		else if(KEY==80)
		{
			if(num==4)
				continue;
			num++;
		}	
	}
}

