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
	
	
	
	DrawString(10, 70, "操作説明", GetColor(0, 0, 0));
	DrawString(10, 90, "プレイヤー移動:Wキー前進、Sキー後退", GetColor(0, 0, 0));
	DrawString(10,110, "プレイヤー回転:Aキー左旋回、Dキー右旋回", GetColor(0, 0, 0));
	DrawString(10,150, "カメラ操作:↑↓キー上下回転、→←キー左右回転", GetColor(0, 0, 0));
}
