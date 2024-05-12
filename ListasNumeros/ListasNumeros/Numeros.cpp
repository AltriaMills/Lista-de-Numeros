#include<iostream>
using namespace std;

int Menu();
int Primo(int);
void solicitarNum();
void Reportes();

typedef struct Numeros {
	int numerop;
	struct Numeros* sig;
	struct Numeros* ant;
};

Numeros* Trabajo = NULL, * Inicio = NULL, * Final = NULL;


int main() {
	int op = 0;
	do {
		op = Menu();
		switch (op)
		{
		case 1: {solicitarNum(); break; }
		}
	} while (op != 2);

}


int Menu() {
	int op = 0;
	do {
		system("cls");
		cout << "\n\t\a Opciones";
		cout << "\n\t 1. Solicitar numero \n\t 2. Salir";
		cin >> op;
	} while (op < 1 || op>2);
	return op;
}

int Primo(int num) {
	int r=0;
	int veces = 0;
	for (int x = 1; x <= num; x++) {
		r = num % x;
		if (r == 0) {
			veces++;
		}
	}
	return veces;
}

void solicitarNum() {
	int primo = 0;
	int num;
	char op = 's';
	do {
		system("cls");
		cout << "\n\t\a Solicitar Numero";
		cout << "\n\t Ingrese un numero: "; cin >> num;
		if (Inicio != NULL) {
			Trabajo = Inicio;
			while (Trabajo != NULL) {
				Trabajo = Trabajo->sig;
					free(Inicio);
					Inicio = Trabajo;
			}
			Inicio = NULL;
			Trabajo = NULL;
			Final = NULL;
		}
		for (int x = 0; x < 15; x++) {
			primo = Primo(num);
			if (primo <= 2) {
				Trabajo = (Numeros*)malloc(sizeof(Numeros));
				Trabajo->numerop = num;
				Trabajo->ant = NULL;
				Trabajo->sig = NULL;
				if (Inicio == NULL) {
					Inicio = Trabajo;
				}
				else {
					Final->sig = Trabajo;
					Trabajo->ant = Final;
				}
				Final = Trabajo;
			}
			else {
				x--;
			}
			num++;
			primo = 0;
		}
		Reportes();
		
		cout << "\n\t\a Desea otro reporte? s/n"; cin >> op;

	} while (op == 's');

}


void Reportes() {
	char op = 's';
	double total = 0;

		system("cls");
		cout << "\n\t\t Reportes";
		Trabajo = Final;
		while (Trabajo != NULL) {
			total = total + Trabajo->numerop;
			cout << "\n\t" << Trabajo->numerop;
			Trabajo = Trabajo->ant;
		}
		cout << endl;
		cout << "\n\t\aTotal es: " << total;
	
}
