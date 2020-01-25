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
	if (perso.choix == 1) {
		
	}
	if (perso.choix == 3) {
		
	}
	
	if (perso.choix == 2) {
		if (perso.id == 1){
			
		}
	}
	
}

int main(){
	
	int check = 0;
	int mageChoice;
	int archerChoice;
	int tankChoice;
	
	//Creation Perso
	
	perso mage = {100, 20, 2, 1};
	perso archer = {100, 5, 20, 1};
	perso tank = {100, 0, 15, 2};
	
	while (check < 2) {
		
		check = 0;
		
		for ( int i=0; i<3; i++) {
			
			mageChoice = 0;
			archerChoice = 0;
			tankChoice = 0;
			
			//mage
			if (i==0) {
				printf("Tape 1 pour attaquer, 2 pour soigner ou 3 pour te protéger.\n");
				scanf("%d", &mage.choix);
				if(mage.choix <= 3 || mage.choix >= 1) {
					check ++;
				}
			}
			
			
			//archer
			if (i==1) {
				printf("Tape 1 pour attaquer, 2 pour empoisonner ou 3 pour te protéger.\n");
				scanf("%d", &archer.choix);
				if(archer.choix <= 3 || archer.choix >= 1) {
					check ++;
				}
			}
			
			//tank
			if (i==2) {
				printf("Tape 1 pour attaquer, 2 pour agro ou 3 pour te protéger.\n");
				scanf("%d", &tank.choix);
				if(tank.choix <= 3 || tank.choix >= 1) {
					check ++;
				}
			}
		}

	}
	
	
	
	
	


	
	return 0;
}

