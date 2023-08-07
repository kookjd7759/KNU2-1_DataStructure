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
		cout << i << "�� �� " << context << endl;
		Sleep(1000);
	}
}

void Again(bool *AnsCheck, int *Ans, int number) // �ٸ� ���� �Է����� �� �ݺ�����
{
	while (true) { // �ٸ� ���� �Է����� ��
		if (!*AnsCheck)
			cout << "�߸��� ���Դϴ�. �ٽ� �Է����ּ���. \n";

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

typedef struct c_info // ������, �����ڼ�, ����ڼ�, �����
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
	void print_info(int option, int IsUp); // optin: 1. �̸���, 2. �����ڼ�, 3. ����ڼ�, 4. �������
	void EnterBaseData(); // 8�� ������ �����ͷ� �ʱ�ȭ

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
	cout << "���� :";
	cin >> data.m_name;
	cout << "�����ڼ� :";
	cin >> data.m_num_of_infection;
	cout << "����ڼ� :";
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
	case 1: sort(m_data.begin(), m_data.end(), cmp_name); break; // �̸���
	case 2: sort(m_data.begin(), m_data.end(), cmp_infection); break; // �����ڼ�
	case 3: sort(m_data.begin(), m_data.end(), cmp_death); break; // ����ڼ�
	case 4: sort(m_data.begin(), m_data.end(), cmp_death_rate); break; // �������
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
	
	
	// ������
	cout << " - HW1-Vector�� Ȱ���� ������ �ڷγ� �������� DB����� - " << endl << " 202024029 ������" << endl << endl;
	cout << " �� ���α׷��� ���Ǿ��� �����ʹ� \'�ڷγ� ���̺� | �ǽð� Ȯ���� ��Ȳ\'" << endl;
	cout << "����Ʈ���� ����Ǿ��� �����͸� ����Ͽ����� [2021.04.03 17�� 10��]�� �������� �մϴ�." << endl << endl;
	cout << "[1] ��ó Ȯ���� ���α׷� ���� \n[2] �ٷ� ����" << endl;

	Again(&AnsCheck, &Ans_1, 2);
	if (Ans_1 == 1)
		system("start https://corona-live.com/");
	
	string DelName;
	int Ans_2 = NULL, Ans_3 = NULL, Choice;
	Ans_1 = 0; AnsCheck = true;

	system("cls");
	
	while(true) { // ���� ���� ����

		if (Ans_1 == 0) { // ����
			cout << "[1] �������� Ȯ���ϱ� \n[2] ������ �����ϱ� \n[3] ������ �߰��ϱ� \n[4] ����" << endl;

			Again(&AnsCheck, &Ans_1, 4);

			if (Ans_1 == 4) {
				cout << "���α׷��� ����." << endl;
				SLEEP(3, "���α׷��� �����մϴ�.");
				return 0;
			}
		}

		if (Ans_1 == 1) { // 1�� ������ . �������� Ȯ���ϱ�
			system("cls");
			cout << "[1] �̸��� \n[2] �����ڼ� \n[3] ����ڼ� \n[4] �������" << endl;

			Again(&AnsCheck, &Ans_2, 4);
			Choice = Ans_2;

			cout << "[1] �������� \n[2] ��������" << endl;
			Again(&AnsCheck, &Ans_3, 4);
			if (Ans_3 == 1)
				global_IsUp = true;
			else
				global_IsUp = false;

			system("cls");
			corona_nation.print_info(Choice, global_IsUp);

			cout << "[1] �������� \n[2] �ٽü���" << endl;

			Again(&AnsCheck, &Ans_3, 2);

			if (Ans_3 == 1) {
				Ans_1 = 0; Ans_2 = NULL; Ans_3 = NULL;
			}
			else {
				Ans_2 = NULL; Ans_3 = NULL;
			}

			system("cls");
		}
		
		if (Ans_1 == 2) { // 2�� ������ . ������ �����ϱ�
			system("cls");
			cout << "������ �������� ���� �̸��� �Է��ϼ���." << endl;

			bool check;
			
			while (true) { // ���� ������ �̸��� �Է�������
				if (!AnsCheck)
					cout << "��ġ�ϴ� ������ �̸��� �����ϴ�. �ٽ� �Է��ϼ���. \n";

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

			cout << "������ �Ϸ� �Ǿ����ϴ�." << endl;
			SLEEP(3, "���� ȭ������ ���ư��ϴ�.");

			system("cls");
			Ans_1 = 0; Ans_2 = NULL, Ans_3 = NULL;
		}

		if (Ans_1 == 3) { // 3�� ������ . ������ �߰��ϱ�
			system("cls");
			corona_nation.insert_data();

			cout << "�Է��� �Ϸ� �Ǿ����ϴ�." << endl;
			SLEEP(3, "���� ȭ������ ���ư��ϴ�.");

			system("cls");
			Ans_1 = 0; Ans_2 = NULL, Ans_3 = NULL;
		}
	}
}