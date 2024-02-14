#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
class StocMateriePrima
{
	char* denumireMateriePrima = nullptr;
	string unitateMasura = "anonima";
	float cantitateStoc = 0;
	static string furnizorMateriePrima;
public:
	StocMateriePrima() {}
	StocMateriePrima(const char* denumireMateriePrima) {
		if (denumireMateriePrima != nullptr)
		{
			this->denumireMateriePrima = new char[strlen(denumireMateriePrima) + 1];
			strcpy(this->denumireMateriePrima, denumireMateriePrima);
		}
	}
	StocMateriePrima(const char* denumireMateriePrima, string unitateMasura, float cantitateStoc) {

		if (denumireMateriePrima != nullptr)
		{
			this->denumireMateriePrima = new char[strlen(denumireMateriePrima) + 1];
			strcpy(this->denumireMateriePrima, denumireMateriePrima);
		}
		this->unitateMasura = unitateMasura;
		this->cantitateStoc = cantitateStoc;
	}
	StocMateriePrima(const StocMateriePrima& s)
	{
		if (s.denumireMateriePrima != nullptr)
		{
			this->denumireMateriePrima = new char[strlen(s.denumireMateriePrima) + 1];
			strcpy(this->denumireMateriePrima, s.denumireMateriePrima);
		}
		this->unitateMasura = s.unitateMasura;
		this->cantitateStoc = s.cantitateStoc;
	}
	StocMateriePrima& operator=(const StocMateriePrima& s)
	{
		if (this != &s)
		{
			delete[]this->denumireMateriePrima;
			this->denumireMateriePrima = nullptr;

			if (s.denumireMateriePrima != nullptr)
			{
				this->denumireMateriePrima = new char[strlen(s.denumireMateriePrima) + 1];
				strcpy(this->denumireMateriePrima, s.denumireMateriePrima);
			}
			this->unitateMasura = s.unitateMasura;
			this->cantitateStoc = s.cantitateStoc;
		}
		return *this;
	}
	void setDenumireMateriePrima(const char* denumireMateriePrima)
	{
		if (denumireMateriePrima != nullptr) {
			delete[]this->denumireMateriePrima;
			this->denumireMateriePrima = new char[strlen(denumireMateriePrima) + 1];
			strcpy(this->denumireMateriePrima, denumireMateriePrima);
		}
	}
	const char* getDenumireMateriePrima()
	{
		return this->denumireMateriePrima;
	}
	void setUnitateMasura(string unitateMasura)
	{
		if (unitateMasura.length() > 0)
			this->unitateMasura = unitateMasura;
	}
	string getUnitateMasura()
	{
		return this->unitateMasura;
	}
	void setCantitateStoc(float cantitateStoc)
	{
		if (cantitateStoc >= 0)
			this->cantitateStoc = cantitateStoc;
	}
	float& getCantitateStoc()
	{
		return this->cantitateStoc;
	}
	static void setFurnizorMateriePrima(string furnizor)
	{
		if (furnizor.length() > 2)
			StocMateriePrima::furnizorMateriePrima = furnizor;
	}
	static string getFurnizorMateriePrima()
	{
		return StocMateriePrima::furnizorMateriePrima;
	}
	//metode de afisare/prelucrare
	void afisareDenumire()
	{
		if (this->denumireMateriePrima != nullptr)
			cout << "\nDenumirea materiei prime: " << this->denumireMateriePrima;
		else
			cout << "-";
	}
	void adaugaStoc(int stocNou)
	{
		if (stocNou > 0)
		{
			this->cantitateStoc += stocNou;
		}
	}
	~StocMateriePrima()
	{
		delete[]this->denumireMateriePrima;
		this->denumireMateriePrima = nullptr;
	}
	friend ostream& operator<<(ostream& out, const StocMateriePrima& s)
	{
		out << "\n*********MATERIE PRIMA************";
		if (s.denumireMateriePrima != nullptr)
			out << "\nDenumire materie prima: " << s.denumireMateriePrima;
		else
			out << "\nDenumire materie prima:  -";
		out << "\nCantitate disponibila pe stoc: " << s.cantitateStoc << " " << s.unitateMasura;
		out << "\nFurnizor: " << StocMateriePrima::furnizorMateriePrima;
		out << "\n*************************";
		return out;
	}
	friend istream& operator>>(istream& in, StocMateriePrima& s)
	{
		delete[]s.denumireMateriePrima;
		s.denumireMateriePrima = nullptr;

		cout << "\nIntroduceti denumirea materiei prime: ";
		in.ignore();
		char buffer[100];
		in.getline(buffer, 100);
		s.denumireMateriePrima = new char[strlen(buffer) + 1];
		strcpy(s.denumireMateriePrima, buffer);
		cout << "\nIntroduceti unitatea de masura: "; in >> s.unitateMasura;
		cout << "\nIntroduceti cantitatea disponibila pe stoc: "; in >> s.cantitateStoc;
		return in;
	}
	explicit operator string()
	{
		return this->denumireMateriePrima;
	}
	bool operator!()
	{
		return !this->cantitateStoc;
	}
};
string StocMateriePrima::furnizorMateriePrima = "Carrefour";
class Ingredient
{
	StocMateriePrima ingredient;
	float cantitate = 0;
	int nrAlergeni = 0;
	string* alergeni = nullptr;

public:
	Ingredient()
	{}
	Ingredient(StocMateriePrima ingredient, float cantitate, int nrAlergeni, string* alergeni)
	{
		this->ingredient = ingredient;
		this->cantitate = cantitate;
		if (nrAlergeni > 0 && alergeni != nullptr)
		{
			this->nrAlergeni = nrAlergeni;
			this->alergeni = new string[this->nrAlergeni];
			for (int i = 0; i < this->nrAlergeni; i++)
				this->alergeni[i] = alergeni[i];
		}
		else
		{
			this->nrAlergeni = 0;
			this->alergeni = nullptr;
		}
	}
	Ingredient(StocMateriePrima ingredient)
	{
		this->ingredient = ingredient;
	}
	Ingredient(int nrAlergeni, string* alergeni)
	{
		if (nrAlergeni > 0 && alergeni != nullptr)
		{
			this->nrAlergeni = nrAlergeni;
			this->alergeni = new string[this->nrAlergeni];
			for (int i = 0; i < this->nrAlergeni; i++)
				this->alergeni[i] = alergeni[i];
		}
		else
		{
			this->nrAlergeni = 0;
			this->alergeni = nullptr;
		}
	}
	Ingredient(const Ingredient& i)
	{
		this->ingredient = i.ingredient;
		this->cantitate = i.cantitate;
		if (i.nrAlergeni > 0 && i.alergeni != nullptr)
		{
			this->nrAlergeni = i.nrAlergeni;
			this->alergeni = new string[this->nrAlergeni];
			for (int k = 0; k < this->nrAlergeni; k++)
				this->alergeni[k] = i.alergeni[k];
		}
		else
		{
			this->nrAlergeni = 0;
			this->alergeni = nullptr;
		}
	}
	Ingredient& operator=(const Ingredient& i) {
		if (this != &i)
		{
			delete[]this->alergeni;
			this->alergeni = nullptr;

			this->ingredient = i.ingredient;
			this->cantitate = i.cantitate;
			if (i.nrAlergeni > 0 && i.alergeni != nullptr)
			{
				this->nrAlergeni = i.nrAlergeni;
				this->alergeni = new string[this->nrAlergeni];
				for (int k = 0; k < this->nrAlergeni; k++)
					this->alergeni[k] = i.alergeni[k];
			}
			else
			{
				this->nrAlergeni = 0;
				this->alergeni = nullptr;
			}
		}
		return *this;
	}
	void setIngredient(StocMateriePrima ingredient)
	{
		if (ingredient.getDenumireMateriePrima() != nullptr)
		{
			this->ingredient = ingredient;
			this->ingredient.setCantitateStoc(ingredient.getCantitateStoc());
		}
	}
	StocMateriePrima& getIngredient()
	{
		return this->ingredient;
	}
	void setCantitateIngredient(float cantitate)
	{
		if (cantitate > 0)
			this->cantitate = cantitate;
	}
	float& getCantitateIngredient()
	{
		return this->cantitate;
	}
	void setAlergeni(int nrAlergeni, string* alergeni)
	{
		delete[]this->alergeni;
		if (nrAlergeni > 0 && alergeni != nullptr)
		{
			this->nrAlergeni = nrAlergeni;
			this->alergeni = new string[this->nrAlergeni];
			for (int i = 0; i < this->nrAlergeni; i++)
				this->alergeni[i] = alergeni[i];
		}
		else
		{
			this->nrAlergeni = 0;
			this->alergeni = nullptr;
		}
	}
	string* getAlergeni()
	{
		if (this->nrAlergeni > 0 && this->alergeni != nullptr)
			return this->alergeni;
	}
	int getNrAlergeni()
	{
		return this->nrAlergeni;
	}
	//metode de prelucrare/afisare atribute
	void adaugaAlergen(string alergenNou)
	{
		if (alergenNou.length() > 1)
		{
			Ingredient i = *this;
			delete[]this->alergeni;
			this->nrAlergeni++;
			this->alergeni = new string[this->nrAlergeni];
			for (int k = 0; k < i.nrAlergeni; k++)
				this->alergeni[k] = i.alergeni[k];
			this->alergeni[this->nrAlergeni - 1] = alergenNou;
		}
	}
	void afisareAlergeni()
	{
		if (this->nrAlergeni > 0 && this->alergeni != nullptr)
		{
			cout << "\nNumarul de alergeni: " << this->nrAlergeni;
			cout << "\nAlergeni: ";
			for (int k = 0; k < this->nrAlergeni; k++)
				cout << this->alergeni[k] << " ";
		}
		else
			throw exception("\nIngredientul nu are alergeni!");
	}

