#pragma once
#include "Scene.h"

class Aim;
class Virus;

class GameplayingScene :
    public Scene
{
private:

    Aim aim1;																					//エイムのデータ変数
    Virus virus[4];																				//隕石のデータ変数
    int BreakCount = 0;																			//隕石の破壊数
    int mouseDetection[3];																		//マウスの入力検知専用変数
    int clickcount = 0;																			//処理をカウントする(mouseDetection用)変数

public:
    GameplayingScene(SceneManager& manager) : Scene(manager) {};
    ~GameplayingScene() {}
    void Init();
    void Update(const InputState& input);
    void Draw();
};

