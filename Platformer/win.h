#pragma once
#include "Scene.h"

class Win : public Scene {
public:
    // ����� STATIC ATTRIBUTES ����� //
    int ENEMY_COUNT = 0;

    // ����� DESTRUCTOR ����� //
    ~Win();

    // ����� METHODS ����� //
    void initialise() override;
    void update(float delta_time) override;
    void render(ShaderProgram* program) override;
};
