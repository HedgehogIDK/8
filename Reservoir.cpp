#include "Reservoir.h"

void Reservoir::set_Name(const char* Name_p) {
	if (!Name)
		delete[]Name;

	Name = new char[strlen(Name_p) + 1];
	strcpy_s(Name, strlen(Name_p) + 1, Name_p);
}

Reservoir::Reservoir(int width_p, int length_p, int depth_max_p, const char* Name_p) :width{ width_p }, length{ length_p }, depth_max{ depth_max_p } {
	if (Name_p) {
		Name = new char[strlen(Name_p) + 1];
		strcpy_s(Name, strlen(Name_p) + 1, Name_p);
	}
}

Reservoir::Reservoir(Reservoir& obj) {
	if (!Name)
		delete[]Name;

	Name = new char[strlen(obj.Name) + 1];
	strcpy_s(Name, strlen(obj.Name) + 1, obj.Name);

	width = obj.width;
	length = obj.length;
	depth_max = obj.depth_max;
}