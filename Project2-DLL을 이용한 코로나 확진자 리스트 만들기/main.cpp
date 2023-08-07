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

    if (head == nullptr) { // ����Ʈ�� ��Ұ� ���� ���
        head = node;
        tail = node;
    }
    else { // ����Ʈ�� �ϳ� �̻��� ��Ҹ� ������ ���� ���
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

        if (isFind == false) { // ����Ʈ�� ���� �ڿ� ��Ұ� ���� �� ���
            tail->next = node;
            tail = tail->next;
        }
        else {
            if (index == 1) { // ����Ʈ�� ù��° ��ҿ� ���� �Ҷ�
                DLLNode<T>* ptr = new DLLNode<T>();
                ptr->next = head;
                ptr->info = el;
                head = ptr;
            }
            else { // ����Ʈ�� ����� ��Ұ� ���� �� ���
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

    if (isFind == false) { // ã�� ������ ���
        cout << name << " �̶�� �̸��� ���� ����� ����Ʈ �ȿ� �����ϴ�. " << endl;
    }
    else if (index != 1 || index != size) { // ������ ��Ұ� �߰��� ����� ���
        tmp->next = ptr->next;
        delete ptr;
    }
    else { 
        if (index == 1) { // ������ ��Ұ� ù��° ����� ���
            DLLNode<T>* ptr = head;
            head = ptr->next;
            delete ptr;
        }
        else { // ������ ��Ұ� ������ ����� ���
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
    // ������
    cout << " - HW2-DLL�� �̿��� �ڷγ� Ȯ���� ����Ʈ ����� - " << endl << " 202024029 ������" << endl << endl;
    cout << " �� ���α׷��� ���Ǿ��� �����ʹ� \'�ڷγ� ���̺� | �ǽð� Ȯ���� ��Ȳ\'" << endl;
    cout << " ����Ʈ���� ����Ǿ��� �����͸� ����Ͽ����� [2021.04.03 17�� 10��]�� �������� �մϴ�." << endl << endl;

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
        cout << "[1] ���� �߰��ϱ�" << endl;
        cout << "[2] ���� �����ϱ�" << endl;
        cout << "[3] ����Ʈ ����" << endl;
        cout << "[4] ����" << endl;
        cout << "-------------------------------------" << endl;
        cout << ": "; cin >> Choice;

        switch (Choice)
        {
            case 1: {
                cout << "���� ���� �Է��ϼ��� : ";
                string name; cin >> name;
                cout << "������ ���� �Է��ϼ��� : ";
                int num1; cin >> num1;
                cout << "����� ���� �Է��ϼ��� : ";
                int num2; cin >> num2;
                DLLdata.AddtoDLLSorted(corona_nation(name, num1, num2));
                cout << endl << "�߰��� �Ϸ� �Ǿ����ϴ�." << endl;

                break;
            }
            case 2: {
                cout << "���� ���� �Է��ϼ��� : ";
                string name; cin >> name;
                DLLdata.deleteDLLSorted(name);
                cout << endl << "������ �Ϸ� �Ǿ����ϴ�." << endl;

                break;
            }
            case 3: DLLdata.printDLLSorted(); break;
            case 4: IsOn = false; break;
            default: cout << "�ٽ� �Է����ּ���." << endl;
        }
    }
    cout << "���α׷��� �����մϴ�." << endl;
}