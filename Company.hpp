#pragma once
#include <iostream>
#include <vector>
#include <variant>
#include "Employees.hpp"
#include "Kredyt.hpp"

class company{
	public:
		company() : stan_konta{ 10 }, n_prac{ 0 }, n_kredytow{ 0 }, n_inz{ 0 }, n_mag{ 0 }, n_mar{ 0 }, n_rob{ 0 } { }
		~company(){}
		void drukuj_pracownikow() const { for (Pracownik* x : tablica_pracownikow) x->id(); }
		void zaplac_wynagrodzenie() { for (Pracownik* x : tablica_pracownikow) stan_konta = stan_konta - x->get_zarobki();  }
		void otrzymaj_przychod() {
			double Cmag = 1;
			double CI = 1;
			double Cmar = 1;
			double Cr = 1;
			double mag_capacity = n_mag * Cmag;
			double cena_produktu = n_inz * CI;
			double popyt = n_mar * Cmar;
			double teor_liczba_prod = n_rob * Cr;
			double real_prod=0;
			double real_sell=0;
			if (mag_capacity <= teor_liczba_prod)
				real_prod = mag_capacity;
			else 
				real_prod = teor_liczba_prod;
			if (popyt <= real_prod)
				 real_sell = popyt;
			else 
				double real_sell = real_prod;
			double przychod = real_sell * cena_produktu;
			historia_przychodów.emplace_back(przychod);
			stan_konta = stan_konta + przychod;
		}
		void wyswietl_historie_przychodu() { for (double x : historia_przychodów) std::cout << x << "\n"; }
		void wyswietl_kredyty() {
			for (Kredyt* x : tablica_kredytow)
				if (x->get_dlug()==0)
					std::cout << "Kredyt splacony \n";
				else
					std::cout << "Pozostaly dlug: " << x->get_dlug() << " Pozostala ilosc rat: " << x->get_pozostale_raty() << "\n";
		}
		void wez_kredyt(double kwota, int czas_splaty) {
			Kredyt* kred = new Kredyt(kwota, czas_splaty); 
			tablica_kredytow.emplace_back(kred);
			n_kredytow = n_kredytow + 1;
			stan_konta = stan_konta + kwota; 
		}
		void splac_raty() { 
			for (Kredyt* x: tablica_kredytow) {
				if (x->get_dlug() > 0) {
					double rata = x->get_dlug() / x->get_pozostale_raty();
					x->set_dlug(x->get_dlug() - rata);
					x->set_pozostale_raty(x->get_pozostale_raty() - 1);
					stan_konta = stan_konta - rata;
				}
		} 
		}
		void zatrudnij_inzyniera(Inzynier* In) { tablica_pracownikow.emplace_back(In); n_prac = n_prac + 1; n_inz = n_inz + 1; }
		void zatrudnij_marketera(Marketer* Mr) { tablica_pracownikow.emplace_back(Mr); n_prac = n_prac + 1; n_mar = n_mar + 1; }
		void zatrudnij_robotnika(Robotnik* Rb) { tablica_pracownikow.emplace_back(Rb); n_prac = n_prac + 1; n_rob = n_rob + 1; }
		void zatrudnij_magazyniera(Magazynier* Mg) { tablica_pracownikow.emplace_back(Mg); n_prac = n_prac + 1; n_mag = n_mag + 1; }
		double get_stan() const{ return stan_konta; }
		int get_n_prac()const { return n_prac;  }
		int get_n_inz()const { return n_inz; }
		int get_n_mag()const { return n_mag; }
		
	private:
		double stan_konta;
		int n_prac;
		int n_inz;
		int n_mag;
		int n_mar;
		int n_rob; 
		//using pracownik_t = std::variant<Magazynier, Robotnik, Marketer, Inzynier>;
		std::vector<Pracownik*> tablica_pracownikow;
		//std::unique_ptr<pracownik_t[]> tablica_pracownikow; 
		std::vector<double> historia_przychodów;
		std::vector<Kredyt*> tablica_kredytow;
		
		int n_kredytow;
		
};
