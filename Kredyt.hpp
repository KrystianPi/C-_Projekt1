#pragma once
#include <iostream>

class Kredyt {
public:
	
	Kredyt(double kwota, int czas_splaty) : dlug{ kwota }, pozostale_raty{ czas_splaty } {};
	~Kredyt() {};
	double get_dlug() { return dlug; }
	void set_dlug(double x) { dlug = x; }
	void set_pozostale_raty(int x) { pozostale_raty = x;  }
	int get_pozostale_raty() { return pozostale_raty;  }
private:
	double dlug;
	int pozostale_raty;
};
