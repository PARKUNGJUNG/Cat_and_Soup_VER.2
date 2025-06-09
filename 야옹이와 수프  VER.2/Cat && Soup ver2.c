#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <conio.h> //_getch(), _kbhit() �Լ��� ���� ���.

// #define �������ϱ� ���� ����Ǵ� �����Ϸ��� �� �κ�. ���� '��ũ��'��� ��.
#define _CRT_SECURE_NO_WARNINGS
#define ROOM_WIDTH 15 //���� �ʺ�
#define HME_POS 1 //�� ��ġ
#define BWL_PO (ROOM_WIDTH - 2) //���� ��ġ
int S_POS, T_POS;

// �� ��ġ ã�� �Լ�
int is_position_free(int pos, int cat_pos, int H_pos, int B_pos, int S_pos, int CT_pos) {
	if (pos == 0 || pos == ROOM_WIDTH - 1) return 0; // �� ��ġ ����
	if (pos == H_pos) return 0; // �� ��ġ ����
	if (pos == B_pos) return 0; // ���� ��ġ ����
	if (pos == S_pos && S_pos != 0) return 0; // ���� ��ũ��ó ��ġ ���� (S_pos�� 0�̸� ���� ��ġ �ȵ�)
	if (pos == CT_pos && CT_pos != 0) return 0; // ���� ĹŸ�� ��ġ ���� (CT_pos�� 0�̸� ���� ��ġ �ȵ�)
	if (pos == cat_pos) return 0; // ����� ��ġ ����
	return 1; // ��� ����
}

int find_random_free_position(int cat_pos, int H_pos, int B_pos, int S_pos, int CT_pos) {
	int pos;
	int try = 0;
	do {
		pos = rand() % (ROOM_WIDTH - 2) + 1; // 1 ~ ROOM_WIDTH-2 ����
		try++;
		if (try > 100) break; // ���� ���� ����
	} while (!is_position_free(pos, cat_pos, H_pos, B_pos, S_pos, CT_pos));
	return pos;
}

