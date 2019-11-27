/*#include <iostream>
using namespace std;
int isLeapYear(int year);
int findDate(int year);

int main() {
	int t = 0;
	int year = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> year;
		cout << findDate(year)<<endl;

	}

}
int isLeapYear(int year)
{
	int leapyear = year;
	if ((leapyear % 400 == 0 || leapyear % 100 != 0) && leapyear % 4 == 0) {

		leapyear = 1;
	}
	else {

		leapyear = 0;
	}

	return leapyear;
}

int findDate(int year) {
	int date = 1; //1월 1일부터 이므로 1부터 시작
	int restOfDate = 0;

	for (int i = 1582; i < year; i++) {//1582년부터 입력한 연도까지 반복
		if (i < 1584) {//1584년부터 윤년이 있으므로 그 아랫연도는 365만 더하고
			date = date + 365;
		}
		else {//1584년 이상부터는
			if (isLeapYear(i) == 1) {	//윤년일때만 date에 366을 더해준다.
				date = date + 366;
			}
			else {//윤년아니면 그냥 date에 365만 더한다.
				date = date + 365;
			}
		}
		
	}
	restOfDate = (date % 7) + 4; //이렇게 나온 date 들은 0 = 일요일이므로 7로나눈 나머지에 4가 더해져야 문제에 나온 요일에 맞다
	if (restOfDate >= 7) {//근데 7이 넘어가버리면 -7을 해주어서 범위안에 다시 들어가게끔 해준다.
		restOfDate = restOfDate - 7;
	}
	return restOfDate;
}
*/