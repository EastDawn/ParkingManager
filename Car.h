/****************************车的构造：类********************************************************/
class Car
{
	string name;                                             /*汽车车牌*/
	
	int in_time;												 /*停入时间                    即生成时间*/
	
	double Money(int now_time);                                         /*        缴费函数    **********/

public:
	int parking_site[2];											/*停车位置*/

	int parking_time;                                          /*停车时间*/

	double money;												/*缴费*/

	int site[2];											/*停车位置*/
	
	int flag;                                               /*是否位置上已经有车 */

	void Parking_time(int now_time);               /*停车时间函数*/
	

	Car()
	{                                          /*无参构造函数*/
		name="x";
		flag=3;
		money=0;
	}

	Car(string na);									/*有参构造函数*/

	~Car();												/*析构函数*/
	
	void show_name();										/*显示该车的车牌*/

	void show_site();									/*显示该车的位置*/

	void show();											/*显示该车所有信息*/

	void Getsite(int x,int y);                             /*获得停车或过道位置*/

	void Get_intime();

	void Getname(string s);

	void Car::GetParking_site(int x,int y);

	string Outname();
	
};


double Car::Money(int now_time)
{								/*缴费函数            */
	return money=0.2*(Time_change((now_time-in_time)));							
}

void Car::Parking_time(int now_time)
{                   /*停车时间函数*/

	parking_time=Time_difference(in_time,now_time);
	
}										

Car::Car(string na)
{                                /*    构造函数   */                     
	name=na;
	in_time=Gettime();
	flag=3;
}

Car::~Car(){}													/*析构函数*/

void Car::show_name()
{												/*显示车的车牌*/
	cout<<"\tName: "<<name;
}

void Car::show_site()
{														/**显示车的坐标*/
	cout<<"Site: "<<"["<<site[0]<<","<<site[1]<<"]";
}

void Car::Getsite(int x,int y)
{                                        /*获得坐标位置函数*/
	site[0]=x;
	site[1]=y;
}

void Car::show()
{  /*输出车的名字函数*/
	Parking_time(Gettime());
	money=Money(Gettime());
	cout<<"\tName: "<<name<<"\tParking time: "<<parking_time/10000<<":"<<(parking_time/100)%100<<":"<<parking_time%100<<"\tPer: 0.2$/s"<<"\tPaid: "<<money<<"$"<<endl;      /*                        **********/
}

void Car::Get_intime()
{												/*获取时间*/
	in_time=Gettime();
}

void Car::Getname(string s)
{										/*获取编号*/
	name=s;
}

void Car::GetParking_site(int x,int y)
{							/*获取停车位置*/
	parking_site[0]=x;
	parking_site[1]=y;
}

string Car::Outname()
{												/*输出编号*/
	return name;
}