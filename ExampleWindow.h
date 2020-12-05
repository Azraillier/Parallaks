#ifndef EXAMPLEWINDOW_H_
#define EXAMPLEWINDOW_H_

#include "Window.h"

class ExampleWindow: public Window{
protected:
	std::shared_ptr<SDL_Texture> _stolb;
	std::shared_ptr<SDL_Texture> _sun;
	std::shared_ptr<SDL_Texture> _road;
	std::shared_ptr<SDL_Texture> _mount;
	std::shared_ptr<SDL_Texture> _mad;
	std::shared_ptr<SDL_Texture> _hill;
	std::shared_ptr<SDL_Texture> _cloud2;
	std::shared_ptr<SDL_Texture> _cloud1;
	std::shared_ptr<SDL_Texture> _car2;
	std::shared_ptr<SDL_Texture> _car1;

	int x_st1 = 0, x_st2 = 1280;
	int x_hill1 = 0, x_hill2 = 1280;
	int x_mount1 = 0, x_mount2 = 1280;
	int x_road1 = 0, x_road2 = 1280;
	int x_car1 = 0, x_car2 = 1300, x_car3 = 2500;
	int y_car1 = 540;
	int x_cloud1 = 200, x_cloud2 = 500, x_cloud3 = 900, x_cloud4 = 1300, x_cloud5 = 1600;
public:
	ExampleWindow(
		int width = DEFAULT_WIDTH,
		int height = DEFAULT_HEIGHT);
	virtual ~ExampleWindow() = default;

	virtual void render() override;
	virtual void handle_keys(const Uint8 *keys) override;
	virtual void do_logic();
};

#endif /* EXAMPLEWINDOW_H_ */
