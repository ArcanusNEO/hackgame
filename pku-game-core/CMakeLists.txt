cmake_minimum_required(VERSION 3.0)
project(pku_game_core)

set(CMAKE_CXX_STANDARD 20)

add_executable(pku_game_core src/main.cc src/MainApplication.cpp src/MainApplication.h src/game/GameClient.cpp src/game/GameClient.h src/renderer/RenderEngine.cpp src/renderer/RenderEngine.h src/game/world/World.cpp src/game/world/World.h src/game/entity/Entity.cpp src/game/entity/Entity.h src/game/entity/Player.cpp src/game/entity/Player.h src/game/block/Block.cpp src/game/block/Block.h src/util/AABB.h src/util/AABB.cpp src/util/Vec2.cpp src/util/Vec2.h src/util/Vec3i.cpp src/util/Vec3i.h src/renderer/BlockRenderer.cpp src/renderer/BlockRenderer.h src/renderer/EntityRenderer.cpp src/renderer/EntityRenderer.h src/renderer/BaseRenderer.cpp src/renderer/BaseRenderer.h src/KeyEventListener.cpp src/KeyEventListener.h src/MouseListener.cpp src/MouseListener.h src/game/item/Item.cpp src/game/item/Item.h src/renderer/UIRenderer.cpp src/renderer/UIRenderer.h src/game/world/WorldGenerator.cpp src/game/world/WorldGenerator.h src/renderer/texture/TextureManager.cpp src/renderer/texture/TextureManager.h src/util/Vec3f.cpp src/util/Vec3f.h src/game/entity/Slime.cpp src/game/entity/Slime.h src/game/entity/Mob.cpp src/game/entity/Mob.h src/game/entity/Food.cpp src/game/entity/Food.h src/game/path/Pathfinder.cpp src/game/path/Pathfinder.h)

target_include_directories(pku_game_core
        PRIVATE
        ${CMAKE_SYSTEM_INCLUDE_PATH}
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src)

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
    target_link_directories(
            pku_game_core
            PRIVATE
            ${CMAKE_SYSTEM_LIBRARY_PATH}
            ${PROJECT_SOURCE_DIR}/lib
    )

    target_link_libraries(
            pku_game_core
            PRIVATE
            pthread
            raylib
            winmm
            jsoncpp
    )
else()
    target_link_directories(
            pku_game_core
            PRIVATE
            ${CMAKE_SYSTEM_LIBRARY_PATH}
    )

    target_link_libraries(
            pku_game_core
            PRIVATE
            GL
            pthread
            raylib
            jsoncpp
    )
endif()


