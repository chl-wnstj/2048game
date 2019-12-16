#include"2048map.h"

int main()
{

	srand((unsigned)time(NULL));

	GameSe mainMenu;
	while (mainMenu.skip)
	{
		mainMenu.Print_Main();//메인화면을 출력한다.
		mainMenu.Arrow_Control();//w,s,스페이스바를 누르면 _getch()함수로 모드를 가리키는 변수값을 수정한다.
	}
	if (mainMenu.selectMode == 4)
	{
		Map_2048 map1;
		int randnum = rand() % 16;
		while (true)
		{
			map1.Print_Board();//게임 화면을 출력한다.
			map1.Move_Number();//getKey 문자 변수에 맞게 함수 호출 2048의 수 이동
			randnum = rand() % 10;//Creat_2()함수에 사용할 난수 값 0일 때-1 해서 0되면 2생성
			map1.Creat_2(randnum);// 난수값에 맞지않으면 처음나온 0에 2삽입
			map1.End_Chack();//칸이 0이 아닌수로 채워져있고 map카피본 map값복사 값 변화없고 2생성체크가 true일때
			if (map1.mapSameChack == true)
			{
				cout << "2를 생성하지 못해서 GameOver";
				break;
			}
			if (map1.chack2048 == true)//End_Chack에서 2048을 달성하면  chack2048를 true로 변환
			{
				cout << "이기셨습니다.";
				break;
			}

		}
	}
	else if (mainMenu.selectMode == 3)
	{
		RPGPlayer player;//기본 2048클래스에  Chack_32_64() Move_Number() 등 메소드오버라이딩을 한 자식 클래스
		RPGEnemy moster;// hp와 damage 멤버변수를 가진 moster클래스
		int randnum = rand() % 16;
		bool chack = false;//일정시간이 지나면 false로 변화 player대미지
		player.Print_Board();
		clock_t startTime = clock();//시작 시간저장 
		clock_t endTime = clock();//끝 시간저장

		while (true)
		{
			if (kbhit()) {
				player.Move_Number();//getKey 문자 변수에 맞게 함수 호출 기존의 2048에 공격및 기술 2개 추가
				moster.Set_Hp(player.ReturnDamage());//player가 공격을 누를 시 총합만큼 대미지 반환Set_Hp로 대미지 반영
				randnum = rand() % 16;//Creat_2()함수에 사용할 난수 값 0일 때-1 해서 0되면 2생성
				player.Creat_2(randnum);// 난수값에 맞지않으면 처음나온 0에 2삽입
				player.End_Chack();//칸이 0이 아닌수로 채워져있고 map카피본 map값복사 값 변화없고 2생성체크가 true일때
				player.Print_Board();//게임화면 출력 변화된 화면 출력
				moster.Print_Monster();// 몬스터변화된 화면 출력
				_getch();
			}
			_sleep(100);
			player.Print_Board();//게임화면 출력 변화된 화면 출력
			moster.Print_Monster();// 몬스터변화된 화면 출력
			//메소드 오버라이딩으로 32이상 있을시 mapSameChack값 false로 조건추가
			if (player.mapSameChack == true)
			{
				cout << "2를 생성하지 못해서 GameOver";
				break;
			}
			if (chack == false)
			{
				player.Hp_less((moster.Get_Damage() * 5));//시간에 따라 chack가 false이면 player HP감소
				player.Print_Board();//게임화면 출력 변화된 화면 출력
				moster.Print_Monster();// 몬스터변화된 화면 출력
				chack = true;//chack가 true로 변화
				startTime = clock();//시작 시간 대미지 입힌 시점으로 변환
			}
			endTime = clock();//입력하면서 현재시간 대입
			if ((endTime - startTime) > 3000)//현재시간에 시작 시간을 빼  3초 넘을 시 
			{
				chack = false;//chack가 false로 변화
			}
			if (moster.Get_Hp() < 0)// 몬스터 HP가 0이되면 끝
			{
				cout << "이기셨습니다." << endl;
				break;
			}
			if (player.Get_Hp() < 0)// player HP가 0이되면 끝
			{
				cout << "패배하셨습니다." << endl;
				break;
			}
		}

	}
	else if (mainMenu.selectMode == 2)
	{
		Map_2048 map1;// 기존의 Map_2048클래스
		Map_2048_2p map2;//Map_2048클래스 상속한 자식 클래스 키를 달리하거나 map1의 정보출력 함수 추가
		int randnum = 0;
		while (true)//끝나는 조건 128을 한명 이 세번 달성하면
		{
			map2.Print_Board(map1);//Map_2048_2p클래스에 추가한 함수map1값도 같이 출력
			cout << "1P차례입니다.";
			map1.Move_Number();//getKey 문자 변수에 맞게 함수 호출 2048의 수 이동
			map2.Map_Chack_128(map1);//Map값중 128이넘는 수확인 및 해 변수 0으로 전환chack128_1P값 1증가
			randnum = rand() % 10;//Creat_2()함수에 사용할 난수 값 0일 때-1 해서 0되면 2생성
			map1.Creat_2(randnum);// 난수값에 맞지않으면 처음나온 0에 2삽입
			map2.Print_Board(map1);//게임 화면을 출력한다.
			map1.End_Chack();//칸이 0이 아닌수로 채워져있고 map카피본 map값복사 값 변화없고 2생성체크가 true일때
			if (map1.mapSameChack == true)//map1이 GameOver조건 달성인지 확인
			{
				cout << "2를 생성하지 못해서 1P GameOver";
				break;
			}
			cout << "2P차례입니다.";
			map2.Move_Number(map1);//getKey 문자 변수에 맞게 함수 호출 2048의 수 이동 함수에서 Print_Board함수
			map2.Map_Chack_128(map1);//Map값중 128이넘는 수확인 및 해 변수 0으로 전환chack128_2P값 1증가
													 //사용으로 map1을 입력받음
			randnum = rand() % 10;//Creat_2()함수에 사용할 난수 값 0일 때-1 해서 0되면 2생성
			map2.Creat_2(randnum);// 난수값에 맞지않으면 처음나온 0에 2삽입
			map2.End_Chack();//칸이 0이 아닌수로 채워져있고 map카피본 map값복사 값 변화없고 2생성체크가 true일때
			if (map2.mapSameChack == true)//map2이 GameOver조건 달성인지 확인
			{
				cout << "2를 생성하지 못해서 1P GameOver";
				break;
			}
			if (map2.chack128_1P > 2)// 1P가 128을 3개 달성 
			{
				map2.Print_Board(map1);
				cout << "1p가 승리 하였습니다.";
				break;
			}
			if (map2.chack128_2P > 2)// 2P가 128을 3개 달성 
			{
				map2.Print_Board(map1);
				cout << "2p가 승리 하였습니다.";
				break;
			}
		}
	}
	else if (mainMenu.selectMode == 2)
	{

	}
}
