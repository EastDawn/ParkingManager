

void setColor(unsigned short ForeColor=3,unsigned short BackGroundColor=0)   /*������ɫ����*/
       //������Ĭ��ֵ
{ 
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE); //
    SetConsoleTextAttribute(hCon,ForeColor|BackGroundColor); 
         
}



int Time_difference(int in_time,int now_time)
{									/*��ʱ���ĺ���*/
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
{									                                	/*��ȡϵͳʱ�亯��*/
	SYSTEMTIME sys;
	GetLocalTime(&sys); 
	return sys.wHour*10000+sys.wMinute*100+sys.wSecond;
}

void Create_ground(int ground[][12])
{												/*����ͣ����*/
	
	int i,j;
	
	for(i=0;i<13;i++)                           /*ǽ*/
		for(j=0;j<12;j++)
			ground[i][j]=4;
	
	for(i=1;i<12;i++)                          /*����*/            
		for(j=1;j<11;j++)
			ground[i][j]=2;
	
	for(i=2;i<11;i+=2)                         /*��λ*/
		for(j=2;j<10;j++)
			ground[i][j]=0;
	
	ground[0][1]=6;
	ground[0][10]=6;
	ground[12][1]=5;
	ground[12][10]=5;
	
}

void show_ground(int gro[][12],int flag)
{												/*��ʾͣ����*/
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
{														/*�˵�ѡ��Ч������*/
	int KEY=0,flag=1;

	cout<<"\n\t\t\t\t"<<s<<"\n\n\t\t\t\t  >>�� <-\n\t\t\t\t  >>�� ";
	while(1)
	{		
		if(KEY==72)
		{
			system("cls");
			show_ground(x,0);
			cout<<"\n\t\t\t\t"<<s<<"\n\n\t\t\t\t  >>�� <-\n\t\t\t\t  >>�� ";
			flag=1;
		}
		else if(KEY==80)
		{
			system("cls");
			show_ground(x,0);
			cout<<"\n\t\t\t\t"<<s<<"\n\n\t\t\t\t  >>�� \n\t\t\t\t  >>�� <-\n";
			flag=0;
		}
		if(KEY==13)
			return flag;
		KEY=getch();
	}
}

void HideCursor()																					/*���ع��*/
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void DisHideCursor()																				/*��ʾ���*/
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 1}; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}


int SystemMenu()
{																					/**ϵͳ�˵�*/

	int KEY=0,flag=1,num=0;
	while(1)
	{
		switch(num)
		{
			case 0:{	system("cls");
			cout<<"\n\n\n\t\t    ***************************************"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    *        ��ӭʹ��ͣ������ϵͳ         *"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    ***************************************"<<endl;
			cout<<"      \n\t\t\t��ʹ�����¼���ѡ������ʹ�õĹ��ܣ�"<<endl;
			cout<<"     \n\t\t\t<*> Ԥ��ͣ����               <-   "<<endl;
			cout<<"       \t\t\t<*> ����ϵͳ                      "<<endl;
			cout<<"       \t\t\t<*> �鿴���ĳ���ͣ�����          "<<endl;
			cout<<"       \t\t\t<*> �鿴��ǰ��ͣ����ʷ��¼        "<<endl;												
			cout<<"       \t\t\t<*> �˳�ϵͳ                      "<<endl;
			flag=0;
			break;
					
		}
		case 1:
		{	
			system("cls");
			cout<<"\n\n\n\t\t    ***************************************"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    *        ��ӭʹ��ͣ������ϵͳ         *"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    ***************************************"<<endl;
			cout<<"      \n\t\t\t��ʹ�����¼���ѡ������ʹ�õĹ��ܣ�"<<endl;
			cout<<"     \n\t\t\t<*> Ԥ��ͣ����                    "<<endl;
			cout<<"       \t\t\t<*> ����ϵͳ                 <-   "<<endl;
			cout<<"       \t\t\t<*> �鿴���ĳ���ͣ�����          "<<endl;
			cout<<"       \t\t\t<*> �鿴��ǰ��ͣ����ʷ��¼        "<<endl;												
			cout<<"       \t\t\t<*> �˳�ϵͳ                      "<<endl;
			flag=1;
			break;
					
		}
		case 2:
		{
			system("cls");
			cout<<"\n\n\n\t\t    ***************************************"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    *        ��ӭʹ��ͣ������ϵͳ         *"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    ***************************************"<<endl;
			cout<<"     \n\t\t\t��ʹ�����¼���ѡ������ʹ�õĹ��ܣ�"<<endl;
			cout<<"     \n\t\t\t<*> Ԥ��ͣ����                    "<<endl;
			cout<<"       \t\t\t<*> ����ϵͳ                      "<<endl;
			cout<<"       \t\t\t<*> �鿴���ĳ���ͣ�����     <-   "<<endl;
			cout<<"       \t\t\t<*> �鿴��ǰ��ͣ����ʷ��¼        "<<endl;												
			cout<<"       \t\t\t<*> �˳�ϵͳ                      "<<endl;
			flag=2;
			break;
		}
		case 3:
		{
			system("cls");
			cout<<"\n\n\n\t\t    ***************************************"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    *        ��ӭʹ��ͣ������ϵͳ         *"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    ***************************************"<<endl;
			cout<<"     \n\t\t\t��ʹ�����¼���ѡ������ʹ�õĹ��ܣ�"<<endl;
			cout<<"     \n\t\t\t<*> Ԥ��ͣ����                    "<<endl;
			cout<<"       \t\t\t<*> ����ϵͳ                      "<<endl;
			cout<<"       \t\t\t<*> �鿴���ĳ���ͣ�����          "<<endl;
			cout<<"       \t\t\t<*> �鿴��ǰ��ͣ����ʷ��¼   <-   "<<endl;												
			cout<<"       \t\t\t<*> �˳�ϵͳ                      "<<endl;
			flag=3;
			break;
		}
		case 4:
		{
			system("cls");	
			cout<<"\n\n\n\t\t    ***************************************"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    *        ��ӭʹ��ͣ������ϵͳ         *"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    *                                     *"<<endl;
			cout<<"      \t\t    ***************************************"<<endl;
			cout<<"     \n\t\t\t��ʹ�����¼���ѡ������ʹ�õĹ��ܣ�"<<endl;
			cout<<"     \n\t\t\t<*> Ԥ��ͣ����                    "<<endl;
			cout<<"       \t\t\t<*> ����ϵͳ                      "<<endl;
			cout<<"       \t\t\t<*> �鿴���ĳ���ͣ�����          "<<endl;
			cout<<"       \t\t\t<*> �鿴��ǰ��ͣ����ʷ��¼        "<<endl;												
			cout<<"       \t\t\t<*> �˳�ϵͳ                 <-   "<<endl;
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

