#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <windows.h>

using namespace std;

bool global_IsUp = true;

void SLEEP(int time, string context)
{
	for (int i = time; i >= 1; i--) {
		cout << i << "초 후 " << context << endl;
		Sleep(1000);
	}
}

void Again(bool *AnsCheck, int *Ans, int number) // 다른 값을 입력했을 때 반복해줌
{
	while (true) { // 다른 값을 입력했을 때
		if (!*AnsCheck)
			cout << "잘못된 값입니다. 다시 입력해주세요. \n";

		cout << ":"; cin >> *Ans;

		if (*Ans >= 1 && *Ans <= number) {
			*AnsCheck = true;
			break;
		}
		else {
			*AnsCheck = false;
		}
	}
}

typedef struct c_info // 국가명, 감염자수, 사망자수, 사망률
{
	string m_name;
	int m_num_of_infection;
	int m_num_of_death;
	double m_death_rate;
}C_INFO;

class Corona_nation
{
public:
	void insert_data();
	bool delete_data(string name);
	void print_info(int option, int IsUp); // optin: 1. 이름순, 2. 감염자순, 3. 사망자순, 4. 사망률순
	void EnterBaseData(); // 8개 국가의 데이터로 초기화

private:
	vector<C_INFO> m_data;
};

bool cmp_name(const C_INFO& a, const C_INFO& b)
{
	if (global_IsUp)
		return a.m_name < b.m_name;
	else
		return a.m_name > b.m_name;
}
bool cmp_infection(const C_INFO& a, const C_INFO& b)
{
	if (global_IsUp)
		return a.m_num_of_infection < b.m_num_of_infection;
	else
		return a.m_num_of_infection > b.m_num_of_infection;
}
bool cmp_death(const C_INFO& a, const C_INFO& b)
{
	if (global_IsUp)
		return a.m_num_of_death < b.m_num_of_death;
	else
		return a.m_num_of_death > b.m_num_of_death;
}
bool cmp_death_rate(const C_INFO& a, const C_INFO& b)
{
	if (global_IsUp)
		return a.m_death_rate < b.m_death_rate;
	else
		return a.m_death_rate > b.m_death_rate;
}

void Corona_nation::insert_data()
{
	C_INFO data;
	cout << "나라 :";
	cin >> data.m_name;
	cout << "감염자수 :";
	cin >> data.m_num_of_infection;
	cout << "사망자수 :";
	cin >> data.m_num_of_death;
	data.m_death_rate = (data.m_num_of_death / (double)data.m_num_of_infection) * 100.0f;

	Corona_nation::m_data.push_back(data);

	cout << endl;
}

bool Corona_nation::delete_data(string name)
{
	int Target = NULL;
	for (int i = 0; i < m_data.size(); i++) {
		if (m_data.at(i).m_name.compare(name) == 0)
		{
			m_data.erase(m_data.begin() + i);
			return true;
		}
	}

	return false;
}

void Corona_nation::print_info(int option, int IsUp)
{
	switch (option)
	{
	case 1: sort(m_data.begin(), m_data.end(), cmp_name); break; // 이름순
	case 2: sort(m_data.begin(), m_data.end(), cmp_infection); break; // 감염자순
	case 3: sort(m_data.begin(), m_data.end(), cmp_death); break; // 사망자순
	case 4: sort(m_data.begin(), m_data.end(), cmp_death_rate); break; // 사망률순
	default: break;
	}

	cout << endl << "| Nation | infection |   death   | death_rate |" << endl << endl;

	for (int i = 0; i < m_data.size(); i++) {
		cout << fixed;
		cout.precision(4);
		cout.setf(ios::showpoint);

		cout << "| " <<left << setw(7) << m_data.at(i).m_name << "| " << left << setw(10) << m_data.at(i).m_num_of_infection << "| " <<
			left << setw(10) << m_data.at(i).m_num_of_death << "| " << left << setw(10) << m_data.at(i).m_death_rate << "%" << "|" << endl;
	}

	cout << endl;
}

