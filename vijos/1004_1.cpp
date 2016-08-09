// vijos 1004_1
#include <stdio.h>

class Date{
	int year, month, day;
public:
	Date(int y=1900, int m=1, int d=1){
		year=y; month=m; day=d;
	}
	Date addMonth() const;
	Date addDay() const;
	bool operator<=(Date a) const;
	bool operator!=(Date a) const;
	Date& operator--();
	class BadDate{};
	friend class DateArray;
};

class DateArray{
	bool arr[110][13][32];
public:
	DateArray(){ arr[0][0][0]=1; }
	bool &operator[](Date loc);
};

const int dayNum[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline bool leapYear(int year){
	return (year % 4 ==0 && year % 100 !=0) || year % 400 ==0;
}

inline int dayInMonth(int year, int month){
	return dayNum[month] + (month==2 && leapYear(year));
}

Date Date::addMonth() const{
	Date temp=*this;
	temp.month++;
	if (temp.month>12){
		temp.year++;
		temp.month=1;
	}
	if (temp.day > dayInMonth(temp.year, temp.month)) throw BadDate();
	return temp;
}

Date Date::addDay() const{
	Date temp=*this;
	temp.day++;
	if (temp.day > dayInMonth(temp.year, temp.month)){
		temp.month++;
		temp.day=1;
		if (temp.month>12){
			temp.year++;
			temp.month=1;
		}
	}
	return temp;
}

bool Date::operator<=(Date a) const{
	return (this->year<a.year || (this->year==a.year && (this->month<a.month || (this->month==a.month && this->day<=a.day))));
}

bool Date::operator!=(Date a) const{
	return (this->year != a.year || this->month != a.month || this->day != a.day);
}

Date &Date::operator--(){
	this->day--;
	if (!this->day){
		this->month--;
		if (!this->month){
			this->year--;
			this->month=12;
		}
		this->day = dayInMonth(this->year, this->month);
	}
	return *this;
}

const Date start(1900, 1, 1), end(2006, 11, 4);

bool &DateArray::operator[](Date loc){
	if (loc<=end) return this->arr[loc.year-1900][loc.month][loc.day];
	else return this->arr[0][0][0];
}

int main(){
	DateArray ans;
	ans[end]=0;
	Date i=end; --i;
	while (start!=i){
		try{
			ans[i] = !ans[i.addMonth()] || !ans[i.addDay()];
		}
		catch (Date::BadDate){
			ans[i] = !ans[i.addDay()];
		}
		--i;
	}
	int n;
	scanf("%d", &n);
	int Y, M, D;
	for (int i=0; i<n; i++){
		scanf("%d %d %d", &Y, &M, &D);
		printf((ans[Date(Y, M, D)])? "YES\n":"NO\n");
	}
	return 0;
}