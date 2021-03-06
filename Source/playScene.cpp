#include "playScene.h"
#include "../Library/sceneManager.h"
#include "DebugScreen.h"
#include "axis.h"
#include "camera.h"
#include "field.h"
#include "player.h"

PlayScene::PlayScene()
{
	CreateGameObject<Axis>();
	Camera* pCam = CreateGameObject<Camera>();
	SetDrawOrder(pCam, 1);
	CreateGameObject<Player>();
	CreateGameObject<Field>();

}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
	if (CheckHitKey(KEY_INPUT_T)) {
		SceneManager::ChangeScene("TitleScene");
	}

	SceneBase::Update();
}

void PlayScene::Draw()
{
	SceneBase::Draw();

	DrawString(10, 10, "PLAY SCENE", GetColor(0, 0, 0));

	DrawString(10, 50, "Push [T]Key To Title", GetColor(0, 0, 0));
	
	
	
	DrawString(10, 70, "ìà¾", GetColor(0, 0, 0));
	DrawString(10, 90, "vC[Ú®:WL[OiASL[ãÞ", GetColor(0, 0, 0));
	DrawString(10,110, "vC[ñ]:AL[¶ùñADL[Eùñ", GetColor(0, 0, 0));
	DrawString(10,150, "Jì:ª«L[ãºñ]A¨©L[¶Eñ]", GetColor(0, 0, 0));
}
