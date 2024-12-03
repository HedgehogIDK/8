#include <iostream>
#include "Reservoir.h"
#define SIZE 200

using namespace std;

void add(Reservoir*& mas, int& size);
void del(Reservoir*& mas, int& size);
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

	cout << "Ââåäèòå êîë-âî îáúåêòîâ: ";
	cin >> size;

	cin.ignore();

	mas = new Reservoir[size];

	for (int i = 0; i < size; i++)
	{
		cout << "Ââåäèòå íàçâàíèå : ";
		gets_s(buffer, SIZE);
		cout << "\nÂâåäèòå øèðèíó : ";
		cin >> width;
		cout << "Ââåäèòå äëèíó: ";
		cin >> length;
		cout << "Ââåäèòå ìàêñèìàëüíóþ ãëóáèíó: ";
		cin >> depth_max;

		cin.ignore();

		mas[i].set_Name(buffer);
		mas[i].set_depth_max(depth_max);
		mas[i].set_length(length);
		mas[i].set_width(width);
	}

	do
	{
		cout << "\n1 - Ïðîâåðêà íà ñîâïàäåíèÿ íàçâàíèé\n2 - Oáúåì\n3 - Ïðîâåðêà íà ñîâïàäåíèÿ ïëîùàäåé\n4 - Äîáàâèòü îáúåêò\n5 - Óäàëèòü îáúåêò\n6 - Çàïèñàòü â ôàéë\n0 - Âûõîä\n    Ââåäèòå: ";
		cin >> menu;
		
		switch (menu)
		{
		case EXIT:
			break;

		case CHECK_NAME:
			cout << "Ââåäèòå íîìåð 1 è 2 îáúåêòà: ";
			cin >> number_First >> number_Secand;

			if (mas[number_First - 1].check_Name(mas[number_Secand - 1].get_Name())) {
				cout << "Äà, îíè ñîâïàäàþò\n";
			}
			else {
				cout << "Íåò, îíè íå ñîâïàäàþò\n";
			}

			break;

		case VOLUME:
			cout << "Ââåäèòå îáúåêò: ";
			cin >> volume_Num;

			cout << mas[volume_Num].Volume();

			break;

		case CHECK_SQUARE:
			cout << "Ââåäèòå íîìåð 1 è 2 îáúåêòà: ";
			cin >> number_First >> number_Secand;

			if (mas[number_First - 1].check_Square(mas[number_Secand - 1].Square())) {
				cout << "Äà, îíè ñîâïàäàþò\n";
			}
			else {
				cout << "Íåò, îíè íå ñîâïàäàþò\n";
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

void add(Reservoir*& mas, int& size) {
	Reservoir* mas_p = new Reservoir[size + 1];
	char buffer[SIZE];
	int width, length, depth_max;

	for (int i = 0;i < size;i++) {
		mas_p[i] = mas[i];
	}

	cout << "Ââåäèòå íàçâàíèå : ";
	gets_s(buffer, SIZE);
	cout << "\nÂâåäèòå øèðèíó : ";
	cin >> width;
	cout << "Ââåäèòå äëèíó: ";
	cin >> length;
	cout << "Ââåäèòå ìàêñèìàëüíóþ ãëóáèíó: ";
	cin >> depth_max;

	mas_p[size].set_Name(buffer);
	mas_p[size].set_depth_max(depth_max);
	mas_p[size].set_length(length);
	mas_p[size].set_width(width);

	delete[]mas;

	mas = mas_p;

	size++;
}

void del(Reservoir*& mas, int& size) {
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
		cout << "Îøèáêà îòêðûòèÿ ôàéëà\n";

		return;
	}

	for (int i = 0; i < size; i++) {

		fprintf(file, "%d %d %d %d %d ", mas[i].get_depth_max(), mas[i].get_length(), mas[i].get_width(), mas[i].Square(), mas[i].Volume());
		
		if (fputs(mas[i].get_Name(), file) == EOF) {
			cout << "Îøèáêà çàïèñè â ôàéë\n";

			fclose(file);

			return;
		}
		fputs("\n", file);
	}

	if (fclose(file) == EOF) {
		cout << "\nÔàéë íå çàêðûò\n";
	}
	else {
		cout << "\nÔàéë çàêðûò óñïåøíî\n";
	}

}