int main(void) {
	srand((unsigned int)time(NULL));

	int soup = 0; //���� ����
	int soup1 = soup; //���� ���� ����
	int relation = 2; //ģ�е� �ʱⰪ
	int relation1 = relation; //ģ�е��� ����
	int cat = 1; //������� �ʱ� ��ġ
	int cat1 = cat; // ���� ����� ��ġ
	int cat2 = cat1; // ���� ����� ��ġ
	int height = 4;
	int cp = 0; //�ڿ�, �߿��̰� ���� �� ��ǰ ���ſ� ���
	int cp1 = cp; //CP�� ����
	int cp2 = 0; //CP ���갪 ����
	int feel = 3; //��� �ʱⰪ
	int feel1 = feel; //��а� ����
	int interaction = 0; //��ȣ�ۿ� �ʱⰪ
	int dice = rand() % 6 + 1; //�ֻ���
	int store; //���� ��ǰ ���
	int TR = 1; //�峭�� ��
	int LZPT = 1; //������ ������
	int S = 1; //��ũ��ó
	int CT = 1; //Ĺ Ÿ��
	int item_list[2] = { 0 }; //������ ���� �迭, �ִ� 2��(TR, LZPT)
	int purchase = 0; //������ ��ȣ �ο�
	int max_choice = 1 + purchase; //���� ���� ���

	//1-4)�� �׸���
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < ROOM_WIDTH; j++) {
			if (i == 1 && j == HME_POS) {
				printf("H"); // �� ��ġ ǥ��
			}
			else if (i == 1 && j == T_POS && CT == 0) {
				printf("T"); // ĹŸ�� ��ġ ǥ��
			}
			else if (i == 1 && j == S_POS && S == 0) {
				printf("S"); // ��ũ��ó ��ġ ǥ��
			}
			else if (i == 1 && j == BWL_PO) {
				printf("B"); // ���� ��ġ ǥ��
			}
			else if (i == 2 && j == cat1) {
				printf("C"); //����� ��ġ ǥ��
			}
			else if (i == 2 && j == cat2) {
				printf("."); //����� ���� ��ġ ǥ��
			}
			// ��� �׸���
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
	printf("****�߿��̿� ����****\n\n\n");
	printf("           /\\_/\\    \n");
	printf("     /\\   / �� �� \\   \n");
	printf("    //\\\\  \\~(*)~/  \n");
	printf("    `  \\/    ^ /     \n");
	printf("       |  \\|| ||     \n");
	printf("       \\  '|| ||     \n");
	printf("        \\)  ()-())   \n\n");

	char name[20];
	printf("�߿����� �̸��� ���� �ּ���: ");
	scanf_s("%s", name, 20); //%c�� ��ߵǳ�?? //scanf_s�� ���ڿ� �Է½� �ڿ� ������ ũ�⸦ �Է��ؾߵ�.
	printf("�߿����� �̸��� %s�Դϴ�.", name);
	Sleep(1000);
	system("cls");

	//1-1)��Ʈ�� & �غ�
	while (1) {
		for (int i = 0; i < 1; i++) {
			Sleep(1000);
			system("cls");

			//1-2)���� ��� //���ݱ��� ���� ������ ���� //ģ�е� ���� ������ ���
			//2-1)����â ���� CP, ��� ���
			printf("==================== ���� ���� ====================\n");
			printf("������� ���� ���� : %d��\n", soup1);
			printf("CP: %d ����Ʈ\n", cp2);
			printf("%s�� ���(0~3): %d\n", name, feel1);
			if (feel1 == 0) printf(" ����� �ſ� ���޴ϴ�.\n");
			else if (feel1 == 1) printf("  �ɽ����մϴ�.\n");
			else if (feel1 == 2) printf("  �Ļ��� �����ϴ�.\n");
			else if (feel1 == 3) printf("  ������ �θ��ϴ�.\n");
			printf("������� ����(0~4) : %d\n", relation1);
			if (relation1 == 0) printf("  �翡 ���� ������ �Ⱦ��մϴ�.\n");
			else if (relation1 == 1) printf("  ���� ���Ǳ� ����Դϴ�.\n");
			else if (relation1 == 2) printf("  �׷����� �� ���� �����Դϴ�.\n");
			else if (relation1 == 3) printf("  �Ǹ��� ����� ���� �ް� �ֽ��ϴ�.\n");
			else if (relation1 == 4) printf("  ���� �������Դϴ�.\n");
			printf("===================================================\n");
			printf("												   \n");
			Sleep(500);

			//2-2)��� ������
			dice = rand() % 6 + 1;
			int relation2 = 6 - relation1;
			printf("6-%d: �ֻ��� ���� %d�����̸� �׳� ����� �������ϴ�.\n", relation1, relation2);
			printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
			printf("%d��(��) ���Խ��ϴ�.\n", dice);
			if (dice <= relation2) {
				int feel2 = feel1;
				feel1 -= 1;
				if (feel1 > 3) { feel1 = 3; }
				else if (feel1 < 0) { feel1 = 0; }
				printf("%s�� ����� �������ϴ� : %d->%d\n", name, feel2, feel1);
			}
			printf("\n");

			/*
			//1-5) �̵�
			dice = rand() % 6 + 1;
			int relation3 = 6 - relation1;
			printf("%s �̵�: ����� ģ���Ҽ��� ���� ������ �� Ȯ���� �������ϴ�.\n", name);
			printf("�ֻ��� ���� %d �̻��̸� ���� ������ �̵��մϴ�.\n", relation3);
			printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
			printf("%d�� (��) ���Խ��ϴ�!\n", dice);
			cat2 = cat1;
			if (dice >= relation3) {
				printf("���� ������ �����Դϴ�.\n");
				printf("\n");
				//���� ������ �� ĭ �̵�
				if (cat1 + 1 < ROOM_WIDTH - 1) {
					cat1++;
				}
			}
			else {
				//�� ������ �� ĭ �̵�
				printf("\n");
				if (cat1 - 1 > 0) {
					cat1--;
				}
			}
			*/

			//2-3)�̵�
			cat2 = cat1;
			if (feel1 == 0) {
				if (cat1 - 1 > 0) { cat1--; }
				printf("����� �ſ� ���� %s��(��) ������ ���մϴ�.\n", name);
			}
			else if (feel1 == 1) {
				// ��ũ��ó�� ĹŸ���� �ϳ��� ������
				if (S == 0 || CT == 0) {
					int min_dist = ROOM_WIDTH; // �ִ� �Ÿ��� �ʱ�ȭ
					int target_pos = cat1;     // �⺻���� ���� ��ġ

					// ��ũ��ó�� ������ �Ÿ� ���
					if (S == 0) {
						int dist = abs(S_POS - cat1); //abs = ����
						if (dist < min_dist) {
							min_dist = dist;
							target_pos = S_POS;
						}
					}
					// ĹŸ���� ������ �Ÿ� ���
					if (CT == 0) {
						int dist = abs(T_POS - cat1);
						if (dist < min_dist) {
							min_dist = dist;
							target_pos = T_POS;
						}
					}

					// �̵� (�� ĭ�� �̵�)
					if (cat1 < target_pos) {
						cat1++; // ���������� �̵�
					}
					else if (cat1 > target_pos) {
						cat1--; // �������� �̵�
					}
					printf("%s��(��) �ɽ��ؼ� �� ����� ���̱ⱸ ������ �̵��մϴ�.\n", name);
				}
				else {
					feel1--;
					if (feel1 > 3) { feel1 = 3; }
					else if (feel1 < 0) { feel1 = 0; }
					printf("�� �Ÿ��� ��� ����� �ſ� �������ϴ�.\n");
				}
			}
			else if (feel1 == 2) {
				printf("%s��(��) ������� �Ļ��� ���� �ֽ��ϴ�.\n", name);
			}
			else if (feel1 == 3) {
				if (cat1 + 1 < ROOM_WIDTH - 1) { cat1++; }
				printf("%s��(��) ������ �θ��� ������ ���鷯 ���ϴ�.\n", name);
			}
			printf("\n");

			//1-6) �ൿ
			//2-4) �ൿ
			if (HME_POS == cat1) {
				feel1++; //��
				if (feel1 > 3) { feel1 = 3; }
				else if (feel1 < 0) { feel1 = 0; }
				printf("%s��(��) �ڽ��� ������ ������� �����ϴ�.\n", name);
			}
			if (S == 0) {
				if (S_POS == cat1) {
					int feel2 = feel1;
					feel1++;
					if (feel1 > 3) { feel1 = 3; }
					else if (feel1 < 0) { feel1 = 0; }
					printf("%s��(��) ��ũ��ó�� �ܰ� ��ҽ��ϴ�.\n", name);
					printf("����� ���� ���������ϴ�: %d->%d\n", feel2, feel1);
				}
			}
			if (CT == 0) {
				if (T_POS == cat1) {
					int feel2 = feel1;
					feel1 += 2;
					if (feel1 > 3) { feel1 = 3; }
					else if (feel1 < 0) { feel1 = 0; }
					printf("%s��(��) ĹŸ���� �پ�ٴմϴ�.\n", name);
					printf("����� ���� ���������ϴ�: %d->%d\n", feel2, feel1);
				}
			}
			if (BWL_PO == cat1) {
				printf("%s��(��) ", name);
				int choicesoup = rand() % 3;
				if (choicesoup == 0) {
					printf("����� ����");
				}
				else if (choicesoup == 1) {
					printf("���� ����");
				}
				else if (choicesoup == 2) {
					printf("����ݸ� ����");
				}
				printf("�� ��������ϴ�!\n");
				soup++;
				soup1 = soup;
				printf("������� ���� ����: %d��\n", soup);
				//cat1 = cat; //������ ����� ������� ��ġ�� �ʱ�ȭ
				//cat2 = cat1; //������ ��ġ�� ���� ��ġ�� �����ϰ� ����.
				//������ ����� ������� ��ġ�� �ʱ�ȭ ��Ű�� �ڵ��Դϴ�.
				//�������� �ۼ��� �ʿ䰡 ���� �ڵ尰���� �ʱ�ȭ�� ���Ѿ� �Ǵ��� �ȵǴ��� ������ �Ȱ� �ڵ带 �ּ�ó�� �߽��ϴ�.
			}

			//1-4) �� �׸���
			printf("\n");
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < ROOM_WIDTH; j++) {
					if (i == 1 && j == HME_POS) {
						printf("H"); // �� ��ġ ǥ��
					}
					else if (i == 1 && j == T_POS && CT == 0) {
						printf("T"); // ĹŸ�� ��ġ ǥ��
					}
					else if (i == 1 && j == S_POS && S == 0) {
						printf("S"); // ��ũ��ó ��ġ ǥ��
					}
					else if (i == 1 && j == BWL_PO) {
						printf("B"); // ���� ��ġ ǥ��
					}
					else if (i == 2 && j == cat1) {
						printf("C"); //����� ��ġ ǥ��
					}
					else if (i == 2 && j == cat2 && cat2 != cat1) {
						printf("."); //����� ���� ��ġ ǥ��
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

			//1-3)��ȣ�ۿ�
			//2-5)��ȣ�ۿ� �Է�
			//2-6)��ȣ�ۿ� ó��

			dice = rand() % 6 + 1;
			printf("\n");
			printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?\n");
			printf("  0. �ƹ��͵� ���� ����\n");
			printf("  1. �ܾ� �ֱ�\n");
			for (int i = 0; i < purchase; i++) {
				switch (item_list[i]) {
				case 1: printf("  %d. �峭�� ��� ��� �ֱ�\n", i + 2); break;
				case 2: printf("  %d. ������ �����ͷ� ��� �ֱ�\n", i + 2); break;
				}
			}
		Loop:
			printf(">> ");
			scanf_s("%d", &interaction);
			if (interaction == 0) {
				int feel2 = feel1;
				feel1--;
				if (feel1 > 3) { feel1 = 3; }
				else if (feel1 < 0) { feel1 = 0; }
				printf("%s�� ����� ���������ϴ�: %d->%d\n", name, feel2, feel1);
				printf("�ֻ����� ������ ���� 5 �����̸� ���谡 1 �����մϴ�.\n");
				printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
				printf("%d��(��) ���Խ��ϴ�!\n", dice);
				if (dice <= 5) {
					printf("������� ���谡 �������ϴ�.\n");
					relation1 -= 1;
					if (relation1 < 0) {
						relation1 = 0;
					}
					printf("���� ģ�е�: %d\n", relation1);
				}
				else {
					printf("������ ģ�е��� �������� �ʾҽ��ϴ�.\n");
					printf("���� ģ�е�: %d\n", relation1);
				}
			}

			if (interaction == 1) {
				printf("%s�� ���� �ܾ��־����ϴ�.\n", name);
				printf("%s�� ����� �״���Դϴ�: %d\n", name, feel1);
				printf("�ֻ����� 5 �̻��̸� ���谡 1 �����մϴ�.\n");
				printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
				printf("%d��(��) ���Խ��ϴ�!\n", dice);
				if (dice == 5 || dice == 6) {
					printf("ģ�е��� �������ϴ�.\n");
					relation1 += 1;
					if (relation1 > 4) {
						relation1 = 4;
					}
					printf("���� ģ�е�: %d\n", relation1);
				}
				else {
					printf("ģ�е��� �״���Դϴ�.\n");
					printf("���� ģ�е�: %d\n", relation1);
				}
			}

			if (interaction >= 2) {
				int item_index = interaction - 2;
				if (item_index >= purchase) {
					goto Loop;
				}

				switch (item_list[item_index]) {
				case 1: // �峭�� �� ó��
					printf("�峭�� ��� %s�� ��� �־����ϴ�.\n", name);
					int feel2 = feel1;
					feel1++;
					if (feel1 > 3) { feel1 = 3; }
					else if (feel1 < 0) { feel1 = 0; }
					printf("%s�� ����� ���� ���������ϴ�: %d->%d\n", name, feel2, feel1);
					printf("�ֻ����� 4 �̻��̸� ���谡 1 �����մϴ�.\n");
					printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
					printf("%d��(��) ���Խ��ϴ�!\n", dice);
					if (dice >= 4) {
						printf("ģ�е��� �������ϴ�.\n");
						relation1 += 1;
						if (relation1 > 4) {
							relation1 = 4;
						}
						printf("���� ģ�е�: %d\n", relation1);
					}
					else {
						printf("ģ�е��� �״���Դϴ�.\n");
						printf("���� ģ�е�: %d\n", relation1);
					}
					break;

				case 2: // ������ ������ ó�� 
					printf("������ �����ͷ� %s�� �ų��� ��� �־����ϴ�.\n", name);
					feel2 = feel1;
					feel1 += 2;
					if (feel1 > 3) { feel1 = 3; }
					else if (feel1 < 0) { feel1 = 0; }
					printf("%s�� ����� �� ���������ϴ�: %d->%d\n", name, feel2, feel1);
					printf("�ֻ����� 2 �̻��̸� ���谡 1 �����մϴ�.\n");
					printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
					printf("%d��(��) ���Խ��ϴ�!\n", dice);
					if (dice >= 2) {
						printf("ģ�е��� �������ϴ�.\n");
						relation1 += 1;
						if (relation1 > 4) {
							relation1 = 4;
						}
						printf("���� ģ�е�: %d\n", relation1);
					}
					else {
						printf("ģ�е��� �״���Դϴ�.\n");
						printf("���� ģ�е�: %d\n", relation1);
					}
					break;
				}
			}

			/*
			if (interaction == 2) {
				printf("�峭�� ��� %s�� ��� �־����ϴ�.\n", name);
				int feel2 = feel1;
				feel1++;
				printf("%s�� ����� ���� ���������ϴ�: %d->%d\n", name, feel2, feel1);
				printf("�ֻ����� 4 �̻��̸� ���谡 1 �����մϴ�.\n");
				printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
				printf("%d��(��) ���Խ��ϴ�!\n", dice);
				if (dice >= 4) {
					printf("ģ�е��� �������ϴ�.\n");
					relation1 += 1;
					if (relation1 > 4) {
						relation1 = 4;
					}
					printf("���� ģ�е�: %d\n", relation1);
				}
				else {
					printf("ģ�е��� �״���Դϴ�.\n");
					printf("���� ģ�е�: %d\n", relation1);
				}
			}

			if (interaction == 3) {
				printf("������ �����ͷ� %s�� �ų��� ��� �־����ϴ�.\n", name);
				int feel2 = feel1;
				feel1 += 2;
				printf("%s�� ����� �� ���������ϴ�: %d->%d\n", name, feel2, feel1);
				printf("�ֻ����� 2 �̻��̸� ���谡 1 �����մϴ�.\n");
				printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
				printf("%d��(��) ���Խ��ϴ�!\n", dice);
				if (dice >= 2) {
					printf("ģ�е��� �������ϴ�.\n");
					relation1 += 1;
					if (relation1 > 4) {
						relation1 = 4;
					}
					printf("���� ģ�е�: %d\n", relation1);
				}
				else {
					printf("ģ�е��� �״���Դϴ�.\n");
					printf("���� ģ�е�: %d\n", relation1);
				}
			}
			*/
			else if (interaction < 0 || interaction > max_choice) {
				goto Loop;
			}
			Sleep(500);

			//2-7) CP ����
			printf("\n");
			int feel2 = feel1 - 1; //(��� -1) ��
			if (feel2 < 0) { feel2 = 0; }
			int CPcnt = (feel2 + relation1);
			printf("%s�� ���(0~3): %d\n", name, feel1);
			printf("������� ģ�е�(0~4): %d\n", relation1);
			printf("%s�� ��а� ģ�е��� ���� CP�� %d ����Ʈ ����Ǿ����ϴ�.\n", name, CPcnt);
			cp1 = CPcnt;
			cp2 += cp1;
			printf("���� CP: %d ����Ʈ\n", cp2);
			printf("\n");
			Sleep(500);

			//2-8) ����
			printf("�������� ������ �� �� �ֽ��ϴ�.\n");
			printf("� ������ �����ұ��?\n");
			printf("  0. �ƹ� �͵� ���� �ʴ´�.\n");
			if (TR == 1) { printf("  1. �峭�� ��: 1 CP\n"); }
			else if (TR == 0) { printf("  1. �峭�� ��: 1 CP (ǰ��)\n"); }
			if (LZPT == 1) { printf("  2. ������ ������: 2 CP\n"); }
			else if (LZPT == 0) { printf("  2. ������ ������: 2 CP (ǰ��)\n"); }
			if (S == 1) { printf("  3. ��ũ��ó: 4 CP\n"); }
			else if (S == 0) { printf("  3. ��ũ��ó: 4 CP (ǰ��)\n"); }
			if (CT == 1) { printf("  4. Ĺ Ÿ��: 6 CP\n"); }
			else if (CT == 0) { printf("  4. Ĺ Ÿ��: 6 CP (ǰ��)\n"); }

		Loop2:
			printf(">> ");
			scanf_s("%d", &store);
			if (0 <= store && store <= 4) {
				if (store == 0) {
					printf("�ƹ� �͵� ���� �ʽ��ϴ�.\n");
					continue;
				}

				if (store == 1) {
					if (TR == 0) {
						printf("�峭�� �㸦 �̹� �����߽��ϴ�.\n");
						goto Loop2;
					}
					if (cp2 >= 1) {
						printf("�峭�� �㸦 �����߽��ϴ�.\n");
						item_list[purchase++] = 1;
						TR = 0;
						cp2 -= 1;
						printf("���� CP %d ����Ʈ\n", cp2);
						continue;
					}
					else if (cp2 < 1) {
						printf("CP�� �����մϴ�.\n");
						goto Loop2;
					}
				}

				if (store == 2) {
					if (LZPT == 0) {
						printf("������ �����͸� �̹� �����߽��ϴ�.\n");
						goto Loop2;
					}
					if (cp2 >= 2) {
						printf("������ �����͸� �����߽��ϴ�.\n");
						item_list[purchase++] = 2;
						LZPT = 0;
						cp2 -= 2;
						printf("���� CP %d ����Ʈ\n", cp2);
						continue;
					}
					else if (cp2 < 2) {
						printf("CP�� �����մϴ�.\n");
						goto Loop2;
					}
				}

				if (store == 3) {
					if (S == 0) {
						printf("��ũ��ó�� �̹� �����߽��ϴ�.\n");
						goto Loop2;
					}
					if (cp2 >= 4) {
						printf("��ũ��ó�� �����߽��ϴ�.\n");
						S_POS = find_random_free_position(cat1, HME_POS, BWL_PO, S_POS, T_POS);
						S = 0;
						cp2 -= 4;
						printf("���� CP %d ����Ʈ\n", cp2);
						continue;
					}
					else if (cp2 < 4) {
						printf("CP�� �����մϴ�.\n");
						goto Loop2;
					}
				}

				if (store == 4) {
					if (CT == 0) {
						printf("Ĺ Ÿ���� �̹� �����߽��ϴ�.\n");
						goto Loop2;
					}
					if (cp2 >= 6) {
						printf("Ĺ Ÿ���� �����߽��ϴ�.\n");
						T_POS = find_random_free_position(cat1, HME_POS, BWL_PO, S_POS, T_POS);
						CT = 0;
						cp2 -= 6;
						printf("���� CP %d ����Ʈ\n", cp2);
						continue;
					}
					else if (cp2 < 6) {
						printf("CP�� �����մϴ�.\n");
						goto Loop2;
					}
				}
			}
			else { goto Loop2; }
			printf("\n");

			Sleep(2500);
			system("cls");
		}
		//2-9) ���� ����Ʈ
		printf("\n���� ����Ʈ �߻�!\n");
		int quest = rand() % 2;
		switch (quest) {
		case 0: // ����̿��� �̴ϰ���
			printf("����̿� �̴ϰ����� �����մϴ�!\n");
			printf("5�� �ȿ� 'a' Ű�� 10�� �Է��ϼ���!\n");
			int count = 0;
			time_t start = time(NULL);
			while (difftime(time(NULL), start) < 5.0) {
				if (_kbhit()) { //_kbhit() Ű���尡 ���ȴ��� üũ����.
					if (_getch() == 'a') { //_getch() Ű���� �Է��� �ް� ����� ������ ����.
						count++;
						printf("����! (%d/10)\n", count);
					}
				}
			}
			if (count >= 10) {
				printf("�̴ϰ��� ����! %s�� ����� ���������ϴ�!\n", name);
				feel1++;
				if (feel1 > 3) feel1 = 3;
			}
			else {
				printf("�̴ϰ��� ����! ������ �ٽ� �����ϼ���.\n");
			}
			break;

		case 1: // ����� ����ֱ� ç����
			printf("����� ����ֱ� ç����!\n");
			printf("10�� ���� ����̿� ��ȣ�ۿ�(�ܾ��ֱ�, �峭�� ��)�� �ִ��� ���� �ϼ���!\n");
			printf("(���͸� ���� ������ ��ȣ�ۿ� 1ȸ)\n");
			int interaction_count = 0;
			start = time(NULL);
			while (difftime(time(NULL), start) < 10.0) {
				if (_kbhit()) {
					if (_getch() == '\r') { //\r ����
						interaction_count++;
						printf("��ȣ�ۿ� %dȸ!\n", interaction_count);
					}
				}
			}
			printf("�� %dȸ ��ȣ�ۿ�!\n", interaction_count);
			if (interaction_count >= 3) {
				printf("ç���� ����! %s�� ģ�е��� �ö����ϴ�!\n", name);
				relation1++;
				if (relation1 > 4) relation1 = 4;
			}
			else {
				printf("���� �� ����غ�����!\n");
			}
			break;
		}
		printf("\n");
	}
}


///��� ������


///��� ������
//������ ����� ����� ��ġ�� �ʱ�ȭ �ؾߵǴ���. (�ش� �ڵ带 �ϴ� �ּ�ó���Ͽ� �ۼ���.)
//ģ�е��� 6 �̻��� ��, ������ �ߵ��Ǵ��� (�ٵ�, ģ�е��� �ִ� 4�� �����Ǿ�����.)
//ģ�е��� ���尪�� ��� ��ġ�� �־�� ����� �ڵ尡 �ߵ��Ǵ���. //while ������
//���� ���¶� ���� ��� �׻� ������. //while ������
//goto���� ����ص� �Ǵ���.
//�̸� �ۼ��ϴ� �ڵ带 ��ȣ�ۿ� �� ������ ����ߵǴ���.
//�̸� �ۼ��� ó���� 1���� ����ߵ�.
//������ ��� ����ؾ� �Ǵ���. //ǥ������ ������ �ƹ����� �ص� ��.
//CP���� ���� �������� ���� ����ؾߵǴ���. //ǥ������ ������ �ƹ����� ���
//��ȣ�ۿ� ó�� �κп��� '�ƹ��͵� ���� ����' �� '�ܾ� �ֱ�' �� ver.1�� �����ϰ� �����ߵǴ��� �ƴϸ� �״�� ���δ���. //ver.1�� �����ص� ������ �˾Ƽ� �� ��������
//���� ���� ���Ŀ��� �ȵȴٴ°�. ó������ �ȵȴٴ°��� //����.