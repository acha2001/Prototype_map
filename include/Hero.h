#ifndef HERO_H
#define HERO_H

#include <GLBasics/GLTexture.h>
#include <Common.h>

class Hero
{
    public:
        Hero();
        virtual ~Hero();

        float hero_size =0.2;

        GLTexture *heroTexture = new GLTexture();


        bool attacking = false;

        void attack();

        void initHero();
        void drawHero();

    protected:

    private:
        clock_t attack_timer;
        float attack_size=0.2;
};

#endif // HERO_H
