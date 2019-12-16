#pragma once
#include <iostream>
#include<conio.h>
#include<time.h>
#include<ctime>
#include <process.h>

using namespace std;

class Map_2048 {

	int  moveCounter;


public:
	bool creatChack;
	bool mapSameChack;
	int  map[4][4];
	int  mapCopy[4][4];
	char getKey;
	bool chack2048;

	Map_2048() {
		creatChack = true;
		mapSameChack = false;
		chack2048 = false;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				map[i][j] = 2;
			}
		}
	}

	void End_Chack()
	{
		int sameChack = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (mapCopy[i][j] == map[i][j])
				{
					sameChack++;
				}
			}
		}
		if ((creatChack == true) && (sameChack > 15))
		{
			mapSameChack = true;
		}

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				mapCopy[i][j] = map[i][j];
				if (map[i][j] > 2047)
				{
					chack2048 = true;
				}
			}
		}
		if (mapSameChack == false)
		{
			sameChack = 0;
		}
	}

	void Move_Number()
	{
		getKey = _getch();
		switch (getKey)
		{
		case 'w':
			Move_UP();
			break;
		case 'a':
			Move_Left();
			break;
		case 's':
			Move_Down();
			break;
		case 'd':
			Move_Right();
			break;

		default:
			cout << "다시입력해주세요" << endl;
			Move_Number();
			Print_Board();
			break;
		}
	}

	void Move_Left()
	{
		for (int a = 0; a < 3; a++)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (map[i][j] == 0)
					{
						map[i][j] = map[i][j + 1];
						map[i][j + 1] = 0;
					}
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (map[i][j] == map[i][j + 1])
				{
					map[i][j] += map[i][j + 1];
					map[i][j + 1] = 0;
					j++;
				}
			}
		}
		for (int a = 0; a < 2; a++)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (map[i][j] == 0)
					{
						map[i][j] = map[i][j + 1];
						map[i][j + 1] = 0;
					}
				}
			}
		}
	}
	void Move_Right()
	{
		for (int a = 0; a < 3; a++)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 3; j > 0; j--)
				{
					if (map[i][j] == 0)
					{
						map[i][j] = map[i][j - 1];
						map[i][j - 1] = 0;
					}
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 3; j > 0; j--)
			{
				if (map[i][j] == map[i][j - 1])
				{
					map[i][j] += map[i][j - 1];
					map[i][j - 1] = 0;
				}
			}
		}
		for (int a = 0; a < 2; a++)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 3; j > 0; j--)
				{
					if (map[i][j] == 0)
					{
						map[i][j] = map[i][j - 1];
						map[i][j - 1] = 0;
					}
				}
			}
		}
	}

	void Move_UP()
	{
		for (int a = 0; a < 3; a++)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (map[j][i] == 0)
					{
						map[j][i] = map[j + 1][i];
						map[j + 1][i] = 0;
					}
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (map[j][i] == map[j + 1][i])
				{
					map[j][i] += map[j + 1][i];
					map[j + 1][i] = 0;
					j++;
				}
			}
		}
		for (int a = 0; a < 2; a++)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (map[j][i] == 0)
					{
						map[j][i] = map[j + 1][i];
						map[j + 1][i] = 0;
					}
				}
			}
		}
	}
	void Move_Down()
	{
		for (int a = 0; a < 3; a++)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 3; j > 0; j--)
				{
					if (map[j][i] == 0)
					{
						map[j][i] = map[j - 1][i];
						map[j - 1][i] = 0;
					}
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 3; j > 0; j--)
			{
				if (map[j][i] == map[j - 1][i])
				{
					map[j][i] += map[j - 1][i];
					map[j - 1][i] = 0;
				}
			}
		}
		for (int a = 0; a < 2; a++)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 3; j > 0; j--)
				{
					if (map[j][i] == 0)
					{
						map[j][i] = map[j - 1][i];
						map[j - 1][i] = 0;
					}
				}
			}
		}
	}
	void Print_Board() {
		system("cls");
		cout << "======2048======" << '\n';
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
			{
				cout << map[i][j] << "   ";
			}
			cout << '\n' << '\n';
		}
		cout << "w: 위  a: 왼쪽  s: 아래  d: 오른쪽" << '\n';
		cout << '\n';
		cout << ">>";
	}

	void Creat_2(int a) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
			{
				if (map[i][j] == 0)
					--a;
				if ((a < 0) && (map[i][j] == 0) && creatChack)
				{
					map[i][j] = 2;
					creatChack = false;
				}
			}
		}
		if (creatChack == true)
		{
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++)
				{
					if (map[i][j] == 0 && creatChack == true)
					{
						map[i][j] = 2;
						creatChack = false;
					}
				}
			}
		}
		creatChack = true;
	}
};


