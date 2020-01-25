#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Perso {
	int id;
	int life;
	int pm;
	int degat;
	int resistance;
	int choix;
};

typedef struct Perso perso;

void actionPerso (struct Perso*perso) {

    check = 0;
    while (check == 0) {
        printf("Tape 1 pour attaquer, 2 pour l'action speciale ou 3 pour te proteger.\n");
			scanf("%d", perso.choix);
			if(perso.choix <= 3 || perso.choix >= 1) {
				check ++;
			}
    }

	if (perso.choix == 1) {

		printf("Choisissez un monstre a attaquer.\n");
        scanf("%d",monstreChoisi)
        
        printf("lance la fonction qui inflige des degats aux monstres en lui donnant comme parametre quel monstre et quel degats\n");

	}
	if (perso.choix == 3) {

        perso.resistance *= 2;
		printf("Vous subissez 2x moins de degats pendant se tour.\n")

	}
	
	if (perso.choix == 2) {

        //mage
		if (perso.id == 1){
			
		}
        //archer
		if (perso.id == 2){
			
		}
        //tank
		if (perso.id == 3){
			
		}
	}
	
}

int main(){
	
	int check;
	int monstreChoisi;
    int persoChoisi;
    int agro = 0;
	
	//Creation Perso
	
	perso mage = {100, 20, 2, 1};
	perso archer = {100, 5, 20, 1};
	perso tank = {100, 0, 15, 2};
	
    //tour de jeu pour chaque perso
    printf("Vous jouez le mage :\nPV : %d\nPM : %d\nDegats :%d\nResistance :%d\nAction speciale : soin\n", mage.life, mage.pm, mage.degat, mage.resistance);
    actionPerso(&mage);
    printf("Vous jouez l'archer :\nPV : %d\nPM : %d\nDegats :%d\nResistance :%d\nAction speciale : fleche empoisonnes\n", archer.life, archer.pm, archer.degat, archer.resistance);
    actionPerso(&archer);
    printf("Vous jouez le tank :\nPV : %d\nPM : %d\nDegats :%d\nResistance :%d\nAction speciale : agro\n", tank.life, tank.pm, tank.degat, tank.resistance);
    actionPerso(&tank);


	
	return 0;
}

