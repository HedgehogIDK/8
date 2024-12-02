#include <iostream>
#include "Reservoir.h"
#define SIZE 200

using namespace std;

void add(Reservoir* mas, int& size);
void del(Reservoir* mas, int& size);
void Save(Reservoir* mas, int size);

enum MENU
{
	EXIT,
	CHECK_NAME,
	VOLUME,
	CHECK_SQUARE,
	ADD,
	DEL,
	SAVE
};

int main() {
	setlocale(LC_ALL, "RUS");

	char buffer[SIZE];
	Reservoir* mas;
	int size, width, length, depth_max, menu, number_First, number_Secand, volume_Num;

	cout << "������� ���-�� ��������: ";
	cin >> size;

	cin.ignore();

	mas = new Reservoir[size];

	for (int i = 0; i < size; i++)
	{
		cout << "������� �������� : ";
		gets_s(buffer, SIZE);
		cout << "\n������� ������ : ";
		cin >> width;
		cout << "������� �����: ";
		cin >> length;
		cout << "������� ������������ �������: ";
		cin >> depth_max;

		cin.ignore();

		mas[i].set_Name(buffer);
		mas[i].set_depth_max(depth_max);
		mas[i].set_length(length);
		mas[i].set_width(width);
	}

	do
	{
		cout << "\n1 - �������� �� ���������� ��������\n2 - O����\n3 - �������� �� ���������� ��������\n4 - �������� ������\n5 - ������� ������\n6 - �������� � ����\n0 - �����\n    �������: ";
		cin >> menu;
		
		switch (menu)
		{
		case EXIT:
			break;

		case CHECK_NAME:
			cout << "������� ����� 1 � 2 �������: ";
			cin >> number_First >> number_Secand;

			if (mas[number_First - 1].check_Name(mas[number_Secand - 1].get_Name())) {
				cout << "��, ��� ���������\n";
			}
			else {
				cout << "���, ��� �� ���������\n";
			}

			break;

		case VOLUME:
			cout << "������� ������: ";
			cin >> volume_Num;

			cout << mas[volume_Num].Volume();

			break;

		case CHECK_SQUARE:
			cout << "������� ����� 1 � 2 �������: ";
			cin >> number_First >> number_Secand;

			if (mas[number_First - 1].check_Square(mas[number_Secand - 1].Square())) {
				cout << "��, ��� ���������\n";
			}
			else {
				cout << "���, ��� �� ���������\n";
			}

			break;

		case ADD:
			cin.ignore();

			add(mas, size);

			break;

		case DEL:
			cin.ignore();

			del(mas, size);

			break;

		case SAVE:
			Save(mas, size);

			break;

		default:
			break;
		}

	} while (menu);
	
	return 0;
}

void add(Reservoir* mas, int& size) {
	Reservoir* mas_p = new Reservoir[size + 1];
	char buffer[SIZE];
	int width, length, depth_max;

	for (int i = 0;i < size;i++) {
		mas_p[i] = mas[i];
	}

	cout << "������� �������� : ";
	gets_s(buffer, SIZE);
	cout << "\n������� ������ : ";
	cin >> width;
	cout << "������� �����: ";
	cin >> length;
	cout << "������� ������������ �������: ";
	cin >> depth_max;

	mas_p[size].set_Name(buffer);
	mas_p[size].set_depth_max(depth_max);
	mas_p[size].set_length(length);
	mas_p[size].set_width(width);

	delete[]mas;

	mas = mas_p;

	size++;
}

void del(Reservoir* mas, int& size) {
	Reservoir* mas_p = new Reservoir[size - 1];

	size--;

	for (int i = 0;i < size;i++) {
		mas_p[i] = mas[i];
	}

	delete[]mas;

	mas = mas_p;
}

void Save(Reservoir* mas, int size) {
	FILE* file;

	if (fopen_s(&file, "Reservoir.txt", "w") != 0) {
		cout << "������ �������� �����\n";

		return;
	}

	for (int i = 0; i < size; i++) {

		fprintf(file, "%d %d %d %d %d ", mas[i].get_depth_max(), mas[i].get_length(), mas[i].get_width(), mas[i].Square(), mas[i].Volume());
		
		if (fputs(mas[i].get_Name(), file) == EOF) {
			cout << "������ ������ � ����\n";

			fclose(file);

			return;
		}
		fputs("\n", file);
	}

	if (fclose(file) == EOF) {
		cout << "\n���� �� ������\n";
	}
	else {
		cout << "\n���� ������ �������\n";
	}

}