	~Ingredient() {
		delete[]this->alergeni;
		this->alergeni = nullptr;
	}

	friend ostream& operator<<(ostream& out, const Ingredient& i)
	{
		out << "\n-----------Ingredient------------";
		out << i.ingredient;
		out << "\nCantitatea ingredientului  necesara prepararii: " << i.cantitate;
		out << "\nNumarul de alergeni: " << i.nrAlergeni;
		out << "\nAlergenii: ";
		if (i.alergeni != nullptr)
			for (int k = 0; k < i.nrAlergeni; k++)
				out << i.alergeni[k] << " ";
		else
			out << "-";
		out << "\n---------------------------------\n";

		return out;
	}
	friend istream& operator>>(istream& in, Ingredient& i)
	{
		delete[]i.alergeni;
		i.alergeni = nullptr;
		cout << "\nIntroduceti ingredientul din stoc: "; in >> i.ingredient;
		cout << "\nIntroduceti cantitatea ingredientului necesara prepararii: "; in >> i.cantitate;
		cout << "\nIntroduceti numarul de alergeni: "; in >> i.nrAlergeni;
		if (i.nrAlergeni <= 0)
		{
			i.nrAlergeni = 0;
			i.alergeni = nullptr;
		}
		else
		{

			i.alergeni = new string[i.nrAlergeni];//alocare vector dinamic
			cout << "\nIntroduceti alergenii:\n";
			for (int k = 0; k < i.nrAlergeni; k++)
			{
				cout << "Alergenul " << k << ": ";
				in >> i.alergeni[k];
			}
		}
		return in;
	}
};
class Preparat
{
	const int idPreparat = 0;//am init cu 0 pentru a putea crea constructorul fara parametri, pt a crea vectorul listaPreparate
	string denumirePreparat = "anonima";
	float gramaj = 0;
	int durataConsum = 0;
	float pret = 0;
	int nrIngrediente = 0;
	Ingredient* listaIngrediente = nullptr; //vector alocat dinamic ce contine o lista cu ingrediente
public:
	Preparat() {}
	Preparat(int idPreparat) :idPreparat(idPreparat)
	{}
	Preparat(int idPreparat, int nrIngrediente, Ingredient* listaIngrediente) :idPreparat(idPreparat) {
		if (nrIngrediente > 0 && listaIngrediente != nullptr)
		{
			this->nrIngrediente = nrIngrediente;
			this->listaIngrediente = new Ingredient[this->nrIngrediente];
			for (int i = 0; i < this->nrIngrediente; i++)
				this->listaIngrediente[i] = listaIngrediente[i];
		}
		else
		{
			this->nrIngrediente = 0;
			this->listaIngrediente = nullptr;
		}

	}
	//c cu toti param
	Preparat(int idPreparat, string denumirePreparat, float gramaj, int durataConsum, float pret, int nrIngrediente, Ingredient* listaIngrediente) :idPreparat(idPreparat)
	{
		this->denumirePreparat = denumirePreparat;
		this->gramaj = gramaj;
		this->durataConsum = durataConsum;
		this->pret = pret;
		if (listaIngrediente != nullptr && nrIngrediente > 0)
		{
			this->nrIngrediente = nrIngrediente;
			this->listaIngrediente = new Ingredient[this->nrIngrediente];
			for (int i = 0; i < this->nrIngrediente; i++)
				this->listaIngrediente[i] = listaIngrediente[i];
		}
		else
		{
			this->nrIngrediente = 0;
			this->listaIngrediente = nullptr;
		}
	}
	Preparat(const Preparat& p) :idPreparat(p.idPreparat)
	{
		this->denumirePreparat = p.denumirePreparat;
		this->gramaj = p.gramaj;
		this->durataConsum = p.durataConsum;
		this->pret = p.pret;
		if (p.listaIngrediente != nullptr && p.nrIngrediente > 0)
		{
			this->nrIngrediente = p.nrIngrediente;
			this->listaIngrediente = new Ingredient[this->nrIngrediente];
			for (int i = 0; i < this->nrIngrediente; i++)
				this->listaIngrediente[i] = p.listaIngrediente[i];
		}
		else
		{
			this->nrIngrediente = 0;
			this->listaIngrediente = nullptr;
		}
	}
	Preparat& operator=(const Preparat& p)
	{
		delete[]this->listaIngrediente;
		this->listaIngrediente = nullptr;

		if (this != &p)
		{
			this->denumirePreparat = p.denumirePreparat;
			this->gramaj = p.gramaj;
			this->durataConsum = p.durataConsum;
			this->pret = p.pret;
			if (p.listaIngrediente != nullptr && p.nrIngrediente > 0)
			{
				this->nrIngrediente = p.nrIngrediente;
				this->listaIngrediente = new Ingredient[this->nrIngrediente];
				for (int i = 0; i < this->nrIngrediente; i++)
					this->listaIngrediente[i] = p.listaIngrediente[i];
			}
			else
			{
				this->nrIngrediente = 0;
				this->listaIngrediente = nullptr;
			}
		}
		return *this;
	}
	//getteri si setteri
	void setDenumirePreparat(string denumirePreparat)
	{
		if (denumirePreparat.length() > 1)
			this->denumirePreparat = denumirePreparat;
	}
	string getDenumirePreparat()
	{
		return this->denumirePreparat;
	}
	void setGramajPreparat(float gramaj)
	{
		if (gramaj > 0)
			this->gramaj = gramaj;
	}
	float getGramajPreparat()
	{
		return this->gramaj;
	}
	void setPretPreparat(float pret)
	{
		if (pret > 0)
			this->pret = pret;
	}
	float getPretPreparat()
	{
		return this->pret;
	}
	void setDurataConsum(int durata)
	{
		if (durata > 0)
			this->durataConsum = durata;
	}
	int getDurataConsum()
	{
		return this->durataConsum;
	}
	int getNrIngrediente()
	{
		return this->nrIngrediente;
	}
	void setListaIngrediente(Ingredient* listaIngrediente, int nrIngrediente)
	{
		delete[]this->listaIngrediente;
		this->listaIngrediente = nullptr;

		if (listaIngrediente != nullptr && nrIngrediente > 0)
		{
			this->nrIngrediente = nrIngrediente;
			this->listaIngrediente = new Ingredient[this->nrIngrediente];
			for (int i = 0; i < this->nrIngrediente; i++)
				this->listaIngrediente[i] = listaIngrediente[i];
		}
		else
		{
			this->nrIngrediente = 0;
			this->listaIngrediente = nullptr;
		}
	}
	Ingredient* getListaIngrediente()
	{
		return this->listaIngrediente;
	}
	//metode de prelucrare/afisare
	void afisareListaIngrediente()
	{
		if (this->nrIngrediente > 0 && this->listaIngrediente != nullptr) {
			cout << "\nIngredientele preparatului " << this->idPreparat << " sunt: ";
			for (int i = 0; i < this->nrIngrediente; i++)
			{
				cout << this->listaIngrediente[i].getIngredient().getDenumireMateriePrima() << "  |  ";
			}
		}
		else
			throw exception("\nNu sunt inregistrate ingredientele pentru acest preparat!");
	}
	bool esteExpirat(int durata)//durata- nr de zile de la crearea preparatului
	{
		if (this->durataConsum < durata)
			return 1;//e expirata
		return 0;
	}
	void adaugaIngredient(Ingredient ingredient)
	{
		Preparat p = *this;
		delete[]this->listaIngrediente;
		this->nrIngrediente++;
		this->listaIngrediente = new Ingredient[this->nrIngrediente];
		for (int i = 0; i < p.nrIngrediente; i++)
			this->listaIngrediente[i] = p.listaIngrediente[i];
		this->listaIngrediente[this->nrIngrediente - 1] = ingredient;
	}
	~Preparat()
	{
		delete[]this->listaIngrediente;
		this->listaIngrediente = nullptr;
	}
	friend ostream& operator<<(ostream& out, const Preparat& p)
	{
		out << "\n-----------PREPARAT------------";
		out << "\nId-ul preparatulu: " << p.idPreparat;
		out << "\nDenumirea preparatului: " << p.denumirePreparat;
		out << "\nGramajul preparatului(grame/ml): " << p.gramaj;
		out << "\nPretul preparatului(lei): " << p.pret;
		out << "\nDurata de consum a preparatului(zile): " << p.durataConsum;
		out << "\nNumarul de ingrediente necesare pentru preparare: " << p.nrIngrediente;
		out << "\nLista ingredientelor : ";
		if (p.listaIngrediente != nullptr)
			for (int i = 0; i < p.nrIngrediente; i++)
				//afiseaza tot ingredientul cu toate atributele: out << p.listaIngrediente[i] << " ";
				out << p.listaIngrediente[i].getIngredient().getDenumireMateriePrima() << "  |  ";
		else
			out << "-";
		out << "\n------------------------------\n";
		return out;
	}
	bool existaIngredient(Ingredient& ingredientCautat)
	{
		for (int i = 0; i < this->nrIngrediente; i++)
		{
			if (this->listaIngrediente[i].getIngredient().getDenumireMateriePrima() == ingredientCautat.getIngredient().getDenumireMateriePrima())
				return true;
		}
		return false;
	}
	friend istream& operator>>(istream& in, Preparat& p)
	{

		cout << "\nIntroduceti denumirea preparatului: "; getline(in, p.denumirePreparat);
		cout << "\nIntroduceti gramajul preparatului: "; in >> p.gramaj;
		cout << "\nIntroduceti durata de consum a preparatului(zile):"; in >> p.durataConsum;
		cout << "\nIntroduceti pretul preparatului(lei): "; in >> p.pret;
		return in;
	}

