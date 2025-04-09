#define F_CPU 16000000UL // Definition de la frequence du microcontrolleur (16 MHz: Arduino Mega2560)

// Importation de librairies necessaires
#include <avr/io.h>
#include <avr/interrupt.h>

// Definition de la LED incorporee
#define LED_PIN PB7

// Definition de la fonction a executer a chaque interruption
ISR(TIMER1_COMPA_vect){
	PORTB ^= (1 << LED_PIN); // Allumage et extinction alternees de la lED
}

// Definition de la function initialisant l'interruption
void timer1_init(void){
	// Definition du mode CTC pour le compteur
	TCCR1B |= (1 << WGM12);

	// Definition de la valeur du compteur correspondant a la frequence recherchee
	// 0.5Hz (delai de 1000ms apres l'allumage et l'extinction de la lED)
	OCR1A = (F_CPU/(2*1024*0.5)) - 1; // Prescaler 1024

	//  Definition du prescaler a 1024
	TCCR1B |= (1 << CS12) | (1 << CS10);

	// Activation de l'interruption
	TIMSK1 |= (1 << OCIE1A);

	// Activation globale de l'interruption
	sei();
}

// Definition de la fonction principale
int main(void){
	// Definition de la broche 7 (connectee a la broche LED incorporee) comme sortie
	DDRB |= (1 << LED_PIN);

	// Initialisation du  compteur
	timer1_init();

	// Boucle infinie d'execution du code
	while(1){}

	return 0;
}
