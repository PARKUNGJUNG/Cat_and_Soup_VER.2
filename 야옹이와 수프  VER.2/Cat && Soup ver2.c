#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
// #define �������ϱ� ���� ����Ǵ� �����Ϸ��� �� �κ�. ���� '��ũ��'��� ��.
#define _CRT_SECURE_NO_WARNINGS
#define ROOM_WIDTH 10 //���� �ʺ�
#define HME_POS 1 //�� ��ġ
#define BWL_PO (ROOM_WIDTH - 2) //���� ��ġ

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

	//1-4)�� �׸���
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < ROOM_WIDTH; j++) {
			if (i == 1 && j == HME_POS) {
				printf("H"); // �� ��ġ ǥ��
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

		//1-2)���� ��� //���ݱ��� ���� ������ ���� //ģ�е� ���� ������ ���
		printf("==================== ���� ���� ====================\n");
		printf("������� ���� ���� : %d��\n", soup1);
		printf("������� ����(0~4) : %d\n", relation1);
		if (relation1 == 0) printf("  �翡 ���� ������ �Ⱦ��մϴ�.\n");
		else if (relation1 == 1) printf("  ���� ���Ǳ� ����Դϴ�.\n");
		else if (relation1 == 2) printf("  �׷����� �� ���� �����Դϴ�.\n");
		else if (relation1 == 3) printf("  �Ǹ��� ����� ���� �ް� �ֽ��ϴ�.\n");
		else if (relation1 == 4) printf("  ���� �������Դϴ�.\n");
		printf("===================================================\n");
		printf("												   \n");
		Sleep(500);


		//1-4)�� �׸���
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < ROOM_WIDTH; j++) {
				if (i == 1 && j == HME_POS) {
					printf("H"); // �� ��ġ ǥ��
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
		Sleep(500);


		//1-3)��ȣ�ۿ�
		int interaction = 0;
		int dice = rand() % 6 + 1;
		printf("                                                                \n");
		printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?   0. �ƹ��͵� ���� ����   1. �ܾ� �ֱ�\n");
	Loop:
		printf(">> ");
		scanf_s("%d", &interaction);
		if (interaction == 0 || interaction == 1) {
			if (interaction == 0) {
				printf("�ƹ��͵� ���� �ʽ��ϴ�.\n");
				printf("4/6�� Ȯ���� ģ�е��� �������ϴ�.\n");
				printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
				printf("%d��(��) ���Խ��ϴ�!\n", dice);
				if (dice <= 4) {
					printf("ģ�е��� �������ϴ�.\n");
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
			else {
				printf("%s�� ���� �ܾ��־����ϴ�.\n", name);
				printf("2/6�� Ȯ���� ģ�е��� �������ϴ�.\n");
				printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
				printf("%d��(��) ���Խ��ϴ�!\n", dice);
				if (dice == 5 || dice == 6) {
					printf("ģ�е��� �������ϴ�.\n");
					relation1 += 1;
					if (relation1 > 4) {
						relation1 = 4;
					}
					printf("���� ģ�е�: %d\n", relation1);
					printf("\n");
				}
				else {
					printf("ģ�е��� �״���Դϴ�.\n");
					printf("���� ģ�е�: %d\n", relation1);
					printf("\n");
				}
			}
		}
		else {
			goto Loop;
		}
		Sleep(500);

		//1-5) �̵�
		int relation2 = 6 - relation1;
		printf("%s �̵�: ����� ģ���Ҽ��� ���� ������ �� Ȯ���� �������ϴ�.\n", name);
		printf("�ֻ��� ���� %d �̻��̸� ���� ������ �̵��մϴ�.\n", relation2);
		printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
		printf("%d�� (��) ���Խ��ϴ�!\n", dice);
		cat2 = cat1;
		if (dice >= relation2) {
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
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < ROOM_WIDTH; j++) {
				if (i == 1 && j == HME_POS) {
					printf("H"); // �� ��ġ ǥ��
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

		//1-6) �ൿ
		if (HME_POS == cat1) {
			printf("%s��(��) �ڽ��� ������ ������� �����ϴ�.\n", name);
		}
		else if (BWL_PO == cat1) {
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
		Sleep(2500);
		system("cls");
	}
}

///��� ������
//������ ����� ����� ��ġ�� �ʱ�ȭ �ؾߵǴ���. (�ش� �ڵ带 �ϴ� �ּ�ó���Ͽ� �ۼ���.)

///��� ������

//ģ�е��� 6 �̻��� ��, ������ �ߵ��Ǵ��� (�ٵ�, ģ�е��� �ִ� 4�� �����Ǿ�����.)
//ģ�е��� ���尪�� ��� ��ġ�� �־�� ����� �ڵ尡 �ߵ��Ǵ���. //while ������
//���� ���¶� ���� ��� �׻� ������. //while ������
//goto���� ����ص� �Ǵ���.
//�̸� �ۼ��ϴ� �ڵ带 ��ȣ�ۿ� �� ������ ����ߵǴ���.
//�̸� �ۼ��� ó���� 1���� ����ߵ�.
