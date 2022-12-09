#pragma once
#include "Scene.h"
#include "Aim.h"
#include "Virus.h"


class GameplayingScene :
    public Scene
{
private:

    Aim aim1;																					//�G�C���̃f�[�^�ϐ�
    Virus virus[4];																				//覐΂̃f�[�^�ϐ�
    int BreakCount;      																		//覐΂̔j��

public:

    GameplayingScene(SceneManager& manager) : Scene(manager),BreakCount() {};
    ~GameplayingScene() {}
    void Init();
    void Update(const InputState& input);
    bool CheckHit(Aim aim, Virus virus);
    void Draw();
};

