## Blink Comme un Pro
Ce projet présente une version optimisée du célèbre programme "Blink" sur Arduino.
Objectif : faire clignoter la LED intégrée en l’allumant et l’éteignant à intervalles réguliers.

La version classique utilise les fonctions de la bibliothèque Arduino. Bien que simples à utiliser, ces fonctions sont génériques et peu optimisées pour des tâches basiques comme le clignotement d’une LED. Résultat :
Environ 1536 octets de mémoire sont utilisés pour une tâche aussi élémentaire.

### L'approche optimisée
Ce projet propose une implémentation bas niveau utilisant directement les registres AVR (ATmega2560).
Les avantages sont clairs :

- Réduction significative de l’espace mémoire utilisé (environ 304 octets, soit 5 fois moins)
- Exécution plus rapide
- Contrôle plus précis du microcontrôleur

## Et Maintenant?
Mettez immédiatement en pratique ce que vous venez d’apprendre :
adaptez le code pour faire clignoter une LED connectée à une autre broche que celle intégrée à l’Arduino.

Happy coding!
