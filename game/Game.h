#pragma once

#include "Player.h"
#include "Platform.h"
#include "Enemy.h"
#include "Projectile.h"
#include "Turret.h"
#include "Ability.h"
#include "Coin.h"
#include "Framework.h"

#include <vector>
#include <iostream>
#include <string>

class Game {
    private:
        MyFramework* framework;
        Player player;
        std::vector<Platform> platforms;
        std::vector<Enemy> enemies;
        std::vector<Projectile> projectiles;
        std::vector<Ability> abilities;
        std::vector<Coin> coins;
        std::vector<Turret> turrets;

        Sprite* backgroundSprite;
        Sprite* platformSprite;
        Sprite* enemySprite;
        Sprite* playerSprite;
        Sprite* projectileSprite;
        Sprite* turretSprite;
        Sprite* coinSprite;
        Sprite* abilitySprite;

    public:
        Game(MyFramework* fw) : framework(fw) {} // initialize framework with the passed MyFramework pointer
        ~Game();

        void init();
        void update();
        void draw();
        void restart();

        // Load sprite from a file
        void loadSprites();

        // Collision detection
        bool checkCollision(Player& player, Platform& platform);
        bool checkCollision(Projectile& projectile, Enemy& enemy);
        bool checkCollision(Player& player, Enemy& enemy);
        bool checkCollision(Player& player, Coin& coin);
        bool checkCollision(Player& player, Turret& turret);

        // Other helper functions
};

Game::~Game() {
    destroySprite(backgroundSprite);
    destroySprite(platformSprite);
    destroySprite(enemySprite);
    destroySprite(playerSprite);
    destroySprite(projectileSprite);
    destroySprite(turretSprite);
    destroySprite(coinSprite);
    destroySprite(abilitySprite);
}