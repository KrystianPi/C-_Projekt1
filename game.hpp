#pragma once
#include "Company.hpp"
#include <iostream>
#include <vector>
#include "RandomNameGenerator.hpp"



class game{
	public:
		const int limit = 20;
		game(): co(new company), state(true) {}
		~game() { delete co;  }
		bool get_state(){ return state; }
		void player_action() { 
			std::string action;
			std::cout << "Wpisz komende, mozliwe komendy:\nWyswietl stan konta: st \nWyswietl kredyty: hkred \nWyswietl historie przychodu: hist\nWyswietl ilosc pracownikow: il\nLista pracownikow : le \nWez kredyt: kre \nZatrudnij pracownika: \nInzyniera: heng\nMagazyniera: hmag\nMarketera: hmar\nRobotnika: hrob\nNastepna runda: kt\n \n";
			std::cin >> action; 
			if (action == "le")
				co->drukuj_pracownikow();
			else if (action == "heng")
				co->zatrudnij_inzyniera(new Inzynier(get_random_name() , "meil"));
			else if (action == "hmag")
				co->zatrudnij_magazyniera(new Magazynier(get_random_name(), true));
			else if (action == "hrob")
				co->zatrudnij_robotnika(new Robotnik(get_random_name(), 42));
			else if (action == "hmar")
				co->zatrudnij_marketera(new Marketer(get_random_name(), 243093));
			else if (action == "st")
				std::cout << "Stan konta: "<< co->get_stan() << "\n";
			else if (action == "il") {
				std::cout << "Ilosc pracownikow: "<< co->get_n_prac() << "\n";
			}
			else if (action == "kt") {
				co->zaplac_wynagrodzenie();
				co->otrzymaj_przychod();
				co->splac_raty();
			}
			else if (action == "kre") {
				std::cout << "Podaj kwote kredytu: \n";
				double kwota;
				std::cin >> kwota;
				std::cout << "Podaj czas splaty: \n";
				int ilosc_rat;
				std::cin >> ilosc_rat;
				co->wez_kredyt(kwota, ilosc_rat);
			}
			else if (action == "hist")
				co->wyswietl_historie_przychodu();
			else if (action == "hkred")
				co->wyswietl_kredyty();
			else if (action == "end")
			{
				state = false;
				std::cout << "Wynik koncowy:\n";
				std::cout << "Stan konta: " << co->get_stan() << "\n";
				std::cout << "Ilosc pracownikow: " << co->get_n_prac() << "\n";
			}
			else if (co->get_stan() > limit)
			{
				std::cout << "WYGRANA";
					state = false;
			}
			else
				std::cout << "Nieprawidlowa komenda\n";
			
			

		}
	private:
		company* co; 
		bool state;
};