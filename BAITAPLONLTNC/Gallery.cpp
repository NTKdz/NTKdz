#include "Gallery.h"
#include "SDL_utils.h"
#include <SDL_image.h>

Gallery::Gallery(SDL_Renderer* renderer_)
    : renderer(renderer_)
{
    loadPictures();
}

Gallery::~Gallery()
{
    for (SDL_Texture* texture : pictures)
        SDL_DestroyTexture(texture);
}

SDL_Texture* Gallery::loadTexture(std::string path )
{
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if ( loadedSurface == NULL )
        logSDLError(std::cout, "Unable to load image " + path + " SDL_image Error: " + IMG_GetError());
    else {
        newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
        if( newTexture == NULL )
            logSDLError(std::cout, "Unable to create texture from " + path + " SDL Error: " + SDL_GetError());
        SDL_FreeSurface( loadedSurface );
    }
    return newTexture;
}

void Gallery::loadPictures()
{
    pictures[PIC_MOUSE] = loadTexture("lolmouse.png");
    pictures[PIC_SNAKE_VERTICAL] = loadTexture("mouse.png");
    pictures[PIC_SNAKE_HORIZONTAL] = loadTexture("mouse.png");
    pictures[PIC_SNAKE_HEAD] = loadTexture("snakehead.png");
}
