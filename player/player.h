 #ifndef PLAYER_H
#define PLAYER_H
#include "character.h"
#include <string>
#include "grid.h"
#include "cell.h"
#include "item.h"
#include <cmath>
class Grid;

class Player : public Character {
        std::string race;
        int gold;
        int baseAtk;
        int baseDef;
        public:
	bool isAlive = true;
        Player(Grid *g,int hp, int def, int attack, std::string race);
        virtual ~Player();
	void kill(Player *p) override;
        std::string getRace() override;
        virtual int getGold();
        virtual void changeGold(int change);
        virtual void attack(Character* c);
        virtual void move(std::string dir) override;
        void  pickUpPotion(Item* item, Cell*pos);
	void pickUpGold(Item *item, Cell * pos);
        void setBaseAtk(int baseAtk);
        int getBaseAtk();
        void setBaseDef(int baseDef);
        int getBaseDef();
        void setBase();
	void reset();
        
};
#endif