	bool disponibilitateStoc(Preparat preparat) {

		for (int i = 0; i < this->nrIngrediente; i++)
		{
			if (preparat.getListaIngrediente()[i].getCantitateIngredient() > preparat.getListaIngrediente()[i].getIngredient().getCantitateStoc())
				return false;
		}
		return true;
	}
	void scadeCantitateStoc() {
		if (this->nrIngrediente > 0 && this->listaIngrediente != nullptr)
		{
			for (int i = 0; i < this->nrIngrediente; i++) {
				float cantitateStoc1 = this->listaIngrediente[i].getIngredient().getCantitateStoc();
				float cantitateNecesara = this->listaIngrediente[i].getCantitateIngredient();
				float cantitateNoua = cantitateStoc1 - cantitateNecesara;
				this->listaIngrediente[i].getIngredient().setCantitateStoc(cantitateNoua);
			}

		}
	}
	Preparat operator+(int pret)
	{
		if (pret > 0)
		{
			Preparat copie = *this;
			copie.pret += 10;
			return copie;
		}
		else
			throw exception("\nValoarea introdusa pentru pret este negativa!");
	}
	Preparat& operator++() {
		this->durataConsum++;
		return*this;
	}
	Preparat operator--(int index)
	{
		Preparat copie = *this;
		this->pret--;
		return copie;
	}
	bool operator>(const Preparat& p)
	{
		if (this->nrIngrediente > 0 && p.nrIngrediente > 0)
		{
			if (this->nrIngrediente > p.nrIngrediente)
				return true;
			return false;
		}
		else
			throw exception("\nUnele preparate nu au ingrediente initializate!");
	}
};

