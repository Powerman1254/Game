#pragma once
#include "Component.h"
#include "template.h"

class Transform :
  public Component
{
public:
  Transform() : position_(0.0f) {}

  explicit Transform(const tmpl8::vec2 position) :
    position_(position)
  {}

  /// <summary>
  /// set the position
  /// </summary>
  /// <param name="position"></param>
  void SetPosition(tmpl8::vec2 position);

  /// <summary>
  /// adds the position to the current position
  /// </summary>
  /// <param name="position"></param>
  void AddPosition(tmpl8::vec2 position);

  /// <summary>
  /// returns the position
  /// </summary>
  /// <returns></returns>
  tmpl8::vec2 GetPosition() const;

private:
  tmpl8::vec2 position_;
};
