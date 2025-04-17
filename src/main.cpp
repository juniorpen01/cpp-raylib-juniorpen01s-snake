#include <print>

#include <raylib.h>
#include <raymath.h>

#include <hello.hpp>

class Player {
  Rectangle rect;
  Vector2 vel;

public:
  Player(Rectangle rect) : rect(rect) {}

  void update(const int speed) {
    double delta_time = GetFrameTime();

    Vector2 direction = {
        static_cast<float>(IsKeyDown(KEY_D) - IsKeyDown(KEY_A)),
        static_cast<float>(IsKeyDown(KEY_S) - IsKeyDown(KEY_W))};
    Vector2 direction_normalized = Vector2Normalize(direction);

    vel.x = speed * delta_time * direction_normalized.x;
    vel.y = speed * delta_time * direction_normalized.y;

    rect.x += vel.x;
    rect.y += vel.y;
  }

  void draw(Color color) const { DrawRectangleRec(rect, color); }
};

int main() {
  const char *hello = hello_good();
  std::println("{}", hello);

  hello = hello_bad();
  std::println("{}", hello);

  char *hello2 = hello_bad();
  std::println("{}", hello2);

  hello2[7] = 'D';
  std::println("{}", hello2);

  delete hello2;
  hello2 = nullptr;

  Player player({150, 150, 150, 150});

  std::println("TraceLog exists");

  Image cat = LoadImage("assets/cat.jpg");

  InitWindow(600, 600, "juniorpen01's Snake");

  ImageResize(&cat, 600, 600);

  Texture2D cat_texture = LoadTextureFromImage(cat);

  SetWindowIcon(cat);

  UnloadImage(cat);

  while (!WindowShouldClose()) {
    player.update(300);

    BeginDrawing();
    ClearBackground(BLACK);

    DrawTexture(cat_texture, 0, 0, WHITE);

    player.draw(RAYWHITE);

    EndDrawing();
  }

  UnloadTexture(cat_texture);

  CloseWindow();
  return 0;
}
