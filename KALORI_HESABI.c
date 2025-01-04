#include <stdio.h>
#include <string.h>

#define MAX_YEMEK 100  

struct yemek_listesi 
{
    char isim[50];
    float kalori;
};

struct yemek_listesi yemekler[MAX_YEMEK];
int yemek_sayisi = 0;   

void kalori_hesaplama() 
{
    int yas, cinsiyet, gunluk_egzersiz;
    float kilo, boy, bazal_metobolizma_hizi, gunluk_kalori;

    printf("Lutfen yasinizi giriniz: ");
    scanf("%d", &yas);

    printf("Lutfen cinsiyetinizi giriniz (Erkek = 1, Kadin = 2): ");
    scanf("%d", &cinsiyet);
    
    if(cinsiyet!=1&&cinsiyet!=2) 
	{
        printf("Gecersiz cinsiyet.\n");
        return;
    }

    printf("Lutfen kilonuzu giriniz (kg): ");
    scanf("%f", &kilo);

    printf("Lutfen boyunuzu giriniz (cm): ");
    scanf("%f", &boy);

    if (cinsiyet == 1) 
	{
        bazal_metobolizma_hizi = 66.47 + (13.75 * kilo) + (5 * boy) - (6.76 * yas);
    } 
	else if (cinsiyet == 2) 
	{
        bazal_metobolizma_hizi = 655.10 + (9.56 * kilo) + (1.85 * boy) - (4.68 * yas);
    } 
	

    printf("\nGunluk aktivite seviyenizi seciniz (1-5)\n");
    printf("1 - Hareketsiz\n");
    printf("2 - Hafif Egzersiz\n");
    printf("3 - Orta Egzersiz\n");
    printf("4 - Yogun Egzersiz\n");
    printf("5 - Cok Yogun Egzersiz\n");
    scanf("%d", &gunluk_egzersiz);

    switch (gunluk_egzersiz) 
	{
        case 1:
            gunluk_kalori = bazal_metobolizma_hizi * 1.2;
            break;
        case 2:
            gunluk_kalori = bazal_metobolizma_hizi * 1.375;
            break;
        case 3:
            gunluk_kalori = bazal_metobolizma_hizi * 1.55;
            break;
        case 4:
            gunluk_kalori = bazal_metobolizma_hizi * 1.725;
            break;
        case 5:
            gunluk_kalori = bazal_metobolizma_hizi * 1.9;
            break;
        default:
            printf("Gecersiz aktivite seviyesi.\n");
            return;
    }

    printf("\nGunluk kalori ihtiyaciniz: %.2f kaloridir.\n", gunluk_kalori);

    int alma_verme;
    printf("\nKilo almak icin 1'e basiniz\nKilo vermek icin 2'ye basiniz\nKilo korumak icin 3'e basiniz\n");
    scanf("%d", &alma_verme);


    if (alma_verme == 1) 
	{
    	printf("Saglikli kilo almak icin gunluk 400 kalori fazla alman yeterlidir.\n");
        printf("Kilo almak icin gunde %.2f kalori almaniz gerekiyor.\n", 400 + gunluk_kalori);
    }
	else if (alma_verme == 2) 
	{
		printf("Saglikli kilo vermek icin gunluk 400 kalori az alman yeterlidir.\n");
        printf("Kilo vermek icin gunde %.2f kalori almaniz gerekiyor.\n", gunluk_kalori - 400);
    }
    else if(alma_verme == 3) 
	{
    	printf("Kilonuzu korumak icin gunde %.2f kalori almaniz gerekiyor\n", gunluk_kalori);
	}
	else {
        printf("Gecersiz secim.\n");
    }
}

void yemekleri_kaydet() 
{
    if (yemek_sayisi < MAX_YEMEK) 
	{
        printf("Yemek adini giriniz: ");
        scanf("%s", &yemekler[yemek_sayisi].isim);
        printf("Yemek kalorisini giriniz: ");
        scanf("%f", &yemekler[yemek_sayisi].kalori);
        yemek_sayisi++;
    } 
	else 
	{
        printf("Yemek listesi dolu.\n");
    }
}

void yemekleri_goster() 
{
	int i;
    if (yemek_sayisi == 0) 
	{
        printf("Henuz yemek kaydedilmedi.\n");
    } 
	else
	{
        printf("\nKaydedilen Yemekler ve Kalorileri:\n");
        for (i = 0; i < yemek_sayisi; i++) 
		{
            printf("%s - %.2f kalori\n", yemekler[i].isim, yemekler[i].kalori);
        }
    }
}

int main() {
    int secim;

    printf("Kalori Hesaplama ve Yemek Takip Programina Hosgeldiniz!\n");

    while (1) 
	{
        printf("\nYapmak istediginiz islemi seciniz:\n");
        printf("1. Kalori Hesaplama\n");
        printf("2. Yemek Kaydet\n");
        printf("3. Kaydedilen Yemekleri Goruntule\n");
        printf("4. Cikis\n");
        scanf("%d", &secim);

        switch (secim) 
		{
            case 1:
                kalori_hesaplama();
                break;
            case 2:
                yemekleri_kaydet();
                break;
            case 3:
                yemekleri_goster();
                break;
            case 4:
                printf("Programdan cikiliyor...\n");
                return 0;
            default:
                printf("Gecersiz secim! Lutfen tekrar deneyin.\n");
        }
    }
    return 0;
}
