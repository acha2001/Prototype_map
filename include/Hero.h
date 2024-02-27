#ifndef HERO_H
#define HERO_H

#include <GLBasics/GLTexture.h>

class Hero
{
    public:
        Hero();
        virtual ~Hero();

        GLTexture *heroTexture = new GLTexture();

        void initHero();
        void drawHero();

    protected:

    private:
};

#endif // HERO_H
