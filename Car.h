/****************************���Ĺ��죺��********************************************************/
class Car
{
	string name;                                             /*��������*/
	
	int in_time;												 /*ͣ��ʱ��                    ������ʱ��*/
	
	double Money(int now_time);                                         /*        �ɷѺ���    **********/

public:
	int parking_site[2];											/*ͣ��λ��*/

	int parking_time;                                          /*ͣ��ʱ��*/

	double money;												/*�ɷ�*/

	int site[2];											/*ͣ��λ��*/
	
	int flag;                                               /*�Ƿ�λ�����Ѿ��г� */

	void Parking_time(int now_time);               /*ͣ��ʱ�亯��*/
	

	Car()
	{                                          /*�޲ι��캯��*/
		name="x";
		flag=3;
		money=0;
	}

	Car(string na);									/*�вι��캯��*/

	~Car();												/*��������*/
	
	void show_name();										/*��ʾ�ó��ĳ���*/

	void show_site();									/*��ʾ�ó���λ��*/

	void show();											/*��ʾ�ó�������Ϣ*/

	void Getsite(int x,int y);                             /*���ͣ�������λ��*/

	void Get_intime();

	void Getname(string s);

	void Car::GetParking_site(int x,int y);

	string Outname();
	
};


double Car::Money(int now_time)
{								/*�ɷѺ���            */
	return money=0.2*(Time_change((now_time-in_time)));							
}

void Car::Parking_time(int now_time)
{                   /*ͣ��ʱ�亯��*/

	parking_time=Time_difference(in_time,now_time);
	
}										

Car::Car(string na)
{                                /*    ���캯��   */                     
	name=na;
	in_time=Gettime();
	flag=3;
}

Car::~Car(){}													/*��������*/

void Car::show_name()
{												/*��ʾ���ĳ���*/
	cout<<"\tName: "<<name;
}

void Car::show_site()
{														/**��ʾ��������*/
	cout<<"Site: "<<"["<<site[0]<<","<<site[1]<<"]";
}

void Car::Getsite(int x,int y)
{                                        /*�������λ�ú���*/
	site[0]=x;
	site[1]=y;
}

void Car::show()
{  /*����������ֺ���*/
	Parking_time(Gettime());
	money=Money(Gettime());
	cout<<"\tName: "<<name<<"\tParking time: "<<parking_time/10000<<":"<<(parking_time/100)%100<<":"<<parking_time%100<<"\tPer: 0.2$/s"<<"\tPaid: "<<money<<"$"<<endl;      /*                        **********/
}

void Car::Get_intime()
{												/*��ȡʱ��*/
	in_time=Gettime();
}

void Car::Getname(string s)
{										/*��ȡ���*/
	name=s;
}

void Car::GetParking_site(int x,int y)
{							/*��ȡͣ��λ��*/
	parking_site[0]=x;
	parking_site[1]=y;
}

string Car::Outname()
{												/*������*/
	return name;
}