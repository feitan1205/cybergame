#include "GameplayingScene.h"
#include "SceneManager.h"
#include "InputState.h"
#include "GameoverScene.h"
#include <DxLib.h>

void GameplayingScene::Init()
{
	for (int i = 0; i < 4; i++) {
		virus[i].SetImage();																	//画像データを取得
		virus[i].SetSize();																		//隕石のサイズを取得
		virus[i].SetPos();																		//隕石の座標データを取得
		virus[i].SetVec();																		//隕石のベクトルを取得
	}
}

void GameplayingScene::Update(const InputState& input) {
	
	aim1.SetPos();																			//エイム(マウスポインタ)の座標を取得

	for (int i = 0; i < 4; i++) {
		if (virus[i].GetPosX() < -(virus[i].GetsizeX())) {									//隕石が画面外に行ったとき

			virus[i].SetPos();																//隕石の座標データを再取得
			virus[i].SetVec();																//隕石のベクトルを再取得

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
	//X座標が重なっていない場合false
	if (virus.GetPosX() > static_cast<float>(aim.GetPosX()) || virus.GetPosX() + virus.GetsizeX() < static_cast<float>(aim.GetPosX())) {
		return false;
	}

	//Y座標が重なっていない場合false
	if (virus.GetPosY() > static_cast<float>(aim.GetPosY()) || virus.GetPosY() + virus.GetsizeY() < static_cast<float>(aim.GetPosY())) {
		return false;
	}

	//上の条件クリアでtrue
	return true;
}

void GameplayingScene::Draw() {
	for (int i = 0; i < 4; i++) {
		virus[i].Draw();																	//隕石を描画
	}
	aim1.Draw();																			//照準を描画
}