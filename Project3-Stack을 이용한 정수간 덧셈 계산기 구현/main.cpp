#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() { // 202024029 ������ 
	stack<int> Num_S1; 
	stack<int> Num_S2;
	stack<int> Result_S;

	bool IsUp = false; // �� ������ ���� 10 �̻����� ��Ÿ���� ����

	// string���� �Է¹޴� ������ ���� ���ڿ� ���� �����ϱ� ����
	// int�� �Է¹��� ���� ũ�⸦ üũ�ϰ� 10 * n �� ������ ������ ������ ��ĺ��� �̰��� ȿ�����̶�� �Ǵ�.
	cout << "ù��° ���� �Է� : ";
	string numst1; cin >> numst1; 

	cout << "�ι�° ���� �Է� : ";
	string numst2; cin >> numst2;

	// �Է¹��� ���� ���ʴ�� �����ϸ� Stack�� push ('1'�� �ƽ�Ű�ڵ� ���� 49 �̹Ƿ� 48�� ���ذ��� push)
	for (int i = 0; i < numst1.size(); i++)
		Num_S1.push((int)numst1.at(i) - 48);

	for (int i = 0; i < numst2.size(); i++)
		Num_S2.push((int)numst2.at(i) - 48);

	while ((!Num_S1.empty() || !Num_S2.empty())) {
		int count = 0; // ���� ���� �����ϰ� push�ϱ� ���� ����

		if (IsUp) // ������ ���� 10 �̻� �̾����� üũ
			count += 1;

		if (Num_S1.empty()) { // Num_S1�� Stack�� ����
			count += Num_S2.top();
			Num_S2.pop();
		}
		else if (Num_S2.empty()) { // Num_S2�� Stack�� ����
			count += Num_S1.top();
			Num_S1.pop();
		}
		else { // �� Stack ��� ������� ���� ���
			count += Num_S1.top() + Num_S2.top();
			Num_S1.pop();
			Num_S2.pop();
		}

		if (count >= 10) { // ������ ���� 10 �̻��ΰ��
			count %= 10;
			IsUp = true;
		}
		else {
			IsUp = false;
		}

		Result_S.push(count);
	}

	// �� �ݺ����� ������ push�� �Ͼ �� IsUp�� üũ���� ���ϰ� ������ ������ üũ
	if (IsUp) 
		Result_S.push(1);

	cout << "�� ������ �� : ";

	while (!Result_S.empty()) { // �ϳ��� ������ ���
		cout << Result_S.top();
		Result_S.pop();
	}

	return 0;
}