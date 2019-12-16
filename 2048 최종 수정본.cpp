#include"2048map.h"

int main()
{

	srand((unsigned)time(NULL));

	GameSe mainMenu;
	while (mainMenu.skip)
	{
		mainMenu.Print_Main();//����ȭ���� ����Ѵ�.
		mainMenu.Arrow_Control();//w,s,�����̽��ٸ� ������ _getch()�Լ��� ��带 ����Ű�� �������� �����Ѵ�.
	}
	if (mainMenu.selectMode == 4)
	{
		Map_2048 map1;
		int randnum = rand() % 16;
		while (true)
		{
			map1.Print_Board();//���� ȭ���� ����Ѵ�.
			map1.Move_Number();//getKey ���� ������ �°� �Լ� ȣ�� 2048�� �� �̵�
			randnum = rand() % 10;//Creat_2()�Լ��� ����� ���� �� 0�� ��-1 �ؼ� 0�Ǹ� 2����
			map1.Creat_2(randnum);// �������� ���������� ó������ 0�� 2����
			map1.End_Chack();//ĭ�� 0�� �ƴѼ��� ä�����ְ� mapī�Ǻ� map������ �� ��ȭ���� 2����üũ�� true�϶�
			if (map1.mapSameChack == true)
			{
				cout << "2�� �������� ���ؼ� GameOver";
				break;
			}
			if (map1.chack2048 == true)//End_Chack���� 2048�� �޼��ϸ�  chack2048�� true�� ��ȯ
			{
				cout << "�̱�̽��ϴ�.";
				break;
			}

		}
	}
	else if (mainMenu.selectMode == 3)
	{
		RPGPlayer player;//�⺻ 2048Ŭ������  Chack_32_64() Move_Number() �� �޼ҵ�������̵��� �� �ڽ� Ŭ����
		RPGEnemy moster;// hp�� damage ��������� ���� mosterŬ����
		int randnum = rand() % 16;
		bool chack = false;//�����ð��� ������ false�� ��ȭ player�����
		player.Print_Board();
		clock_t startTime = clock();//���� �ð����� 
		clock_t endTime = clock();//�� �ð�����

		while (true)
		{
			if (kbhit()) {
				player.Move_Number();//getKey ���� ������ �°� �Լ� ȣ�� ������ 2048�� ���ݹ� ��� 2�� �߰�
				moster.Set_Hp(player.ReturnDamage());//player�� ������ ���� �� ���ո�ŭ ����� ��ȯSet_Hp�� ����� �ݿ�
				randnum = rand() % 16;//Creat_2()�Լ��� ����� ���� �� 0�� ��-1 �ؼ� 0�Ǹ� 2����
				player.Creat_2(randnum);// �������� ���������� ó������ 0�� 2����
				player.End_Chack();//ĭ�� 0�� �ƴѼ��� ä�����ְ� mapī�Ǻ� map������ �� ��ȭ���� 2����üũ�� true�϶�
				player.Print_Board();//����ȭ�� ��� ��ȭ�� ȭ�� ���
				moster.Print_Monster();// ���ͺ�ȭ�� ȭ�� ���
				_getch();
			}
			_sleep(100);
			player.Print_Board();//����ȭ�� ��� ��ȭ�� ȭ�� ���
			moster.Print_Monster();// ���ͺ�ȭ�� ȭ�� ���
			//�޼ҵ� �������̵����� 32�̻� ������ mapSameChack�� false�� �����߰�
			if (player.mapSameChack == true)
			{
				cout << "2�� �������� ���ؼ� GameOver";
				break;
			}
			if (chack == false)
			{
				player.Hp_less((moster.Get_Damage() * 5));//�ð��� ���� chack�� false�̸� player HP����
				player.Print_Board();//����ȭ�� ��� ��ȭ�� ȭ�� ���
				moster.Print_Monster();// ���ͺ�ȭ�� ȭ�� ���
				chack = true;//chack�� true�� ��ȭ
				startTime = clock();//���� �ð� ����� ���� �������� ��ȯ
			}
			endTime = clock();//�Է��ϸ鼭 ����ð� ����
			if ((endTime - startTime) > 3000)//����ð��� ���� �ð��� ��  3�� ���� �� 
			{
				chack = false;//chack�� false�� ��ȭ
			}
			if (moster.Get_Hp() < 0)// ���� HP�� 0�̵Ǹ� ��
			{
				cout << "�̱�̽��ϴ�." << endl;
				break;
			}
			if (player.Get_Hp() < 0)// player HP�� 0�̵Ǹ� ��
			{
				cout << "�й��ϼ̽��ϴ�." << endl;
				break;
			}
		}

	}
	else if (mainMenu.selectMode == 2)
	{
		Map_2048 map1;// ������ Map_2048Ŭ����
		Map_2048_2p map2;//Map_2048Ŭ���� ����� �ڽ� Ŭ���� Ű�� �޸��ϰų� map1�� ������� �Լ� �߰�
		int randnum = 0;
		while (true)//������ ���� 128�� �Ѹ� �� ���� �޼��ϸ�
		{
			map2.Print_Board(map1);//Map_2048_2pŬ������ �߰��� �Լ�map1���� ���� ���
			cout << "1P�����Դϴ�.";
			map1.Move_Number();//getKey ���� ������ �°� �Լ� ȣ�� 2048�� �� �̵�
			map2.Map_Chack_128(map1);//Map���� 128�̳Ѵ� ��Ȯ�� �� �� ���� 0���� ��ȯchack128_1P�� 1����
			randnum = rand() % 10;//Creat_2()�Լ��� ����� ���� �� 0�� ��-1 �ؼ� 0�Ǹ� 2����
			map1.Creat_2(randnum);// �������� ���������� ó������ 0�� 2����
			map2.Print_Board(map1);//���� ȭ���� ����Ѵ�.
			map1.End_Chack();//ĭ�� 0�� �ƴѼ��� ä�����ְ� mapī�Ǻ� map������ �� ��ȭ���� 2����üũ�� true�϶�
			if (map1.mapSameChack == true)//map1�� GameOver���� �޼����� Ȯ��
			{
				cout << "2�� �������� ���ؼ� 1P GameOver";
				break;
			}
			cout << "2P�����Դϴ�.";
			map2.Move_Number(map1);//getKey ���� ������ �°� �Լ� ȣ�� 2048�� �� �̵� �Լ����� Print_Board�Լ�
			map2.Map_Chack_128(map1);//Map���� 128�̳Ѵ� ��Ȯ�� �� �� ���� 0���� ��ȯchack128_2P�� 1����
													 //������� map1�� �Է¹���
			randnum = rand() % 10;//Creat_2()�Լ��� ����� ���� �� 0�� ��-1 �ؼ� 0�Ǹ� 2����
			map2.Creat_2(randnum);// �������� ���������� ó������ 0�� 2����
			map2.End_Chack();//ĭ�� 0�� �ƴѼ��� ä�����ְ� mapī�Ǻ� map������ �� ��ȭ���� 2����üũ�� true�϶�
			if (map2.mapSameChack == true)//map2�� GameOver���� �޼����� Ȯ��
			{
				cout << "2�� �������� ���ؼ� 1P GameOver";
				break;
			}
			if (map2.chack128_1P > 2)// 1P�� 128�� 3�� �޼� 
			{
				map2.Print_Board(map1);
				cout << "1p�� �¸� �Ͽ����ϴ�.";
				break;
			}
			if (map2.chack128_2P > 2)// 2P�� 128�� 3�� �޼� 
			{
				map2.Print_Board(map1);
				cout << "2p�� �¸� �Ͽ����ϴ�.";
				break;
			}
		}
	}
	else if (mainMenu.selectMode == 2)
	{

	}
}
