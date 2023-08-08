#include <iostream>

using namespace std;

class corona_nation
{
public:
    corona_nation(string name = "empty", int num_of_confirmed_p = 0, int num_of_death_p = 0);
    void print_info();

    string m_name;
    int m_num_of_confirmed_p;
    int m_num_of_death_p;
    double m_death_rate;
};

template<class T>
class DLLNode
{
public:
    DLLNode() { next = prev = NULL; }

    DLLNode(const T& el, DLLNode* n = NULL, DLLNode* p = NULL) {
        info = el;
        next = n;
        prev = p;
    }

    T info;
    DLLNode* next, * prev;
};

template<class T>
class DLL
{
public:
    DLL()
    {
        head = NULL;
        tail = NULL;
    }

    void AddtoDLLSorted(const T& el);
    void deleteDLLSorted(const string& name);
    void printDLLSorted();

private:
    DLLNode<T>* head;
    DLLNode<T>* tail;
    int size = 0;
};

template<class T>
void DLL<T>::AddtoDLLSorted(const T& el)
{
    DLLNode<T>* node = new DLLNode<T>;

    size++;

    node->info = el;
    node->next = nullptr;

    if (head == nullptr) { // 리스트의 요소가 없을 경우
        head = node;
        tail = node;
    }
    else { // 리스트가 하나 이상의 요소를 가지고 있을 경우
        DLLNode<T>* ptr = head;
        int index = 0;
        bool isFind = false;

        while (ptr != nullptr) {
            index++;

            if (ptr->info.m_name >= el.m_name) {
                isFind = true; 
                break;
            }
            ptr = ptr->next;
        }

        if (isFind == false) { // 리스트의 가장 뒤에 요소가 들어가야 할 경우
            tail->next = node;
            tail = tail->next;
        }
        else {
            if (index == 1) { // 리스트의 첫번째 요소에 들어가야 할때
                DLLNode<T>* ptr = new DLLNode<T>();
                ptr->next = head;
                ptr->info = el;
                head = ptr;
            }
            else { // 리스트의 가운데에 요소가 들어가야 할 경우
                DLLNode<T>* ptr = head;
                DLLNode<T>* tmp = ptr;
                DLLNode<T>* node = new DLLNode<T>;

                node->info = el;
                node->next = nullptr;

                for (int i = 0; i < index - 1; i++) {
                    tmp = ptr;
                    ptr = ptr->next;
                }

                tmp->next = node;
                node->next = ptr;
            }
        }
    }
}

template<class T>
void DLL<T>::deleteDLLSorted(const string& name)
{
    DLLNode<T>* ptr = head;
    DLLNode<T>* tmp = ptr;

    size--;

    int index = 0;
    bool isFind = false;

    while (ptr != nullptr) {
        index++;

        if (ptr->info.m_name == name) {
            isFind = true;
            break;
        }
        else {
            tmp = ptr;
            ptr = ptr->next;
        }
    }

    if (isFind == false) { // 찾지 못했을 경우
        cout << name << " 이라는 이름을 가진 나라는 리스트 안에 없습니다. " << endl;
    }
    else if (index != 1 || index != size) { // 삭제할 요소가 중간의 요소인 경우
        tmp->next = ptr->next;
        delete ptr;
    }
    else { 
        if (index == 1) { // 삭제할 요소가 첫번째 요소인 경우
            DLLNode<T>* ptr = head;
            head = ptr->next;
            delete ptr;
        }
        else { // 삭제할 요소가 마지막 요소인 경우
            DLLNode<T>* ptr = head;
            DLLNode<T>* tmp = new DLLNode<T>;

            while (ptr->next != nullptr) {
                tmp = ptr;
                ptr = ptr->next;
            }

            tail = tmp;
            tail->next = nullptr;
            delete ptr;
        }
    }
}

template<class T>
void DLL<T>::printDLLSorted()
{
    DLLNode<T>* ptr = head;

    bool isFind = false;

    while (ptr != nullptr) {
        ptr->info.print_info();
        ptr = ptr->next;
    }

    cout << endl;
}

corona_nation::corona_nation(string name, int num_of_confirmed_p, int num_of_death_p)
{
    m_name = name;
    m_num_of_confirmed_p = num_of_confirmed_p;
    m_num_of_death_p = num_of_death_p;
    m_death_rate = ((double)m_num_of_death_p / m_num_of_confirmed_p) * 100;
}

void corona_nation::print_info()
{
    cout.width(10);
    cout << m_name;
    cout.width(10);
    cout << m_num_of_confirmed_p;
    cout.width(10);
    cout << m_num_of_death_p;
    cout.width(10);
    cout << m_death_rate << endl;
}

int main()
{
    // 오프닝
    cout << " - HW2-DLL을 이용한 코로나 확진자 리스트 만들기 - " << endl << " 202024029 국동균" << endl << endl;
    cout << " 본 프로그램에 사용되어진 데이터는 \'코로나 라이브 | 실시간 확진자 현황\'" << endl;
    cout << " 사이트에서 집계되어진 데이터를 사용하였으며 [2021.04.03 17시 10분]을 기준으로 합니다." << endl << endl;

    DLL<corona_nation> DLLdata;
    bool IsOn = true;

    DLLdata.AddtoDLLSorted(corona_nation("US", 31314625, 567610));
    DLLdata.AddtoDLLSorted(corona_nation("BR", 12912379, 328366));
    DLLdata.AddtoDLLSorted(corona_nation("IN", 12392260, 164141));
    DLLdata.AddtoDLLSorted(corona_nation("FR", 4741759, 96280));
    DLLdata.AddtoDLLSorted(corona_nation("RU", 4563056, 4186251));
    DLLdata.AddtoDLLSorted(corona_nation("GB", 4353668, 126816));
    DLLdata.AddtoDLLSorted(corona_nation("IT", 3629000, 110328));
    DLLdata.AddtoDLLSorted(corona_nation("TR", 3400296, 31892));

    while (IsOn) {
        static int Choice;

        cout << "-------------------------------------" << endl;
        cout << "[1] 나라 추가하기" << endl;
        cout << "[2] 나라 삭제하기" << endl;
        cout << "[3] 리스트 보기" << endl;
        cout << "[4] 종료" << endl;
        cout << "-------------------------------------" << endl;
        cout << ": "; cin >> Choice;

        switch (Choice)
        {
            case 1: {
                cout << "나라 명을 입력하세요 : ";
                string name; cin >> name;
                cout << "감염자 수를 입력하세요 : ";
                int num1; cin >> num1;
                cout << "사망자 수를 입력하세요 : ";
                int num2; cin >> num2;
                DLLdata.AddtoDLLSorted(corona_nation(name, num1, num2));
                cout << endl << "추가가 완료 되었습니다." << endl;

                break;
            }
            case 2: {
                cout << "나라 명을 입력하세요 : ";
                string name; cin >> name;
                DLLdata.deleteDLLSorted(name);
                cout << endl << "삭제가 완료 되었습니다." << endl;

                break;
            }
            case 3: DLLdata.printDLLSorted(); break;
            case 4: IsOn = false; break;
            default: cout << "다시 입력해주세요." << endl;
        }
    }
    cout << "프로그램을 종료합니다." << endl;
}
