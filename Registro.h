#include <iostream>
#include <fstream>

using namespace std;

class Registro
{
	private:
		string Id;
		string Nombre;
		string Apellido;
		double Nota1;
		double Nota2;
		
		string Id2;
		double Not1;
		double Not2;
		
	public:
		
		void setId(string Id);
		void setNombre(string Nombre);
		void setApellido(string Apellido);
		void setNota1(double Nota1);
		void setNota2(double Nota2);
		
		void setId2(string Id2);
		void setNot1(double Not1);
		void setNot2(double Not2);
		
		string getId();
		string getNombre();
		string getApellido();
		double getNota1();
		double getNota2();
		
		string getId2();
		double getNot1();
		double getNot2();
		
		void archivoTxt();
		void insertar(ofstream &escr);
		void eliminar(ifstream &lect);
		void modificar(ifstream &lect);
		void consultaxId(ifstream &lect);
		void consultaGeneral(ifstream &lect);
};

