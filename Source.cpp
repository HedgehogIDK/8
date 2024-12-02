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

	cout << "Введите кол-во объектов: ";
	cin >> size;

	cin.ignore();

	mas = new Reservoir[size];

	for (int i = 0; i < size; i++)
	{
		cout << "Введите название : ";
		gets_s(buffer, SIZE);
		cout << "\nВведите ширину : ";
		cin >> width;
		cout << "Введите длину: ";
		cin >> length;
		cout << "Введите максимальную глубину: ";
		cin >> depth_max;

		cin.ignore();

		mas[i].set_Name(buffer);
		mas[i].set_depth_max(depth_max);
		mas[i].set_length(length);
		mas[i].set_width(width);
	}

	do
	{
		cout << "\n1 - Проверка на совпадения названий\n2 - Oбъем\n3 - Проверка на совпадения площадей\n4 - Добавить объект\n5 - Удалить объект\n6 - Записать в файл\n0 - Выход\n    Введите: ";
		cin >> menu;
		
		switch (menu)
		{
		case EXIT:
			break;

		case CHECK_NAME:
			cout << "Введите номер 1 и 2 объекта: ";
			cin >> number_First >> number_Secand;

			if (mas[number_First - 1].check_Name(mas[number_Secand - 1].get_Name())) {
				cout << "Да, они совпадают\n";
			}
			else {
				cout << "Нет, они не совпадают\n";
			}

			break;

		case VOLUME:
			cout << "Введите объект: ";
			cin >> volume_Num;

			cout << mas[volume_Num].Volume();

			break;

		case CHECK_SQUARE:
			cout << "Введите номер 1 и 2 объекта: ";
			cin >> number_First >> number_Secand;

			if (mas[number_First - 1].check_Square(mas[number_Secand - 1].Square())) {
				cout << "Да, они совпадают\n";
			}
			else {
				cout << "Нет, они не совпадают\n";
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

	cout << "Введите название : ";
	gets_s(buffer, SIZE);
	cout << "\nВведите ширину : ";
	cin >> width;
	cout << "Введите длину: ";
	cin >> length;
	cout << "Введите максимальную глубину: ";
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
		cout << "Ошибка открытия файла\n";

		return;
	}

	for (int i = 0; i < size; i++) {

		fprintf(file, "%d %d %d %d %d ", mas[i].get_depth_max(), mas[i].get_length(), mas[i].get_width(), mas[i].Square(), mas[i].Volume());
		
		if (fputs(mas[i].get_Name(), file) == EOF) {
			cout << "Ошибка записи в файл\n";

			fclose(file);

			return;
		}
		fputs("\n", file);
	}

	if (fclose(file) == EOF) {
		cout << "\nФайл не закрыт\n";
	}
	else {
		cout << "\nФайл закрыт успешно\n";
	}

}