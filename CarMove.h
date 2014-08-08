#include"Ground.h"
#include"Car.h"

static int his_number=0;

void Cargroup_Create(Car x[])
{														/*车数组构造*/
	int i,j;
	char s[6];

	srand(time(NULL));;

	for(i=0;i<50;i++)
	{
		for(j=0;j<5;j++)
		{
			s[j]=rand()%10+48;
		}
		s[j]='\0';
		x[i].flag=-1;
		x[i].Getname(s);
		x[i].Getsite(12,rand()%2==0?1:10);
	}
}

void Car_change(Car &x)
{															/*车对象的重新构造*/
	int j;
	char s[6];
	for(j=0;j<5;j++)
	{
		srand(time(NULL));
		s[j]=rand()%10;
	}
	s[j]='\0';
	x.flag=-1;
	x.Getname(s);
	x.Getsite(12,rand()%2==0?1:10);
}

void Car_move(Car &x,int ground[][12])
{											/*控制车移动的函数*/
	int n,sure=0;
	while(sure==0)
	{
		srand(time(NULL));
		srand(time(NULL));
		n=rand()%4+1;
		if(n==1)
		{
			if(x.site[0]-1<=0)
				continue;
UP:
			if(ground[x.site[0]-1][x.site[1]]!=1&&ground[x.site[0]-1][x.site[1]]!=4&&ground[x.site[0]-1][x.site[1]]!=6)
			{
				x.site[0]--;
				sure++;
			}
			else
			{
				if(x.site[1]-1<10-x.site[1])
					goto RIGHT;
				goto LEFT;
			}
		}
		else if(n==2)
		{
			if(x.site[0]+1>=12)
				continue;
DOWN:	
			if(ground[x.site[0]+1][x.site[1]]!=1&&ground[x.site[0]+1][x.site[1]]!=4&&ground[x.site[0]+1][x.site[1]]!=5)
			{
				x.site[0]++;
				sure++;
			}
			else
			{
				if(x.site[1]-1<10-x.site[1])
					goto RIGHT;
				goto LEFT;
			}
		}
		else if(n==3)
		{
			if(x.site[1]-1<=0)
				continue;
LEFT:
			if(ground[x.site[0]][x.site[1]-1]!=1&&ground[x.site[0]][x.site[1]-1]!=4)
			{
				x.site[1]--;
				sure++;
			}
			else
			{
				if(x.site[0]-1<11-x.site[0])
					goto DOWN;
				goto UP;
			}
		}
		
		else if(n==4)
		{
			if(x.site[1]+1>=11)
				continue;
RIGHT:	
			if(ground[x.site[0]][x.site[1]+1]!=1&&ground[x.site[0]][x.site[1]+1]!=4)
			{
				x.site[1]++;
				sure++;
			}
			else
			{
				if(x.site[0]-1<11-x.site[0])
					goto DOWN;
				goto UP;
			}
		}
	}
}

void Car_goout(Car &x,int ground[][12],int &number,FILE *&fp)
{								/*让车离开停车场的函数*/
	system("cls");
	if(x.flag==3)
	{
		if(x.site[1]-1<=10-x.site[1])
		{
			while(x.site[1]!=1)
			{
				ground[x.site[0]][x.site[1]]=x.flag;
				show_ground(ground,7);
				cout<<"\n\tCurrently:";
				x.show_name();
				cout<<"\t";
				x.show_site();
				cout<<"\tTotal: "<<number;
				ground[x.site[0]][x.site[1]]=2;
				x.site[1]--;
				Sleep(500);;
				system("cls");
				
			}
		}
		else
		{
			while(x.site[1]!=10)
			{
				ground[x.site[0]][x.site[1]]=x.flag;
				show_ground(ground,7);
				cout<<"\n\tCurrently:";
				x.show_name();
				cout<<"\t";
				x.show_site();
				cout<<"\tTotal: "<<number;
				ground[x.site[0]][x.site[1]]=2;
				x.site[1]++;
				Sleep(500);;
				system("cls");
			}
		}
	}
	else
	{
		ground[x.site[0]][x.site[1]]=0;
		x.site[0]--;
		x.flag=3;
		if(x.site[1]-1<=10-x.site[1])
		{
			while(x.site[1]!=1)
			{
				ground[x.site[0]][x.site[1]]=x.flag;
				show_ground(ground,7);
				cout<<"\n\tCurrently:";
				x.show_name();
				cout<<"\t";
				x.show_site();
				cout<<"\tTotal: "<<number;
				ground[x.site[0]][x.site[1]]=2;
				x.site[1]--;
				Sleep(500);;
				system("cls");
			}
		}
		else
		{
			while(x.site[1]!=10)
			{
				ground[x.site[0]][x.site[1]]=x.flag;
				show_ground(ground,7);
				cout<<"\n\tCurrently:";
				x.show_name();
				cout<<"\t";
				x.show_site();
				cout<<"\tTotal: "<<number;
				ground[x.site[0]][x.site[1]]=2;
				x.site[1]++;
				Sleep(500);;
				system("cls");
			}
		}
	}
	while(x.site[0]!=0)
	{
		ground[x.site[0]][x.site[1]]=x.flag;
		show_ground(ground,7);
		cout<<"\n\tCurrently:";
		x.show_name();
		cout<<"\t";
		x.show_site();
		cout<<"\tTotal: "<<number;
		ground[x.site[0]][x.site[1]]=2;
		x.site[0]--;
		Sleep(500);
		system("cls");	
	}
	number--;
	show_ground(ground,7);
	cout<<endl;
	string nam=x.Outname();
	int ax=x.parking_site[0],bx=x.parking_site[1];
	x.show();
	fprintf(fp,"%s %d %d %d %d %d %lf\n",
		nam.c_str(),
		ax,
		bx,
		x.parking_time/10000,
		(x.parking_time/100)%100,
		x.parking_time%100,
		x.money);
	his_number++;
	Car_change(x);
	
	Sleep(3000);
}


 
void Find_car(Car a[])
{																	/*查找车的函数*/
	string s;
	cout<<"\n\t\t\t    请输入您的车的车牌号:\n\n\t\t\t\t";
	DisHideCursor();																			

	cin>>s;cout<<endl;
	HideCursor();
	for(int i=0;i<50;i++)
	{
		if(a[i].Outname()==s&&a[i].flag==1)
		{
			a[i].Parking_time(Gettime());
			cout<<"\t\tName:"<<a[i].Outname()<<"\tSite: ("<<a[i].site[0]<<","<<a[i].site[1]<<")\tTime: "<<a[i].parking_time/10000<<":"<<(a[i].parking_time/100)%100<<":"<<a[i].parking_time%100<<endl;
			Sleep(1000);
			system("pause");
			return ;
		}
	}
	cout<<"\t\t\t\t    查无此车"<<endl;
	Sleep(2000);
}


