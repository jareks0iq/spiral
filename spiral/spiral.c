#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
int field[12][12];
int input() {
	char xx[100];
	int flag = 0, x1 = 0;
	gets(xx);
	for (int i = 0; i < strlen(xx); i++) {
		if (isdigit(xx[i])) {
			flag = 0;
			continue;
		}
		else {
			flag = 1;
			break;
		}
	}
	if (flag == 0 && strlen(xx) <= 2 && strlen(xx) > 0) {
		sscanf_s(xx, "%d", &x1);
		if (x1 <= 11 && x1 >= 1) { return x1; }
		else { return -1; }
	}
	else { return -1; }
}
void walls(int x, int y) {
	memset(field, -1, sizeof(field));
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			field[i][j] = 0;
		}
	}
}
void printwalls(int x, int y) {
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			printf("%4d", (field[i][j]));
		}
		_putch('\n');
	}
}
void decision3(int x, int y) {
	int k = 1, deltax = 0, deltay = 0, levo = 0, niz = 0;
	while (true) {
		while (deltax < x) {
			field[deltay][deltax] = k;
			deltax++;
			k++;
		}
		niz++;
		x--;
		deltax--;
		if (((field[deltay + 1][deltax] != 0) && (field[deltay - 1][deltax] != 0) && (field[deltay][deltax + 1] != 0) && (field[deltay][deltax - 1] != 0)) || y == 1) { break; }
		if (field[deltay + 1][deltax] == 0) { deltay++; }
		while (deltay < y) {
			field[deltay][deltax] = k;
			deltay++;
			k++;
		}
		y--;
		deltay--;
		if (((field[deltay + 1][deltax] != 0) && (field[deltay - 1][deltax] != 0) && (field[deltay][deltax + 1] != 0) && (field[deltay][deltax - 1] != 0)) || x == 0) { break; }
		if (field[deltay][deltax - 1] == 0) { deltax--; }
		while (deltax >= levo) {
			field[deltay][deltax] = k;
			deltax--;
			k++;
		}
		deltax++;
		if ((field[deltay + 1][deltax] != 0) && (field[deltay - 1][deltax] != 0) && (field[deltay][deltax + 1] != 0) && (field[deltay][deltax - 1] != 0)) { break; }
		if (field[deltay - 1][deltax] == 0) { deltay--; }
		levo++;
		while (deltay >= niz) {
			field[deltay][deltax] = k;
			deltay--;
			k++;
		}
		deltay++;
		if ((field[deltay + 1][deltax] != 0) && (field[deltay - 1][deltax] != 0) && (field[deltay][deltax + 1] != 0) && (field[deltay][deltax - 1] != 0)) { break; }
		if (field[deltay][deltax + 1] == 0) { deltax++; }
	}
}
void decision4(int x, int y) {
	int k = 1, deltax = x-1, deltay = 0, levo = 0, niz = 0, prov = x * y;
	while (true) {
		while (deltax >= levo) {
			field[deltay][deltax] = k;
			deltax--;
			k++;
		}
		niz++;
		deltax++;
		if (((field[deltay + 1][deltax] != 0) && (field[deltay - 1][deltax] != 0) && (field[deltay][deltax + 1] != 0) && (field[deltay][deltax - 1] != 0)) || y == 1) { break; }
		if (field[deltay + 1][deltax] == 0) { deltay++; }
		while (deltay < y) {
			field[deltay][deltax] = k;
			deltay++;
			k++;
		}
		y--;
		deltay--;
		if (((field[deltay + 1][deltax] != 0) && (field[deltay - 1][deltax] != 0) && (field[deltay][deltax + 1] != 0) && (field[deltay][deltax - 1] != 0)) || x == 0) { break; }
		if (field[deltay][deltax + 1] == 0) { deltax++; }
		levo++;
		while (deltax < x) {
			field[deltay][deltax] = k;
			deltax++;
			k++;
		}
		x--;
		deltax--;
		if ((field[deltay + 1][deltax] != 0) && (field[deltay - 1][deltax] != 0) && (field[deltay][deltax + 1] != 0) && (field[deltay][deltax - 1] != 0)) { break; }
		if (field[deltay - 1][deltax] == 0) { deltay--; }
		while (deltay >= niz) {
			field[deltay][deltax] = k;
			deltay--;
			k++;
		}
		deltay++;
		if ((field[deltay + 1][deltax] != 0) && (field[deltay - 1][deltax] != 0) && (field[deltay][deltax + 1] != 0) && (field[deltay][deltax - 1] != 0)) { break; }
		if (field[deltay][deltax - 1] == 0) { deltax--; }
	}
}
void decision5(int x, int y) {
	int k = x * y, deltax = 0, deltay = 0, levo = 0, niz = 0, prov = x * y;
	while (true) {
		while (deltax < x) {
			field[deltay][deltax] = k;
			deltax++;
			k--;
		}
		niz++;
		x--;
		deltax--;
		if (((field[deltay + 1][deltax] != 0) && (field[deltay - 1][deltax] != 0) && (field[deltay][deltax + 1] != 0) && (field[deltay][deltax - 1] != 0)) || y == 1) { break; }
		if (field[deltay + 1][deltax] == 0) { deltay++; }
		while (deltay < y) {
			field[deltay][deltax] = k;
			deltay++;
			k--;
		}
		y--;
		deltay--;
		if (((field[deltay + 1][deltax] != 0) && (field[deltay - 1][deltax] != 0) && (field[deltay][deltax + 1] != 0) && (field[deltay][deltax - 1] != 0)) || x == 0) { break; }
		if (field[deltay][deltax - 1] == 0) { deltax--; }
		while (deltax >= levo) {
			field[deltay][deltax] = k;
			deltax--;
			k--;
		}
		deltax++;
		if ((field[deltay + 1][deltax] != 0) && (field[deltay - 1][deltax] != 0) && (field[deltay][deltax + 1] != 0) && (field[deltay][deltax - 1] != 0)) { break; }
		if (field[deltay - 1][deltax] == 0) { deltay--; }
		levo++;
		while (deltay >= niz) {
			field[deltay][deltax] = k;
			deltay--;
			k--;
		}
		deltay++;
		if ((field[deltay + 1][deltax] != 0) && (field[deltay - 1][deltax] != 0) && (field[deltay][deltax + 1] != 0) && (field[deltay][deltax - 1] != 0)) { break; }
		if (field[deltay][deltax + 1] == 0) { deltax++; }
	}
}
void decision6(int x, int y) {
	int k = x * y, deltax = x - 1, deltay = 0, levo = 0, niz = 0, prov = x * y;
	while (true) {
		while (deltax >= levo) {
			field[deltay][deltax] = k;
			deltax--;
			k--;
		}
		niz++;
		deltax++;
		if (((field[deltay + 1][deltax] != 0) && (field[deltay - 1][deltax] != 0) && (field[deltay][deltax + 1] != 0) && (field[deltay][deltax - 1] != 0)) || y == 1) { break; }
		if (field[deltay + 1][deltax] == 0) { deltay++; }
		while (deltay < y) {
			field[deltay][deltax] = k;
			deltay++;
			k--;
		}
		y--;
		deltay--;
		if (((field[deltay + 1][deltax] != 0) && (field[deltay - 1][deltax] != 0) && (field[deltay][deltax + 1] != 0) && (field[deltay][deltax - 1] != 0)) || x == 0) { break; }
		if (field[deltay][deltax + 1] == 0) { deltax++; }
		levo++;
		while (deltax < x) {
			field[deltay][deltax] = k;
			deltax++;
			k--;
		}
		x--;
		deltax--;
		if ((field[deltay + 1][deltax] != 0) && (field[deltay - 1][deltax] != 0) && (field[deltay][deltax + 1] != 0) && (field[deltay][deltax - 1] != 0)) { break; }
		if (field[deltay - 1][deltax] == 0) { deltay--; }
		while (deltay >= niz) {
			field[deltay][deltax] = k;
			deltay--;
			k--;
		}
		deltay++;
		if ((field[deltay + 1][deltax] != 0) && (field[deltay - 1][deltax] != 0) && (field[deltay][deltax + 1] != 0) && (field[deltay][deltax - 1] != 0)) { break; }
		if (field[deltay][deltax - 1] == 0) { deltax--; }
	}
}
int main() {
	setlocale(LC_ALL, "Rus");
	int ch = 0, k = 1, n = 1, m = 1;
	printf("> 1) Число N: %d\n", n);
	printf("2) Число M: %d \n", m);
	printf("3) Спираль снаружи по часовой стрелке \n");
	printf("4) Спираль снаружи против часовой стрелке \n");
	printf("5) Спираль изнутри по часовой стрелке \n");
	printf("6) Спираль изнутри против часовой стрелке \n");
	printf("7) Выход \n");
	while (true) {
		ch = getch();
		if (ch == 49 || (ch == 13 && k == 1)) {
			k = 1;
			system("cls");
			memset(field, 0, sizeof(field));
			printf("Введите число N от 1 до 11 включительно: ");
			n = input();
		}
		else if (ch == 50 || (ch == 13 && k == 2)) {
			k = 2;
			system("cls");
			memset(field, 0, sizeof(field));
			printf("Введите число M от 1 до 11 включительно: ");
			m = input();
		}
		else if (ch == 51 || (ch == 13 && k == 3)) {
			k = 3;
			int p = 0;
			while (p != 27) {
				system("cls");
				printf("Ваша спираль снаружи по часовой стрелке: \n");
				walls(n, m);
				decision3(n, m);
				printwalls(n, m);
				printf("Для выхода нажмите ESC \n");
				p = getch();
			}


		}
		else if (ch == 52 || (ch == 13 && k == 4)) {
			k = 4;
			int p = 0;
			while (p != 27) {
				system("cls");
				printf("Ваша спираль снаружи против часовой стрелки: \n");
				walls(n, m);
				decision4(n, m);
				printwalls(n, m);
				printf("Для выхода нажмите ESC \n");
				p = getch();
			}
		}
		else if (ch == 53 || (ch == 13 && k == 5)) {
			k = 5;
			int p = 0;
			while (p != 27) {
				system("cls");
				printf("Ваша спираль изнутри против часовой стрелки: \n");
				walls(n, m);
				decision5(n, m);
				printwalls(n, m);
				printf("Для выхода нажмите ESC \n");
				p = getch();
			}
		}
		else if (ch == 54 || (ch == 13 && k == 6)) {
			k = 6;
			int p = 0;
			while (p != 27) {
				system("cls");
				printf("Ваша спираль изнутри по часовой стрелки: \n");
				walls(n, m);
				decision6(n, m);
				printwalls(n, m);
				printf("Для выхода нажмите ESC \n");
				p = getch();
			}
		}
		else if (ch == 55 || (ch == 13 && k == 7)) {
			exit();
		}
		else if (ch == 80) {
			if (k == 7) { continue; }
			else { k++; }
		}
		else if (ch == 72) {
			if (k == 1) { continue; }
			else { k--; }
		}
		system("cls");
		if (k == 1) {
			if (n != -1) { printf("> 1) Число N: %d\n", n); }
			else { printf("> 1) Число N: некорректное значение\n"); }
		}
		else {
			if (n != -1) { printf("1) Число N: %d\n", n); }
			else { printf("1) Число N: некорректное значение\n"); }
		}
		if (k == 2) {
			if (m != -1) { printf("> 2) Число M: %d\n", m); }
			else { printf("> 2) Число M: некорректное значение\n"); }
		}
		else {
			if (m != -1) { printf("2) Число M: %d\n", m); }
			else { printf("2) Число M: некорректное значение\n"); }
		}
		if (k == 3) { printf("> 3) Спираль снаружи по часовой стрелке \n"); }
		else { printf("3) Спираль снаружи по часовой стрелке \n"); }
		if (k == 4) { printf("> 4) Спираль снаружи против часовой стрелке \n"); }
		else { printf("4) Спираль снаружи против часовой стрелке \n"); }
		if (k == 5) { printf("> 5) Спираль изнутри по часовой стрелке \n"); }
		else { printf("5) Спираль изнутри по часовой стрелке \n"); }
		if (k == 6) { printf("> 6) Спираль изнутри против часовой стрелке \n"); }
		else { printf("6) Спираль изнутри против часовой стрелке \n"); }
		if (k == 7) { printf("> 7) Выход \n"); }
		else { printf("7) Выход \n"); }
	}
}