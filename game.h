#pragma once

#include <SDL_scancode.h>
#include <vector>

#include "Entity.h"
#include "template.h"

class Menu;
class EntityManager;

namespace tmpl8
{
  class Surface;

  class Game
  {
  public:
    Game(vec2 screenRes, bool isFullscreen);
    ~Game();

    Game(const Game& copy) = delete;
    Game& operator=(const Game& copy) = delete;

    Game(Game&& copy) = delete;
    Game& operator=(Game&& copy) = delete;

    static Game& Get();

    Entity& GetPlayer() const { return *player; }
    const std::vector<Entity*>& GetEntities() { return entities; }
    Surface* GetScreen() const { return screen; }
    EntityManager& GetEntityManager() const { return *entityManager; }
    vec2 GetMousePos() const { return mousePos; }

    void SetTarget(Surface* surface) { screen = surface; }
    void Init();
    void Shutdown();
    void Tick();
    void MouseUp(int button) const;
    void MouseDown(int button) const;
    void MouseMove(int x, int y);
    void KeyUp(SDL_Scancode key) const;
    void KeyDown(SDL_Scancode key);

    void CheckCollisions() const;

    void AddObstacle(vec2 pos);

    bool IsDebug() const { return debug; }

    void EndGame();

    void StartGame(int difficulty);
    int GetDifficulty() const { return difficulty; }

    Menu* GetMenu() const { return menu; }

    void setFullscreen(bool Fullscreen) { isFullscreen = Fullscreen; }
    void resizeWindow(vec2 newSize) { windowSize = newSize; }

    void JoystickMove(Uint8 axis, Sint16 value) const;
    void ButtonDown(Uint8 button) const;
    void ButtonUp(Uint8 button) const;

  private:
    EntityManager* entityManager{};
    Menu* menu{};

    Surface* heart;

    Surface* screen = nullptr;
    Surface* background = nullptr;
    Entity* player = nullptr;
    std::vector<Entity*> entities;

    int difficulty = 0;
    bool running = false;

    static Game* theGame;

    bool debug = false;
    bool isFullscreen;

    vec2 mousePos;
    const vec2 screenSize;
    vec2 windowSize = { ScreenWidth, ScreenHeight };
  };
}; // namespace Tmpl8
