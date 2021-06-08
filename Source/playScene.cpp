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
	
	
	
	DrawString(10, 70, "�������", GetColor(0, 0, 0));
	DrawString(10, 90, "�v���C���[�ړ�:W�L�[�O�i�AS�L�[���", GetColor(0, 0, 0));
	DrawString(10,110, "�v���C���[��]:A�L�[������AD�L�[�E����", GetColor(0, 0, 0));
	DrawString(10,150, "�J��������:�����L�[�㉺��]�A�����L�[���E��]", GetColor(0, 0, 0));
}
