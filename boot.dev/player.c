#include "player.h"
#include <string.h>

Player make_player(const char *name, int health, int mana) {
	struct Player player;

	strncpy(player.name, name, 15);
	player.name[15] = '\0';

	player.health = health;
	player.mana = mana;

	return player;
}
