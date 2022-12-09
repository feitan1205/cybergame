#pragma once
#include "Scene.h"

class Aim;
class Virus;

class GameplayingScene :
    public Scene
{
private:

    Aim aim1;																					//�G�C���̃f�[�^�ϐ�
    Virus virus[4];																				//覐΂̃f�[�^�ϐ�
    int BreakCount = 0;																			//覐΂̔j��
    int mouseDetection[3];																		//�}�E�X�̓��͌��m��p�ϐ�
    int clickcount = 0;																			//�������J�E���g����(mouseDetection�p)�ϐ�

public:
    GameplayingScene(SceneManager& manager) : Scene(manager) {};
    ~GameplayingScene() {}
    void Init();
    void Update(const InputState& input);
    void Draw();
};

