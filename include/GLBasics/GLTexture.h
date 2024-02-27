#ifndef GLTEXTURE_H
#define GLTEXTURE_H

#include <SOIL.h>
#include <Common.h>


class GLTexture
{
    public:
        GLTexture();
        virtual ~GLTexture();

        GLuint tex;
        GLint width, height;

        unsigned char* image;
        void loadTexture(char *fileName);
        void bindTexture();


    protected:

    private:
};


#endif // GLTEXTURE_H
