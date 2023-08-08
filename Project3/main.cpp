#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() { // 202024029 국동균 
	stack<int> Num_S1; 
	stack<int> Num_S2;
	stack<int> Result_S;

	bool IsUp = false; // 두 정수의 합이 10 이상임을 나타내기 위함

	// string으로 입력받는 이유는 이후 인자에 쉽게 접근하기 위함
	// int로 입력받은 이후 크기를 체크하고 10 * n 을 나누며 정수를 빼내는 방식보다 이것이 효율적이라고 판단.
	cout << "첫번째 정수 입력 : ";
	string numst1; cin >> numst1; 

	cout << "두번째 정수 입력 : ";
	string numst2; cin >> numst2;

	// 입력받은 값을 차례대로 접근하며 Stack에 push ('1'의 아스키코드 값은 49 이므로 48을 빼준값을 push)
	for (int i = 0; i < numst1.size(); i++)
		Num_S1.push((int)numst1.at(i) - 48);

	for (int i = 0; i < numst2.size(); i++)
		Num_S2.push((int)numst2.at(i) - 48);

	while ((!Num_S1.empty() || !Num_S2.empty())) {
		int count = 0; // 더한 값을 저장하고 push하기 위한 변수

		if (IsUp) // 이전의 값이 10 이상 이었는지 체크
			count += 1;

		if (Num_S1.empty()) { // Num_S1의 Stack이 빈경우
			count += Num_S2.top();
			Num_S2.pop();
		}
		else if (Num_S2.empty()) { // Num_S2의 Stack이 빈경우
			count += Num_S1.top();
			Num_S1.pop();
		}
		else { // 두 Stack 모두 비어있지 않은 경우
			count += Num_S1.top() + Num_S2.top();
			Num_S1.pop();
			Num_S2.pop();
		}

		if (count >= 10) { // 더해진 값이 10 이상인경우
			count %= 10;
			IsUp = true;
		}
		else {
			IsUp = false;
		}

		Result_S.push(count);
	}

	// 위 반복에서 마지막 push가 일어난 후 IsUp을 체크하지 못하고 나오기 때문에 체크
	if (IsUp) 
		Result_S.push(1);

	cout << "두 정수의 합 : ";

	while (!Result_S.empty()) { // 하나씩 꺼내며 출력
		cout << Result_S.top();
		Result_S.pop();
	}

	return 0;
}
