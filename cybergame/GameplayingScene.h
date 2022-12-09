#pragma once
#include "Scene.h"
#include "Aim.h"
#include "Virus.h"


class GameplayingScene :
    public Scene
{
private:

    Aim aim1;																					//エイムのデータ変数
    Virus virus[4];																				//隕石のデータ変数
    int BreakCount;      																		//隕石の破壊数

public:

    GameplayingScene(SceneManager& manager) : Scene(manager),BreakCount() {};
    ~GameplayingScene() {}
    void Init();
    void Update(const InputState& input);
    bool CheckHit(Aim aim, Virus virus);
    void Draw();
};

