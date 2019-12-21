#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

///150202114 Nedret Gegeoglu
///140202121 Selda Yapal

int cark();
void sec(int x);
int ozdegerbul();
int ozvektorbul();
void nilpotent();

int main()
{
    int secim,mod=0;
    secim=cark();


    printf("uretilen son rastgele sayi: %d\n",secim);
    mod=secim%4;
    printf("modlanmis hali: %d\n\n",mod);
    sec(secim);

    while(1)
    {

    }

    return 0;
}
void nilpotent()
{
    FILE *dosya;
    dosya=fopen("sonuc/nilpotent.txt","a");

    fprintf(dosya,"\nNILPOTENT Fonksiyonu Islemleri: \nGirilen Matris: \n");
    fclose(dosya);

    int boyut;
    printf("kare matris boyutunu gir: ");
    scanf("%d",&boyut);

    int matris[boyut][boyut];
    dosya=fopen("sonuc/nilpotent.txt","a");
    int rastgele=0;
    int i,j;
    srand(time(NULL));

    ///rastgele matris olustur
    for(i=0;i<boyut;i++)
    {
        for(j=0;j<boyut;j++)
        {
            rastgele=rand()%31 +(-15);
            matris[i][j]=rastgele;
        }
    }
    printf("\ngirilen matris:\n");

    for(i=0;i<boyut;i++)
    {
        for(j=0;j<boyut;j++)
        {
           printf("%d\t",matris[i][j]);
           fprintf(dosya,"%d\t",matris[i][j]);
        }
        printf("\n");
        fprintf(dosya,"\n");
    }

    int nilmatris[boyut][boyut];
    int carpim;
    int durum=0;
    int toplam=0;

    for(i=0;i<boyut;i++)
    {
        for(j=0;j<boyut;j++)
        {
            nilmatris[i][j]=matris[i][j];
        }
    }

    //printf("durum: %d\n",durum);
    if(boyut==2)
    {
        if(durum==0)
        {
        for(i=0;i<(boyut-1);i++)
        {
            for(j=0;j<boyut;j++)
            {
                carpim=matris[i][j]*matris[j][i];
                toplam+=carpim;
                nilmatris[0][0]=toplam;
            }
        }
        ///olusan nilmatrisi txt yazdir
        fprintf(dosya,"\nOlustan Nilpotent Matris:\n");
        for(i=0;i<boyut;i++)
        {
            for(j=0;j<boyut;j++)
            {
                fprintf(dosya,"%d\t",nilmatris[i][j]);
            }
            fprintf(dosya,"\n");
        }


        carpim=0;
        toplam=0;
        //printf("\ndurum1: %d\n",durum);
        durum++;
        }

        if(durum==1)
        {
            for(i=0;i<boyut;i++)
            {
                    carpim=matris[i][i]*matris[0][1];
                    toplam+=carpim;
                    nilmatris[0][1]=toplam;
            }

            ///olusan nilmatrisi txt yazdir
        fprintf(dosya,"\nOlustan Nilpotent Matris:\n");
        for(i=0;i<boyut;i++)
        {
            for(j=0;j<boyut;j++)
            {
                fprintf(dosya,"%d\t",nilmatris[i][j]);
            }
            fprintf(dosya,"\n");
        }
            carpim=0;
            toplam=0;
            //printf("\ndurum2: %d\n",durum);
            durum++;
        }

        if(durum==2)
        {
            for(i=0;i<boyut;i++)
            {
                    carpim=matris[i][i]*matris[0][1];
                    toplam+=carpim;
                    nilmatris[1][0]=toplam;
            }

            ///olusan nilmatrisi txt yazdir
        fprintf(dosya,"\nOlustan Nilpotent Matris:\n");

        for(i=0;i<boyut;i++)
        {
            for(j=0;j<boyut;j++)
            {
                fprintf(dosya,"%d\t",nilmatris[i][j]);
            }
            fprintf(dosya,"\n");
        }
            carpim=0;
            toplam=0;
           // printf("\ndurum3: %d\n",durum);
            durum++;
        }

        if(durum==3)
        {
            for(i=1;i<boyut;i++)
            {
                for(j=0;j<boyut;j++)
                {
                    carpim=matris[i][j]*matris[j][i];
                    toplam+=carpim;
                    nilmatris[1][1]=toplam;

                }
            }

            ///olusan nilmatrisi txt yazdir
        fprintf(dosya,"\nOlustan Nilpotent Matris:\n");
        for(i=0;i<boyut;i++)
        {
            for(j=0;j<boyut;j++)
            {
                fprintf(dosya,"%d\t",nilmatris[i][j]);
            }
            fprintf(dosya,"\n");
        }
            carpim=0;
            toplam=0;
           // printf("\ndurum4: %d\n",durum);
            durum++;
        }

    }
    printf("\nolusan matris:\n");
    for(i=0;i<boyut;i++)
    {
        for(j=0;j<boyut;j++)
        {
            printf("%d\t",nilmatris[i][j]);
        }
        printf("\n");
    }
    int kontroldizi[boyut*boyut];
    int kontrolindis=0;

    for(i=0;i<boyut;i++)
    {
        for(j=0;j<boyut;j++)
        {
            kontroldizi[kontrolindis]=nilmatris[i][j];
            kontrolindis++;
        }
    }
    /*
    printf("\nkontrol dizi:\n");
    for(i=0;i<(boyut*boyut);i++)
    {
        printf("%d\n",kontroldizi[i]);
    }*/
    int nilkontrol=0;

    for(i=0;i<(boyut*boyut);i++)
    {
        if(kontroldizi[i]!=0)
        {
            nilkontrol++;
        }
    }

    if(nilkontrol==0){
        printf("girilen matris nilpotent matristir.\n");
        fprintf(dosya,"\nGirilen matris nilpotent matristir.\n");
    }
    else if(nilkontrol!=0){
        printf("girilen matris nilpotent matris degildir.\n");
        fprintf(dosya,"\nGirilen matris nilpotent matris degildir.\n");
    }
    fprintf(dosya,"\n_________________________________________________________________\n");




}
int ozvektorbul()
{
    FILE *dosya;
    dosya=fopen("sonuc/ozvektor.txt","a");

    fprintf(dosya,"\nOZVEKTOR Fonksiyonu Islemleri: \nGirilen Matris: \n");
    fclose(dosya);

    int boyut;
    printf("kare matris boyutunu gir: ");
    scanf("%d",&boyut);

    dosya=fopen("sonuc/ozvektor.txt","a");
    float matris[boyut][boyut];
    float detmatris[boyut][boyut];
    float detcarpimi=1;
    float eksidetcarpimi=1;
    float lambda;
    float carpan1,carpan2;
    float islem;
    float ozkontrol;
    float ozkok;
    float kontroldizi[50];
    float lambda1,lambda2;
    int i,j;

    for(i=0;i<boyut;i++)
    {
        for(j=0;j<boyut;j++)
        {
            printf("matrisin %d. satir %d. sutun elemanini gir: ",i+1,j+1);
            scanf("%f",&matris[i][j]);

            fprintf(dosya,"%3.0f\t",matris[i][j]);
        }
        fprintf(dosya,"\n");
    }
    printf("girilen matris: \n");

    for(i=0;i<boyut;i++)
    {
        for(j=0;j<boyut;j++)
        {
            printf("%3.0f ",matris[i][j]);


        }
        printf("\n");
    }
    /// matrisin elemanlarini -1 ile carp
    fprintf(dosya,"\nOlusturulan determinant matrisi: \n");

    for(i=0;i<boyut;i++)
    {
        for(j=0;j<boyut;j++)
        {
            detmatris[i][j]=matris[i][j]*-1;

            fprintf(dosya,"%3.0f\t",detmatris[i][j]);
        }
        fprintf(dosya,"\n");
    }
    /// detmatrisi ekrana yazdir
    printf("detmatris: \n");
    for(i=0;i<boyut;i++)
    {
        for(j=0;j<boyut;j++)
        {
            printf("%3.0f ",detmatris[i][j]);
        }
        printf("\n");
    }

    carpan1=detmatris[0][0]; /// detmatris[0][0] = carpan1 yaptik
    carpan2=detmatris[1][1]; /// detmatris[1][1] = carpan2 yaptik

    ///determinant carpimi yap (capraz carp)
    for(i=0;i<boyut;i++)
    {
        for(j=0;j<boyut;j++)
        {
            if(i==j)
            {
                detcarpimi=detcarpimi*detmatris[i][j];
            }
            else if(i!=j)
            {
                eksidetcarpimi=eksidetcarpimi*detmatris[i][j];
            }
        }
    }

    //printf("detcarpimi: %f",detcarpimi);
    eksidetcarpimi=eksidetcarpimi*-1;
    //printf("\neksi det carpimi: %.0f",eksidetcarpimi);

    islem=(lambda*lambda)+(lambda*carpan2)+(carpan1*lambda)+(carpan1*carpan2);
    //printf("\nislem sonucu: %.0f",islem);

    /// ozkontrol degiskeni ve ozkok olusturuldu.
    ozkontrol=carpan1+carpan2;
    //printf("\nozkontrol: %0.f\n",ozkontrol);
    ozkok=(carpan1*carpan2)+eksidetcarpimi;
    //printf("\nozkok: %f",ozkok);

    ozkok=fabs(ozkok);
    //printf("\nozkok mutlak deger: %f",ozkok);

    float eksiozkok;
    eksiozkok=ozkok*-1;

    ///kontrol dizisini olustur
    for(i=0;i<=(ozkok*2);i++)
    {
        kontroldizi[i]=eksiozkok;
        eksiozkok++;
    }

    /*///kontrol dizisini ekrana yazdir
    printf("\nkontrol dizi:\n");
    for(i=0;i<=(ozkok*2);i++)
    {
        printf("%.0f\n",kontroldizi[i]);
    }*/

    ///denklem koklerini bul (ozkontrol degiskeni uzerinden)
    for(i=0;i<=(ozkok*2);i++)
    {
        for(j=0;j<=(ozkok*2);j++)
        {
            if(kontroldizi[i]+kontroldizi[j]==ozkontrol)
            {
                lambda1=kontroldizi[i]*-1;
                lambda2=kontroldizi[j]*-1;
            }
        }
    }

    ///ve son
    printf("\n\ndenklemin ozdegerleri:\n");
    printf("lambda1: %0.f\tlambda2: %0.f",lambda1,lambda2);

    ///___________________________OZVEKTOR___________________________________////

    matris[0][0]=matris[0][0]-lambda1;
    matris[1][1]=matris[1][1]-lambda1;

    printf("\nDenklemden Lambda Cikartilmis Matris:\n");
    fprintf(dosya,"\nDenklemden Lambda Cikartilmis Matris:\n");
    for(i=0;i<boyut;i++)
    {
        for(j=0;j<boyut;j++)
        {
            printf("%.0f\t",matris[i][j]);
            fprintf(dosya,"%.0f\t",matris[i][j]);
        }
        printf("\n");
        fprintf(dosya,"\n");
    }
    int ozvektorsonuc;
    int ozvektor1;
    int ozvektor2;

    ozvektor1=matris[0][0];
    ozvektor2=matris[0][1]*-1;

    fprintf(dosya,"\nOzvektor Denklemi:\n");
    fprintf(dosya,"%dx1 + %dx2=0\n\n",ozvektor1,(ozvektor2*-1));
    fprintf(dosya,"%dx1 = %dx2\n\n",ozvektor1,ozvektor2);

    ozvektorsonuc=ozvektor1/ozvektor2;

    for(i=1;i<=3;i++)
    {
        if(ozvektor1%i==0 && ozvektor2%i==0)
        {
            ozvektor1=ozvektor1/i;
            ozvektor2=ozvektor2/i;
        }
    }
    fprintf(dosya,"Denklemin Sadelesmis Hali:\n");
    fprintf(dosya,"%d = %d\n",ozvektor1,ozvektor2);

    printf("\nozvektorler:\n");
    printf("ozvektor1(X1): %d\tozvektor2(X2): %d\n",ozvektor1,ozvektor2);

    fprintf(dosya,"\n Denklemin Ozvektorleri:\n");
    fprintf(dosya,"Ozvektor 1(X1): %d\tOzvektor2(X2): %d",ozvektor1,ozvektor2);
    fprintf(dosya,"\n_______________________________________________________________________________\n\n");

}
int ozdegerbul()
{
    FILE *dosya;
    dosya=fopen("sonuc/ozdeger.txt","a");

    fprintf(dosya,"\nOZDEGER Fonksiyonu Islemleri: \nGirilen Matris: \n");
    fclose(dosya);

    int boyut;
    printf("kare matris boyutunu gir: ");
    scanf("%d",&boyut);

    ///__________________________________________2x2_______________________________________________///
    if(boyut==2)
    {
    dosya=fopen("sonuc/ozdeger.txt","a");
    float matris[boyut][boyut];
    float detmatris[boyut][boyut];
    float detcarpimi=1;
    float eksidetcarpimi=1;
    float lambda;
    float carpan1,carpan2;
    float islem;
    float ozkontrol;
    float ozkok;
    float kontroldizi[50];
    float lambda1,lambda2;
    int i,j;

    for(i=0;i<boyut;i++)
    {
        for(j=0;j<boyut;j++)
        {
            printf("matrisin %d. satir %d. sutun elemanini gir: ",i+1,j+1);
            scanf("%f",&matris[i][j]);

            fprintf(dosya,"%3.0f\t",matris[i][j]);
        }
        fprintf(dosya,"\n");
    }
    printf("girilen matris: \n");

    for(i=0;i<boyut;i++)
    {
        for(j=0;j<boyut;j++)
        {
            printf("%3.0f ",matris[i][j]);


        }
        printf("\n");
    }
    /// matrisin elemanlarini -1 ile carp
    fprintf(dosya,"\nOlusturulan determinant matrisi: \n");

    for(i=0;i<boyut;i++)
    {
        for(j=0;j<boyut;j++)
        {
            detmatris[i][j]=matris[i][j]*-1;

            fprintf(dosya,"%3.0f\t",detmatris[i][j]);
        }
        fprintf(dosya,"\n");
    }
    /// detmatrisi ekrana yazdir
    printf("detmatris: \n");
    for(i=0;i<boyut;i++)
    {
        for(j=0;j<boyut;j++)
        {
            printf("%3.0f ",detmatris[i][j]);
        }
        printf("\n");
    }

    carpan1=detmatris[0][0]; /// detmatris[0][0] = carpan1 yaptik
    carpan2=detmatris[1][1]; /// detmatris[1][1] = carpan2 yaptik

    ///determinant carpimi yap (capraz carp)
    for(i=0;i<boyut;i++)
    {
        for(j=0;j<boyut;j++)
        {
            if(i==j)
            {
                detcarpimi=detcarpimi*detmatris[i][j];
            }
            else if(i!=j)
            {
                eksidetcarpimi=eksidetcarpimi*detmatris[i][j];
            }
        }
    }

    //printf("detcarpimi: %f",detcarpimi);
    eksidetcarpimi=eksidetcarpimi*-1;
    printf("\neksi det carpimi: %.0f",eksidetcarpimi);

    islem=(lambda*lambda)+(lambda*carpan2)+(carpan1*lambda)+(carpan1*carpan2);
    printf("\nislem sonucu: %.0f",islem);

    /// ozkontrol degiskeni ve ozkok olusturuldu.
    ozkontrol=carpan1+carpan2;
    printf("\nozkontrol: %0.f\n",ozkontrol);
    ozkok=(carpan1*carpan2)+eksidetcarpimi;
    printf("\nozkok: %f",ozkok);

    ozkok=fabs(ozkok);
    printf("\nozkok mutlak deger: %f",ozkok);

    float eksiozkok;
    eksiozkok=ozkok*-1;

    ///kontrol dizisini olustur
    for(i=0;i<=(ozkok*2);i++)
    {
        kontroldizi[i]=eksiozkok;
        eksiozkok++;
    }

    ///denklem koklerini bul (ozkontrol degiskeni uzerinden)
    for(i=0;i<=(ozkok*2);i++)
    {
        for(j=0;j<=(ozkok*2);j++)
        {
            if(kontroldizi[i]+kontroldizi[j]==ozkontrol)
            {
                lambda1=kontroldizi[i]*-1;
                lambda2=kontroldizi[j]*-1;
            }
        }
    }

    ///ve son
    printf("\n\ndenklemin ozdegerleri:\n");
    printf("lambda1: %0.f\tlambda2: %0.f",lambda1,lambda2);
    fprintf(dosya,"\n Denklemin Ozdegerleri:\n");
    fprintf(dosya,"lambda 1: %.0f\tlambda2: %.0f",lambda1,lambda2);
    fprintf(dosya,"\n_______________________________________________________________________________\n\n");
    }


///______________________________________________________3x3________________________________________________________________///

    else if(boyut==3)
    {
        dosya=fopen("sonuc/ozdeger.txt","a");
        float matris[boyut][boyut];
        float detmatris[(boyut+2)][boyut];
        int lambda=10;
        int i,j;

        ///matrisi olustur ve ekrana yazdir
        for(i=0;i<boyut;i++)
    {
        for(j=0;j<boyut;j++)
        {
            printf("matrisin %d. satir %d. sutun elemanini gir: ",i+1,j+1);
            scanf("%f",&matris[i][j]);

            fprintf(dosya,"%3.0f\t",matris[i][j]);
        }
        fprintf(dosya,"\n");
    }
    printf("girilen matris: \n");

    for(i=0;i<boyut;i++)
    {
        for(j=0;j<boyut;j++)
        {
            printf("%3.0f ",matris[i][j]);

        }
        printf("\n");
    }
    ///det matrisi olustur ve yazdir
    for(i=0;i<(boyut+2);i++)
    {
        for(j=0;j<boyut;j++)
        {
            detmatris[i][j]=matris[(i%3)][j];

        }
    }
    printf("\ndetmatris:\n");
    fprintf(dosya,"\nOlusturulan determinant matrisi: \n");
    for(i=0;i<(boyut+2);i++)
    {
        for(j=0;j<boyut;j++)
        {
            printf("%3.0f ",detmatris[i][j]);
            fprintf(dosya,"%3.0f\t",detmatris[i][j]);

        }
        printf("\n");
        fprintf(dosya,"\n");
    }

       float sol[20];
       detmatris[0][0]=detmatris[0][0]-lambda;
       detmatris[1][1]=detmatris[1][1]-lambda;
       detmatris[2][2]=detmatris[2][2]-lambda;
       detmatris[3][0]=detmatris[3][0]-lambda;
       detmatris[4][1]=detmatris[4][1]-lambda;

        printf("\nlambda eklenmis detmatris:\n");
    for(i=0;i<(boyut+2);i++)
    {
        for(j=0;j<boyut;j++)
        {
            printf("%3.0f ",detmatris[i][j]);

        }
        printf("\n");
    }
    /// soldan saga olan diziye eleman aktarimi
    sol[0]=detmatris[0][0];
    sol[1]=detmatris[1][1];
    sol[2]=detmatris[2][2];
    sol[3]=detmatris[1][0];
    sol[4]=detmatris[2][1];
    sol[5]=detmatris[3][2];
    sol[6]=detmatris[2][0];
    sol[7]=detmatris[3][1];
    sol[8]=detmatris[4][2];
    int solindis=9;
    int aynisol;
    int aynisag;

    printf("\nsol dizi:\n");

    for(i=0;i<9;i++)
        printf("%.0f\n",sol[i]);


    ///sol 1,2,3 arasinda ayni eleman var mi kontrolu  (dinamik dongu)
    for(i=0;i<3;i++)
    {
        for(j=i+1;j<(3+i);j++)
        {
            if(sol[i]==sol[j%3])
            {
                aynisol=i;
                aynisag=j%3;

                sol[i]=sol[i]+lambda;           /// lambda ekleyerek elemana kendi degerini ver
                sol[j]=((sol[i]*lambda)*2)*-1;  /// eslesen dizi elemanini silip yerine (-2ab) eklendi
                sol[i]=sol[i]*sol[i];           /// elemanin karesini al (a2)
                sol[solindis]=lambda*lambda;    /// dizi uzerinde yeni eleman olarak lambdanin karesi eklendi (b2)

            }
        }
    }

    printf("\nayni sol: %d\nayni sag: %d",aynisol,aynisag);

    printf("\nsol dizi kare alinmis hali:\n");

    for(i=0;i<10;i++)
        printf("%.0f\n",sol[i]);

        for(i=0;i<3;i++)
        {
            if(i!=aynisol && i!=aynisag)
            {
                sol[aynisol]=sol[i]*sol[aynisol];
                sol[aynisag]=sol[i]*sol[aynisag];
                sol[i]=sol[i]*sol[solindis];
                sol[solindis]=0;
            }
        }

    printf("\nsol dizi kare acilimi yapilmis hali:\n");

    for(i=0;i<9;i++)
        printf("%.0f\n",sol[i]);

        float solrakam=1;
        float solrakam2=1;
        float soltoplam;

        for(i=3;i<6;i++)
            solrakam=sol[i]*solrakam;

        for(i=6;i<9;i++)
            solrakam2=sol[i]*solrakam2;

            soltoplam=solrakam+solrakam2;

            printf("\nsol toplam: %.0f",soltoplam);

            float sag[20];
            float toplamdizi[20];
            int toplamindis=0;
            float sagtoplam=0;

            sag[0]=detmatris[0][2];
            sag[1]=detmatris[1][1];
            sag[2]=detmatris[2][0];
            sag[3]=detmatris[1][2];
            sag[4]=detmatris[2][1];
            sag[5]=detmatris[3][0];
            sag[6]=detmatris[2][2];
            sag[7]=detmatris[3][1];
            sag[8]=detmatris[4][0];
            int sagindis=9;

            ///sag dizide ilk 3 elemanin carpma islemi gerceklendi.
            toplamdizi[toplamindis]=sag[0]*sag[1]*sag[2];
            toplamindis++;

            ///4,5 elemanlarinin carpma islemi
            toplamdizi[toplamindis]=sag[3]*sag[4]*(sag[5]+lambda);
            toplamindis++;

            ///6.elemanin (lambda) carpma islemi
            toplamdizi[toplamindis]=sag[3]*sag[4]*(lambda*-1);
            toplamindis++;

            ///7.elemanin (lambda) carpma islemi
            toplamdizi[toplamindis]=sag[7]*sag[8]*(lambda*-1);
            toplamindis++;

            ///8,9 elemanlarinin carpma islemi
            toplamdizi[toplamindis]=sag[7]*sag[8]*(sag[6]+lambda);
            toplamindis++;

            ///toplam diziyi yazdir
            for(i=0;i<5;i++)
                    printf("\ntoplam dizi elemanlari %d. eleman: %.0f\n",i+1,toplamdizi[i]);



            float saglambdatoplam;
            int toplamintdizi[20];

            ///toplam int dizi dogru aktarilmis mi ekrana yazdir
            for(i=0;i<5;i++)
                toplamintdizi[i]=toplamdizi[i];

                printf("\ntoplam int dizi\n");
                for(i=0;i<5;i++)
                    printf("%d\n",toplamintdizi[i]);

                    saglambdatoplam=toplamdizi[0];

            for(i=1;i<5;i++)
            {
                    if((toplamintdizi[0]%lambda==0) && (toplamintdizi[i]%lambda==0))
                    {
                        saglambdatoplam+=toplamdizi[i];
                    }
            }
            printf("\nsag lambda toplam: %.0f\n",saglambdatoplam);

            for(i=0;i<toplamindis;i++)
            {
                if(toplamintdizi[i]%lambda!=0)
                {
                    sagtoplam+=toplamdizi[i];
                }
            }

            printf("\nsag toplam :%.0f\n",sagtoplam);

            ///eksi halleri alindi
            sagtoplam=sagtoplam*-1;
            saglambdatoplam=saglambdatoplam*-1;

            float geneltoplam=0;

            geneltoplam=soltoplam+sagtoplam;
            printf("\ngenel toplam: %.0f\n",geneltoplam);

            ///lambda denkliklerini bulmak
            float lambdageneltoplam[20];
            int solint[solindis];
            int lambdagenelindis=0;

            for(i=0;i<solindis;i++)
            {
                solint[i]=sol[i];
            }

            ///soldaki lambdalari genel lambda toplam dizisine ekle.
            for(i=0;i<solindis;i++)
            {
                if(solint[i]%lambda==0)
                {
                    lambdageneltoplam[lambdagenelindis]=sol[i];
                    lambdagenelindis++;
                }
            }

            ///sagdaki lambdalar genel lambda toplam dizisine ekle.
            lambdageneltoplam[lambdagenelindis]=saglambdatoplam;
            lambdagenelindis++;

            ///lambda genel toplam dizisini ekrana yazdir.
            printf("\nlambda genel dizi toplami:\n");
            for(i=0;i<lambdagenelindis;i++)
                printf("%.0f\n",lambdageneltoplam[i]);

            float lambdau3=0,lambdau2=0,lambdau1=0;
            int lambdagenelinttoplam[20];

            for(i=0;i<lambdagenelindis;i++)
            {
                lambdagenelinttoplam[i]=lambdageneltoplam[i];
            }

            int sayac=0;
            devam:
            for(i=sayac;i<4;i++)
            {

                if(lambdagenelinttoplam[i]%(lambda*lambda*lambda)==0)
                {
                    lambdau3+=lambdageneltoplam[i];
                    sayac++;
                    printf("\n3\n");
                    goto devam;



                }

                else if(lambdagenelinttoplam[i]%(lambda*lambda)==0)
                {
                    lambdau2+=lambdageneltoplam[i];
                    sayac++;
                    printf("\n2\n");
                    goto devam;


                }

                else if(lambdagenelinttoplam[i]%lambda==0)
                {
                    lambdau1+=lambdageneltoplam[i];
                    sayac++;
                    printf("\n1\n");
                    goto devam;
                }

            }
            printf("\n");

            printf("lambdau3: %.0f\n",lambdau3);
            printf("lambdau2: %.0f\n",lambdau2);
            printf("lambdau1: %.0f\n",lambdau1);
            printf("genel toplam: %.0f\n",geneltoplam);

            int geneltoplamkok[20];
            int koksayac=0;
            int geneltoplamint=geneltoplam;

            ///genel toplam degerinin kokleri
            for(i=1;i<=geneltoplamint;i++)
            {
                if(geneltoplamint%i==0)
                {
                    geneltoplamkok[koksayac]=i;
                    koksayac++;
                }
            }

            int koksayac2=koksayac;
            printf("koksayac2:%d\n",koksayac2);

            for(i=0;i<koksayac2;i++)
            {
                geneltoplamkok[koksayac]=geneltoplamkok[i]*-1;
                koksayac++;
            }
            printf("koksayac: %d\n",koksayac);

            for(i=0;i<koksayac;i++){
                printf("%d\n",geneltoplamkok[i]);
            }

           int koktoplam=0;

        int lambdakup=lambda*lambda;
        lambdakup=lambda*lambdakup;

        int lambdakare=lambda*lambda;

        printf("lambda kup: %d\nlambda kare: %d",lambdakup,lambdakare);

        koktoplam=lambdau3+lambdau2+lambdau1+geneltoplam;
        printf("\nkok toplam: %d\n",koktoplam);

        int kup=lambdau3/lambdakup;
        int kare=lambdau2/lambdakare;
        int birus=lambdau1/lambda;

        //int sonuc=(8*kup)+(8*kare)+(8*birus)+geneltoplam;
        printf("kup: %d\t kare:%d\t birinci us: %d\t genel toplam: %.0f",kup,kare,birus,geneltoplam);

        int kokkup;
        int kokkare;
        int kokbirus;
        int sonuc=0;

        int ozdegersonuc[3];
        int ozdegerindis=0;

        for(i=0;i<koksayac;i++)
        {
           kokkup=geneltoplamkok[i]*geneltoplamkok[i];
           kokkup=kokkup*geneltoplamkok[i];

           kokkare=geneltoplamkok[i]*geneltoplamkok[i];

           kokbirus=geneltoplamkok[i];

           sonuc=(kokkup*kup)+(kokkare*kare)+(kokbirus*birus)+geneltoplam;

           if(sonuc==0)
           {
               //printf("\ndenklem koku lambda: %d\n",geneltoplamkok[i]);
               ozdegersonuc[ozdegerindis]=geneltoplamkok[i];
               ozdegerindis++;
           }
        }
        printf("\ndenklemin ozdegerleri:\n");

           for(i=0;i<ozdegerindis;i++){
           printf("%d\t",ozdegersonuc[i]);
           }

        fprintf(dosya,"\n 3x3 Denklemin Ozdegerleri:\n");
        fprintf(dosya,"lambda 1: %d\tlambda2: %d\tlambda3: %d",ozdegersonuc[0],ozdegersonuc[1],ozdegersonuc[2]);
        fprintf(dosya,"\n_______________________________________________________________________________\n\n");

    }
}

void sec(int x)
{
    if(x%4==0){
        printf("Oz Deger:\n");
        ozdegerbul();

    }

    else if(x%4==1){
        printf("Schur Teoremi:\n");

    }

    else if(x%4==2){
        printf("Oz Vektor:\n");
        ozvektorbul();

    }

    else if(x%4==3){
        printf("Nilpotent Matris:\n");
        nilpotent();
    }
}
int cark()
{
    int tekrar=0;
    initwindow(400,400,"Matematik Carki");
    setbkcolor(11);

    printf("Cark kac kez donecek: ");
    scanf("%d",&tekrar);
    srand(time(NULL));

    ///CARK RESIMLERINI GONDER
    char adres[50];
    int i,j;
    int rastgele=0;
    char raststr[50];


    for(j=0;j<tekrar;j++){
            rastgele=rand()%241;
            itoa(rastgele,raststr,10);

        for(i=0;i<11;i++)
        {
        sprintf(adres,"resim/d%d.jpg",i);
        readimagefile(adres,0,0,400,400);
        Sleep(100);
        }
        setcolor(BLACK);
        outtextxy(208,9,raststr);
        Sleep(1000);
    }
        return rastgele;
}
