//
// Created by listerily on 5/8/21.
//

#ifndef PKU_GAME_CORE_ENTITYRENDERER_H
#define PKU_GAME_CORE_ENTITYRENDERER_H

#include "BaseRenderer.h"

class EntityRenderer : public BaseRenderer {
private:

public:
  explicit EntityRenderer(RenderEngine&);
  void render(World& world);
};


#endif //PKU_GAME_CORE_ENTITYRENDERER_H
