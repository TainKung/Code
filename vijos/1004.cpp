// vijos 1004
#include <stdio.h>

const int dayNum[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline bool leapYear(int year){
	return ((year % 4 ==0 && year % 100 !=0) || year % 400 ==0);
}

inline int dayInMonth(int year, int month){
	if (month!=2) return dayNum[month];
	else return dayNum[2]+(leapYear(year));
}

class Date{
	int year, month, day;
public:
	Date(int y=1900, int m=1, int d=1){
		year=y; month=m; day=d;
	}
	class BadDate{};
	Date addMonth();
	Date addDay();
	Date& operator--();
	bool operator!=(Date a) const;
	bool operator<=(Date a) const;
	friend bool &arr(Date a);
}; 

Date& Date::operator--(){
	this->day--;
	if (!this->day){
		this->month--;
		if (!this->month){
			this->month=12; this->year--;
		}
		this->day=dayInMonth(this->year, this->month);
	}
	return *this;
}

Date Date::addMonth(){
	Date temp=*this;
	temp.month++;
	if (temp.month>12){
		temp.month=1;
		temp.year++;
	}
	if (temp.day>dayInMonth(temp.year, temp.month)) throw BadDate();
	return temp;
}

Date Date::addDay(){
	Date temp=*this;
	temp.day++;
	if (temp.day>dayInMonth(temp.year, temp.month)){
		temp.month++;
		temp.day=1;
		if (temp.month>12){
			temp.month=1;
			temp.year++;
		}
	}
	return temp;
}

bool Date::operator!=(Date a) const{
	return !(this->year==a.year && this->month==a.month && this->day==a.day);
}

bool Date::operator<=(Date a) const{
	return (this->year*10000+this->month*100+this->day <= a.year*10000+a.month*100+a.day);
}

bool ans[130][13][32];
const Date start=Date(2006, 11, 3), end=Date();

bool &arr(Date a){return (a<=Date(2006, 11, 4))?ans[a.year-1900][a.month][a.day]:ans[0][0][0];}

int main(){
	arr(Date(2006, 11, 4))=0;
	ans[0][0][0]=1;
	for (Date i=start; i!=end; --i){
		try{
			arr(i) = !arr(i.addMonth()) || !arr(i.addDay());
		}
		catch (Date::BadDate){
			arr(i) = !arr(i.addDay());
		}
	}
	int n;
	int Y,M,D;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d %d %d", &Y, &M, &D);
		printf((arr(Date(Y, M, D)))? "YES\n":"NO\n");
		// printf("%d\n",arr(Date(Y, M, D)));
	}
	return 0;
}