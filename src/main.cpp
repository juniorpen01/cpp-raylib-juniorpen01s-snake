#include <cstdlib>
#include <print>

#include <raylib.h>
#include <toml++/toml.hpp>

#include <config.hpp>
#include <snake.hpp>

int main() {
  auto config_result = toml::parse_file("config.toml");
  if (!config_result) {
    TraceLog(LOG_ERROR, "Configuration file `config.toml` not found: %s",
             config_result.error().description());
    return EXIT_FAILURE;
  }

  Config config(config_result.table());

  Snake snake(config.snake.position_initial, config.snake.length_initial,
              config.snake.direction_initial);

  std::ranges::for_each(snake.get_body(), [](const Vector2 segment) {
    std::print("({},{}) ", segment.x, segment.y);
  });
  std::println();

  std::println("{}", sizeof(toml::table));

  InitWindow(800, 800, "juniorpen01's Snake");

  Image cat_image = LoadImage("assets/cat.jpg");

  ImageResize(&cat_image, 600, 600);

  Texture2D cat_texture = LoadTextureFromImage(cat_image);

  while (!WindowShouldClose()) {
    BeginDrawing();

    DrawTexture(cat_texture, 0, 0, RAYWHITE);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
