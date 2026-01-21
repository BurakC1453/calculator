#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//FONKSİYON PROTOTİPLERİ
double toplama(double x, double y);
double cikarma(double x, double y);
double carpma(double x, double y);
double bolme(double x, double y);
double usAlma(double x, double y);
double kareKok(double x);
double logaritma(double x);
double dogalLogaritma(double x);
double mutlakDeger(double x);
double yuvarlama(double x); 


// ----BÜTÜN FONKSİYONLAR----
double toplama(double x, double y){
    return x + y;
}

double cikarma(double x, double y){
    return  x - y;
}

double carpma(double x, double y){
    return x * y;
}    

double bolme (double x, double y ){
    if ( y != 0 ){
        return x / y;
    } else {
        printf("Hata: Bir sayi sifira bolunemez.\n");
        return 0;
    }
}
double usAlma(double x, double y){
    return pow(x, y);
}    

double kareKok(double x){
    if ( x >= 0 ){
        return sqrt(x);
    } else {
        printf("Hata: Negatif sayilarin karekoku alinamaz.\n");
        return 0;
    }
}
double logaritma(double x){
    if ( x > 0 ){
        return log10(x);
    } else {
        printf("Hata: Logaritma sadece pozitif sayilar icin tanimlidir.\n");
        return 0;
    }
}

double dogalLogaritma(double x){
    if ( x > 0 ){
        return log(x);
    } else {
        printf("Hata: Dogal logaritma sadece pozitif sayilar icin tanimlidir.\n");
        return 0;
    }
}

double mutlakDeger(double x){
    if ( x < 0 ){
        return -x;
    } else {
        return x;
    }
}

double yuvarlama(double x){
    return round(x);
}


// ----ANA PROGRAM----
int main () {

    int secim;
    double x,y,sonuc;
    char satir[255];
    FILE *f;

do{
    printf("----Hesap Makinesi----\n");
    printf("Cift Sayi Gerektirenler \n1. Toplama\n2. Cikarma\n3. Carpma\n4.Bolme\n5. Us Alma\n");
    printf("Tek Sayi Gerektirenler \n1. Kare Kok\n2. Logaritma\n3. Dogal Logaritma\n4. Mutlak Deger\n5. Yuvarlama\n");
    printf("Gecmisi goruntulemek icin 11'e basiniznn\n");
    printf("Cikis icin 0'a basin.\n");
    printf("Lutfen yapmak istediginiz islemi secin (0-11): \n");
    printf("NOT: Eger tek sayi gerektiren bir islem secmek isterseniz, islem numarasini 5 ile toplayin. Ornegin, karekok icin 6'yi secin.\n");
    scanf("%d", &secim);

    if (secim > 0 && secim < 6 ){

    printf("Birinci sayiyi girin: ");
    scanf("%lf", &x);

    printf("Ikinci sayiyi girin: ");
    scanf("%lf", &y);

        switch (secim) {
            case 1:
                sonuc = toplama(x, y);
                printf("Sonuc: %.2lf\n", sonuc);
                break;
    
            case 2:
                sonuc = cikarma(x,y);
                printf("Sonuc: %.2lf\n", sonuc);
                break;
            
            case 3:
                sonuc = carpma(x,y);
                printf("Sonuc:%.2lf\n", sonuc);
                break;
            
            case 4:
                sonuc = bolme(x,y);
                printf("sonuc: %.2lf\n", sonuc);
                break;
            
            case 5:
                sonuc = usAlma(x,y);
                printf("Sonuc: %.2lf\n", sonuc);
                break;
        }//  İLK SWİTCH SONU 
    f = fopen("gecmis.txt", "a");    
    fprintf(f, "Islem: %d | %.2lf ve %.2lf kullanildi | Sonuc: %.2lf\n", secim, x,y,sonuc );
    fclose(f);

    } else if ( secim > 5 && secim < 11) {

    printf("Kullanacaginiz sayiyi giriniz:\n");
    scanf("%lf", &x);

    
        switch (secim) {

            case 6:

            sonuc = kareKok(x);
            printf("Sonuc: %.2lf\n ", sonuc); 
            break;

            case 7:

            sonuc = logaritma(x);
            printf("Sonuc: %.2lf", sonuc);
            break;

            case 8:

            sonuc = dogalLogaritma(x);
            printf("Sonuc: %.2lf", sonuc);
            break;

            case 9:

            sonuc = mutlakDeger(x);
            printf("Sonuc: %.2lf", sonuc);
            break;

            case 10:

            sonuc = yuvarlama(x);
            printf("Sonuc: %.2lf", sonuc);
            break;

        }// İKİNCİ SWİTCH SONU  
    f = fopen("gecmis.txt", "a");
    fprintf(f, "Islem: %d | %.2lf kullanildi | sonuc: %.2lf\n", secim,x,sonuc);
    fclose(f);    

    }// ELSE İF SONU
    else if (secim == 11){


 f = fopen("gecmis.txt", "r");

    if (f == NULL ){
        printf("Henuz bir kayit bulunamadi.");
    } else { 
        
        printf("---ISLEM GECMISI---");
        while (fgets(satir, sizeof(satir), f) != NULL ) {
        printf("%s\n", satir);
    }
    fclose(f);

    }
    }// ELSE İF SONU


} while (secim != 0);


    
    if (secim == 0 )
    printf("Cikis yapiliyor:\n");
    return 0;
}
