#include <iostream>
#include <fstream>

#include "Registro.h"

using namespace std;

		void Registro :: setId(string Idx){
			Id = Idx;
		}
		void Registro :: setNombre(string Nombrex){
			Nombre = Nombrex;
		}
		void Registro :: setApellido(string Apellidox){
			Apellido = Apellidox;
		}
		void Registro :: setNota1(double Notax1){
			Nota1 = Notax1;
		}
		void Registro :: setNota2(double Notax2){
			Nota2 = Notax2;
		}
		
		string Registro :: getId(){
			return Id;
		}
		string Registro :: getNombre(){
			return Nombre;
		}
		string Registro :: getApellido(){
			return Apellido;
		}
		double Registro :: getNota1(){
			return Nota1;
		}
		double Registro :: getNota2(){
			return Nota2;
		}

	void Registro :: archivoTxt(){
		ofstream escritura("dataBase.txt", ios::out | ios::in);
		escritura<<"ID\tNOMBRE\tAPELLIDO\t\tNOTA 1\tNOTA 2\n";
	}
	
	void Registro :: insertar(ofstream &escritura){
		system("cls");
		
		escritura.open("dataBase.txt", ios::out | ios::app);
		cout<<"** INGRESE DATOS A REGISTRAR **"<<endl;
		cout<<"* Id: "; cin>>Id;
		cout<<"* Nombre: "; cin>>Nombre;
		cout<<"* Apellido: "; cin>>Apellido;
		cout<<"* Nota 1: "; cin>>Nota1;
		cout<<"* Nota 2: "; cin>>Nota2;
		
		cout<<"** Registro Guardados con Exito\n";
		system("pause");
		
		
		escritura<<Id<<"\t"<<Nombre<<"\t"<<Apellido<<"\t"<<Nota1<<"\t"<<Nota2<<"\n";
		escritura.close();
	}
	
	void Registro :: eliminar(ifstream &lectura){
		system("cls");
		
		string Id1;
		
		lectura.open("dataBase.txt", ios::in);
		ofstream aux("dataAuxi.txt", ios::out);
		if(lectura.is_open())
		{
			cout<<"\n\t* Digite Id para eliminar registro: ";cin>>Id1;
			lectura>>Id;
			while(!lectura.eof())
			{
				lectura>>Nombre;
				lectura>>Apellido;
				lectura>>Nota1;
				lectura>>Nota2;
				if(Id == Id1)
				{
					cout<<"\n\tRegistro Eliminado con Exito"<<endl;
					system("pause");
				}
				else
				{
					aux<<Id<<" "<<Nombre<<" "<<Apellido<<" "<<Nota1<<" "<<Nota2<<"\n";
					/*cout<<"\t\tRegistro no encontrado"<<endl;
					system("pause");*/
				}
				lectura>>Id;
			}
			lectura.close();
			aux.close();
		}
		else
			cout<<"Error"<<endl;
		remove("dataBase.txt");
		rename("dataAuxi.txt", "database.txt");
	}

	void Registro :: modificar(ifstream &lectura){
		system("cls");
		
		string Id1;
		double Not1;
		double Not2;
		
		lectura.open("dataBase.txt", ios::in);
		ofstream aux("dataAuxi.txt", ios::out);
		if(lectura.is_open())
		{
			cout<<"\n\t* Digite Id para modificar registro: ";cin>>Id1;
			lectura>>Id;
			while(!lectura.eof())
			{
				lectura>>Nombre;
				lectura>>Apellido;
				lectura>>Nota1;
				lectura>>Nota2;
				if(Id == Id1)
				{
					cout<<"\n\t\tDigite nueva nota 1: "; cin>>Not1;
					cout<<"\t\tDigite nueva nota 2: "; cin>>Not2;
					
					aux<<Id<<" "<<Nombre<<" "<<Apellido<<" "<<Not1<<" "<<Not2<<"\n";
					cout<<"\n\t\tRegistros Modificados con Exito"<<endl;
					system("pause");
				}
				else
				{
					aux<<Id<<" "<<Nombre<<" "<<Apellido<<" "<<Nota1<<" "<<Nota2<<"\n";
					/*cout<<"\t\tRegistro no encontrado"<<endl;
					system("pause");*/
				}
				lectura>>Nombre;
			}
			lectura.close();
			aux.close();
		}
		else
			cout<<"Error"<<endl;
		remove("dataBase.txt");
		rename("dataAuxi.txt", "database.txt");
			
	}
	
	void Registro :: consultaxId(ifstream &lectura){
		system("cls");
		lectura.open("dataBase.txt", ios::in);
		
		string Id2;
		bool encontrado = false;
		
		cout<<"\n\t* Digite Id para buscar registro: "; cin>>Id2;
		
		lectura>>Id;
		
		while(!lectura.eof() && !encontrado)
		{
			lectura>>Nombre;
			lectura>>Apellido;
			lectura>>Nota1;
			lectura>>Nota2;
			if(Id == Id2)
			{
				cout<<"\t* Id: "<<Id<<endl;
				cout<<"\t* Nombre: "<<Nombre<<endl;
				cout<<"\t* Apellido: "<<Apellido<<endl;
				cout<<"\t* Nota 1: "<<Nota1<<endl;
				cout<<"\t*Nota 2: "<<Nota2<<endl<<endl;
				cout<<"\t***** ***** ***** *****"<<endl<<endl;
				
				encontrado = true;
			}
			lectura>> Id;
		}
		lectura.close();
		
		if(!encontrado)
			cout<<"\n\t\tDato no encontrado"<<endl;
		system("pause");
	}
	
	void Registro :: consultaGeneral(ifstream &lectura){
		
		system("cls");
		lectura.open("dataBase.txt", ios::in);
		cout<<"*** Registro de Estudiantes ***"<<endl<<endl;
		
		lectura>>Id;
		while(!lectura.eof())
		{
			lectura>>Nombre;
			lectura>>Apellido;
			lectura>>Nota1;
			lectura>>Nota2;
			
			cout<<"* Id: " <<Id<<endl;
			cout<<"* Nombre: " <<Nombre<<endl;
			cout<<"* Apellido: " <<Apellido<<endl;
			cout<<"* Nota 1: " <<Nota1<<endl;
			cout<<"* Nota 2: " <<Nota2<<endl<<endl;;
			cout<<"***** ***** ***** *****"<<endl<<endl;
			
			lectura>>Id;
		}
		lectura.close();
		system("pause");
	}
