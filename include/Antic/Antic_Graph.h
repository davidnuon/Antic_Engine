#ifndef ANTIC_GRAPH_H
#define ANTIC_GRAPH_H

#include <SDL2/SDL.h>

#ifdef __APPLE__
    #include <SDL2_image/SDL_image.h>
    #include <SDL2_ttf/SDL_ttf.h>
#else
    #include <SDL2/SDL_image.h>
    #include <SDL2/SDL_ttf.h>
#endif

#include <map>
#include <iostream>

/**
 * A small Graphics API used in this engine that is just a wrapper for SDL2 rendering.
 */
namespace AGraph
{
	static SDL_Window *window = nullptr;
	static SDL_Renderer *renderer = nullptr;
	static SDL_Event event;

	// Maps that store things to be easily accessed later.
	static std::map< std::string, SDL_Texture* > textureMap;
	static std::map< std::string, TTF_Font* > fontMap;
	static std::map< std::string, SDL_Color > colorMap;

	// Initializes Antic_Graph.
	bool initAGraph( std::string title = "", int width = 640, int height = 480 );

	// Cleans up Antic_Graph. Call this once you know you are done using Antic_Graph.
	void cleanup();

	// Functions for freeing up memory.
	void clearTextureMap();
	void clearFontMap();
	void clearColorMap();

	// Loads textures from images.
	SDL_Texture *loadImage( std::string path );
	SDL_Texture *loadImage( std::string path, Uint8 r, Uint8 g, Uint8 b );
	SDL_Texture *loadImage( std::string path, SDL_Color &color );

	bool loadImage( std::string name, std::string path );
	bool loadImage( std::string name, std::string path, Uint8 r, Uint8 g, Uint8 b );
	bool loadImage( std::string name, std::string path, SDL_Color &color );
	bool loadImage( std::string name, std::string path, std::string color );

	SDL_Texture *getTexture( std::string name );

	// Loads fonts.
	bool loadFont( std::string name, std::string path, int fontSize = 12 );
	TTF_Font *loadFont( std::string path, int fontSize = 12 );
	TTF_Font *getFont( std::string name );

	// Loads strings as a texture.
	bool loadWords( std::string name, std::string words, std::string fontName, std::string colorName );
	bool loadWords( std::string name, std::string words, TTF_Font* font, std::string colorName );

	bool loadWords( std::string name, std::string words, std::string fontName, SDL_Color color );
	bool loadWords( std::string name, std::string words, TTF_Font* font, SDL_Color color );

	bool loadColor( std::string name, Uint8 r = 255, Uint8 g = 255, Uint8 b = 255, Uint8 a = 0 );
	bool loadColor( std::string name, SDL_Color newColor );

	// These functions loads and stores colors. You can overwrite colors.
	SDL_Color getColor( std::string name );

	// Render functions.
	void render( std::string name, int x = 0, int y = 0, SDL_Rect *clip = nullptr, const double angle = 0.0f, const SDL_Point *centerRotate = nullptr );
	void render( SDL_Texture *texture, int x = 0, int y = 0, SDL_Rect *clip = nullptr, const double angle = 0.0f, const SDL_Point *centerRotate = nullptr );

	// Draws a filled rect. If no color is specified, it will be black by default.
	void drawRect( int x, int y, int w, int h );
	void drawRect( int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255 );
	void drawRect( SDL_Rect *rect );
	void drawRect( SDL_Rect *rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255 );

	// Draws lines to the screen. The default color is black.
	void drawLine( int x1, int y1, int x2, int y2 );
	void drawLine( int x1, int y1, int x2, int y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255 );


	// Call this function when done rendering to display to the screen.
	void renderDone();

	void getWindowSize( int &w, int &h );
}

#endif