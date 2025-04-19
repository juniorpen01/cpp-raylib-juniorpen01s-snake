#include <print>

#include <snake.hpp>
#include <vector2.hpp>

int main() {
  // INFO: imagine ideal body
  const Snake snake({15, 15}, 5, Dir::Right);
  snake.get_body();

  // HACK: i am haxxor
  Snake snake2({6, 0}, 7, Dir::Down);

  // NOTE: do not delete lmfao
  InitWindow(800, 800, "juniorpen01's Snake");

  SetTargetFPS(5);

  Image cat_image = LoadImage("assets/cat.jpg");

  ImageResize(&cat_image, 800, 800);

  Texture cat_texture = LoadTextureFromImage(cat_image);

  UnloadImage(cat_image);

  while (!WindowShouldClose()) {
    std::optional<Direction> direction = []() -> std::optional<Direction> {
      if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT))
        return Dir::Left;
      if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN))
        return Dir::Down;
      if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP))
        return Dir::Up;
      if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT))
        return Dir::Right;
      else
        return std::nullopt;
    }();

    if (direction) {
      snake2.set_direction(direction);
    }

    snake2.move();

    BeginDrawing();

    DrawTexture(cat_texture, 0, 0, RAYWHITE);

    for (const Vector2 segment : snake2.get_body()) {
      std::println("{}", segment);
      DrawRectangle(40 * segment.x, 40 * segment.y, 40, 40, BLUE);
    }

    EndDrawing();
  }

  UnloadTexture(cat_texture);

  CloseWindow();
  return 0;
}
