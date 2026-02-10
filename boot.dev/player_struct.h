#pragma once

typedef struct Player {
	char name[16];
	int health;
	int mana;
} Player;

Player make_player(const char *name, int health, int mana);
