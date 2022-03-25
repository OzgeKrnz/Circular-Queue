#include <stdio.h>
#include <stdlib.h>
#define N 4

struct queue {
    int veri[N];
    int on, arka;
};

typedef struct queue kuyruk;
kuyruk Q;
void olustur(kuyruk*);
void ekle(kuyruk*, int);
void cikart(kuyruk*);



int main()
{
    olustur(&Q);

    ekle(&Q, 10);
    ekle(&Q, 20);
    ekle(&Q, 30);
    ekle(&Q, 40);
    ekle(&Q, 50);//Kuyruk dolu- eklenmedi

    cikart(&Q); //10 silindi
    cikart(&Q); //20 silindi

    ekle(&Q, 60); //eklendi
    ekle(&Q,70); //eklendi
    ekle(&Q, 80); //kuyruk dolu- eklenmedi

    cikart(&Q); //30 silindi
    cikart(&Q); //40 silindi

    ekle(&Q, 90); //eklendi
 
    cikart(&Q); // 60 silindi
    cikart(&Q); //70 silindi
    cikart(&Q); //90 silindi
    cikart(&Q); //kuyruk boş
  
    return 1;
 
}

void olustur(kuyruk* Q) {
    Q->on = -1;
    Q->arka = -1;
}

int bosMu(kuyruk* K) {
    return (K->on == -1);
}

int doluMu(kuyruk* K) {
    return (K->arka == N-1 && K->on == 0 || K->on == K->arka + 1);
}

void ekle(kuyruk* K, int oge) {
    if (doluMu(K))
        printf("Kuyruk dolu\n");

    else {
        if (K->on == -1) {
            K->on = K->arka = 0;
        }
        else {
            K->arka = (K->arka+1) % N;

        }
        K->veri[K->arka] = oge;
        printf("%d eklendi..\n", K->veri[K->arka]);
    }
}

void cikart(kuyruk* K) {
    if (bosMu(K)) {
        printf("Kuyruk bos\n");
        
    }

    else if (K->on == K->arka) { // kuyrukta son eleman kaldıysa.
        printf("%d silindi\n", K->veri[K->on]);
        K->on = K->arka = -1; //siilindikten sonra -1, kuyruk bos mesajı
    }
    else {
        printf("%d silindi\n", K->veri[K->on]);
        K->on=(K->on+1)%N;
    }
}

