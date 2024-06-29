/****************************************************************************
										**					SAKARYA ÜNÝVERSÝTESÝ
										**			      BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
										**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
										**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
										**
										**				ÖDEV NUMARASI…: 2
										**				ÖÐRENCÝ ADI SOYADI: Tuðra YAVUZ
										**				ÖÐRENCÝ NUMARASI.: B221210064
										**				DERS GRUBU: 1.Öðretim A grubu (1-A)
										****************************************************************************/








#include <cmath>
#include <iostream>
using namespace std;
class karmasiksayilar {                             //karmasik sayilar sinifi
private:
	float imajiner;								//degiskenlerimiz (PRIVATE OLANLAR)
	float gercek;


public:										// public kisim
	karmasiksayilar() {
		gercek = 0;										//parametresiz kurucu metot
		imajiner = 0;

	}
	karmasiksayilar(float gercekkurucu, float imajinerkurucu) {
		imajiner = imajinerkurucu;															// parametreli kurucu metot
		gercek = gercekkurucu;


	}

	~karmasiksayilar()
	{
		//yok edici metot
	}
	void istemefonksiyonu() {

		cout << "lutfen karmasik sayinin gercek sayi kismini giriniz" << endl;
		cin >> gercek;
		cout << "lutfen karmasik sayinin imajiner sayi kismini giriniz" << endl;						//karmasik sayinin degiskenlerini istedigimiz public fonksyion
		cin >> imajiner;

	}

	void yazdir() {
		if (imajiner > 0)						//imajiner 0dan buyuk mu kontrol ediliyor																	
			cout << gercek << " + " << imajiner << "i" << endl;												// karmasik sayiyi parametrelerine gore yazdiran kod 
		else if (imajiner < 0)  // imajiner 0dan kucuk mu kontrol eden kod
			cout << gercek << " - " << -imajiner << "i" << endl;
		else
			cout << gercek << endl;
	}
	void toplamacikarmaicinresetlemefonksiyonu() {


		gercek = 0;
		imajiner = 0;							//toplamacikarmaesittirli islemlerde degeri korumak icin kullanilan fonksiyon


	}
	void carpmavebolmeicindegeratamafonk() {
		gercek = 1;
		imajiner = 1;														//carpma ve bolmede sonuc tanimsiz cikmamasi icin deger atama fonksiyonu
	}

	void kutupsalgosterimfonksyionu() {

		double rdegeri;													//kutupsal gosterimde islemleri yapip degerleri yazdirmaya yarayan fonksiyon
		double acidegeri;
		const double sabit = 180 / 3;
		rdegeri = sqrt(gercek * gercek + imajiner * imajiner);
		acidegeri = atan(imajiner / gercek) * sabit;
		cout << "kutupsal gosteriminiz r.cis(aci) seklinde olacaktir  " << "kutupsal gosteriminiz:       " << rdegeri << ".cis(" << acidegeri << ")" << endl;
	}


	karmasiksayilar operator+ (karmasiksayilar obje1)
	{
		karmasiksayilar toplam1;									//toplama islemi asiri yukeleme
		toplam1.gercek = gercek + obje1.gercek;
		toplam1.imajiner = imajiner + obje1.imajiner;
		return toplam1;
	}
	karmasiksayilar operator- (karmasiksayilar obje1)
	{
		karmasiksayilar toplam2;
		toplam2.gercek = gercek - obje1.gercek;					//cikarma islemi asiri yukleme
		toplam2.imajiner = imajiner - obje1.imajiner;
		return toplam2;
	}
	karmasiksayilar operator* (karmasiksayilar obje1)
	{
		karmasiksayilar carpim;
		carpim.gercek = gercek * obje1.gercek;					//carpma islemi asiri yukleme
		carpim.imajiner = imajiner * obje1.imajiner;
		return carpim;
	}
	karmasiksayilar operator/ (karmasiksayilar obje1)
	{
		karmasiksayilar bolum;
		bolum.gercek = gercek / obje1.gercek;					//bolme islemi asiri yukleme
		bolum.imajiner = imajiner / obje1.imajiner;
		return bolum;
	}
	karmasiksayilar operator+= (karmasiksayilar obje1)
	{
		gercek = gercek + obje1.gercek;
		imajiner = imajiner + obje1.imajiner;					//+= islemi asiri yukleme
		return *this;

	}
	karmasiksayilar operator-= (karmasiksayilar obje1)
	{																	//-= islemi asiri yukleme
		gercek = gercek - obje1.gercek;
		imajiner = imajiner - obje1.imajiner;
		return *this;
	}
	karmasiksayilar operator*= (karmasiksayilar obje1)
	{																					//*= islemi asiri yukleme
		gercek = gercek * obje1.gercek;
		imajiner = imajiner * obje1.imajiner;
		return *this;
	}
	karmasiksayilar operator/= (karmasiksayilar obje1)
	{																		// /= islemi asiri yukleme
		gercek = gercek / obje1.gercek;
		imajiner = imajiner / obje1.imajiner;
		return *this;
	}



};



