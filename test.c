#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Menu() {
	printf("***********************\n");
	printf("      五子棋游戏       \n");
	printf(" 1.开始游戏 0.结束游戏 \n");
	printf("***********************\n");
	printf("   请输入您的选择：    \n");
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
void Print() {//打印棋盘
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
	printf("玩家落子！\n");
	while (1) {
		printf("请输入落子位置的坐标（row，col):");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= Max_ROW
			|| col < 0 || col >= MAX_COL) {
			printf("您输入的坐标不合法，请重新输入！\n");
			continue;
		}
		if (chess_board[row][col] != ' ') {
			printf("您要落子的位置已经被占用了，请重新输入！\n");
			continue;
		}
		chess_board[row][col] = 'x';
		break;
	}
	printf("玩家落子完毕！\n");
}
//如果棋盘满了返回1，否则返回0
int IsFull() {
	for (int row = 0; row < Max_ROW; ++row) {
		for (int col = 0; col < MAX_COL; ++col) {
			if (chess_board[row][col] == ' ') {
				//未满
				return 0;
			}
		}
	}
	return 1;
}
//返回值表示胜利者是谁
//x表示玩家胜
//o表示电脑胜
//q表示和棋
//‘ ’表示未分出胜负
char CheckWinner() {
	for (int row = 0; row < Max_ROW; ++row) {
		for (int col = 0; col < (MAX_COL - 4); ++col) {
			if (chess_board[row][col] == chess_board[row][col + 1] &&     //判断同行是否有连成五子的情况
				chess_board[row][col] == chess_board[row][col + 2] &&
				chess_board[row][col] == chess_board[row][col + 3] &&
				chess_board[row][col] == chess_board[row][col + 4] && (chess_board[row][col] != ' ')) {
				return chess_board[row][col];
			}
		}
	}
	for (int row = 0; row < (Max_ROW - 4); ++row) {
		for (int col = 0; col < MAX_COL; ++col) {
			if (chess_board[row][col] == chess_board[row + 1][col] &&  //判断同列是否有连成五子的情况
				chess_board[row][col] == chess_board[row + 2][col] &&
				chess_board[row][col] == chess_board[row + 3][col] &&
				chess_board[row][col] == chess_board[row + 4][col] && (chess_board[row][col] != ' ')) {
				return chess_board[row][col];
			}
		}
	}
	for (int row = 0; row < (Max_ROW - 4); ++row) {
		for (int col = 0; col < (MAX_COL - 4); ++col) {
			if (chess_board[row][col] == chess_board[row + 1][col + 1] &&  //判断向右对角线是否有连成五子的情况
				chess_board[row][col] == chess_board[row + 2][col + 2] &&
				chess_board[row][col] == chess_board[row + 3][col + 3] &&
				chess_board[row][col] == chess_board[row + 4][col + 4] && (chess_board[row][col] != ' ')) {
				return chess_board[row][col];
			}
		}
	}
	for (int row = 0; row < (Max_ROW - 4); ++row) {
		for (int col = 0; col < (MAX_COL - 4); ++col) {
			if (chess_board[row][col + 4] == chess_board[row + 1][col + 3] &&  //判断向左对角线是否有连成五子的情况
				chess_board[row][col + 4] == chess_board[row + 2][col + 2] &&
				chess_board[row][col + 4] == chess_board[row + 3][col + 1] &&
				chess_board[row][col + 4] == chess_board[row + 4][col] && (chess_board[row][col + 4] != ' ')) {
				return chess_board[row][col + 4];
			}
		}
	}
	//棋盘满并且未分出胜负
	if (IsFull()) {
		return 'q';
	}
	return ' ';
}

void ComputerMove() {
	printf("电脑落子\n");
	while (1) {
		int row = rand() % 10;
		int col = rand() % 10;
		if (chess_board[row][col] != ' ') {
			continue;
		}
		chess_board[row][col] = 'o';
		break;
	}
	printf("电脑落子完毕！\n");
}
void Game() {
	//1.初始化棋盘
	Init();
	char winner = ' ';
	while (1) {
		//2.打印棋盘
		Print();
		//3.玩家落子
		PlayerMove();
		//4.检测胜负
		winner = CheckWinner();
		if (winner != ' ') {
			break;
		}
		//5.电脑落子
		ComputerMove();
		//6.检测胜负
		winner = CheckWinner();
		if (winner != ' ') {
			break;
		}
	}
	Print();
	if (winner == 'x') {
		printf("恭喜您胜利了！\n");
	}
	else if (winner == 'o') {
		printf("电脑取得胜利，您输了！\n");
	}
	else if (winner == 'q') {
		printf("平局，请再接再厉！\n");
	}
	else {
		printf("出现问题了\n");
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
			printf("您的输入有误！请输入0或1\n");
		}
	}
	system("pause");
	return 0;

}