void History(FILE *&fp)
{														/*输出停车历史记录的函数*/
	int a,b,c,d,e;
	char s[6];
	if(his_number==0)
	{
		system("cls");
		cout<<"\n\t\t\t\t    No car!"<<endl;
		Sleep(2000);
	}
	else
	{
		if(fclose(fp))
		{
			printf("System is wrong,Restart please!");
			exit(0);
		}
		if((fp=fopen("123.txt","r"))==NULL)
		{
			cout<<"System is wrong,Restart please!"<<endl;
			exit(0);
		}
		double m;
		system("cls");
		cout<<endl;
		while(!feof(fp))
		{
			fscanf(fp,"%s%d%d%d%d%d%lf\n",s,&a,&b,&c,&d,&e,&m);
			printf("\tName: %s \t Site: (%d,%d) \t Time: %d : %d : %d \t Paid: %.2f\n",s,a,b,c,d,e,m);
		}
		Sleep(3000);
		system("pause");
		fclose(fp);
		if((fp=fopen("123.txt","a"))==NULL)
		{
			cout<<"System is wrong,Restart please!"<<endl;
			exit(0);
		}
	}
}

void RUN()
{																					/*停车场系统运行的函数*/
	FILE *fp;

	if((fp=fopen("123.txt","w"))==NULL)
	{
		cout<<"System is wrong,Restart please!"<<endl;
		exit(0);
	}

	int ground[13][12];
	int ground_number=0;
	Create_ground(ground);
	Car cargroup[50];
	Cargroup_Create(cargroup);
	int i=0; 

	int x;
	while(1)
	{
		switch(SystemMenu())
		{
			case 0:
			{
				system("cls");
				show_ground(ground,0);
				Sleep(3000);
				system("pause");
				break;
			}
			case 1:
			{
				while(1)
				{
					system("cls");
					cargroup[i%50].Get_intime();
					cargroup[i%50].site[0]--;
					cargroup[i%50].flag=3;

					if(ground_number==40)
					{																	/*在停车场停满车的时候只能提车*/
						cout<<"\t\t\t\tThe parking places is FULL!  !!!NO Parking NOW!!!"<<endl;
						Car_goout(cargroup[i%50],ground,ground_number,fp);
					}
					else
					{	
						while(cargroup[i%50].flag==3)
						{															/*将车停入车场*/
							if(ground[cargroup[i%50].site[0]][cargroup[i%50].site[1]]==0)
							{
								cargroup[i%50].flag=1;
								ground[cargroup[i%50].site[0]][cargroup[i%50].site[1]]=cargroup[i%50].flag;
								show_ground(ground,2);
								cout<<"\n\tCurtently:";
								cargroup[i].GetParking_site(cargroup[i%50].site[0],cargroup[i%50].site[1]);
								cargroup[i%50].show_name();
								cout<<"\t";
								cargroup[i%50].show_site();
								cargroup[i%50].parking_site[0]=cargroup[i].site[0];
								cargroup[i%50].parking_site[1]=cargroup[i].site[1];
								ground_number++;
								cout<<"\tTotal:"<<ground_number<<endl;
								Sleep(2000);
								break;
							}
							ground[cargroup[i%50].site[0]][cargroup[i%50].site[1]]=cargroup[i%50].flag;
							show_ground(ground,3);
							cout<<"\n\tCurtently:";
							cargroup[i%50].show_name();
							cout<<"\t";
							cargroup[i%50].show_site();
							cout<<"\tTotal:"<<ground_number<<endl;
							ground[cargroup[i%50].site[0]][cargroup[i%50].site[1]]=2;
							Car_move(cargroup[i%50],ground);
							Sleep(500);
							system("cls");
				
						}
					}
					if(ground_number!=0)
					{													/*在停车数目不为零的情况下模拟随机提车*/
						int random,random2;
						srand(time(NULL));
						random=rand()%100+1;
						if(random%5==0&&i>=5)
						{
							srand(time(NULL));
							random2=rand()%i;
							if(cargroup[random2].flag==1)
							Car_goout(cargroup[random2],ground,ground_number,fp);
						}
					}
				
				int index;
				srand(time(NULL));
				index=rand()%100;
				if(index%5==0)
					if(Menu("是否想退出系统?",ground))
					{
						break;
					}
					i++;
				}
				break;
			}

			case 2:Find_car(cargroup);break;
			case 3:History(fp);break;
			case 4:cout<<"\n\t\t\t欢迎您再次使用本系统！"<<endl;return;
			}
	}
	
}