#include "GameplayingScene.h"
#include "SceneManager.h"
#include "InputState.h"
#include "GameoverScene.h"
#include <DxLib.h>

void GameplayingScene::Init()
{
	for (int i = 0; i < 4; i++) {
		virus[i].SetImage();																	//�摜�f�[�^���擾
		virus[i].SetSize();																		//覐΂̃T�C�Y���擾
		virus[i].SetPos();																		//覐΂̍��W�f�[�^���擾
		virus[i].SetVec();																		//覐΂̃x�N�g�����擾
	}
}

void GameplayingScene::Update(const InputState& input) {
	
	aim1.SetPos();																			//�G�C��(�}�E�X�|�C���^)�̍��W���擾

	for (int i = 0; i < 4; i++) {
		if (virus[i].GetPosX() < -(virus[i].GetsizeX())) {									//覐΂���ʊO�ɍs�����Ƃ�

			virus[i].SetPos();																//覐΂̍��W�f�[�^���Ď擾
			virus[i].SetVec();																//覐΂̃x�N�g�����Ď擾

		}
	}

	if (input.IsTriggered(InputType::shot)) {
		for (int i = 0; i < 4; i++) {
			if (CheckHit(aim1, virus[i])) {
				virus[i].Delete();														//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
				virus[i].SetPos();														//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
				virus[i].SetVec();														//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
				BreakCount++;															//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
				break;																	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
			}
		}
	}

	/*if (input.IsTriggered(InputType::next)) {
		manager_.ChangeScene(new GameoverScene(manager_));
		return;
	}*/
}

bool GameplayingScene::CheckHit(Aim aim, Virus virus)
{
	//X���W���d�Ȃ��Ă��Ȃ��ꍇfalse
	if (virus.GetPosX() > static_cast<float>(aim.GetPosX()) || virus.GetPosX() + virus.GetsizeX() < static_cast<float>(aim.GetPosX())) {
		return false;
	}

	//Y���W���d�Ȃ��Ă��Ȃ��ꍇfalse
	if (virus.GetPosY() > static_cast<float>(aim.GetPosY()) || virus.GetPosY() + virus.GetsizeY() < static_cast<float>(aim.GetPosY())) {
		return false;
	}

	//��̏����N���A��true
	return true;
}

void GameplayingScene::Draw() {
	for (int i = 0; i < 4; i++) {
		virus[i].Draw();																	//覐΂�`��
	}
	aim1.Draw();																			//�Ə���`��
}