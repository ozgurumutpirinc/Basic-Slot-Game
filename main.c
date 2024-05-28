#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>



char symbols(int num)   //Bu fonksiyonda main fonksiyonunda elde edilen sayilar sembollere cevrilir
{
    switch(num)
    {
        case 1: return '*';
        break;
        case 2: return '+';
        break;
        case 3: return '&';
        break;
        case 4: return '?';
        break;
        case 5: return  '%';
        break;
        case 6: return '!';
        break;
    }
}

float bahis_alma()  //Kullanicidan bahis alinir
{
    float bet;
    puts("Bahisler lutfen!");
    scanf("%f", &bet);
    if(bet <= 0.0)
    {
        puts("Lutfen gecerli bir bahis miktari giriniz!");
        return bahis_alma();
    }
    else
    {
        system("cls");
        sleep(1);
        return bet;
    }

}


//Sonraki 3 fonksiyonda kullanicinin kazanc oranina gore ekrana bir mesaj yazilip akabinde kaldirilir
void kazanc_75()
{
    printf("\t\t\t\t\t%%75  KAZANDINIZ");
    sleep(3);
    fflush(stdout);
    printf("\r");
    printf("\t\t\t\t\t                ");
    fflush(stdout);
    puts("");
}

void kazanc_40()
{
    printf("\t\t\t\t\t%%40  KAZANDINIZ");
    sleep(3);
    fflush(stdout);
    printf("\r");
    printf("\t\t\t\t\t                ");
    fflush(stdout);
    puts("");
}

void kayip()
{
    printf("\t\t\t\t\t TUM PARANIZI KAYBETTINIZ");
    sleep(3);
    fflush(stdout);
    printf("\r");
    printf("\t\t\t\t\t                         ");
    fflush(stdout);
    puts("");
}




float oyun_ekrani()
{
    float bahis = bahis_alma();
    char choice;
    int *ptr;
    ptr = (int *)malloc(3 * sizeof(int));   //Sonuç sembollerini hafızada tutmak  icin bellek yonetimi kullanildi
    for(int i = 0; i < 3; i++)
    {
        ptr[i] = rand() % 6 + 1;
    }

    int a, b, c;
    int i = 0;


    while(i < 5)   //Bu döngüde random sayilarin fonksiyonda sekillere donusmus hali ekrana bastirilir
    {
        a = rand() % 6 + 1;
        b = rand() % 6 + 1;
        c = rand() % 6 + 1;
        printf("_________________________________\n");
        puts("|\t\t\t\t|");
        puts("|\t\t\t\t|");
        printf("|\t");
        printf("%c\t%c\t%c", symbols(a), symbols(b), symbols(c));
        printf("\t|\n");
        puts("|\t\t\t\t|");
        printf("|");
        printf(" \t \t\t\t|\n");
        printf("---------------------------------\n");
        usleep(500000);
        system("cls");
        i++;
    }

    //Bu kod blogunda nihai sonuc sembolleri ekrana yazilir
    printf("_________________________________\n");
    puts("|\t\t\t\t|");
    puts("|\t\t\t\t|");
    printf("|\t");
    printf("%c\t%c\t%c", symbols(ptr[0]), symbols(ptr[1]), symbols(ptr[2]));
    printf("\t|\n");
    puts("|\t\t\t\t|");
    printf("|");
    printf(" \t \t\t\t|\n");
    printf("---------------------------------\n");

    //Elde edilen sonuca göre bir mesaj yazdirilir
    if((ptr[0] == ptr[1]) && (ptr[1] == ptr[2]))
    {
        kazanc_75();
        printf("Girilen bahis: %.2f\n", bahis);
        bahis = bahis*1.75;
        printf("Oyun sonu olusan bakiye: %.2f\n", bahis);
        return bahis;
    }
    else if((ptr[0] == ptr[1]) || (ptr[0] == ptr[2]) || (ptr[1] == ptr[2]))
    {
        kazanc_40();
        printf("Girilen bahis: %.2f\n", bahis);
        bahis = bahis*1.40;
        printf("Oyun sonu olusan bakiye: %.2f\n", bahis);
        return bahis;
    }
    else
    {
        kayip();
        printf("Girilen bahis: %.2f\n", bahis);
        printf("Oyun sonu olusan bakiye: 0 \n");
        return -bahis;
    }


    free(ptr);  //Sonuc sembolleri hafızadan kaldirilir
}


int main()
{
    float oyuncu_bakiye = 0.0;
    char choice;
    srand(time(NULL));
    int cont = 1;
    while(cont == 1)
    {

        oyuncu_bakiye += oyun_ekrani();
        printf("Yeniden oynamak icin c'ye, ardindan Enter'a basiniz\n");
        printf("Cikmak icin q tusuna basiniz\n");

        scanf(" %c", &choice);

        if(choice == 'q')
        {
            printf("Son durumdaki bakiyeniz: %.2f\n", oyuncu_bakiye);
            printf("Oyununuz icin tesekkur ederiz efendim, yine bekleriz!");
            cont = 0;

        }
    }
    return 0;
}
