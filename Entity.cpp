#include "Entity.h"

#include "Component.h"

class BoxCollider;

Entity::~Entity()
{
  for (const auto& iter : components)
  {
    delete iter.second;
  }
}

void Entity::Update()
{
  for (const auto& c : components)
  {
    if (c.second->GetState())
    {
      c.second->Update(*this);
    }
  }
}

void Entity::Render(tmpl8::Surface& screen)
{
  for (const auto& c : components)
  {
    c.second->Render(*this, screen);
  }
}

void Entity::KeyUp(SDL_Scancode key)
{
  for (const auto& c : components)
  {
    c.second->KeyUp(*this, key);
  }
}

void Entity::KeyDown(SDL_Scancode key)
{
  for (const auto& c : components)
  {
    c.second->KeyDown(*this, key);
  }
}

void Entity::MouseMove(int x, int y)
{
  for (const auto& c : components)
  {
    c.second->MouseMove(*this, x, y);
  }
}

void Entity::MouseUp(int key)
{
  for (const auto& c : components)
  {
    c.second->MouseUp(*this, key);
  }
}

void Entity::MouseDown(int key)
{
  for (const auto& c : components)
  {
    c.second->MouseDown(*this, key);
  }
}

void Entity::Hurt()
{
  for (const auto& c : components)
  {
    c.second->Hurt(*this);
  }
}

void Entity::SetActive(bool state)
{
  for (const auto& component : components)
  {
    component.second->SetActive(*this, state);
  }
}

void Entity::JoystickMove(Uint8 axis, Sint16 value)
{
  for (const auto & component : components)
  {
    component.second->JoystickMove(axis, value);
  }
}

void Entity::ButtonDown(Uint8 button)
{
  for (auto && component : components)
  {
    component.second->ButtonDown(button);
  }
}

void Entity::ButtonUp(Uint8 button)
{
  for (auto && component : components)
  {
    component.second->ButtonUp(button);
  }
}
