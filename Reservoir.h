#pragma once
#include <iostream>

using namespace std;

class Reservoir
{
	char* Name;
	int width, length, depth_max;

public:
	//Конструкторы
	Reservoir() :Reservoir(1, 1, 1, nullptr) {}
	explicit Reservoir(int width_p):Reservoir(width_p, 1, 1, nullptr){}
	 Reservoir(int width_p, int length_p) :Reservoir(width_p, length_p, 1, nullptr) {}
	 Reservoir(int width_p, int length_p, int depth_max_p) :Reservoir(width_p, length_p, depth_max_p, nullptr) {}
	 Reservoir(int width_p, int length_p, int depth_max_p, const char* Name_p);

	 //Конструктор копирования 
	 Reservoir(Reservoir& obj);

	 //Методы
	auto Volume() { return width * length * depth_max; }
	
	bool check_Name(const char* Name_p) { return strcmp(Name_p, Name) == 0; }
	bool check_Square(int square_p) { return Square() == square_p; }\

	void set_Name(const char* Name_p);
	void set_width(int width_p) { width = width_p; }
	void set_length(int length_p) { length = length_p; }
	void set_depth_max(int depth_max_p) { depth_max = depth_max_p; }
	const char* get_Name() const { return Name; }
	
	int Square() { return width * length; }
	int get_width() { return width; }
	int get_length() { return length; }
	int get_depth_max() { return depth_max; }
	

	~Reservoir() { delete[]Name; }
};

