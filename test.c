#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Menu() {
	printf("***********************\n");
	printf("      ��������Ϸ       \n");
	printf(" 1.��ʼ��Ϸ 0.������Ϸ \n");
	printf("***********************\n");
	printf("   ����������ѡ��    \n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

#define Max_ROW 10
#define MAX_COL 10
char chess_board[Max_ROW][MAX_COL];
void Init() {
	for (int row = 0; row < Max_ROW; ++row) {
		for (int col = 0; col < MAX_COL; ++col) {
			chess_board[row][col] = ' ';
		}
	}
}
void Print() {//��ӡ����
	for (int i = 0; i < MAX_COL; ++i) {
		printf("   %d", i);
	}
	printf("\n");
	printf("  ");
	for (int i = 0; i < MAX_COL; ++i) {
		printf("----");
	}
	printf("\n");
	for (int row = 0; row < Max_ROW; ++row) {
		printf("%d|", row);
		for (int col = 0; col < MAX_COL; ++col) {
			printf(" %c |", chess_board[row][col]);
		}
		printf("\n");
		//for (int row = 0; row < Max_ROW; ++row) {
		//printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n",
		//	chess_board[row][0],chess_board[row][1],chess_board[row][2], chess_board[row][3],
		//	chess_board[row][4], chess_board[row][5], chess_board[row][6], chess_board[row][7],
		//	chess_board[row][8], chess_board[row][9]);
		if (row != Max_ROW - 1) {
			printf("  ---|---|---|---|---|---|---|---|---|---|\n");
		}
		if (row == Max_ROW - 1) {
			printf("  ----------------------------------------\n");
		}
	}
}
void PlayerMove() {
	printf("������ӣ�\n");
	while (1) {
		printf("����������λ�õ����꣨row��col):");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= Max_ROW
			|| col < 0 || col >= MAX_COL) {
			printf("����������겻�Ϸ������������룡\n");
			continue;
		}
		if (chess_board[row][col] != ' ') {
			printf("��Ҫ���ӵ�λ���Ѿ���ռ���ˣ����������룡\n");
			continue;
		}
		chess_board[row][col] = 'x';
		break;
	}
	printf("���������ϣ�\n");
}
//����������˷���1�����򷵻�0
int IsFull() {
	for (int row = 0; row < Max_ROW; ++row) {
		for (int col = 0; col < MAX_COL; ++col) {
			if (chess_board[row][col] == ' ') {
				//δ��
				return 0;
			}
		}
	}
	return 1;
}
//����ֵ��ʾʤ������˭
//x��ʾ���ʤ
//o��ʾ����ʤ
//q��ʾ����
//�� ����ʾδ�ֳ�ʤ��
char CheckWinner() {
	for (int row = 0; row < Max_ROW; ++row) {
		for (int col = 0; col < (MAX_COL - 4); ++col) {
			if (chess_board[row][col] == chess_board[row][col + 1] &&     //�ж�ͬ���Ƿ����������ӵ����
				chess_board[row][col] == chess_board[row][col + 2] &&
				chess_board[row][col] == chess_board[row][col + 3] &&
				chess_board[row][col] == chess_board[row][col + 4] && (chess_board[row][col] != ' ')) {
				return chess_board[row][col];
			}
		}
	}
	for (int row = 0; row < (Max_ROW - 4); ++row) {
		for (int col = 0; col < MAX_COL; ++col) {
			if (chess_board[row][col] == chess_board[row + 1][col] &&  //�ж�ͬ���Ƿ����������ӵ����
				chess_board[row][col] == chess_board[row + 2][col] &&
				chess_board[row][col] == chess_board[row + 3][col] &&
				chess_board[row][col] == chess_board[row + 4][col] && (chess_board[row][col] != ' ')) {
				return chess_board[row][col];
			}
		}
	}
	for (int row = 0; row < (Max_ROW - 4); ++row) {
		for (int col = 0; col < (MAX_COL - 4); ++col) {
			if (chess_board[row][col] == chess_board[row + 1][col + 1] &&  //�ж����ҶԽ����Ƿ����������ӵ����
				chess_board[row][col] == chess_board[row + 2][col + 2] &&
				chess_board[row][col] == chess_board[row + 3][col + 3] &&
				chess_board[row][col] == chess_board[row + 4][col + 4] && (chess_board[row][col] != ' ')) {
				return chess_board[row][col];
			}
		}
	}
	for (int row = 0; row < (Max_ROW - 4); ++row) {
		for (int col = 0; col < (MAX_COL - 4); ++col) {
			if (chess_board[row][col + 4] == chess_board[row + 1][col + 3] &&  //�ж�����Խ����Ƿ����������ӵ����
				chess_board[row][col + 4] == chess_board[row + 2][col + 2] &&
				chess_board[row][col + 4] == chess_board[row + 3][col + 1] &&
				chess_board[row][col + 4] == chess_board[row + 4][col] && (chess_board[row][col + 4] != ' ')) {
				return chess_board[row][col + 4];
			}
		}
	}
	//����������δ�ֳ�ʤ��
	if (IsFull()) {
		return 'q';
	}
	return ' ';
}

void ComputerMove() {
	printf("��������\n");
	while (1) {
		int row = rand() % 10;
		int col = rand() % 10;
		if (chess_board[row][col] != ' ') {
			continue;
		}
		chess_board[row][col] = 'o';
		break;
	}
	printf("����������ϣ�\n");
}
void Game() {
	//1.��ʼ������
	Init();
	char winner = ' ';
	while (1) {
		//2.��ӡ����
		Print();
		//3.�������
		PlayerMove();
		//4.���ʤ��
		winner = CheckWinner();
		if (winner != ' ') {
			break;
		}
		//5.��������
		ComputerMove();
		//6.���ʤ��
		winner = CheckWinner();
		if (winner != ' ') {
			break;
		}
	}
	Print();
	if (winner == 'x') {
		printf("��ϲ��ʤ���ˣ�\n");
	}
	else if (winner == 'o') {
		printf("����ȡ��ʤ���������ˣ�\n");
	}
	else if (winner == 'q') {
		printf("ƽ�֣����ٽ�������\n");
	}
	else {
		printf("����������\n");
	}
}
int main() {
	while (1) {
		int choice = Menu();
		if (choice == 1) {
			Game();
		}
		else if (choice == 0) {
			printf("goodbye\n");
			break;
		}
		else {
			printf("������������������0��1\n");
		}
	}
	system("pause");
	return 0;

}