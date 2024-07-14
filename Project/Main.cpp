#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<cctype>

using namespace std;
//입력 받을때 정수형이 아니면 다시 입력받는 함수
int write_int() {
	int result;
	while (!(cin >> result)) {
		cin.clear();
		while (cin.get() == '\n') break;
		cout << "올바른 값(정수)을 적어주세요.\n" << endl;
		break;
	}
	return result;
}
int main() {
	//프랜차이즈 매장 클래스
	class franchise_store{
	private:
		string name;
		string adress;
	public:
		franchise_store(){
			cout << "매장 이름을 작성해주세요 " << endl;
			cin >> name;
			cout << "매장 주소를 작성해주세요 " << endl;
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

	//매장 vector와 메뉴 map 선언
	vector<franchise_store>stores;
	map<string, int> menu;
	
	while (1) {
		cout << "-----------------------------" << endl;
		cout << "원하시는 기능을 선택해주세요" << endl;
		cout << "1 매장 추가 " << endl;
		cout << "2 매장 수정 " << endl;
		cout << "3 메뉴 추가 " << endl;
		cout << "4 메뉴 수정 " << endl;
		cout << "5 종료 " << endl;
		cout << "-----------------------------" << endl;
		int x;
		x=write_int();

		switch (x)
		{
		//매장 추가 코드
		case 1: {
			//프랜차이즈 매장 객체 생성 후 벡터에 push
			franchise_store add_store;
			stores.push_back(add_store);
			break;
		}
		//매장 수정 코드
		case 2: {

			int temp = 0;
			string temp_name;
			string temp_adress;

			//매장이 입력되어있지 않을 때 오류 출력 후 break
			if (stores.size() == 0) {
				cout << "매장이 존재하지 않습니다.\n" << endl;
				break;
			}
			//현재 매장 내역 출력
			cout << "----------매장 내역----------" << endl;
			int i = 0;
			//for-each로 vector내 값들 전부 출력 
			for (franchise_store var : stores)
			{
				cout << i + 1 << " 매장 이름 :  " << var.getName() + " 매장 주소 : " + var.getAdress() << endl;
				i++;
			}
			cout << "-----------------------------" << endl;

			cout << "수정하고 싶은 매장의 번호를 적어주세요." << endl;

			i = write_int();
			//수정할 수 없는 번호 입력 시 오류 출력 후 break
			if (i > stores.size()) {
				cout << "올바른 번호를 적어주세요.\n" << endl;
				break;
			}
			
			cout << "가게 이름만 수정 : 1" << endl;
			cout << "가게 주소만 수정 : 2" << endl;
			cout << "전부 수정 : 3" << endl;
			cout << "가게 삭제 : 4" << endl;
			//저장된 정보들을 수정 및 삭제 하는 코드
			temp = write_int();
			switch (temp)
			{
			case 1: {
				string name;
				cout << "원하는 이름을 작성해주세요." << endl;
				cin >> name;
				stores.at(i - 1).setName(name);
				break;
			}
			case 2: {
				string adress;
				cout << "원하는 주소를 작성해주세요." << endl;
				cin >> adress;
				stores.at(i - 1).setAdress(adress);
				break;
			}
			case 3: {
				string name;
				cout << "원하는 이름을 작성해주세요." << endl;
				cin >> name;
				stores.at(i - 1).setName(name);
				string adress;
				cout << "원하는 주소를 작성해주세요." << endl;
				cin >> adress;
				stores.at(i - 1).setAdress(adress);
				break;
			}
			case 4: {
				stores.erase(stores.begin() + i - 1);
				break;

			default:
				cout << "정확한 번호를 적어주세요." << endl;
				break;
			}

			}
			break;
		}
		//메뉴 추가 코드
		case 3: {
			string name;
			int price = 0;
			cout << "메뉴 이름을 적어주세요." <<endl;
			cin >> name;
			cout << "메뉴 가격을 적어주세요." << endl;
			price=write_int();
			menu.insert({ name, price });
			break;
		}
		//메뉴 수정 코드
		case 4: {
			int i=0;
			string temp_n;
			if (menu.empty()) {
				cout << "메뉴가 존재하지 않습니다.\n" << endl;
				break;
			}
			cout << "----------메뉴 내역----------" << endl;
			for (auto i:menu) {
				cout << " 메뉴 이름 : " << i.first << " 메뉴 가격 : " << i.second << endl;
			}
			cout << "-----------------------------" << endl;
			cout << "수정하고 싶은 메뉴의 이름을 적어주세요." << endl;
			//메뉴의 이름을 받아 map의 key값으로 존재하는지 검색 및 가격 수정
			cin >> temp_n;
			if (menu.count(temp_n)==0) {
				cout << "해당 메뉴가 존재하지 않습니다.\n" << endl;
				break;
			}
			cout << "메뉴 가격 수정 : 1" << endl;
			cout << "메뉴 삭제 : 2" << endl;

			i = write_int();
			switch (i)
			{
			//메뉴 가격 수정
			case 1: {
				int price=0;
				cout << "원하는 가격을 작성해주세요." << endl;
				price = write_int();
				menu[temp_n] = price;
				break;
			}
			//메뉴 삭제
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
