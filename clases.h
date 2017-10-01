
#include <iostream>
#include <fstream>

using namespace std;

//Struct de Objetos

typedef struct
{
		int w_; //peso del objeto
		int v_; //valor del objeto
}objeto;	
		
//CLASE MOCHILA
class mochila
{
	private:
		int pm_; //peso maximo soportado por la mochila
		int n_; //numero de objetos
		objeto* obj_; //puntero a la clase objeto
	public:
		mochila();
		~mochila();
		void read();
		int resultado();
};