void Corona_nation::EnterBaseData()
{
	C_INFO data;

	for (int i = 0; i < 8; i++) {
		switch (i){
		case 0: data.m_name = "US"; data.m_num_of_infection = 31314625; data.m_num_of_death = 567610; break;
		case 1: data.m_name = "BR"; data.m_num_of_infection = 12912379; data.m_num_of_death = 328366; break;
		case 2:	data.m_name = "IN"; data.m_num_of_infection = 12392260; data.m_num_of_death = 164141; break;
		case 3:	data.m_name = "FR"; data.m_num_of_infection = 4741759; data.m_num_of_death = 96280; break;
		case 4:	data.m_name = "RU"; data.m_num_of_infection = 4563056; data.m_num_of_death = 4186251; break;
		case 5:	data.m_name = "GB"; data.m_num_of_infection = 4353668; data.m_num_of_death = 126816; break;
		case 6:	data.m_name = "IT"; data.m_num_of_infection = 3629000; data.m_num_of_death = 110328; break;
		case 7:	data.m_name = "TR"; data.m_num_of_infection = 3400296; data.m_num_of_death = 31892; break;
		default: break;
		}

		data.m_death_rate = (data.m_num_of_death / (double)data.m_num_of_infection) * 100.0f;

		Corona_nation::m_data.push_back(data);
	}
}

int main(void)
{
	Corona_nation corona_nation;
	corona_nation.EnterBaseData();
	
	int Ans_1 = NULL;
	bool AnsCheck = true;
	
	
	// 오프닝
	cout << " - HW1-Vector를 활용한 국가별 코로나 감염정도 DB만들기 - " << endl << " 202024029 국동균" << endl << endl;
	cout << " 본 프로그램에 사용되어진 데이터는 \'코로나 라이브 | 실시간 확진자 현황\'" << endl;
	cout << "사이트에서 집계되어진 데이터를 사용하였으며 [2021.04.03 17시 10분]을 기준으로 합니다." << endl << endl;
	cout << "[1] 출처 확인후 프로그램 실행 \n[2] 바로 실행" << endl;

	Again(&AnsCheck, &Ans_1, 2);
	if (Ans_1 == 1)
		system("start https://corona-live.com/");
	
	string DelName;
	int Ans_2 = NULL, Ans_3 = NULL, Choice;
	Ans_1 = 0; AnsCheck = true;

	system("cls");
	
	while(true) { // 메인 루프 시작

		if (Ans_1 == 0) { // 메인
			cout << "[1] 감염정도 확인하기 \n[2] 데이터 삭제하기 \n[3] 데이터 추가하기 \n[4] 종료" << endl;

			Again(&AnsCheck, &Ans_1, 4);

			if (Ans_1 == 4) {
				cout << "프로그램을 종료." << endl;
				SLEEP(3, "프로그램을 종료합니다.");
				return 0;
			}
		}

		if (Ans_1 == 1) { // 1번 선택지 . 감염정도 확인하기
			system("cls");
			cout << "[1] 이름순 \n[2] 감염자순 \n[3] 사망자순 \n[4] 사망률순" << endl;

			Again(&AnsCheck, &Ans_2, 4);
			Choice = Ans_2;

			cout << "[1] 오름차순 \n[2] 내림차순" << endl;
			Again(&AnsCheck, &Ans_3, 4);
			if (Ans_3 == 1)
				global_IsUp = true;
			else
				global_IsUp = false;

			system("cls");
			corona_nation.print_info(Choice, global_IsUp);

			cout << "[1] 메인으로 \n[2] 다시선택" << endl;

			Again(&AnsCheck, &Ans_3, 2);

			if (Ans_3 == 1) {
				Ans_1 = 0; Ans_2 = NULL; Ans_3 = NULL;
			}
			else {
				Ans_2 = NULL; Ans_3 = NULL;
			}

			system("cls");
		}
		
		if (Ans_1 == 2) { // 2번 선택지 . 데이터 삭제하기
			system("cls");
			cout << "삭제할 데이터의 나라 이름을 입력하세요." << endl;

			bool check;
			
			while (true) { // 없는 국가의 이름을 입력했을때
				if (!AnsCheck)
					cout << "일치하는 국가의 이름이 없습니다. 다시 입력하세요. \n";

				cout << ":"; cin >> DelName;
				check = corona_nation.delete_data(DelName);

				if (check) {
					AnsCheck = true;
					break;
				}
				else {
					AnsCheck = false;
				}
			}

			cout << "삭제가 완료 되었습니다." << endl;
			SLEEP(3, "메인 화면으로 돌아갑니다.");

			system("cls");
			Ans_1 = 0; Ans_2 = NULL, Ans_3 = NULL;
		}

		if (Ans_1 == 3) { // 3번 선택지 . 데이터 추가하기
			system("cls");
			corona_nation.insert_data();

			cout << "입력이 완료 되었습니다." << endl;
			SLEEP(3, "메인 화면으로 돌아갑니다.");

			system("cls");
			Ans_1 = 0; Ans_2 = NULL, Ans_3 = NULL;
		}
	}
}
