
#include <ctime>
using namespace std;
#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
class Fecha{
public:
  Fecha(); // se cree con la fecha actual
  Fecha(int day, int month, int year);

  int getYear() ;
  void setYear(int year);
  int getMonth() ;
  void setMonth(int month);
  int getDay() ;
  void setDay(int day);
  bool esFechaValida();
  //Revisar sobrecargas de comparaciones
bool operator<(const Fecha& otraFecha) const {
    if (_year < otraFecha._year)
        return true;
    if (_year == otraFecha._year && _month < otraFecha._month)
        return true;
    if (_year == otraFecha._year && _month == otraFecha._month && _day < otraFecha._day)
        return true;
    return false;
}

bool operator>(const Fecha& otraFecha) const {
    return otraFecha < *this;
}

bool operator<=(const Fecha& otraFecha) const {
    return !(*this > otraFecha);
}

bool operator>=(const Fecha& otraFecha) const {
    return !(*this < otraFecha);
}

bool operator==(const Fecha& otraFecha) const {
    return _year == otraFecha._year && _month == otraFecha._month && _day == otraFecha._day;
}

bool operator!=(const Fecha& otraFecha) const {
    return !(*this == otraFecha);
}
private:
  int _year;
  int _month;
  int _day;
};

Fecha::Fecha()
{
  time_t tiempo = time(nullptr);
  tm* fecha = localtime(&tiempo);

  setDay(fecha->tm_mday);
  setMonth(fecha->tm_mon + 1);
  setYear(fecha->tm_year + 1900);
}

Fecha::Fecha(int day, int month, int year)
  : _day(0), _month(0), _year(0)
{
  setDay(day);
  setMonth(month);
  setYear(year);
}

int Fecha::getYear() 
{
  return _year;
}

void Fecha::setYear( int year)
{
  if(year >= 1)
  {
    _year = year;
  }
}

int Fecha::getMonth() {
  return _month;
}

void Fecha::setMonth(int month)
{
  if(month >= 1 && month <= 12)
  {
    _month = month;
  }
}

int Fecha::getDay(){
  return _day;
}

void Fecha::setDay(int day)
{
  if(day >= 1 && day <= 31)
  {
    _day = day;
  }
}

bool Fecha::esFechaValida()
{
    if (_year < 1 || _month < 1 || _month > 12 || _day < 1)
    {
        return false;
    }

    int diasEnMes = 31; // Por defecto, se asumen 31 días

    if (_month == 4 || _month == 6 || _month == 9 || _month == 11)
    {
        diasEnMes = 30; // Abril, junio, septiembre, noviembre tienen 30 días
    }
    else if (_month == 2)
    {
        // Febrero tiene 28 o 29 días dependiendo si es un año bisiesto
        if ((_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0))
        {
            diasEnMes = 29; // Año bisiesto
        }
        else
        {
            diasEnMes = 28; // Año no bisiesto
        }
    }

    if (_day > diasEnMes)
    {
        return false;
    }

    return true;
}


#endif // FECHA_H_INCLUDED