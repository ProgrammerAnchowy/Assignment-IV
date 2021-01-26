/****************************************************************************
**						SAKARYA �N�VERS�TES�
**				B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**					B�LG�SAYAR M�HEND�SL��� B�L�M�
**					 PROGRAMLAMAYA G�R��� DERS�
**
**					�DEV NUMARASI�...:04
**					��RENC� ADI......:Davud Samed Tombul
**					��RENC� NUMARASI.:B171210007
**					DERS GRUBU.......:�rg�nE�itim 1D
****************************************************************************/


#include <iostream>//Cout gibi temel komutlar� kullanmak i�in gerekli k�t�phane.
#include<locale.h>//T�rk�e karakterleri kullanabilmemiz i�in gerekli k�t�phane.
#include <string>
#include<iomanip>//Setw manipulat�r�n� kullanbilmemiz i�in gerekli k�t�phane.



using namespace std;//Her seferinde std::cout vs yazarak zaman kaybetmemek i�in kulland���m�z komut.

					//Girece�imiz metni �ifreleyecek ve �ifresini ��zecek fonksiyonlar�n bildirimini i�eren class'�m�z.
class Sifre
{
public:

	void Sifrele(const string &yazi, const string &key, string &sifreliyazi);

	void SifreyiCoz(const string &sifreliyazi, const string &key, string &yazi);

private:

};

//Girece�imiz metni �ifreleyecek parametreli fonksiyonumuz.
void Sifre::Sifrele(const string &yazi, const string &anahtarKelime, string &sifremetin)
{
	int yeni;
	int t, k;

	for (t = 0, k = 0; t < yazi.length(); ++t, k++)
	{
		if (k >= anahtarKelime.length())
			k = 0;

		if (yazi[t] >= 'A' && yazi[t] <= 'Z')
			yeni = ((yazi[t] - 64) + (anahtarKelime[k] - 64)) % 26;

		else
			yeni = yazi[t] - 64;
		sifremetin.append(string(1, (char)(yeni + 64)));
	}
}

//�ifreli metnin �ifresini ��zecek fonksiyonumuz.
void Sifre::SifreyiCoz(const string &sifremetin, const string &anahtarKelime, string &yazi)
{
	int yenile;
	int q, w;

	for (q = 0, w = 0; q < sifremetin.length(); ++q, w++)
	{
		if (w >= anahtarKelime.length())
			w = 0;

		if (sifremetin[q] >= 'A' && sifremetin[w] <= 'Z')
			yenile = ((sifremetin[q] - 64) + 26 - (anahtarKelime[w] - 64)) % 26;

		else
			yenile = sifremetin[q] - 'A';

		yazi.append(string(1, (char)(yenile + 64)));
	}
}

int main()
{
	//T�rk�e karakter kullanabilmemiz i�in gerekli komut.
	setlocale(LC_ALL, "Turkish");

	//Sifre class'�ndan sifree adl� nesneyi �retiyoruz.
	Sifre sifree;

	string sifre, desifre;


	char yazi[500];

	char anahtarKelime[500];


	cout << setw(30) << "Alfabe" << endl << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z" << endl << endl;

	cout << "Girece�iniz t�m karakterlerin b�y�k harfli ve alfabeden se�ilmi� olmas�na dikkat ediniz..." << endl << endl;

	cout << "�ifrelemek �stedi�iniz Metni Yaz�n�z: ";


	cin.getline(yazi, 256);


	cout << "Anahtar Kelimeyi Yaz�n�z :";

	cin.getline(anahtarKelime, 256);


	sifree.Sifrele(yazi, anahtarKelime, sifre);


	sifree.SifreyiCoz(sifre, anahtarKelime, desifre);


	cout << "�ifreli Metin: " << sifre << setw(50) << "�ifresi ��z�lm�� Metin: " << desifre << endl;


	system("pause");

	return 0;
}
