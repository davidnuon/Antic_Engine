#ifndef ANTIC_MAIN_H
#define ANTIC_MAIN_H

#include <Antic/StateManager.h>
#include <Antic/Antic_Graph.h>
#include <Antic/EventSystem.h>

//#include <Antic/Services.h>

#include <stdio.h>
#include <stdlib.h>
#include <string>

namespace antic
{
	class Engine : public Subject
	{
	public:
		Engine();

		/// Cleans everything up. Also calls close(), so you don't have to worry about it.
		virtual ~Engine();
		virtual bool init( std::string title, int width, int height );
		virtual void update();
		virtual void render();

		void close();

		void setStateManager( StateManager* );

		SDL_Window* getWindow();

		SDL_Event event;
	private:
		StateManager* sm;
		SDL_Window* window;
		SDL_GLContext context;
	};
}

#endif