
#include "metodos.cpp"

int main()
{
	mochila A;

	A.read();
	cout << "Valor total: " << A.resultado() << endl;
	return 0;
}