int main() {
	short verigirisekraninadonusdegiskeni;
	karmasiksayilar sayi1, sayi2, gosterileceksayi;
	do {							//deger giris ekranina geri donmek icin do while
		cout << "1. sayi icin ";
		sayi1.istemefonksiyonu();
		cout << "2 sayi icin ";
		sayi2.istemefonksiyonu();

		int menudeyapilacakislemdegiskeni;
		short menudonusdegiskeni;
		do {			//menu ekranina donus icin do while
			do { //yapilacak islem gecerli mi diye kontrol eden do while

				cout << "lutfen sayilarinizla yapmak istediginiz islemi seciniz" << endl;
				cout << "1. islem : toplama  " << endl;
				cout << "2. islem : cikarma  " << endl;
				cout << "3. islem : carpma  " << endl;
				cout << "4. islem : bolme  " << endl;
				cout << "5. islem : kutupsal gosterim " << endl;
				cout << "6. islem : += toplama  " << endl;
				cout << "7. islem : -= cikarma " << endl;
				cout << "8. islem : *= carpma  " << endl;
				cout << "9. islem : /= bolme  " << endl;

				cin >> menudeyapilacakislemdegiskeni;
				if (menudeyapilacakislemdegiskeni == 1)									//yapilacak islem kontrol ediliyor
				{
					gosterileceksayi = sayi1 + sayi2;
					gosterileceksayi.yazdir();

				}
				else if (menudeyapilacakislemdegiskeni == 2)											//yapilacak islem kontrol ediliyor
				{
					gosterileceksayi = sayi1 - sayi2;
					gosterileceksayi.yazdir();

				}
				else if (menudeyapilacakislemdegiskeni == 3)
				{
					gosterileceksayi = sayi1 * sayi2;										//yapilacak islem kontrol ediliyor
					gosterileceksayi.yazdir();

				}
				else if (menudeyapilacakislemdegiskeni == 4)
				{
					gosterileceksayi = sayi1 / sayi2;
					gosterileceksayi.yazdir();															//yapilacak islem kontrol ediliyor

				}
				else if (menudeyapilacakislemdegiskeni == 5)										//yapilacak islem kontrol ediliyor
				{
					cout << "1. sayi icin ";
					sayi1.kutupsalgosterimfonksyionu();
					cout << "2. sayi icin ";
					sayi2.kutupsalgosterimfonksyionu();
				}


				else if (menudeyapilacakislemdegiskeni == 6) {
					gosterileceksayi.toplamacikarmaicinresetlemefonksiyonu();															//yapilacak islem kontrol ediliyor		
					gosterileceksayi += sayi1;
					gosterileceksayi += sayi2;
					gosterileceksayi.yazdir();

				}

				else if (menudeyapilacakislemdegiskeni == 7) {
					gosterileceksayi.toplamacikarmaicinresetlemefonksiyonu();																																				//yapilacak islem kontrol ediliyor																					
					gosterileceksayi = sayi1 - gosterileceksayi;
					gosterileceksayi -= sayi2;
					gosterileceksayi.yazdir();

				}
				else if (menudeyapilacakislemdegiskeni == 8) {
					gosterileceksayi.carpmavebolmeicindegeratamafonk();												//yapilacak islem kontrol ediliyor
					gosterileceksayi *= sayi1;
					gosterileceksayi *= sayi2;
					gosterileceksayi.yazdir();

				}
				else if (menudeyapilacakislemdegiskeni == 9) {														//yapilacak islem kontrol ediliyor
					gosterileceksayi.carpmavebolmeicindegeratamafonk();
					gosterileceksayi = sayi1;
					gosterileceksayi /= sayi2;
					gosterileceksayi.yazdir();

				}

				else
				{
					cout << "lutfen 1 ile 5 arasinda deger giriniz" << endl;								// secilen islem gecerli degilse calisacak kod blogu
					system("cls");
				}
			} while (!(menudeyapilacakislemdegiskeni >= 1 && menudeyapilacakislemdegiskeni <= 9));    //girilen islem gecerli mi kontrol etmek icin do while

			cout << "islem menusune geri donmek ister misiniz istiyorsaniz 1i istemiyorsaniz baska bir sayi giriniz" << endl;
			cin >> menudonusdegiskeni;
		} while (menudonusdegiskeni == 1);				//menuye donus icin do while

		cout << "veri giris ekranina donemk ister misiniz isterseniz 1i istemezseniz baska bir sayi tuslayiniz" << endl;
		cout << "***********************eger baska bir sayi girerseniz programdan cikmis olacaksiniz" << endl;
		cin >> verigirisekraninadonusdegiskeni;
	} while (verigirisekraninadonusdegiskeni == 1);  //veri giris ekranina donus icin do while
	return 0;
}