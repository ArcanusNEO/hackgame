//
// Created by listerily on 5/9/21.
//

#include "WorldGenerator.h"

#include "World.h"

#include "../block/Block.h"

#include <json/json.h>
#include <fstream>
#include <memory>

WorldGenerator::WorldGenerator(World &world, GameClient &client) :
        world(&world), gameClient(&client)
{

}

WorldGenerator::~WorldGenerator()
{

}

void WorldGenerator::generate()
{
    using namespace Json;
    using namespace std;

    Value value;
    std::ifstream("../config/world_data.json") >> value;
    for(auto const& v: value["blocks"])
    {
        world->setBlock(v["pos"][0].asInt(), v["pos"][1].asInt(), v["pos"][2].asInt(),
                std::move(std::make_unique<Block>(v["id"].asString(), v["texture"].asString())));
    }
}