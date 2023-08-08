#include <iostream>
#include <time.h>
#include <stack>

using namespace std;

char Area[12][12]; // 10 X 10 의 형태 ( 테두리를 만들기 위해서 12 X 12 로 할당 )
// 모든함수에서 쉽게 접근이 가능하도록 전역변수로 지정

void AreaFrame() {
	for (int i = 0; i < 12; i++) {
		Area[0][i] = 'b';
		Area[11][i] = 'b';

		if (i == 0) {
			for (int j = 0; j < 12; j++) {
				Area[j][0] = 'b';
			}
		} 

		if (i == 11) {
			for (int j = 0; j < 12; j++) {
				Area[j][11] = 'b';
			}
		}
	}
}

void AreaRandomReset() {
	int random;

	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++) {
			random = rand() % 2;

			if (random == 0) {
				Area[i][j] = 'b';
			}
			else {
				Area[i][j] = 'w';
			}
		}
	}
}

void AreaPrintSell() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			cout << Area[i][j] << " ";
		}

		cout << endl;
	}
}

int CheckAdjacentCell(int i, int j) {
	Area[i][j] = 'b';

	int w, a, s, d;

	if (Area[i + 1][j] == 'w')
		s = CheckAdjacentCell(i + 1, j);
	else
		s = 0;

	if (Area[i - 1][j] == 'w')
		w = CheckAdjacentCell(i - 1, j);
	else
		w = 0;

	if (Area[i][j + 1] == 'w')
		d = CheckAdjacentCell(i, j + 1);
	else
		d = 0;

	if (Area[i][j - 1] == 'w')
		a = CheckAdjacentCell(i, j - 1);
	else
		a = 0;

	if ((w + a + s + d) == 0)
		return 1;
	else
		return (w + a + s + d) + 1;
}

void CheckAndPrint() {
	stack<int> s;
	stack<int> s_sub;

	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++) {
			if (Area[i][j] == 'w') {
				s.push(CheckAdjacentCell(i, j));
			}
		}
	}

	while (!s.empty()) {
		s_sub.push(s.top());
		s.pop();
	}

	cout << endl << s_sub.size() << " white areas of ";
	for (int i = 0, size = s_sub.size(); i < size; i++) {
		cout << s_sub.top(); 
		s_sub.pop();

		if (i != size - 1)
			cout << ", ";
		if (i == size - 2)
			cout << "and ";
	}

	cout << " cells." << endl << endl;
}

int main() {
	srand(time(NULL));

	int Choice;

	AreaFrame(); // 틀 제작 ( 테두리를 'b' 로 초기화 )

	while (true) {
		static int count = 0;
		if (count == 0) cout << "[1] Start [2] Quit";
		else cout << "[1] Again [2] Quit";
		cout << endl << " : ";

		Choice; cin >> Choice; 
		cout << endl;

		if (Choice == 1) {
			AreaRandomReset(); // 셀을 랜덤으로 값을 초기화
			AreaPrintSell(); // 현재 셀의 구성 보이기
			CheckAndPrint(); // 흰타일의 갯수와 각 사이즈를 계산하고 출력
		}
		else if (Choice == 2) {
			cout << "System End ..." << endl;
			return 0;
		}
		else 
			cout << "What ?" << endl;
		
		count++;
	}
}
