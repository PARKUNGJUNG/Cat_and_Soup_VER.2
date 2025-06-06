#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
// #define 컴파일하기 전에 실행되는 컴파일러의 한 부분. 보통 '매크로'라고 함.
#define _CRT_SECURE_NO_WARNINGS
#define ROOM_WIDTH 15 //방의 너비
#define HME_POS 1 //집 위치
#define BWL_PO (ROOM_WIDTH - 2) //냄비 위치
#define S_POS (ROOM_WIDTH - 6) //스크래처 위치
#define T_POS (ROOM_WIDTH - 10) //캣 타워 위치

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
	int cp = 0; //자원, 야옹이가 생산 및 물품 구매에 사용
	int cp1 = cp; //CP값 저장
	int cp2 = 0; //CP 생산값 저장
	int feel = 3; //기분 초기값
	int feel1 = feel; //기분값 저장
	int interaction = 0; //상호작용 초기값
	int dice = rand() % 6 + 1; //주사위
	int store; //상점 물품 목록
	int TR = 1; //장난감 쥐
	int LZPT = 1; //레이저 포인터
	int S = 1; //스크래처
	int CT = 1; //캣 타워

	//1-4)방 그리기
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < ROOM_WIDTH; j++) {
			if (i == 1 && j == HME_POS) {
				printf("H"); // 집 위치 표시
			}
			else if (i == 1 && j == T_POS && CT == 0) {
				printf("T"); // 캣타워 위치 표시
			}
			else if (i == 1 && j == S_POS && S == 0) {
				printf("S"); // 스크래처 위치 표시
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
		//2-1)상태창 변경 CP, 기분 출력
		printf("==================== 현재 상태 ====================\n");
		printf("현재까지 만든 수프 : %d개\n", soup1);
		printf("CP: %d 포인트\n", cp2);
		printf("%s이 기분(0~3): %d\n", name, feel1);
		if (feel1 == 0) printf(" 기분이 매우 나쁩니다.\n");
		else if (feel1 == 1) printf("  심심해합니다.\n");
		else if (feel1 == 2) printf("  식빵을 굽습니다.\n");
		else if (feel1 == 3) printf("  골골송을 부릅니다.\n");
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
				else if (i == 1 && j == T_POS && CT == 0) {
					printf("T"); // 캣타워 위치 표시
				}
				else if (i == 1 && j == S_POS && S == 0) {
					printf("S"); // 스크래처 위치 표시
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

		//2-2)기분 나빠짐
		dice = rand() % 6 + 1;
		int relation2 = 6 - relation1;
		printf("\n");
		printf("6-%d: 주사위 눈이 %d이하이면 그냥 기분이 나빠집니다.\n", relation1, relation2);
		printf("주사위를 굴립니다. 또르르...\n");
		printf("%d이(가) 나왔습니다.\n", dice);
		if (dice <= relation2) {
			int feel2 = feel1;
			feel1 -= 1;
			if (feel1 > 3) { feel1 = 3; }
			else if (feel1 < 0) { feel1 = 0; }
			printf("%s의 기분이 나빠집니다 : %d->%d\n", name, feel2, feel1);
		}

		//1-3)상호작용
		dice = rand() % 6 + 1;
		printf("\n");
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

		/*
		//1-5) 이동
		dice = rand() % 6 + 1;
		int relation3 = 6 - relation1;
		printf("%s 이동: 집사와 친밀할수록 냄비 쪽으로 갈 확률이 높아집니다.\n", name);
		printf("주사위 눈이 %d 이상이면 냄비 쪽으로 이동합니다.\n", relation3);
		printf("주사위를 굴립니다. 또르륵...\n");
		printf("%d이 (가) 나왔습니다!\n", dice);
		cat2 = cat1;
		if (dice >= relation3) {
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
		*/

		//2-3)이동
		cat2 = cat1;
		if (feel1 == 0) {
			if (cat1 - 1 > 0) { cat1--; }
			printf("기분이 매우 나쁜 %s은(는) 집으로 향합니다.\n", name);
		}
		else if (feel1 == 1) {}
		else if (feel1 == 2) { 
			printf("%s은(는) 기분좋게 식빵을 굽고 있습니다.\n", name); 
		}
		else if (feel1 == 3) {
			if (cat1 + 1 < ROOM_WIDTH - 1) { cat1++; }
			printf("%s은(는) 골골송을 부르며 수프를 만들러 갑니다.\n", name);
		}
		printf("\n");
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < ROOM_WIDTH; j++) {
				if (i == 1 && j == HME_POS) {
					printf("H"); // 집 위치 표시
				}
				else if (i == 1 && j == T_POS && CT == 0) {
					printf("T"); // 캣타워 위치 표시
				}
				else if (i == 1 && j == S_POS && S == 0) {
					printf("S"); // 스크래처 위치 표시
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
		//2-4) 행동
		if (HME_POS == cat1) {
			feel1++; //집
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

		//2-7) CP 생산
		printf("\n");
		int feel2 = feel1 - 1; //(기분 -1) 값
		if (feel2 < 0) { feel2 = 0; }
		int CPcnt = (feel2 + relation1);
		printf("%s의 기분(0~3): %d\n", name, feel1);
		printf("집사와의 친밀도(0~4): %d\n", relation1);
		printf("%s의 기분과 친밀도에 따라서 CP가 %d 포인트 생산되었습니다.\n", name, CPcnt);
		cp1 = CPcnt;
		cp2 += cp1;
		printf("보유 CP: %d 포인트\n", cp2);
		printf("\n");
		Sleep(500);

		//2-8) 상점
		printf("상점에서 물건을 살 수 있습니다.\n");
		printf("어떤 물건을 구매할까요?\n");
		printf("  0. 아무 것도 사지 않는다.\n");
		if (TR == 1) { printf("  1. 장난감 쥐: 1 CP\n"); }
		else if (TR == 0) { printf("  1. 장난감 쥐: 1 CP (품절)\n"); }
		if (LZPT == 1) { printf("  2. 레이저 포인터: 2 CP\n"); }
		else if (LZPT == 0) { printf("  2. 레이저 포인터: 2 CP (품절)\n"); }
		if (S == 1) { printf("  3. 스크래처: 4 CP\n"); }
		else if (S == 0) { printf("  3. 스크래처: 4 CP (품절)\n"); }
		if (CT == 1) { printf("  4. 캣 타워: 6 CP\n"); }
		else if (CT == 0) { printf("  4. 캣 타워: 6 CP (품절)\n"); }

	Loop2:
		printf(">> ");
		scanf_s("%d", &store);
		if (0 <= store && store <= 4) {
			if (store == 0) {
				printf("아무 것도 사지 않습니다.\n");
				continue;
			}

			if (store == 1) {
				if (TR == 0) {
					printf("장난감 쥐를 이미 구매했습니다.\n");
					goto Loop2;
				}
				if (cp2 >= 1) {
					printf("장난감 쥐를 구매했습니다.\n");
					TR = 0;
					cp2 -= 1;
					printf("보유 CP %d 포인트\n", cp2);
					continue;
				}
				else if (cp2 < 1) {
					printf("CP가 부족합니다.\n");
					goto Loop2;
				}
			}

			if (store == 2) {
				if (LZPT == 0) {
					printf("레이저 포인터를 이미 구매했습니다.\n");
					goto Loop2;
				}
				if (cp2 >= 2) {
					printf("레이저 포인터를 구매했습니다.\n");
					LZPT = 0;
					cp2 -= 2;
					printf("보유 CP %d 포인트\n", cp2);
					continue;
				}
				else if (cp2 < 2) {
					printf("CP가 부족합니다.\n");
					goto Loop2;
				}
			}

			if (store == 3) {
				if (S == 0) {
					printf("스크래처를 이미 구매했습니다.\n");
					goto Loop2;
				}
				if (cp2 >= 4) {
					printf("스크래처를 구매했습니다.\n");
					S = 0;
					cp2 -= 4;
					printf("보유 CP %d 포인트\n", cp2);
					continue;
				}
				else if (cp2 < 4) {
					printf("CP가 부족합니다.\n");
					goto Loop2;
				}
			}

			if (store == 4) {
				if (CT == 0) {
					printf("캣 타워를 이미 구매했습니다.\n");
					goto Loop2;
				}
			 if (cp2 >= 6) {
				printf("캣 타워를 구매했습니다.\n");
				CT = 0;
				cp2 -= 6;
				printf("보유 CP %d 포인트\n", cp2);
				continue;
			}
			else if (cp2 < 6) {
				printf("CP가 부족합니다.\n");
				goto Loop2;
			}
			}
		}
		else { goto Loop2; }
		printf("\n");

		Sleep(2500);
		//system("cls");
	}
}


///물어볼 질문들


///물어본 질문들
//수프를 만들고 고양이 위치를 초기화 해야되는지. (해당 코드를 일단 주석처리하여 작성함.)
//친밀도가 6 이상일 때, 조건이 발동되는지 (근데, 친밀도는 최대 4로 설정되어있음.)
//친밀도의 저장값을 어느 위치에 넣어야 제대로 코드가 발동되는지. //while 밖으로
//현재 상태랑 방을 어떻게 항상 띄우는지. //while 밖으로
//goto문을 사용해도 되는지.
//이름 작성하는 코드를 상호작용 할 때마다 띄워야되는지.
//이름 작성은 처음에 1번만 띄워야됨.
//상점은 어디에 출력해야 되는지. //표시하지 않은건 아무데나 해도 됨.
//CP생산 매턴 마지막에 따로 출력해야되는지. //표시하지 않은건 아무데나 출력
//상호작용 처리 부분에서 '아무것도 하지 않음' 과 '긁어 주기' 를 ver.1을 삭제하고 만들어야되는지 아니면 그대로 놔두는지. //ver.1을 수정해도 되지만 알아서 잘 버무리기
//집에 들어온 직후에는 안된다는게. 처음에도 안된다는건지 //맞음.




