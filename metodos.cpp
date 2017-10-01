
#include "clases.h"


//////////////////////////////////////METODOS CLASE MOCHILA

//Constructor
mochila::mochila()
{
	pm_ = 0;
	n_ = 0;
	obj_ = NULL;
}

//Destructor
mochila::~mochila()
{
	pm_ = 0;
	n_ = 0;
	if (obj_ != NULL)
	{
		delete [] obj_;
	}
	obj_ = NULL;
}

//Read
void mochila::read()
{
	ifstream is("datos.txt");
	is >> pm_;
	is >> n_;
	obj_ = new objeto[n_];
	for (int i = 0; i <= n_; i++)
	{
		is >> obj_[i].w_;
		is >> obj_[i].v_;
	}
	cout << endl << "Almacenamiento : " << endl << endl;
	cout << "Peso Maximo de la mochila: " << pm_ << endl;
	cout << "Listado de objetos: " << endl;
	for(int i = 0; i < n_;i++)
	{
		cout << " objeto n: " << i + 1 << endl;
		cout << " peso : " << obj_[i].w_ << endl;
		cout << " valor: " << obj_[i].v_ << endl << endl;
	}
}

//Resultado
int mochila::resultado()
{
     int *a = new int[pm_];
     int *b = new int[pm_];
     int aux = 0;
     int retornar = 0;

     for (int i = 0; i <= pm_; i++)
     {
          a[i] = 0;
          b[i] = -1;
     }
	 
     for (int i = 1; i <= pm_; i++)
          for (int j = 0; j < n_; j++)
               if ((obj_[j].w_ <= i) && (a[i] < a[i - obj_[j].w_] + obj_[j].v_))
	       {
                    a[i] = a[i - obj_[j].w_] + obj_[j].v_;
                    b[i] = j;
               }

     aux = pm_;
    /* while ((aux > 0) && (b[aux] != -1))
     {
          cout << "Se agrego " << b[aux] + 1 << " (Valor: "<<obj_[b[aux]].v_ << " , Peso: " << obj_[b[aux]].w_ << " Espacio disponible: " << aux - obj_[b[aux]].w_ << endl;
          aux -= obj_[b[aux]].w_;
     }*/
     retornar = a[pm_];
     //delete [] b;
     //delete [] a;
     return retornar;
}