class Map_2048_2p :public Map_2048
{

public:
	int chack128_1P = 0;
	int chack128_2P = 0;
	void Map_Chack_128(Map_2048& a)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (map[i][j] > 127)
				{
					map[i][j] = 0;
					chack128_2P++;
				}
				if (a.map[i][j] > 127)
				{
					a.map[i][j] = 0;
					chack128_1P++;
				}
			}
		}
	}
	void Move_Number(const Map_2048& a)
	{
		getKey = _getch();
		switch (getKey)
		{
		case '8':
			Move_UP();
			break;
		case '4':
			Move_Left();
			break;
		case '6':
			Move_Right();
			break;
		case '5':
			Move_Down();
			break;
		default:
			cout << "다시입력해주세요" << endl;
			Move_Number(a);
			Print_Board(a);
			break;
		}
	}
	void Print_Board(const Map_2048& a) {
		system("cls");
		cout << "======2048======" << "		======2048======" << '\n';
		cout << "1P" << "				2P" << endl;
		for (int i = 0; i < 4; i++) {

			for (int j = 0; j < 4; j++)
			{
				cout << a.map[i][j] << "   ";
			}
			cout << "		";
			for (int j = 0; j < 4; j++)
			{
				cout << map[i][j] << "   ";
			}
			cout << '\n' << '\n';
		}
		cout << "w: 위  a: 왼쪽  s: 아래  d: 오른쪽" << '\n';
		cout << "8: 위  4: 왼쪽  5: 아래  6: 오른쪽" << '\n';
		cout << '\n';

		cout << "128 세개를 먼저 만들시 승리" << '\n';
		cout << "1p: ";
		for (int i = 0; i < chack128_1P; i++)
		{
			cout << "◎";
		}
		cout << '\n';
		cout << "2p: ";
		for (int i = 0; i < chack128_2P; i++)
		{
			cout << "◎";
		}
		cout << '\n';
		cout << ">>";
	}
};


class GameSe
{
	int key;
	int ui;
	char selectUi[4];

public:
	bool skip;
	int selectMode;

	GameSe() {
		ui = 3;
		selectMode = 10;
		skip = true;
	}

	void Arrow_Control()
	{
		key = _getch();
		if (key == 224)
		{
			key = _getch();
			switch (key)
			{
			case(72):
				++ui;
				break;
			case(80):
				--ui;
				break;

			default:
				break;
			}
			Ui_Set();
		}
		else if (key == 13)
		{
			skip = false;
			Ui_Set();
		}
	}

	void Ui_Set()
	{
		if (ui > 4)
			ui = 1;
		else if (ui < 1)
			ui = 4;
		for (int i = 0; i < 4; i++)
		{
			selectUi[i] = 'O';
		}
		selectUi[ui - 1] = '*';
	}

	void Print_Main()
	{
		Ui_Set();
		selectMode = ui;
		system("cls");
		cout << "	      " << "2048 게임즈" << endl << endl;
		cout << "	" << selectUi[3] << " 1인 플레이(노멀 모드)" << endl << endl;
		cout << "	" << selectUi[2] << " 1인 플레이(어택 모드)" << endl << endl;
		cout << "	" << selectUi[1] << " 2인 플레이(대전 모드)" << endl << endl;
		cout << "	" << selectUi[0] << " 	게임 종료" << endl << endl;
		cout << " 원하는 모드 선택후 Enter를 두번 눌러주세요" << endl << endl;
	}
};


