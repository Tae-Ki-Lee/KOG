#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<cctype>

using namespace std;
//�Է� ������ �������� �ƴϸ� �ٽ� �Է¹޴� �Լ�
int write_int() {
	int result;
	while (!(cin >> result)) {
		cin.clear();
		while (cin.get() == '\n') break;
		cout << "�ùٸ� ��(����)�� �����ּ���.\n" << endl;
		break;
	}
	return result;
}
int main() {
	//���������� ���� Ŭ����
	class franchise_store{
	private:
		string name;
		string adress;
	public:
		franchise_store(){
			cout << "���� �̸��� �ۼ����ּ��� " << endl;
			cin >> name;
			cout << "���� �ּҸ� �ۼ����ּ��� " << endl;
			cin >> adress;
		}
		void setName(string name) {
			this->name = name;
		}
		void setAdress(string param) {
			this->adress = param;
		}
		string getName() {
			return name;
		}
		string getAdress() {
			return adress;
		}
	};

	//���� vector�� �޴� map ����
	vector<franchise_store>stores;
	map<string, int> menu;
	
	while (1) {
		cout << "-----------------------------" << endl;
		cout << "���Ͻô� ����� �������ּ���" << endl;
		cout << "1 ���� �߰� " << endl;
		cout << "2 ���� ���� " << endl;
		cout << "3 �޴� �߰� " << endl;
		cout << "4 �޴� ���� " << endl;
		cout << "5 ���� " << endl;
		cout << "-----------------------------" << endl;
		int x;
		x=write_int();

		switch (x)
		{
		//���� �߰� �ڵ�
		case 1: {
			//���������� ���� ��ü ���� �� ���Ϳ� push
			franchise_store add_store;
			stores.push_back(add_store);
			break;
		}
		//���� ���� �ڵ�
		case 2: {

			int temp = 0;
			string temp_name;
			string temp_adress;

			//������ �ԷµǾ����� ���� �� ���� ��� �� break
			if (stores.size() == 0) {
				cout << "������ �������� �ʽ��ϴ�.\n" << endl;
				break;
			}
			//���� ���� ���� ���
			cout << "----------���� ����----------" << endl;
			int i = 0;
			//for-each�� vector�� ���� ���� ��� 
			for (franchise_store var : stores)
			{
				cout << i + 1 << " ���� �̸� :  " << var.getName() + " ���� �ּ� : " + var.getAdress() << endl;
				i++;
			}
			cout << "-----------------------------" << endl;

			cout << "�����ϰ� ���� ������ ��ȣ�� �����ּ���." << endl;

			i = write_int();
			//������ �� ���� ��ȣ �Է� �� ���� ��� �� break
			if (i > stores.size()) {
				cout << "�ùٸ� ��ȣ�� �����ּ���.\n" << endl;
				break;
			}
			
			cout << "���� �̸��� ���� : 1" << endl;
			cout << "���� �ּҸ� ���� : 2" << endl;
			cout << "���� ���� : 3" << endl;
			cout << "���� ���� : 4" << endl;
			//����� �������� ���� �� ���� �ϴ� �ڵ�
			temp = write_int();
			switch (temp)
			{
			case 1: {
				string name;
				cout << "���ϴ� �̸��� �ۼ����ּ���." << endl;
				cin >> name;
				stores.at(i - 1).setName(name);
				break;
			}
			case 2: {
				string adress;
				cout << "���ϴ� �ּҸ� �ۼ����ּ���." << endl;
				cin >> adress;
				stores.at(i - 1).setAdress(adress);
				break;
			}
			case 3: {
				string name;
				cout << "���ϴ� �̸��� �ۼ����ּ���." << endl;
				cin >> name;
				stores.at(i - 1).setName(name);
				string adress;
				cout << "���ϴ� �ּҸ� �ۼ����ּ���." << endl;
				cin >> adress;
				stores.at(i - 1).setAdress(adress);
				break;
			}
			case 4: {
				stores.erase(stores.begin() + i - 1);
				break;

			default:
				cout << "��Ȯ�� ��ȣ�� �����ּ���." << endl;
				break;
			}

			}
			break;
		}
		//�޴� �߰� �ڵ�
		case 3: {
			string name;
			int price = 0;
			cout << "�޴� �̸��� �����ּ���." <<endl;
			cin >> name;
			cout << "�޴� ������ �����ּ���." << endl;
			price=write_int();
			menu.insert({ name, price });
			break;
		}
		//�޴� ���� �ڵ�
		case 4: {
			int i=0;
			string temp_n;
			if (menu.empty()) {
				cout << "�޴��� �������� �ʽ��ϴ�.\n" << endl;
				break;
			}
			cout << "----------�޴� ����----------" << endl;
			for (auto i:menu) {
				cout << " �޴� �̸� : " << i.first << " �޴� ���� : " << i.second << endl;
			}
			cout << "-----------------------------" << endl;
			cout << "�����ϰ� ���� �޴��� �̸��� �����ּ���." << endl;
			//�޴��� �̸��� �޾� map�� key������ �����ϴ��� �˻� �� ���� ����
			cin >> temp_n;
			if (menu.count(temp_n)==0) {
				cout << "�ش� �޴��� �������� �ʽ��ϴ�.\n" << endl;
				break;
			}
			cout << "�޴� ���� ���� : 1" << endl;
			cout << "�޴� ���� : 2" << endl;

			i = write_int();
			switch (i)
			{
			//�޴� ���� ����
			case 1: {
				int price=0;
				cout << "���ϴ� ������ �ۼ����ּ���." << endl;
				price = write_int();
				menu[temp_n] = price;
				break;
			}
			//�޴� ����
			case 2: {
				menu.erase(temp_n);
				break;
			}
			default:
				break;
			}
			break;
		}
		case 5: return 0;
		default:{
			   break;
			}
		}
	}
}
