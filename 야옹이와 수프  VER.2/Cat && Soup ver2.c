#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
// #define 컴파일하기 전에 실행되는 컴파일러의 한 부분. 보통 '매크로'라고 함.
#define _CRT_SECURE_NO_WARNINGS
#define ROOM_WIDTH 10 //방의 너비
#define HME_POS 1 //집 위치
#define BWL_PO (ROOM_WIDTH - 2) //냄비 위치

int main(void) {
	srand((unsigned int)time(NULL));

	int soup = 0; //수프 개수
	int soup1 = soup; //수프 개수 저장
	int relation = 2; //친밀도 초기값
	int relation1 = relation; //친밀도값 저장
	int cat = 1; //고양이의 초기 위치
	int cat1 = cat; // 현재 고양이 위치
	int cat2 = cat1; // 직전 고양이 위치
	int height = 4;

	//1-4)방 그리기
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < ROOM_WIDTH; j++) {
			if (i == 1 && j == HME_POS) {
				printf("H"); // 집 위치 표시
			}
			else if (i == 1 && j == BWL_PO) {
				printf("B"); // 냄비 위치 표시
			}
			else if (i == 2 && j == cat1) {
				printf("C"); //고양이 위치 표시
			}
			else if (i == 2 && j == cat2) {
				printf("."); //고양이 직전 위치 표시
			}
			// 경계 그리기
			else if (i == 0 || i == height - 1 || j == 0 || j == ROOM_WIDTH - 1) {
				printf("#");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}

	printf("                      \n");
	printf("****야옹이와 수프****\n\n\n");
	printf("           /\\_/\\    \n");
	printf("     /\\   / ° ° \\   \n");
	printf("    //\\\\  \\~(*)~/  \n");
	printf("    `  \\/    ^ /     \n");
	printf("       |  \\|| ||     \n");
	printf("       \\  '|| ||     \n");
	printf("        \\)  ()-())   \n\n");

	char name[20];
	printf("야옹이의 이름을 지어 주세요: ");
	scanf_s("%s", name, 20); //%c를 써야되나?? //scanf_s는 문자열 입력시 뒤에 버퍼의 크기를 입력해야됨.
	printf("야옹이의 이름은 %s입니다.", name);
	Sleep(1000);
	system("cls");

	//1-1)인트로 & 준비
	while (1) {

		//1-2)상태 출력 //지금까지 만든 수프의 개수 //친밀도 값과 설명을 출력
		printf("==================== 현재 상태 ====================\n");
		printf("현재까지 만든 수프 : %d개\n", soup1);
		printf("집사와의 관계(0~4) : %d\n", relation1);
		if (relation1 == 0) printf("  곁에 오는 것조차 싫어합니다.\n");
		else if (relation1 == 1) printf("  간식 자판기 취급입니다.\n");
		else if (relation1 == 2) printf("  그럭저럭 쓸 만한 집사입니다.\n");
		else if (relation1 == 3) printf("  훌륭한 집사로 인정 받고 있습니다.\n");
		else if (relation1 == 4) printf("  집사 껌딱지입니다.\n");
		printf("===================================================\n");
		printf("												   \n");
		Sleep(500);


		//1-4)방 그리기
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < ROOM_WIDTH; j++) {
				if (i == 1 && j == HME_POS) {
					printf("H"); // 집 위치 표시
				}
				else if (i == 1 && j == BWL_PO) {
					printf("B"); // 냄비 위치 표시
				}
				else if (i == 2 && j == cat1) {
					printf("C"); //고양이 위치 표시
				}
				else if (i == 2 && j == cat2 && cat2 != cat1) {
					printf("."); //고양이 직전 위치 표시
				}
				// 경계 그리기
				else if (i == 0 || i == height - 1 || j == 0 || j == ROOM_WIDTH - 1) {
					printf("#");
				}
				else {
					printf(" ");
				}
			}
			printf("\n");
		}
		Sleep(500);


		//1-3)상호작용
		int interaction = 0;
		int dice = rand() % 6 + 1;
		printf("                                                                \n");
		printf("어떤 상호작용을 하시겠습니까?   0. 아무것도 하지 않음   1. 긁어 주기\n");
	Loop:
		printf(">> ");
		scanf_s("%d", &interaction);
		if (interaction == 0 || interaction == 1) {
			if (interaction == 0) {
				printf("아무것도 하지 않습니다.\n");
				printf("4/6의 확률로 친밀도가 떨어집니다.\n");
				printf("주사위를 굴립니다. 또르륵...\n");
				printf("%d이(가) 나왔습니다!\n", dice);
				if (dice <= 4) {
					printf("친밀도가 떨어집니다.\n");
					relation1 -= 1;
					if (relation1 < 0) {
						relation1 = 0;
					}
					printf("현재 친밀도: %d\n", relation1);
				}
				else {
					printf("다행히 친밀도가 떨어지지 않았습니다.\n");
					printf("현재 친밀도: %d\n", relation1);
				}
			}
			else {
				printf("%s의 턱을 긁어주었습니다.\n", name);
				printf("2/6의 확률로 친밀도가 높아집니다.\n");
				printf("주사위를 굴립니다. 또르륵...\n");
				printf("%d이(가) 나왔습니다!\n", dice);
				if (dice == 5 || dice == 6) {
					printf("친밀도가 높아집니다.\n");
					relation1 += 1;
					if (relation1 > 4) {
						relation1 = 4;
					}
					printf("현재 친밀도: %d\n", relation1);
					printf("\n");
				}
				else {
					printf("친밀도는 그대로입니다.\n");
					printf("현재 친밀도: %d\n", relation1);
					printf("\n");
				}
			}
		}
		else {
			goto Loop;
		}
		Sleep(500);

		//1-5) 이동
		int relation2 = 6 - relation1;
		printf("%s 이동: 집사와 친밀할수록 냄비 쪽으로 갈 확률이 높아집니다.\n", name);
		printf("주사위 눈이 %d 이상이면 냄비 쪽으로 이동합니다.\n", relation2);
		printf("주사위를 굴립니다. 또르륵...\n");
		printf("%d이 (가) 나왔습니다!\n", dice);
		cat2 = cat1;
		if (dice >= relation2) {
			printf("냄비 쪽으로 움직입니다.\n");
			printf("\n");
			//냄비 쪽으로 한 칸 이동
			if (cat1 + 1 < ROOM_WIDTH - 1) {
				cat1++;
			}
		}
		else {
			//집 쪽으로 한 칸 이동
			printf("\n");
			if (cat1 - 1 > 0) {
				cat1--;
			}
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < ROOM_WIDTH; j++) {
				if (i == 1 && j == HME_POS) {
					printf("H"); // 집 위치 표시
				}
				else if (i == 1 && j == BWL_PO) {
					printf("B"); // 냄비 위치 표시
				}
				else if (i == 2 && j == cat1) {
					printf("C"); //고양이 위치 표시
				}
				else if (i == 2 && j == cat2 && cat2 != cat1) {
					printf("."); //고양이 직전 위치 표시
				}
				else if (i == 0 || i == height - 1 || j == 0 || j == ROOM_WIDTH - 1) {
					printf("#");
				}
				else {
					printf(" ");
				}
			}
			printf("\n");
		}
		Sleep(500);

		//1-6) 행동
		if (HME_POS == cat1) {
			printf("%s은(는) 자신의 집에서 편안함을 느낍니다.\n", name);
		}
		else if (BWL_PO == cat1) {
			printf("%s이(가) ", name);
			int choicesoup = rand() % 3;
			if (choicesoup == 0) {
				printf("양송이 수프");
			}
			else if (choicesoup == 1) {
				printf("감자 수프");
			}
			else if (choicesoup == 2) {
				printf("브로콜리 수프");
			}
			printf("를 만들었습니다!\n");
			soup++;
			soup1 = soup;
			printf("현재까지 만든 수프: %d개\n", soup);
			//cat1 = cat; //수프를 만들면 고양이의 위치를 초기화
			//cat2 = cat1; //직전의 위치도 현재 위치랑 동일하게 설정.
			//수프를 만들면 고양이의 위치를 초기화 시키는 코드입니다.
			//과제에는 작성할 필요가 없는 코드같지만 초기화를 시켜야 되는지 안되는지 가늠이 안가 코드를 주석처리 했습니다.
		}
		Sleep(2500);
		system("cls");
	}
}

///물어볼 질문들
//수프를 만들고 고양이 위치를 초기화 해야되는지. (해당 코드를 일단 주석처리하여 작성함.)

///물어본 질문들

//친밀도가 6 이상일 때, 조건이 발동되는지 (근데, 친밀도는 최대 4로 설정되어있음.)
//친밀도의 저장값을 어느 위치에 넣어야 제대로 코드가 발동되는지. //while 밖으로
//현재 상태랑 방을 어떻게 항상 띄우는지. //while 밖으로
//goto문을 사용해도 되는지.
//이름 작성하는 코드를 상호작용 할 때마다 띄워야되는지.
//이름 작성은 처음에 1번만 띄워야됨.
