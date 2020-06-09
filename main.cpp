#include <iostream>
#include <fstream>

#include "Registro.h"

	/*
	FUENTE:
	http://www.programacionenc.net/index.php?option=com_content&view=article&id=69:manejo-de-archivos-en-c&catid=37:programacion-cc&Itemid=55

	* ios::app Operaciones de añadidura.
	* ios::ate Coloca el apuntador del archivo al final del mismo.
	* ios::in Operaciones de lectura. Esta es la opción por defecto para objetos de la clase ifstream.
	* ios::out Operaciones de escritura. Esta es la opción por defecto para objetos de la clase ofstream.
	* ios::nocreate Si el archivo no existe se suspende la operación.
	* ios::noreplace Crea un archivo, si existe uno con el mismo nombre la operación se suspende.
	* ios::trunc Crea un archivo, si existe uno con el mismo nombre lo borra.
	* ios::binary Operaciones binarias.
	*/

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


using namespace std;

int main(int argc, char** argv) {
	
	ofstream Escritura;
	ifstream Lectura;
	
	Registro reg;
	//reg.archivoTxt();
	
	int op;
	
	do
	{
		system("cls");
		cout<<"\n\n\t\t\t\t******* REGISTRO ESTUDIANTIL *******"<<endl;
		cout<<"\t\t\t\t*  1. Insertar Registro            *"<<endl;
		cout<<"\t\t\t\t*  2. Eliminar Registro            *"<<endl;
		cout<<"\t\t\t\t*  3. Modificar Registro           *"<<endl;
		cout<<"\t\t\t\t*  4. Consulta x Id                *"<<endl;
		cout<<"\t\t\t\t*  5. Consulta General             *"<<endl;
		cout<<"\t\t\t\t*  6. Salir de Registro            *"<<endl;
		cout<<"\t\t\t\t------ ------ -- -- -- ------ ------"<<endl<<endl;
		cout<<"\t\t\t\tDigite su opcion: "; cin>>op;
		
		
		switch(op)
		{
			case 1:
				reg.insertar(Escritura);
				break;
			case 2:
				reg.eliminar(Lectura);
				break;
			case 3:
				reg.modificar(Lectura);
				break;
			case 4:
				reg.consultaxId(Lectura);
				break;
			case 5:
				reg.consultaGeneral(Lectura);
				break;
		}
	}while(op != 6);
	
	return 0;
}
