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
	int date = 1; //1�� 1�Ϻ��� �̹Ƿ� 1���� ����
	int restOfDate = 0;

	for (int i = 1582; i < year; i++) {//1582����� �Է��� �������� �ݺ�
		if (i < 1584) {//1584����� ������ �����Ƿ� �� �Ʒ������� 365�� ���ϰ�
			date = date + 365;
		}
		else {//1584�� �̻���ʹ�
			if (isLeapYear(i) == 1) {	//�����϶��� date�� 366�� �����ش�.
				date = date + 366;
			}
			else {//����ƴϸ� �׳� date�� 365�� ���Ѵ�.
				date = date + 365;
			}
		}
		
	}
	restOfDate = (date % 7) + 4; //�̷��� ���� date ���� 0 = �Ͽ����̹Ƿ� 7�γ��� �������� 4�� �������� ������ ���� ���Ͽ� �´�
	if (restOfDate >= 7) {//�ٵ� 7�� �Ѿ������ -7�� ���־ �����ȿ� �ٽ� ���Բ� ���ش�.
		restOfDate = restOfDate - 7;
	}
	return restOfDate;
}
*/