class  RPGPlayer :public Map_2048
{
	int hp;
	int energe;
	int attackDamage;

public:
	bool attackChack;

	RPGPlayer()
	{
		hp = 300;
		energe = 0;
		attackDamage = 0;
		attackChack = false;

	}

	int Get_Hp()
	{
		return hp;
	}

	void End_Chack()
	{
		int sameChack = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (mapCopy[i][j] == map[i][j])
				{
					sameChack++;
				}
				if (mapCopy[i][j] > 31)
				{
					sameChack--;
				}
			}
		}
		if ((creatChack == true) && (sameChack > 15))
		{
			mapSameChack = true;
		}

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				mapCopy[i][j] = map[i][j];
				if (map[i][j] > 2047)
				{
					chack2048 = true;
				}
			}
		}
		if (mapSameChack == false)
		{
			sameChack = 0;
		}
	}

	void Chack_32_64()
	{
		attackChack = true;
		for (int i = 0; i < 4; i++) {

			for (int j = 0; j < 4; j++)
			{
				if (map[i][j] == 32)
				{
					attackDamage += 32;
					map[i][j] = 0;
				}
				if (map[i][j] > 63)
				{
					attackDamage += map[i][j];
					energe++;
					map[i][j] = 0;
				}
			}
		}
	}

	int ReturnDamage()
	{
		int reteunDamage = 0;
		reteunDamage = attackDamage;
		attackDamage = 0;
		return reteunDamage;
	}

	void Move_Number()
	{
			getKey = _getch();
			switch (getKey)
			{
			case 'w':
				Move_UP();
				break;
			case 'a':
				Move_Left();
				break;
			case 's':
				Move_Down();
				break;
			case 'd':
				Move_Right();
				break;
			case' ':
				Chack_32_64();
				break;
			case'z':
				Change_2_8();
				break;
			case'x':
				Heal();
				break;
			default:

				cout << "다시입력해주세요" << endl;
				Move_Number();
				Print_Board();
				break;
			
		}
	}

	void Print_attck() //
	{
		cout << attackDamage << "만큼 공격";
	}

	void Hp_less(int damage) //
	{
		hp -= damage;
	}

	void Change_2_8()
	{
		if (energe > 2)
		{
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++)
				{
					if (map[i][j] == 2)
					{
						map[i][j] = 8;
					}
				}
			}
			energe -= 3;
		}
	}

	void Heal() {
		if (energe > 2)
		{
			hp += (energe * 15);
			energe = 0;
		}
	}

	void Print_Board() {
		system("cls");
		cout << "======2048======" << '\n';
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
			{
				cout << map[i][j] << "   ";
			}
			cout << '\n' << '\n';
		}
		cout << "	Hp :" << hp;
		for (int i = 0; i < (hp / 30); i++)
		{
			cout << "■" << " ";
		}
		cout << '\n';
		cout << "	EnergeGage :";
		for (int i = 0; i < energe; i++)
		{
			cout << "◎" << " ";
		}
		cout << '\n';
		cout << "SPACE바: 32이상 공격 " << '\n' << "Energe게이지가 3 이상일 때 z: 2를 8으로 x: 게이지*15 회복" << '\n';
		cout << "w: 위  a: 왼쪽  s: 아래  d: 오른쪽" << '\n';
		cout << '\n';
		Print_attck();
		cout << ">>";
	}
};

class  RPGEnemy
{
protected:
	int	hp;
	int damage;

public:

	RPGEnemy() {
		hp = 500;
		damage = 2;
	}

	int Get_Damage()
	{
		return damage;
	}

	int Get_Hp()
	{
		return hp;
	}

	void Set_Hp(int plyerDamage)
	{
		hp -= plyerDamage;
	}

	void Print_Monster()
	{
		cout << "	" << "Monster" << endl;
		cout << "	" << "Hp :" << hp;
		for (int i = 0; i < (hp / 50); i++)
		{
			cout << "●";
		}
	}
};
