#pragma once
#include <iostream>
#include <variant>

/*
template <typename T>
struct PrinterPracownikow{

    void operator()(const T& prac){ prac.id(); }
    void operator()(Inzynier inz) { inz.id(); }
    void operator()(Robotnik rob) { rob.id(); }
    void operator()(Marketer mar) { mar.id(); }
};*/





class Pracownik{
public:
    Pracownik(std::string imie, double cash) : name{ imie }, zarobki{cash} {}
    virtual ~Pracownik(){}
    std::string get_Name() const { return name; }
    double get_zarobki() const { return zarobki;  }
    virtual void id() { std::cout << "Pracownik o imieniu: " << get_Name() << std::endl; }
private:
    std::string name;
    double zarobki;
};
class Magazynier : public Pracownik {
public:
    Magazynier(std::string imie, bool jezdzi) : Pracownik(imie, 0.3), wozek(jezdzi) { Cmag = 1; }
    virtual ~Magazynier(){}
    void id() override { std::cout << "Magazynier o imieniu: " << get_Name() << " Czy umie jezdzic wozkiem: " << get_wozek() << " Pensja: " << get_zarobki() << std::endl;  }
    bool get_wozek() const { return wozek;  }
    
    
private:
    double Cmag;
    bool wozek;
};
class Robotnik : public Pracownik {
public:
    Robotnik(std::string imie, double rozmiar_buta) : Pracownik(imie, 0.1), rozmiar(rozmiar_buta) { CR = 1; }
    virtual ~Robotnik(){}
    void   id()override { std::cout << "Robotnik o imieniu: " << get_Name() << " Rozmiar buta : " << get_rozmiar() << " Pensja: " << get_zarobki() << std::endl; }
    double get_rozmiar() const { return rozmiar;  }
    

private:
    double CR;
    double rozmiar;
};
class Marketer : public Pracownik {
public:
    Marketer(std::string imie, int liczba_obserwujacych) : Pracownik(imie, 0.5), obserwujacy(liczba_obserwujacych) { CMar = 1;  }
    virtual ~Marketer(){}
    void id() override { std::cout << "Marketer o imieniu: " << get_Name() << " Liczba obserwujacych : " << get_liczba()<< " Pensja: " << get_zarobki() << std::endl; }
    int get_liczba() const { return obserwujacy;  }
   
   
private:
    double CMar;
    int obserwujacy;
};
class Inzynier : public Pracownik {
    public:
        Inzynier(std::string imie, std::string nazwa_wydzialu) : Pracownik(imie, 0.7), wydzial(nazwa_wydzialu) { CI = 1; };
        virtual ~Inzynier(){}
        void   id()override { std::cout << "Inzynier o imieniu: " << get_Name() << " Skonczony wydzial : " << get_wydzial() << " Pensja: " << get_zarobki() << std::endl; }
        std::string get_wydzial() const { return wydzial; }
        
       
    private:
        double CI;
        std::string wydzial; 

};


