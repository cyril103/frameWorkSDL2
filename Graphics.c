#include "Graphics.h"

static Bool initialized = False;
static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

static Bool init(void);
static void DrawTexture(SDL_Texture* tex, SDL_Rect* clip, SDL_Rect* rend, float angle, SDL_RendererFlip flip);

void Graphics_init(void){
    
    if(!initialized){
        initialized = init();
    }

    
}
void Graphics_release(void){

    SDL_DestroyWindow(window);
    window = NULL;
    SDL_DestroyRenderer(renderer);
    renderer = NULL; 

    IMG_Quit();  
    SDL_Quit();    
    
    initialized = False;
}
Bool Graphics_isInitialized(void){
    return initialized;
}

Bool init(){
    
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {

			printf("SDL Initialization Error: %s\n", SDL_GetError());
			return False;
		}

    window =  SDL_CreateWindow(GRAPHICS_TITLE,
     SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
       GRAPHICS_WIDTH, GRAPHICS_HEIGHT, SDL_WINDOW_SHOWN);
    
    if(window == NULL){
        printf("Window Creation Error: %s\n", SDL_GetError());
			return False;
    }
     renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

     if(renderer == NULL){
         printf("Renderer Creation Error: %s\n", SDL_GetError());
			return False;
    }
    SDL_SetRenderDrawColor(renderer,0,0,0,255);

    int flags = IMG_INIT_PNG;
		if(!(IMG_Init(flags) & flags)) {

			printf("IMG Initialization Error: %s\n", IMG_GetError());
			return False;
		}

    return True;

}

void Graphics_clearBackBuffer(){
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderClear(renderer);
}
void Graphics_render(){
    SDL_RenderPresent(renderer);
}

void Graphics_draw_rects(SDL_Rect *rects,int n, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
    SDL_SetRenderDrawColor(renderer,r,g,b,a);
    SDL_RenderFillRects(renderer, rects, n);
}

SDL_Texture* Graphics_loadTexture(char const * path){
    SDL_Texture* tex = NULL;

		//load the image onto a surface
		SDL_Surface* surface = IMG_Load(path);
		//Handling image loading errors
		if(surface == NULL) {

			printf("Image Load Error: Path(%s) - Error(%s)\n", path, IMG_GetError());
			return tex;
        }
		//Converting the surface into a texture to be able to render it using the renderer
		tex = SDL_CreateTextureFromSurface(renderer, surface);
		//Handling texture creation errors
		if(tex == NULL) {

			printf("Create Texture Error: %s\n", SDL_GetError());
			return tex;
		}

		//free the surface since only the texture is needed
		SDL_FreeSurface(surface);

		return tex;
	}void Graphics_drawTexture(SDL_Texture* tex){
        DrawTexture(tex, NULL, NULL, 0.0f, SDL_FLIP_NONE);

    }
   static void DrawTexture(SDL_Texture* tex, SDL_Rect* clip, SDL_Rect* rend, float angle, SDL_RendererFlip flip){
       SDL_RenderCopyEx(renderer,tex,clip,rend,angle,NULL,flip);
   }



