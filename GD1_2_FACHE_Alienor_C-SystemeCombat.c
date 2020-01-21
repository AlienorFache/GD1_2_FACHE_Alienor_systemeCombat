#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int monsterLife;
	int playerLife;
	int degatJoueur;
	int degatMonstre;
	int playerChoice;
	int monsterChoice;
	int playerPM;
	int monsterPM;
	int playerSpell;
	int playerTimer;
	int monsterTimer;
	int check;
	int spellCheck;
	
	monsterLife = 100;
	monsterPM = 10;
	monsterTimer = 0;
	playerLife = 100;
	playerPM = 10;
	playerTimer = 0;
	
	//initialise le générateur de nombre pseudo-aléatoire
	srand (time( NULL ));
	
	printf("Tu joue a FF XVI\n");
	
	while (playerLife > 0 && monsterLife > 0) {
		
		check = 0;
		spellCheck = 0;
		
		printf("\n\n\nNOUVEAU TOUR\n");
		
		if(playerPM < 10) {
			playerPM ++;
		}
		
		if(monsterPM < 10) {
			monsterPM ++;
		}
		
		if (playerTimer > 0) {
			monsterLife -= 10;
			playerTimer --;
			printf("Le monstre perd 10PV grace au poison.\n");
			if(monsterLife <= 0) {
				printf("Ton poison a tue le monstre ! C'est lache ! Mais Bravo.");
				break;
			}
		}
		
		if (monsterTimer > 0) {
			playerLife -= 10;
			monsterTimer --;
			printf("Tu perds 10PV a cause du poison.\n");
			if(playerLife <= 0) {
				printf("Tu es mort empoisonne sans pouvoir combattre ... une honte pese sur ta famille.\n");
				break;
			}
		}
		
		printf("\nTu as %dPV et %dPM et le monstre a %dPV.\n", playerLife, playerPM, monsterLife);
		
		while (check == 0) {
			
			if ((playerPM >=4 && monsterTimer > 0) || playerPM >= 9) {
				printf("Tape 1 pour attaquer, 2 pour te proteger ou 3 pour lancer un sort.\n");
				scanf("%d", &playerChoice);
				if(playerChoice <= 3 || playerChoice >= 1) {
					check = 1;
				}
			}
			else {
				printf("Tape 1 pour attaquer ou 2 pour te proteger.\n");
				scanf("%d", &playerChoice);
				if(playerChoice <= 2 || playerChoice >= 1) {
					check = 1;
				}
			}
		}
	
		if (monsterPM >= 9) {
			monsterChoice = (rand() % 3) + 1;
		}
		else {
			monsterChoice = (rand() % 2) + 1;
		}
		
		// tire un nombre aléatoire en 0 et 10 et ajoute 4 pour être entre 4 et 14
		//le minimum étant à 4 meme quand celui d'en face se défend l'attaquant fera au moins 1 pts de dégats
		degatJoueur = (rand() % 11) + 4;
		degatMonstre = (rand() % 11) + 4;
		
		if(playerChoice == 1) {
			if(monsterChoice == 1) {
				monsterLife -= degatJoueur;
				playerLife -= degatMonstre;
				
				printf("Grace a ton puissant coup de poele tu inflige %d degats au monstre.\n",degatJoueur);
				printf("Cependant il riposte en t'assenant un puissant coup de griffe. Tu perds %dPV.\n", degatMonstre);
			}
			else if (monsterChoice == 2) {
				monsterLife -= degatJoueur/4;
				printf("Ta poele avait tout pour infliger un puissant coup au monstre, mais il c'est protege. Tu ne lui fais donc que %d degats\n", degatJoueur/4);
			}
			else if (monsterChoice == 3) {
				monsterLife -= degatJoueur;
				monsterTimer = 3;
				monsterPM -= 9;
				printf("Le monstre sort sa baguette et tu lance un sort de poison ! Tu perda 10PV pendant les 3 prochains tours. Ta poele a tout de meme atteind son but et inflige %d degats au monstre.\n", degatJoueur);
			}
		}
		
		if (playerChoice == 2) {
			if(monsterChoice == 1) {
				playerLife -= degatMonstre/4;
				printf("Tu t'es vaillamant defendu ! Le monstre ne t'inflige donc que %d degats.\n", degatMonstre/4);
			}
			else if (monsterChoice == 2) {
				printf("tu etes ridicule ! tu parez tous les deux des attaques imaginaires.\n");
			}
			else if (monsterChoice == 3) {
				monsterTimer = 3;
				monsterPM -= 9;
				printf("Le monstre sort sa baguette et tu lance un sort de poison ! Tu perda 10PV pendant les 3 prochains tours. Tu es ridicule.\n");
			}
		}
		
		if (playerChoice == 3) {
			while (spellCheck == 0) {
				if (playerPM >= 9 && monsterTimer > 0) {
					printf("Tape 1 pour lancer un sort de poison (cout = 9, degats = 10 ,duree = 3 tours) ou 2 pour prendre un antidote (cout = 4, effet = annule l'empoisonnement du joueur).\n");
					scanf("%d", &playerSpell);
					if(playerSpell <= 2 || playerSpell >= 1) {
						spellCheck = 1;
					}
				}
				else if (playerPM >=9) {
					printf("Tape 1 pour lancer un sort de poison (cout = 9, degats = 10 ,duree = 3 tours.\n");
					scanf("%d", &playerSpell);
					if(playerSpell == 1) {
						spellCheck = 1;
					}
				}
				else if (playerPM >= 4 && monsterTimer > 0) {
					printf("Tape 2 pour prendre un antidote (cout = 4, effet = annule l'empoisonnement du joueur).\n");
					scanf("%d", &playerSpell);
					if(playerSpell == 2) {
						spellCheck = 1;
					}
				}
			}
			
			if (playerSpell == 1) {
				printf("Tu lance ton sort puant sur le monstre !\n");
				playerTimer = 3;
				playerPM -= 9;
			}
			if (playerSpell == 2) {
				monsterTimer = 0;
				printf("Tu as annule le sort du monstre, tu te sens mieux.");
				playerPM -=4;
			}

			if(monsterChoice == 1) {
				playerLife -= degatMonstre;
				printf("Pendant que tu lance ton sort le monstre t'inflige %d degats en te mordant la cheville !\n", degatMonstre/4);
			}
			else if (monsterChoice == 2) {
				printf("Ce monstre est vraiment bete. Il essaye de parer en vainc ton sort.\n");
			}
			else if (monsterChoice == 3) {
				monsterTimer = 3;
				monsterPM -= 9;
				printf("Le monstre sort sa baguette et tu lance un sort de poison ! Tu perdra 10PV pendant les 3 prochains tours sauf si tu avez l'antidote.\n");
			}	 
		}

		if(playerLife <= 0) {
			printf("Tu es mort !");
		}
		
		if(monsterLife <= 0) {
			printf("Tu es es le heros qui terrassa le monstre !");
		}
	}
	
	return 0;
}