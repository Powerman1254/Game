#pragma once
#include "AudioPlayer.h"

#include <string>

#include "ScoreboardManager.h"

class Exit;
class Difficulty;
class Reset;
class Start;
class Button;

namespace tmpl8
{
  class Surface;
  class Sprite;
}

class Menu
{
public:
  Menu();

  ~Menu();

  void Render(tmpl8::Surface& dst) const;
  void MouseDown(int button);

  void MouseMove(int x, int y) const;

  int GetState() const { return state; }
  void SetState(int state) { this->state = state; }

  Exit* GetExitButton() const { return buttons.exit; }

  void ButtonDown(Uint8 button);

  void KeyDown(SDL_Keycode key);

  SDL_Cursor* GetArrowCursor() const {return arrow;}
private:
  tmpl8::Surface* menu;

  int state = 0;

  union
  {
    struct
    {
      Difficulty* normal;
      Difficulty* easy;
      Difficulty* hard;

      Start* start;
      Reset* reset;
      Exit* exit;
    };

    Button* array[6];
  } buttons;

  AudioPlayer click{ "assets/sounds/button.wav" };

  ScoreboardManager scoreboard;
  std::string input;

  SDL_Cursor* arrow;
  SDL_Cursor* hand;
};
