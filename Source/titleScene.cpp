#include "titleScene.h"
#include "../Library/sceneManager.h"
#include "DebugScreen.h"

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Update()
{
	if (CheckHitKey(KEY_INPUT_P)) {
		SceneManager::ChangeScene("PlayScene");
	}

	SceneBase::Update();
}

void TitleScene::Draw()
{
	SceneBase::Draw();

	DrawString(10, 10, "TITLE SCENE", GetColor(255,255,255));
	DrawString(10, 50, "Push [P]Key To Play", GetColor(255, 255, 255));
}
