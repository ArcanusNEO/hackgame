//
// Created by listerily on 5/8/21.
//

#include <raylib.h>
#include "BlockRenderer.h"

#include "game/world/World.h"
#include "game/block/Block.h"

#include "RenderEngine.h"
#include "texture/TextureManager.h"
#include "game/entity/Player.h"

#include <cmath>

void BlockRenderer::render(World &world)
{
    auto const& blocks = world.getBlocks();

    auto* player = world.getPlayer();
    Camera3D camera = { 0 };
    camera.position = (Vector3){ player->getPosition().x, player->getPosition().y, player->getPosition().z};
    float targetX = std::cos(player->getPitch()) * std::cos(player->getYaw());
    float targetY = std::sin(player->getPitch());
    float targetZ = std::cos(player->getPitch()) * std::sin(player->getYaw());
    targetX += player->getPosition().x;
    targetY += player->getPosition().y;
    targetZ += player->getPosition().z;
    camera.target = (Vector3){ targetX, targetY, targetZ };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetCameraMode(camera, CAMERA_FREE);
    UpdateCamera(&camera);

    BeginDrawing();

    ClearBackground(RAYWHITE);

    BeginMode3D(camera);

    for(auto const& block: blocks)
    {
        if(block.second == nullptr)
            continue;

        auto* texture = getRenderEngine().getTextureManager().getTexture(block.second->getTexture());
        DrawCubeTexture(*texture,
                        Vector3{(float)block.first.x, (float)block.first.y, (float)block.first.z}, 1.0f, 1.0f, 1.0f, WHITE);
    }

    DrawGrid(10, 1.0f);

    EndMode3D();

    EndDrawing();
}

BlockRenderer::BlockRenderer(RenderEngine & e) : BaseRenderer(e){

}