enum TipMeniu
{
	Necunoscut = 10, Micdejun = 20, Pranz = 30, Cina = 40
};
class Meniu {
	TipMeniu tipMeniu = TipMeniu::Necunoscut;
	int nrPreparate = 0;
	Preparat* listaPreparate = nullptr;
public:
	Meniu() {
		//c fara param
	}
	Meniu(TipMeniu tipMeniu, int nrPreparate, Preparat* listaPreparate)
	{
		this->tipMeniu = tipMeniu;
		if (nrPreparate > 0 && listaPreparate != nullptr)
		{
			this->nrPreparate = nrPreparate;
			this->listaPreparate = new Preparat[this->nrPreparate];
			for (int i = 0; i < this->nrPreparate; i++)
				this->listaPreparate[i] = listaPreparate[i];
		}
		else {
			this->nrPreparate = 0;
			this->listaPreparate = nullptr;
		}
	}
	Meniu(TipMeniu tipMeniu) {
		this->tipMeniu = tipMeniu;
	}
	Meniu(const Meniu& m)
	{

		this->tipMeniu = m.tipMeniu;
		if (m.nrPreparate > 0 && m.listaPreparate != nullptr)
		{
			this->nrPreparate = m.nrPreparate;
			this->listaPreparate = new Preparat[this->nrPreparate];
			for (int i = 0; i < this->nrPreparate; i++)
				this->listaPreparate[i] = m.listaPreparate[i];
		}
		else {
			this->nrPreparate = 0;
			this->listaPreparate = nullptr;
		}
	}
	Meniu& operator=(const Meniu& m)
	{
		if (this != &m)
		{
			delete[]this->listaPreparate;
			this->listaPreparate = nullptr;

			this->tipMeniu = m.tipMeniu;
			if (m.nrPreparate > 0 && m.listaPreparate != nullptr)
			{
				this->nrPreparate = m.nrPreparate;
				this->listaPreparate = new Preparat[this->nrPreparate];
				for (int i = 0; i < this->nrPreparate; i++)
					this->listaPreparate[i] = m.listaPreparate[i];
			}
			else {
				this->nrPreparate = 0;
				this->listaPreparate = nullptr;
			}
		}
		return *this;
	}
	//getteri si setteri
	void setTipMeniu(TipMeniu tipMeniu)
	{
		if (tipMeniu == TipMeniu::Micdejun || tipMeniu == TipMeniu::Pranz || tipMeniu == TipMeniu::Cina)
		{
			this->tipMeniu = tipMeniu;
		}
	}
	TipMeniu getTipMeniu()
	{
		return this->tipMeniu;
	}
	void setNrPreparate(int nrPreparate)
	{
		if (nrPreparate > 0)
			this->nrPreparate = nrPreparate;
	}
	int getNrPreparate()
	{
		return this->nrPreparate;
	}
	void setListaPreparate(Preparat* listaPreparate, int nrPreparate)
	{
		delete[]this->listaPreparate;
		this->listaPreparate = nullptr;
		if (listaPreparate != nullptr && nrPreparate > 0)
		{
			this->nrPreparate = nrPreparate;
			this->listaPreparate = new Preparat[this->nrPreparate];
			for (int i = 0; i < this->nrPreparate; i++)
				this->listaPreparate[i] = listaPreparate[i];
		}
		else
		{
			this->nrPreparate = 0;
			this->listaPreparate = nullptr;
		}
	}
	Preparat* getListaPreparate()
	{
		return this->listaPreparate;
	}
	//metode de adaugare si afisare preparat 
	void afisareListaPreparate()
	{
		if (this->nrPreparate > 0 && this->listaPreparate != nullptr) {
			cout << "\nNumarul de preparate existente in meniu: " << this->nrPreparate;
			cout << "\nPreparatele din meniu sunt: ";
			for (int i = 0; i < this->nrPreparate; i++)
			{
				cout << this->listaPreparate[i].getDenumirePreparat() << "  |  ";
			}
		}
		else
			throw exception("\nNu sunt inregistrate preparatele in acest meniu!");
	}
	void adaugaPreparat(Preparat preparat)
	{
		Meniu m = *this;
		delete[]this->listaPreparate;
		this->nrPreparate++;
		this->listaPreparate = new Preparat[this->nrPreparate];
		for (int i = 0; i < m.nrPreparate; i++)
		{
			this->listaPreparate[i] = m.listaPreparate[i];
		}
		this->listaPreparate[this->nrPreparate - 1] = preparat;
	}
	~Meniu()
	{
		delete[]this->listaPreparate;
		this->listaPreparate = nullptr;
	}
	friend ostream& operator<<(ostream& out, const Meniu& m)
	{
		out << "\n-----------------MENIU----------------";
		out << "\nTipul meniului(Micdejun-20, Pranz-30, Cina-40): " << m.tipMeniu;
		out << "\nNumarul de preparate existente in meniu: " << m.nrPreparate;
		out << "\nLista preparatelor : ";
		out << "\n-------------------------------------";
		if (m.listaPreparate != nullptr)
			for (int i = 0; i < m.nrPreparate; i++)
			{
				out << endl << m.listaPreparate[i].getDenumirePreparat() << "  ****************  " << m.listaPreparate[i].getPretPreparat() << "   lei   ";
			}
		else
			out << "-";
		out << "\n------------------------------------\n";
		return out;
	}
	friend istream& operator>>(istream& in, Meniu& m)
	{
		in.ignore();
		string tipMeniu;
		cout << "\nIntroduceti tipul meniului(Micdejun/Pranz/Cina): "; getline(in, tipMeniu);
		while (tipMeniu != "Micdejun" && tipMeniu != "Pranz" && tipMeniu != "Cina")
		{
			cout << "\nAti introdus o denumire incorecta! Va rugam introduceti tipul meniului Micdejun/Pranz/Cina: "; getline(in, tipMeniu);

		}
		if (tipMeniu == "Micdejun")
		{
			m.tipMeniu = TipMeniu::Micdejun;
		}
		else
		{
			if (tipMeniu == "Pranz")
				m.tipMeniu = TipMeniu::Pranz;
			else
				if (tipMeniu == "Cina")
					m.tipMeniu = TipMeniu::Cina;
		}
		return in;
	}
	bool preparatInMeniu(string denumirePreparat) {
		for (int i = 0; i < this->nrPreparate; i++)
		{
			if (this->listaPreparate[i].getDenumirePreparat() == denumirePreparat)
				return true;
		}
		return false;
	}
	Preparat& getPreparatDupaDenumire(string denumirePreparat)
	{
		for (int i = 0; i < this->nrPreparate; i++)
			if (this->listaPreparate[i].getDenumirePreparat() == denumirePreparat)
				return this->listaPreparate[i];
	}
	bool operator!()
	{
		return !this->nrPreparate;
	}
};
class Comanda
{
	const int idComanda = 0;
	string statusComanda = "Necunoscut";
	int nrPreparateComandate = 0;
	Preparat* listaPreparateComandate = nullptr;
	Meniu meniu;
public:
	Comanda() {
	}
	Comanda(int idComanda) :idComanda(idComanda)
	{}
	Comanda(int idComanda, string statusComanda, Meniu meniu, int nrPreparateComandate, Preparat* listaPreparateComandate) :idComanda(idComanda)
	{
		this->statusComanda = statusComanda;
		this->meniu = meniu;
		if (nrPreparateComandate > 0 && listaPreparateComandate != nullptr)
		{
			this->nrPreparateComandate = nrPreparateComandate;
			this->listaPreparateComandate = new Preparat[this->nrPreparateComandate];
			for (int i = 0; i < this->nrPreparateComandate; i++)
				this->listaPreparateComandate[i] = listaPreparateComandate[i];
		}
		else {
			this->nrPreparateComandate = 0;
			this->listaPreparateComandate = nullptr;
		}
	}
	Comanda(int idComanda, string statusComanda, Meniu meniu) :idComanda(idComanda)
	{
		this->statusComanda = statusComanda;
		this->meniu = meniu;
	}
	Comanda(const Comanda& c) :idComanda(c.idComanda)
	{
		this->statusComanda = c.statusComanda;
		this->meniu = c.meniu;
		if (c.nrPreparateComandate > 0 && c.listaPreparateComandate != nullptr)
		{
			this->nrPreparateComandate = c.nrPreparateComandate;
			this->listaPreparateComandate = new Preparat[this->nrPreparateComandate];
			for (int i = 0; i < this->nrPreparateComandate; i++)
				this->listaPreparateComandate[i] = c.listaPreparateComandate[i];
		}
		else {
			this->nrPreparateComandate = 0;
			this->listaPreparateComandate = nullptr;
		}
	}
	Comanda& operator=(const Comanda& c)
	{
		if (this != &c)
		{
			delete[]this->listaPreparateComandate;
			this->listaPreparateComandate = nullptr;

			this->statusComanda = c.statusComanda;
			this->meniu = c.meniu;
			if (c.nrPreparateComandate > 0 && c.listaPreparateComandate != nullptr)
			{
				this->nrPreparateComandate = c.nrPreparateComandate;
				this->listaPreparateComandate = new Preparat[this->nrPreparateComandate];
				for (int i = 0; i < this->nrPreparateComandate; i++)
					this->listaPreparateComandate[i] = c.listaPreparateComandate[i];
			}
			else {
				this->nrPreparateComandate = 0;
				this->listaPreparateComandate = nullptr;
			}
		}
		return *this;
	}
	//getteri si setteri
	void setStatusComanda(string statusComanda)
	{
		if (statusComanda.length() > 0)
		{
			this->statusComanda = statusComanda;
		}
	}
	string getStatusComanda()
	{
		return this->statusComanda;
	}
	void setMeniu(Meniu meniu)
	{
		if (meniu.getListaPreparate() != nullptr)
		{
			this->meniu = meniu;
		}
	}
	Meniu getMeniu()
	{
		return this->meniu;
	}
	void setNrPreparateComandate(int nrPreparateComandate)
	{
		if (nrPreparateComandate > 0)
			this->nrPreparateComandate = nrPreparateComandate;
	}
	int getNrPreparateComandate()
	{
		return this->nrPreparateComandate;
	}
	void setListaPreparateComandate(Preparat* listaPreparateComandate, int nrPreparateComandate)
	{
		delete[]this->listaPreparateComandate;
		this->listaPreparateComandate = nullptr;
		if (listaPreparateComandate != nullptr && nrPreparateComandate > 0)
		{
			this->nrPreparateComandate = nrPreparateComandate;
			this->listaPreparateComandate = new Preparat[this->nrPreparateComandate];
			for (int i = 0; i < this->nrPreparateComandate; i++)
			{
				if (meniu.preparatInMeniu(listaPreparateComandate[i].getDenumirePreparat()))
					this->listaPreparateComandate[i] = listaPreparateComandate[i];
				else
					this->nrPreparateComandate--; //se adauga doar preparatele existente in meniu
			}
		}
		else
		{
			this->nrPreparateComandate = 0;
			this->listaPreparateComandate = nullptr;
		}
	}
	Preparat* getListaPreparateComandate()
	{
		return this->listaPreparateComandate;
	}
	//metode de adaugare si afisare preparat 
	void afisareListaPreparateComandate()
	{
		if (this->nrPreparateComandate > 0 && this->listaPreparateComandate != nullptr) {
			cout << "\nNumarul de preparate coamndate: " << this->nrPreparateComandate;
			cout << "\nPreparatele comandate: ";
			for (int i = 0; i < this->nrPreparateComandate; i++)
			{
				cout << this->listaPreparateComandate[i].getDenumirePreparat() << "  |  ";
			}
		}
		else
			throw exception("\nNu este comandat niciun preparat!");
	}
	void adaugaPreparatComandat(Preparat preparat)
	{
		if (meniu.preparatInMeniu(preparat.getDenumirePreparat()))
		{
			Comanda c = *this;
			delete[]this->listaPreparateComandate;
			//this->nrPreparateComandate++;
			this->listaPreparateComandate = new Preparat[this->nrPreparateComandate + 1];
			for (int i = 0; i < c.nrPreparateComandate; i++)
				this->listaPreparateComandate[i] = c.listaPreparateComandate[i];
			this->listaPreparateComandate[this->nrPreparateComandate] = preparat;

		}
		else
			cout << "\nPreparatul pe care doriti sa il adaugati nu exista in meniu!";
	}
	~Comanda()
	{
		delete[]this->listaPreparateComandate;
		this->listaPreparateComandate = nullptr;
	}
	friend ostream& operator<<(ostream& out, const Comanda& c)
	{
		out << "\n--------COMANDA--------";
		out << "\nID comanda: " << c.idComanda;
		out << "\nStatus comanda: " << c.statusComanda;
		out << "\nNumarul de preparate comandate: " << c.nrPreparateComandate;
		out << "\nLista preparatelor comandate : ";
		if (c.listaPreparateComandate != nullptr)
			for (int i = 0; i < c.nrPreparateComandate; i++)
			{
				out << c.listaPreparateComandate[i].getDenumirePreparat() << "  |  ";
			}
		else
			out << "-";
		out << "\nPret total comanda: " << c.pretTotal() << " lei.";
		out << "\n----------------------------\n";

		return out;
	}
	friend istream& operator>>(istream& in, Comanda& c)
	{
		delete[]c.listaPreparateComandate;
		c.listaPreparateComandate = nullptr;
		cout << c.meniu;
		cout << "\nIntroduceti statusul comenzii "; in >> c.statusComanda;
		cout << "\nIntroduceti numarul total de preparate pe care doriti sa le comandati: "; in >> c.nrPreparateComandate;
		in.ignore();
		if (c.nrPreparateComandate <= 0)
		{
			c.nrPreparateComandate = 0;
			c.listaPreparateComandate = nullptr;
		}
		else
		{

			c.listaPreparateComandate = new Preparat[c.nrPreparateComandate];
			for (int i = 0; i < c.nrPreparateComandate; i++)
			{
				string denumirePrepComanda;
				cout << "\nIntroduceti denumirea preparatului pe care doriti sa il comandati: "; getline(in, denumirePrepComanda);
				bool preparatGasit = false;
				while (!c.meniu.preparatInMeniu(denumirePrepComanda))
				{
					cout << "\nPreparatul " << denumirePrepComanda << " nu exista in meniu! Alegeti altul!";
					cout << "\nIntroduceti denumirea preparatului pe care doriti sa il comandati: "; getline(in, denumirePrepComanda);
				}
				if (c.meniu.preparatInMeniu(denumirePrepComanda))
				{
					Preparat preparat = c.meniu.getPreparatDupaDenumire(denumirePrepComanda);
					if (preparat.disponibilitateStoc(preparat))
					{
						c.listaPreparateComandate[i] = preparat;
						c.meniu.getPreparatDupaDenumire(preparat.getDenumirePreparat()).scadeCantitateStoc();
						preparatGasit = true;
					}
					else
					{
						cout << "\nPreparatul " << denumirePrepComanda << " nu este disponibil in stoc!Va rugam alegeti altul!";
					}
				}
				if (!preparatGasit)
					i--;

			}
			cout << "\n!!!!!!!COMANDA DVS A FOST PRELUATA CU SUCCES!!!!!!!!\n";
		}
		return in;
	}
	float pretTotal()const
	{
		float pret = 0;
		for (int i = 0; i < this->nrPreparateComandate; i++)
		{
			pret += this->listaPreparateComandate[i].getPretPreparat();
		}
		return pret;
	}
	Preparat& operator[](int index)
	{
		return this->listaPreparateComandate[index];
	}
	bool operator==(const Comanda& c)
	{
		if (this->statusComanda == c.statusComanda && this->nrPreparateComandate == c.nrPreparateComandate)
		{
			for (int i = 0; i < this->nrPreparateComandate; i++)
			{
				if (this->listaPreparateComandate == c.listaPreparateComandate)
					return true;
			}
			return true;
		}
		return false;

	}
};
int main() {
	//CLASA MATERIE PRIMA
	StocMateriePrima s1("Rosii", "kilograme", 200);
	StocMateriePrima::setFurnizorMateriePrima("Lidl");
	// functiile de prelucrare/afisare
	//s1.afisareDenumire();
	//s1.cantitateNouaStoc(1000);
//	cin >> s1;
//	cout << s1;
	StocMateriePrima s2("Oua", "bucati", 100);
	StocMateriePrima s3("Lapte", "litri", 200);
	StocMateriePrima s4("Faina", "kilograme", 200);
	StocMateriePrima s5("Salam", "kilograme", 10);
	StocMateriePrima s6("Cartofi", "kilograme", 300);
	StocMateriePrima s7("Ciorba", "litri", 100);
	StocMateriePrima s8("Morcovi", "kilograme", 50);
	StocMateriePrima s9("Rosii", "kilograme", 50);
	StocMateriePrima s10("Pui", "kilograme", 30);
	//op cast la string
	string denumire = (string)s2;
	//	cout << s2;
	//	cout <<"\nDenumire materie prima(op cast la string) : "<< denumire;
	
	//op!
	/*if (!s1)//s1 nu are stoc
		cout << "\nMateria prima: " << s1.getDenumireMateriePrima() << " nu are stoc";
	else
		cout << "\nMateria prima: " << s1.getDenumireMateriePrima() << " are stoc";*/

	//CLASA INGREDIENT
	string alergeni[] = { "ou", "vitaminaA", "vitaminaC" };
	Ingredient i1(s1, 20, 0, alergeni);
	Ingredient i2(s2, 2, 1, alergeni); //cout << "\nIngredientul 2: " << i2;
	Ingredient i3(s3, 20, 0, alergeni); //cout << "\nIngredientul 3:" << i3;
	//i3.adaugaAlergen("VitaminaE2");
	/*try {
		i3.afisareAlergeni();
	}
	catch (exception ex)
	{
		cout << ex.what();
	}*/
	string alergeni1[] = { "vitaminaA", "vitaminaB" };
	Ingredient i4(s4, 200, 0, alergeni1);
	Ingredient i5(s5, 5, 1, alergeni1);
	Ingredient i6(s6, 200, 0, alergeni);
	Ingredient i7(s7, 100, 0, alergeni);
	Ingredient i8(s8, 20, 1, alergeni1);
	Ingredient i9(s9, 15, 1, alergeni1);
	Ingredient i10(s10, 1, 0, alergeni);
	//cin >> i4;
	//cout << i4;

	//CLASA PREPARAT
	Ingredient listaIngrediente1[] = { i1, i2, i3, i4, i5 };
	Ingredient listaIngrediente2[] = { i4, i5 };
	Preparat p1(1, "Paste carbonara", 200, 2, 25, 5, listaIngrediente1);
	try {
		// p1 = p1 + -1; //pentru a arunca exceptia
		p1 = p1 + 10; //crestem pretul prep 10
	}
	catch (exception ex)
	{
		cout << ex.what();
	}
	Preparat p2(2, "Pizza", 300, 4, 30, 2, listaIngrediente2); //cout << p2;
	++p2;//crestem durata de consum cu o zi
	//cout << p2;
	p2--;//scadem pretul preparatului cu 1 leu
	//cout << p2;
	//op >
	/*try {
		if (p1 > p2)
			cout << "\nPreparatul 1 are un numar de ingrediente mai mare decat preparatul 2";
		else
			cout << "\nPreparatul 2 are un numar de ingrediente mai mare decat preparatul 1";
	}
	catch (exception ex) //exemplu de exception prin parametri
	{
		cout << ex.what();
	}*/
	//functii de prelucrare/afisare
	//p2.adaugaIngredient(i3);
	//p2.afisareListaIngrediente();
	Ingredient listaIngrediente3[] = { i8, i9 };
	Preparat p3(3,"Supa",250,2, 23, 2, listaIngrediente3);
	
	//Preparat p3(3, 2, listaIngrediente3); //pentru supraincarcarea op >>
	//cin >> p3;
	//	cout << p3;
		/*try {
			p3.afisareListaIngrediente();
		}
		catch (exception ex)
		{
			cout << ex.what();
		}
		if (p2.esteExpirat(6))
			cout << "\nPreparatul este expirat";//6>5
		else
			cout << "\nPreparatul nu este expirat!";
		*/
	Ingredient listaIngrediente4[] = { i7, i10 };
	Preparat p4(4, "Ciorba de pui", 250, 3, 40, 2, listaIngrediente4);
	Ingredient listaIngrediente5[] = { i6, i8, i9 };
	Preparat p7(7, "Supa de legume", 250, 3, 15, 3, listaIngrediente5);
	Ingredient listaIngrediente6[] = { i2 };
	Preparat p5(5, "Omleta", 150, 1, 20, 1, listaIngrediente6);
	Preparat p6(6, "Ou fiert", 10, 1, 5, 1, listaIngrediente6);
	//CLASA MENIU
	Preparat preparateMeniu[] = { p1, p2, p3, p7 };
	Preparat preparateMeniu1[] = { p1, p2, p4, p7 };
	Meniu m1(TipMeniu::Pranz, 4, preparateMeniu1);
	Meniu m2(TipMeniu::Pranz, 4, preparateMeniu);
	Meniu m3(TipMeniu::Cina, 4, preparateMeniu1);
	m1.adaugaPreparat(p3);
	Preparat preparateMeniuMicDejun[] = { p5, p6 };
	Meniu m4(TipMeniu::Micdejun, 2, preparateMeniuMicDejun);
	//Meniu m5;
	/*try {
		cout << endl;
		//m5.afisareListaPreparate(); //pentru a arunca exceptia
		m1.afisareListaPreparate();
	}
	catch (exception ex)
	{
		cout << ex.what();
	}*/
	//cin >> m1; //citesc doar tipulMeniului
	//cout << m1;
	
	//op!
	/*Meniu m0;
	if (!m0)
		cout << "Meniul nu are preparate adaugate.(nu este valid)";
	else
		cout << "Meniul nu are preparate adaugate.(nu este valid)";*/

	//CLASA COMANDA
	Preparat listaPreparateComandate[] = { p1, p2 };
	Comanda c1(1, "Pregatire", m1, 2, listaPreparateComandate);
	Comanda c2(2, "Preluare", m1, 3, preparateMeniu);
	c1.adaugaPreparatComandat(p4);//p4-- nu exista in meniu m1 -> se adauga doar preparatele existente in meniu
	//cout << c1;
	/*//Comanda c4;
	try {
		//c4.afisareListaPreparateComandate();//arunc exceptie
		c2.afisareListaPreparateComandate();
	}
	catch (exception ex)
	{
		cout << ex.what();
	}*/
	cin >> c2;
	cout << c2;
	//op indexare
	cout << "\nIntroduceti numarul preparatului caruia doriti sa ii cunoasteti detaliile: "; int nr; cin >> nr;
	Preparat prepComandat = c2[nr];//nu are id pt ca e o vb auxiliara
	cout << prepComandat;
	//op==
	Comanda c3(3, "Preluare", m1, 2, listaPreparateComandate);
	Comanda c4(4, "Preluare", m1, 2, listaPreparateComandate);
	if (c3 == c4)
		cout << "\nComanda 3 si comanda 4 sunt la fel.";
	else
		cout << "\nComanda 3 si comanda 4 sunt diferite.";
	return 0;
}