# Serr.ino
Implementazione di una serra indoor tramite sensori ed attuatori.
___
L'idea di questo progetto è quella di realizzare una serra indoor autonoma per la crescita di piante. 
I sensori previsti sono i seguenti:
- Fotoresistore
- Sensore di temperatura
- Sensore di umidità del suolo

A seguito dei valori letti da questi sensori la board gestirà automaticamente l'accensione delle ventole e l'irrigazione per portare i valori a quelli impostati dall'utente.
Un display permette la visualizzazione della temperatura, dell'umidità e del livello di luce.

L'illuminazione viene fornita da una striscia LED che viene accesa o spenta dalle rilevazioni del fotoresistore ma può anche essere accesa manualmente tramite uno switch ON/OFF.
L'alimentazione viene fornita totalmente dalla board.