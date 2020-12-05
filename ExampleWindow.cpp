#include "ExampleWindow.h"
#include <stdexcept>
#include <iostream>

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>

ExampleWindow::ExampleWindow(int width, int height)
:Window(width, height) {

	_stolb = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "stolb.png"),
			SDL_DestroyTexture
	);

	_sun = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "sun.png"),
			SDL_DestroyTexture
	);

	_road = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "road.png"),
			SDL_DestroyTexture
	);

	_mount = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "mount.png"),
			SDL_DestroyTexture
	);

	_mad = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "mad.png"),
			SDL_DestroyTexture
	);

	_hill = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "hill.png"),
			SDL_DestroyTexture
	);

	_cloud2 = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "cloud2.png"),
			SDL_DestroyTexture
	);

	_cloud1 = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "cloud1.png"),
			SDL_DestroyTexture
	);

	_car1 = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "car1.png"),
			SDL_DestroyTexture
	);

	_car2 = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "car2.png"),
			SDL_DestroyTexture
	);
}

void ExampleWindow::render() {

	double red = 21;
	double green = 141;
	double blue = 217;
	for(double y = 0; y <= 400; y += 0.4){
		SDL_SetRenderDrawColor(_renderer.get(), red, green, blue, 255);
		SDL_RenderDrawLine(_renderer.get(), 0, y, 1280, y);
		blue += 0.015;
		green += 0.044;
		red += 0.093;
	}

	SDL_Rect sun {700, 0, 193, 193};
	SDL_RenderCopy(_renderer.get(), _sun.get(), nullptr, &sun);

	SDL_Rect cloud21 {100, 80, 150, 35};
	SDL_RenderCopy(_renderer.get(), _cloud1.get(), nullptr, &cloud21);

	SDL_Rect cloud22 {400, 100, 150, 35};
	SDL_RenderCopy(_renderer.get(), _cloud1.get(), nullptr, &cloud22);

	SDL_Rect cloud23 {700, 60, 150, 35};
	SDL_RenderCopy(_renderer.get(), _cloud1.get(), nullptr, &cloud23);

	SDL_Rect cloud24 {1000, 85, 150, 35};
	SDL_RenderCopy(_renderer.get(), _cloud1.get(), nullptr, &cloud24);

	SDL_Rect mount {x_mount1, 68, 1293, 271};
	SDL_RenderCopy(_renderer.get(), _mount.get(), nullptr, &mount);
	SDL_Rect mount_2 {x_mount2, 68, 1293, 271};
	SDL_RenderCopy(_renderer.get(), _mount.get(), nullptr, &mount_2);

	SDL_Rect cloud1 {x_cloud1, 80, 150, 70};
	SDL_RenderCopy(_renderer.get(), _cloud1.get(), nullptr, &cloud1);

	SDL_Rect cloud2 {x_cloud2, 95, 150, 70};
	SDL_RenderCopy(_renderer.get(), _cloud1.get(), nullptr, &cloud2);

	SDL_Rect cloud3 {x_cloud3, 60, 150, 70};
	SDL_RenderCopy(_renderer.get(), _cloud1.get(), nullptr, &cloud3);

	SDL_Rect cloud4 {x_cloud4, 75, 150, 70};
	SDL_RenderCopy(_renderer.get(), _cloud1.get(), nullptr, &cloud4);

	SDL_Rect cloud5 {x_cloud5, 70, 150, 70};
	SDL_RenderCopy(_renderer.get(), _cloud1.get(), nullptr, &cloud5);

	SDL_Rect hill {x_hill1, 181, 1280, 291};
	SDL_RenderCopy(_renderer.get(), _hill.get(), nullptr, &hill);
	SDL_Rect hill_2 {x_hill2, 181, 1280, 291};
	SDL_RenderCopy(_renderer.get(), _hill.get(), nullptr, &hill_2);

	SDL_Rect mad {0, 472, 1280, 26};
	SDL_RenderCopy(_renderer.get(), _mad.get(), nullptr, &mad);

	SDL_Rect stolb2 {x_st1, 446, 1280, 84};
	SDL_RenderCopy(_renderer.get(), _stolb.get(), nullptr, &stolb2);
	SDL_Rect stolb2_2 {x_st2, 446, 1280, 84};
	SDL_RenderCopy(_renderer.get(), _stolb.get(), nullptr, &stolb2_2);

	SDL_Rect road {x_road1, 530, 1280, 158};
	SDL_RenderCopy(_renderer.get(), _road.get(), nullptr, &road);
	SDL_Rect road_2 {x_road2, 530, 1280, 158};
	SDL_RenderCopy(_renderer.get(), _road.get(), nullptr, &road_2);

	SDL_Rect car2 {x_car2, 510, 240, 79};
	SDL_RenderCopy(_renderer.get(), _car2.get(), nullptr, &car2);

	SDL_Rect car3 {x_car3, 510, 240, 79};
	SDL_RenderCopy(_renderer.get(), _car2.get(), nullptr, &car3);

	SDL_Rect car1 {x_car1, y_car1, 240, 120};
	SDL_RenderCopy(_renderer.get(), _car1.get(), nullptr, &car1);

	SDL_Rect stolb1 {x_st1, 636, 1280, 84};
	SDL_RenderCopy(_renderer.get(), _stolb.get(), nullptr, &stolb1);
	SDL_Rect stolb1_2 {x_st2, 636, 1280, 84};
	SDL_RenderCopy(_renderer.get(), _stolb.get(), nullptr, &stolb1_2);
}

void ExampleWindow::handle_keys(const Uint8 *keys) {
	if (keys[SDL_SCANCODE_LEFT] && x_car1 >= 0){
		x_car1 -= 2;
	}

	if (keys[SDL_SCANCODE_RIGHT] && x_car1 <= 1040){
		x_car1 += 2;
	}

	if (keys[SDL_SCANCODE_DOWN] && y_car1 <= 550){
		y_car1 += 1;
	}

	if (keys[SDL_SCANCODE_UP] && y_car1 >= 520){
		y_car1 -= 1;
	}
}

void ExampleWindow::do_logic() {
	//Параллакс
	x_car2 -= 10;
	if (x_car2 <= -1500) x_car2 = 1300;

	x_car3 -= 10;
	if (x_car3 <= -1500) x_car3 = 1300;

	x_st1 -= 6;
	x_st2 -= 6;
	if (x_st1 <= -1280) x_st1 = 1280;
	if (x_st2 <= -1280) x_st2 = 1280;

	x_road1 -= 6;
	x_road2 -= 6;
	if (x_road1 <= -1280) x_road1 = 1280;
	if (x_road2 <= -1280) x_road2 = 1280;

	x_hill1 -= 3;
	x_hill2 -= 3;
	if (x_hill1 <= -1280) x_hill1 = 1280;
	if (x_hill2 <= -1280) x_hill2 = 1280;

	x_mount1 -= 2;
	x_mount2 -= 2;
	if (x_mount1 <= -1280) x_mount1 = 1280;
	if (x_mount2 <= -1280) x_mount2 = 1280;

	x_cloud1--;
	x_cloud2--;
	x_cloud3--;
	x_cloud4--;
	x_cloud5--;
	if (x_cloud1 <= -200) x_cloud1 = 1600;
	if (x_cloud2 <= -200) x_cloud2 = 1600;
	if (x_cloud3 <= -200) x_cloud3 = 1600;
	if (x_cloud4 <= -200) x_cloud4 = 1600;
	if (x_cloud5 <= -200) x_cloud5 = 1600;
}
